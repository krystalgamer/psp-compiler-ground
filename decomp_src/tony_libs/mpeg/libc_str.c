/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

unsigned int func_00007500(int type);
/* --- end declarations --- */

char *func_000066F4(const char *s, char c)
{
	if (s == NULL)
		return NULL;
	do {
		if (*s == c)
			return (char *)s;
	} while (*s++ != '\0');
	return NULL;
}

int func_00006724(const char *s1, const char *s2)
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

int func_000067A4(const char *s1, const char *s2)
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

int func_0000684C(const char *s, const char *reject)
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

char *func_000068B8(const char *s, char c)
{
	if (s == NULL)
		return NULL;
	do {
		if (*s == c)
			return (char *)s;
	} while (*s++ != '\0');
	return NULL;
}

char *func_000068E8(const char *s, char c)
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

int func_00006930(const char *s)
{
	int n = 0;

	if (s == NULL)
		return 0;
	while (*s++ != '\0')
		n++;
	return n;
}

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libc_str", func_00006964);

int func_000069CC(const char *s1, const char *s2, int n)
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

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libc_str", func_00006A64);

char *func_00006B28(char *dst, const char *src, int n)
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

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libc_str", func_00006BA4);

char *func_00006BFC(const char *s, char c)
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

int func_00006C44(const char *s, const char *accept)
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

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libc_str", func_00006CB0);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libc_str", func_00006D14);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libc_str", func_00006DE8);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libc_str", func_00006FB8);

char *func_00007140(char *dst, const char *src)
{
	char *p = dst;

	if (dst == NULL || src == NULL)
		return NULL;
	while ((*p++ = *src++) != '\0')
		;
	return dst;
}

char *func_00007178(char *s, const char *delim)
{
	return strtok_r(s, delim, &D_00007D80);
}

int func_00007198(const char *s, int *out)
{
	char *end;

	*out = strtol(s, &end, 10);
	return (int)end;
}
