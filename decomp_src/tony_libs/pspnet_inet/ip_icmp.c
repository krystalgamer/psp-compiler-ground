/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"
#include <stdarg.h>

#define mtutab D_0002E89C
#define mtu_table D_0002E864
extern u_int mtu_table[14];
extern int icmpreturndatabytes, icmpmaskrepl, icmperrppslim;
extern struct icmpstat_t icmpstat;
extern struct sockaddr_in icmpsrc __attribute__((aligned(4))), icmpdst __attribute__((aligned(4))), icmpgw __attribute__((aligned(4)));
struct icmp_mtudisc_callback {
	LIST_ENTRY(icmp_mtudisc_callback) mc_list;
	void (*mc_func)(struct in_addr);
};
extern LIST_HEAD(, icmp_mtudisc_callback) icmp_mtudisc_callbacks;
extern struct rttimer_queue *ip_mtudisc_timeout_q;
extern int mtutab[12];

void icmp_mtudisc(struct icmp *, struct in_addr);
static void icmp_mtudisc_timeout(struct rtentry *, struct rttimer *);
static int icmp_ratelimit(const struct in_addr *, const int, const int);

void
icmp_mtudisc_callback_register(void (*func)(struct in_addr))
{
	struct icmp_mtudisc_callback *mc;

	for (mc = LIST_FIRST(&icmp_mtudisc_callbacks); mc != NULL;
	     mc = LIST_NEXT(mc, mc_list)) {
		if (mc->mc_func == func)
			return;
	}

	mc = sceNetMallocInternal(sizeof(*mc));
	if (mc == NULL)
		return;

	mc->mc_func = func;
	LIST_INSERT_HEAD(&icmp_mtudisc_callbacks, mc, mc_list);
}

void
icmp_init(void)
{
	icmpreturndatabytes = 8;
	icmpmaskrepl = 0;
	memset(&icmpstat, 0, sizeof(icmpstat));
	memset(&icmpsrc, 0, sizeof(icmpsrc));
	icmpsrc.sin_len = sizeof(struct sockaddr_in);
	icmpsrc.sin_family = AF_INET;
	memset(&icmpdst, 0, sizeof(icmpdst));
	icmpdst.sin_len = sizeof(struct sockaddr_in);
	icmpdst.sin_family = AF_INET;
	memset(&icmpgw, 0, sizeof(icmpgw));
	icmpgw.sin_len = sizeof(struct sockaddr_in);
	icmpgw.sin_family = AF_INET;
	LIST_INIT(&icmp_mtudisc_callbacks);
}

