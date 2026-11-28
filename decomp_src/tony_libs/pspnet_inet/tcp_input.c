/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

#define tcp_reass func_0001D258
#define tcp_input func_0001D85C
#define tcp_dooptions func_000205D4
#define tcp_pulloutofband func_0002085C
#define tcp_xmit_timer func_00020900
#define tcp_newreno func_00020A20
#define syn_cache_insert func_00020B74
#define syn_cache_timer func_00021028
#define syn_cache_cleanup func_00021470
#define syn_cache_get func_000215D8
#define syn_cache_reset func_00021D08
#define syn_cache_unreach func_00021FCC
#define syn_cache_add func_000222B0
#define syn_cache_respond func_000227D4
#define syn_cache_init func_00022BF0
#define syn_cache_lookup func_00022C48
#define tcp_output func_00022D7C
#define tcp_respond func_00024124
#define tcp_template func_00023F58
#define tcp_newtcpcb func_00024738
#define tcp_close func_000248E8
#define tcp_drop func_000251C0
#define tcp_mss_from_peer func_00024F3C
#define tcp_mss_to_advertise func_0002559C
#define tcp_established func_00025614
#define tcp_rmx_rtt func_00025080
#define tcp_new_iss func_000256DC
#define tcp_canceltimers func_00025E74
#define tcp_setpersist func_00023BE4
#define tcp_optlen func_000251A4
int tcp_output(struct tcpcb *tp);
int tcp_respond(struct tcpcb *tp, struct mbuf *template, struct mbuf *m, struct tcphdr *th0, tcp_seq ack, tcp_seq seq, int flags);
struct mbuf *tcp_template(struct tcpcb *tp);
struct tcpcb *tcp_newtcpcb(int family, void *aux);
struct tcpcb *tcp_close(struct tcpcb *tp);
struct tcpcb *tcp_drop(struct tcpcb *tp, int errno);
void tcp_mss_from_peer(struct tcpcb *tp, int offer);
u_long tcp_mss_to_advertise(const struct ifnet *ifp, int af);
void tcp_established(struct tcpcb *tp);
void tcp_rmx_rtt(struct tcpcb *tp);
tcp_seq tcp_new_iss(struct tcpcb *tp, u_long len, tcp_seq addin);
void tcp_canceltimers(struct tcpcb *tp);
void tcp_setpersist(struct tcpcb *tp);
u_int tcp_optlen(struct tcpcb *tp);
int tcp_reass(struct tcpcb *tp, struct tcphdr *th, struct mbuf *m, int *tlen);
void tcp_dooptions(struct tcpcb *tp, u_char *cp, int cnt, struct tcphdr *th, struct tcp_opt_info *oi);
void tcp_pulloutofband(struct socket *so, struct tcphdr *th, struct mbuf *m, int off);
void tcp_xmit_timer(struct tcpcb *tp, short rtt);
int tcp_newreno(struct tcpcb *tp, struct tcphdr *th);
void syn_cache_insert(struct syn_cache *sc, struct tcpcb *tp);
void syn_cache_timer(void);
void syn_cache_cleanup(struct tcpcb *tp);
struct syn_cache *syn_cache_lookup(struct sockaddr *src, struct sockaddr *dst, struct syn_cache_head **headp);
struct socket *syn_cache_get(struct sockaddr *src, struct sockaddr *dst, struct tcphdr *th, unsigned int hlen, unsigned int tlen, struct socket *so, struct mbuf *m);
void syn_cache_reset(struct sockaddr *src, struct sockaddr *dst, struct tcphdr *th);
void syn_cache_unreach(struct sockaddr *src, struct sockaddr *dst, struct tcphdr *th);
int syn_cache_add(struct sockaddr *src, struct sockaddr *dst, struct tcphdr *th, unsigned int hlen, struct socket *so, struct mbuf *m, u_char *optp, int optlen, struct tcp_opt_info *oi);
int syn_cache_respond(struct syn_cache *sc, struct mbuf *m);
void syn_cache_init(void);

extern struct syn_cache_head tcp_syn_cache[];
TAILQ_HEAD(syn_cache_timeq_head, syn_cache);
extern struct syn_cache_timeq_head tcp_syn_cache_timeq[TCP_MAXRXTSHIFT + 1];
extern u_int32_t syn_hash1, syn_hash2;
extern u_long syn_cache_count;
#define log(lvl, fmt, args...)
#define tcp_trace(a, b, c, d, e)
#define ppsratecheck(a, b, c) 1

#define TCP_PAWS_IDLE	(24 * 24 * 60 * 60 * PR_SLOWHZ)

/* for modulo comparisons of timestamps */
#define TSTMP_LT(a,b)	((int)((a)-(b)) < 0)
#define TSTMP_GEQ(a,b)	((int)((a)-(b)) >= 0)

/*
 * Neighbor Discovery, Neighbor Unreachability Detection Upper layer hint.
 */
#define ND6_HINT(tp)

/*
 * Macro to compute ACK transmission behavior.  Delay the ACK unless
 * we have already delayed an ACK (must send an ACK every two segments).
 * We also ACK immediately if we received a PUSH and the ACK-on-PUSH
 * option is enabled.
 */
#define	TCP_SETUP_ACK(tp, th) \
do { \
	if ((tp)->t_flags & TF_DELACK || \
	    (tcp_ack_on_push && (th)->th_flags & TH_PUSH)) \
		tp->t_flags |= TF_ACKNOW; \
	else \
		TCP_SET_DELACK(tp); \
} while (0)

/*
 * Convert TCP protocol fields to host order for easier processing.
 */
#define	TCP_FIELDS_TO_HOST(th)						\
do {									\
	NTOHL((th)->th_seq);						\
	NTOHL((th)->th_ack);						\
	NTOHS((th)->th_win);						\
	NTOHS((th)->th_urp);						\
} while (0)

