/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

int func_00003438(void)
{
	D_0000A0A4 = sceKernelCreateSema("SceNetSpl", 0, 1, 1, 0);
	if (D_0000A0A4 < 0)
		return D_0000A0A4;
	D_0000B02C = -1;
	return 0;
}

void func_0000348C(void)
{
	if (D_0000A0A4 >= 0)
		sceKernelDeleteSema(D_0000A0A4);
	D_0000A0A4 = -1;
}

int _sce_pspnet_spllock(void)
{
	int thid;

	thid = sceKernelGetThreadId();
	if (thid == D_0000B02C)
		return 0;
	sceKernelWaitSema(D_0000A0A4, 1, 0);
	D_0000B02C = thid;
	return 1;
}

void _sce_pspnet_splunlock(int locked)
{
	if (locked) {
		D_0000B02C = -1;
		sceKernelSignalSema(D_0000A0A4, 1);
	}
}

int sceNet_lib_6DC71518(void)
{
	return D_0000B02C;
}
