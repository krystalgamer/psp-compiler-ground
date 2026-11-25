/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"
#include <stdarg.h>

#define ROUNDUP(a) ((a) > 0 ? (1 + (((a) - 1) | (sizeof(long) - 1))) : sizeof(long))
#define ADVANCE(x, n) (x += ROUNDUP((n)->sa_len))
#define Bcopy(a, b, n) bcopy(((caddr_t)(a)), ((caddr_t)(b)), (unsigned)(n))
#define R_Malloc(p, t, n) (p = (t) sceNetMallocInternal((unsigned int)(n)))
#define Free(p) sceNetFreeInternal((caddr_t)p)

#define dst info.rti_info[RTAX_DST]
#define gate info.rti_info[RTAX_GATEWAY]
#define netmask info.rti_info[RTAX_NETMASK]
#define genmask info.rti_info[RTAX_GENMASK]
#define ifpaddr info.rti_info[RTAX_IFP]
#define ifaaddr info.rti_info[RTAX_IFA]
#define brdaddr info.rti_info[RTAX_BRD]

static struct mbuf *rt_msg1(int, struct rt_addrinfo *, caddr_t, int);
static int rt_msg2(int, struct rt_addrinfo *, caddr_t, struct walkarg *, int *);
static void rt_xaddrs(caddr_t, caddr_t, struct rt_addrinfo *);
static void rt_setmetrics(u_long, struct rt_metrics *, struct rt_metrics *);


int
route_usrreq(struct socket *so, int req, struct mbuf *m, struct mbuf *nam, struct mbuf *control)
{
	int error = 0;
	struct rawcb *rp = sotorawcb(so);
	int s;

	if (req == PRU_ATTACH) {
		rp = sceNetMallocInternal(sizeof(*rp));
		if ((so->so_pcb = rp) != NULL)
			memset(so->so_pcb, 0, sizeof(*rp));
	}
	if (req == PRU_DETACH && rp) {
		route_cb.any_count--;
		switch (rp->rcb_proto.sp_protocol) {
		case AF_INET:
			route_cb.ip_count--;
			break;
		case AF_IPX:
			route_cb.ipx_count--;
			break;
		case AF_NS:
			route_cb.ns_count--;
			break;
		case AF_ISO:
			route_cb.iso_count--;
			break;
		}
	}
	s = _sce_pspnet_spllock();
	if (req == PRU_ATTACH)
		error = raw_attach(so, (int)(long)nam);
	else
		error = raw_usrreq(so, req, m, nam, control);

	rp = sotorawcb(so);
	if (req == PRU_ATTACH && rp) {
		if (error) {
			sceNetFreeInternal(rp);
			_sce_pspnet_splunlock(s);
			return (error);
		}
		route_cb.any_count++;
		switch (rp->rcb_proto.sp_protocol) {
		case AF_INET:
			route_cb.ip_count++;
			break;
		case AF_IPX:
			route_cb.ipx_count++;
			break;
		case AF_NS:
			route_cb.ns_count++;
			break;
		case AF_ISO:
			route_cb.iso_count++;
			break;
		}
		rp->rcb_laddr = &route_src;
		rp->rcb_faddr = &route_dst;
		soisconnected(so);
		so->so_options |= SO_USELOOPBACK;
	}
	_sce_pspnet_splunlock(s);
	return (error);
}

