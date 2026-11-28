/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

#define SIN(s) ((struct sockaddr_in *)s)
#define SDL(s) ((struct sockaddr_dl *)s)
#define SRP(s) ((struct sockaddr_inarp *)s)
#define Bcopy(a, b, n) bcopy(((caddr_t)(a)), ((caddr_t)(b)), (unsigned)(n))
#define Bzero(p, n) memset((caddr_t)(p), 0, (unsigned)(n))
#define R_Malloc(p, t, n) (p = (t) sceNetMallocInternal((unsigned int)(n)))
#define Free(p) sceNetFreeInternal((caddr_t)p)

#define null_sdl D_0002E5C8
extern int arpt_prune, arpt_keep, arpt_down, arp_maxtries, useloopback;
extern LIST_HEAD(, llinfo_arp) llinfo_arp;
extern int arp_inuse, arp_allocated, arp_locked, D_0002F510;
extern struct callout arptimer_ch;
extern int arpinit_done, myip_initialized, revarp_in_progress;
extern struct ifnet *myip_ifp;
extern struct in_addr myip, srv_ip;
extern struct sockaddr_dl null_sdl;
#define sin D_0002EB98
extern struct sockaddr_inarp sin;

#define arprequest func_0000FA28
#define in_arpinput func_0000FEA4
#define arplookup func_0001041C
#define arptimer func_00010A30
#define arp_init func_00010B98

static void arprequest(struct ifnet *, struct in_addr *, struct in_addr *, u_int8_t *);
static void arptfree(struct llinfo_arp *);
static void arptimer(void *);
static struct llinfo_arp *arplookup(struct in_addr *, int, int);
static void in_arpinput(struct mbuf *);

static __inline int
arp_lock_try(int recurse)
{
	int s;

	s = _sce_pspnet_spllock();
	if (!recurse && arp_locked) {
		_sce_pspnet_splunlock(s);
		return (0);
	}
	arp_locked++;
	_sce_pspnet_splunlock(s);
	return (1);
}

static __inline void
arp_unlock(void)
{
	int s;

	s = _sce_pspnet_spllock();
	arp_locked--;
	_sce_pspnet_splunlock(s);
}

#define ARP_LOCK(x) (void)arp_lock_try(x)
#define ARP_UNLOCK() arp_unlock()

void
arp_rtrequest(int req, struct rtentry *rt, struct sockaddr *sa)
{
	struct sockaddr *gate = rt->rt_gateway;
	struct llinfo_arp *la = (struct llinfo_arp *)rt->rt_llinfo;
	size_t allocsize;
	struct mbuf *mold;
	int s;

	if (!arpinit_done) {
		arpinit_done = 1;
		callout_init(&arptimer_ch);
		callout_reset(&arptimer_ch, hz, arptimer, NULL);
	}
	if (rt->rt_flags & RTF_GATEWAY)
		return;

	ARP_LOCK(1);

	switch (req) {

	case RTM_ADD:
		if ((rt->rt_flags & RTF_HOST) == 0 &&
		    SIN(rt_mask(rt))->sin_addr.s_addr != 0xffffffff)
			rt->rt_flags |= RTF_CLONING;
		if (rt->rt_flags & RTF_CLONING) {
			rt_setgate(rt, rt_key(rt),
			    (struct sockaddr *)&null_sdl);
			gate = rt->rt_gateway;
			SDL(gate)->sdl_type = rt->rt_ifp->if_type;
			SDL(gate)->sdl_index = rt->rt_ifp->if_index;
			rt->rt_expire = sceNetGetSystemClockSec();
			break;
		}
		if (rt->rt_flags & RTF_ANNOUNCE)
			arprequest(rt->rt_ifp,
			    &SIN(rt_key(rt))->sin_addr,
			    &SIN(rt_key(rt))->sin_addr,
			    (u_char *)LLADDR(SDL(gate)));
		/*FALLTHROUGH*/
	case RTM_RESOLVE:
		if (gate->sa_family != AF_LINK ||
		    gate->sa_len < sizeof(null_sdl))
			break;
		SDL(gate)->sdl_type = rt->rt_ifp->if_type;
		SDL(gate)->sdl_index = rt->rt_ifp->if_index;
		if (la != 0)
			break;
		allocsize = sizeof(*la);
		R_Malloc(la, struct llinfo_arp *, allocsize);
		rt->rt_llinfo = (caddr_t)la;
		if (la == 0)
			break;
		arp_inuse++, arp_allocated++;
		Bzero(la, allocsize);
		la->la_rt = rt;
		rt->rt_flags |= RTF_LLINFO;
		LIST_INSERT_HEAD(&llinfo_arp, la, la_list);
		if (in_hosteq(SIN(rt_key(rt))->sin_addr,
		    (IA_SIN(rt->rt_ifa))->sin_addr)) {
			rt->rt_expire = 0;
			Bcopy(LLADDR(rt->rt_ifp->if_sadl),
			    LLADDR(SDL(gate)),
			    SDL(gate)->sdl_alen =
			    rt->rt_ifp->if_data.ifi_addrlen);
			if (useloopback)
				rt->rt_ifp = &loif;
		}
		break;

	case RTM_DELETE:
		if (la == 0)
			break;
		arp_inuse--;
		LIST_REMOVE(la, la_list);
		rt->rt_llinfo = 0;
		rt->rt_flags &= ~RTF_LLINFO;

		s = _sce_pspnet_spllock();
		mold = la->la_hold;
		la->la_hold = 0;
		_sce_pspnet_splunlock(s);

		if (mold)
			m_freem(mold);

		Free((caddr_t)la);
	}
	ARP_UNLOCK();
}

