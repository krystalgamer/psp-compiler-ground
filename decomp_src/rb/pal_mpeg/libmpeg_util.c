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

unsigned int func_0000725C(int type, int ch)
{
	int sh = 0;

	if (type > 16)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	switch (D_00007AA0[type].mask) {
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
	return D_00007AA0[type].id | (ch << sh);
}

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/libmpeg_util", func_000072F0);

unsigned int func_00007504(int type)
{
	if (type > 16)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	return D_00007AA0[type].mask;
}

int func_00007530(void *p)
{
	unsigned char *c = (unsigned char *)p;

	return (unsigned short)((c[0] << 8) + c[1]);
}

unsigned int func_00007548(void *p)
{
	unsigned char *c = (unsigned char *)p;

	return (c[0] << 16) + (c[1] << 8) + c[2];
}

unsigned int func_00007568(void *p)
{
	unsigned char *c = (unsigned char *)p;

	return (c[0] << 24) + (c[1] << 16) + (c[2] << 8) + c[3];
}

INCLUDE_RODATA("tmp/asm/rb/pal_mpeg/nonmatchings/libmpeg_util", D_00007AA0);
