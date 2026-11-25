/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

#define equal(a1, a2) \
  (bcmp((caddr_t)(a1), (caddr_t)(a2), ((struct sockaddr *)(a1))->sa_len) == 0)

struct ifaddr *
ifa_ifwithnet(struct sockaddr *addr)
{
	struct ifnet *ifp;
	struct ifaddr *ifa;
	struct sockaddr_dl *sdl;
	struct ifaddr *ifa_maybe = 0;
	u_int af = addr->sa_family;
	char *addr_data = addr->sa_data, *cplim;
	struct ifnet_head ifnet;
	int if_index;
	struct ifnet **ifindex2ifnet;
	struct ifaddr **ifnet_addrs;

	_sce_pspnet_get_if_core_variables(&if_index, (int *)&ifindex2ifnet, (int *)&ifnet_addrs, &ifnet);
	if (af == AF_LINK) {
		sdl = (struct sockaddr_dl *)addr;
		if (sdl->sdl_index && sdl->sdl_index <= if_index &&
		    ifindex2ifnet[sdl->sdl_index]->if_output != if_nulloutput)
			return (ifnet_addrs[sdl->sdl_index]);
	}
	for (ifp = TAILQ_FIRST(&ifnet); ifp != NULL;
	     ifp = TAILQ_NEXT(ifp, if_list)) {
		if (ifp->if_output == if_nulloutput)
			continue;
		for (ifa = TAILQ_FIRST(&ifp->if_addrlist); ifa != NULL;
		     ifa = TAILQ_NEXT(ifa, ifa_list)) {
			char *cp, *cp2, *cp3;

			if (ifa->ifa_addr->sa_family != af ||
			    ifa->ifa_netmask == 0)
 next:				continue;
			cp = addr_data;
			cp2 = ifa->ifa_addr->sa_data;
			cp3 = ifa->ifa_netmask->sa_data;
			cplim = (char *)ifa->ifa_netmask +
			    ifa->ifa_netmask->sa_len;
			while (cp3 < cplim) {
				if ((*cp++ ^ *cp2++) & *cp3++) {
					goto next;
				}
			}
			if (ifa_maybe == 0 ||
			    rn_refines((caddr_t)ifa->ifa_netmask,
			    (caddr_t)ifa_maybe->ifa_netmask))
				ifa_maybe = ifa;
		}
	}
	return (ifa_maybe);
}

struct ifaddr *
ifaof_ifpforaddr(struct sockaddr *addr, struct ifnet *ifp)
{
	struct ifaddr *ifa;
	char *cp, *cp2, *cp3;
	char *cplim;
	struct ifaddr *ifa_maybe = 0;
	u_int af = addr->sa_family;

	if (ifp->if_output == if_nulloutput)
		return (NULL);

	if (af >= AF_MAX)
		return (NULL);

	for (ifa = TAILQ_FIRST(&ifp->if_addrlist); ifa != NULL;
	     ifa = TAILQ_NEXT(ifa, ifa_list)) {
		if (ifa->ifa_addr->sa_family != af)
			continue;
		ifa_maybe = ifa;
		if (ifa->ifa_netmask == 0) {
			if (equal(addr, ifa->ifa_addr) ||
			    (ifa->ifa_dstaddr &&
			     equal(addr, ifa->ifa_dstaddr)))
				return (ifa);
			continue;
		}
		cp = addr->sa_data;
		cp2 = ifa->ifa_addr->sa_data;
		cp3 = ifa->ifa_netmask->sa_data;
		cplim = ifa->ifa_netmask->sa_len + (char *)ifa->ifa_netmask;
		for (; cp3 < cplim; cp3++) {
			if ((*cp++ ^ *cp2++) & *cp3)
				break;
		}
		if (cp3 == cplim)
			return (ifa);
	}
	return (ifa_maybe);
}

int
if_rt_walktree(struct radix_node *rn, void *v)
{
	struct ifnet *ifp = (struct ifnet *)v;
	struct rtentry *rt = (struct rtentry *)rn;

	if (rt->rt_ifp == ifp) {
		rtrequest(RTM_DELETE, rt_key(rt), rt->rt_gateway,
		    rt_mask(rt), rt->rt_flags, NULL);
	}
	return (0);
}

struct ifaddr *
ifa_ifwithaddr(struct sockaddr *addr)
{
	struct ifnet *ifp;
	struct ifaddr *ifa;
	struct ifnet_head ifnet;

	_sce_pspnet_get_if_core_variables(NULL, NULL, NULL, &ifnet);
	for (ifp = TAILQ_FIRST(&ifnet); ifp != NULL;
	     ifp = TAILQ_NEXT(ifp, if_list)) {
		if (ifp->if_output == if_nulloutput)
			continue;
		for (ifa = TAILQ_FIRST(&ifp->if_addrlist); ifa != NULL;
		     ifa = TAILQ_NEXT(ifa, ifa_list)) {
			if (ifa->ifa_addr->sa_family != addr->sa_family)
				continue;
			if (equal(addr, ifa->ifa_addr))
				return (ifa);
			if ((ifp->if_flags & IFF_BROADCAST) &&
			    ifa->ifa_broadaddr &&
			    ifa->ifa_broadaddr->sa_len != 0 &&
			    equal(ifa->ifa_broadaddr, addr))
				return (ifa);
		}
	}
	return (NULL);
}