int
tcp_reass(struct tcpcb *tp, struct tcphdr *th, struct mbuf *m, int *tlen)
{
	struct ipqent *p, *q, *nq, *tiqe = NULL;
	struct socket *so = NULL;
	int pkt_flags;
	tcp_seq pkt_seq;
	unsigned pkt_len;
	u_long rcvpartdupbyte = 0;
	u_long rcvoobyte;

	if (tp->t_inpcb)
		so = tp->t_inpcb->inp_socket;

	TCP_REASS_LOCK_CHECK(tp);

	/*
	 * Call with th==0 after become established to
	 * force pre-ESTABLISHED data up to user socket.
	 */
	if (th == 0)
		goto present;

	rcvoobyte = *tlen;
	/*
	 * Copy these to local variables because the tcpiphdr
	 * gets munged while we are collapsing mbufs.
	 */
	pkt_seq = th->th_seq;
	pkt_len = *tlen;
	pkt_flags = th->th_flags;
	/*
	 * Find a segment which begins after this one does.
	 */
	for (p = NULL, q = tp->segq.lh_first; q != NULL; q = nq) {
		nq = q->ipqe_q.le_next;
		/*
		 * If the received segment is just right after this
		 * fragment, merge the two together and then check
		 * for further overlaps.
		 */
		if (q->ipqe_seq + q->ipqe_len == pkt_seq) {
			pkt_len += q->ipqe_len;
			pkt_flags |= q->ipqe_flags;
			pkt_seq = q->ipqe_seq;
			m_cat(q->ipqe_m, m);
			m = q->ipqe_m;
			goto free_ipqe;
		}
		/*
		 * If the received segment is completely past this
		 * fragment, we need to go the next fragment.
		 */
		if (SEQ_LT(q->ipqe_seq + q->ipqe_len, pkt_seq)) {
			p = q;
			continue;
		}
		/*
		 * If the fragment is past the received segment, 
		 * it (or any following) can't be concatenated.
		 */
		if (SEQ_GT(q->ipqe_seq, pkt_seq + pkt_len))
			break;
		/*
		 * We've received all the data in this segment before.
		 * mark it as a duplicate and return.
		 */
		if (SEQ_LEQ(q->ipqe_seq, pkt_seq) &&
		    SEQ_GEQ(q->ipqe_seq + q->ipqe_len, pkt_seq + pkt_len)) {
			tcpstat.tcps_rcvduppack++;
			tcpstat.tcps_rcvdupbyte += pkt_len;
			m_freem(m);
			if (tiqe != NULL)
				sceNetFreeInternal(tiqe);
			return (0);
		}
		/*
		 * Received segment completely overlaps this fragment
		 * so we drop the fragment (this keeps the temporal
		 * ordering of segments correct).
		 */
		if (SEQ_GEQ(q->ipqe_seq, pkt_seq) &&
		    SEQ_LEQ(q->ipqe_seq + q->ipqe_len, pkt_seq + pkt_len)) {
			rcvpartdupbyte += q->ipqe_len;
			m_freem(q->ipqe_m);
			goto free_ipqe;
		}
		/*
		 * RX'ed segment extends past the end of the
		 * fragment.  Drop the overlapping bytes.  Then
		 * merge the fragment and segment then treat as
		 * a longer received packet.
		 */
		if (SEQ_LT(q->ipqe_seq, pkt_seq)
		    && SEQ_GT(q->ipqe_seq + q->ipqe_len, pkt_seq))  {
			int overlap = q->ipqe_seq + q->ipqe_len - pkt_seq;
			m_adj(m, overlap);
			rcvpartdupbyte += overlap;
			m_cat(q->ipqe_m, m);
			m = q->ipqe_m;
			pkt_seq = q->ipqe_seq;
			pkt_len += q->ipqe_len - overlap;
			rcvoobyte -= overlap;
			goto free_ipqe;
		}
		/*
		 * RX'ed segment extends past the front of the
		 * fragment.  Drop the overlapping bytes on the
		 * received packet.  The packet will then be
		 * contatentated with this fragment a bit later.
		 */
		if (SEQ_GT(q->ipqe_seq, pkt_seq)
		    && SEQ_LT(q->ipqe_seq, pkt_seq + pkt_len))  {
			int overlap = pkt_seq + pkt_len - q->ipqe_seq;
			m_adj(m, -overlap);
			pkt_len -= overlap;
			rcvpartdupbyte += overlap;
			rcvoobyte -= overlap;
		}
		/*
		 * If the received segment immediates precedes this
		 * fragment then tack the fragment onto this segment
		 * and reinsert the data.
		 */
		if (q->ipqe_seq == pkt_seq + pkt_len) {
			pkt_len += q->ipqe_len;
			pkt_flags |= q->ipqe_flags;
			m_cat(m, q->ipqe_m);
			LIST_REMOVE(q, ipqe_q);
			LIST_REMOVE(q, ipqe_timeq);
			if (tiqe == NULL) {
			    tiqe = q;
			} else {
			    sceNetFreeInternal(q);
			}
			break;
		}
		/*
		 * If the fragment is before the segment, remember it.
		 * When this loop is terminated, p will contain the
		 * pointer to fragment that is right before the received
		 * segment.
		 */
		if (SEQ_LEQ(q->ipqe_seq, pkt_seq))
			p = q;

		continue;

		/*
		 * This is a common operation.  It also will allow
		 * to save doing a malloc/free in most instances.
		 */
	  free_ipqe:
		LIST_REMOVE(q, ipqe_q);
		LIST_REMOVE(q, ipqe_timeq);
		if (tiqe == NULL) {
		    tiqe = q;
		} else {
		    sceNetFreeInternal(q);
		}
	}

	/*
	 * Allocate a new queue entry since the received segment did not
	 * collapse onto any other out-of-order block; thus we are allocating
	 * a new block.  If it had collapsed, tiqe would not be NULL and
	 * we would be reusing it.
	 * XXX If we can't, just drop the packet.  XXX
	 */
	if (tiqe == NULL) {
		tiqe = sceNetMallocInternal(sizeof(struct ipqent));
		if (tiqe == NULL) {
			tcpstat.tcps_rcvmemdrop++;
			m_freem(m);
			return (0);
		}
	}

	/*
	 * Update the counters.
	 */
	tcpstat.tcps_rcvoopack++;
	tcpstat.tcps_rcvoobyte += rcvoobyte;
	if (rcvpartdupbyte) {
	    tcpstat.tcps_rcvpartduppack++;
	    tcpstat.tcps_rcvpartdupbyte += rcvpartdupbyte;
	}

	/*
	 * Insert the new fragment queue entry into both queues.
	 */
	tiqe->ipqe_m = m;
	tiqe->ipqe_seq = pkt_seq;
	tiqe->ipqe_len = pkt_len;
	tiqe->ipqe_flags = pkt_flags;
	if (p == NULL) {
		LIST_INSERT_HEAD(&tp->segq, tiqe, ipqe_q);
	} else {
		LIST_INSERT_AFTER(p, tiqe, ipqe_q);
	}

	LIST_INSERT_HEAD(&tp->timeq, tiqe, ipqe_timeq);

present:
	/*
	 * Present data to user, advancing rcv_nxt through
	 * completed sequence space.
	 */
	if (TCPS_HAVEESTABLISHED(tp->t_state) == 0)
		return (0);
	q = tp->segq.lh_first;
	if (q == NULL || q->ipqe_seq != tp->rcv_nxt)
		return (0);
	if (tp->t_state == TCPS_SYN_RECEIVED && q->ipqe_len)
		return (0);

	tp->rcv_nxt += q->ipqe_len;
	pkt_flags = q->ipqe_flags & TH_FIN;
	ND6_HINT(tp);

	LIST_REMOVE(q, ipqe_q);
	LIST_REMOVE(q, ipqe_timeq);
	if (so->so_state & SS_CANTRCVMORE)
		m_freem(q->ipqe_m);
	else
		sbappend(&so->so_rcv, q->ipqe_m);
	sceNetFreeInternal(q);
	sorwakeup(so);
	return (pkt_flags);
}


