/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

unsigned int func_00007500(int type);
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libmpeg_util", func_00007258);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libmpeg_util", func_000072EC);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libmpeg_util", func_00007500);

int func_0000752C(void *p)
{
	unsigned char *c = (unsigned char *)p;

	return (unsigned short)((c[0] << 8) + c[1]);
}

unsigned int func_00007544(void *p)
{
	unsigned char *c = (unsigned char *)p;

	return (c[0] << 16) + (c[1] << 8) + c[2];
}

unsigned int func_00007564(void *p)
{
	unsigned char *c = (unsigned char *)p;

	return (c[0] << 24) + (c[1] << 16) + (c[2] << 8) + c[3];
}

INCLUDE_RODATA("tmp/asm/tony_libs/mpeg/nonmatchings/libmpeg_util", D_00007A90);
