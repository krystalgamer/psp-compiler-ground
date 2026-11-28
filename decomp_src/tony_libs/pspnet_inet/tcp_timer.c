/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

extern int syn_cache_last;
#define tcp_output func_00022D7C
#define tcp_usrreq func_00025EE0
#define syn_cache_timer func_00021028
#define tcp_close func_000248E8
#define tcp_drop func_000251C0
#define tcp_respond func_00024124
#define tcp_setpersist func_00023BE4
#define tcp_fasttimo func_00025E14
#define tcp_slowtimo func_00025768
#define tcp_canceltimers func_00025E74
#define tcp_timers func_00025940
#define tcp_timer_init func_00025E94
int tcp_output(struct tcpcb *tp);
int tcp_usrreq(struct socket *so, int req, struct mbuf *m, struct mbuf *nam, struct mbuf *control);
void syn_cache_timer(void);
struct tcpcb *tcp_close(struct tcpcb *tp);
struct tcpcb *tcp_drop(struct tcpcb *tp, int errno);
int tcp_respond(struct tcpcb *tp, struct mbuf *template, struct mbuf *m, struct tcphdr *th0, tcp_seq ack, tcp_seq seq, int flags);
void tcp_setpersist(struct tcpcb *tp);

/*
 * Fast timeout routine for processing delayed acks
 */
void
tcp_fasttimo(void)
{
	struct tcpcb *tp, *ntp;
	int s;

	s = _sce_pspnet_spllock();
	for (tp = tcp_delacks.lh_first; tp != NULL; tp = ntp) {
		ntp = tp->t_delack.le_next;
		tp->t_flags |= TF_ACKNOW;
		(void) tcp_output(tp);
	}
	_sce_pspnet_splunlock(s);
}

void
tcp_slowtimo(void)
{
	struct inpcb *inp, *ninp;
	struct tcpcb *tp;
	int s;
	long i;
	int skip, mask;

	skip = mask = 0;

	s = _sce_pspnet_spllock();
	tcp_maxidle = tcp_keepcnt * tcp_keepintvl;
	mask |= 1;
	inp = tcbtable.inpt_queue.cqh_first;
	if (inp == (struct inpcb *)0) {				/* XXX */
		skip |= 1;
		goto dotcb6;
	}
	for (; inp != (struct inpcb *)&tcbtable.inpt_queue; inp = ninp) {
		ninp = inp->inp_queue.cqe_next;
		tp = intotcpcb(inp);
		if (tp == 0 || tp->t_state == TCPS_LISTEN)
			continue;
		for (i = 0; i < TCPT_NTIMERS; i++) {
			if (TCP_TIMER_ISEXPIRED(tp, i)) {
				TCP_TIMER_DISARM(tp, i);
				(void) tcp_usrreq(tp->t_inpcb->inp_socket,
				    PRU_SLOWTIMO, (struct mbuf *)0,
				    (struct mbuf *)i, (struct mbuf *)0);
				/* XXX NOT MP SAFE */
				if ((ninp == (void *)&tcbtable.inpt_queue &&
				    tcbtable.inpt_queue.cqh_last != inp) ||
				    ninp->inp_queue.cqe_prev != inp)
					goto tpgone;
			}
		}
		tp->t_idle++;
		if (tp->t_rtt)
			tp->t_rtt++;
tpgone:
		;
	}
dotcb6:
	if (mask == skip)
		goto done;
	tcp_iss_seq += TCP_ISSINCR;			/* increment iss */
	tcp_now++;					/* for timestamps */
	if (++syn_cache_last >= tcp_syn_cache_interval) {
		syn_cache_timer();
		syn_cache_last = 0;
	}
done:
	_sce_pspnet_splunlock(s);
}

/*
 * Cancel all timers for TCP tp.
 */
void
tcp_canceltimers(struct tcpcb *tp)
{
	int i;

	for (i = 0; i < TCPT_NTIMERS; i++)
		TCP_TIMER_DISARM(tp, i);
}

/*
 * TCP timer processing.
 */