static void
arprequest(struct ifnet *ifp, struct in_addr *sip, struct in_addr *tip, u_int8_t *enaddr)
{
	struct mbuf *m;
	struct arphdr *ah;
	struct sockaddr sa;

	if ((m = m_gethdr(M_DONTWAIT, MT_DATA)) == NULL)
		return;
	m->m_len = sizeof(*ah) + 2*sizeof(struct in_addr) +
	    2*ifp->if_data.ifi_addrlen;
	m->m_pkthdr.len = m->m_len;
	MH_ALIGN(m, m->m_len);
	ah = mtod(m, struct arphdr *);
	memset((caddr_t)ah, 0, m->m_len);
	ah->ar_pro = htons(ETHERTYPE_IP);
	ah->ar_hln = ifp->if_data.ifi_addrlen;
	ah->ar_pln = sizeof(struct in_addr);
	ah->ar_op = htons(ARPOP_REQUEST);
	bcopy((caddr_t)enaddr, (caddr_t)ar_sha(ah), ah->ar_hln);
	bcopy((caddr_t)sip, (caddr_t)ar_spa(ah), ah->ar_pln);
	bcopy((caddr_t)tip, (caddr_t)ar_tpa(ah), ah->ar_pln);
	sa.sa_family = AF_ARP;
	sa.sa_len = 2;
	m->m_flags |= M_BCAST;
	(*ifp->if_output)(ifp, m, &sa, (struct rtentry *)0);
}

int
arpresolve(struct ifnet *ifp, struct rtentry *rt, struct mbuf *m, struct sockaddr *dst, u_char *desten)
{
	struct llinfo_arp *la;
	struct sockaddr_dl *sdl;
	struct mbuf *mold;
	int s;

	if (rt)
		la = (struct llinfo_arp *)rt->rt_llinfo;
	else {
		if ((la = arplookup(&SIN(dst)->sin_addr, 1, 0)) != NULL)
			rt = la->la_rt;
	}
	if (la == 0 || rt == 0) {
		m_freem(m);
		return (0);
	}
	sdl = SDL(rt->rt_gateway);
	if ((rt->rt_expire == 0 || rt->rt_expire > sceNetGetSystemClockSec()) &&
	    sdl->sdl_family == AF_LINK && sdl->sdl_alen != 0) {
		bcopy(LLADDR(sdl), desten,
		    min(sdl->sdl_alen, ifp->if_data.ifi_addrlen));
		return 1;
	}

	s = _sce_pspnet_spllock();
	mold = la->la_hold;
	la->la_hold = m;
	_sce_pspnet_splunlock(s);

	if (mold)
		m_freem(mold);

	if (rt->rt_expire) {
		rt->rt_flags &= ~RTF_REJECT;
		if (la->la_asked == 0 || rt->rt_expire != sceNetGetSystemClockSec()) {
			rt->rt_expire = sceNetGetSystemClockSec();
			if (la->la_asked++ < arp_maxtries)
				arprequest(ifp,
				    &SIN(rt->rt_ifa->ifa_addr)->sin_addr,
				    &SIN(dst)->sin_addr,
				    LLADDR(ifp->if_sadl));
			else {
				rt->rt_flags |= RTF_REJECT;
				rt->rt_expire += arpt_down;
				la->la_asked = 0;
			}
		}
	}
	return (0);
}

