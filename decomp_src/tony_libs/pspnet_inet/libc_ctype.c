/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "inetlib.h"
/* --- end declarations --- */

char func_0002C7B4(char c)
{
	int f = D_0002EAB0[c + 1];

	if (f & 2)
		c -= 0x20;
	return c;
}

char func_0002C7E0(char c)
{
	int f = D_0002EAB0[c + 1];

	if (f & 1)
		c += 0x20;
	return c;
}

char func_0002C80C(int c)
{
	return D_0002EAB0[c + 1];
}

const char *func_0002C820(void)
{
	return D_0002EAB0 + 1;
}
