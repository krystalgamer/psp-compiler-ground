/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc_auth.h"
/* --- end declarations --- */

void func_000038D0(int *p, int v)
{
	*p = v;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/lock", func_000038D8);

void func_0000392C(void)
{
	if (D_00003ED0 > 0)
		sceKernelDeleteSema(D_00003ED0);
	D_00003ED0 = -1;
}

int func_00003968(void)
{
	int thid;

	thid = sceKernelGetThreadId();
	if (thid == D_00003ED4)
		return 0;
	sceKernelWaitSema(D_00003ED0, 1, 0);
	D_00003ED4 = thid;
	return 1;
}

void func_000039C4(int locked)
{
	if (locked) {
		D_00003ED4 = -1;
		sceKernelSignalSema(D_00003ED0, 1);
	}
}