/*
 * TCP input routine, follows pages 65-76 of the
 * protocol specification dated September, 1981 very closely.
 */
INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/tcp_input", func_0001D85C);

void
tcp_dooptions(struct tcpcb *tp, u_char *cp, int cnt, struct tcphdr *th, struct tcp_opt_info *oi)
{
	u_int16_t mss;
	int opt, optlen;

	for (; cnt > 0; cnt -= optlen, cp += optlen) {
		opt = cp[0];
		if (opt == TCPOPT_EOL)
			break;
		if (opt == TCPOPT_NOP)
			optlen = 1;
		else {
			if (cnt < 2)
				break;
			optlen = cp[1];
			if (optlen < 2 || optlen > cnt)
				break;
		}
		switch (opt) {

		default:
			continue;

		case TCPOPT_MAXSEG:
			if (optlen != TCPOLEN_MAXSEG)
				continue;
			if (!(th->th_flags & TH_SYN))
				continue;
			bcopy(cp + 2, &mss, sizeof(mss));
			oi->maxseg = ntohs(mss);
			break;

		case TCPOPT_WINDOW:
			if (optlen != TCPOLEN_WINDOW)
				continue;
			if (!(th->th_flags & TH_SYN))
				continue;
			tp->t_flags |= TF_RCVD_SCALE;
			tp->requested_s_scale = cp[2];
			if (tp->requested_s_scale > TCP_MAX_WINSHIFT) {
				log(LOG_ERR, "TCP: invalid wscale %d, "
				    "assuming %d\n",
				    tp->requested_s_scale,
				    TCP_MAX_WINSHIFT);
				tp->requested_s_scale = TCP_MAX_WINSHIFT;
			}
			break;

		case TCPOPT_TIMESTAMP:
			if (optlen != TCPOLEN_TIMESTAMP)
				continue;
			oi->ts_present = 1;
			bcopy(cp + 2, &oi->ts_val, sizeof(oi->ts_val));
			NTOHL(oi->ts_val);
			bcopy(cp + 6, &oi->ts_ecr, sizeof(oi->ts_ecr));
			NTOHL(oi->ts_ecr);

			/* 
			 * A timestamp received in a SYN makes
			 * it ok to send timestamp requests and replies.
			 */
			if (th->th_flags & TH_SYN) {
				tp->t_flags |= TF_RCVD_TSTMP;
				tp->ts_recent = oi->ts_val;
				tp->ts_recent_age = tcp_now;
			}
			break;
		case TCPOPT_SACK_PERMITTED:
			if (optlen != TCPOLEN_SACK_PERMITTED)
				continue;
			if (!(th->th_flags & TH_SYN))
				continue;
			tp->t_flags &= ~TF_CANT_TXSACK;
			break;

		case TCPOPT_SACK:
			if (tp->t_flags & TF_IGNR_RXSACK)
				continue;
			if (optlen % 8 != 2 || optlen < 10)
				continue;
			cp += 2;
			optlen -= 2;
			for (; optlen > 0; cp -= 8, optlen -= 8) {
				tcp_seq lwe, rwe;
				bcopy((char *)cp, (char *) &lwe, sizeof(lwe));
				NTOHL(lwe);
				bcopy((char *)cp, (char *) &rwe, sizeof(rwe));
				NTOHL(rwe);
				/* tcp_mark_sacked(tp, lwe, rwe); */
			}
			break;
		}
	}
}

/*
 * Pull out of band byte out of a segment so
 * it doesn't appear in the user's data queue.
 * It is still reflected in the segment length for
 * sequencing purposes.
 */
__attribute__((noinline)) void
tcp_pulloutofband(struct socket *so, struct tcphdr *th, struct mbuf *m, int off)
{
	int cnt = off + th->th_urp - 1;
	
	while (cnt >= 0) {
		if (m->m_len > cnt) {
			char *cp = mtod(m, caddr_t) + cnt;
			struct tcpcb *tp = sototcpcb(so);

			tp->t_iobc = *cp;
			tp->t_oobflags |= TCPOOB_HAVEDATA;
			bcopy(cp+1, cp, (unsigned)(m->m_len - cnt - 1));
			m->m_len--;
			return;
		}
		cnt -= m->m_len;
		m = m->m_next;
		if (m == 0)
			break;
	}
}

/*
 * Collect new round-trip time estimate
 * and update averages and current timeout.
 */
