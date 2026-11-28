/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

#define tcp_init func_00023E20
#define tcp_template func_00023F58
#define tcp_respond func_00024124
#define tcp_newtcpcb func_00024738
#define tcp_close func_000248E8
#define tcp_freeq func_00024B7C
#define tcp_ctlinput func_00024C00
#define tcp_mss_from_peer func_00024F3C
#define tcp_rmx_rtt func_00025080
#define tcp_optlen func_000251A4
#define tcp_drop func_000251C0
#define tcp_drain func_00025290
#define tcp_notify func_00025378
#define tcp_quench func_0002544C
#define tcp_mtudisc_callback func_00025468
#define tcp_mtudisc func_000254C0
#define tcp_mss_to_advertise func_0002559C
#define tcp_established func_00025614
#define tcp_new_iss func_000256DC
#define tcp_output func_00022D7C
#define tcp_timer_init func_00025E94
#define tcp_canceltimers func_00025E74
#define syn_cache_init func_00022BF0
#define syn_cache_cleanup func_00021470
#define syn_cache_unreach func_00021FCC
int tcp_output(struct tcpcb *tp);
void tcp_timer_init(void);
void tcp_canceltimers(struct tcpcb *tp);
void syn_cache_init(void);
void syn_cache_cleanup(struct tcpcb *tp);
void syn_cache_unreach(struct sockaddr *src, struct sockaddr *dst, struct tcphdr *th);
int tcp_freeq(struct tcpcb *tp);
void tcp_mtudisc_callback(struct in_addr faddr);
void tcp_mtudisc(struct inpcb *inp, int errno);
void tcp_notify(struct inpcb *inp, int error);
struct tcpcb *tcp_close(struct tcpcb *tp);
u_int tcp_optlen(struct tcpcb *tp);
void tcp_quench(struct inpcb *inp, int errno);
#define syn_cache_count D_00030354
extern u_long syn_cache_count;
#define RTM_RTTUNIT 1000000

void
tcp_init(void)
{
	int max_linkhdr, max_protohdr;

	tcp_cwm_burstsize = 4;
	tcp_mssdflt = TCP_MSS;
	tcprexmtthresh = 3;
	tcp_log_refused = 0;
	tcp_rttdflt = TCPTV_SRTTDFLT / PR_SLOWHZ;
	tcp_cwm = 0;
	tcp_do_rfc1323 = 1;
	tcp_do_sack = 1;
	tcp_do_win_scale = 1;
	tcp_do_timestamps = 1;
	tcp_init_win = 1;
	tcp_do_newreno = 0;
	tcp_ack_on_push = 0;
	tcp_mss_ifmtu = 0;
	tcp_compat_42 = 0;
	tcp_iss_seq = 0;
	tcp_now = 0;
	memset(&tcpstat, 0, sizeof(tcpstat));
	tcp_timer_init();
	in_pcbinit(&tcbtable, tcbhashsize, tcbhashsize);
	LIST_INIT(&tcp_delacks);
	sceNetIfhandle_lib_5FB31C72(&max_linkhdr, &max_protohdr, NULL, NULL);
	if (max_protohdr < (int)(sizeof(struct ip) + sizeof(struct tcphdr)))
		max_protohdr = sizeof(struct ip) + sizeof(struct tcphdr);
	sceNetIfhandle_lib_62B20015(max_linkhdr, max_protohdr, 0, 0);
	icmp_mtudisc_callback_register(tcp_mtudisc_callback);
	syn_cache_init();
}

