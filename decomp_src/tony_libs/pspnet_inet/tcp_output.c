/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

#define tcp_output func_00022D7C
#define tcp_setpersist func_00023BE4
#define tcp_segsize func_00023C74
#define tcp_optlen func_000251A4
#define tcp_quench func_0002544C
#define tcp_mss_to_advertise func_0002559C
u_int tcp_optlen(struct tcpcb *tp);
void tcp_quench(struct inpcb *inp, int errno);
u_long tcp_mss_to_advertise(const struct ifnet *ifp, int af);
void tcp_setpersist(struct tcpcb *tp);
#define MAX_TCPOPTLEN 32

static void tcp_segsize(struct tcpcb *, int *, int *);

/*
 * Tcp output routine: figure out what should be sent and send it.
 */
INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/tcp_output", func_00022D7C);

__attribute__((noinline)) void
tcp_setpersist(struct tcpcb *tp)
{
	int t = ((tp->t_srtt >> 2) + tp->t_rttvar) >> (1 + 2);
	int nticks;

	/*
	 * Start/restart persistance timer.
	 */
	if (t < tp->t_rttmin)
		t = tp->t_rttmin;
	TCPT_RANGESET(nticks, t * tcp_backoff[tp->t_rxtshift],
	    TCPTV_PERSMIN, TCPTV_PERSMAX);
	TCP_TIMER_ARM(tp, TCPT_PERSIST, nticks);
	if (tp->t_rxtshift < TCP_MAXRXTSHIFT)
		tp->t_rxtshift++;
}
static __attribute__((used)) void
tcp_segsize(struct tcpcb *tp, int *txsegsizep, int *rxsegsizep)
{
	struct inpcb *inp = tp->t_inpcb;
	struct rtentry *rt;
	struct ifnet *ifp;
	int size;
	int iphlen;

	switch (tp->t_family) {
	case AF_INET:
		iphlen = sizeof(struct ip);
		break;
	default:
		size = tcp_mssdflt;
		goto out;
	}

	if (inp)
		rt = in_pcbrtentry(inp);
	else
		rt = NULL;
	if (rt == NULL) {
		size = tcp_mssdflt;
		goto out;
	}

	ifp = rt->rt_ifp;

	size = tcp_mssdflt;
	if (tp->t_mtudisc && rt->rt_rmx.rmx_mtu != 0)
		size = rt->rt_rmx.rmx_mtu - iphlen - sizeof(struct tcphdr);
	else if (tp->t_mtudisc || ifp->if_flags & IFF_LOOPBACK)
		size = ifp->if_mtu - iphlen - sizeof(struct tcphdr);
	else if (inp && in_localaddr(inp->inp_faddr))
		size = ifp->if_mtu - iphlen - sizeof(struct tcphdr);
	size -= tcp_optlen(tp);
	if (inp) {
		size -= ip_optlen(inp);
	}

 out:
	*txsegsizep = min(tp->t_peermss, size);
	*rxsegsizep = min(tp->t_ourmss, size);

	if (*txsegsizep != tp->t_segsz) {
		if (*txsegsizep < tp->t_segsz) {
			tp->snd_cwnd = max((tp->snd_cwnd / tp->t_segsz) 
					   * *txsegsizep, *txsegsizep);
			tp->snd_ssthresh = max((tp->snd_ssthresh / tp->t_segsz) 
						* *txsegsizep, *txsegsizep);
		}
		tp->t_segsz = *txsegsizep;
	}
}

__asm__(".globl func_00023C74");
