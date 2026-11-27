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

int func_000071D0(int x)
{
	if (x < 0)
		x = -x;
	return x;
}

char func_000071E4(char c)
{
	int f = D_00007B30[c + 1];

	if (f & 2)
		c -= 0x20;
	return c;
}

char func_00007210(char c)
{
	int f = D_00007B30[c + 1];

	if (f & 1)
		c += 0x20;
	return c;
}

char func_0000723C(int c)
{
	return D_00007B30[c + 1];
}

const char *func_00007250(void)
{
	return D_00007B30 + 1;
}
