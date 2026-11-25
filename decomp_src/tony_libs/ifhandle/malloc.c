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

int sceNetIfhandle_lib_0C391E9F(unsigned int size)
{
	int ret;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	ret = sceKernelCreateVpl("pspnet", 2, 0, size, 0);
	if (ret >= 0) {
		D_00003B28 = ret;
		D_00003B2C = 0;
	}
	K1_RESTORE(oldk1);
	return ret;
}

int sceNetIfhandle_lib_29ED84C5(void)
{
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (D_00003B28 > 0) {
		sceKernelDeleteVpl(D_00003B28);
		D_00003B28 = -1;
	}
	K1_RESTORE(oldk1);
	return 0;
}

int sceNetIfhandle_lib_4C2886CB(int *stat)
{
	int ret;
	SceKernelVplInfo info;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (stat == 0 || (K1_USER() && (int)stat < 0)) {
		K1_RESTORE(oldk1);
		return 0x80410103;
	}
	info.size = sizeof(info);
	ret = sceKernelReferVplStatus(D_00003B28, &info);
	if (ret < 0) {
		K1_RESTORE(oldk1);
		return ret;
	}
	stat[1] = 0;
	stat[2] = 0;
	stat[1] = D_00003B2C;
	stat[0] = info.poolSize;
	stat[2] = info.freeSize;
	K1_RESTORE(oldk1);
	return 0;
}

void *sceNetMallocInternal(unsigned int size)
{
	void *ret;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	ret = mallocSub(size);
	K1_RESTORE(oldk1);
	return ret;
}

void sceNetFreeInternal(void *p)
{
	int ret;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (p == 0)
		goto end;
	if (K1_USER() && (int)p < 0)
		goto end;
	ret = sceKernelFreeVpl(D_00003B28, p);
	if (ret < 0)
		Kprintf("sceNetFree: invalid ptr 0x%x, ret = 0x%08x\n", p, ret);
end:
	K1_RESTORE(oldk1);
}