int
route_output(struct mbuf *m, ...)
{
	struct rt_msghdr *rtm = 0;
	struct radix_node *rn = 0;
	struct rtentry *rt = 0;
	struct rtentry *saved_nrt = 0;
	struct radix_node_head *rnh;
	struct rt_addrinfo info;
	int len, error = 0;
	struct ifnet *ifp = 0;
	struct ifaddr *ifa = 0;
	struct socket *so;
	va_list ap;

	va_start(ap, m);
	so = va_arg(ap, struct socket *);
	va_end(ap);

	memset(&info, 0, sizeof(info));
#define senderr(e) do { error = e; goto flush; } while (0)
	if (m == 0 || ((m->m_len < sizeof(int32_t)) &&
	    (m = m_pullup(m, sizeof(int32_t))) == 0))
		return (ENOBUFS);
	len = m->m_pkthdr.len;
	if (len < sizeof(*rtm) ||
	    len != mtod(m, struct rt_msghdr *)->rtm_msglen) {
		dst = 0;
		senderr(EINVAL);
	}
	R_Malloc(rtm, struct rt_msghdr *, len);
	if (rtm == 0) {
		dst = 0;
		senderr(ENOBUFS);
	}
	m_copydata(m, 0, len, (caddr_t)rtm);
	if (rtm->rtm_version != RTM_VERSION) {
		dst = 0;
		senderr(EPROTONOSUPPORT);
	}
	rtm->rtm_pid = sceKernelGetThreadId();
	info.rti_addrs = rtm->rtm_addrs;
	rt_xaddrs((caddr_t)(rtm + 1), len + (caddr_t)rtm, &info);
	if (dst == 0 || (dst->sa_family >= AF_MAX))
		senderr(EINVAL);
	if (gate != 0 && (gate->sa_family >= AF_MAX))
		senderr(EINVAL);
	if (genmask) {
		struct radix_node *t;
		t = rn_addmask((caddr_t)genmask, 0, 1);
		if (t && bcmp(genmask, t->rn_key, *(u_char *)genmask) == 0)
			genmask = (struct sockaddr *)(t->rn_key);
		else
			senderr(ENOBUFS);
	}
	switch (rtm->rtm_type) {

	case RTM_ADD:
		if (gate == 0)
			senderr(EINVAL);
		error = rtrequest(RTM_ADD, dst, gate, netmask,
		    rtm->rtm_flags, &saved_nrt);
		if (error == 0 && saved_nrt) {
			rt_setmetrics(rtm->rtm_inits,
			    &rtm->rtm_rmx, &saved_nrt->rt_rmx);
			saved_nrt->rt_refcnt--;
			saved_nrt->rt_genmask = genmask;
		}
		break;

	case RTM_DELETE:
		error = rtrequest(RTM_DELETE, dst, gate, netmask,
		    rtm->rtm_flags, &saved_nrt);
		if (error == 0) {
			(rt = saved_nrt)->rt_refcnt++;
			goto report;
		}
		break;

	case RTM_GET:
	case RTM_CHANGE:
	case RTM_LOCK:
		if ((rnh = rt_tables[dst->sa_family]) == 0) {
			senderr(EAFNOSUPPORT);
		}
		rn = rnh->rnh_lookup(dst, netmask, rnh);
		if (rn == NULL || (rn->rn_flags & RNF_ROOT) != 0) {
			senderr(ESRCH);
		}
		rt = (struct rtentry *)rn;
		rt->rt_refcnt++;
		switch (rtm->rtm_type) {

		case RTM_GET:
		report:
			dst = rt_key(rt);
			gate = rt->rt_gateway;
			netmask = rt_mask(rt);
			genmask = rt->rt_genmask;
			if (rtm->rtm_addrs & (RTA_IFP | RTA_IFA)) {
				if ((ifp = rt->rt_ifp) != NULL) {
					ifpaddr = ifp->if_addrlist.tqh_first->ifa_addr;
					ifaaddr = rt->rt_ifa->ifa_addr;
					if (ifp->if_flags & IFF_POINTOPOINT)
						brdaddr = rt->rt_ifa->ifa_dstaddr;
					else
						brdaddr = 0;
					rtm->rtm_index = ifp->if_index;
				} else {
					ifpaddr = 0;
					ifaaddr = 0;
				}
			}
			(void)rt_msg2(rtm->rtm_type, &info, (caddr_t)0,
			    (struct walkarg *)0, &len);
			if (len > rtm->rtm_msglen) {
				struct rt_msghdr *new_rtm;
				R_Malloc(new_rtm, struct rt_msghdr *, len);
				if (new_rtm == 0)
					senderr(ENOBUFS);
				Bcopy(rtm, new_rtm, rtm->rtm_msglen);
				Free(rtm); rtm = new_rtm;
			}
			(void)rt_msg2(rtm->rtm_type, &info, (caddr_t)rtm,
			    (struct walkarg *)0, 0);
			rtm->rtm_flags = rt->rt_flags;
			rtm->rtm_rmx = rt->rt_rmx;
			rtm->rtm_addrs = info.rti_addrs;
			break;

		case RTM_CHANGE:
			if (gate && rt_setgate(rt, rt_key(rt), gate))
				senderr(EDQUOT);
			if (ifpaddr && (ifa = ifa_ifwithnet(ifpaddr)) &&
			    (ifp = ifa->ifa_ifp) && (ifaaddr || gate))
				ifa = ifaof_ifpforaddr(ifaaddr ? ifaaddr : gate,
				    ifp);
			else if ((ifaaddr && (ifa = ifa_ifwithaddr(ifaaddr))) ||
			    (gate && (ifa = ifa_ifwithroute(rt->rt_flags,
			    rt_key(rt), gate))))
				ifp = ifa->ifa_ifp;
			if (ifa) {
				struct ifaddr *oifa = rt->rt_ifa;
				if (oifa != ifa) {
					if (oifa && oifa->ifa_rtrequest)
						oifa->ifa_rtrequest(RTM_DELETE, rt, gate);
					IFAFREE(rt->rt_ifa);
					rt->rt_ifa = ifa;
					ifa->ifa_refcnt++;
					rt->rt_ifp = ifp;
				}
			}
			rt_setmetrics(rtm->rtm_inits, &rtm->rtm_rmx,
			    &rt->rt_rmx);
			if (rt->rt_ifa && rt->rt_ifa->ifa_rtrequest)
				rt->rt_ifa->ifa_rtrequest(RTM_ADD, rt, gate);
			if (genmask)
				rt->rt_genmask = genmask;
		case RTM_LOCK:
			rt->rt_rmx.rmx_locks &= ~(rtm->rtm_inits);
			rt->rt_rmx.rmx_locks |=
			    (rtm->rtm_inits & rtm->rtm_rmx.rmx_locks);
			break;
		}
		break;

	default:
		senderr(EOPNOTSUPP);
	}

flush:
	if (rtm) {
		if (error)
			rtm->rtm_errno = error;
		else
			rtm->rtm_flags |= RTF_DONE;
	}
	if (rt)
		rtfree(rt);
    {
	struct rawcb *rp = 0;

	if ((so->so_options & SO_USELOOPBACK) == 0) {
		if (route_cb.any_count <= 1) {
			if (rtm)
				Free(rtm);
			m_freem(m);
			return (error);
		}
		rp = sotorawcb(so);
	}
	if (rtm) {
		m_copyback(m, 0, rtm->rtm_msglen, (caddr_t)rtm);
		Free(rtm);
	}
	if (rp)
		rp->rcb_proto.sp_family = 0;
	if (dst)
		route_proto.sp_protocol = dst->sa_family;
	raw_input(m, &route_proto, &route_src, &route_dst);
	if (rp)
		rp->rcb_proto.sp_family = PF_ROUTE;
    }
	return (error);
}

