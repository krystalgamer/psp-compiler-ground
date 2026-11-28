/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

extern TAILQ_HEAD(in_mk_head, in_ifaddr) in_mk;
#define in_fmtaddr_buf D_0002EBB0
extern char in_fmtaddr_buf[sizeof("123.456.789.123")];

static int in_mask2len(struct in_addr *);
static void in_len2mask(struct in_addr *, int);
static int in_lifaddr_ioctl(struct socket *, u_long, caddr_t, struct ifnet *);

int
in_localaddr(struct in_addr in)
{
	struct in_ifaddr *ia;

	if (subnetsarelocal) {
		for (ia = in_ifaddr.tqh_first; ia != 0; ia = ia->ia_list.tqe_next)
			if ((in.s_addr & ia->ia_netmask) == ia->ia_net)
				return (1);
	} else {
		for (ia = in_ifaddr.tqh_first; ia != 0; ia = ia->ia_list.tqe_next)
			if ((in.s_addr & ia->ia_subnetmask) == ia->ia_subnet)
				return (1);
	}
	return (0);
}

int
in_canforward(struct in_addr in)
{
	u_int32_t net;

	if (IN_EXPERIMENTAL(in.s_addr) || IN_MULTICAST(in.s_addr))
		return (0);
	if (IN_CLASSA(in.s_addr)) {
		net = in.s_addr & IN_CLASSA_NET;
		if (net == 0 || net == htonl(IN_LOOPBACKNET << IN_CLASSA_NSHIFT))
			return (0);
	}
	return (1);
}

void
in_socktrim(struct sockaddr_in *ap)
{
	char *cplim = (char *) &ap->sin_addr;
	char *cp = (char *) (&ap->sin_addr + 1);

	ap->sin_len = 0;
	while (--cp >= cplim)
		if (*cp) {
			(ap)->sin_len = cp - (char *) (ap) + 1;
			break;
		}
}

const char *
in_fmtaddr(struct in_addr addr)
{

	addr.s_addr = ntohl(addr.s_addr);

	sprintf(in_fmtaddr_buf, "%d.%d.%d.%d",
		(addr.s_addr >> 24) & 0xFF,
		(addr.s_addr >> 16) & 0xFF,
		(addr.s_addr >>  8) & 0xFF,
		(addr.s_addr >>  0) & 0xFF);
	return in_fmtaddr_buf;
}

void
in_setmaxmtu(void)
{
	struct in_ifaddr *ia;
	struct ifnet *ifp;
	unsigned long maxmtu = 0;

	for (ia = in_ifaddr.tqh_first; ia != 0; ia = ia->ia_list.tqe_next) {
		if ((ifp = ia->ia_ifp) == 0)
			continue;
		if ((ifp->if_flags & (IFF_UP|IFF_LOOPBACK)) != IFF_UP)
			continue;
		if (ifp->if_mtu > maxmtu)
			maxmtu = ifp->if_mtu;
	}
	if (maxmtu)
		in_maxmtu = maxmtu;
}

static int
in_mask2len(struct in_addr *mask)
{
	int x, y;
	u_char *p;

	p = (u_char *)mask;
	for (x = 0; x < sizeof(*mask); x++) {
		if (p[x] != 0xff)
			break;
	}
	y = 0;
	if (x < sizeof(*mask)) {
		for (y = 0; y < 8; y++) {
			if ((p[x] & (0x80 >> y)) == 0)
				break;
		}
	}
	return x * 8 + y;
}

static void
in_len2mask(struct in_addr *mask, int len)
{
	int i;
	u_char *p;

	p = (u_char *)mask;
	memset(mask, 0, sizeof(*mask));
	for (i = 0; i < len / 8; i++)
		p[i] = 0xff;
	if (len % 8)
		p[i] = (0xff00 >> (len % 8)) & 0xff;
}

