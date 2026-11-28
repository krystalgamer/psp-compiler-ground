/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

#define TCPCTL_STATS 25
extern struct {
	 unsigned int valid : 1;
	 unsigned int rdonly : 1;
	 int *var;
	 int val;
} tcp_ctlvars[26];
#define tcp_output func_00022D7C
#define tcp_usrreq func_00025EE0
#define tcp_ctloutput func_000263E0
#define tcp_attach func_000265F0
#define tcp_disconnect func_000266D8
#define tcp_usrclosed func_0002678C
#define tcp_sysctl func_00026858
#define tcp_usrreq_init func_00026930
#define tcp_close func_000248E8
#define tcp_drop func_000251C0
#define tcp_timers func_00025940
#define tcp_template func_00023F58
#define tcp_newtcpcb func_00024738
#define tcp_new_iss func_000256DC
int tcp_output(struct tcpcb *tp);
struct tcpcb *tcp_close(struct tcpcb *tp);
struct tcpcb *tcp_drop(struct tcpcb *tp, int errno);
struct tcpcb *tcp_timers(struct tcpcb *tp, int timer);
struct mbuf *tcp_template(struct tcpcb *tp);
struct tcpcb *tcp_newtcpcb(int family, void *aux);
tcp_seq tcp_new_iss(struct tcpcb *tp, u_long len, tcp_seq addin);
int tcp_attach(struct socket *so);
struct tcpcb *tcp_disconnect(struct tcpcb *tp);
struct tcpcb *tcp_usrclosed(struct tcpcb *tp);

