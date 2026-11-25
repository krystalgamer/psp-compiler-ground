/* cflags: -O2 -frename-registers */
#include "common.h"

typedef unsigned int SceSize;

void *memchr(const void *p, int c, SceSize n)
{
	unsigned char *cp = (unsigned char *)p;
	unsigned char cc = c;
	long nn = n;

	if (cp != NULL) {
		for (; nn > 0; nn--) {
			if (*cp == cc)
				return cp;
			cp++;
		}
	}
	return NULL;
}

void *memmove(void *dest, const void *src, SceSize n)
{
	unsigned char *p = dest;
	const unsigned char *s = src;
	long nn = n;

	if (dest == NULL)
		return NULL;
	if (p >= s) {
		for (nn--; nn >= 0; nn--)
			p[nn] = s[nn];
	} else {
		for (; nn > 0; nn--)
			*p++ = *s++;
	}
	return dest;
}

int memcmp(const void *s1, const void *s2, SceSize n)
{
	const unsigned char *c1 = s1;
	const unsigned char *c2 = s2;
	long nn = n;

	for (; nn > 0; nn--) {
		if (*c1 != *c2)
			return (*c1 < *c2) ? -1 : 1;
		c1++;
		c2++;
	}
	return 0;
}

void *memcpy(void *dest, const void *src, SceSize n)
{
	unsigned char *p;
	const unsigned char *q;
	long nn;

	if (dest == NULL)
		return NULL;
	p = dest;
	q = src;
	for (nn = n; nn > 0; nn--)
		*p++ = *q++;
	return dest;
}

void *memset(void *s, int c, SceSize n)
{
	if (s != NULL) {
		unsigned char *p = s;
		unsigned char cc = c;
		long nn = n;

		for (; nn > 0; nn--)
			*p++ = cc;
	}
	return s;
}

int bcmp(const void *s1, const void *s2, SceSize n)
{
	const unsigned char *c1 = s1;
	const unsigned char *c2 = s2;
	long nn = n;

	for (; nn > 0; nn--) {
		if (*c1 != *c2)
			return (*c1 < *c2) ? -1 : 1;
		c1++;
		c2++;
	}
	return 0;
}

void bcopy(const void *src, void *dest, SceSize n)
{
	memmove(dest, src, n);
}

void bzero(void *s, SceSize n)
{
	if (s != NULL) {
		unsigned char *p = s;
		long nn = n;

		for (; nn > 0; nn--)
			*p++ = 0;
	}
}