int
in_control(struct socket *so, u_long cmd, caddr_t data, struct ifnet *ifp)
{
	struct ifreq *ifr = (struct ifreq *)data;
	struct in_ifaddr *ia = 0;
	struct in_aliasreq *ifra = (struct in_aliasreq *)data;
	struct sockaddr_in oldaddr;
	int error, hostIsNew, maskIsNew;
	int newifaddr;

	switch (cmd) {
	case SIOCALIFADDR:
	case SIOCDLIFADDR:
	case SIOCGLIFADDR:
		if (!ifp)
			return EINVAL;
		return in_lifaddr_ioctl(so, cmd, data, ifp);
	}

	/*
	 * Find address for this interface, if it exists.
	 */
	if (ifp)
		IFP_TO_IA(ifp, ia);

	switch (cmd) {

	case SIOCAIFADDR:
	case SIOCDIFADDR:
	case SIOCGIFALIAS:
		if (ifra->ifra_addr.sin_family == AF_INET)
			for (ia = IN_IFADDR_HASH(ifra->ifra_addr.sin_addr.s_addr).lh_first;
			    ia != 0; ia = ia->ia_hash.le_next) {
				if (ia->ia_ifp == ifp  &&
				    in_hosteq(ia->ia_addr.sin_addr,
				    ifra->ifra_addr.sin_addr))
					break;
			}
		if (cmd == SIOCDIFADDR) {
			if (ia == 0)
				return (EADDRNOTAVAIL);
			if (ifra->ifra_addr.sin_family == AF_UNSPEC)
				ifra->ifra_addr.sin_family = AF_INET;
		}
		/* FALLTHROUGH */
	case SIOCSIFADDR:
	case SIOCSIFDSTADDR:
		if (ifra->ifra_addr.sin_family != AF_INET)
			return (EAFNOSUPPORT);
		/* FALLTHROUGH */
	case SIOCSIFNETMASK:
		if (cmd == SIOCGIFALIAS)
			break;

		if (ia == 0) {
			ia = sceNetMallocInternal(sizeof(*ia));
			if (ia == 0)
				return (ENOBUFS);
			memset((caddr_t)ia, 0, sizeof *ia);
			TAILQ_INSERT_TAIL(&in_ifaddr, ia, ia_list);
			IFAREF(&ia->ia_ifa);
			TAILQ_INSERT_TAIL(&ifp->if_addrlist, &ia->ia_ifa,
			    ifa_list);
			IFAREF(&ia->ia_ifa);
			ia->ia_ifa.ifa_addr = sintosa(&ia->ia_addr);
			ia->ia_ifa.ifa_dstaddr = sintosa(&ia->ia_dstaddr);
			ia->ia_ifa.ifa_netmask = sintosa(&ia->ia_sockmask);
			ia->ia_sockmask.sin_len = 8;
			if (ifp->if_flags & IFF_BROADCAST) {
				ia->ia_broadaddr.sin_len = sizeof(ia->ia_addr);
				ia->ia_broadaddr.sin_family = AF_INET;
			}
			ia->ia_ifp = ifp;
			LIST_INIT(&ia->ia_multiaddrs);
			newifaddr = 1;
		} else
			newifaddr = 0;
		break;

	case SIOCSIFBRDADDR:

	case SIOCGIFADDR:
	case SIOCGIFNETMASK:
	case SIOCGIFDSTADDR:
	case SIOCGIFBRDADDR:
		if (ia == 0)
			return (EADDRNOTAVAIL);
		break;
	}
	switch (cmd) {

	case SIOCGIFADDR:
		*satosin(&ifr->ifr_addr) = ia->ia_addr;
		break;

	case SIOCGIFBRDADDR:
		if ((ifp->if_flags & IFF_BROADCAST) == 0)
			return (EINVAL);
		*satosin(&ifr->ifr_dstaddr) = ia->ia_broadaddr;
		break;

	case SIOCGIFDSTADDR:
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0)
			return (EINVAL);
		*satosin(&ifr->ifr_dstaddr) = ia->ia_dstaddr;
		break;

	case SIOCGIFNETMASK:
		*satosin(&ifr->ifr_addr) = ia->ia_sockmask;
		break;

	case SIOCSIFDSTADDR:
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0)
			return (EINVAL);
		oldaddr = ia->ia_dstaddr;
		ia->ia_dstaddr = *satosin(&ifr->ifr_dstaddr);
		if (ifp->if_ioctl && (error = (*ifp->if_ioctl)
					(ifp, SIOCSIFDSTADDR, (caddr_t)ia))) {
			ia->ia_dstaddr = oldaddr;
			return (error);
		}
		if (ia->ia_flags & IFA_ROUTE) {
			ia->ia_ifa.ifa_dstaddr = sintosa(&oldaddr);
			rtinit(&(ia->ia_ifa), (int)RTM_DELETE, RTF_HOST);
			ia->ia_ifa.ifa_dstaddr = sintosa(&ia->ia_dstaddr);
			rtinit(&(ia->ia_ifa), (int)RTM_ADD, RTF_HOST|RTF_UP);
		}
		break;

	case SIOCSIFBRDADDR:
		if ((ifp->if_flags & IFF_BROADCAST) == 0)
			return (EINVAL);
		ia->ia_broadaddr = *satosin(&ifr->ifr_broadaddr);
		break;

	case SIOCSIFADDR:
		error = in_ifinit(ifp, ia, satosin(&ifr->ifr_addr), 1);
		return error;

	case SIOCSIFNETMASK:
		ia->ia_subnetmask = ia->ia_sockmask.sin_addr.s_addr =
		    ifra->ifra_addr.sin_addr.s_addr;
		break;

	case SIOCAIFADDR:
		maskIsNew = 0;
		hostIsNew = 1;
		error = 0;
		if (ia->ia_addr.sin_family == AF_INET) {
			if (ifra->ifra_addr.sin_len == 0) {
				ifra->ifra_addr = ia->ia_addr;
				hostIsNew = 0;
			} else if (in_hosteq(ia->ia_addr.sin_addr, ifra->ifra_addr.sin_addr))
				hostIsNew = 0;
		}
		if (ifra->ifra_mask.sin_len) {
			in_ifscrub(ifp, ia);
			ia->ia_sockmask = ifra->ifra_mask;
			ia->ia_subnetmask = ia->ia_sockmask.sin_addr.s_addr;
			maskIsNew = 1;
		}
		if ((ifp->if_flags & IFF_POINTOPOINT) &&
		    (ifra->ifra_dstaddr.sin_family == AF_INET)) {
			in_ifscrub(ifp, ia);
			ia->ia_dstaddr = ifra->ifra_dstaddr;
			maskIsNew  = 1; /* We lie; but the effect's the same */
		}
		if (ifra->ifra_addr.sin_family == AF_INET &&
		    (hostIsNew || maskIsNew)) {
			error = in_ifinit(ifp, ia, &ifra->ifra_addr, 0);
		}
		if ((ifp->if_flags & IFF_BROADCAST) &&
		    (ifra->ifra_broadaddr.sin_family == AF_INET))
			ia->ia_broadaddr = ifra->ifra_broadaddr;
		return (error);

	case SIOCGIFALIAS:
		ifra->ifra_mask = ia->ia_sockmask;
		if ((ifp->if_flags & IFF_POINTOPOINT) &&
		    (ia->ia_dstaddr.sin_family == AF_INET))
			ifra->ifra_dstaddr = ia->ia_dstaddr;
		else if ((ifp->if_flags & IFF_BROADCAST) &&
		    (ia->ia_broadaddr.sin_family == AF_INET))
			ifra->ifra_broadaddr = ia->ia_broadaddr;
		else
			memset(&ifra->ifra_broadaddr, 0, sizeof(ifra->ifra_broadaddr));
		return 0;

	case SIOCDIFADDR:
		in_purgeaddr(&ia->ia_ifa, ifp);
		break;


	default:
		if (ifp == 0 || ifp->if_ioctl == 0)
			return (EOPNOTSUPP);
		error = (*ifp->if_ioctl)(ifp, cmd, data);
		in_setmaxmtu();
		return(error);
	}
	return (0);
}

