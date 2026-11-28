/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

void
in_pcbinit(struct inpcbtable *table, int bindhashsize, int connecthashsize)
{
	CIRCLEQ_INIT(&table->inpt_queue);
	table->inpt_bindhashtbl = hashinit(bindhashsize, &table->inpt_bindhash);
	table->inpt_connecthashtbl = hashinit(connecthashsize, &table->inpt_connecthash);
	table->inpt_lastlow = 1023;
	table->inpt_lastport = anonportmin + sceNetRand() % (anonportmax - anonportmin + 1);
}

int
in_pcballoc(struct socket *so, void *v)
{
	struct inpcbtable *table = v;
	struct inpcb *inp;
	int s;

	inp = sceNetMallocInternal(sizeof(*inp));
	if (inp == NULL)
		return (ENOBUFS);
	memset((caddr_t)inp, 0, sizeof(*inp));
	inp->inp_table = table;
	inp->inp_socket = so;
	inp->inp_errormtu = -1;
	so->so_pcb = inp;
	s = _sce_pspnet_spllock();
	CIRCLEQ_INSERT_HEAD(&table->inpt_queue, inp, inp_queue);
	in_pcbstate(inp, INP_ATTACHED);
	_sce_pspnet_splunlock(s);
	return (0);
}

int
in_pcbbind(void *v, struct mbuf *nam)
{
	struct inpcb *inp = v;
	struct socket *so = inp->inp_socket;
	struct inpcbtable *table = inp->inp_table;
	struct sockaddr_in *sin;
	u_int16_t lport = 0;
	int wild = 0, reuseport = (so->so_options & SO_REUSEPORT);

	if (in_ifaddr.tqh_first == 0)
		return (EADDRNOTAVAIL);
	if (inp->inp_lport || !in_nullhost(inp->inp_laddr))
		return (EINVAL);
	if ((so->so_options & (SO_REUSEADDR|SO_REUSEPORT)) == 0)
		wild = 1;
	if (nam == 0)
		goto noname;
	sin = mtod(nam, struct sockaddr_in *);
	if (nam->m_len != sizeof (*sin))
		return (EINVAL);
	lport = sin->sin_port;
	if (IN_MULTICAST(sin->sin_addr.s_addr)) {
		if (so->so_options & SO_REUSEADDR)
			reuseport = SO_REUSEADDR|SO_REUSEPORT;
	} else if (!in_nullhost(sin->sin_addr)) {
		sin->sin_port = 0;
		if (ifa_ifwithaddr(sintosa(sin)) == 0)
			return (EADDRNOTAVAIL);
	}
	if (lport) {
		struct inpcb *t;

		t = in_pcblookup_port(table, sin->sin_addr, lport, wild);
		if (t && (reuseport & t->inp_socket->so_options) == 0)
			return (EADDRINUSE);
	}
	inp->inp_laddr = sin->sin_addr;

noname:
	if (lport == 0) {
		int	   cnt;
		u_int16_t  min, max;
		u_int16_t *lastport;

		if (inp->inp_flags & INP_LOWPORT) {
			min = lowportmin;
			max = lowportmax;
			lastport = &table->inpt_lastlow;
		} else {
			min = anonportmin;
			max = anonportmax;
			lastport = &table->inpt_lastport;
		}
		if (min > max) {
			u_int16_t swp;

			swp = min;
			min = max;
			max = swp;
		}

		lport = *lastport - 1;
		for (cnt = max - min + 1; cnt; cnt--, lport--) {
			if (lport < min || lport > max)
				lport = max;
			if (!in_pcblookup_port(table, inp->inp_laddr,
			    htons(lport), 1))
				goto found;
		}
		if (!in_nullhost(inp->inp_laddr))
			inp->inp_laddr.s_addr = INADDR_ANY;
		return (EAGAIN);
	found:
		inp->inp_flags |= INP_ANONPORT;
		*lastport = lport;
		lport = htons(lport);
	}
	inp->inp_lport = lport;
	in_pcbstate(inp, INP_BOUND);
	return (0);
}

