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

int func_000060E4(void)
{
	int needed;
	int ret;

	D_00007CC0 = &D_00007D00;
	memset(&D_00007D00, 0, sizeof(AudioCtx));
	ret = func_0000615C(&needed, 0);
	if (ret != 0)
		return ret;
	ret = sceAudiocodecGetEDRAM(D_00007CC0, 0x1000);
	if (ret == 0)
		return 0;
	D_00007CC0->edram = 0;
	return ret;
}

int func_0000615C(int *needed, int type)
{
	int ret;
	int k = (type == 3);

	D_00007CC0->unk30 = 1;
	D_00007CC0->p28 = D_00007A94[k];
	D_00007CC0->p2C = D_00007A98[k];
	D_00007CC0->unk14 = 1;
	ret = sceAudiocodecCheckNeedMem(D_00007CC0, 0x1000);
	*needed = D_00007CC0->neededMem;
	return ret;
}

int func_0000620C(AudioCtx *ctx, int edram, unsigned int size, AudioParam2 *p2, AudioParam4 *p4)
{
	int ret;

	func_00005AE4(D_00007D88);
	ctx->edram = edram;
	ctx->unk30 = 1;
	ctx->p28 = *p2;
	ctx->p2C = *p4;
	ctx->unk14 = 1;
	ret = sceAudiocodecCheckNeedMem(ctx, 0x1000);
	if (ret != 0)
		goto err;
	if (size < (unsigned int)ctx->neededMem) {
		ret = 0x807F0001;
		func_00005B80(D_00007D88);
		return ret;
	}
	ret = sceAudiocodecInit(ctx, 0x1000);
	if (ret == 0) {
		func_00005B80(D_00007D88);
		return 0;
	}
err:
	func_00005B80(D_00007D88);
	return ret;
}

void func_00006318(void)
{
	if (D_00007CC0->edram != 0)
		sceAudiocodecReleaseEDRAM(D_00007CC0);
}

int func_00006350(int *needed, int type)
{
	int ret;

	func_00005AE4(D_00007D88);
	ret = func_0000615C(needed, type);
	func_00005B80(D_00007D88);
	return ret;
}

int func_000063AC(void)
{
	return D_00007CC0->edram;
}

int func_000063BC(AudioCtx *ctx)
{
	int ret;

	func_00005AE4(D_00007D88);
	ret = sceAudiocodecDecode(ctx, 0x1000);
	if (ret != 0) {
		func_00005B80(D_00007D88);
		return ret;
	}
	func_00005B80(D_00007D88);
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/pal_mpeg/nonmatchings/mpeg_audio", D_00007A94);

INCLUDE_RODATA("tmp/asm/rb/pal_mpeg/nonmatchings/mpeg_audio", D_00007A98);
