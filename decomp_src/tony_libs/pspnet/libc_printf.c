/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

int func_00008008(char *buf, const char *fmt, ...)
{
	va_list ap;
	char *p = buf;
	int ret;

	va_start(ap, fmt);
	ret = func_00008054(func_0000877C, &p, fmt, ap);
	va_end(ap);
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/libc_printf", func_00008054);

void func_0000877C(char **pp, int c)
{
	if (c < 0x100)
		*(*pp)++ = c;
	else
		**pp = '\0';
}

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet/nonmatchings/libc_printf", D_00009DA0);

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet/nonmatchings/libc_printf", D_00009DA8);

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet/nonmatchings/libc_printf", D_00009F8C);
