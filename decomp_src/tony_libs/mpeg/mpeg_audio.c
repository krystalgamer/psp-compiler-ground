/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;
extern const char D_00007994[];

extern const StreamTypeInfo D_000078F4[];
/* --- end declarations --- */

int func_000060E0(void)
{
	int needed;
	int ret;

	D_00007CC0 = &D_00007D00;
	memset(&D_00007D00, 0, sizeof(AudioCtx));
	ret = func_00006158(&needed, 0);
	if (ret != 0)
		return ret;
	ret = sceAudiocodecGetEDRAM(D_00007CC0, 0x1000);
	if (ret == 0)
		return 0;
	D_00007CC0->edram = 0;
	return ret;
}

int func_00006158(int *needed, int type)
{
	int ret;
	int k = (type == 3);

	D_00007CC0->unk30 = 1;
	D_00007CC0->p28 = D_00007A84[k];
	D_00007CC0->p2C = D_00007A88[k];
	D_00007CC0->unk14 = 1;
	ret = sceAudiocodecCheckNeedMem(D_00007CC0, 0x1000);
	*needed = D_00007CC0->neededMem;
	return ret;
}

int func_00006208(AudioCtx *ctx, int edram, unsigned int size, AudioParam2 *p2, AudioParam4 *p4)
{
	int ret;

	func_00005AE0(D_00007D88);
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
		func_00005B7C(D_00007D88);
		return ret;
	}
	ret = sceAudiocodecInit(ctx, 0x1000);
	if (ret == 0) {
		func_00005B7C(D_00007D88);
		return 0;
	}
err:
	func_00005B7C(D_00007D88);
	return ret;
}

void func_00006314(void)
{
	if (D_00007CC0->edram != 0)
		sceAudiocodecReleaseEDRAM(D_00007CC0);
}

int func_0000634C(int *needed, int type)
{
	int ret;

	func_00005AE0(D_00007D88);
	ret = func_00006158(needed, type);
	func_00005B7C(D_00007D88);
	return ret;
}

int func_000063A8(void)
{
	return D_00007CC0->edram;
}

int func_000063B8(AudioCtx *ctx)
{
	int ret;

	func_00005AE0(D_00007D88);
	ret = sceAudiocodecDecode(ctx, 0x1000);
	if (ret != 0) {
		func_00005B7C(D_00007D88);
		return ret;
	}
	func_00005B7C(D_00007D88);
	return 0;
}

INCLUDE_RODATA("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_audio", D_00007A84);

INCLUDE_RODATA("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_audio", D_00007A88);