void
arpintr(void)
{
	struct mbuf *m;
	struct arphdr *ar;
	int s;

	while (arpintrq.ifq_head) {
		s = _sce_pspnet_spllock();
		IF_DEQUEUE(&arpintrq, m);
		_sce_pspnet_splunlock(s);

		if (m->m_len >= sizeof(struct arphdr) &&
		    (ar = mtod(m, struct arphdr *)) &&
		    m->m_len >=
		      sizeof(struct arphdr) + 2 * (ar->ar_hln + ar->ar_pln))
			switch (ntohs(ar->ar_pro)) {

			case ETHERTYPE_IP:
			case ETHERTYPE_IPTRAILERS:
				in_arpinput(m);
				continue;
			}
		m_freem(m);
	}
}

static void
in_arpinput(struct mbuf *m)
{
	struct arphdr *ah;
	struct ifnet *ifp = m->m_pkthdr.rcvif;
	struct llinfo_arp *la = 0;
	struct rtentry *rt;
	struct in_ifaddr *ia;
	struct sockaddr_dl *sdl;
	struct sockaddr sa;
	struct in_addr isaddr, itaddr, myaddr;
	int op;
	struct mbuf *mold;
	int s;

	ah = mtod(m, struct arphdr *);
	op = ntohs(ah->ar_op);
	bcopy((caddr_t)ar_spa(ah), (caddr_t)&isaddr, sizeof(isaddr));
	bcopy((caddr_t)ar_tpa(ah), (caddr_t)&itaddr, sizeof(itaddr));

	if (in_nullhost(itaddr))
		goto out;

	if (in_nullhost(isaddr))
		goto out;

	INADDR_TO_IA(itaddr, ia);
	while ((ia != NULL) && ia->ia_ifp != m->m_pkthdr.rcvif)
		NEXT_IA_WITH_SAME_ADDR(ia);

	if (ia == NULL) {
		INADDR_TO_IA(isaddr, ia);
		while ((ia != NULL) && ia->ia_ifp != m->m_pkthdr.rcvif)
			NEXT_IA_WITH_SAME_ADDR(ia);

		if (ia == NULL) {
			IFP_TO_IA(ifp, ia);
			if (ia == NULL)
				goto out;
		}
	}

	myaddr = ia->ia_addr.sin_addr;

	if (!bcmp((caddr_t)ar_sha(ah), LLADDR(ifp->if_sadl),
	    ifp->if_data.ifi_addrlen))
		goto out;

	if (!bcmp((caddr_t)ar_sha(ah), (caddr_t)ifp->if_broadcastaddr,
	    ifp->if_data.ifi_addrlen))
		goto out;

	if (in_hosteq(isaddr, myaddr)) {
		itaddr = myaddr;
		goto reply;
	}
	la = arplookup(&isaddr, in_hosteq(itaddr, myaddr), 0);
	if (la && (rt = la->la_rt) && (sdl = SDL(rt->rt_gateway))) {
		if (sdl->sdl_alen &&
		    bcmp((caddr_t)ar_sha(ah), LLADDR(sdl), sdl->sdl_alen)) {
			if (rt->rt_flags & RTF_STATIC)
				goto out;
			else if (rt->rt_ifp != ifp)
				goto out;
		}
		if (ifp->if_data.ifi_addrlen != ah->ar_hln)
			goto reply;
		bcopy((caddr_t)ar_sha(ah), LLADDR(sdl),
		    sdl->sdl_alen = ah->ar_hln);
		if (rt->rt_expire)
			rt->rt_expire = sceNetGetSystemClockSec() + arpt_keep;
		rt->rt_flags &= ~RTF_REJECT;
		la->la_asked = 0;

		s = _sce_pspnet_spllock();
		mold = la->la_hold;
		la->la_hold = 0;
		_sce_pspnet_splunlock(s);

		if (mold)
			(*ifp->if_output)(ifp, mold, rt_key(rt), rt);
	}
reply:
	if (op != ARPOP_REQUEST) {
	out:
		m_freem(m);
		return;
	}
	if (in_hosteq(itaddr, myaddr)) {
		bcopy((caddr_t)ar_sha(ah), (caddr_t)ar_tha(ah), ah->ar_hln);
		bcopy(LLADDR(ifp->if_sadl), (caddr_t)ar_sha(ah), ah->ar_hln);
	} else {
		la = arplookup(&itaddr, 0, SIN_PROXY);
		if (la == 0)
			goto out;
		rt = la->la_rt;
		bcopy((caddr_t)ar_sha(ah), (caddr_t)ar_tha(ah), ah->ar_hln);
		sdl = SDL(rt->rt_gateway);
		bcopy(LLADDR(sdl), (caddr_t)ar_sha(ah), ah->ar_hln);
	}

	bcopy((caddr_t)ar_spa(ah), (caddr_t)ar_tpa(ah), ah->ar_pln);
	bcopy((caddr_t)&itaddr, (caddr_t)ar_spa(ah), ah->ar_pln);
	ah->ar_op = htons(ARPOP_REPLY);
	ah->ar_pro = htons(ETHERTYPE_IP);
	m->m_flags &= ~(M_BCAST|M_MCAST);
	m->m_len = sizeof(*ah) + (2 * ah->ar_pln) + (2 * ah->ar_hln);
	m->m_pkthdr.len = m->m_len;
	sa.sa_family = AF_ARP;
	sa.sa_len = 2;
	(*ifp->if_output)(ifp, m, &sa, (struct rtentry *)0);
	return;
}

