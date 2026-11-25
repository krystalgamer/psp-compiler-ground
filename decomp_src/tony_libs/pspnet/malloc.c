/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

int func_00007738(int poolsize)
{
	int ret;

	ret = sceNetIfhandle_lib_0C391E9F(poolsize);
	if (ret < 0) {
		sceNetIfhandle_lib_29ED84C5();
		return ret;
	}
	return 0;
}

int func_00007778(void)
{
	sceNetIfhandle_lib_29ED84C5();
	return 0;
}
