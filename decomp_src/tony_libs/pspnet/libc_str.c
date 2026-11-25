/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"
/* --- end declarations --- */

int func_00007D60(const char *s1, const char *s2)
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

char *func_00007DE0(const char *s, char c)
{
	if (s == NULL)
		return NULL;
	do {
		if (*s == c)
			return (char *)s;
	} while (*s++ != '\0');
	return NULL;
}

char *func_00007E10(const char *s, char c)
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

int func_00007E58(const char *s1, const char *s2, int n)
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

char *func_00007EF0(char *dst, const char *src, int n)
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

char *func_00007F6C(const char *s, char c)
{
	if (s == NULL)
		return NULL;
	do {
		if (*s == c)
			return (char *)s;
	} while (*s++ != '\0');
	return NULL;
}

char *func_00007F9C(char *dst, const char *src)
{
	char *p = dst;

	if (dst == NULL || src == NULL)
		return NULL;
	while ((*p++ = *src++) != '\0')
		;
	return dst;
}

int func_00007FD4(const char *s)
{
	int n = 0;

	if (s == NULL)
		return 0;
	while (*s++ != '\0')
		n++;
	return n;
}
