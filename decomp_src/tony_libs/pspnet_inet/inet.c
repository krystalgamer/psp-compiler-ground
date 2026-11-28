/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

int func_00001E30(void);
int func_00001D50(void);
void func_00001D78(void);
void func_00001FA4(void);
int func_0000963C(void);
void func_000096D0(void);
int func_0000999C(void);
void func_000099D4(void);
void func_00001584(void);
void ipintr(void);
void arpintr(void);
void arp_ifinit(struct ifnet *ifp, struct ifaddr *ifa);
void loopattach(int n);
void soinit(void);
#define SOCK_DGRAM 2
int _sce_pspnet_start_of_inet_module_in_ifhandle_ether(void (*f)(struct ifnet *, struct ifaddr *));
void _sce_pspnet_stop_of_inet_module_in_ifhandle_ether(void);
int _sce_pspnet_start_of_inet_module_in_netintr(void (*ip)(void), void (*arp)(void));
void _sce_pspnet_stop_of_inet_module_in_netintr(void);
int sceNetInetTerm(void);
int sceNetInetSocket(int domain, int type, int protocol);
int sceNetInetClose(int s);
int sceNetInetGetErrno(void);
int sceNetInet_lib_AEE60F84(int s, u_long com, caddr_t data);
int sceNetInet_lib_4F68DB0E(const char *name, const struct in_addr *addr, const struct in_addr *broadaddr, const struct in_addr *mask);
int sceNetInet_lib_6A046357(const char *name);
int func_00001598(int cmd, struct sockaddr *dst, struct sockaddr *gw, struct sockaddr *mask, int flags);
#define D_0002EB40_ D_0002EB40
extern int D_0002EB40, D_0002EB44;
extern struct in_addr D_0002EB48, D_0002EB4C;
struct ifaliasreq {
	char ifra_name[16];
	struct sockaddr ifra_addr;
	struct sockaddr ifra_broadaddr;
	struct sockaddr ifra_mask;
};
struct tcpcbstat {
	struct tcpcbstat *next;
	u_int txqueue;
	u_int rxqueue;
	struct in_addr laddr;
	struct in_addr faddr;
	u_short lport;
	u_short fport;
	short state;
};
struct udpcbstat {
	struct udpcbstat *next;
	u_int txqueue;
	u_int rxqueue;
	struct in_addr laddr;
	struct in_addr faddr;
	u_short lport;
	u_short fport;
};
extern struct inpcbtable udbtable;
int sceNetInetSend(int s, const void *buf, size_t len, int flags);
int sceNetInetRecv(int s, void *buf, size_t len, int flags);
int sceNetInetShutdown(int s, int how);
int sceNetInet_lib_B3FF98EB(int *name, u_int namelen, void *oldp, size_t *oldlenp, void *newp, size_t newlen);
#define sysctl sceNetInet_lib_B3FF98EB
int _sce_pspnet_get_ifindex(const char *name);
struct ifnet *_sce_pspnet_ifplookup_index(int index);
int func_00001744(char **bufp, size_t *lenp);
int func_0000188C(int s, struct rt_msghdr *rtm, int cmd, struct sockaddr *dst, struct sockaddr *gate, struct sockaddr *mask, int flags, int seq);
#define ROUNDUP(a) ((a) > 0 ? (1 + (((a) - 1) | (sizeof(long) - 1))) : sizeof(long))
#define ADVANCE(x, n) (x += ROUNDUP((n)->sa_len))
#define rtm_seq0 D_0002EB40
#define rtm_seq1 D_0002EB44
#define CTL_NET 4
#define RTF_GATEWAY_ 0x2
#define RTA_DST 0x1
#define RTA_GATEWAY 0x2
#define RTA_NETMASK 0x4
#define RTA_GENMASK 0x8
#ifndef IFT_ETHER
#define IFT_ETHER 0x6
#endif
#ifndef AF_LINK
#define AF_LINK 18
#endif
#ifndef RTV_EXPIRE
#define RTV_EXPIRE 0x4
#endif
struct rtentstat {
	struct rtentstat *next;
	u_int flags;
	struct in_addr dst;
	struct in_addr gateway;
	struct in_addr mask;
	char ifname[16];
};
struct arpentstat {
	struct arpentstat *next;
	u_int unk4;
	struct in_addr addr;
	u_char hwaddr[6];
	char ifname[16];
};
int sceNetInet_lib_3D905F34(int *size, struct rtentstat *buf);
struct rtmsgbuf {
	struct rt_msghdr m_rtm;
	char m_space[512];
};
#define SCE_ERR_SOCKET 0x80410280
#define SCE_ERR_ADDRNOTAVAIL 0x80410183