struct mbuf *
tcp_template(struct tcpcb *tp)
{
	struct inpcb *inp = tp->t_inpcb;
	struct tcphdr *n;
	struct mbuf *m;
	int hlen;

	switch (tp->t_family) {
	case AF_INET:
		hlen = sizeof(struct ip);
		if (inp)
			break;
		return NULL;	/*EINVAL*/
	default:
		hlen = 0;	/*pacify gcc*/
		return NULL;	/*EAFNOSUPPORT*/
	}
	m = tp->t_template;
	if (m && m->m_len == hlen + sizeof(struct tcphdr))
		;
	else {
		if (m)
			m_freem(m);
		m = tp->t_template = NULL;
		MGETHDR(m, M_DONTWAIT, MT_HEADER);
		if (m && hlen + sizeof(struct tcphdr) > MHLEN) {
			MCLGET(m, M_DONTWAIT);
			if ((m->m_flags & M_EXT) == 0) {
				m_free(m);
				m = NULL;
			}
		}
		if (m == NULL)
			return NULL;
		m->m_pkthdr.len = m->m_len = hlen + sizeof(struct tcphdr);
	}
	memset(mtod(m, caddr_t), 0, m->m_len);
	switch (tp->t_family) {
	case AF_INET:
	    {
		struct ipovly *ipov;
		mtod(m, struct ip *)->ip_v = 4;
		ipov = mtod(m, struct ipovly *);
		ipov->ih_pr = IPPROTO_TCP;
		ipov->ih_len = htons(sizeof(struct tcphdr));
		if (inp) {
			ipov->ih_src = inp->inp_laddr;
			ipov->ih_dst = inp->inp_faddr;
		}
		break;
	    }
	}
	n = (struct tcphdr *)(mtod(m, caddr_t) + hlen);
	if (inp) {
		n->th_sport = inp->inp_lport;
		n->th_dport = inp->inp_fport;
	}
	n->th_seq = 0;
	n->th_ack = 0;
	n->th_x2 = 0;
	n->th_off = 5;
	n->th_flags = 0;
	n->th_win = 0;
	n->th_sum = 0;
	n->th_urp = 0;
	return (m);
}

int
tcp_respond(struct tcpcb *tp, struct mbuf *template, struct mbuf *m, struct tcphdr *th0, tcp_seq ack, tcp_seq seq, int flags)
{
	struct route *ro;
	int error, tlen, win = 0;
	int hlen;
	struct ip *ip;
	int family;	/* family on packet, not inpcb/in6pcb! */
	struct tcphdr *th = NULL;
	int max_linkhdr;

	sceNetIfhandle_lib_5FB31C72(&max_linkhdr, NULL, NULL, NULL);

	if (tp != NULL && (flags & TH_RST) == 0) {
		if (tp->t_inpcb)
			win = sbspace(&tp->t_inpcb->inp_socket->so_rcv);
	}

	ip = NULL;
	if (m == 0) {
		if (!template)
			return EINVAL;

		/* get family information from template */
		switch (mtod(template, struct ip *)->ip_v) {
		case 4:
			family = AF_INET;
			hlen = sizeof(struct ip);
			break;
		default:
			return EAFNOSUPPORT;
		}

		MGETHDR(m, M_DONTWAIT, MT_HEADER);
		if (m) {
			MCLGET(m, M_DONTWAIT);
			if ((m->m_flags & M_EXT) == 0) {
				m_free(m);
				m = NULL;
			}
		}
		if (m == NULL)
			return (ENOBUFS);

		if (tcp_compat_42)
			tlen = 1;
		else
			tlen = 0;

		m->m_data += max_linkhdr;
		bcopy(mtod(template, caddr_t), mtod(m, caddr_t),
			template->m_len);
		switch (family) {
		case AF_INET:
			ip = mtod(m, struct ip *);
			th = (struct tcphdr *)(ip + 1);
			break;
		}
		flags = TH_ACK;
	} else {

		if ((m->m_flags & M_PKTHDR) == 0) {
			m_freem(m);
			return EINVAL;
		}

		/* get family information from m */
		switch (mtod(m, struct ip *)->ip_v) {
		case 4:
			family = AF_INET;
			hlen = sizeof(struct ip);
			ip = mtod(m, struct ip *);
			break;
		default:
			m_freem(m);
			return EAFNOSUPPORT;
		}
		if ((flags & TH_SYN) == 0 || sizeof(*th0) > (th0->th_off << 2))
			tlen = sizeof(*th0);
		else
			tlen = th0->th_off << 2;

		if (m->m_len > hlen + tlen && (m->m_flags & M_EXT) == 0 &&
		    mtod(m, caddr_t) + hlen == (caddr_t)th0) {
			m->m_len = hlen + tlen;
			m_freem(m->m_next);
			m->m_next = NULL;
		} else {
			struct mbuf *n;

			MGETHDR(n, M_DONTWAIT, MT_HEADER);
			if (n && max_linkhdr + hlen + tlen > MHLEN) {
				MCLGET(n, M_DONTWAIT);
				if ((n->m_flags & M_EXT) == 0) {
					m_freem(n);
					n = NULL;
				}
			}
			if (!n) {
				m_freem(m);
				return ENOBUFS;
			}

			n->m_data += max_linkhdr;
			n->m_len = hlen + tlen;
			m_copyback(n, 0, hlen, mtod(m, caddr_t));
			m_copyback(n, hlen, tlen, (caddr_t)th0);

			m_freem(m);
			m = n;
			n = NULL;
		}

#define xchg(a,b,type) { type t; t=a; a=b; b=t; }
		switch (family) {
		case AF_INET:
			ip = mtod(m, struct ip *);
			th = (struct tcphdr *)(ip + 1);
			ip->ip_p = IPPROTO_TCP;
			xchg(ip->ip_dst, ip->ip_src, struct in_addr);
			ip->ip_p = IPPROTO_TCP;
			break;
		}
		xchg(th->th_dport, th->th_sport, u_int16_t);
#undef xchg
		tlen = 0;	/*be friendly with the following code*/
	}
	th->th_seq = htonl(seq);
	th->th_ack = htonl(ack);
	th->th_x2 = 0;
	if ((flags & TH_SYN) == 0) {
		if (tp)
			win >>= tp->rcv_scale;
		if (win > TCP_MAXWIN)
			win = TCP_MAXWIN;
		th->th_win = htons((u_int16_t)win);
		th->th_off = sizeof (struct tcphdr) >> 2;
		tlen += sizeof(*th);
	} else
		tlen += th->th_off << 2;
	m->m_len = hlen + tlen;
	m->m_pkthdr.len = hlen + tlen;
	m->m_pkthdr.rcvif = (struct ifnet *) 0;
	th->th_flags = flags;
	th->th_urp = 0;

	switch (family) {
	case AF_INET:
	    {
		struct ipovly *ipov = (struct ipovly *)ip;
		memset(ipov->ih_x1, 0, sizeof ipov->ih_x1);
		ipov->ih_len = htons((u_int16_t)tlen);

		th->th_sum = 0;
		th->th_sum = in_cksum(m, hlen + tlen);
		ip->ip_len = hlen + tlen;	/*will be flipped on output*/
		ip->ip_ttl = ip_defttl;
		break;
	    }
	}


	if (tp != NULL && tp->t_inpcb != NULL) {
		ro = &tp->t_inpcb->inp_route;
	}
	else
		ro = NULL;

	switch (family) {
	case AF_INET:
		error = ip_output(m, NULL, ro,
		    (tp && tp->t_mtudisc ? IP_MTUDISC : 0),
		    NULL);
		break;
	default:
		error = EAFNOSUPPORT;
		break;
	}

	return (error);
}

