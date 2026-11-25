/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "ifhandle.h"

static inline void *mallocSub(unsigned int size)
{
	void *p;
	int used;
	SceKernelVplInfo info;

	if (sceKernelTryAllocateVpl(D_00003B28, size, &p) < 0)
		return 0;
	info.size = sizeof(info);
	if (sceKernelReferVplStatus(D_00003B28, &info) == 0) {
		used = info.poolSize - info.freeSize;
		if (D_00003B2C < used)
			D_00003B2C = used;
	}
	return p;
}
/* --- end declarations --- */

int module_start(void)
{
	return 0;
}

int module_stop(void)
{
	return 0;
}