__attribute__((noinline)) int
sceNetInetInit(void)
{
	int ret;
	struct in_addr addr, mask;

	if ((ret = func_00001E30()) < 0)
		goto fail;
	soinit();
	if ((ret = func_00001D50()) < 0)
		goto fail;
	if ((ret = _sce_pspnet_start_of_inet_module_in_ifhandle_ether(arp_ifinit)) < 0)
		goto fail;
	if ((ret = func_0000963C()) < 0)
		goto fail;
	if ((ret = func_0000999C()) < 0)
		goto fail;
	if ((ret = _sce_pspnet_start_of_inet_module_in_netintr(ipintr, arpintr)) < 0)
		goto fail;
	func_00001584();
	loopattach(1);
	addr.s_addr = htonl(0x7f000001);
	mask.s_addr = htonl(0xff000000);
	if ((ret = sceNetInet_lib_4F68DB0E("lo0", &addr, NULL, &mask)) < 0)
		goto fail;
	return 0;
fail:
	sceNetInetTerm();
	return ret;
}

__attribute__((noinline)) int
sceNetInetTerm(void)
{
	_sce_pspnet_stop_of_inet_module_in_netintr();
	func_000099D4();
	func_000096D0();
	_sce_pspnet_stop_of_inet_module_in_ifhandle_ether();
	func_00001D78();
	func_00001FA4();
	return 0;
}

__attribute__((noinline)) int
sceNetInetGetErrno(void)
{
	return _sce_pspnet_get_thread_errno();
}

__attribute__((noinline)) int
sceNetInet_lib_5155EC8A(const char *name, struct in_addr *addr, struct in_addr *broadaddr, struct in_addr *mask)
{
	struct ifreq ifr;
	int s, ret;

	ret = 0;
	s = sceNetInetSocket(AF_INET, SOCK_DGRAM, 0);
	if (s < 0)
		return SCE_ERR_SOCKET;
	memset(&ifr, 0, sizeof(ifr));
	strncpy(ifr.ifr_name, name, sizeof(ifr.ifr_name));
	if (addr) {
		satosin(&ifr.ifr_addr)->sin_addr.s_addr = 0;
		if ((ret = sceNetInet_lib_AEE60F84(s, SIOCGIFADDR, (caddr_t)&ifr)) < 0) {
			ret = 0;
			if (sceNetInetGetErrno() != SCE_ERR_ADDRNOTAVAIL) {
				ret = 0x80410204;
				goto out;
			}
		}
		addr->s_addr = satosin(&ifr.ifr_addr)->sin_addr.s_addr;
	}
	if (mask) {
		satosin(&ifr.ifr_addr)->sin_addr.s_addr = 0;
		if ((ret = sceNetInet_lib_AEE60F84(s, SIOCGIFNETMASK, (caddr_t)&ifr)) < 0) {
			ret = 0;
			if (sceNetInetGetErrno() != SCE_ERR_ADDRNOTAVAIL) {
				ret = 0x80410204;
				goto out;
			}
		}
		mask->s_addr = satosin(&ifr.ifr_addr)->sin_addr.s_addr;
	}
	if (broadaddr) {
		satosin(&ifr.ifr_addr)->sin_addr.s_addr = 0;
		if ((ret = sceNetInet_lib_AEE60F84(s, SIOCGIFBRDADDR, (caddr_t)&ifr)) < 0) {
			ret = 0;
			if (sceNetInetGetErrno() != SCE_ERR_ADDRNOTAVAIL) {
				ret = 0x80410204;
				goto out;
			}
		}
		broadaddr->s_addr = satosin(&ifr.ifr_addr)->sin_addr.s_addr;
	}
out:
	sceNetInetClose(s);
	return ret;
}