static void
rt_setmetrics(u_long which, struct rt_metrics *in, struct rt_metrics *out)
{
#define metric(f, e) if (which & (f)) out->e = in->e;
	metric(RTV_RPIPE, rmx_recvpipe);
	metric(RTV_SPIPE, rmx_sendpipe);
	metric(RTV_SSTHRESH, rmx_ssthresh);
	metric(RTV_RTT, rmx_rtt);
	metric(RTV_RTTVAR, rmx_rttvar);
	metric(RTV_HOPCOUNT, rmx_hopcount);
	metric(RTV_MTU, rmx_mtu);
	metric(RTV_EXPIRE, rmx_expire);
#undef metric
}

static void
rt_xaddrs(caddr_t cp, caddr_t cplim, struct rt_addrinfo *rtinfo)
{
	struct sockaddr *sa;
	int i;

	memset(rtinfo->rti_info, 0, sizeof(rtinfo->rti_info));
	for (i = 0; (i < RTAX_MAX) && (cp < cplim); i++) {
		if ((rtinfo->rti_addrs & (1 << i)) == 0)
			continue;
		rtinfo->rti_info[i] = sa = (struct sockaddr *)cp;
		ADVANCE(cp, sa);
	}
}

static int
rt_msg2(int type, struct rt_addrinfo *rtinfo, caddr_t cp, struct walkarg *w, int *lenp)
{
	int i;
	int len, dlen, second_time = 0;
	caddr_t cp0;

	rtinfo->rti_addrs = 0;
again:
	switch (type) {

	case RTM_DELADDR:
	case RTM_NEWADDR:
		len = sizeof(struct ifa_msghdr);
		break;

	case RTM_IFINFO:
		len = sizeof(struct if_msghdr);
		break;

	default:
		len = sizeof(struct rt_msghdr);
	}
	if ((cp0 = cp) != NULL)
		cp += len;
	for (i = 0; i < RTAX_MAX; i++) {
		struct sockaddr *sa;

		if ((sa = rtinfo->rti_info[i]) == 0)
			continue;
		rtinfo->rti_addrs |= (1 << i);
		dlen = ROUNDUP(sa->sa_len);
		if (cp) {
			bcopy(sa, cp, (unsigned)dlen);
			cp += dlen;
		}
		len += dlen;
	}
	if (cp == 0 && w != NULL && !second_time) {
		struct walkarg *rw = w;

		rw->w_needed += len;
		if (rw->w_needed <= 0 && rw->w_where) {
			if (rw->w_tmemsize < len) {
				if (rw->w_tmem)
					Free(rw->w_tmem);
				rw->w_tmem = (caddr_t)sceNetMallocInternal(len);
				if (rw->w_tmem)
					rw->w_tmemsize = len;
			}
			if (rw->w_tmem) {
				cp = rw->w_tmem;
				second_time = 1;
				goto again;
			} else {
				rw->w_tmemneeded = len;
				return (ENOBUFS);
			}
		}
	}
	if (cp) {
		struct rt_msghdr *rtm = (struct rt_msghdr *)cp0;

		rtm->rtm_version = RTM_VERSION;
		rtm->rtm_type = type;
		rtm->rtm_msglen = len;
	}
	if (lenp)
		*lenp = len;
	return (0);
}

