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

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libc_mem", func_0000647C);

void *func_000064B4(void *dst, const void *src, int n)
{
	unsigned char *d = dst;
	const unsigned char *s = src;

	if (dst == NULL)
		return NULL;
	if (d >= s) {
		for (n--; n >= 0; n--)
			d[n] = s[n];
	} else {
		while (n > 0) {
			*d++ = *s++;
			n--;
		}
	}
	return dst;
}

int func_00006528(const void *a, const void *b, int n)
{
	const unsigned char *p = a;
	const unsigned char *q = b;

	for (; n > 0; n--) {
		if (*p != *q)
			return (*p < *q) ? -1 : 1;
		p++;
		q++;
	}
	return 0;
}

void *func_00006568(void *dst, const void *src, int n)
{
	unsigned char *d;
	const unsigned char *s;

	if (dst == NULL)
		return NULL;
	d = dst;
	s = src;
	while (n > 0) {
		*d++ = *s++;
		n--;
	}
	return dst;
}

void *func_0000659C(void *dst, int c, int n)
{
	unsigned char *d;
	unsigned char ch;

	if (dst != NULL) {
		ch = c;
		d = dst;
		while (n > 0) {
			*d++ = ch;
			n--;
		}
	}
	return dst;
}

int func_000065C8(const void *a, const void *b, int n)
{
	const unsigned char *p = a;
	const unsigned char *q = b;

	for (; n > 0; n--) {
		if (*p != *q)
			return (*p < *q) ? -1 : 1;
		p++;
		q++;
	}
	return 0;
}

void func_00006608(const void *src, void *dst, int n)
{
	memmove(dst, src, n);
}

void func_0000662C(void *p, int n)
{
	unsigned char *d = p;

	if (d == NULL)
		return;
	while (n > 0) {
		*d++ = 0;
		n--;
	}
}

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libc_mem", func_00006654);