struct tcpcb *
tcp_newtcpcb(int family, void *aux)
{
	struct tcpcb *tp;

	switch (family) {
	case PF_INET:
		break;
	default:
		return NULL;
	}

	tp = sceNetMallocInternal(sizeof(*tp));
	if (tp == NULL)
		return (NULL);
	memset((caddr_t)tp, 0, sizeof(struct tcpcb));
	LIST_INIT(&tp->segq);
	LIST_INIT(&tp->timeq);
	tp->t_family = family;		/* may be overridden later on */
	tp->t_peermss = tcp_mssdflt;
	tp->t_ourmss = tcp_mssdflt;
	tp->t_segsz = tcp_mssdflt;
	LIST_INIT(&tp->t_sc);

	tp->t_flags = 0;
	if (tcp_do_rfc1323 && tcp_do_win_scale)
		tp->t_flags |= TF_REQ_SCALE;
	if (tcp_do_rfc1323 && tcp_do_timestamps)
		tp->t_flags |= TF_REQ_TSTMP;
	if (tcp_do_sack == 2)
		tp->t_flags |= TF_WILL_SACK;
	else if (tcp_do_sack == 1)
		tp->t_flags |= TF_WILL_SACK|TF_IGNR_RXSACK;
	tp->t_flags |= TF_CANT_TXSACK;
	switch (family) {
	case PF_INET:
		tp->t_inpcb = (struct inpcb *)aux;
		tp->t_mtudisc = ip_mtudisc;
		break;
	}
	/*
	 * Init srtt to TCPTV_SRTTBASE (0), so we can tell that we have no
	 * rtt estimate.  Set rttvar so that srtt + 2 * rttvar gives
	 * reasonable initial retransmit time.
	 */
	tp->t_srtt = TCPTV_SRTTBASE;
	tp->t_rttvar = tcp_rttdflt * PR_SLOWHZ << (TCP_RTTVAR_SHIFT + 2 - 1);
	tp->t_rttmin = TCPTV_MIN;
	TCPT_RANGESET(tp->t_rxtcur, TCP_REXMTVAL(tp),
	    TCPTV_MIN, TCPTV_REXMTMAX);
	tp->snd_cwnd = TCP_MAXWIN << TCP_MAX_WINSHIFT;
	tp->snd_ssthresh = TCP_MAXWIN << TCP_MAX_WINSHIFT;
	if (family == AF_INET) {
		struct inpcb *inp = (struct inpcb *)aux;
		inp->inp_ip.ip_ttl = ip_defttl;
		inp->inp_ppcb = (caddr_t)tp;
	}
	return (tp);
}

