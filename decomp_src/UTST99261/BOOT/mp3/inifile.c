#include "common.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static inline int IsCrlf(char c)
{
	return c == '\r' || c == '\n';
}

static inline int IsBlank(char c)
{
	return c == ' ' || c == '\t';
}

static int SearchCrlf(char *p)
{
	int count;

	count = 0;
	while (*p != 0 && !IsCrlf(*p)) {
		p++;
		count++;
	}
	return count;
}

static char *SkipCrlf(char *p)
{
	while (*p != 0 && IsCrlf(*p))
		p++;
	return p;
}

#define SkipBlank SkipBlank_B490

static char *SkipBlank(char *p)
{
	while (*p != 0 && IsBlank(*p))
		p++;
	return p;
}

void strcpynlower(char *d, char *s, int n)
{
	int i;
	char c;

	for (i = 0; i < n - 1; i++) {
		c = *s++;
		if (c == 0)
			break;
		if (c == '\\')
			c = '/';
		*d++ = tolower(c);
	}
	*d = 0;
}

char *ExtractFileExt(char *name)
{
	char *p;
	int count;
	int size;

	p = name;
	size = strlen(name);
	for (count = size - 1; count >= 0; count--) {
		if (p[count] == '.')
			break;
	}
	if (count >= 0)
		return &p[count + 1];
	return &p[size];
}

static char *SearchSection(char *p, char *section)
{
	int size;
	int i;
	char c;

	if (section == NULL)
		return p;
	size = strlen(section);
	for (;;) {
		if (*p == 0)
			return NULL;
		if (*p == '[') {
			p++;
			for (i = 0; i < size; i++) {
				c = *p++;
				c = tolower(c);
				if (c != tolower(section[i]))
					break;
			}
			if (i == size && *p == ']')
				return SkipCrlf(p + SearchCrlf(p));
		}
		p = SkipCrlf(p + SearchCrlf(p));
	}
}

static char *GetIdentString(char *dst, char *p)
{
	int size;

	size = 0;
	dst[0] = 0;
	for (;;) {
		if (*p == 0 || IsCrlf(*p))
			break;
		if (*p == '=') {
			while (size > 0) {
				if (!IsBlank(dst[size - 1]))
					break;
				size--;
			}
			dst[size] = 0;
			break;
		}
		dst[size++] = *p++;
		dst[size] = 0;
	}
	return p;
}

static char *SearchIdent(char *p, char *ident)
{
	int size;
	int i;
	char name[256];
	char c;

	size = strlen(ident);
	for (;;) {
		p = SkipBlank(p);
		c = *p;
		if (c == 0)
			break;
		if (c == '[')
			break;
		if (c != '#' && !IsCrlf(c)) {
			p = GetIdentString(name, p);
			if (strlen(name) == size) {
				for (i = 0; i < size; i++) {
					if (tolower(name[i]) != tolower(ident[i]))
						break;
				}
				if (i == size) {
					p = SkipBlank(p);
					return SkipBlank(p + 1);
				}
			}
		}
		p = SkipCrlf(p + SearchCrlf(p));
	}
	return NULL;
}

int GetIniString(char *dst, char *buffer, char *section, char *ident)
{
	int size;

	*dst = 0;
	buffer = SearchSection(buffer, section);
	if (buffer == NULL)
		return 0;
	buffer = SearchIdent(buffer, ident);
	if (buffer == NULL)
		return 0;
	size = 0;
	for (;;) {
		if (*buffer == 0 || IsCrlf(*buffer))
			break;
		if (*buffer == '\\' && IsCrlf(buffer[1])) {
		again:
			buffer = SkipCrlf(buffer + 1);
			if (*buffer == '#') {
				do {
					buffer++;
					if (*buffer == 0)
						goto end;
				} while (!IsCrlf(*buffer));
				goto again;
			}
			if (*buffer != ' ' && *buffer != '\t')
				break;
		}
		*dst++ = *buffer++;
		size++;
	}
end:
	*dst = 0;
	return size;
}

static int GetIdentCount(char *p)
{
	int count;
	char c;

	count = 0;
	for (;;) {
		p = SkipBlank(p);
		c = *p;
		if (c == 0)
			break;
		if (c == '[')
			break;
		if (c != '#' && !IsCrlf(c))
			count++;
		p = SkipCrlf(p + SearchCrlf(p));
	}
	return count;
}

#ifdef NON_MATCHING
/* the index test block is laid out inline; the original has it after the loop's back edge */
static int GetIdent(char *dst, char *p, int index)
{
	int i;
	int size;
	char c;

	*dst = 0;
	i = 0;
	for (;;) {
		p = SkipBlank(p);
		c = *p;
		if (c == 0)
			break;
		if (c == '[')
			break;
		if (c != '#' && !IsCrlf(c)) {
			if (i == index) {
				GetIdentString(dst, p);
				size = strlen(dst);
				return size;
			}
			i++;
		}
		p = SkipCrlf(p + SearchCrlf(p));
	}
	return 0;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/inifile", GetIdent);
#endif

int GetIniIdentCount(char *buffer, char *section)
{
	buffer = SearchSection(buffer, section);
	if (buffer == NULL)
		return 0;
	return GetIdentCount(buffer);
}

int GetIniIdentString(char *dst, char *buffer, char *section, int index)
{
	buffer = SearchSection(buffer, section);
	if (buffer == NULL)
		return 0;
	return GetIdent(dst, buffer, index);
}
