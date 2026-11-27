/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

static __inline__ int __strtok_find(const char *d, char c)
{
	int sc;

	while ((sc = *d++) != '\0') {
		if (sc == c)
			return sc;
	}
	return 0;
}
int __tolower_i(int c) __asm__("func_00007210");
extern const char D_000079A4[];

extern const StreamTypeInfo D_00007904[];
/* --- end declarations --- */

int func_00005A5C(int init, int max, const char *name, int *id)
{
	int ret = 0;
	int r;

	r = sceKernelCreateSema(name, 0, init, max, NULL);
	*id = r;
	if (r < 0)
		ret = 0x80000041;
	return ret;
}

int func_00005AB4(int id)
{
	int ret = 0;

	if (sceKernelDeleteSema(id) != 0)
		ret = 0x80000041;
	return ret;
}

int func_00005AE4(int id)
{
	int ret = 0;

	if (sceKernelWaitSema(id, 1, NULL) != 0)
		ret = 0x80000041;
	return ret;
}

int func_00005B18(int id, unsigned int timeout)
{
	int ret = 0;

	if (sceKernelWaitSema(id, 1, &timeout) != 0)
		ret = 0x80000041;
	return ret;
}

int func_00005B50(int id)
{
	int ret = 0;

	if (sceKernelPollSema(id, 0) != 0)
		ret = 0x80000041;
	return ret;
}

int func_00005B80(int id)
{
	int ret = 0;

	if (sceKernelSignalSema(id, 1) != 0)
		ret = 0x80000041;
	return ret;
}

int func_00005BB0(int id, int *count)
{
	SceKernelSemaInfo info;
	int ret = 0;

	if (sceKernelReferSemaStatus(id, &info) != 0)
		ret = 0x80000041;
	else
		*count = info.currentCount;
	return ret;
}
