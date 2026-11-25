/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;
extern const char D_00007994[];

extern const StreamTypeInfo D_000078F4[];
/* --- end declarations --- */

INCLUDE_RODATA("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_psmf", D_00007994);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_psmf", sceMpegQueryStreamOffset);

int func_00001100(SceMpeg *mp)
{
	if (strcmp(mp->sys->magic, D_00007994) != 0)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	return 0;
}

int sceMpegQueryStreamSize(void *addr, unsigned int *size)
{
	int ret = 0;

	*size = func_00007564((char *)addr + 12);
	if ((*size & 0x7FF) != 0) {
		*size = 0;
		ret = SCE_MPEG_ERROR_INVALID_VALUE;
	}
	return ret;
}

int func_00001180(void *addr)
{
	char *ver = (char *)addr + 4;

	if (memcmp(ver, "0012", 4) == 0)
		return 0;
	if (memcmp(ver, "0013", 4) == 0)
		return 1;
	if (memcmp(ver, "0014", 4) == 0)
		return 2;
	return -1;
}