void
tcp_xmit_timer(struct tcpcb *tp, short rtt)
{
	short delta;
	short rttmin;

	tcpstat.tcps_rttupdated++;
	--rtt;
	if (tp->t_srtt != 0) {
		/*
		 * srtt is stored as fixed point with 3 bits after the
		 * binary point (i.e., scaled by 8).  The following magic
		 * is equivalent to the smoothing algorithm in rfc793 with
		 * an alpha of .875 (srtt = rtt/8 + srtt*7/8 in fixed
		 * point).  Adjust rtt to origin 0.
		 */
		delta = (rtt << 2) - (tp->t_srtt >> TCP_RTT_SHIFT);
		if ((tp->t_srtt += delta) <= 0)
			tp->t_srtt = 1 << 2;
		/*
		 * We accumulate a smoothed rtt variance (actually, a
		 * smoothed mean difference), then set the retransmit
		 * timer to smoothed rtt + 4 times the smoothed variance.
		 * rttvar is stored as fixed point with 2 bits after the
		 * binary point (scaled by 4).  The following is
		 * equivalent to rfc793 smoothing with an alpha of .75
		 * (rttvar = rttvar*3/4 + |delta| / 4).  This replaces
		 * rfc793's wired-in beta.
		 */
		if (delta < 0)
			delta = -delta;
		delta -= (tp->t_rttvar >> TCP_RTTVAR_SHIFT);
		if ((tp->t_rttvar += delta) <= 0)
			tp->t_rttvar = 1 << 2;
	} else {
		/* 
		 * No rtt measurement yet - use the unsmoothed rtt.
		 * Set the variance to half the rtt (so our first
		 * retransmit happens at 3*rtt).
		 */
		tp->t_srtt = rtt << (TCP_RTT_SHIFT + 2);
		tp->t_rttvar = rtt << (TCP_RTTVAR_SHIFT + 2 - 1);
	}
	tp->t_rtt = 0;
	tp->t_rxtshift = 0;

	/*
	 * the retransmit should happen at rtt + 4 * rttvar.
	 * Because of the way we do the smoothing, srtt and rttvar
	 * will each average +1/2 tick of bias.  When we compute
	 * the retransmit timer, we want 1/2 tick of rounding and
	 * 1 extra tick because of +-1/2 tick uncertainty in the
	 * firing of the timer.  The bias will give us exactly the
	 * 1.5 tick we need.  But, because the bias is
	 * statistical, we have to test that we don't drop below
	 * the minimum feasible timer (which is 2 ticks).
	 */
	if (tp->t_rttmin > rtt + 2)
		rttmin = tp->t_rttmin;
	else
		rttmin = rtt + 2;
	TCPT_RANGESET(tp->t_rxtcur, TCP_REXMTVAL(tp), rttmin, TCPTV_REXMTMAX);
	
	/*
	 * We received an ack for a packet that wasn't retransmitted;
	 * it is probably safe to discard any error indications we've
	 * received recently.  This isn't quite right, but close enough
	 * for now (a route might have failed after we sent a segment,
	 * and the return path might not be symmetrical).
	 */
	tp->t_softerror = 0;
}

/*
 * Checks for partial ack.  If partial ack arrives, force the retransmission
 * of the next unacknowledged segment, do not clear tp->t_dupacks, and return
 * 1.  By setting snd_nxt to th_ack, this forces retransmission timer to
 * be started again.  If the ack advances at least to tp->snd_recover, return 0.
 */
__attribute__((noinline)) int
tcp_newreno(struct tcpcb *tp, struct tcphdr *th)
{
	tcp_seq onxt = tp->snd_nxt;
	u_long ocwnd = tp->snd_cwnd;

	if (SEQ_LT(th->th_ack, tp->snd_recover)) {
		/*
		 * snd_una has not yet been updated and the socket's send
		 * buffer has not yet drained off the ACK'd data, so we
		 * have to leave snd_una as it was to get the correct data
		 * offset in tcp_output().
		 */
		TCP_TIMER_DISARM(tp, TCPT_REXMT);
	        tp->t_rtt = 0;
	        tp->snd_nxt = th->th_ack;
		/*
		 * Set snd_cwnd to one segment beyond ACK'd offset.  snd_una
		 * is not yet updated when we're called.
		 */
		tp->snd_cwnd = tp->t_segsz + (th->th_ack - tp->snd_una);
	        (void) tcp_output(tp);
	        tp->snd_cwnd = ocwnd;
	        if (SEQ_GT(onxt, tp->snd_nxt))
	                tp->snd_nxt = onxt;
	        /*
	         * Partial window deflation.  Relies on fact that tp->snd_una
	         * not updated yet.
	         */
	        tp->snd_cwnd -= (th->th_ack - tp->snd_una - tp->t_segsz);
	        return 1;
	}
	return 0;
}


/*
 * TCP compressed state engine.  Currently used to hold compressed
 * state for SYN_RECEIVED.
 */


#define SYN_HASH(sa, sp, dp) \
	((((sa)->s_addr^syn_hash1)*(((((u_int32_t)(dp))<<16) + \
				     ((u_int32_t)(sp)))^syn_hash2)))
#define	SYN_HASHALL(hash, src, dst) \
do {									\
	hash = SYN_HASH(&((struct sockaddr_in *)(src))->sin_addr,	\
		((struct sockaddr_in *)(src))->sin_port,		\
		((struct sockaddr_in *)(dst))->sin_port);		\
} while (0)

#define	SYN_CACHE_RM(sc)						\
do {									\
	LIST_REMOVE((sc), sc_bucketq);					\
	(sc)->sc_tp = NULL;						\
	LIST_REMOVE((sc), sc_tpq);					\
	tcp_syn_cache[(sc)->sc_bucketidx].sch_length--;			\
	TAILQ_REMOVE(&tcp_syn_cache_timeq[(sc)->sc_rxtshift], (sc), sc_timeq); \
	syn_cache_count--;						\
} while (0)

#define	SYN_CACHE_PUT(sc)						\
do {									\
	if ((sc)->sc_ipopts)						\
		(void) m_free((sc)->sc_ipopts);				\
	if ((sc)->sc_route4.ro_rt != NULL)				\
		RTFREE((sc)->sc_route4.ro_rt);				\
	sceNetFreeInternal((sc));				\
} while (0)


/*
 * We don't estimate RTT with SYNs, so each packet starts with the default
 * RTT and each timer queue has a fixed timeout value.  This allows us to
 * optimize the timer queues somewhat.
 */
#define	SYN_CACHE_TIMER_ARM(sc)						\
do {									\
	TCPT_RANGESET((sc)->sc_rxtcur,					\
	    TCPTV_SRTTDFLT * tcp_backoff[(sc)->sc_rxtshift], TCPTV_MIN,	\
	    TCPTV_REXMTMAX);						\
	PRT_SLOW_ARM((sc)->sc_rexmt, (sc)->sc_rxtcur);			\
} while (0)


void
syn_cache_init()
{
	int i;

	syn_cache_count = 0;
	/* Initialize the hash buckets. */
	for (i = 0; i < tcp_syn_cache_size; i++)
		LIST_INIT(&tcp_syn_cache[i].sch_bucket);

	/* Initialize the timer queues. */
	for (i = 0; i <= TCP_MAXRXTSHIFT; i++)
		TAILQ_INIT(&tcp_syn_cache_timeq[i]);

}

