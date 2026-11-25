/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc_auth.h"
/* --- end declarations --- */

int func_00001110(struct mbuf *m)
{
	int s;

	if (m->m_pkthdr.len < 0x14)
		return -1;
	s = sceKernelCpuSuspendIntr();
	if (D_00003EE4 == 0 || IF_QFULL(&D_00004058))
		goto fail;
	IF_ENQUEUE(&D_00004058, m);
	if (!(D_00003EE4->flags & 1)) {
		D_00003EE4->flags |= 1;
		sceKernelSendMbx(D_00003EE4->mbx, &D_00003EE4->msg);
	}
	sceKernelCpuResumeIntr(s);
	return 0;
fail:
	sceKernelCpuResumeIntr(s);
	return -1;
}

int func_000011F0(void)
{
	return 0;
}

void func_000011F8(void)
{
	sceNetAdhocAuth_lib_2E6AA271();
}
