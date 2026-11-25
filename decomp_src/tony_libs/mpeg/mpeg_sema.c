/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

unsigned int func_00007500(int type);
/* --- end declarations --- */

int func_00005A58(int init, int max, const char *name, int *id)
{
	int ret = 0;
	int r;

	r = sceKernelCreateSema(name, 0, init, max, NULL);
	*id = r;
	if (r < 0)
		ret = 0x80000041;
	return ret;
}

int func_00005AB0(int id)
{
	int ret = 0;

	if (sceKernelDeleteSema(id) != 0)
		ret = 0x80000041;
	return ret;
}

int func_00005AE0(int id)
{
	int ret = 0;

	if (sceKernelWaitSema(id, 1, NULL) != 0)
		ret = 0x80000041;
	return ret;
}

int func_00005B14(int id, unsigned int timeout)
{
	int ret = 0;

	if (sceKernelWaitSema(id, 1, &timeout) != 0)
		ret = 0x80000041;
	return ret;
}

int func_00005B4C(int id)
{
	int ret = 0;

	if (sceKernelPollSema(id, 0) != 0)
		ret = 0x80000041;
	return ret;
}

int func_00005B7C(int id)
{
	int ret = 0;

	if (sceKernelSignalSema(id, 1) != 0)
		ret = 0x80000041;
	return ret;
}

int func_00005BAC(int id, int *count)
{
	SceKernelSemaInfo info;
	int ret = 0;

	if (sceKernelReferSemaStatus(id, &info) != 0)
		ret = 0x80000041;
	else
		*count = info.currentCount;
	return ret;
}