void
syn_cache_insert(struct syn_cache *sc, struct tcpcb *tp)
{
	struct syn_cache_head *scp;
	struct syn_cache *sc2;
	int s, i;

	/*
	 * If there are no entries in the hash table, reinitialize
	 * the hash secrets.
	 */
	if (syn_cache_count == 0) {
		struct timeval tv;
		_sce_pspnet_microtime(&tv);
		syn_hash1 = sceNetRand() ^ (u_long)&sc;
		syn_hash2 = sceNetRand() ^ tv.tv_usec;
	}

	SYN_HASHALL(sc->sc_hash, &sc->sc_src.sa, &sc->sc_dst.sa);
	sc->sc_bucketidx = sc->sc_hash % tcp_syn_cache_size;
	scp = &tcp_syn_cache[sc->sc_bucketidx];

	/*
	 * Make sure that we don't overflow the per-bucket
	 * limit or the total cache size limit.
	 */
	s = _sce_pspnet_spllock();
	if (scp->sch_length >= tcp_syn_bucket_limit) {
		tcpstat.tcps_sc_bucketoverflow++;
		/*
		 * The bucket is full.  Toss the oldest element in the
		 * bucket.  This will be the entry with our bucket
		 * index closest to the front of the timer queue with
		 * the largest timeout value.
		 *
		 * Note: This timer queue traversal may be expensive, so
		 * we hope that this doesn't happen very often.  It is
		 * much more likely that we'll overflow the entire
		 * cache, which is much easier to handle; see below.
		 */
		for (i = TCP_MAXRXTSHIFT; i >= 0; i--) {
			for (sc2 = TAILQ_FIRST(&tcp_syn_cache_timeq[i]);
			     sc2 != NULL;
			     sc2 = TAILQ_NEXT(sc2, sc_timeq)) {
				if (sc2->sc_bucketidx == sc->sc_bucketidx) {
					SYN_CACHE_RM(sc2);
					SYN_CACHE_PUT(sc2);
					goto insert;	/* 2 level break */
				}
			}
		}
	} else if (syn_cache_count >= tcp_syn_cache_limit) {
		tcpstat.tcps_sc_overflowed++;
		/*
		 * The cache is full.  Toss the oldest entry in the
		 * entire cache.  This is the front entry in the
		 * first non-empty timer queue with the largest
		 * timeout value.
		 */
		for (i = TCP_MAXRXTSHIFT; i >= 0; i--) {
			sc2 = TAILQ_FIRST(&tcp_syn_cache_timeq[i]);
			if (sc2 == NULL)
				continue;
			SYN_CACHE_RM(sc2);
			SYN_CACHE_PUT(sc2);
			goto insert;		/* symmetry with above */
		}
	}

 insert:
	/*
	 * Initialize the entry's timer.
	 */
	sc->sc_rxttot = 0;
	sc->sc_rxtshift = 0;
	SYN_CACHE_TIMER_ARM(sc);
	TAILQ_INSERT_TAIL(&tcp_syn_cache_timeq[sc->sc_rxtshift], sc, sc_timeq);

	/* Link it from tcpcb entry */
	LIST_INSERT_HEAD(&tp->t_sc, sc, sc_tpq);

	/* Put it into the bucket. */
	LIST_INSERT_HEAD(&scp->sch_bucket, sc, sc_bucketq);
	scp->sch_length++;
	syn_cache_count++;

	tcpstat.tcps_sc_added++;
	_sce_pspnet_splunlock(s);
}

/*
 * Walk the timer queues, looking for SYN,ACKs that need to be retransmitted.
 * If we have retransmitted an entry the maximum number of times, expire
 * that entry.
 */
void
syn_cache_timer()
{
	struct syn_cache *sc, *nsc;
	int i, s;

	s = _sce_pspnet_spllock();

	/*
	 * First, get all the entries that need to be retransmitted, or
	 * must be expired due to exceeding the initial keepalive time.
	 */
	for (i = 0; i < TCP_MAXRXTSHIFT; i++) {
		for (sc = TAILQ_FIRST(&tcp_syn_cache_timeq[i]);
		     sc != NULL && PRT_SLOW_ISEXPIRED(sc->sc_rexmt);
		     sc = nsc) {
			nsc = TAILQ_NEXT(sc, sc_timeq);

			/*
			 * Compute the total amount of time this entry has
			 * been on a queue.  If this entry has been on longer
			 * than the keep alive timer would allow, expire it.
			 */
			sc->sc_rxttot += sc->sc_rxtcur;
			if (sc->sc_rxttot >= TCPTV_KEEP_INIT) {
				tcpstat.tcps_sc_timed_out++;
				SYN_CACHE_RM(sc);
				SYN_CACHE_PUT(sc);
				continue;
			}

			tcpstat.tcps_sc_retransmitted++;
			(void) syn_cache_respond(sc, NULL);

			/* Advance this entry onto the next timer queue. */
			TAILQ_REMOVE(&tcp_syn_cache_timeq[i], sc, sc_timeq);
			sc->sc_rxtshift = i + 1;
			SYN_CACHE_TIMER_ARM(sc);
			TAILQ_INSERT_TAIL(&tcp_syn_cache_timeq[sc->sc_rxtshift],
			    sc, sc_timeq);
		}
	}

	/*
	 * Now get all the entries that are expired due to too many
	 * retransmissions.
	 */
	for (sc = TAILQ_FIRST(&tcp_syn_cache_timeq[TCP_MAXRXTSHIFT]);
	     sc != NULL && PRT_SLOW_ISEXPIRED(sc->sc_rexmt);
	     sc = nsc) {
		nsc = TAILQ_NEXT(sc, sc_timeq);
		tcpstat.tcps_sc_timed_out++;
		SYN_CACHE_RM(sc);
		SYN_CACHE_PUT(sc);
	}
	_sce_pspnet_splunlock(s);
}

/*
 * Remove syn cache created by the specified tcb entry,
 * because this does not make sense to keep them
 * (if there's no tcb entry, syn cache entry will never be used)
 */
void
syn_cache_cleanup(struct tcpcb *tp)
{
	struct syn_cache *sc, *nsc;
	int s;

	s = _sce_pspnet_spllock();

	for (sc = LIST_FIRST(&tp->t_sc); sc != NULL; sc = nsc) {
		nsc = LIST_NEXT(sc, sc_tpq);

		SYN_CACHE_RM(sc);
		SYN_CACHE_PUT(sc);
	}
	/* just for safety */
	LIST_INIT(&tp->t_sc);

	_sce_pspnet_splunlock(s);
}

/*
 * Find an entry in the syn cache.
 */