void
icmp_error(struct mbuf *n, int type, int code, n_long dest, struct ifnet *destifp)
{
	struct ip *oip = mtod(n, struct ip *), *nip;
	unsigned oiplen = oip->ip_hl << 2;
	struct icmp *icp;
	struct mbuf *m;
	unsigned icmplen, mblen;

	if (type != ICMP_REDIRECT)
		icmpstat.icps_error++;
	/*
	 * Don't send error if the original packet was encrypted.
	 * Don't send error if not the first fragment of message.
	 * Don't error if the old packet protocol was ICMP
	 * error message, only known informational types.
	 */
	if (n->m_flags & M_DECRYPTED)
		goto freeit;
	if (oip->ip_off &~ (IP_MF|IP_DF))
		goto freeit;
	if (oip->ip_p == IPPROTO_ICMP && type != ICMP_REDIRECT &&
	  n->m_len >= oiplen + ICMP_MINLEN &&
	  !ICMP_INFOTYPE(((struct icmp *)((caddr_t)oip + oiplen))->icmp_type)) {
		icmpstat.icps_oldicmp++;
		goto freeit;
	}
	/* Don't send error in response to a multicast or broadcast packet */
	if (n->m_flags & (M_BCAST|M_MCAST))
		goto freeit;

	/*
	 * First, do a rate limitation check.
	 */
	if (icmp_ratelimit(&oip->ip_src, type, code)) {
		/* XXX stat */
		goto freeit;
	}

	/*
	 * Now, formulate icmp message
	 */
	icmplen = oiplen + min(icmpreturndatabytes, oip->ip_len - oiplen);
	/*
	 * Defend against mbuf chains shorter than oip->ip_len:
	 */
	mblen = 0;
	for (m = n; m && (mblen < icmplen); m = m->m_next)
		mblen += m->m_len;
	icmplen = min(mblen, icmplen);

	/*
	 * As we are not required to return everything we have,
	 * we return whatever we can return at ease.
	 *
	 * Note that ICMP datagrams longer than 576 octets are out of spec
	 * according to RFC1812; the limit on icmpreturndatabytes below in
	 * icmp_sysctl will keep things below that limit.
	 */


	if (icmplen + ICMP_MINLEN > MCLBYTES)
		icmplen = MCLBYTES - ICMP_MINLEN;

	m = m_gethdr(M_DONTWAIT, MT_HEADER);
	if (m && (icmplen + ICMP_MINLEN > MHLEN)) {
		MCLGET(m, M_DONTWAIT);
		if ((m->m_flags & M_EXT) == 0) {
			m_freem(m);
			m = NULL;
		}
	}
	if (m == NULL)
		goto freeit;
	m->m_len = icmplen + ICMP_MINLEN;
	if ((m->m_flags & M_EXT) == 0)
		MH_ALIGN(m, m->m_len);
	icp = mtod(m, struct icmp *);
	icmpstat.icps_outhist[type]++;
	icp->icmp_type = type;
	if (type == ICMP_REDIRECT)
		icp->icmp_gwaddr.s_addr = dest;
	else {
		icp->icmp_void = 0;
		/* 
		 * The following assignments assume an overlay with the
		 * zeroed icmp_void field.
		 */
		if (type == ICMP_PARAMPROB) {
			icp->icmp_pptr = code;
			code = 0;
		} else if (type == ICMP_UNREACH &&
		    code == ICMP_UNREACH_NEEDFRAG && destifp)
			icp->icmp_nextmtu = htons(destifp->if_mtu);
	}

	HTONS(oip->ip_off);
	HTONS(oip->ip_len);
	icp->icmp_code = code;
	m_copydata(n, 0, icmplen, (caddr_t)&icp->icmp_ip);
	nip = &icp->icmp_ip;

	/*
	 * Now, copy old ip header (without options)
	 * in front of icmp message.
	 */
	m->m_data -= sizeof(struct ip);
	m->m_len += sizeof(struct ip);
	m->m_pkthdr.len = m->m_len;
	m->m_pkthdr.rcvif = n->m_pkthdr.rcvif;
	nip = mtod(m, struct ip *);
	/* ip_v set in ip_output */
	nip->ip_hl = sizeof(struct ip) >> 2;
	nip->ip_tos = 0;
	nip->ip_len = m->m_len;
	/* ip_id set in ip_output */
	nip->ip_off = 0;
	/* ip_ttl set in icmp_reflect */
	nip->ip_p = IPPROTO_ICMP;
	nip->ip_src = oip->ip_src;
	nip->ip_dst = oip->ip_dst;
	icmp_reflect(m);

freeit:
	m_freem(n);
}