__attribute__((noinline)) int
sceNetInet_lib_4F68DB0E(const char *name, const struct in_addr *addr, const struct in_addr *broadaddr, const struct in_addr *mask)
{
	struct ifaliasreq ifra;
	int s, ret;

	ret = 0;
	sceNetInet_lib_6A046357(name);
	s = sceNetInetSocket(AF_INET, SOCK_DGRAM, 0);
	if (s < 0)
		return SCE_ERR_SOCKET;
	memset(&ifra, 0, sizeof(ifra));
	strncpy(ifra.ifra_name, name, sizeof(ifra.ifra_name));
	if (addr) {
		satosin(&ifra.ifra_addr)->sin_len = sizeof(struct sockaddr_in);
		satosin(&ifra.ifra_addr)->sin_family = AF_INET;
		satosin(&ifra.ifra_addr)->sin_addr.s_addr = addr->s_addr;
	}
	if (mask) {
		satosin(&ifra.ifra_mask)->sin_len = sizeof(struct sockaddr_in);
		satosin(&ifra.ifra_mask)->sin_addr.s_addr = mask->s_addr;
	}
	if (broadaddr) {
		satosin(&ifra.ifra_broadaddr)->sin_len = sizeof(struct sockaddr_in);
		satosin(&ifra.ifra_broadaddr)->sin_family = AF_INET;
		satosin(&ifra.ifra_broadaddr)->sin_addr.s_addr = broadaddr->s_addr;
	}
	if (sceNetInet_lib_AEE60F84(s, SIOCAIFADDR, (caddr_t)&ifra) < 0)
		ret = 0x80410205;
	sceNetInetClose(s);
	return ret;
}

__attribute__((noinline)) int
sceNetInet_lib_6A046357(const char *name)
{
	struct ifreq ifr;
	int s, ret;

	s = sceNetInetSocket(AF_INET, SOCK_DGRAM, 0);
	if (s < 0)
		return SCE_ERR_SOCKET;
	memset(&ifr, 0, sizeof(ifr));
	strncpy(ifr.ifr_name, name, sizeof(ifr.ifr_name));
	if ((ret = sceNetInet_lib_AEE60F84(s, SIOCDIFADDR, (caddr_t)&ifr)) < 0) {
		if (sceNetInetGetErrno() == SCE_ERR_ADDRNOTAVAIL)
			ret = 0;
		else
			ret = 0x80410206;
	}
	sceNetInetClose(s);
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_E6F67D14);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_3D905F34);

__attribute__((noinline)) int
sceNetInet_lib_59561561(const u_char *hwaddr, const struct in_addr *addr)
{
#define rtm (&m_rtmsg.m_rtm)
	struct rtmsgbuf m_rtmsg;
	struct sockaddr_in sin_m;
	struct sockaddr_dl sdl_m;
	struct sockaddr_in *sin;
	struct sockaddr_dl *sdl;
	int s, ret;

	s = sceNetInetSocket(PF_ROUTE, SOCK_RAW, 0);
	if (s < 0)
		return SCE_ERR_SOCKET;
	memset(&sin_m, 0, sizeof(sin_m));
	sin_m.sin_len = sizeof(sin_m);
	sin_m.sin_family = AF_INET;
	sin_m.sin_addr.s_addr = addr->s_addr;
	ret = func_0000188C(s, rtm, RTM_GET, (struct sockaddr *)&sin_m, NULL, NULL, 0, ++rtm_seq1);
	if (ret < 0)
		goto out;
	sin = (struct sockaddr_in *)(rtm + 1);
	sdl = (struct sockaddr_dl *)(ROUNDUP(sin->sin_len) + (char *)sin);
	if (sin->sin_addr.s_addr == sin_m.sin_addr.s_addr) {
		if (sdl->sdl_family == AF_LINK &&
		    (rtm->rtm_flags & (RTF_LLINFO | RTF_GATEWAY_)) == RTF_LLINFO) switch (sdl->sdl_type) {
		case IFT_ETHER:
			goto overwrite;
		}
		ret = 0x80410283;
		goto out;
	}
overwrite:
	if (sdl->sdl_family != AF_LINK) {
		ret = 0x80410283;
		goto out;
	}
	memset(&sdl_m, 0, sizeof(sdl_m));
	sdl_m.sdl_len = sizeof(sdl_m);
	sdl_m.sdl_family = AF_LINK;
	sdl_m.sdl_type = sdl->sdl_type;
	sdl_m.sdl_index = sdl->sdl_index;
	memcpy(LLADDR(&sdl_m), hwaddr, 6);
	sdl_m.sdl_alen = 6;
	ret = func_0000188C(s, rtm, RTM_ADD, (struct sockaddr *)&sin_m, (struct sockaddr *)&sdl_m, NULL, RTF_HOST | RTF_STATIC, ++rtm_seq1);
out:
	sceNetInetClose(s);
	return ret;
}
#undef rtm

