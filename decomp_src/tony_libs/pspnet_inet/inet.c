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
int sceNetInet_lib_3D905F34(int *size, void *buf);
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
#define udbtable D_000302C8
extern struct inpcbtable udbtable;
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

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_59561561);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_DC38FEE9);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_DE9E5174);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_824CBC6D);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_4459EAAF);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_EB7A7E4F);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_7776A492);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_3FDDB0BA);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInet_lib_8FE19FC4);

__attribute__((noinline)) void
func_00001584(void)
{
	D_0002EB40 = 0;
	D_0002EB44 = 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", func_00001598);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", func_00001744);

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

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInetGetTcpcbstat);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/inet", sceNetInetGetUdpcbstat);
