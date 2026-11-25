/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"
/* --- end declarations --- */

char func_000087A4(char c)
{
	int f = D_0000A0CC[c + 1];

	if (f & 2)
		c -= 0x20;
	return c;
}

char func_000087D0(char c)
{
	int f = D_0000A0CC[c + 1];

	if (f & 1)
		c += 0x20;
	return c;
}

char func_000087FC(int c)
{
	return D_0000A0CC[c + 1];
}

const char *func_00008810(void)
{
	return D_0000A0CC + 1;
}