__attribute__((noinline)) int
sceNetInet_lib_DC38FEE9(void *unused, const struct in_addr *addr)
{
#define rtm (&m_rtmsg.m_rtm)
	struct rtmsgbuf m_rtmsg;
	struct sockaddr_in sin_m;
	struct sockaddr_in *sin;
	struct sockaddr_dl *sdl;
	int s, ret;

	s = sceNetInetSocket(PF_ROUTE, SOCK_RAW, 0);
	if (s < 0)
		return SCE_ERR_SOCKET;
	memset(&sin_m, 0, sizeof(sin_m));
	sin_m.sin_len = sizeof(sin_m);
	sin_m.sin_family = AF_INET;
	sin_m.sin_addr.s_addr = addr->s_addr;
	ret = func_0000188C(s, rtm, RTM_GET, (struct sockaddr *)&sin_m, NULL, NULL, 0, ++rtm_seq1);
	if (ret < 0)
		goto out;
	sin = (struct sockaddr_in *)(rtm + 1);
	sdl = (struct sockaddr_dl *)(ROUNDUP(sin->sin_len) + (char *)sin);
	if (sin->sin_addr.s_addr == sin_m.sin_addr.s_addr) {
		if (sdl->sdl_family == AF_LINK &&
		    (rtm->rtm_flags & (RTF_LLINFO | RTF_GATEWAY_)) == RTF_LLINFO) switch (sdl->sdl_type) {
		case IFT_ETHER:
			goto delete;
		}
		ret = 0x80410284;
		goto out;
	}
delete:
	if (sdl->sdl_family != AF_LINK) {
		ret = 0x80410284;
		goto out;
	}
	ret = func_0000188C(s, rtm, RTM_DELETE, NULL, NULL, NULL, 0, ++rtm_seq1);
out:
	sceNetInetClose(s);
	return ret;
}
#undef rtm

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_DE9E5174);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_824CBC6D);

__attribute__((noinline)) int
sceNetInet_lib_4459EAAF(const struct in_addr *dst, const struct in_addr *gw, const struct in_addr *mask)
{
	struct sockaddr_in sdst, sgw, smask;

	memset(&sdst, 0, sizeof(sdst));
	memset(&sgw, 0, sizeof(sgw));
	memset(&smask, 0, sizeof(smask));
	sdst.sin_addr.s_addr = dst->s_addr;
	sgw.sin_addr.s_addr = gw->s_addr;
	smask.sin_addr.s_addr = mask->s_addr;
	smask.sin_family = AF_INET;
	sgw.sin_family = AF_INET;
	sdst.sin_family = AF_INET;
	smask.sin_len = sizeof(smask);
	sgw.sin_len = sizeof(sgw);
	sdst.sin_len = sizeof(sdst);
	return func_00001598(RTM_ADD, (struct sockaddr *)&sdst, (struct sockaddr *)&sgw,
	    (struct sockaddr *)&smask, RTF_UP | RTF_GATEWAY_ | RTF_STATIC);
}

__attribute__((noinline)) int
sceNetInet_lib_EB7A7E4F(const struct in_addr *dst, const struct in_addr *gw, const struct in_addr *mask)
{
	struct sockaddr_in sdst, sgw, smask;

	memset(&sdst, 0, sizeof(sdst));
	memset(&sgw, 0, sizeof(sgw));
	memset(&smask, 0, sizeof(smask));
	sdst.sin_addr.s_addr = dst->s_addr;
	sgw.sin_addr.s_addr = gw->s_addr;
	smask.sin_addr.s_addr = mask->s_addr;
	smask.sin_family = AF_INET;
	sgw.sin_family = AF_INET;
	sdst.sin_family = AF_INET;
	smask.sin_len = sizeof(smask);
	sgw.sin_len = sizeof(sgw);
	sdst.sin_len = sizeof(sdst);
	return func_00001598(RTM_DELETE, (struct sockaddr *)&sdst, (struct sockaddr *)&sgw,
	    (struct sockaddr *)&smask, RTF_GATEWAY_ | RTF_STATIC);
}

static inline int
route_delete_default(void)
{
	struct sockaddr_in dst, mask;

	memset(&dst, 0, sizeof(dst));
	memset(&mask, 0, sizeof(mask));
	mask.sin_family = AF_INET;
	mask.sin_len = sizeof(mask);
	dst.sin_family = AF_INET;
	dst.sin_len = sizeof(dst);
	return func_00001598(RTM_DELETE, (struct sockaddr *)&dst, NULL,
	    (struct sockaddr *)&mask, RTF_GATEWAY_ | RTF_STATIC);
}