void
rt_newaddrmsg(int cmd, struct ifaddr *ifa, int error, struct rtentry *rt)
{
	struct rt_addrinfo info;
	struct sockaddr *sa = NULL;
	int pass;
	struct mbuf *m = NULL;
	struct ifnet *ifp = ifa->ifa_ifp;

	if (route_cb.any_count == 0)
		return;
	for (pass = 1; pass < 3; pass++) {
		memset(&info, 0, sizeof(info));
		if ((cmd == RTM_ADD && pass == 1) ||
		    (cmd == RTM_DELETE && pass == 2)) {
			struct ifa_msghdr ifam;
			int ncmd = cmd == RTM_ADD ? RTM_NEWADDR : RTM_DELADDR;

			ifaaddr = sa = ifa->ifa_addr;
			ifpaddr = ifp->if_addrlist.tqh_first->ifa_addr;
			netmask = ifa->ifa_netmask;
			brdaddr = ifa->ifa_dstaddr;
			memset(&ifam, 0, sizeof(ifam));
			ifam.ifam_index = ifp->if_index;
			ifam.ifam_metric = ifa->ifa_metric;
			ifam.ifam_flags = ifa->ifa_flags;
			m = rt_msg1(ncmd, &info, (caddr_t)&ifam, sizeof(ifam));
			if (m == NULL)
				continue;
			mtod(m, struct ifa_msghdr *)->ifam_addrs =
			    info.rti_addrs;
		}
		if ((cmd == RTM_ADD && pass == 2) ||
		    (cmd == RTM_DELETE && pass == 1)) {
			struct rt_msghdr rtm;

			if (rt == 0)
				continue;
			netmask = rt_mask(rt);
			dst = sa = rt_key(rt);
			gate = rt->rt_gateway;
			memset(&rtm, 0, sizeof(rtm));
			rtm.rtm_index = ifp->if_index;
			rtm.rtm_flags |= rt->rt_flags;
			rtm.rtm_errno = error;
			m = rt_msg1(cmd, &info, (caddr_t)&rtm, sizeof(rtm));
			if (m == NULL)
				continue;
			mtod(m, struct rt_msghdr *)->rtm_addrs = info.rti_addrs;
		}
		route_proto.sp_protocol = sa ? sa->sa_family : 0;
		raw_input(m, &route_proto, &route_src, &route_dst);
	}
}