struct tcpcb *
tcp_drop(struct tcpcb *tp, int errno)
{
	struct socket *so;

	if (tp->t_inpcb)
		so = tp->t_inpcb->inp_socket;
	else
		return NULL;

	if (TCPS_HAVERCVDSYN(tp->t_state)) {
		tp->t_state = TCPS_CLOSED;
		(void) tcp_output(tp);
		tcpstat.tcps_drops++;
	} else
		tcpstat.tcps_conndrops++;
	if (errno == ETIMEDOUT && tp->t_softerror)
		errno = tp->t_softerror;
	so->so_error = errno;
	return (tcp_close(tp));
}

struct tcpcb *
tcp_close(struct tcpcb *tp)
{
	struct inpcb *inp;
	struct socket *so;
#ifdef RTV_RTT
	struct rtentry *rt;
#endif
	struct route *ro;

	inp = tp->t_inpcb;
	so = NULL;
	ro = NULL;
	if (inp) {
		so = inp->inp_socket;
		ro = &inp->inp_route;
	}

#ifdef RTV_RTT
	/*
	 * If we sent enough data to get some meaningful characteristics,
	 * save them in the routing entry.  'Enough' is arbitrarily 
	 * defined as the sendpipesize (default 4K) * 16.  This would
	 * give us 16 rtt samples assuming we only get one sample per
	 * window (the usual case on a long haul net).  16 samples is
	 * enough for the srtt filter to converge to within 5% of the correct
	 * value; fewer samples and we could save a very bogus rtt.
	 *
	 * Don't update the default route's characteristics and don't
	 * update anything that the user "locked".
	 */
	if (SEQ_LT(tp->iss + so->so_snd.sb_hiwat * 16, tp->snd_max) &&
	    ro && (rt = ro->ro_rt) &&
	    !in_nullhost(satosin(rt_key(rt))->sin_addr)) {
		u_long i = 0;

		if ((rt->rt_rmx.rmx_locks & RTV_RTT) == 0) {
			i = tp->t_srtt *
			    ((RTM_RTTUNIT / PR_SLOWHZ) >> (TCP_RTT_SHIFT + 2));
			if (rt->rt_rmx.rmx_rtt && i)
				/*
				 * filter this update to half the old & half
				 * the new values, converting scale.
				 * See route.h and tcp_var.h for a
				 * description of the scaling constants.
				 */
				rt->rt_rmx.rmx_rtt =
				    (rt->rt_rmx.rmx_rtt + i) / 2;
			else
				rt->rt_rmx.rmx_rtt = i;
		}
		if ((rt->rt_rmx.rmx_locks & RTV_RTTVAR) == 0) {
			i = tp->t_rttvar *
			    ((RTM_RTTUNIT / PR_SLOWHZ) >> (TCP_RTTVAR_SHIFT + 2));
			if (rt->rt_rmx.rmx_rttvar && i)
				rt->rt_rmx.rmx_rttvar =
				    (rt->rt_rmx.rmx_rttvar + i) / 2;
			else
				rt->rt_rmx.rmx_rttvar = i;
		}
		/*
		 * update the pipelimit (ssthresh) if it has been updated
		 * already or if a pipesize was specified & the threshhold
		 * got below half the pipesize.  I.e., wait for bad news
		 * before we start updating, then update on both good
		 * and bad news.
		 */
		if (((rt->rt_rmx.rmx_locks & RTV_SSTHRESH) == 0 &&
		    (i = tp->snd_ssthresh) && rt->rt_rmx.rmx_ssthresh) ||
		    i < (rt->rt_rmx.rmx_sendpipe / 2)) {
			/*
			 * convert the limit from user data bytes to
			 * packets then to packet data bytes.
			 */
			i = (i + tp->t_segsz / 2) / tp->t_segsz;
			if (i < 2)
				i = 2;
			i *= (u_long)(tp->t_segsz + sizeof (struct tcpiphdr));
			if (rt->rt_rmx.rmx_ssthresh)
				rt->rt_rmx.rmx_ssthresh =
				    (rt->rt_rmx.rmx_ssthresh + i) / 2;
			else
				rt->rt_rmx.rmx_ssthresh = i;
		}
	}
#endif /* RTV_RTT */
	/* free the reassembly queue, if any */
	TCP_REASS_LOCK(tp);
	(void) tcp_freeq(tp);
	TCP_REASS_UNLOCK(tp);

	TCP_CLEAR_DELACK(tp);
	syn_cache_cleanup(tp);

	if (tp->t_template) {
		m_free(tp->t_template);
		tp->t_template = NULL;
	}
	sceNetFreeInternal(tp);
	if (inp) {
		inp->inp_ppcb = 0;
		soisdisconnected(so);
		in_pcbdetach(inp);
	}
	tcpstat.tcps_closed++;
	return ((struct tcpcb *)0);
}