void
icmp_input(struct mbuf *m, ...)
{
	int proto;
	struct icmp *icp;
	struct ip *ip = mtod(m, struct ip *);
	int icmplen;
	int i;
	struct in_ifaddr *ia;
	void *(*ctlfunc) (int, struct sockaddr *, void *);
	int code;
	int hlen;
	va_list ap;

	va_start(ap, m);
	hlen = va_arg(ap, int);
	proto = va_arg(ap, int);
	va_end(ap);

	/*
	 * Locate icmp structure in mbuf, and check
	 * that not corrupted and of at least minimum length.
	 */
	icmplen = ip->ip_len - hlen;
	if (icmplen < ICMP_MINLEN) {
		icmpstat.icps_tooshort++;
		goto freeit;
	}
	i = hlen + min(icmplen, ICMP_ADVLENMIN);
	if (m->m_len < i && (m = m_pullup(m, i)) == 0) {
		icmpstat.icps_tooshort++;
		return;
	}
	ip = mtod(m, struct ip *);
	m->m_len -= hlen;
	m->m_data += hlen;
	icp = mtod(m, struct icmp *);
	if (in_cksum(m, icmplen)) {
		icmpstat.icps_checksum++;
		goto freeit;
	}
	m->m_len += hlen;
	m->m_data -= hlen;

	if (icp->icmp_type > ICMP_MAXTYPE)
		goto raw;
	icmpstat.icps_inhist[icp->icmp_type]++;
	code = icp->icmp_code;
	switch (icp->icmp_type) {

	case ICMP_UNREACH:
		switch (code) {
			case ICMP_UNREACH_NET:
			case ICMP_UNREACH_HOST:
			case ICMP_UNREACH_PROTOCOL:
			case ICMP_UNREACH_PORT:
			case ICMP_UNREACH_SRCFAIL:
				code += PRC_UNREACH_NET;
				break;

			case ICMP_UNREACH_NEEDFRAG:
				code = PRC_MSGSIZE;
				break;
				
			case ICMP_UNREACH_NET_UNKNOWN:
			case ICMP_UNREACH_NET_PROHIB:
			case ICMP_UNREACH_TOSNET:
				code = PRC_UNREACH_NET;
				break;

			case ICMP_UNREACH_HOST_UNKNOWN:
			case ICMP_UNREACH_ISOLATED:
			case ICMP_UNREACH_HOST_PROHIB:
			case ICMP_UNREACH_TOSHOST:
				code = PRC_UNREACH_HOST;
				break;

			default:
				goto badcode;
		}
		goto deliver;

	case ICMP_TIMXCEED:
		if (code > 1)
			goto badcode;
		code += PRC_TIMXCEED_INTRANS;
		goto deliver;

	case ICMP_PARAMPROB:
		if (code > 1)
			goto badcode;
		code = PRC_PARAMPROB;
		goto deliver;

	case ICMP_SOURCEQUENCH:
		if (code)
			goto badcode;
		code = PRC_QUENCH;
		goto deliver;

	deliver:
		/*
		 * Problem with datagram; advise higher level routines.
		 */
		if (icmplen < ICMP_ADVLENMIN || icmplen < ICMP_ADVLEN(icp) ||
		    icp->icmp_ip.ip_hl < (sizeof(struct ip) >> 2)) {
			icmpstat.icps_badlen++;
			goto freeit;
		}
		if (IN_MULTICAST(icp->icmp_ip.ip_dst.s_addr))
			goto badcode;
		NTOHS(icp->icmp_ip.ip_len);
		icmpsrc.sin_addr = icp->icmp_ip.ip_dst;
		/*
		 * XXX if the packet contains [IPv4 AH TCP], we can't make a
		 * notification to TCP layer.
		 */
		ctlfunc = inetsw[ip_protox[icp->icmp_ip.ip_p]].pr_ctlinput;
		if (ctlfunc)
			(*ctlfunc)(code, sintosa(&icmpsrc), &icp->icmp_ip);
		break;

	badcode:
		icmpstat.icps_badcode++;
		break;

	case ICMP_ECHO:
		icp->icmp_type = ICMP_ECHOREPLY;
		goto reflect;

	case ICMP_TSTAMP:
		if (icmplen < ICMP_TSLEN) {
			icmpstat.icps_badlen++;
			break;
		}
		icp->icmp_type = ICMP_TSTAMPREPLY;
		icp->icmp_rtime = iptime();
		icp->icmp_ttime = icp->icmp_rtime;	/* bogus, do later! */
		goto reflect;
		
	case ICMP_MASKREQ:
		if (icmpmaskrepl == 0)
			break;
		/*
		 * We are not able to respond with all ones broadcast
		 * unless we receive it over a point-to-point interface.
		 */
		if (icmplen < ICMP_MASKLEN) {
			icmpstat.icps_badlen++;
			break;
		}
		if (ip->ip_dst.s_addr == INADDR_BROADCAST ||
		    in_nullhost(ip->ip_dst))
			icmpdst.sin_addr = ip->ip_src;
		else
			icmpdst.sin_addr = ip->ip_dst;
		ia = ifatoia(ifaof_ifpforaddr(sintosa(&icmpdst),
		    m->m_pkthdr.rcvif));
		if (ia == 0)
			break;
		icp->icmp_type = ICMP_MASKREPLY;
		icp->icmp_mask = ia->ia_sockmask.sin_addr.s_addr;
		if (in_nullhost(ip->ip_src)) {
			if (ia->ia_ifp->if_flags & IFF_BROADCAST)
				ip->ip_src = ia->ia_broadaddr.sin_addr;
			else if (ia->ia_ifp->if_flags & IFF_POINTOPOINT)
				ip->ip_src = ia->ia_dstaddr.sin_addr;
		}
reflect:
		icmpstat.icps_reflect++;
		icmpstat.icps_outhist[icp->icmp_type]++;
		icmp_reflect(m);
		return;

	case ICMP_REDIRECT:
		if (code > 3)
			goto badcode;
		if (icmplen < ICMP_ADVLENMIN || icmplen < ICMP_ADVLEN(icp) ||
		    icp->icmp_ip.ip_hl < (sizeof(struct ip) >> 2)) {
			icmpstat.icps_badlen++;
			break;
		}
		/*
		 * Short circuit routing redirects to force
		 * immediate change in the kernel's routing
		 * tables.  The message is also handed to anyone
		 * listening on a raw socket (e.g. the routing
		 * daemon for use in updating its tables).
		 */
		icmpgw.sin_addr = ip->ip_src;
		icmpdst.sin_addr = icp->icmp_gwaddr;
		icmpsrc.sin_addr = icp->icmp_ip.ip_dst;
		rtredirect(sintosa(&icmpsrc), sintosa(&icmpdst),
		    (struct sockaddr *)0, RTF_GATEWAY | RTF_HOST,
		    sintosa(&icmpgw), (struct rtentry **)0);
		pfctlinput(PRC_REDIRECT_HOST, sintosa(&icmpsrc));
		break;

	/*
	 * No kernel processing for the following;
	 * just fall through to send to raw listener.
	 */
	case ICMP_ECHOREPLY:
	case ICMP_ROUTERADVERT:
	case ICMP_ROUTERSOLICIT:
	case ICMP_TSTAMPREPLY:
	case ICMP_IREQREPLY:
	case ICMP_MASKREPLY:
	default:
		break;
	}

raw:
	rip_input(m, hlen, proto);
	return;

freeit:
	m_freem(m);
	return;
}

