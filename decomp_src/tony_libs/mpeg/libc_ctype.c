/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

unsigned int func_00007500(int type);
/* --- end declarations --- */

int func_000071CC(int x)
{
	if (x < 0)
		x = -x;
	return x;
}

char func_000071E0(char c)
{
	int f = D_00007B20[c + 1];

	if (f & 2)
		c -= 0x20;
	return c;
}

char func_0000720C(char c)
{
	int f = D_00007B20[c + 1];

	if (f & 1)
		c += 0x20;
	return c;
}

char func_00007238(int c)
{
	return D_00007B20[c + 1];
}

const char *func_0000724C(void)
{
	return D_00007B20 + 1;
}