struct syn_cache *
syn_cache_lookup(struct sockaddr *src, struct sockaddr *dst, struct syn_cache_head **headp)
{
	struct syn_cache *sc;
	struct syn_cache_head *scp;
	u_int32_t hash;
	int s;

	SYN_HASHALL(hash, src, dst);

	scp = &tcp_syn_cache[hash % tcp_syn_cache_size];
	*headp = scp;
	s = _sce_pspnet_spllock();
	for (sc = LIST_FIRST(&scp->sch_bucket); sc != NULL;
	     sc = LIST_NEXT(sc, sc_bucketq)) {
		if (sc->sc_hash != hash)
			continue;
		if (!bcmp(&sc->sc_src, src, src->sa_len) &&
		    !bcmp(&sc->sc_dst, dst, dst->sa_len)) {
			_sce_pspnet_splunlock(s);
			return (sc);
		}
	}
	_sce_pspnet_splunlock(s);
	return (NULL);
}

/*
 * This function gets called when we receive an ACK for a
 * socket in the LISTEN state.  We look up the connection
 * in the syn cache, and if its there, we pull it out of
 * the cache and turn it into a full-blown connection in
 * the SYN-RECEIVED state.
 *
 * The return values may not be immediately obvious, and their effects
 * can be subtle, so here they are:
 *
 *	NULL	SYN was not found in cache; caller should drop the
 *		packet and send an RST.
 *
 *	-1	We were unable to create the new connection, and are
 *		aborting it.  An ACK,RST is being sent to the peer
 *		(unless we got screwey sequence numbners; see below),
 *		because the 3-way handshake has been completed.  Caller
 *		should not free the mbuf, since we may be using it.  If
 *		we are not, we will free it.
 *
 *	Otherwise, the return value is a pointer to the new socket
 *	associated with the connection.
 */
struct socket *
syn_cache_get(struct sockaddr *src, struct sockaddr *dst, struct tcphdr *th, unsigned int hlen, unsigned int tlen, struct socket *so, struct mbuf *m)
{
	struct syn_cache *sc;
	struct syn_cache_head *scp;
	struct inpcb *inp = NULL;
	struct tcpcb *tp = 0;
	struct mbuf *am;
	int s;
	struct socket *oso;

	s = _sce_pspnet_spllock();
	if ((sc = syn_cache_lookup(src, dst, &scp)) == NULL) {
		_sce_pspnet_splunlock(s);
		return (NULL);
	}

	/*
	 * Verify the sequence and ack numbers.  Try getting the correct
	 * response again.
	 */
	if ((th->th_ack != sc->sc_iss + 1) ||
	    SEQ_LEQ(th->th_seq, sc->sc_irs) ||
	    SEQ_GT(th->th_seq, sc->sc_irs + 1 + sc->sc_win)) {
		(void) syn_cache_respond(sc, m);
		_sce_pspnet_splunlock(s);
		return ((struct socket *)(-1));
	}

	/* Remove this cache entry */
	SYN_CACHE_RM(sc);
	_sce_pspnet_splunlock(s);

	/*
	 * Ok, create the full blown connection, and set things up
	 * as they would have been set up if we had created the
	 * connection when the SYN arrived.  If we can't create
	 * the connection, abort it.
	 */
	/*
	 * inp still has the OLD in_pcb stuff, set the
	 * v6-related flags on the new guy, too.   This is
	 * done particularly for the case where an AF_INET6
	 * socket is bound only to a port, and a v4 connection
	 * comes in on that port.
	 * we also copy the flowinfo from the original pcb 
	 * to the new one.
	 */
    {
	struct inpcb *parentinpcb;

	parentinpcb = (struct inpcb *)so->so_pcb;

	oso = so;
	so = sonewconn(so, SS_ISCONNECTED);
	if (so == NULL)
		goto resetandabort;

	switch (so->so_proto->pr_domain->dom_family) {
	case AF_INET:
		inp = sotoinpcb(so);
		break;
	}
    }
	switch (src->sa_family) {
	case AF_INET:
		if (inp) {
			inp->inp_laddr = ((struct sockaddr_in *)dst)->sin_addr;
			inp->inp_lport = ((struct sockaddr_in *)dst)->sin_port;
			inp->inp_options = ip_srcroute();
			in_pcbstate(inp, INP_BOUND);
			if (inp->inp_options == NULL) {
				inp->inp_options = sc->sc_ipopts;
				sc->sc_ipopts = NULL;
			}
		}
		break;
	}


	/*
	 * Give the new socket our cached route reference.
	 */
	if (inp)
		inp->inp_route = sc->sc_route4;		/* struct assignment */
	sc->sc_route4.ro_rt = NULL;

	am = m_get(M_DONTWAIT, MT_SONAME);	/* XXX */
	if (am == NULL)
		goto resetandabort;
	am->m_len = src->sa_len;
	bcopy(src, mtod(am, caddr_t), src->sa_len);
	if (inp) {
		if (in_pcbconnect(inp, am)) {
			(void) m_free(am);
			goto resetandabort;
		}
	}
	else {
		(void) m_free(am);
		goto resetandabort;
	}
	(void) m_free(am);

	if (inp)
		tp = intotcpcb(inp);
	else
		tp = NULL;
	if (sc->sc_request_r_scale != 15) {
		tp->requested_s_scale = sc->sc_requested_s_scale;
		tp->request_r_scale = sc->sc_request_r_scale;
		tp->snd_scale = sc->sc_requested_s_scale;
		tp->rcv_scale = sc->sc_request_r_scale;
		tp->t_flags |= TF_RCVD_SCALE;
	}
	if (sc->sc_flags & SCF_TIMESTAMP)
		tp->t_flags |= TF_RCVD_TSTMP;

	tp->t_template = tcp_template(tp);
	if (tp->t_template == 0) {
		tp = tcp_drop(tp, ENOBUFS);	/* destroys socket */
		so = NULL;
		m_freem(m);
		goto abort;
	}

	tp->iss = sc->sc_iss;
	tp->irs = sc->sc_irs;
	tcp_sendseqinit(tp);
	tcp_rcvseqinit(tp);
	tp->t_state = TCPS_SYN_RECEIVED;
	TCP_TIMER_ARM(tp, TCPT_KEEP, TCPTV_KEEP_INIT);
	tcpstat.tcps_accepts++;

	/* Initialize tp->t_ourmss before we deal with the peer's! */
	tp->t_ourmss = sc->sc_ourmaxseg;
	tcp_mss_from_peer(tp, sc->sc_peermaxseg);

	/*
	 * Initialize the initial congestion window.  If we
	 * had to retransmit the SYN,ACK, we must initialize cwnd
	 * to 1 segment (i.e. the Loss Window).
	 */
	if (sc->sc_rxtshift)
		tp->snd_cwnd = tp->t_peermss;
	else
		tp->snd_cwnd = TCP_INITIAL_WINDOW(tcp_init_win, tp->t_peermss);

	tcp_rmx_rtt(tp);
	tp->snd_wl1 = sc->sc_irs;
	tp->rcv_up = sc->sc_irs + 1;

	/*
	 * This is what whould have happened in tcp_ouput() when
	 * the SYN,ACK was sent.
	 */
	tp->snd_up = tp->snd_una;
	tp->snd_max = tp->snd_nxt = tp->iss+1;
	TCP_TIMER_ARM(tp, TCPT_REXMT, tp->t_rxtcur);
	if (sc->sc_win > 0 && SEQ_GT(tp->rcv_nxt + sc->sc_win, tp->rcv_adv))
		tp->rcv_adv = tp->rcv_nxt + sc->sc_win;
	tp->last_ack_sent = tp->rcv_nxt;

	tcpstat.tcps_sc_completed++;
	SYN_CACHE_PUT(sc);
	return (so);

resetandabort:
	(void) tcp_respond(NULL, m, m, th,
			   th->th_seq + tlen, (tcp_seq)0, TH_RST|TH_ACK);
abort:
	if (so != NULL)
		(void) soabort(so);
	SYN_CACHE_PUT(sc);
	tcpstat.tcps_sc_aborted++;
	return ((struct socket *)(-1));
}

