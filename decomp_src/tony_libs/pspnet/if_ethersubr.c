/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

int func_00006654(struct ifreq *ifr, struct ifnet *ec)
{

	struct ether_multi *enm;
	u_char addrlo[6];
	u_char addrhi[6];
	int s, error;

	s = _sce_pspnet_spllock();
	error = ether_multiaddr_i(&ifr->ifr_ifru.ifru_addr, addrlo, addrhi);
	if (error != 0) {
		_sce_pspnet_splunlock(s);
		return error;
	}
	if (!(addrlo[0] & 1) || !(addrhi[0] & 1)) {
		_sce_pspnet_splunlock(s);
		return 22;
	}
	ETHER_LOOKUP_MULTI(addrlo, addrhi, ec, enm);
	if (enm != NULL) {
		enm->enm_refcount++;
		_sce_pspnet_splunlock(s);
		return 0;
	}
	enm = sceNetMallocInternal(sizeof(*enm));
	if (enm == NULL) {
		_sce_pspnet_splunlock(s);
		return 0x69;
	}
	bcopy(addrlo, enm->enm_addrlo, 6);
	bcopy(addrhi, enm->enm_addrhi, 6);
	enm->enm_ec = ec;
	enm->enm_refcount = 1;
	if ((enm->enm_next = ec->ec_multiaddrs) != NULL)
		ec->ec_multiaddrs->enm_prev = &enm->enm_next;
	ec->ec_multiaddrs = enm;
	enm->enm_prev = &ec->ec_multiaddrs;
	ec->ec_multicnt++;
	_sce_pspnet_splunlock(s);
	return 0x7E;
}

int func_00006844(struct ifreq *ifr, struct ifnet *ec)
{

	struct ether_multi *enm;
	u_char addrlo[6];
	u_char addrhi[6];
	int s, error;

	s = _sce_pspnet_spllock();
	error = ether_multiaddr_i(&ifr->ifr_ifru.ifru_addr, addrlo, addrhi);
	if (error != 0) {
		_sce_pspnet_splunlock(s);
		return error;
	}
	ETHER_LOOKUP_MULTI(addrlo, addrhi, ec, enm);
	if (enm == NULL) {
		_sce_pspnet_splunlock(s);
		return 6;
	}
	if (--enm->enm_refcount != 0) {
		_sce_pspnet_splunlock(s);
		return 0;
	}
	if (enm->enm_next != NULL)
		enm->enm_next->enm_prev = enm->enm_prev;
	*enm->enm_prev = enm->enm_next;
	sceNetFreeInternal(enm);
	ec->ec_multicnt--;
	_sce_pspnet_splunlock(s);
	return 0x7E;
}

char *func_000069D4(const u_char *ap)
{
	int i;
	char *cp = D_0000B098;

	for (i = 0; i < 6; i++) {
		*cp++ = D_0000A0B8[*ap >> 4];
		*cp++ = D_0000A0B8[*ap++ & 0xf];
		*cp++ = ':';
	}
	*--cp = 0;
	return D_0000B098;
}

void func_00006A40(struct ifnet *ifp, const u_char *lla)
{
	struct sockaddr_dl *sdl;

	ifp->if_type = 6;
	ifp->if_addrlen = 6;
	ifp->if_hdrlen = 14;
	ifp->if_mtu = 1500;
	ifp->if_output = func_000071C8;
	ifp->if_input = func_00006E34;
	if (ifp->if_baudrate == 0)
		ifp->if_baudrate = 10000000;
	if ((sdl = ifp->if_sadl) != NULL && sdl->sdl_family == 18) {
		sdl->sdl_type = 6;
		sdl->sdl_alen = ifp->if_addrlen;
		bcopy(lla, sdl->sdl_data + sdl->sdl_nlen, ifp->if_addrlen);
	}
	ifp->ec_multiaddrs = NULL;
	ifp->if_unkE4 = etherbroadcastaddr;
}

void func_00006B10(struct ifnet *ifp)
{
	struct ether_multi *enm;
	struct sockaddr_dl *sdl = ifp->if_sadl;
	int s;

	s = _sce_pspnet_spllock();
	while ((enm = ifp->ec_multiaddrs) != NULL) {
		if (enm->enm_next != NULL)
			enm->enm_next->enm_prev = enm->enm_prev;
		*enm->enm_prev = enm->enm_next;
		sceNetFreeInternal(enm);
		ifp->ec_multicnt--;
	}
	_sce_pspnet_splunlock(s);
	__builtin_memset(sdl->sdl_data + sdl->sdl_nlen, 0, 6);
	sdl->sdl_alen = 0;
	sdl->sdl_type = 0;
}

u_int func_00006BBC(const u_char *buf, u_int len)
{
	static const u_int crctab[] = {
		0x00000000, 0x1db71064, 0x3b6e20c8, 0x26d930ac,
		0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c,
		0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c,
		0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c
	};
	u_int crc;
	u_int i;

	crc = 0xffffffffU;
	for (i = 0; i < len; i++) {
		crc ^= buf[i];
		crc = (crc >> 4) ^ crctab[crc & 0xf];
		crc = (crc >> 4) ^ crctab[crc & 0xf];
	}
	return crc;
}

u_int func_00006C28(const u_char *buf, u_int len)
{
	u_int c, crc, carry;
	u_int i, j;

	crc = 0xffffffffU;
	for (i = 0; i < len; i++) {
		c = buf[i];
		for (j = 0; j < 8; j++) {
			carry = ((crc & 0x80000000U) ? 1 : 0) ^ (c & 0x01);
			crc <<= 1;
			c >>= 1;
			if (carry)
				crc = (crc ^ 0x04c11db6) | carry;
		}
	}
	return crc;
}

