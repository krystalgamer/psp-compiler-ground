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

void *func_00006480(const void *s, int c, int n)
{
	const unsigned char *p = s;
	unsigned char ch = c;

	if (p != NULL) {
		for (; n > 0; n--) {
			if (*p == ch)
				return (void *)p;
			p++;
		}
	}
	return NULL;
}

void *func_000064B8(void *dst, const void *src, int n)
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

int func_0000652C(const void *a, const void *b, int n)
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

void *func_0000656C(void *dst, const void *src, int n)
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

void *func_000065A0(void *dst, int c, int n)
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

int func_000065CC(const void *a, const void *b, int n)
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

void func_0000660C(const void *src, void *dst, int n)
{
	memmove(dst, src, n);
}

void func_00006630(void *p, int n)
{
	unsigned char *d = p;

	if (d == NULL)
		return;
	while (n > 0) {
		*d++ = 0;
		n--;
	}
}

char *strcat(char *dest, const char *src)
{
	char *s1 = dest;
	const char *s2 = src;
	char *w;

	if (dest == NULL || src == NULL)
		return NULL;

	if (dest + strlen(dest) != src + strlen(src)) {
		while (*s1++)
			;
		s1--;
		while ((*s1++ = *s2++) != 0)
			;
		w = dest;
		return w;
	}
	return NULL;
}
