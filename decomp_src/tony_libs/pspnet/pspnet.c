/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

int sceNetInit(int poolsize, int calloutprio, int calloutstack, int netintrprio, int netintrstack)
{
	int ret;

	func_00007798(sceKernelGetSystemTimeLow());
	if ((ret = func_00007738(poolsize)) < 0)
		goto fail;
	sceNetIfhandle_lib_0FB8AE0D();
	if ((ret = func_00002B34(calloutprio, calloutstack)) < 0)
		goto fail;
	if ((ret = func_00003438()) < 0)
		goto fail;
	if ((ret = func_00002FC4()) < 0)
		goto fail;
	if ((ret = func_00001F0C()) < 0)
		goto fail;
	if ((ret = func_00001A00(netintrprio, netintrstack)) < 0)
		goto fail;
	func_000057D8();
	func_0000426C(8);
	return 0;
fail:
	func_00001B7C();
	func_00002300();
	func_00003028();
	func_0000348C();
	func_000028D0();
	func_00007778();
	return ret;
}

int sceNetTerm(void)
{
	func_00001B7C();
	func_00002300();
	func_00003028();
	func_0000348C();
	func_000028D0();
	func_00007778();
	return 0;
}