int
in_pcbconnect(void *v, struct mbuf *nam)
{
	struct inpcb *inp = v;
	struct in_ifaddr *ia;
	struct sockaddr_in *ifaddr = NULL;
	struct sockaddr_in *sin = mtod(nam, struct sockaddr_in *);
	int error;

	if (nam->m_len != sizeof (*sin))
		return (EINVAL);
	if (sin->sin_family != AF_INET)
		return (EAFNOSUPPORT);
	if (sin->sin_port == 0)
		return (EADDRNOTAVAIL);
	if (in_ifaddr.tqh_first != 0) {
		if (in_nullhost(sin->sin_addr))
			sin->sin_addr = in_ifaddr.tqh_first->ia_addr.sin_addr;
		else if (sin->sin_addr.s_addr == INADDR_BROADCAST)
			for (ia = in_ifaddr.tqh_first; ia != NULL;
			    ia = ia->ia_list.tqe_next)
				if (ia->ia_ifp->if_flags & IFF_BROADCAST) {
					sin->sin_addr =
					    ia->ia_broadaddr.sin_addr;
					break;
				}
	}
	if (in_nullhost(inp->inp_laddr)) {
		int error;
		ifaddr = in_selectsrc(sin, &inp->inp_route,
			inp->inp_socket->so_options, inp->inp_moptions, &error);
		if (ifaddr == NULL) {
			if (error == 0)
				error = EADDRNOTAVAIL;
			return error;
		}
	}
	if (in_pcblookup_connect(inp->inp_table, sin->sin_addr, sin->sin_port,
	    !in_nullhost(inp->inp_laddr) ? inp->inp_laddr : ifaddr->sin_addr,
	    inp->inp_lport) != 0)
		return (EADDRINUSE);
	if (in_nullhost(inp->inp_laddr)) {
		if (inp->inp_lport == 0) {
			error = in_pcbbind(inp, (struct mbuf *)0);
			if (error == EAGAIN)
				return (error);
		}
		inp->inp_laddr = ifaddr->sin_addr;
	}
	inp->inp_faddr = sin->sin_addr;
	inp->inp_fport = sin->sin_port;
	in_pcbstate(inp, INP_CONNECTED);
	return (0);
}

void
in_pcbdisconnect(void *v)
{
	struct inpcb *inp = v;

	inp->inp_faddr = zeroin_addr;
	inp->inp_fport = 0;
	in_pcbstate(inp, INP_BOUND);
	if (inp->inp_socket->so_state & SS_NOFDREF)
		in_pcbdetach(inp);
}

void
in_pcbdetach(void *v)
{
	struct inpcb *inp = v;
	struct socket *so = inp->inp_socket;
	int s;

	so->so_pcb = 0;
	sofree(so);
	if (inp->inp_options)
		(void)m_free(inp->inp_options);
	if (inp->inp_route.ro_rt)
		rtfree(inp->inp_route.ro_rt);
	ip_freemoptions(inp->inp_moptions);
	s = _sce_pspnet_spllock();
	in_pcbstate(inp, INP_ATTACHED);
	CIRCLEQ_REMOVE(&inp->inp_table->inpt_queue, inp, inp_queue);
	_sce_pspnet_splunlock(s);
	sceNetFreeInternal(inp);
}

void
in_setsockaddr(struct inpcb *inp, struct mbuf *nam)
{
	struct sockaddr_in *sin;

	nam->m_len = sizeof (*sin);
	sin = mtod(nam, struct sockaddr_in *);
	memset((caddr_t)sin, 0, sizeof (*sin));
	sin->sin_family = AF_INET;
	sin->sin_len = sizeof(*sin);
	sin->sin_port = inp->inp_lport;
	sin->sin_addr = inp->inp_laddr;
}

void
in_setpeeraddr(struct inpcb *inp, struct mbuf *nam)
{
	struct sockaddr_in *sin;

	nam->m_len = sizeof (*sin);
	sin = mtod(nam, struct sockaddr_in *);
	memset((caddr_t)sin, 0, sizeof (*sin));
	sin->sin_family = AF_INET;
	sin->sin_len = sizeof(*sin);
	sin->sin_port = inp->inp_fport;
	sin->sin_addr = inp->inp_faddr;
}

int
in_pcbnotify(struct inpcbtable *table, struct in_addr faddr, u_int fport_arg, struct in_addr laddr, u_int lport_arg, int errno, void (*notify)(struct inpcb *, int))
{
	struct inpcbhead *head;
	struct inpcb *inp, *ninp;
	u_int16_t fport = fport_arg, lport = lport_arg;
	int nmatch;

	if (in_nullhost(faddr) || notify == 0)
		return (0);

	nmatch = 0;
	head = INPCBHASH_CONNECT(table, faddr, fport, laddr, lport);
	for (inp = head->lh_first; inp != NULL; inp = ninp) {
		ninp = inp->inp_hash.le_next;
		if (in_hosteq(inp->inp_faddr, faddr) &&
		    inp->inp_fport == fport &&
		    inp->inp_lport == lport &&
		    in_hosteq(inp->inp_laddr, laddr)) {
			(*notify)(inp, errno);
			nmatch++;
		}
	}
	return (nmatch);
}