int
tcp_freeq(struct tcpcb *tp)
{
	struct ipqent *qe;
	int rv = 0;
#ifdef TCPREASS_DEBUG
	int i = 0;
#endif

	TCP_REASS_LOCK_CHECK(tp);

	while ((qe = tp->segq.lh_first) != NULL) {
#ifdef TCPREASS_DEBUG
		printf("tcp_freeq[%p,%d]: %u:%u(%u) 0x%02x\n",
			tp, i++, qe->ipqe_seq, qe->ipqe_seq + qe->ipqe_len,
			qe->ipqe_len, qe->ipqe_flags & (TH_SYN|TH_FIN|TH_RST));
#endif
		LIST_REMOVE(qe, ipqe_q);
		LIST_REMOVE(qe, ipqe_timeq);
		m_freem(qe->ipqe_m);
		sceNetFreeInternal(qe);
		rv = 1;
	}
	return (rv);
}

void
tcp_drain()
{
	struct inpcb *inp;
	struct tcpcb *tp;

	/*
	 * Free the sequence queue of all TCP connections.
	 */
	inp = tcbtable.inpt_queue.cqh_first;
	if (inp)						/* XXX */
	for (; inp != (struct inpcb *)&tcbtable.inpt_queue;
	    inp = inp->inp_queue.cqe_next) {
		if ((tp = intotcpcb(inp)) != NULL) {
			/*
			 * We may be called from a device's interrupt
			 * context.  If the tcpcb is already busy,
			 * just bail out now.
			 */
			if (tcp_reass_lock_try(tp) == 0)
				continue;
			if (tcp_freeq(tp))
				tcpstat.tcps_connsdrained++;
			TCP_REASS_UNLOCK(tp);
		}
	}
}

void
tcp_notify(struct inpcb *inp, int error)
{
	struct tcpcb *tp = (struct tcpcb *)inp->inp_ppcb;
	struct socket *so = inp->inp_socket;

	/*
	 * Ignore some errors if we are hooked up.
	 * If connection hasn't completed, has retransmitted several times,
	 * and receives a second error, give up now.  This is better
	 * than waiting a long time to establish a connection that
	 * can never complete.
	 */
	if (tp->t_state == TCPS_ESTABLISHED &&
	     (error == EHOSTUNREACH || error == ENETUNREACH ||
	      error == EHOSTDOWN)) {
		return;
	} else if (TCPS_HAVEESTABLISHED(tp->t_state) == 0 &&
	    tp->t_rxtshift > 3 && tp->t_softerror)
		so->so_error = error;
	else 
		tp->t_softerror = error;
	wakeup((caddr_t) &so->so_timeo);
	sorwakeup(so);
	sowwakeup(so);
}

