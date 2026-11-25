/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

void _sce_pspnet_if_attach(struct ifnet *ifp)
{
	unsigned int socksize, ifasize;
	int namelen, masklen;
	struct sockaddr_dl *sdl;
	struct ifaddr *ifa;
	struct ifnet *p;
	int index = 1;

	TAILQ_INIT(&ifp->if_addrlist);
	for (;;) {
		for (p = D_0000BB24.tqh_first; p != NULL; p = p->if_list.tqe_next) {
			if (p->if_index == index)
				break;
		}
		if (p == NULL)
			break;
		if (++index >= 8)
			break;
	}
	if (D_0000B070 < index)
		D_0000B070 = index;
	TAILQ_INSERT_TAIL(&D_0000BB24, ifp, if_list);
	ifp->if_index = index;
	D_0000B078[ifp->if_index] = ifp;

	namelen = strlen(ifp->if_xname);
	masklen = 8 + namelen;
	socksize = masklen + ifp->if_addrlen;
	if (socksize < sizeof(struct sockaddr_dl))
		socksize = sizeof(struct sockaddr_dl);
	socksize = ((socksize - 1) | 3) + 1;
	ifasize = sizeof(*ifa) + 2 * socksize;
	ifa = sceNetMallocInternal(ifasize);
	memset(ifa, 0, ifasize);
	sdl = (struct sockaddr_dl *)(ifa + 1);
	sdl->sdl_len = socksize;
	sdl->sdl_family = 18;
	bcopy(ifp->if_xname, sdl->sdl_data, namelen);
	sdl->sdl_nlen = namelen;
	sdl->sdl_index = ifp->if_index;
	sdl->sdl_type = ifp->if_type;
	D_0000B074[ifp->if_index] = ifa;
	ifa->ifa_refcnt++;
	ifa->ifa_rtrequest = _sce_pspnet_link_rtrequest;
	ifa->ifa_ifp = ifp;
	if ((ifa->ifa_list.tqe_next = ifp->if_addrlist.tqh_first) != NULL)
		ifp->if_addrlist.tqh_first->ifa_list.tqe_prev = &ifa->ifa_list.tqe_next;
	else
		ifp->if_addrlist.tqh_last = &ifa->ifa_list.tqe_next;
	ifp->if_addrlist.tqh_first = ifa;
	ifa->ifa_list.tqe_prev = &ifp->if_addrlist.tqh_first;
	ifa->ifa_refcnt++;
	ifa->ifa_addr = (struct sockaddr *)sdl;
	ifp->if_sadl = sdl;
	sdl = (struct sockaddr_dl *)(socksize + (char *)sdl);
	ifa->ifa_netmask = (struct sockaddr *)sdl;
	sdl->sdl_len = masklen;
	while (namelen != 0)
		sdl->sdl_data[--namelen] = 0xff;
	if (ifp->if_snd.ifq_maxlen == 0)
		ifp->if_snd.ifq_maxlen = D_0000A0AC;
	ifp->if_unkE4 = NULL;
	ifp->if_link_state = 0;
	if (D_0000B068 > 0)
		D_0000B038(ifp);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", _sce_pspnet_if_detach);

void _sce_pspnet_if_down(struct ifnet *ifp)
{
	ifp->if_flags &= ~1;
	if (D_0000B068 > 0)
		D_0000B04C(ifp);
	func_00005404(&ifp->if_snd);
	if (D_0000B068 > 0)
		D_0000B050(ifp);
}

void func_00005404(struct ifqueue *ifq)
{
	struct mbuf *m, *n;

	n = ifq->ifq_head;
	while ((m = n) != NULL) {
		n = m->m_nextpkt;
		sceNetMFreem(m);
	}
	ifq->ifq_head = NULL;
	ifq->ifq_tail = NULL;
	ifq->ifq_len = 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", _sce_pspnet_ifioctl);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", func_00005614);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", func_000057D8);

int _sce_pspnet_if_nulloutput(struct ifnet *ifp, struct mbuf *m, void *dst, void *rt)
{
	return 6;
}

void func_0000593C(struct ifnet *ifp, struct mbuf *m)
{
}

void func_00005944(struct ifnet *ifp)
{
}

int func_0000594C(struct ifnet *ifp, u_long cmd, void *data)
{
	return 6;
}

int func_00005954(struct ifnet *ifp)
{
	return 6;
}

void func_0000595C(struct ifnet *ifp)
{
}

void func_00005964(struct ifnet *ifp)
{
}

void func_0000596C(struct ifnet *ifp)
{
	int s;

	s = _sce_pspnet_spllock();
	ifp->if_output = _sce_pspnet_if_nulloutput;
	ifp->if_input = func_0000593C;
	ifp->if_start = func_00005944;
	ifp->if_ioctl = func_0000594C;
	ifp->if_init = func_00005954;
	ifp->if_watchdog = func_0000595C;
	ifp->if_drain = func_00005964;
	ifp->if_snd.ifq_maxlen = 0;
	_sce_pspnet_splunlock(s);
}

void _sce_pspnet_ifafree(void *ifa)
{
	sceNetFreeInternal(ifa);
}

void _sce_pspnet_link_rtrequest(int cmd, void *rt, void *info)
{
	if (D_0000B068 > 0)
		D_0000B030(cmd, rt, info);
}

void _sce_pspnet_if_up(struct ifnet *ifp)
{
	ifp->if_flags |= 1;
	if (D_0000B068 > 0)
		D_0000B054(ifp);
}

void func_00005A78(void *arg)
{
	struct ifnet *ifp;
	int s;

	s = _sce_pspnet_spllock();
	for (ifp = D_0000BB24.tqh_first; ifp != NULL; ifp = ifp->if_list.tqe_next) {
		if (ifp->if_timer == 0 || --ifp->if_timer)
			continue;
		if (ifp->if_watchdog)
			(*ifp->if_watchdog)(ifp);
	}
	_sce_pspnet_splunlock(s);
	_sce_pspnet_callout_reset(&D_0000BB2C, 100, func_00005A78, NULL);
}

struct ifnet *_sce_pspnet_ifunit(const char *name)
{
	return if_find(name);
}

int _sce_pspnet_if_exist(const char *name)
{
	struct ifnet *ifp;
	int s;

	s = _sce_pspnet_spllock();
	for (ifp = D_0000BB24.tqh_first; ifp != NULL; ifp = ifp->if_list.tqe_next) {
		if (ifp->if_output == _sce_pspnet_if_nulloutput)
			continue;
		if (strcmp(ifp->if_xname, name) == 0) {
			_sce_pspnet_splunlock(s);
			return 1;
		}
	}
	_sce_pspnet_splunlock(s);
	return 0;
}

int _sce_pspnet_ifioctl_sync(const char *name, int *out)
{
	struct ifnet *ifp;

	if (out == NULL)
		return 0x80410103;
	ifp = if_find(name);
	if (ifp == NULL)
		return 0x80410180;
	while (ifp->if_iopending > 0) {
		if (sceNetIfhandlePollSema(ifp->if_iosema, 1) < 0)
			return 0x80410181;
		ifp->if_iopending--;
	}
	*out = ifp->if_iostatus;
	sceNetIfhandleSignalSema(ifp->if_iosema2, 1);
	return 0;
}

int _sce_pspnet_get_ifindex(const char *name)
{
	struct ifnet *ifp;
	int idx = -1;
	int s;

	s = _sce_pspnet_spllock();
	for (ifp = D_0000BB24.tqh_first; ifp != NULL; ifp = ifp->if_list.tqe_next) {
		if (strncmp(name, ifp->if_xname, 16) == 0) {
			idx = ifp->if_index;
			break;
		}
	}
	_sce_pspnet_splunlock(s);
	return idx;
}

struct ifnet *_sce_pspnet_ifplookup_index(int idx)
{
	struct ifnet *ifp;
	int s;

	s = _sce_pspnet_spllock();
	for (ifp = D_0000BB24.tqh_first; ifp != NULL; ifp = ifp->if_list.tqe_next) {
		if (ifp->if_index == idx)
			break;
	}
	_sce_pspnet_splunlock(s);
	return ifp;
}

int _sce_pspnet_get_if_core_variables(int *a, int *b, int *c, struct ifnet_head *d)
{
	if (a != NULL)
		*a = D_0000B070;
	if (b != NULL)
		*b = D_0000B078;
	if (c != NULL)
		*c = D_0000B074;
	if (d != NULL)
		*d = D_0000BB24;
	return 0;
}

int _sce_pspnet_start_of_inet_module_in_if_core(void (*a)(int, void *, void *), void *b,
	void (*c)(struct ifnet *), void (*d)(struct ifaddr *), void (*e)(struct ifnet *, int),
	void (*f)(struct ifnet *), void (*g)(struct ifnet *), void (*h)(struct ifnet *),
	void (*i)(struct ifnet *), void (*j)(struct ifnet *), void *k, void *l, void *m)
{
	struct ifnet *ifp;

	D_0000B030 = a;
	D_0000B034 = b;
	D_0000B038 = c;
	D_0000B03C = d;
	D_0000B040 = e;
	D_0000B044 = f;
	D_0000B048 = g;
	D_0000B04C = h;
	D_0000B050 = i;
	D_0000B054 = j;
	D_0000B058 = k;
	D_0000B05C = l;
	D_0000B060 = m;
	for (ifp = D_0000BB24.tqh_first; ifp != NULL; ifp = ifp->if_list.tqe_next) {
		c(ifp);
		if (ifp->if_flags & 1)
			j(ifp);
	}
	D_0000B068 = 1;
	return 0;
}

int _sce_pspnet_stop_of_inet_module_in_if_core(void)
{
	struct ifnet *ifp;
	struct ifaddr *ifa;
	int s, af;

	D_0000B068 = 0;
	for (ifp = D_0000BB24.tqh_first; ifp != NULL; ifp = ifp->if_list.tqe_next) {
		s = _sce_pspnet_spllock();
		_sce_pspnet_if_down(ifp);
		ifa = ifp->if_addrlist.tqh_first;
		while (ifa != NULL) {
			af = ifa->ifa_addr->sa_family;
			if (af == 18) {
				D_0000B03C(ifa);
				ifa = ifa->ifa_list.tqe_next;
			} else {
				D_0000B040(ifp, af);
				ifa = ifp->if_addrlist.tqh_first;
			}
		}
		D_0000B044(ifp);
		D_0000B048(ifp);
		_sce_pspnet_splunlock(s);
	}
	D_0000B030 = NULL;
	D_0000B034 = NULL;
	D_0000B038 = NULL;
	D_0000B03C = NULL;
	D_0000B040 = NULL;
	D_0000B044 = NULL;
	D_0000B048 = NULL;
	D_0000B04C = NULL;
	D_0000B050 = NULL;
	D_0000B054 = NULL;
	D_0000B058 = NULL;
	D_0000B05C = NULL;
	D_0000B060 = NULL;
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", func_0000610C);