int
tcp_usrreq(struct socket *so, int req, struct mbuf *m, struct mbuf *nam, struct mbuf *control)
{
	struct inpcb *inp;
	struct tcpcb *tp = NULL;
	int s;
	int error = 0;
	int ostate;
	int family;	/* family of the socket */

	family = so->so_proto->pr_domain->dom_family;

	if (req == PRU_CONTROL) {
		switch (family) {
		case PF_INET:
			return (in_control(so, (long)m, (caddr_t)nam,
			    (struct ifnet *)control));
		default:
			return EAFNOSUPPORT;
		}
	}

	if (req == PRU_PURGEIF) {
		switch (family) {
		case PF_INET:
			in_purgeif((struct ifnet *)control);
			in_pcbpurgeif(&tcbtable, (struct ifnet *)control);
			break;
		default:
			return (EAFNOSUPPORT);
		}
		return (0);
	}

	s = _sce_pspnet_spllock();
	switch (family) {
	case PF_INET:
		inp = sotoinpcb(so);
		break;
	default:
		_sce_pspnet_splunlock(s);
		return EAFNOSUPPORT;
	}

	/*
	 * When a TCP is attached to a socket, then there will be
	 * a (struct inpcb) pointed at by the socket, and this
	 * structure will point at a subsidary (struct tcpcb).
	 */
	if (inp == 0 && req != PRU_ATTACH)
	{
		error = EINVAL;
		goto release;
	}
	if (inp) {
		tp = intotcpcb(inp);
		/* WHAT IF TP IS 0? */
		ostate = tp->t_state;
	}
	else
		ostate = 0;

	switch (req) {

	/*
	 * TCP attaches to socket via PRU_ATTACH, reserving space,
	 * and an internet control block.
	 */
	case PRU_ATTACH:
		if (inp != 0)
		{
			error = EISCONN;
			break;
		}
		error = tcp_attach(so);
		if (error)
			break;
		if ((so->so_options & SO_LINGER) && so->so_linger == 0)
			so->so_linger = TCP_LINGERTIME;
		tp = sototcpcb(so);
		break;

	/*
	 * PRU_DETACH detaches the TCP protocol from the socket.
	 */
	case PRU_DETACH:
		tp = tcp_disconnect(tp);
		break;

	/*
	 * Give the socket an address.
	 */
	case PRU_BIND:
		switch (family) {
		case PF_INET:
			error = in_pcbbind(inp, nam);
			break;
		}
		break;

	/*
	 * Prepare to accept connections.
	 */
	case PRU_LISTEN:
		if (inp && inp->inp_lport == 0) {
			error = in_pcbbind(inp, (struct mbuf *)0);
			if (error)
				break;
		}
		tp->t_state = TCPS_LISTEN;
		break;

	/*
	 * Initiate connection to peer.
	 * Create a template for use in transmissions on this connection.
	 * Enter SYN_SENT state, and mark socket as connecting.
	 * Start keep-alive timer, and seed output sequence space.
	 * Send initial segment on connection.
	 */
	case PRU_CONNECT:
		if (inp) {
			if (inp->inp_lport == 0) {
				error = in_pcbbind(inp, (struct mbuf *)0);
				if (error)
					break;
			}
			error = in_pcbconnect(inp, nam);
		}
		if (error)
			break;
		tp->t_template = tcp_template(tp);
		if (tp->t_template == 0) {
			if (inp)
				in_pcbdisconnect(inp);
			error = ENOBUFS;
			break;
		}
		/* Compute window scaling to request.  */
		while (tp->request_r_scale < TCP_MAX_WINSHIFT &&
		    (TCP_MAXWIN << tp->request_r_scale) < so->so_rcv.sb_hiwat)
			tp->request_r_scale++;
		soisconnecting(so);
		tcpstat.tcps_connattempt++;
		tp->t_state = TCPS_SYN_SENT;
		TCP_TIMER_ARM(tp, TCPT_KEEP, TCPTV_KEEP_INIT);
		tp->iss = tcp_new_iss(tp, sizeof(struct tcpcb), 0);
		tcp_sendseqinit(tp);
		error = tcp_output(tp);
		break;

	/*
	 * Create a TCP connection between two sockets.
	 */
	case PRU_CONNECT2:
		error = EOPNOTSUPP;
		break;

	/*
	 * Initiate disconnect from peer.
	 * If connection never passed embryonic stage, just drop;
	 * else if don't need to let data drain, then can just drop anyways,
	 * else have to begin TCP shutdown process: mark socket disconnecting,
	 * drain unread data, state switch to reflect user close, and
	 * send segment (e.g. FIN) to peer.  Socket will be really disconnected
	 * when peer sends FIN and acks ours.
	 *
	 * SHOULD IMPLEMENT LATER PRU_CONNECT VIA REALLOC TCPCB.
	 */
	case PRU_DISCONNECT:
		tp = tcp_disconnect(tp);
		break;

	/*
	 * Accept a connection.  Essentially all the work is
	 * done at higher levels; just return the address
	 * of the peer, storing through addr.
	 */
	case PRU_ACCEPT:
		if (inp)
			in_setpeeraddr(inp, nam);
		break;

	/*
	 * Mark the connection as being incapable of further output.
	 */
	case PRU_SHUTDOWN:
		socantsendmore(so);
		tp = tcp_usrclosed(tp);
		if (tp)
			error = tcp_output(tp);
		break;

	/*
	 * After a receive, possibly send window update to peer.
	 */
	case PRU_RCVD:
		(void) tcp_output(tp);
		break;

	/*
	 * Do a send by putting data in output queue and updating urgent
	 * marker if URG set.  Possibly send more data.
	 */
	case PRU_SEND:
		if (control && control->m_len) {
			m_freem(control);
			m_freem(m);
			error = EINVAL;
			break;
		}
		sbappend(&so->so_snd, m);
		error = tcp_output(tp);
		break;

	/*
	 * Abort the TCP.
	 */
	case PRU_ABORT:
		tp = tcp_drop(tp, ECONNABORTED);
		break;

	case PRU_SENSE:
		/*
		 * stat: don't bother with a blocksize.
		 */
		_sce_pspnet_splunlock(s);
		return (0);

	case PRU_RCVOOB:
		if (control && control->m_len) {
			m_freem(control);
			m_freem(m);
			error = EINVAL;
			break;
		}
		if ((so->so_oobmark == 0 &&
		    (so->so_state & SS_RCVATMARK) == 0) ||
		    so->so_options & SO_OOBINLINE ||
		    tp->t_oobflags & TCPOOB_HADDATA) {
			error = EINVAL;
			break;
		}
		if ((tp->t_oobflags & TCPOOB_HAVEDATA) == 0) {
			error = EWOULDBLOCK;
			break;
		}
		m->m_len = 1;
		*mtod(m, caddr_t) = tp->t_iobc;
		if (((long)nam & MSG_PEEK) == 0)
			tp->t_oobflags ^= (TCPOOB_HAVEDATA | TCPOOB_HADDATA);
		break;

	case PRU_SENDOOB:
		if (sbspace(&so->so_snd) < -512) {
			m_freem(m);
			error = ENOBUFS;
			break;
		}
		/*
		 * According to RFC961 (Assigned Protocols),
		 * the urgent pointer points to the last octet
		 * of urgent data.  We continue, however,
		 * to consider it to indicate the first octet
		 * of data past the urgent section.
		 * Otherwise, snd_up should be one lower.
		 */
		sbappend(&so->so_snd, m);
		tp->snd_up = tp->snd_una + so->so_snd.sb_cc;
		tp->t_force = 1;
		error = tcp_output(tp);
		tp->t_force = 0;
		break;

	case PRU_SOCKADDR:
		if (inp)
			in_setsockaddr(inp, nam);
		break;

	case PRU_PEERADDR:
		if (inp)
			in_setpeeraddr(inp, nam);
		break;

	/*
	 * TCP slow timer went off; going through this
	 * routine for tracing's sake.
	 */
	case PRU_SLOWTIMO:
		tp = tcp_timers(tp, (long)nam);
		req |= (long)nam << 8;		/* for debug's sake */
		break;

	default:
		break;
	}

release:
	_sce_pspnet_splunlock(s);
	return (error);
}