void
in_purgeaddr(struct ifaddr *ifa, struct ifnet *ifp)
{
	struct in_ifaddr *ia = (void *) ifa;

	in_ifscrub(ifp, ia);
	LIST_REMOVE(ia, ia_hash);
	TAILQ_REMOVE(&ifp->if_addrlist, &ia->ia_ifa, ifa_list);
	IFAFREE(&ia->ia_ifa);
	TAILQ_REMOVE(&in_ifaddr, ia, ia_list);
	if (ia->ia_allhosts != NULL)
		in_delmulti(ia->ia_allhosts);
	if (LIST_FIRST(&ia->ia_multiaddrs) != NULL &&
	    /*
	     * If the interface is going away, don't bother to save
	     * the multicast entries.
	     */
	    ifp->if_output != if_nulloutput)
		in_savemkludge(ia);
	IFAFREE(&ia->ia_ifa);
	in_setmaxmtu();
}

void
in_purgeif(struct ifnet *ifp)
{
	struct ifaddr *ifa, *nifa;

	for (ifa = TAILQ_FIRST(&ifp->if_addrlist); ifa != NULL; ifa = nifa) {
		nifa = TAILQ_NEXT(ifa, ifa_list);
		if (ifa->ifa_addr->sa_family != AF_INET)
			continue;
		in_purgeaddr(ifa, ifp);
	}
	in_purgemkludge(ifp);
}

