/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

#define syn_cache_last D_0002EC28
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
INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/tcp_timer", func_00025940);

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