int
tcp_ctloutput(int op, struct socket *so, int level, int optname, struct mbuf **mp)
{
	int error = 0, s;
	struct inpcb *inp;
	struct tcpcb *tp;
	struct mbuf *m;
	int i;
	int family;	/* family of the socket */

	family = so->so_proto->pr_domain->dom_family;

	s = _sce_pspnet_spllock();
	switch (family) {
	case PF_INET:
		inp = sotoinpcb(so);
		break;
	default:
		_sce_pspnet_splunlock(s);
		return EAFNOSUPPORT;
	}
	if (inp == NULL)
	{
		_sce_pspnet_splunlock(s);
		if (op == PRCO_SETOPT && *mp)
			(void) m_free(*mp);
		return (ECONNRESET);
	}
	if (level != IPPROTO_TCP) {
		switch (family) {
		case PF_INET:
			error = ip_ctloutput(op, so, level, optname, mp);
			break;
		}
		_sce_pspnet_splunlock(s);
		return (error);
	}
	if (inp)
		tp = intotcpcb(inp);
	else
		tp = NULL;

	switch (op) {

	case PRCO_SETOPT:
		m = *mp;
		switch (optname) {

		case TCP_NODELAY:
			if (m == NULL || m->m_len < sizeof (int))
				error = EINVAL;
			else if (*mtod(m, int *))
				tp->t_flags |= TF_NODELAY;
			else
				tp->t_flags &= ~TF_NODELAY;
			break;

		case TCP_MAXSEG:
			if (m && (i = *mtod(m, int *)) > 0 && 
			    i <= tp->t_peermss)
				tp->t_peermss = i;  /* limit on send size */
			else
				error = EINVAL;
			break;

		default:
			error = ENOPROTOOPT;
			break;
		}
		if (m)
			(void) m_free(m);
		break;

	case PRCO_GETOPT:
		*mp = m = m_get(M_WAIT, MT_SOOPTS);
		if (m == NULL) {
			error = ENOBUFS;
			break;
		}
		m->m_len = sizeof(int);

		switch (optname) {
		case TCP_NODELAY:
			*mtod(m, int *) = tp->t_flags & TF_NODELAY;
			break;
		case TCP_MAXSEG:
			*mtod(m, int *) = tp->t_peermss;
			break;
		default:
			error = ENOPROTOOPT;
			break;
		}
		break;
	}
	_sce_pspnet_splunlock(s);
	return (error);
}


/*
 * Attach TCP protocol to socket, allocating
 * internet protocol control block, tcp control block,
 * bufer space, and entering LISTEN state if to accept connections.
 */
int
tcp_attach(struct socket *so)
{
	struct tcpcb *tp;
	struct inpcb *inp;
	int error;
	int family;	/* family of the socket */

	family = so->so_proto->pr_domain->dom_family;

	if (so->so_snd.sb_hiwat == 0 || so->so_rcv.sb_hiwat == 0) {
		error = soreserve(so, tcp_sendspace, tcp_recvspace);
		if (error)
			return (error);
	}
	switch (family) {
	case PF_INET:
		error = in_pcballoc(so, &tcbtable);
		if (error)
			return (error);
		inp = sotoinpcb(so);
		break;
	default:
		return EAFNOSUPPORT;
	}
	if (inp)
		tp = tcp_newtcpcb(family, (void *)inp);
	else
		tp = NULL;

	if (tp == 0) {
		int nofd = so->so_state & SS_NOFDREF;	/* XXX */

		so->so_state &= ~SS_NOFDREF;	/* don't free the socket yet */
		if (inp)
			in_pcbdetach(inp);
		so->so_state |= nofd;
		return (ENOBUFS);
	}
	tp->t_state = TCPS_CLOSED;
	return (0);
}

