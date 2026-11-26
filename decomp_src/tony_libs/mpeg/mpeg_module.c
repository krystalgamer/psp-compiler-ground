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
int __tolower_i(int c) __asm__("func_0000720C");
extern const char D_00007994[];

extern const StreamTypeInfo D_000078F4[];
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
