/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

static __inline__ int __strtok_find(const char *d, char c)
{
	int sc;

	while ((sc = *d++) != '\0') {
		if (sc == c)
			return sc;
	}
	return 0;
}
int __tolower_i(int c) __asm__("func_00007210");
extern const char D_000079A4[];

extern const StreamTypeInfo D_00007904[];
/* --- end declarations --- */

INCLUDE_RODATA("tmp/asm/rb/pal_mpeg/nonmatchings/mpeg_psmf", D_000079A4);

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/mpeg_psmf", sceMpegQueryStreamOffset);

int func_00001104(SceMpeg *mp)
{
	if (strcmp(mp->sys->magic, D_000079A4) != 0)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	return 0;
}

int sceMpegQueryStreamSize(void *addr, unsigned int *size)
{
	int ret = 0;

	*size = func_00007568((char *)addr + 12);
	if ((*size & 0x7FF) != 0) {
		*size = 0;
		ret = SCE_MPEG_ERROR_INVALID_VALUE;
	}
	return ret;
}

int func_00001184(void *addr)
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