static int
in_lifaddr_ioctl(struct socket *so, u_long cmd, caddr_t data, struct ifnet *ifp)
{
	struct if_laddrreq *iflr = (struct if_laddrreq *)data;
	struct ifaddr *ifa;
	struct sockaddr *sa;

	/* sanity checks */
	switch (cmd) {
	case SIOCGLIFADDR:
		/* address must be specified on GET with IFLR_PREFIX */
		if ((iflr->flags & IFLR_PREFIX) == 0)
			break;
		/*FALLTHROUGH*/
	case SIOCALIFADDR:
	case SIOCDLIFADDR:
		/* address must be specified on ADD and DELETE */
		sa = (struct sockaddr *)&iflr->addr;
		if (sa->sa_family != AF_INET)
			return EINVAL;
		if (sa->sa_len != sizeof(struct sockaddr_in))
			return EINVAL;
		/* XXX need improvement */
		sa = (struct sockaddr *)&iflr->dstaddr;
		if (sa->sa_family
		 && sa->sa_family != AF_INET)
			return EINVAL;
		if (sa->sa_len && sa->sa_len != sizeof(struct sockaddr_in))
			return EINVAL;
		break;
	default:
		return EOPNOTSUPP;
	}
	if (sizeof(struct in_addr) * 8 < iflr->prefixlen)
		return EINVAL;

	switch (cmd) {
	case SIOCALIFADDR:
	    {
		struct in_aliasreq ifra;

		if (iflr->flags & IFLR_PREFIX)
			return EINVAL;

		/* copy args to in_aliasreq, perform ioctl(SIOCAIFADDR_IN6). */
		memset(&ifra, 0, sizeof(ifra));
		bcopy(iflr->iflr_name, ifra.ifra_name,
			sizeof(ifra.ifra_name));

		bcopy(&iflr->addr, &ifra.ifra_addr,
			((struct sockaddr *)&iflr->addr)->sa_len);

		if (((struct sockaddr *)&iflr->dstaddr)->sa_family) {	/*XXX*/
			bcopy(&iflr->dstaddr, &ifra.ifra_dstaddr,
				((struct sockaddr *)&iflr->dstaddr)->sa_len);
		}

		ifra.ifra_mask.sin_family = AF_INET;
		ifra.ifra_mask.sin_len = sizeof(struct sockaddr_in);
		in_len2mask(&ifra.ifra_mask.sin_addr, iflr->prefixlen);

		return in_control(so, SIOCAIFADDR, (caddr_t)&ifra, ifp);
	    }
	case SIOCGLIFADDR:
	case SIOCDLIFADDR:
	    {
		struct in_ifaddr *ia;
		struct in_addr mask, candidate, match;
		struct sockaddr_in *sin;
		int cmp;

		memset(&mask, 0, sizeof(mask));
		if (iflr->flags & IFLR_PREFIX) {
			/* lookup a prefix rather than address. */
			in_len2mask(&mask, iflr->prefixlen);

			sin = (struct sockaddr_in *)&iflr->addr;
			match.s_addr = sin->sin_addr.s_addr;
			match.s_addr &= mask.s_addr;

			/* if you set extra bits, that's wrong */
			if (match.s_addr != sin->sin_addr.s_addr)
				return EINVAL;

			cmp = 1;
		} else {
			if (cmd == SIOCGLIFADDR) {
				/* on getting an address, take the 1st match */
				cmp = 0;	/*XXX*/
			} else {
				/* on deleting an address, do exact match */
				in_len2mask(&mask, 32);
				sin = (struct sockaddr_in *)&iflr->addr;
				match.s_addr = sin->sin_addr.s_addr;

				cmp = 1;
			}
		}

		for (ifa = ifp->if_addrlist.tqh_first; ifa; ifa = ifa->ifa_list.tqe_next) {
			if (ifa->ifa_addr->sa_family != AF_INET6)
				continue;
			if (!cmp)
				break;
			candidate.s_addr = ((struct sockaddr_in *)&ifa->ifa_addr)->sin_addr.s_addr;
			candidate.s_addr &= mask.s_addr;
			if (candidate.s_addr == match.s_addr)
				break;
		}
		if (!ifa)
			return EADDRNOTAVAIL;
		ia = (struct in_ifaddr *)ifa;

		if (cmd == SIOCGLIFADDR) {
			/* fill in the if_laddrreq structure */
			bcopy(&ia->ia_addr, &iflr->addr, ia->ia_addr.sin_len);

			if ((ifp->if_flags & IFF_POINTOPOINT) != 0) {
				bcopy(&ia->ia_dstaddr, &iflr->dstaddr,
					ia->ia_dstaddr.sin_len);
			} else
				memset(&iflr->dstaddr, 0, sizeof(iflr->dstaddr));

			iflr->prefixlen =
				in_mask2len(&ia->ia_sockmask.sin_addr);

			iflr->flags = 0;	/*XXX*/

			return 0;
		} else {
			struct in_aliasreq ifra;

			/* fill in_aliasreq and do ioctl(SIOCDIFADDR_IN6) */
			memset(&ifra, 0, sizeof(ifra));
			bcopy(iflr->iflr_name, ifra.ifra_name,
				sizeof(ifra.ifra_name));

			bcopy(&ia->ia_addr, &ifra.ifra_addr,
				ia->ia_addr.sin_len);
			if ((ifp->if_flags & IFF_POINTOPOINT) != 0) {
				bcopy(&ia->ia_dstaddr, &ifra.ifra_dstaddr,
					ia->ia_dstaddr.sin_len);
			}
			bcopy(&ia->ia_sockmask, &ifra.ifra_dstaddr,
				ia->ia_sockmask.sin_len);

			return in_control(so, SIOCDIFADDR, (caddr_t)&ifra,
				ifp);
		}
	    }
	}

	return EOPNOTSUPP;	/*just for safety*/
}