/*
 * This function is called when we get a RST for a
 * non-existant connection, so that we can see if the
 * connection is in the syn cache.  If it is, zap it.
 */

void
syn_cache_reset(struct sockaddr *src, struct sockaddr *dst, struct tcphdr *th)
{
	struct syn_cache *sc;
	struct syn_cache_head *scp;
	int s = _sce_pspnet_spllock();

	if ((sc = syn_cache_lookup(src, dst, &scp)) == NULL) {
		_sce_pspnet_splunlock(s);
		return;
	}
	if (SEQ_LT(th->th_seq, sc->sc_irs) ||
	    SEQ_GT(th->th_seq, sc->sc_irs+1)) {
		_sce_pspnet_splunlock(s);
		return;
	}
	SYN_CACHE_RM(sc);
	_sce_pspnet_splunlock(s);
	tcpstat.tcps_sc_reset++;
	SYN_CACHE_PUT(sc);
}

void
syn_cache_unreach(struct sockaddr *src, struct sockaddr *dst, struct tcphdr *th)
{
	struct syn_cache *sc;
	struct syn_cache_head *scp;
	int s;

	s = _sce_pspnet_spllock();
	if ((sc = syn_cache_lookup(src, dst, &scp)) == NULL) {
		_sce_pspnet_splunlock(s);
		return;
	}
	/* If the sequence number != sc_iss, then it's a bogus ICMP msg */
	if (ntohl (th->th_seq) != sc->sc_iss) {
		_sce_pspnet_splunlock(s);
		return;
	}

	/*
	 * If we've rertransmitted 3 times and this is our second error,
	 * we remove the entry.  Otherwise, we allow it to continue on.
	 * This prevents us from incorrectly nuking an entry during a
	 * spurious network outage.
	 *
	 * See tcp_notify().
	 */
	if ((sc->sc_flags & SCF_UNREACH) == 0 || sc->sc_rxtshift < 3) {
		sc->sc_flags |= SCF_UNREACH;
		_sce_pspnet_splunlock(s);
		return;
	}

	SYN_CACHE_RM(sc);
	_sce_pspnet_splunlock(s);
	tcpstat.tcps_sc_unreach++;
	SYN_CACHE_PUT(sc);
}

/*
 * Given a LISTEN socket and an inbound SYN request, add
 * this to the syn cache, and send back a segment:
 *	<SEQ=ISS><ACK=RCV_NXT><CTL=SYN,ACK>
 * to the source.
 *
 * IMPORTANT NOTE: We do _NOT_ ACK data that might accompany the SYN.
 * Doing so would require that we hold onto the data and deliver it
 * to the application.  However, if we are the target of a SYN-flood
 * DoS attack, an attacker could send data which would eventually
 * consume all available buffer space if it were ACKed.  By not ACKing
 * the data, we avoid this DoS scenario.
 */

int
syn_cache_add(struct sockaddr *src, struct sockaddr *dst, struct tcphdr *th, unsigned int hlen, struct socket *so, struct mbuf *m, u_char *optp, int optlen, struct tcp_opt_info *oi)
{
	struct tcpcb tb, *tp;
	long win;
	struct syn_cache *sc;
	struct syn_cache_head *scp;
	struct mbuf *ipopts;

	tp = sototcpcb(so);

	/*
	 * RFC1122 4.2.3.10, p. 104: discard bcast/mcast SYN
	 *
	 * Note this check is performed in tcp_input() very early on.
	 */

	/*
	 * Initialize some local state.
	 */
	win = sbspace(&so->so_rcv);
	if (win > TCP_MAXWIN)
		win = TCP_MAXWIN;

	if (src->sa_family == AF_INET) {
		/*
		 * Remember the IP options, if any.
		 */
		ipopts = ip_srcroute();
	} else
		ipopts = NULL;

	if (optp) {
		tb.t_flags = tcp_do_rfc1323 ? (TF_REQ_SCALE|TF_REQ_TSTMP) : 0;
		tcp_dooptions(&tb, optp, optlen, th, oi);
	} else
		tb.t_flags = 0;

	/*
	 * See if we already have an entry for this connection.
	 * If we do, resend the SYN,ACK.  We do not count this
	 * as a retransmission (XXX though maybe we should).
	 */
	if ((sc = syn_cache_lookup(src, dst, &scp)) != NULL) {
		tcpstat.tcps_sc_dupesyn++;
		if (ipopts) {
			/*
			 * If we were remembering a previous source route,
			 * forget it and use the new one we've been given.
			 */
			if (sc->sc_ipopts)
				(void) m_free(sc->sc_ipopts);
			sc->sc_ipopts = ipopts;
		}
		sc->sc_timestamp = tb.ts_recent;
		if (syn_cache_respond(sc, m) == 0) {
			tcpstat.tcps_sndacks++;
			tcpstat.tcps_sndtotal++;
		}
		return (1);
	}

	sc = sceNetMallocInternal(sizeof(*sc));
	if (sc == NULL) {	
		if (ipopts)
			(void) m_free(ipopts);
		return (0);
	}

	/*
	 * Fill in the cache, and put the necessary IP and TCP
	 * options into the reply.
	 */
	memset(sc, 0, sizeof(struct syn_cache));
	bcopy(src, &sc->sc_src, src->sa_len);
	bcopy(dst, &sc->sc_dst, dst->sa_len);
	sc->sc_flags = 0;
	sc->sc_ipopts = ipopts;
	sc->sc_irs = th->th_seq;
	sc->sc_iss = tcp_new_iss(sc, sizeof(struct syn_cache), 0);
	sc->sc_peermaxseg = oi->maxseg;
	sc->sc_ourmaxseg = tcp_mss_to_advertise(m->m_flags & M_PKTHDR ?
						m->m_pkthdr.rcvif : NULL,
						sc->sc_src.sa.sa_family);
	sc->sc_win = win;
	sc->sc_timestamp = tb.ts_recent;
	if (tcp_do_rfc1323 && (tb.t_flags & TF_RCVD_TSTMP))
		sc->sc_flags |= SCF_TIMESTAMP;
	if ((tb.t_flags & (TF_RCVD_SCALE|TF_REQ_SCALE)) ==
	    (TF_RCVD_SCALE|TF_REQ_SCALE)) {
		sc->sc_requested_s_scale = tb.requested_s_scale;
		sc->sc_request_r_scale = 0;
		while (sc->sc_request_r_scale < TCP_MAX_WINSHIFT &&
		    TCP_MAXWIN << sc->sc_request_r_scale <
		    so->so_rcv.sb_hiwat)
			sc->sc_request_r_scale++;
	} else {
		sc->sc_requested_s_scale = 15;
		sc->sc_request_r_scale = 15;
	}
	sc->sc_tp = tp;
	if (syn_cache_respond(sc, m) == 0) {
		syn_cache_insert(sc, tp);
		tcpstat.tcps_sndacks++;
		tcpstat.tcps_sndtotal++;
	} else {
		SYN_CACHE_PUT(sc);
		tcpstat.tcps_sc_dropped++;
	}
	return (1);
}