static inline int
route_add(const struct in_addr *dst, const struct in_addr *gw, const struct in_addr *mask)
{
	struct sockaddr_in sdst, sgw, smask;

	memset(&sdst, 0, sizeof(sdst));
	memset(&sgw, 0, sizeof(sgw));
	memset(&smask, 0, sizeof(smask));
	sdst.sin_addr.s_addr = dst->s_addr;
	sgw.sin_addr.s_addr = gw->s_addr;
	smask.sin_addr.s_addr = mask->s_addr;
	smask.sin_family = AF_INET;
	sgw.sin_family = AF_INET;
	sdst.sin_family = AF_INET;
	smask.sin_len = sizeof(smask);
	sgw.sin_len = sizeof(sgw);
	sdst.sin_len = sizeof(sdst);
	return func_00001598(RTM_ADD, (struct sockaddr *)&sdst, (struct sockaddr *)&sgw,
	    (struct sockaddr *)&smask, RTF_UP | RTF_GATEWAY_ | RTF_STATIC);
}

__attribute__((noinline)) int
sceNetInet_lib_7776A492(const struct in_addr *gw)
{
	struct in_addr dst, mask;

	route_delete_default();
	mask.s_addr = 0;
	dst.s_addr = 0;
	return route_add(&dst, gw, &mask);
}

__attribute__((noinline)) int
sceNetInet_lib_3FDDB0BA(void)
{
	struct sockaddr_in dst, mask;

	memset(&dst, 0, sizeof(dst));
	memset(&mask, 0, sizeof(mask));
	mask.sin_family = AF_INET;
	mask.sin_len = sizeof(mask);
	dst.sin_family = AF_INET;
	dst.sin_len = sizeof(dst);
	return func_00001598(RTM_DELETE, (struct sockaddr *)&dst, NULL,
	    (struct sockaddr *)&mask, RTF_GATEWAY | RTF_STATIC);
}

__attribute__((noinline)) int
sceNetInet_lib_8FE19FC4(u_char *out)
{
	struct rtentstat rt;
	int size = sizeof(rt);
	int ret;
	u_int v;

	ret = sceNetInet_lib_3D905F34(&size, &rt);
	if (ret < 0)
		goto out;
	if (rt.dst.s_addr != 0) {
		ret = 0x80410207;
		goto out;
	}
	v = rt.gateway.s_addr;
	out[0] = v;
	out[1] = v >> 8;
	out[2] = v >> 16;
	out[3] = v >> 24;
out:
	return ret;
}

__attribute__((noinline)) void
func_00001584(void)
{
	D_0002EB40 = 0;
	D_0002EB44 = 0;
}

__attribute__((noinline)) int
func_00001598(int cmd, struct sockaddr *dst, struct sockaddr *gate, struct sockaddr *mask, int flags)
{
	struct rtmsgbuf m_rtmsg;
	char *cp = m_rtmsg.m_space;
	int s, l, ret;

	s = sceNetInetSocket(PF_ROUTE, SOCK_RAW, 0);
	if (s < 0)
		return SCE_ERR_SOCKET;
	memset(&m_rtmsg, 0, sizeof(m_rtmsg));
	m_rtmsg.m_rtm.rtm_type = cmd;
	m_rtmsg.m_rtm.rtm_flags = flags;
	m_rtmsg.m_rtm.rtm_version = RTM_VERSION;
	m_rtmsg.m_rtm.rtm_seq = ++rtm_seq0;
#define NEXTADDR(w, u) \
	if (u) { \
		m_rtmsg.m_rtm.rtm_addrs |= (w); \
		l = ROUNDUP(u->sa_len); \
		memmove(cp, u, l); \
		cp += l; \
	}
	NEXTADDR(RTA_DST, dst);
	NEXTADDR(RTA_GATEWAY, gate);
	NEXTADDR(RTA_NETMASK, mask);
#undef NEXTADDR
	m_rtmsg.m_rtm.rtm_msglen = l = cp - (char *)&m_rtmsg;
	ret = sceNetInetSend(s, &m_rtmsg, l, 0) < 0 ? 0x80410209 : 0;
	sceNetInetClose(s);
	return ret;
}