static void
arptfree(struct llinfo_arp *la)
{
	struct rtentry *rt = la->la_rt;
	struct sockaddr_dl *sdl;

	if (rt->rt_refcnt > 0 && (sdl = SDL(rt->rt_gateway)) &&
	    sdl->sdl_family == AF_LINK) {
		sdl->sdl_alen = 0;
		la->la_asked = 0;
		rt->rt_flags &= ~RTF_REJECT;
		return;
	}
	rtrequest(RTM_DELETE, rt_key(rt), (struct sockaddr *)0, rt_mask(rt),
	    0, (struct rtentry **)0);
}

static struct llinfo_arp *
arplookup(struct in_addr *addr, int create, int proxy)
{
	struct rtentry *rt;

	sin.sin_len = sizeof(sin);
	sin.sin_family = AF_INET;
	sin.sin_addr = *addr;
	sin.sin_other = proxy ? SIN_PROXY : 0;
	rt = rtalloc1(sintosa(&sin), create);
	if (rt == 0)
		return (0);
	rt->rt_refcnt--;

	if (rt->rt_flags & RTF_GATEWAY)
		;
	else if ((rt->rt_flags & RTF_LLINFO) == 0)
		;
	else if (rt->rt_gateway->sa_family != AF_LINK)
		;
	else
		return ((struct llinfo_arp *)rt->rt_llinfo);

	if (create) {
		if (rt->rt_refcnt <= 0 && (rt->rt_flags & RTF_CLONED) != 0) {
			rtrequest(RTM_DELETE, (struct sockaddr *)rt_key(rt),
			    rt->rt_gateway, rt_mask(rt), rt->rt_flags, 0);
		}
	}
	return (0);
}

void
in_revarpinput(struct mbuf *m)
{
	struct ifnet *ifp;
	struct arphdr *ah;
	int op;

	ah = mtod(m, struct arphdr *);
	op = ntohs(ah->ar_op);
	switch (op) {
	case ARPOP_REQUEST:
	case ARPOP_REPLY:
		in_arpinput(m);
		return;
	case ARPOP_REVREPLY:
		break;
	case ARPOP_REVREQUEST:
	default:
		goto out;
	}
	if (!revarp_in_progress)
		goto out;
	ifp = m->m_pkthdr.rcvif;
	if (ifp != myip_ifp)
		goto out;
	if (myip_initialized)
		goto wake;
	if (bcmp(ar_tha(ah), LLADDR(ifp->if_sadl), ifp->if_sadl->sdl_alen))
		goto out;
	bcopy((caddr_t)ar_spa(ah), (caddr_t)&srv_ip, sizeof(srv_ip));
	bcopy((caddr_t)ar_tpa(ah), (caddr_t)&myip, sizeof(myip));
	myip_initialized = 1;
wake:
	wakeup((caddr_t)&myip);

out:
	m_freem(m);
}

__attribute__((noinline)) void
arp_drain(void)
{
	struct llinfo_arp *la, *nla;
	int count = 0;
	struct mbuf *mold;

	if (arp_lock_try(0) == 0)
		return;

	for (la = llinfo_arp.lh_first; la != 0; la = nla) {
		nla = la->la_list.le_next;

		mold = la->la_hold;
		la->la_hold = 0;

		if (mold) {
			m_freem(mold);
			count++;
		}
	}
	ARP_UNLOCK();
}

__attribute__((noinline)) int
arpioctl(u_long cmd, caddr_t data)
{
	return (EOPNOTSUPP);
}

__attribute__((noinline)) void
arp_ifinit(struct ifnet *ifp, struct ifaddr *ifa)
{
	struct in_addr *ip;

	ip = &IA_SIN(ifa)->sin_addr;
	if (!in_nullhost(*ip))
		arprequest(ifp, ip, ip, LLADDR(ifp->if_sadl));

	ifa->ifa_rtrequest = arp_rtrequest;
	ifa->ifa_flags |= RTF_CLONING;
}

