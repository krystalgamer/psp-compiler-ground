/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

#define senderr(e) { error = (e); goto bad; }
#define SIN(s) ((struct sockaddr_in *)s)

int
ether_multiaddr(struct sockaddr *sa, u_int8_t addrlo[ETHER_ADDR_LEN], u_int8_t addrhi[ETHER_ADDR_LEN])
{
	struct sockaddr_in *sin;

	switch (sa->sa_family) {
	case AF_INET:
		sin = satosin(sa);
		if (sin->sin_addr.s_addr == INADDR_ANY) {
			bcopy(ether_ipmulticast_min, addrlo, ETHER_ADDR_LEN);
			bcopy(ether_ipmulticast_max, addrhi, ETHER_ADDR_LEN);
		} else {
			ETHER_MAP_IP_MULTICAST(&sin->sin_addr, addrlo);
			bcopy(addrlo, addrhi, ETHER_ADDR_LEN);
		}
		break;
	}
	return (0);
}

void
func_0000988C(struct ifnet *ifp, struct mbuf *m, u_short etype, void *arg)
{
	if (D_0002EB70 > 0)
		D_0002EB6C(m, etype, arg);
}

void
func_000098D0(struct ifnet *ifp, struct mbuf *m, u_short etype, void *arg,
    struct ifqueue **inq, int *isr, int *done)
{
	switch (etype) {
	case ETHERTYPE_IP:
		*isr = NETISR_IP;
		*inq = &ipintrq;
		break;
	case ETHERTYPE_ARP:
		*isr = NETISR_ARP;
		*inq = &arpintrq;
		break;
	case ETHERTYPE_REVARP:
		revarpinput(m);
		*done = 1;
		break;
	default:
		m_freem(m);
		*done = 1;
		break;
	}
}

int
func_00009968(void (*fn)(struct mbuf *, u_short, void *))
{
	D_0002EB6C = fn;
	D_0002EB70 = 1;
	return 0;
}

int
func_00009984(void)
{
	D_0002EB70 = 0;
	D_0002EB6C = 0;
	return 0;
}

int
func_0000999C(void)
{
	return _sce_pspnet_start_of_inet_module_in_if_ethersubr_core(ether_output,
	    func_0000988C, func_000098D0, ether_multiaddr);
}

void
func_000099D4(void)
{
	_sce_pspnet_stop_of_inet_module_in_if_ethersubr_core();
}

struct ifqueue *
sceNetInet_lib_D7928A6D(void)
{
	return &ipintrq;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/if_ethersubr", func_000099FC);