struct tcpcb *
tcp_timers(struct tcpcb *tp, int timer)
{
	short	rto;

	switch (timer) {

	case TCPT_2MSL:
		if (tp->t_state != TCPS_TIME_WAIT &&
		    ((tcp_maxidle == 0) || (tp->t_idle <= tcp_maxidle)))
			TCP_TIMER_ARM(tp, TCPT_2MSL, tcp_keepintvl);
		else
			tp = tcp_close(tp);
		break;

	case TCPT_REXMT:
		if (++tp->t_rxtshift > TCP_MAXRXTSHIFT) {
			tp->t_rxtshift = TCP_MAXRXTSHIFT;
			tcpstat.tcps_timeoutdrop++;
			tp = tcp_drop(tp, tp->t_softerror ?
			    tp->t_softerror : ETIMEDOUT);
			break;
		}
		tcpstat.tcps_rexmttimeo++;
		rto = TCP_REXMTVAL(tp);
		if (rto < tp->t_rttmin)
			rto = tp->t_rttmin;
		TCPT_RANGESET(tp->t_rxtcur, rto * tcp_backoff[tp->t_rxtshift],
		    tp->t_rttmin, TCPTV_REXMTMAX);
		TCP_TIMER_ARM(tp, TCPT_REXMT, tp->t_rxtcur);
		if (ip_mtudisc && tp->t_rxtshift > TCP_MAXRXTSHIFT / 6) {
			tcpstat.tcps_pmtublackhole++;
			if (tp->t_inpcb)
				tp->t_mtudisc = 0;
		}
		if (tp->t_rxtshift > TCP_MAXRXTSHIFT / 4) {
			if (tp->t_inpcb)
				in_losing(tp->t_inpcb);
			tp->t_rttvar += (tp->t_srtt >> TCP_RTT_SHIFT);
			tp->t_srtt = 0;
		}
		tp->snd_nxt = tp->snd_una;
		tp->t_rtt = 0;
		if (tp->t_state == TCPS_SYN_SENT)
			tp->t_flags |= TF_SYN_REXMT;
		{
		u_int win = min(tp->snd_wnd, tp->snd_cwnd) / 2 / tp->t_segsz;
		if (win < 2)
			win = 2;
		tp->snd_cwnd = tp->t_segsz;
		tp->snd_ssthresh = win * tp->t_segsz;
		tp->t_dupacks = 0;
		}
		(void) tcp_output(tp);
		break;

	case TCPT_PERSIST:
		rto = TCP_REXMTVAL(tp);
		if (rto < tp->t_rttmin)
			rto = tp->t_rttmin;
		if (tp->t_rxtshift == TCP_MAXRXTSHIFT &&
		    (tp->t_idle >= tcp_maxpersistidle ||
		    tp->t_idle >= rto * tcp_totbackoff)) {
			tcpstat.tcps_persistdrops++;
			tp = tcp_drop(tp, ETIMEDOUT);
			break;
		}
		tcpstat.tcps_persisttimeo++;
		tcp_setpersist(tp);
		tp->t_force = 1;
		(void) tcp_output(tp);
		tp->t_force = 0;
		break;

	case TCPT_KEEP:
	    {
		struct socket *so = NULL;

		tcpstat.tcps_keeptimeo++;
		if (TCPS_HAVEESTABLISHED(tp->t_state) == 0)
			goto dropit;
		if (tp->t_inpcb)
			so = tp->t_inpcb->inp_socket;
		if (so->so_options & SO_KEEPALIVE &&
		    tp->t_state <= TCPS_CLOSE_WAIT) {
		    	if ((tcp_maxidle > 0) &&
			    (tp->t_idle >= tcp_keepidle + tcp_maxidle))
				goto dropit;
			tcpstat.tcps_keepprobe++;
			if (tcp_compat_42) {
				(void)tcp_respond(tp, tp->t_template,
				    (struct mbuf *)NULL, NULL, tp->rcv_nxt - 1,
				    tp->snd_una - 1, 0);
			} else {
				(void)tcp_respond(tp, tp->t_template,
				    (struct mbuf *)NULL, NULL, tp->rcv_nxt,
				    tp->snd_una - 1, 0);
			}
			TCP_TIMER_ARM(tp, TCPT_KEEP, tcp_keepintvl);
		} else
			TCP_TIMER_ARM(tp, TCPT_KEEP, tcp_keepidle);
		break;
	    }
	dropit:
		tcpstat.tcps_keepdrops++;
		tp = tcp_drop(tp, ETIMEDOUT);
		break;
	}
	return (tp);
}

void
tcp_timer_init(void)
{
	tcp_keepidle = TCPTV_KEEP_IDLE;
	tcp_totbackoff = 511;
	tcp_keepintvl = TCPTV_KEEPINTVL;
	tcp_keepcnt = TCPTV_KEEPCNT;
	tcp_maxpersistidle = TCPTV_KEEP_IDLE;
	tcp_maxidle = 0;
	syn_cache_last = 0;
}