void
in_ifscrub(struct ifnet *ifp, struct in_ifaddr *ia)
{

	if ((ia->ia_flags & IFA_ROUTE) == 0)
		return;
	if (ifp->if_flags & (IFF_LOOPBACK|IFF_POINTOPOINT))
		rtinit(&(ia->ia_ifa), (int)RTM_DELETE, RTF_HOST);
	else
		rtinit(&(ia->ia_ifa), (int)RTM_DELETE, 0);
	ia->ia_flags &= ~IFA_ROUTE;
}

int
in_ifinit(struct ifnet *ifp, struct in_ifaddr *ia, struct sockaddr_in *sin, int scrub)
{
	u_int32_t i = sin->sin_addr.s_addr;
	struct sockaddr_in oldaddr;
	int s = _sce_pspnet_spllock(), flags = RTF_UP, error;

	/*
	 * Set up new addresses.
	 */
	oldaddr = ia->ia_addr;
	if (ia->ia_addr.sin_family == AF_INET)
		LIST_REMOVE(ia, ia_hash);
	ia->ia_addr = *sin;
	LIST_INSERT_HEAD(&IN_IFADDR_HASH(ia->ia_addr.sin_addr.s_addr), ia, ia_hash);

	/*
	 * Give the interface a chance to initialize
	 * if this is its first address,
	 * and to validate the address if necessary.
	 */
	if (ifp->if_ioctl &&
	    (error = (*ifp->if_ioctl)(ifp, SIOCSIFADDR, (caddr_t)ia)))
		goto bad;
	_sce_pspnet_splunlock(s);
	if (scrub) {
		ia->ia_ifa.ifa_addr = sintosa(&oldaddr);
		in_ifscrub(ifp, ia);
		ia->ia_ifa.ifa_addr = sintosa(&ia->ia_addr);
	}

	if (IN_CLASSA(i))
		ia->ia_netmask = IN_CLASSA_NET;
	else if (IN_CLASSB(i))
		ia->ia_netmask = IN_CLASSB_NET;
	else
		ia->ia_netmask = IN_CLASSC_NET;
	/*
	 * The subnet mask usually includes at least the standard network part,
	 * but may may be smaller in the case of supernetting.
	 * If it is set, we believe it.
	 */
	if (ia->ia_subnetmask == 0) {
		ia->ia_subnetmask = ia->ia_netmask;
		ia->ia_sockmask.sin_addr.s_addr = ia->ia_subnetmask;
	} else
		ia->ia_netmask &= ia->ia_subnetmask;

	ia->ia_net = i & ia->ia_netmask;
	ia->ia_subnet = i & ia->ia_subnetmask;
	in_socktrim(&ia->ia_sockmask);
	/* re-calculate the "in_maxmtu" value */
	in_setmaxmtu();
	/*
	 * Add route for the network.
	 */
	ia->ia_ifa.ifa_metric = ifp->if_metric;
	if (ifp->if_flags & IFF_BROADCAST) {
		ia->ia_broadaddr.sin_addr.s_addr =
			ia->ia_subnet | ~ia->ia_subnetmask;
		ia->ia_netbroadcast.s_addr =
			ia->ia_net | ~ia->ia_netmask;
	} else if (ifp->if_flags & IFF_LOOPBACK) {
		ia->ia_ifa.ifa_dstaddr = ia->ia_ifa.ifa_addr;
		flags |= RTF_HOST;
	} else if (ifp->if_flags & IFF_POINTOPOINT) {
		if (ia->ia_dstaddr.sin_family != AF_INET)
			return (0);
		flags |= RTF_HOST;
	}
	error = rtinit(&ia->ia_ifa, (int)RTM_ADD, flags);
	if (!error)
		ia->ia_flags |= IFA_ROUTE;
	/* XXX check if the subnet route points to the same interface */
	if (error == EEXIST)
		error = 0;
	/*
	 * recover multicast kludge entry, if there is.
	 */
	if (ifp->if_flags & IFF_MULTICAST)
		in_restoremkludge(ia, ifp);
	/*
	 * If the interface supports multicast, join the "all hosts"
	 * multicast group on that interface.
	 */
	if ((ifp->if_flags & IFF_MULTICAST) != 0 && ia->ia_allhosts == NULL) {
		struct in_addr addr;

		addr.s_addr = INADDR_ALLHOSTS_GROUP;
		ia->ia_allhosts = in_addmulti(&addr, ifp);
	}
	return (error);
bad:
	_sce_pspnet_splunlock(s);
	LIST_REMOVE(ia, ia_hash);
	ia->ia_addr = oldaddr;
	if (ia->ia_addr.sin_family == AF_INET)
		LIST_INSERT_HEAD(&IN_IFADDR_HASH(ia->ia_addr.sin_addr.s_addr),
		    ia, ia_hash);
	return (error);
}

