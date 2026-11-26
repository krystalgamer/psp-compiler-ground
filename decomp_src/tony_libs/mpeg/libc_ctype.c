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
