/* cflags: -O2 -frename-registers */
#include "common.h"

extern char _ctype_[129];

/* the class tests are statement expressions (an empty lexical block in DWARF) */
#define CTYPE(c) ({ (int)_ctype_[1 + (c)]; })

char toupper(char c)
{
	if (CTYPE(c) & 2)
		c -= 0x20;
	return c;
}

char tolower(char c)
{
	if (CTYPE(c) & 1)
		c += 0x20;
	return c;
}

int look_ctype_table(unsigned int c)
{
	return _ctype_[1 + c];
}

char *get_ctype_table(void)
{
	return _ctype_ + 1;
}
