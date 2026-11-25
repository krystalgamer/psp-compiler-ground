/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhocctl.h"
/* --- end declarations --- */

void *func_00004DDC(const void *s, int c, int n)
{
	const unsigned char *p = s;
	const unsigned char *r;

	c &= 0xFF;
	if (p != NULL) {
		while (n > 0) {
			r = p;
			n--;
			if (*p++ == c)
				goto out;
		}
	}
	r = NULL;
out:
	return (void *)r;
}

void *func_00004E14(void *dst, const void *src, int n)
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

int func_00004E88(const void *a, const void *b, int n)
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

void *func_00004EC8(void *dst, const void *src, int n)
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

void *func_00004EFC(void *dst, int c, int n)
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

int func_00004F28(const void *a, const void *b, int n)
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

void func_00004F68(const void *src, void *dst, int n)
{
	memmove(dst, src, n);
}

void func_00004F8C(void *p, int n)
{
	unsigned char *d = p;

	if (d == NULL)
		return;
	while (n > 0) {
		n--;
		*d++ = 0;
	}
}
