/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", _sce_pspnet_if_attach);

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

void func_0000595C(struct ifnet *ifp, int disable)
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
	ifp->if_stop = func_0000595C;
	ifp->if_watchdog = func_00005964;
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

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", func_00005A78);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", _sce_pspnet_ifunit);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", _sce_pspnet_if_exist);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", _sce_pspnet_ifioctl_sync);

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

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", _sce_pspnet_start_of_inet_module_in_if_core);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", _sce_pspnet_stop_of_inet_module_in_if_core);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", func_0000610C);


INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", func_00006654);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if", func_00006844);