struct ifaddr *
ifa_ifwithdstaddr(struct sockaddr *addr)
{
	struct ifnet *ifp;
	struct ifaddr *ifa;
	struct ifnet_head ifnet;

	_sce_pspnet_get_if_core_variables(NULL, NULL, NULL, &ifnet);
	for (ifp = TAILQ_FIRST(&ifnet); ifp != NULL;
	     ifp = TAILQ_NEXT(ifp, if_list)) {
		if (ifp->if_output == if_nulloutput)
			continue;
		if (ifp->if_flags & IFF_POINTOPOINT) {
			for (ifa = TAILQ_FIRST(&ifp->if_addrlist); ifa != NULL;
			     ifa = TAILQ_NEXT(ifa, ifa_list)) {
				if (ifa->ifa_addr->sa_family !=
				      addr->sa_family ||
				    ifa->ifa_dstaddr == NULL)
					continue;
				if (equal(addr, ifa->ifa_dstaddr))
					return (ifa);
			}
		}
	}
	return (NULL);
}

struct ifaddr *
ifa_ifwithladdr(struct sockaddr *addr)
{
	struct ifaddr *ia;

	if ((ia = ifa_ifwithaddr(addr)) || (ia = ifa_ifwithdstaddr(addr)) ||
	    (ia = ifa_ifwithnet(addr)))
		return (ia);
	return (NULL);
}

struct ifaddr *
ifa_ifwithaf(int af)
{
	struct ifnet *ifp;
	struct ifaddr *ifa;
	struct ifnet_head ifnet;

	_sce_pspnet_get_if_core_variables(NULL, NULL, NULL, &ifnet);
	for (ifp = TAILQ_FIRST(&ifnet); ifp != NULL;
	     ifp = TAILQ_NEXT(ifp, if_list)) {
		if (ifp->if_output == if_nulloutput)
			continue;
		for (ifa = TAILQ_FIRST(&ifp->if_addrlist); ifa != NULL;
		     ifa = TAILQ_NEXT(ifa, ifa_list)) {
			if (ifa->ifa_addr->sa_family == af)
				return (ifa);
		}
	}
	return (NULL);
}

void
func_000093F0(struct ifnet *ifp)
{
	rt_ifannouncemsg(ifp, IFAN_ARRIVAL);
}

void
func_0000940C(struct ifaddr *ifa)
{
	rtinit(ifa, RTM_DELETE, 0);
}

void
func_0000942C(struct ifnet *ifp, int family)
{
	struct socket so;
	struct domain *dp;
	struct protosw *pr;

	memset(&so, 0, sizeof(so));
	dp = pffinddomain(family);
	for (pr = dp->dom_protosw; pr < dp->dom_protoswNPROTOSW; pr++) {
		so.so_proto = pr;
		if (pr->pr_usrreq != NULL)
			(*pr->pr_usrreq)(&so, PRU_PURGEIF, NULL, NULL,
			    (struct mbuf *)ifp);
	}
}

void
func_000094D0(struct ifnet *ifp)
{
	struct radix_node_head *rnh;
	int i;

	for (i = 0; i <= AF_MAX; i++) {
		if ((rnh = rt_tables[i]) != NULL)
			(void)(*rnh->rnh_walktree)(rnh, if_rt_walktree, ifp);
	}
}

void
func_00009548(struct ifnet *ifp)
{
	rt_ifannouncemsg(ifp, IFAN_DEPARTURE);
}

void
func_00009564(struct ifnet *ifp)
{
	struct ifaddr *ifa;

	for (ifa = TAILQ_FIRST(&ifp->if_addrlist); ifa != NULL;
	     ifa = TAILQ_NEXT(ifa, ifa_list))
		pfctlinput(PRC_IFDOWN, ifa->ifa_addr);
}

void
func_000095A4(struct ifnet *ifp)
{
	rt_ifmsg(ifp);
}

void
func_000095C0(struct ifnet *ifp)
{
	rt_ifmsg(ifp);
}

int
func_000095DC(void)
{
	return 0;
}

int
func_000095E4(struct socket *so, int *done)
{
	if (so->so_proto == NULL) {
		*done = 1;
		return (EOPNOTSUPP);
	}
	return 0;
}

int
func_00009608(struct socket *so, u_long cmd, caddr_t data, struct ifnet *ifp)
{
	return ((*so->so_proto->pr_usrreq)(so, PRU_CONTROL,
	    (struct mbuf *)cmd, (struct mbuf *)data, (struct mbuf *)ifp));
}

void func_000097BC(void);

int
func_0000963C(void)
{
	return _sce_pspnet_start_of_inet_module_in_if_core(link_rtrequest,
	    func_000097BC, func_000093F0, func_0000940C, func_0000942C,
	    func_000094D0, func_00009548, func_00009564, func_000095A4,
	    func_000095C0, func_000095DC, func_000095E4, func_00009608);
}

void
func_000096D0(void)
{
	_sce_pspnet_stop_of_inet_module_in_if_core();
}

void
link_rtrequest(int cmd, struct rtentry *rt, struct sockaddr *sa)
{
	struct ifaddr *ifa;
	struct sockaddr *dst;
	struct ifnet *ifp;

	if (cmd != RTM_ADD || ((ifa = rt->rt_ifa) == 0) ||
	    ((ifp = ifa->ifa_ifp) == 0) || ((dst = rt_key(rt)) == 0))
		return;
	if ((ifa = ifaof_ifpforaddr(dst, ifp)) != NULL) {
		IFAFREE(rt->rt_ifa);
		rt->rt_ifa = ifa;
		IFAREF(ifa);
		if (ifa->ifa_rtrequest && ifa->ifa_rtrequest != _sce_pspnet_link_rtrequest)
			ifa->ifa_rtrequest(cmd, rt, sa);
	}
}

void func_000097BC(void) {
}
