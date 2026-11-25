/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "inetlib.h"
/* --- end declarations --- */

int func_0002CCAC(char *buf, const char *fmt, ...)
{
	va_list ap;
	char *p = buf;
	int ret;

	va_start(ap, fmt);
	ret = vsnprintf(func_0002D420, &p, fmt, ap);
	va_end(ap);
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/libc_printf", func_0002CCF8);

void func_0002D420(char **pp, int c)
{
	if (c < 0x100)
		*(*pp)++ = c;
	else
		**pp = '\0';
}

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet_inet/nonmatchings/libc_printf", D_0002E290);

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet_inet/nonmatchings/libc_printf", D_0002E298);