void
icmp_reflect(struct mbuf *m)
{
	struct ip *ip = mtod(m, struct ip *);
	struct in_ifaddr *ia;
	struct ifaddr *ifa;
	struct sockaddr_in *sin = 0;
	struct in_addr t;
	struct mbuf *opts = 0;
	int optlen = (ip->ip_hl << 2) - sizeof(struct ip);

	if (!in_canforward(ip->ip_src) &&
	    ((ip->ip_src.s_addr & IN_CLASSA_NET) !=
	     htonl(IN_LOOPBACKNET << IN_CLASSA_NSHIFT))) {
		m_freem(m);	/* Bad return address */
		goto done;	/* ip_output() will check for broadcast */
	}
	t = ip->ip_dst;
	ip->ip_dst = ip->ip_src;
	/*
	 * If the incoming packet was addressed directly to us, use
	 * dst as the src for the reply.  Otherwise (broadcast or
	 * anonymous), use an address which corresponds to the
	 * incoming interface, with a preference for the address which
	 * corresponds to the route to the destination of the ICMP.
	 */

	/* Look for packet addressed to us */
	INADDR_TO_IA(t, ia);

	/* look for packet sent to broadcast address */
	if (ia == NULL && (m->m_pkthdr.rcvif->if_flags & IFF_BROADCAST)) {
		for (ifa = m->m_pkthdr.rcvif->if_addrlist.tqh_first;  
		    ifa != NULL; ifa = ifa->ifa_list.tqe_next) {
			if (ifa->ifa_addr->sa_family != AF_INET)
				continue;
			if (in_hosteq(t,ifatoia(ifa)->ia_broadaddr.sin_addr)) {
				ia = ifatoia(ifa);
				break;
			}
		}
	}

	if (ia)
		sin = &ia->ia_addr;

	icmpdst.sin_addr = t;

	/* if the packet is addressed somewhere else, compute the
	   source address for packets routed back to the source, and
	   use that, if it's an address on the interface which
	   received the packet */
	if (sin == (struct sockaddr_in *)0) {
		struct sockaddr_in sin_dst;
		struct route icmproute;
		int errornum;

		sin_dst.sin_family = AF_INET;
		sin_dst.sin_len = sizeof(struct sockaddr_in);
		sin_dst.sin_addr = ip->ip_dst;
		memset(&icmproute, 0, sizeof(icmproute));
		errornum = 0;
		sin = in_selectsrc(&sin_dst, &icmproute, 0, NULL, &errornum);
		/* errornum is never used */
		if (icmproute.ro_rt)
			RTFREE(icmproute.ro_rt);
		/* check to make sure sin is a source address on rcvif */
		if (sin) {
			t = sin->sin_addr;
			sin = (struct sockaddr_in *)0;
			INADDR_TO_IA(t, ia);
			while (ia) {
				if (ia->ia_ifp == m->m_pkthdr.rcvif) {
					sin = &ia->ia_addr;
					break;
				}
				NEXT_IA_WITH_SAME_ADDR(ia);
			}
		}
	}

	/* if it was not addressed to us, but the route doesn't go out
	   the source interface, pick an address on the source
	   interface.  This can happen when routing is asymmetric, or
	   when the incoming packet was encapsulated */
	if (sin == (struct sockaddr_in *)0) {
		for (ifa = m->m_pkthdr.rcvif->if_addrlist.tqh_first;  
		     ifa != NULL; ifa = ifa->ifa_list.tqe_next) {
			if (ifa->ifa_addr->sa_family != AF_INET)
				continue;
			sin = &(ifatoia(ifa)->ia_addr);
			break;
		}
	}

	/*
	 * The following happens if the packet was not addressed to us,
	 * and was received on an interface with no IP address:
	 * We find the first AF_INET address on the first non-loopback
	 * interface.
	 */
	if (sin == (struct sockaddr_in *)0)
		for (ia = in_ifaddr.tqh_first; ia != NULL;
		    ia = ia->ia_list.tqe_next) {
			if (ia->ia_ifp->if_flags & IFF_LOOPBACK)
				continue;
			sin = &ia->ia_addr;
			break;
		}

	/*
	 * If we still didn't find an address, punt.  We could have an
	 * interface up (and receiving packets) with no address.
	 */
	if (sin == (struct sockaddr_in *)0) {
		m_freem(m);
		goto done;
	}

	ip->ip_src = sin->sin_addr;
	ip->ip_ttl = MAXTTL;

	if (optlen > 0) {
		u_char *cp;
		int opt, cnt;
		u_int len;

		/*
		 * Retrieve any source routing from the incoming packet;
		 * add on any record-route or timestamp options.
		 */
		cp = (u_char *) (ip + 1);
		if ((opts = ip_srcroute()) == 0 &&
		    (opts = m_gethdr(M_DONTWAIT, MT_HEADER))) {
			opts->m_len = sizeof(struct in_addr);
			*mtod(opts, struct in_addr *) = zeroin_addr;
		}
		if (opts) {
		    for (cnt = optlen; cnt > 0; cnt -= len, cp += len) {
			    opt = cp[IPOPT_OPTVAL];
			    if (opt == IPOPT_EOL)
				    break;
			    if (opt == IPOPT_NOP)
				    len = 1;
			    else {
				    if (cnt < IPOPT_OLEN + sizeof(*cp))
					    break;
				    len = cp[IPOPT_OLEN];
				    if (len < IPOPT_OLEN + sizeof(*cp) ||
				        len > cnt)
					    break;
			    }
			    /*
			     * Should check for overflow, but it "can't happen"
			     */
			    if (opt == IPOPT_RR || opt == IPOPT_TS || 
				opt == IPOPT_SECURITY) {
				    bcopy((caddr_t)cp,
					mtod(opts, caddr_t) + opts->m_len, len);
				    opts->m_len += len;
			    }
		    }
		    /* Terminate & pad, if necessary */
		    if ((cnt = opts->m_len % 4) != 0) {
			    for (; cnt < 4; cnt++) {
				    *(mtod(opts, caddr_t) + opts->m_len) =
					IPOPT_EOL;
				    opts->m_len++;
			    }
		    }
		}
		/*
		 * Now strip out original options by copying rest of first
		 * mbuf's data back, and adjust the IP length.
		 */
		ip->ip_len -= optlen;
		ip->ip_hl = sizeof(struct ip) >> 2;
		m->m_len -= optlen;
		if (m->m_flags & M_PKTHDR)
			m->m_pkthdr.len -= optlen;
		optlen += sizeof(struct ip);
		bcopy((caddr_t)ip + optlen, (caddr_t)(ip + 1),
			 (unsigned)(m->m_len - sizeof(struct ip)));
	}
	m->m_flags &= ~(M_BCAST|M_MCAST);
	icmp_send(m, opts);
done:
	if (opts)
		(void)m_free(opts);
}

