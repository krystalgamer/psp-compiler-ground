/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhocctl.h"
/* --- end declarations --- */

char func_00004D64(char c)
{
	int f = D_00006810[c + 1];

	if (f & 2)
		c -= 0x20;
	return c;
}

char func_00004D90(char c)
{
	int f = D_00006810[c + 1];

	if (f & 1)
		c += 0x20;
	return c;
}

char func_00004DBC(int c)
{
	return D_00006810[c + 1];
}

const char *func_00004DD0(void)
{
	return D_00006810 + 1;
}