void *
tcp_ctlinput(int cmd, struct sockaddr *sa, void *v)
{
	struct ip *ip = v;
	struct tcphdr *th;
	struct icmp *icp;
	void (*notify) (struct inpcb *, int) = tcp_notify;
	int errno;
	int nmatch;

	if (sa->sa_family != AF_INET ||
	    sa->sa_len != sizeof(struct sockaddr_in))
		return NULL;
	if ((unsigned)cmd >= PRC_NCMDS)
		return NULL;
	errno = inetctlerrmap[cmd];
	if (cmd == PRC_QUENCH)
		notify = tcp_quench;
	else if (PRC_IS_REDIRECT(cmd))
		notify = in_rtchange, ip = 0;
	else if (cmd == PRC_MSGSIZE && ip && ip->ip_v == 4) {
		/*
		 * Check to see if we have a valid TCP connection
		 * corresponding to the address in the ICMP message
		 * payload.
		 *
		 * Boundary check is made in icmp_input(), with ICMP_ADVLENMIN.
		 */
		th = (struct tcphdr *)((caddr_t)ip + (ip->ip_hl << 2));
		if (in_pcblookup_connect(&tcbtable, ip->ip_dst, th->th_dport,
		    ip->ip_src, th->th_sport) != NULL)
			;
		else
			return NULL;

		/*
		 * Now that we've validated that we are actually communicating
		 * with the host indicated in the ICMP message, locate the
		 * ICMP header, recalculate the new MTU, and create the
		 * corresponding routing entry.
		 */
		icp = (struct icmp *)((caddr_t)ip -
		    offsetof(struct icmp, icmp_ip));
		icmp_mtudisc(icp, ip->ip_dst);

		return NULL;
	} else if (cmd == PRC_HOSTDEAD)
		ip = 0;
	else if (errno == 0)
		return NULL;
	if (ip && ip->ip_v == 4 && sa->sa_family == AF_INET) {
		th = (struct tcphdr *)((caddr_t)ip + (ip->ip_hl << 2));
		nmatch = in_pcbnotify(&tcbtable, satosin(sa)->sin_addr,
		    th->th_dport, ip->ip_src, th->th_sport, errno, notify);
		if (nmatch == 0 && syn_cache_count &&
		    (inetctlerrmap[cmd] == EHOSTUNREACH ||
		    inetctlerrmap[cmd] == ENETUNREACH ||
		    inetctlerrmap[cmd] == EHOSTDOWN)) {
			struct sockaddr_in sin;
			memset(&sin, 0, sizeof(sin));
			sin.sin_len = sizeof(sin);
			sin.sin_family = AF_INET;
			sin.sin_port = th->th_sport;
			sin.sin_addr = ip->ip_src;
			syn_cache_unreach((struct sockaddr *)&sin, sa, th);
		}

		/* XXX mapped address case */
	} else
		in_pcbnotifyall(&tcbtable, satosin(sa)->sin_addr, errno,
		    notify);
	return NULL;
}

void
tcp_quench(struct inpcb *inp, int errno)
{
	struct tcpcb *tp = intotcpcb(inp);

	if (tp)
		tp->snd_cwnd = tp->t_segsz;
}

void
tcp_mtudisc_callback(struct in_addr faddr)
{

	in_pcbnotifyall(&tcbtable, faddr, EMSGSIZE, tcp_mtudisc);
}

void
tcp_mtudisc(struct inpcb *inp, int errno)
{
	struct tcpcb *tp = intotcpcb(inp);
	struct rtentry *rt = in_pcbrtentry(inp);

	if (tp != 0) {
		if (rt != 0) {
			/*
			 * If this was not a host route, remove and realloc.
			 */
			if ((rt->rt_flags & RTF_HOST) == 0) {
				in_rtchange(inp, errno);
				if ((rt = in_pcbrtentry(inp)) == 0)
					return;
			}

			/*
			 * Slow start out of the error condition.  We
			 * use the MTU because we know it's smaller
			 * than the previously transmitted segment.
			 *
			 * Note: This is more conservative than the
			 * suggestion in draft-floyd-incr-init-win-03.
			 */
			if (rt->rt_rmx.rmx_mtu != 0)
				tp->snd_cwnd =
				    TCP_INITIAL_WINDOW(tcp_init_win,
				    rt->rt_rmx.rmx_mtu);
		}
	    
		/*
		 * Resend unacknowledged packets.
		 */
		tp->snd_nxt = tp->snd_una;
		tcp_output(tp);
	}
}