void
icmp_send(struct mbuf *m, struct mbuf *opts)
{
	struct ip *ip = mtod(m, struct ip *);
	int hlen;
	struct icmp *icp;

	hlen = ip->ip_hl << 2;
	m->m_data += hlen;
	m->m_len -= hlen;
	icp = mtod(m, struct icmp *);
	icp->icmp_cksum = 0;
	icp->icmp_cksum = in_cksum(m, ip->ip_len - hlen);
	m->m_data -= hlen;
	m->m_len += hlen;
	(void) ip_output(m, opts, NULL, 0, NULL);
}

n_time
iptime(void)
{
	struct timeval atv;
	u_long t;

	microtime(&atv);
	t = (atv.tv_sec % (24*60*60)) * 1000 + atv.tv_usec / 1000;
	return (htonl(t));
}

int
icmp_sysctl(int *name, u_int namelen, void *oldp, size_t *oldlenp, void *newp, size_t newlen)
{
	int arg, error;

	if (namelen != 1)
		return (ENOTDIR);

	switch (name[0])
	{
	case ICMPCTL_MASKREPL:
		error = sysctl_int(oldp, oldlenp, newp, newlen, &icmpmaskrepl);
		break;
	case ICMPCTL_RETURNDATABYTES:
		arg = icmpreturndatabytes;
		error = sysctl_int(oldp, oldlenp, newp, newlen, &arg);
		if (error)
			break;
		if ((arg >= 8) || (arg <= 512))
			icmpreturndatabytes = arg;
		else
			error = EINVAL;
		break;
	case ICMPCTL_ERRPPSLIMIT:
		error = sysctl_int(oldp, oldlenp, newp, newlen, &icmperrppslim);
		break;
	case ICMPCTL_STATS:
		error = sysctl_rdstruct(oldp, oldlenp, newp, &icmpstat,
		    sizeof(icmpstat));
		break;
	default:
		error = ENOPROTOOPT;
		break;
	}
	return error;
}