int
in_broadcast(struct in_addr in, struct ifnet *ifp)
{
	struct ifaddr *ifa;

	if (in.s_addr == INADDR_BROADCAST ||
	    in_nullhost(in))
		return 1;
	if ((ifp->if_flags & IFF_BROADCAST) == 0)
		return 0;
	/*
	 * Look through the list of addresses for a match
	 * with a broadcast address.
	 */
#define ia (ifatoia(ifa))
	for (ifa = ifp->if_addrlist.tqh_first; ifa; ifa = ifa->ifa_list.tqe_next)
		if (ifa->ifa_addr->sa_family == AF_INET &&
		    !in_hosteq(in, ia->ia_addr.sin_addr) &&
		    (in_hosteq(in, ia->ia_broadaddr.sin_addr) ||
		     in_hosteq(in, ia->ia_netbroadcast) ||
		     (hostzeroisbroadcast && 
		      /*
		       * Check for old-style (host 0) broadcast.
		       */
		      (in.s_addr == ia->ia_subnet ||
		       in.s_addr == ia->ia_net))))
			return 1;
	return (0);
#undef ia
}

void
in_savemkludge(struct in_ifaddr *oia)
{
	struct in_ifaddr *ia;
	struct in_multi *inm, *next;

	IFP_TO_IA(oia->ia_ifp, ia);
	if (ia) {	/* there is another address */
		for (inm = oia->ia_multiaddrs.lh_first; inm; inm = next){
			next = inm->inm_list.le_next;
			IFAFREE(&inm->inm_ia->ia_ifa);
			IFAREF(&ia->ia_ifa);
			inm->inm_ia = ia;
			LIST_INSERT_HEAD(&ia->ia_multiaddrs, inm, inm_list);
		}
	} else {	/* last address on this if deleted, save */
		TAILQ_INSERT_TAIL(&in_mk, oia, ia_list);
		IFAREF(&oia->ia_ifa);
	}
}