__attribute__((noinline)) int
func_00001744(char **bufp, size_t *lenp)
{
	int mib[6];
	size_t needed;
	char *buf;
	int ret = 0;

again:
	mib[0] = CTL_NET;
	mib[1] = PF_ROUTE;
	mib[2] = 0;
	mib[3] = AF_INET;
	mib[4] = NET_RT_DUMP;
	mib[5] = 0;
	if (sysctl(mib, 6, NULL, &needed, NULL, 0) < 0)
		return 0x80410208;
	if (needed == 0) {
		*lenp = 0;
		return 0;
	}
	if ((buf = sceNetMallocInternal(needed)) == NULL)
		return 0x80410001;
	memset(buf, 0, needed);
	if (sysctl(mib, 6, buf, &needed, NULL, 0) < 0) {
		if (sceNetInetGetErrno() == ENOSPC) {
			sceNetFreeInternal(buf);
			goto again;
		}
		ret = 0x80410208;
	} else {
		*bufp = buf;
		*lenp = needed;
	}
	if (ret < 0) {
		if (buf)
			sceNetFreeInternal(buf);
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", func_0000188C);

__attribute__((noinline)) int
sceNetInet_lib_AC9D90A5(struct in_addr *a, struct in_addr *b)
{
	if (a)
		*a = D_0002EB48;
	if (b)
		*b = D_0002EB4C;
	return 0;
}

__attribute__((noinline)) int
sceNetInet_lib_AAF4895A(const struct in_addr *a, const struct in_addr *b)
{
	if (a)
		D_0002EB48 = *a;
	if (b)
		D_0002EB4C = *b;
	return 0;
}

__attribute__((noinline)) int
sceNetInetGetTcpcbstat(int *size, struct tcpcbstat *buf)
{
	struct inpcb *inp;
	struct tcpcbstat *tcs, *prev;
	struct socket *so;
	int s, n = 0;

	s = _sce_pspnet_spllock();
	tcs = buf;
	prev = NULL;
	for (inp = tcbtable.inpt_queue.cqh_first;
	    inp != (struct inpcb *)&tcbtable.inpt_queue;
	    inp = inp->inp_queue.cqe_next) {
		n++;
		if (buf == NULL)
			continue;
		if (*size < n) {
			n--;
			break;
		}
		if (prev)
			prev->next = tcs;
		memset(tcs, 0, sizeof(*tcs));
		so = inp->inp_socket;
		tcs->txqueue = so->so_snd.sb_cc;
		tcs->rxqueue = so->so_rcv.sb_cc;
		memcpy(&tcs->laddr, &inp->inp_laddr, sizeof(tcs->laddr));
		memcpy(&tcs->faddr, &inp->inp_faddr, sizeof(tcs->faddr));
		tcs->lport = inp->inp_lport;
		tcs->fport = inp->inp_fport;
		tcs->state = intotcpcb(inp)->t_state;
		prev = tcs;
		tcs++;
	}
	_sce_pspnet_splunlock(s);
	*size = n * sizeof(struct tcpcbstat);
	return 0;
}

__attribute__((noinline)) int
sceNetInetGetUdpcbstat(int *size, struct udpcbstat *buf)
{
	struct inpcb *inp;
	struct udpcbstat *ucs, *prev;
	struct socket *so;
	int s, n = 0;

	s = _sce_pspnet_spllock();
	ucs = buf;
	prev = NULL;
	for (inp = udbtable.inpt_queue.cqh_first;
	    inp != (struct inpcb *)&udbtable.inpt_queue;
	    inp = inp->inp_queue.cqe_next) {
		n++;
		if (buf == NULL)
			continue;
		if (*size < n) {
			n--;
			break;
		}
		if (prev)
			prev->next = ucs;
		memset(ucs, 0, sizeof(*ucs));
		so = inp->inp_socket;
		ucs->txqueue = so->so_snd.sb_cc;
		ucs->rxqueue = so->so_rcv.sb_cc;
		memcpy(&ucs->laddr, &inp->inp_laddr, sizeof(ucs->laddr));
		memcpy(&ucs->faddr, &inp->inp_faddr, sizeof(ucs->faddr));
		ucs->lport = inp->inp_lport;
		ucs->fport = inp->inp_fport;
		prev = ucs;
		ucs++;
	}
	_sce_pspnet_splunlock(s);
	*size = n * sizeof(struct udpcbstat);
	return 0;
}
