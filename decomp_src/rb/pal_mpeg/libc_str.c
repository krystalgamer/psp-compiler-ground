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

char *func_000066F8(const char *s, char c)
{
	if (s == NULL)
		return NULL;
	do {
		if (*s == c)
			return (char *)s;
	} while (*s++ != '\0');
	return NULL;
}

int func_00006728(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL) {
		if (s1 == s2)
			return 0;
		return (s1 == NULL) ? -1 : 1;
	}
	while (*s1 == *s2++) {
		if (*s1++ == '\0')
			return 0;
	}
	return *s1 - *(s2 - 1);
}

int func_000067A8(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL) {
		if (s1 == s2)
			return 0;
		return (s1 == NULL) ? -1 : 1;
	}
	while (tolower(*s1) == tolower(*s2++)) {
		if (*s1++ == '\0')
			return 0;
	}
	return tolower(*s1) - tolower(*(s2 - 1));
}

int func_00006850(const char *s, const char *reject)
{
	const char *p;
	const char *r;

	for (p = s; *p != '\0'; p++) {
		for (r = reject; *r != '\0'; r++) {
			if (*r == *p)
				break;
		}
		if (*r != '\0')
			break;
	}
	return p - s;
}

char *func_000068BC(const char *s, char c)
{
	if (s == NULL)
		return NULL;
	do {
		if (*s == c)
			return (char *)s;
	} while (*s++ != '\0');
	return NULL;
}

char *func_000068EC(const char *s, char c)
{
	const char *p = s;

	if (s == NULL)
		return NULL;
	while (*p++ != '\0')
		;
	p--;
	do {
		if (*p == c)
			return (char *)p;
	} while (s < p--);
	return NULL;
}

int func_00006934(const char *s)
{
	int n = 0;

	if (s == NULL)
		return 0;
	while (*s++ != '\0')
		n++;
	return n;
}

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/libc_str", func_00006968);

int func_000069D0(const char *s1, const char *s2, int n)
{
	if (s1 == NULL || s2 == NULL) {
		if (s1 == s2)
			return 0;
		return (s1 == NULL) ? -1 : 1;
	}
	while (--n >= 0 && *s1 == *s2++) {
		if (*s1++ == '\0')
			return 0;
	}
	return (n < 0) ? 0 : *s1 - *(s2 - 1);
}

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/libc_str", func_00006A68);

char *func_00006B2C(char *dst, const char *src, int n)
{
	char *p = dst;
	int i;

	if (dst == NULL || src == NULL)
		return NULL;
	for (i = 0; i < n; i++) {
		if ((*p++ = *src++) == '\0') {
			for (i++; i < n; i++)
				*p++ = '\0';
			return dst;
		}
	}
	return dst;
}

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/libc_str", func_00006BA8);

char *func_00006C00(const char *s, char c)
{
	const char *p = s;

	if (s == NULL)
		return NULL;
	while (*p++ != '\0')
		;
	p--;
	do {
		if (*p == c)
			return (char *)p;
	} while (s < p--);
	return NULL;
}

int func_00006C48(const char *s, const char *accept)
{
	const char *p;
	const char *a;

	for (p = s; *p != '\0'; p++) {
		for (a = accept; *a != '\0'; a++) {
			if (*a == *p)
				break;
		}
		if (*a == '\0')
			break;
	}
	return p - s;
}

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/libc_str", func_00006CB4);

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/libc_str", func_00006D18);

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/libc_str", func_00006DEC);

unsigned long func_00006FBC(const char *s, char **endptr, int base)
{
	unsigned long v = 0;
	int c;
	int f;
	unsigned int d;

	if (s == NULL)
		return 0;
	while (__ctype_flags(*s) & 8)
		s++;
	if ((unsigned int)(base - 2) >= 35)
		base = 0;
	if (base == 0)
		base = 10;
	if (*s == '0') {
		s++;
		switch (*s) {
		case 'x':
		case 'X':
			s++;
			base = 16;
			break;
		case 'b':
		case 'B':
			s++;
			base = 2;
			break;
		}
	} else if (toupper(*s) == 'O') {
		s++;
		base = 8;
	}
	for (;;) {
		c = *s;
		f = __ctype_flags(c);
		s++;
		if (f & 4)
			d = c - '0';
		else if (__ctype_flags(c) & 3)
			d = __tolower_i(c) - 'a' + 10;
		else
			d = 9999999;
		if (d >= (unsigned int)base)
			break;
		v *= base;
		v += d;
	}
	if (endptr != NULL)
		*endptr = (char *)s - 1;
	return v;
}

char *func_00007144(char *dst, const char *src)
{
	char *p = dst;

	if (dst == NULL || src == NULL)
		return NULL;
	while ((*p++ = *src++) != '\0')
		;
	return dst;
}

char *func_0000717C(char *s, const char *delim)
{
	return strtok_r(s, delim, &D_00007D80);
}

int func_0000719C(const char *s, int *out)
{
	char *end;

	*out = strtol(s, &end, 10);
	return (int)end;
}