/*
 * Initiate (or continue) disconnect.
 * If embryonic state, just send reset (once).
 * If in ``let data drain'' option and linger null, just drop.
 * Otherwise (hard), mark socket disconnecting and drop
 * current input data; switch states based on user close, and
 * send segment to peer (with FIN).
 */
struct tcpcb *
tcp_disconnect(struct tcpcb *tp)
{
	struct socket *so;

	if (tp->t_inpcb)
		so = tp->t_inpcb->inp_socket;
	else
		so = NULL;

	if (TCPS_HAVEESTABLISHED(tp->t_state) == 0)
		tp = tcp_close(tp);
	else if ((so->so_options & SO_LINGER) && so->so_linger == 0)
		tp = tcp_drop(tp, 0);
	else {
		soisdisconnecting(so);
		sbflush(&so->so_rcv);
		tp = tcp_usrclosed(tp);
		if (tp)
			(void) tcp_output(tp);
	}
	return (tp);
}

/*
 * User issued close, and wish to trail through shutdown states:
 * if never received SYN, just forget it.  If got a SYN from peer,
 * but haven't sent FIN, then go to FIN_WAIT_1 state to send peer a FIN.
 * If already got a FIN from peer, then almost done; go to LAST_ACK
 * state.  In all other cases, have already sent FIN to peer (e.g.
 * after PRU_SHUTDOWN), and just have to play tedious game waiting
 * for peer to send FIN or not respond to keep-alives, etc.
 * We can let the user exit from the close as soon as the FIN is acked.
 */
struct tcpcb *
tcp_usrclosed(struct tcpcb *tp)
{

	switch (tp->t_state) {

	case TCPS_CLOSED:
	case TCPS_LISTEN:
	case TCPS_SYN_SENT:
		tp->t_state = TCPS_CLOSED;
		tp = tcp_close(tp);
		break;

	case TCPS_SYN_RECEIVED:
	case TCPS_ESTABLISHED:
		tp->t_state = TCPS_FIN_WAIT_1;
		break;

	case TCPS_CLOSE_WAIT:
		tp->t_state = TCPS_LAST_ACK;
		break;
	}
	if (tp && tp->t_state >= TCPS_FIN_WAIT_2) {
		struct socket *so;
		if (tp->t_inpcb)
			so = tp->t_inpcb->inp_socket;
		else
			so = NULL;
		soisdisconnected(so);
		/*
		 * If we are in FIN_WAIT_2, we arrived here because the
		 * application did a shutdown of the send side.  Like the
		 * case of a transition from FIN_WAIT_1 to FIN_WAIT_2 after
		 * a full close, we start a timer to make sure sockets are
		 * not left in FIN_WAIT_2 forever.
		 */
		if ((tp->t_state == TCPS_FIN_WAIT_2) && (tcp_maxidle > 0))
			TCP_TIMER_ARM(tp, TCPT_2MSL, tcp_maxidle);
	}
	return (tp);
}


/*
 * Sysctl for tcp variables.
 */
int
tcp_sysctl(int *name, u_int namelen, void *oldp, size_t *oldlenp, void *newp, size_t newlen)
{

	/* All sysctl names at this level are terminal. */
	if (namelen != 1)
		return (ENOTDIR);

	if (name[0] < sizeof(tcp_ctlvars)/sizeof(tcp_ctlvars[0])
	    && tcp_ctlvars[name[0]].valid) {
		if (tcp_ctlvars[name[0]].rdonly)
			return (sysctl_rdint(oldp, oldlenp, newp, 
			    tcp_ctlvars[name[0]].val));
		else
			return (sysctl_int(oldp, oldlenp, newp, newlen,
			    tcp_ctlvars[name[0]].var));
	}
	if (name[0] == TCPCTL_STATS)
		return (sysctl_rdstruct(oldp, oldlenp, newp, &tcpstat,
		    sizeof(tcpstat)));

	return (ENOPROTOOPT);
}

void
tcp_usrreq_init(void)
{
	tcp_recvspace = tcp_sendspace = 1024*16;
}
