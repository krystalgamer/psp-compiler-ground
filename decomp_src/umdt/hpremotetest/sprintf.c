/* cflags: -O2 -frename-registers */
#include "common.h"

typedef void (*putchar_handler)(void *, int);
typedef void *__gnuc_va_list;
typedef __gnuc_va_list va_list;

int prnt(putchar_handler pf, void *pfd, const char *fmt0, va_list argp);
static void sprintf_char(void *pfd, int ch);

int sprintf(char *outbuf, const char *format, ...)
{
	va_list ap;
	char *outp;
	int count;

	__builtin_va_start(ap, format);
	outp = outbuf;
	count = prnt(sprintf_char, &outp, format, ap);
	__builtin_va_end(ap);
	return count;
}

INCLUDE_ASM("tmp/asm/umdt/hpremotetest/nonmatchings/sprintf", prnt);

int vsprintf(char *outbuf, const char *format, va_list ap)
{
	char *outp = outbuf;

	return prnt(sprintf_char, &outp, format, ap);
}

static void sprintf_char(void *pfd, int ch)
{
	if (ch < 0x100)
		*(*(char **)pfd)++ = ch;
	else
		**(char **)pfd = '\0';
}

INCLUDE_RODATA("tmp/asm/umdt/hpremotetest/nonmatchings/sprintf", D_0000205C);

INCLUDE_RODATA("tmp/asm/umdt/hpremotetest/nonmatchings/sprintf", D_00002064);
