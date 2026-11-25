/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

unsigned int func_00007500(int type);
/* --- end declarations --- */

int module_start(void)
{
	if (func_00005BF4() < 0)
		return 1;
	if (func_000060E0() < 0)
		return 1;
	return 0;
}

int module_stop(void)
{
	func_00005E54();
	func_00006314();
	return 0;
}
