/* cflags: -O2 -frename-registers */
#include "common.h"

typedef unsigned int SceSize;

int tolower(int c);
SceSize strlen(const char *ss);
char *strtok_r(char *s1, const char *s2, char **lasts);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/string", strcat);

int strcmp(const char *s1, const char *s2)
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
	return *s1 - s2[-1];
}

int strcasecmp(const char *s1, const char *s2)
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
	return tolower(*s1) - tolower(s2[-1]);
}

char *index(const char *ss, int cc)
{
	char *s = (char *)ss;
	char c = cc;

	if (s == NULL)
		return NULL;
	for (;;) {
		if (*s == c)
			return s;
		if (*s++ == '\0')
			return NULL;
	}
}

char *rindex(const char *ss, int cc)
{
	char *s = (char *)ss;
	char c = cc;
	char *w;

	if (s == NULL)
		return NULL;
	while (*s++)
		;
	s--;
	do {
		if (*s == c)
			return s;
	} while (ss < s--);
	return NULL;
}

SceSize strlen(const char *ss)
{
	const char *s = ss;
	SceSize count = 0;

	if (s == NULL)
		return 0;
	while (*s++)
		count++;
	return count;
}

char *strncat(char *dest, const char *src, SceSize nn)
{
	char *s1 = dest;
	const char *s2 = src;
	int n = nn;
	char *w = NULL;

	if (dest == NULL || src == NULL)
		return w;
	while (*s1++)
		;
	s1--;
	while ((*s1++ = *s2++) != 0) {
		if (--n < 0) {
			s1[-1] = '\0';
			break;
		}
	}
	return dest;
}

int strncmp(const char *s1, const char *s2, SceSize nn)
{
	int n = nn;

	if (s1 == NULL || s2 == NULL) {
		if (s1 == s2)
			return 0;
		return (s1 == NULL) ? -1 : 1;
	}
	while (--n >= 0 && *s1 == *s2++) {
		if (*s1++ == '\0')
			return 0;
	}
	return (n < 0) ? 0 : *s1 - s2[-1];
}

int strncasecmp(const char *s1, const char *s2, SceSize nn)
{
	int n = nn;

	if (s1 == NULL || s2 == NULL) {
		if (s1 == s2)
			return 0;
		return (s1 == NULL) ? -1 : 1;
	}
	while (--n >= 0 && tolower(*s1) == tolower(*s2++)) {
		if (*s1++ == '\0')
			return 0;
	}
	return (n < 0) ? 0 : tolower(*s1) - tolower(s2[-1]);
}

char *strncpy(char *dest, const char *src, SceSize nn)
{
	char *s1 = dest;
	const char *s2 = src;
	int n = nn;
	int i;
	char *w = NULL;

	if (dest == NULL || src == NULL)
		return w;
	for (i = 0; i < n; i++) {
		if ((*s1++ = *s2++) == '\0') {
			for (i++; i < n; i++)
				*s1++ = '\0';
			return dest;
		}
	}
	return dest;
}

char *strchr(const char *ss, int cc)
{
	char *s = (char *)ss;
	char c = cc;

	if (s == NULL)
		return NULL;
	for (;;) {
		if (*s == c)
			return s;
		if (*s++ == '\0')
			return NULL;
	}
}

int strcspn(const char *s1, const char *s2)
{
	const char *s = s1;
	const char *k;
	const char *p, *w;

	for (; *s != '\0'; s++) {
		for (k = s2; *k != '\0'; k++) {
			if (*k == *s)
				break;
		}
		if (*k != '\0')
			break;
	}
	return s - s1;
}

char *strpbrk(const char *s1, const char *s2)
{
	char *s = (char *)s1;
	char *k;

	for (; *s != '\0'; s++) {
		for (k = (char *)s2; *k != '\0'; k++) {
			if (*k == *s)
				return s;
		}
	}
	return NULL;
}

char *strrchr(const char *ss, int cc)
{
	char *s = (char *)ss;
	char c = cc;
	char *w;

	if (s == NULL)
		return NULL;
	while (*s++)
		;
	s--;
	do {
		if (*s == c)
			return s;
	} while (ss < s--);
	return NULL;
}

int strspn(const char *s1, const char *s2)
{
	const char *s = s1;
	const char *k;

	for (; *s != '\0'; s++) {
		for (k = s2; *k != '\0'; k++) {
			if (*k == *s)
				break;
		}
		if (*k == '\0')
			break;
	}
	return s - s1;
}

char *strstr(const char *s1, const char *s2)
{
	const char *w1, *w2;

	if (*s2 == '\0')
		return (char *)s1;
	while (*s1 != '\0') {
		for (w1 = s1, w2 = s2; ; w1++, w2++) {
			if (*w2 == '\0')
				return (char *)s1;
			if (*w1 == '\0')
				return NULL;
			if (*w1 != *w2)
				break;
		}
		s1++;
	}
	return NULL;
}

char *strtok_r(char *s1, const char *s2, char **lasts)
{
	char *s;
	char *d;
	char *p, *t;
	char *w;
	int mark;
	char c;

	s = s1;
	if (s == NULL) {
		s = *lasts;
		if (s == NULL)
			return NULL;
	}
	while ((c = *s++) != '\0') {
		mark = 0;
		for (d = (char *)s2; *d != '\0'; d++) {
			if (c == *d) {
				mark = 1;
				break;
			}
		}
		if (!mark)
			break;
	}
	if (c == '\0') {
		*lasts = NULL;
		return NULL;
	}
	t = s - 1;
	while ((c = *s++) != '\0') {
		for (d = (char *)s2; *d != '\0'; d++) {
			if (c == *d) {
				s[-1] = '\0';
				*lasts = s;
				return t;
			}
		}
	}
	*lasts = NULL;
	return t;
}

char *strcpy(char *dest, const char *src)
{
	char *s1 = dest;
	const char *s2 = src;
	char *w = NULL;

	if (dest == NULL || src == NULL)
		return w;
	while ((*s1++ = *s2++) != 0)
		;
	return dest;
}

extern char *D_003198C8; /* strtok's static os */
char *strtok(char *s1, const char *s2)
{
	return strtok_r(s1, s2, &D_003198C8);
}
