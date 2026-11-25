/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

extern const StreamTypeInfo D_000078F4[];
/* --- end declarations --- */

unsigned int func_00007258(int type, int ch)
{
	int sh = 0;

	if (type > 16)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	switch (D_00007A90[type].mask) {
	case 0xFF000000:
		sh = 24;
		break;
	case 0xFFFF0000:
		sh = 16;
		break;
	case 0xFFFFFF00:
		sh = 8;
		break;
	case 0xFFFFFFFF:
		break;
	default:
		return 0;
	}
	return D_00007A90[type].id | (ch << sh);
}

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/libmpeg_util", func_000072EC);

unsigned int func_00007500(int type)
{
	if (type > 16)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	return D_00007A90[type].mask;
}

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
