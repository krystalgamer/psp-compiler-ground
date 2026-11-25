/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/ifhandle_ether", func_000071FC);

void func_00007680(struct ifnet *ifp)
{
	struct mbuf *m;

	for (;;) {
		m = ifp->if_snd.ifq_head;
		if (m == NULL)
			break;
		if ((ifp->if_snd.ifq_head = m->m_nextpkt) == NULL)
			ifp->if_snd.ifq_tail = NULL;
		m->m_nextpkt = NULL;
		ifp->if_snd.ifq_len--;
		if (ifp->if_bpf)
			func_000044C0(ifp->if_bpf, m);
		sceNetIfhandleIfStart(ifp, m);
	}
}

int _sce_pspnet_start_of_inet_module_in_ifhandle_ether(void *a)
{
	D_0000B0AC = a;
	D_0000B0B0 = 1;
	return 0;
}

int _sce_pspnet_stop_of_inet_module_in_ifhandle_ether(void)
{
	D_0000B0B0 = 0;
	D_0000B0AC = NULL;
	return 0;
}