void
in_pcbnotifyall(struct inpcbtable *table, struct in_addr faddr, int errno, void (*notify)(struct inpcb *, int))
{
	struct inpcb *inp, *ninp;

	if (in_nullhost(faddr) || notify == 0)
		return;

	for (inp = table->inpt_queue.cqh_first;
	    inp != (struct inpcb *)&table->inpt_queue;
	    inp = ninp) {
		ninp = inp->inp_queue.cqe_next;
		if (in_hosteq(inp->inp_faddr, faddr))
			(*notify)(inp, errno);
	}
}

void
in_pcbpurgeif(struct inpcbtable *table, struct ifnet *ifp)
{
	struct inpcb *inp, *ninp;
	struct ip_moptions *imo;
	int i, gap;

	for (inp = CIRCLEQ_FIRST(&table->inpt_queue);
	    inp != (void *)&table->inpt_queue;
	    inp = ninp) {
		ninp = CIRCLEQ_NEXT(inp, inp_queue);
		if (inp->inp_route.ro_rt != NULL &&
		    inp->inp_route.ro_rt->rt_ifp == ifp)
			in_rtchange(inp, 0);
		imo = inp->inp_moptions;
		if (imo != NULL) {
			if (imo->imo_multicast_ifp == ifp)
				imo->imo_multicast_ifp = NULL;
			for (i = 0, gap = 0; i < imo->imo_num_memberships;
			    i++) {
				if (imo->imo_membership[i]->inm_ifp == ifp) {
					in_delmulti(imo->imo_membership[i]);
					gap++;
				} else if (gap != 0)
					imo->imo_membership[i - gap] =
					    imo->imo_membership[i];
			}
			imo->imo_num_memberships -= gap;
		}
	}
}

void
in_losing(struct inpcb *inp)
{
	struct rtentry *rt;
	struct rt_addrinfo info;

	if ((rt = inp->inp_route.ro_rt)) {
		inp->inp_route.ro_rt = 0;
		memset((caddr_t)&info, 0, sizeof(info));
		info.rti_info[RTAX_DST] = &inp->inp_route.ro_dst;
		info.rti_info[RTAX_GATEWAY] = rt->rt_gateway;
		info.rti_info[RTAX_NETMASK] = rt_mask(rt);
		rt_missmsg(RTM_LOSING, &info, rt->rt_flags, 0);
		if (rt->rt_flags & RTF_DYNAMIC)
			(void) rtrequest(RTM_DELETE, rt_key(rt),
				rt->rt_gateway, rt_mask(rt), rt->rt_flags,
				(struct rtentry **)0);
		else
			rtfree(rt);
	}
}

void
in_rtchange(struct inpcb *inp, int errno)
{
	if (inp->inp_route.ro_rt) {
		rtfree(inp->inp_route.ro_rt);
		inp->inp_route.ro_rt = 0;
	}
}

struct inpcb *
in_pcblookup_port(struct inpcbtable *table, struct in_addr laddr, u_int lport_arg, int lookup_wildcard)
{
	struct inpcb *inp, *match = 0;
	int matchwild = 3, wildcard;
	u_int16_t lport = lport_arg;

	for (inp = table->inpt_queue.cqh_first;
	    inp != (struct inpcb *)&table->inpt_queue;
	    inp = inp->inp_queue.cqe_next) {
		if (inp->inp_lport != lport)
			continue;
		wildcard = 0;
		if (!in_nullhost(inp->inp_faddr))
			wildcard++;
		if (in_nullhost(inp->inp_laddr)) {
			if (!in_nullhost(laddr))
				wildcard++;
		} else {
			if (in_nullhost(laddr))
				wildcard++;
			else {
				if (!in_hosteq(inp->inp_laddr, laddr))
					continue;
			}
		}
		if (wildcard && !lookup_wildcard)
			continue;
		if (wildcard < matchwild) {
			match = inp;
			matchwild = wildcard;
			if (matchwild == 0)
				break;
		}
	}
	return (match);
}

struct inpcb *
in_pcblookup_connect(struct inpcbtable *table, struct in_addr faddr, u_int fport_arg, struct in_addr laddr, u_int lport_arg)
{
	struct inpcbhead *head;
	struct inpcb *inp;
	u_int16_t fport = fport_arg, lport = lport_arg;

	head = INPCBHASH_CONNECT(table, faddr, fport, laddr, lport);
	for (inp = head->lh_first; inp != NULL; inp = inp->inp_hash.le_next) {
		if (in_hosteq(inp->inp_faddr, faddr) &&
		    inp->inp_fport == fport &&
		    inp->inp_lport == lport &&
		    in_hosteq(inp->inp_laddr, laddr))
			goto out;
	}
	return (0);

out:
	if (inp != head->lh_first) {
		LIST_REMOVE(inp, inp_hash);
		LIST_INSERT_HEAD(head, inp, inp_hash);
	}
	return (inp);
}