int func_00006C90(struct sockaddr *sa, u_char *addrlo, u_char *addrhi)
{
	int handled;
	int ret;

	if (D_0000B090 > 0) {
		handled = 0;
		ret = ((int (*)(struct sockaddr *, u_char *, u_char *, int *))D_0000B088)(sa, addrlo, addrhi, &handled);
		if (handled > 0)
			return ret;
	}
	if (sa->sa_family != 0)
		return 0x6A;
	bcopy(sa->sa_data, addrlo, 6);
	bcopy(addrlo, addrhi, 6);
	return 0;
}

struct ifnet *_sce_pspnet_ifplookup_lladdr(const u_char *lla)
{
	struct ifnet *ifp;

	for (ifp = ifnet.tqh_first; ifp != NULL; ifp = ifp->if_list.tqe_next) {
		if (memcmp(ifp->if_sadl->sdl_data + ifp->if_sadl->sdl_nlen, lla, 6) == 0)
			break;
	}
	return ifp;
}

int _sce_pspnet_start_of_inet_module_in_if_ethersubr_core(int (*a)(struct ifnet *, struct mbuf *, void *, void *), void *b, void *c, void *d)
{
	D_0000B07C = a;
	D_0000B080 = b;
	D_0000B084 = c;
	D_0000B088 = d;
	D_0000B090 = 1;
	return 0;
}

int _sce_pspnet_stop_of_inet_module_in_if_ethersubr_core(void)
{
	D_0000B090 = 0;
	D_0000B07C = NULL;
	D_0000B080 = NULL;
	D_0000B084 = NULL;
	D_0000B088 = NULL;
	return 0;
}

int _sce_pspnet_start_of_adhoc_module_in_if_ethersubr_core(void *a)
{
	D_0000B08C = a;
	D_0000B094 = 1;
	return 0;
}

int _sce_pspnet_stop_of_adhoc_module_in_if_ethersubr_core(void)
{
	D_0000B094 = 0;
	D_0000B08C = NULL;
	return 0;
}

void func_00006E34(struct ifnet *ifp, struct mbuf *m)
{
	struct ifqueue *inq = NULL;
	int isr = 0;
	u_char *eh;
	u_short etype;
	int s;

	if ((ifp->if_flags & 1) == 0) {
		sceNetMFreem(m);
		return;
	}
	eh = mtod(m, u_char *);
	etype = (u_short)__builtin_allegrex_wsbh((eh[13] << 8) | eh[12]);
	if (m->m_pkthdr.len > ifp->if_mtu + 14 + (((u_short)m->m_flags & 0x1000) ? 4 : 0) + ((etype == 0x8100) ? 4 : 0)) {
		sceNetMFreem(m);
		return;
	}
	ifp->if_ibytes += m->m_pkthdr.len;
	if (eh[0] & 1)
		ifp->if_imcasts++;
	else if ((ifp->if_flags & 0x100) &&
	    memcmp(ifp->if_sadl->sdl_data + ifp->if_sadl->sdl_nlen, eh, 6) != 0) {
		sceNetMFreem(m);
		return;
	}
	if (etype == 0x88C8) {
		s = _sce_pspnet_spllock();
		if (D_0000B094 > 0) {
			if (((int (*)(struct ifnet *, struct mbuf *, struct ifqueue **))D_0000B08C)(ifp, m, &inq) >= 0) {
				if (inq->ifq_len >= inq->ifq_maxlen) {
					inq->ifq_drops++;
					sceNetMFreem(m);
				} else {
					m->m_nextpkt = NULL;
					if (inq->ifq_tail == NULL)
						inq->ifq_head = m;
					else
						inq->ifq_tail->m_nextpkt = m;
					inq->ifq_tail = m;
					inq->ifq_len++;
				}
				_sce_pspnet_splunlock(s);
				_sce_pspnet_schednetintr(0x1D);
				return;
			}
			_sce_pspnet_splunlock(s);
			return;
		}
		_sce_pspnet_splunlock(s);
	}
	if (D_0000B090 > 0) {
		int handled = 0;

		((void (*)(struct ifnet *, struct mbuf *, int, int *))D_0000B080)(ifp, m, etype, &handled);
		if (handled > 0)
			return;
	}
	sceNetMAdj(m, 14);
	if (m->m_flags & 0x1000)
		sceNetMAdj(m, -4);
	if (D_0000B090 > 0) {
		int handled = 0;

		((void (*)(struct ifnet *, struct mbuf *, int, u_char *, struct ifqueue **, int *, int *))D_0000B084)(ifp, m, etype, eh, &inq, &isr, &handled);
		if (handled > 0)
			return;
	}
	if (inq == NULL) {
		sceNetMFreem(m);
		return;
	}
	s = _sce_pspnet_spllock();
	if (inq->ifq_len >= inq->ifq_maxlen) {
		inq->ifq_drops++;
		sceNetMFreem(m);
	} else {
		m->m_nextpkt = NULL;
		if (inq->ifq_tail == NULL)
			inq->ifq_head = m;
		else
			inq->ifq_tail->m_nextpkt = m;
		inq->ifq_tail = m;
		inq->ifq_len++;
		_sce_pspnet_schednetintr(isr);
	}
	_sce_pspnet_splunlock(s);
}

int func_000071C8(struct ifnet *ifp, struct mbuf *m, void *dst, void *rt)
{
	int ret = 0;

	if (D_0000B090 > 0)
		ret = D_0000B07C(ifp, m, dst, rt);
	return ret;
}