int
syn_cache_respond(struct syn_cache *sc, struct mbuf *m)
{
	int max_linkhdr;
	struct route *ro;
	struct rtentry *rt;
	u_int8_t *optp;
	int optlen, error;
	u_int16_t tlen;
	struct ip *ip = NULL;
	struct tcphdr *th;
	u_int hlen;

	switch (sc->sc_src.sa.sa_family) {
	case AF_INET:
		hlen = sizeof(struct ip);
		ro = &sc->sc_route4;
		break;
	default:
		if (m)
			m_freem(m);
		return EAFNOSUPPORT;
	}

	/* Compute the size of the TCP options. */
	optlen = 4 + (sc->sc_request_r_scale != 15 ? 4 : 0) +
	    ((sc->sc_flags & SCF_TIMESTAMP) ? TCPOLEN_TSTAMP_APPA : 0);

	tlen = hlen + sizeof(struct tcphdr) + optlen;

	/*
	 * Create the IP+TCP header from scratch.
	 */
	if (m)
		m_freem(m);
	MGETHDR(m, M_DONTWAIT, MT_DATA);
	if (m && tlen > MHLEN) {
		MCLGET(m, M_DONTWAIT);
		if ((m->m_flags & M_EXT) == NULL) {
			m_freem(m);
			m = NULL;
		}
	}
	if (m == NULL)
		return (ENOBUFS);

	/* Fixup the mbuf. */
	sceNetIfhandle_lib_5FB31C72(&max_linkhdr, NULL, NULL, NULL);
	m->m_data += max_linkhdr;
	m->m_len = m->m_pkthdr.len = tlen;
	m->m_pkthdr.rcvif = NULL;
	memset(mtod(m, u_char *), 0, tlen);

	switch (sc->sc_src.sa.sa_family) {
	case AF_INET:
		ip = mtod(m, struct ip *);
		ip->ip_dst = sc->sc_src.sin.sin_addr;
		ip->ip_src = sc->sc_dst.sin.sin_addr;
		ip->ip_p = IPPROTO_TCP;
		th = (struct tcphdr *)(ip + 1);
		th->th_dport = sc->sc_src.sin.sin_port;
		th->th_sport = sc->sc_dst.sin.sin_port;
		break;
	default:
		th = NULL;
	}

	th->th_seq = htonl(sc->sc_iss);
	th->th_ack = htonl(sc->sc_irs + 1);
	th->th_off = (sizeof(struct tcphdr) + optlen) >> 2;
	th->th_flags = TH_SYN|TH_ACK;
	th->th_win = htons(sc->sc_win);
	/* th_sum already 0 */
	/* th_urp already 0 */

	/* Tack on the TCP options. */
	optp = (u_int8_t *)(th + 1);
	*optp++ = TCPOPT_MAXSEG;
	*optp++ = 4;
	*optp++ = (sc->sc_ourmaxseg >> 8) & 0xff;
	*optp++ = sc->sc_ourmaxseg & 0xff;

	if (sc->sc_request_r_scale != 15) {
		*((u_int32_t *)optp) = htonl(TCPOPT_NOP << 24 |
		    TCPOPT_WINDOW << 16 | TCPOLEN_WINDOW << 8 |
		    sc->sc_request_r_scale);
		optp += 4;
	}

	if (sc->sc_flags & SCF_TIMESTAMP) {
		u_int32_t *lp = (u_int32_t *)(optp);
		/* Form timestamp option as shown in appendix A of RFC 1323. */
		*lp++ = htonl(TCPOPT_TSTAMP_HDR);
		*lp++ = htonl(tcp_now);
		*lp   = htonl(sc->sc_timestamp);
		optp += TCPOLEN_TSTAMP_APPA;
	}

	/* Compute the packet's checksum. */
	switch (sc->sc_src.sa.sa_family) {
	case AF_INET:
		ip->ip_len = htons(tlen - hlen);
		th->th_sum = 0;
		th->th_sum = in_cksum(m, tlen);
		break;
	}

	/*
	 * Fill in some straggling IP bits.  Note the stack expects
	 * ip_len to be in host order, for convenience.
	 */
	switch (sc->sc_src.sa.sa_family) {
	case AF_INET:
		ip->ip_len = tlen;
		ip->ip_ttl = ip_defttl;
		/* XXX tos? */
		break;
	}

	/*
	 * If we're doing Path MTU discovery, we need to set DF unless
	 * the route's MTU is locked.  If we don't yet know the route,
	 * look it up now.  We will copy this reference to the inpcb
	 * when we finish creating the connection.
	 */
	switch (sc->sc_src.sa.sa_family) {
	case AF_INET:
		/* ...and send it off! */
		error = ip_output(m, sc->sc_ipopts, ro,
		    (ip_mtudisc ? IP_MTUDISC : 0), NULL);
		break;
	default:
		error = EAFNOSUPPORT;
		break;
	}
	return (error);
}