__attribute__((noinline)) void
revarpinput(struct mbuf *m)
{
	struct arphdr *ar;

	if (m->m_len < sizeof(struct arphdr))
		goto out;
	ar = mtod(m, struct arphdr *);
	if (m->m_len < sizeof(struct arphdr) + 2 * (ar->ar_hln + ar->ar_pln))
		goto out;
	switch (ntohs(ar->ar_pro)) {

	case ETHERTYPE_IP:
	case ETHERTYPE_IPTRAILERS:
		in_revarpinput(m);
		return;

	default:
		break;
	}
out:
	m_freem(m);
}

__attribute__((noinline)) void
revarprequest(struct ifnet *ifp)
{
	struct sockaddr sa;
	struct mbuf *m;
	struct arphdr *ah;

	if ((m = m_gethdr(M_DONTWAIT, MT_DATA)) == NULL)
		return;
	m->m_len = sizeof(*ah) + 2*sizeof(struct in_addr) +
	    2*ifp->if_data.ifi_addrlen;
	m->m_pkthdr.len = m->m_len;
	MH_ALIGN(m, m->m_len);
	ah = mtod(m, struct arphdr *);
	memset((caddr_t)ah, 0, m->m_len);
	ah->ar_pro = htons(ETHERTYPE_IP);
	ah->ar_hln = ifp->if_data.ifi_addrlen;
	ah->ar_pln = sizeof(struct in_addr);
	ah->ar_op = htons(ARPOP_REVREQUEST);

	bcopy(LLADDR(ifp->if_sadl), (caddr_t)ar_sha(ah), ah->ar_hln);
	bcopy(LLADDR(ifp->if_sadl), (caddr_t)ar_tha(ah), ah->ar_hln);

	sa.sa_family = AF_ARP;
	sa.sa_len = 2;
	m->m_flags |= M_BCAST;
	(*ifp->if_output)(ifp, m, &sa, (struct rtentry *)0);
}

__attribute__((noinline)) int
revarpwhoarewe(struct ifnet *ifp, struct in_addr *serv_in, struct in_addr *clnt_in)
{
	int result, count = 20;

	myip_initialized = 0;
	myip_ifp = ifp;

	revarp_in_progress = 1;
	while (count--) {
		revarprequest(ifp);
		result = tsleep((caddr_t)&myip, hz/2);
		if (result != EWOULDBLOCK)
			break;
	}
	revarp_in_progress = 0;

	if (!myip_initialized)
		return ENETUNREACH;

	bcopy((caddr_t)&srv_ip, serv_in, sizeof(*serv_in));
	bcopy((caddr_t)&myip, clnt_in, sizeof(*clnt_in));
	return 0;
}

static void
arptimer(void *arg)
{
	int s;
	struct llinfo_arp *la, *nla;

	s = _sce_pspnet_spllock();

	if (arp_lock_try(0) == 0) {
		_sce_pspnet_splunlock(s);
		return;
	}

	callout_reset(&arptimer_ch, arpt_prune * hz, arptimer, NULL);
	for (la = llinfo_arp.lh_first; la != 0; la = nla) {
		struct rtentry *rt = la->la_rt;

		nla = la->la_list.le_next;
		if (rt->rt_expire && rt->rt_expire <= sceNetGetSystemClockSec())
			arptfree(la);
	}

	ARP_UNLOCK();

	_sce_pspnet_splunlock(s);
}

static void
arp_init(void)
{
	arpintrq.ifq_maxlen = 50;
	D_0002F510 = 0;
	arp_inuse = 0;
	arp_allocated = 0;
	arp_locked = 0;
	arpinit_done = 0;
	arpintrq.ifq_head = 0;
	llinfo_arp.lh_first = 0;
	myip_initialized = 0;
	revarp_in_progress = 0;
	myip_ifp = 0;
	arpintrq.ifq_len = 0;
	arpintrq.ifq_drops = 0;
	arpintrq.ifq_tail = 0;
}

/*
 * arpsw/arpdomain live in the asm .data (D_0002E568/D_0002E59C); this copy only
 * keeps the static functions referenced and goes to a discarded section.
 */
#define DISCARD __attribute__((section(".discard")))
__asm__(".globl func_00010B98");

const char D_0002DB04[] = "arp";

DISCARD struct protosw arpsw[] = {
	{ 0, 0, 0, 0,
	  0, 0, 0, 0,
	  0,
	  0, 0, 0, arp_drain,
	}
};

DISCARD struct domain arpdomain =
{	PF_ARP, (char *)D_0002DB04, arp_init, 0, 0,
	arpsw, &arpsw[sizeof(arpsw)/sizeof(arpsw[0])]
};
