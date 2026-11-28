/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
char *ttrFontInitEx();
int textCpy();
int ttrFontTerm();
void consPrintf(const char *, ...);
int sceCccSetErrorCharUTF8(int);
int sceCccEncodeUTF8(char **, int);
void *memset(void *, int, unsigned int);

/* separate flags: a combined test folds into an unsigned range check */
static inline int cccValid(int c)
{
	int a = c != 0;
	int b = ~c != 0;
	return a & b;
}
int cccUcs4ToUtf8(char *dst, int *src)
{
	char *p = dst;
	int i;

	sceCccSetErrorCharUTF8(0x3013);
	for (i = 0; cccValid(src[i]); i++)
		sceCccEncodeUTF8(&p, src[i]);
	*p = 0;
	consPrintf("%s : [%s]\n", "cccUcs4ToUtf8", dst);
	return 1;
}

int cccTtrToUcs4(int *dst, int a, int b, int c, int d)
{
	char *f = ttrFontInitEx(0, a, b, 0, c, d);
	int r = (unsigned char)f[0x3C4];
	textCpy(dst, f + 0x48);
	ttrFontTerm(f);
	return r;
}

int cccTtrToUtf8(char *dst, int a, int b, int c, int d)
{
	int buf[192];
	memset(buf, 0, 0x300);
	cccTtrToUcs4(buf, a, b, c, d);
	cccUcs4ToUtf8(dst, buf);
	return 1;
}