__attribute__((noinline)) void
rt_missmsg(int type, struct rt_addrinfo *rtinfo, int flags, int error)
{
	struct rt_msghdr rtm;
	struct mbuf *m;
	struct sockaddr *sa = rtinfo->rti_info[RTAX_DST];

	if (route_cb.any_count == 0)
		return;
	memset(&rtm, 0, sizeof(rtm));
	rtm.rtm_flags = RTF_DONE | flags;
	rtm.rtm_errno = error;
	m = rt_msg1(type, rtinfo, (caddr_t)&rtm, sizeof(rtm));
	if (m == 0)
		return;
	mtod(m, struct rt_msghdr *)->rtm_addrs = rtinfo->rti_addrs;
	route_proto.sp_protocol = sa ? sa->sa_family : 0;
	raw_input(m, &route_proto, &route_src, &route_dst);
}

__attribute__((noinline)) void
rt_ifmsg(struct ifnet *ifp)
{
	struct if_msghdr ifm;
	struct mbuf *m;
	struct rt_addrinfo info;

	if (route_cb.any_count == 0)
		return;
	memset(&info, 0, sizeof(info));
	memset(&ifm, 0, sizeof(ifm));
	ifm.ifm_index = ifp->if_index;
	ifm.ifm_flags = ifp->if_flags;
	ifm.ifm_data = ifp->if_data;
	ifm.ifm_addrs = 0;
	m = rt_msg1(RTM_IFINFO, &info, (caddr_t)&ifm, sizeof(ifm));
	if (m == 0)
		return;
	route_proto.sp_protocol = 0;
	raw_input(m, &route_proto, &route_src, &route_dst);
}

__attribute__((noinline)) void
rt_ifannouncemsg(struct ifnet *ifp, int what)
{
	struct if_announcemsghdr ifan;
	struct rt_addrinfo info;
	struct mbuf *m;

	if (route_cb.any_count == 0)
		return;
	memset(&info, 0, sizeof(info));
	memset(&ifan, 0, sizeof(ifan));
	ifan.ifan_index = ifp->if_index;
	strcpy(ifan.ifan_name, ifp->if_xname);
	ifan.ifan_what = what;
	m = rt_msg1(RTM_IFANNOUNCE, &info, (caddr_t)&ifan, sizeof(ifan));
	if (m == NULL)
		return;
	route_proto.sp_protocol = 0;
	raw_input(m, &route_proto, &route_src, &route_dst);
}