void
in_restoremkludge(struct in_ifaddr *ia, struct ifnet *ifp)
{
	struct in_ifaddr *oia;

	for (oia = TAILQ_FIRST(&in_mk); oia != NULL;
	    oia = TAILQ_NEXT(oia, ia_list)) {
		if (oia->ia_ifp == ifp) {
			struct in_multi *inm, *next;

			for (inm = LIST_FIRST(&oia->ia_multiaddrs);
			    inm != NULL; inm = next) {
				next = LIST_NEXT(inm, inm_list);
				IFAFREE(&inm->inm_ia->ia_ifa);
				IFAREF(&ia->ia_ifa);
				inm->inm_ia = ia;
				LIST_INSERT_HEAD(&ia->ia_multiaddrs,
				    inm, inm_list);
			}
	    		TAILQ_REMOVE(&in_mk, oia, ia_list);
			IFAFREE(&oia->ia_ifa);
			break;
		}
	}
}

void
in_purgemkludge(struct ifnet *ifp)
{
	struct in_ifaddr *oia;

	for (oia = TAILQ_FIRST(&in_mk); oia != NULL;
	    oia = TAILQ_NEXT(oia, ia_list)) {
		if (oia->ia_ifp != ifp)
			continue;

		/*
		 * Leaving from all multicast groups joined through
		 * this interface is done via in_pcbpurgeif().
		 */

	    	TAILQ_REMOVE(&in_mk, oia, ia_list);
		IFAFREE(&oia->ia_ifa);
		break;
	}
}