u_long
tcp_mss_to_advertise(const struct ifnet *ifp, int af)
{
	extern u_long in_maxmtu;
	u_long mss = 0;
	u_long hdrsiz;

	/*
	 * In order to avoid defeating path MTU discovery on the peer,
	 * we advertise the max MTU of all attached networks as our MSS,
	 * per RFC 1191, section 3.1.
	 *
	 * We provide the option to advertise just the MTU of
	 * the interface on which we hope this connection will
	 * be receiving.  If we are responding to a SYN, we
	 * will have a pretty good idea about this, but when
	 * initiating a connection there is a bit more doubt.
	 *
	 * We also need to ensure that loopback has a large enough
	 * MSS, as the loopback MTU is never included in in_maxmtu.
	 */

	if (ifp != NULL)
		mss = ifp->if_mtu;

	if (tcp_mss_ifmtu == 0)
		mss = max(in_maxmtu, mss);

	switch (af) {
	case AF_INET:
		hdrsiz = sizeof(struct ip);
		break;
	default:
		hdrsiz = 0;
		break;
	}
	hdrsiz += sizeof(struct tcphdr);
	if (mss > hdrsiz)
		mss -= hdrsiz;

	mss = max(tcp_mssdflt, mss);
	return (mss);
}

void
tcp_mss_from_peer(struct tcpcb *tp, int offer)
{
	struct socket *so;
#if defined(RTV_SPIPE) || defined(RTV_SSTHRESH)
	struct rtentry *rt;
#endif
	u_long bufsize;
	int mss;

	so = NULL;
	rt = NULL;
	if (tp->t_inpcb) {
		so = tp->t_inpcb->inp_socket;
#if defined(RTV_SPIPE) || defined(RTV_SSTHRESH)
		rt = in_pcbrtentry(tp->t_inpcb);
#endif
	}

	/*
	 * As per RFC1122, use the default MSS value, unless they 
	 * sent us an offer.  Do not accept offers less than 32 bytes.
	 */
	mss = tcp_mssdflt;
	if (offer)
		mss = offer;
	mss = max(mss, 32);		/* sanity */
	tp->t_peermss = mss;
	mss -= tcp_optlen(tp);
	if (tp->t_inpcb)
		mss -= ip_optlen(tp->t_inpcb);

	/*
	 * If there's a pipesize, change the socket buffer to that size.
	 * Make the socket buffer an integral number of MSS units.  If
	 * the MSS is larger than the socket buffer, artificially decrease
	 * the MSS.
	 */
#ifdef RTV_SPIPE
	if (rt != NULL && rt->rt_rmx.rmx_sendpipe != 0)
		bufsize = rt->rt_rmx.rmx_sendpipe;
	else
#endif
		bufsize = so->so_snd.sb_hiwat;
	if (bufsize < mss)
		mss = bufsize;
	else {
		bufsize = roundup(bufsize, mss);
		if (bufsize > SB_MAX)
			bufsize = SB_MAX;
		(void) sbreserve(&so->so_snd, bufsize);
	}
	tp->t_segsz = mss;

#ifdef RTV_SSTHRESH
	if (rt != NULL && rt->rt_rmx.rmx_ssthresh) {
		/*
		 * There's some sort of gateway or interface buffer
		 * limit on the path.  Use this to set the slow
		 * start threshold, but set the threshold to no less
		 * than 2 * MSS.
		 */
		tp->snd_ssthresh = max(2 * mss, rt->rt_rmx.rmx_ssthresh);
	}
#endif
}

void
tcp_established(struct tcpcb *tp)
{
	struct socket *so;
#ifdef RTV_RPIPE
	struct rtentry *rt;
#endif
	u_long bufsize;

	so = NULL;
	rt = NULL;
	if (tp->t_inpcb) {
		so = tp->t_inpcb->inp_socket;
#if defined(RTV_RPIPE)
		rt = in_pcbrtentry(tp->t_inpcb);
#endif
	}

	tp->t_state = TCPS_ESTABLISHED;
	TCP_TIMER_ARM(tp, TCPT_KEEP, tcp_keepidle);

#ifdef RTV_RPIPE
	if (rt != NULL && rt->rt_rmx.rmx_recvpipe != 0)
		bufsize = rt->rt_rmx.rmx_recvpipe;
	else
#endif
		bufsize = so->so_rcv.sb_hiwat;
	if (bufsize > tp->t_ourmss) {
		bufsize = roundup(bufsize, tp->t_ourmss);
		if (bufsize > SB_MAX)
			bufsize = SB_MAX;
		(void) sbreserve(&so->so_rcv, bufsize);
	}
}