static __attribute__((noinline)) struct mbuf *
rt_msg1(int type, struct rt_addrinfo *rtinfo, caddr_t data, int datalen)
{
	struct rt_msghdr *rtm;
	struct mbuf *m;
	int i;
	struct sockaddr *sa;
	int len, dlen;

	m = m_gethdr(M_DONTWAIT, MT_DATA);
	if (m == 0)
		return (m);
	switch (type) {
	case RTM_DELADDR:
	case RTM_NEWADDR:
		len = sizeof(struct ifa_msghdr);
		break;
	case RTM_IFINFO:
		len = sizeof(struct if_msghdr);
		break;
	case RTM_IFANNOUNCE:
		len = sizeof(struct if_announcemsghdr);
		break;
	default:
		len = sizeof(struct rt_msghdr);
	}
	m->m_pkthdr.len = m->m_len = len;
	m->m_pkthdr.rcvif = 0;
	m_copyback(m, 0, datalen, data);
	rtm = mtod(m, struct rt_msghdr *);
	for (i = 0; i < RTAX_MAX; i++) {
		if ((sa = rtinfo->rti_info[i]) == NULL)
			continue;
		rtinfo->rti_addrs |= (1 << i);
		dlen = ROUNDUP(sa->sa_len);
		m_copyback(m, len, dlen, (caddr_t)sa);
		len += dlen;
	}
	rtm->rtm_msglen = len;
	rtm->rtm_version = RTM_VERSION;
	rtm->rtm_type = type;
	return (m);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/rtsock", func_0000E678);

static __attribute__((noinline, used)) int
sysctl_dumpentry(struct radix_node *rn, void *v)
{
	struct walkarg *w = v;
	struct rtentry *rt = (struct rtentry *)rn;
	int error = 0, size;
	struct rt_addrinfo info;

	if (w->w_op == NET_RT_FLAGS && !(rt->rt_flags & w->w_arg))
		return 0;
	memset(&info, 0, sizeof(info));
	dst = rt_key(rt);
	gate = rt->rt_gateway;
	netmask = rt_mask(rt);
	genmask = rt->rt_genmask;
	if (rt->rt_ifp) {
		ifpaddr = rt->rt_ifp->if_addrlist.tqh_first->ifa_addr;
		ifaaddr = rt->rt_ifa->ifa_addr;
		if (rt->rt_ifp->if_flags & IFF_POINTOPOINT)
			brdaddr = rt->rt_ifa->ifa_dstaddr;
	}
	if ((error = rt_msg2(RTM_GET, &info, 0, w, &size)))
		return (error);
	if (w->w_where && w->w_tmem && w->w_needed <= 0) {
		struct rt_msghdr *rtm = (struct rt_msghdr *)w->w_tmem;

		rtm->rtm_flags = rt->rt_flags;
		rtm->rtm_use = rt->rt_use;
		rtm->rtm_rmx = rt->rt_rmx;
		rtm->rtm_index = rt->rt_ifp->if_index;
		rtm->rtm_errno = rtm->rtm_pid = rtm->rtm_seq = 0;
		rtm->rtm_addrs = info.rti_addrs;
		bcopy(rtm, w->w_where, size);
		w->w_where += size;
	}
	return (error);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/rtsock", func_0000EA48);

int sysctl_rtable(int *, u_int, void *, size_t *, void *, size_t);

/*
 * routesw/routedomain live in the asm .data (D_0002E4D8/D_0002E50C); this copy only
 * keeps sysctl_rtable referenced and goes to a section the linker script discards.
 */
#define DISCARD __attribute__((section(".discard")))
extern struct domain routedomain;

DISCARD struct protosw routesw[] = {
{ SOCK_RAW,	&routedomain,	0,		PR_ATOMIC | PR_ADDR,
  raw_input,	route_output,	raw_ctlinput,	0,
  route_usrreq,
  raw_init,	0,		0,		0,
  sysctl_rtable,
}
};

const char D_0002DAAC[] = "route";

DISCARD struct domain routedomain =
    { PF_ROUTE, (char *)D_0002DAAC, route_init, 0, 0,
      routesw, &routesw[sizeof(routesw) / sizeof(routesw[0])] };