struct in_multi *
in_addmulti(struct in_addr *ap, struct ifnet *ifp)
{
	struct in_multi *inm;
	struct ifreq ifr;
	struct in_ifaddr *ia;
	int s = _sce_pspnet_spllock();

	/*
	 * See if address already in list.
	 */
	IN_LOOKUP_MULTI(*ap, ifp, inm);
	if (inm != NULL) {
		/*
		 * Found it; just increment the reference count.
		 */
		++inm->inm_refcount;
	} else {
		/*
		 * New address; allocate a new multicast record
		 * and link it into the interface's multicast list.
		 */
		inm = (struct in_multi *)sceNetMallocInternal(sizeof(*inm));
		if (inm == NULL) {
			_sce_pspnet_splunlock(s);
			return (NULL);
		}
		inm->inm_addr = *ap;
		inm->inm_ifp = ifp;
		inm->inm_refcount = 1;
		IFP_TO_IA(ifp, ia);
		if (ia == NULL) {
			sceNetFreeInternal(inm);
			_sce_pspnet_splunlock(s);
			return (NULL);
		}
		inm->inm_ia = ia;
		IFAREF(&inm->inm_ia->ia_ifa);
		LIST_INSERT_HEAD(&ia->ia_multiaddrs, inm, inm_list);
		/*
		 * Ask the network driver to update its multicast reception
		 * filter appropriately for the new address.
		 */
		satosin(&ifr.ifr_addr)->sin_len = sizeof(struct sockaddr_in);
		satosin(&ifr.ifr_addr)->sin_family = AF_INET;
		satosin(&ifr.ifr_addr)->sin_addr = *ap;
		if ((ifp->if_ioctl == NULL) ||
		    (*ifp->if_ioctl)(ifp, SIOCADDMULTI,(caddr_t)&ifr) != 0) {
			LIST_REMOVE(inm, inm_list);
			sceNetFreeInternal(inm);
			_sce_pspnet_splunlock(s);
			return (NULL);
		}
		/*
		 * Let IGMP know that we have joined a new IP multicast group.
		 */
		igmp_joingroup(inm);
	}
	_sce_pspnet_splunlock(s);
	return (inm);
}

void
in_delmulti(struct in_multi *inm)
{
	struct ifreq ifr;
	int s = _sce_pspnet_spllock();

	if (--inm->inm_refcount == 0) {
		/*
		 * No remaining claims to this record; let IGMP know that
		 * we are leaving the multicast group.
		 */
		igmp_leavegroup(inm);
		/*
		 * Unlink from list.
		 */
		LIST_REMOVE(inm, inm_list);
		IFAFREE(&inm->inm_ia->ia_ifa);
		/*
		 * Notify the network driver to update its multicast reception
		 * filter.
		 */
		satosin(&ifr.ifr_addr)->sin_family = AF_INET;
		satosin(&ifr.ifr_addr)->sin_addr = inm->inm_addr;
		(*inm->inm_ifp->if_ioctl)(inm->inm_ifp, SIOCDELMULTI,
							     (caddr_t)&ifr);
		sceNetFreeInternal(inm);
	}
	_sce_pspnet_splunlock(s);
}

void
func_00012D54(void)
{
	hostzeroisbroadcast = subnetsarelocal = 1;
	in_maxmtu = 0;
	TAILQ_INIT(&in_mk);
}