void
icmp_mtudisc(struct icmp *icp, struct in_addr faddr)
{
	struct icmp_mtudisc_callback *mc;
	struct sockaddr *dst = sintosa(&icmpsrc);
	struct rtentry *rt;
	u_long mtu = ntohs(icp->icmp_nextmtu);  /* Why a long?  IPv6 */
	int    error;

	rt = rtalloc1(dst, 1);
	if (rt == 0)
		return;
    
	/* If we didn't get a host route, allocate one */
    
	if ((rt->rt_flags & RTF_HOST) == 0) {
		struct rtentry *nrt;

		error = rtrequest((int) RTM_ADD, dst, 
		    (struct sockaddr *) rt->rt_gateway,
		    (struct sockaddr *) 0, 
		    RTF_GATEWAY | RTF_HOST | RTF_DYNAMIC, &nrt);
		if (error) {
			rtfree(rt);
			rtfree(nrt);
			return;
		}
		nrt->rt_rmx = rt->rt_rmx;
		rtfree(rt);
		rt = nrt;
	}
	error = rt_timer_add(rt, icmp_mtudisc_timeout, ip_mtudisc_timeout_q);
	if (error) {
		rtfree(rt);
		return;
	}

	if (mtu == 0) {
		int i = 0;

		mtu = icp->icmp_ip.ip_len; /* NTOHS happened in deliver: */
		/* Some 4.2BSD-based routers incorrectly adjust the ip_len */
		if (mtu > rt->rt_rmx.rmx_mtu && rt->rt_rmx.rmx_mtu != 0)
			mtu -= (icp->icmp_ip.ip_hl << 2);

		/* If we still can't guess a value, try the route */

		if (mtu == 0) {
			mtu = rt->rt_rmx.rmx_mtu;

			/* If no route mtu, default to the interface mtu */

			if (mtu == 0)
				mtu = rt->rt_ifp->if_mtu;
		}

		for (i = 0; i < sizeof(mtu_table) / sizeof(mtu_table[0]); i++)
			if (mtu > mtu_table[i]) {
				mtu = mtu_table[i];
				break;
			}
	}

	/*
	 * XXX:   RTV_MTU is overloaded, since the admin can set it
	 *	  to turn off PMTU for a route, and the kernel can
	 *	  set it to indicate a serious problem with PMTU
	 *	  on a route.  We should be using a separate flag
	 *	  for the kernel to indicate this.
	 */

	if ((rt->rt_rmx.rmx_locks & RTV_MTU) == 0) {
		if (mtu < 296 || mtu > rt->rt_ifp->if_mtu)
			rt->rt_rmx.rmx_locks |= RTV_MTU;
		else if (rt->rt_rmx.rmx_mtu > mtu || 
			 rt->rt_rmx.rmx_mtu == 0) {
					rt->rt_rmx.rmx_mtu = mtu;
		}
	}

	if (rt)
		rtfree(rt);

	/*
	 * Notify protocols that the MTU for this destination
	 * has changed.
	 */
	for (mc = LIST_FIRST(&icmp_mtudisc_callbacks); mc != NULL;
	     mc = LIST_NEXT(mc, mc_list))
		(*mc->mc_func)(faddr);
}

int
ip_next_mtu(int mtu, int dir)
{
	int i;

	for (i = 0; i < (sizeof mtutab) / (sizeof mtutab[0]); i++) {
		if (mtu >= mtutab[i])
			break;
	}

	if (dir < 0) {
		if (i == 0) {
			return 0;
		} else {
			return mtutab[i - 1];
		}
	} else {
		if (mtutab[i] == 0) {
			return 0;
		} else if(mtu > mtutab[i]) {
			return mtutab[i];
		} else {
			return mtutab[i + 1];
		}
	}
}

static void
icmp_mtudisc_timeout(struct rtentry *rt, struct rttimer *r)
{
	if ((rt->rt_flags & (RTF_DYNAMIC | RTF_HOST)) == 
	    (RTF_DYNAMIC | RTF_HOST)) {
		rtrequest((int) RTM_DELETE, (struct sockaddr *)rt_key(rt),
		    rt->rt_gateway, rt_mask(rt), rt->rt_flags, 0);
	} else {
		if ((rt->rt_rmx.rmx_locks & RTV_MTU) == 0) {
			rt->rt_rmx.rmx_mtu = 0;
		}
	}
}

static int
icmp_ratelimit(const struct in_addr *dst, const int type, const int code)
{
	return 0;
}