void
tcp_rmx_rtt(struct tcpcb *tp)
{
#ifdef RTV_RTT
	struct rtentry *rt = NULL;
	int rtt;

	if (tp->t_inpcb)
		rt = in_pcbrtentry(tp->t_inpcb);
	if (rt == NULL)
		return;

	if (tp->t_srtt == 0 && (rtt = rt->rt_rmx.rmx_rtt)) {
		/*
		 * XXX The lock bit for MTU indicates that the value
		 * is also a minimum value; this is subject to time.
		 */
		if (rt->rt_rmx.rmx_locks & RTV_RTT)
			TCPT_RANGESET(tp->t_rttmin,
			    rtt / (RTM_RTTUNIT / PR_SLOWHZ),
			    TCPTV_MIN, TCPTV_REXMTMAX);
		tp->t_srtt = rtt /
		    ((RTM_RTTUNIT / PR_SLOWHZ) >> (TCP_RTT_SHIFT + 2));
		if (rt->rt_rmx.rmx_rttvar) {
			tp->t_rttvar = rt->rt_rmx.rmx_rttvar /
			    ((RTM_RTTUNIT / PR_SLOWHZ) >>
				(TCP_RTTVAR_SHIFT + 2));
		} else {
			/* Default variation is +- 1 rtt */
			tp->t_rttvar =
			    tp->t_srtt >> (TCP_RTT_SHIFT - TCP_RTTVAR_SHIFT);
		}
		TCPT_RANGESET(tp->t_rxtcur,
		    ((tp->t_srtt >> 2) + tp->t_rttvar) >> (1 + 2),
		    tp->t_rttmin, TCPTV_REXMTMAX);
	}
#endif
}

tcp_seq
tcp_new_iss(void *tp, u_long len, tcp_seq addin)
{
	tcp_seq          tcp_iss;

	/*
	 * Randomize.
	 */
#if NRND > 0
	rnd_extract_data(&tcp_iss, sizeof(tcp_iss), RND_EXTRACT_ANY);
#else
	tcp_iss = sceNetRand();
#endif

	/*
	 * If we were asked to add some amount to a known value,
	 * we will take a random value obtained above, mask off the upper
	 * bits, and add in the known value.  We also add in a constant to
	 * ensure that we are at least a certain distance from the original
	 * value.
	 *
	 * This is used when an old connection is in timed wait
	 * and we have a new one coming in, for instance.
	 */
	if (addin != 0) {
#ifdef TCPISS_DEBUG
		printf("Random %08x, ", tcp_iss);
#endif
		tcp_iss &= TCP_ISS_RANDOM_MASK;
		tcp_iss += addin + TCP_ISSINCR;
#ifdef TCPISS_DEBUG
		printf("Old ISS %08x, ISS %08x\n", addin, tcp_iss);
#endif
	} else {
		tcp_iss &= TCP_ISS_RANDOM_MASK;
		tcp_iss += tcp_iss_seq;
		tcp_iss_seq += TCP_ISSINCR;
#ifdef TCPISS_DEBUG
		printf("ISS %08x\n", tcp_iss);
#endif
	}

	if (tcp_compat_42) {
		/*
		 * Limit it to the positive range for really old TCP
		 * implementations.
		 */
		if (tcp_iss >= 0x80000000)
			tcp_iss &= 0x7fffffff;		/* XXX */
	}

	return tcp_iss;
}

u_int
tcp_optlen(struct tcpcb *tp)
{
	if ((tp->t_flags & (TF_REQ_TSTMP|TF_RCVD_TSTMP|TF_NOOPT)) == 
	    (TF_REQ_TSTMP | TF_RCVD_TSTMP))
		return TCPOLEN_TSTAMP_APPA;
	else
		return 0;
}