struct inpcb *
in_pcblookup_bind(struct inpcbtable *table, struct in_addr laddr, u_int lport_arg)
{
	struct inpcbhead *head;
	struct inpcb *inp;
	u_int16_t lport = lport_arg;

	head = INPCBHASH_BIND(table, laddr, lport);
	for (inp = head->lh_first; inp != NULL; inp = inp->inp_hash.le_next) {
		if (inp->inp_lport == lport &&
		    in_hosteq(inp->inp_laddr, laddr))
			goto out;
	}
	head = INPCBHASH_BIND(table, zeroin_addr, lport);
	for (inp = head->lh_first; inp != NULL; inp = inp->inp_hash.le_next) {
		if (inp->inp_lport == lport &&
		    in_hosteq(inp->inp_laddr, zeroin_addr))
			goto out;
	}
	return (0);

out:
	if (inp != head->lh_first) {
		LIST_REMOVE(inp, inp_hash);
		LIST_INSERT_HEAD(head, inp, inp_hash);
	}
	return (inp);
}

void
in_pcbstate(struct inpcb *inp, int state)
{
	if (inp->inp_state > INP_ATTACHED)
		LIST_REMOVE(inp, inp_hash);

	switch (state) {
	case INP_BOUND:
		LIST_INSERT_HEAD(INPCBHASH_BIND(inp->inp_table,
		    inp->inp_laddr, inp->inp_lport), inp, inp_hash);
		break;
	case INP_CONNECTED:
		LIST_INSERT_HEAD(INPCBHASH_CONNECT(inp->inp_table,
		    inp->inp_faddr, inp->inp_fport,
		    inp->inp_laddr, inp->inp_lport), inp, inp_hash);
		break;
	}

	inp->inp_state = state;
}

struct rtentry *
in_pcbrtentry(struct inpcb *inp)
{
	struct route *ro;

	ro = &inp->inp_route;
	if (ro->ro_rt == NULL && !in_nullhost(inp->inp_faddr)) {
		ro->ro_dst.sa_family = AF_INET;
		ro->ro_dst.sa_len = sizeof(ro->ro_dst);
		satosin(&ro->ro_dst)->sin_addr = inp->inp_faddr;
		rtalloc(ro);
	}
	return (ro->ro_rt);
}

struct sockaddr_in *
in_selectsrc(struct sockaddr_in *sin, struct route *ro, int soopts, struct ip_moptions *mopts, int *errorp)
{
	struct in_ifaddr *ia;

	ia = (struct in_ifaddr *)0;
	if (ro->ro_rt &&
	    (!in_hosteq(satosin(&ro->ro_dst)->sin_addr, sin->sin_addr) ||
	    soopts & SO_DONTROUTE)) {
		RTFREE(ro->ro_rt);
		ro->ro_rt = (struct rtentry *)0;
	}
	if ((soopts & SO_DONTROUTE) == 0 &&
	    (ro->ro_rt == (struct rtentry *)0 ||
	     ro->ro_rt->rt_ifp == (struct ifnet *)0)) {
		ro->ro_dst.sa_family = AF_INET;
		ro->ro_dst.sa_len = sizeof(struct sockaddr_in);
		satosin(&ro->ro_dst)->sin_addr = sin->sin_addr;
		rtalloc(ro);
	}
	if (ro->ro_rt && !(ro->ro_rt->rt_ifp->if_flags & IFF_LOOPBACK))
		ia = ifatoia(ro->ro_rt->rt_ifa);
	if (ia == NULL) {
		u_int16_t fport = sin->sin_port;

		sin->sin_port = 0;
		ia = ifatoia(ifa_ifwithladdr(sintosa(sin)));
		sin->sin_port = fport;
		if (ia == 0) {
			for (ia = in_ifaddr.tqh_first;
			     ia != NULL;
			     ia = ia->ia_list.tqe_next) {
				if (!(ia->ia_ifp->if_flags & IFF_LOOPBACK))
					break;
			}
		}
		if (ia == NULL) {
			*errorp = EADDRNOTAVAIL;
			return NULL;
		}
	}
	if (IN_MULTICAST(sin->sin_addr.s_addr) && mopts != NULL) {
		struct ip_moptions *imo;
		struct ifnet *ifp;

		imo = mopts;
		if (imo->imo_multicast_ifp != NULL) {
			ifp = imo->imo_multicast_ifp;
			IFP_TO_IA(ifp, ia);
			if (ia == 0) {
				*errorp = EADDRNOTAVAIL;
				return NULL;
			}
		}
	}
	return satosin(&ia->ia_addr);
}
