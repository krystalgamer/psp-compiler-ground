/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "audiocodec.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", sceAudiocodecCheckNeedMem);

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", sceAudiocodecInit);

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", sceAudiocodecDecode);

int sceAudiocodecGetInfo(AudiocodecCtx *ctx, int codec)
{
	int ret;
	unsigned int oldk1;

	if (ctx == 0)
		return 0x807F0001;
	K1_SAVE(oldk1);
	if (k1StaBufBad((unsigned int)ctx, 0x68)) {
		ret = 0x80000023;
		goto end;
	}
	if (k1DynBufBad(ctx->edram, ctx->neededMem)) {
		ret = 0x80000023;
		goto end;
	}
	switch (codec) {
	case 0x1000:
		ctx->unk0 = 0x04090701;
		ret = sceMeAudio_driver_39F06790(codec, 4, ctx);
		break;
	case 0x1001:
	case 0x1003:
		ret = 0;
		goto end;
	case 0x1002:
	case 0x1004:
		ctx->unk0 = 0x04090701;
		ret = sceMeAudio_driver_39F06790(codec, 2, ctx);
		break;
	default:
		ret = 0x80000004;
		goto end;
	}
	if (ret < 0)
		ret = convErr(ret);
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceAudiocodec_6CD2A861(AudiocodecCtx *ctx, int codec, int *out)
{
	int ret;
	unsigned int oldk1;

	if (ctx == 0)
		return 0x807F0001;
	if (out == 0)
		return 0x807F0001;
	K1_SAVE(oldk1);
	if (!k1StaBufOk(out, 4)) {
		ret = 0x80000023;
	} else {
		ret = func_000007B4(ctx, codec);
		if (ret >= 0) {
			*out = ret;
			ret = 0;
		}
	}
	K1_RESTORE(oldk1);
	return ret;
}

int sceAudiocodecAlcExtendParameter(AudiocodecCtx *ctx, int codec, int *out)
{
	int ret;
	unsigned int oldk1;

	if (ctx == 0)
		return 0x807F0001;
	if (out == 0)
		return 0x807F0001;
	K1_SAVE(oldk1);
	if (!k1StaBufOk(out, 4)) {
		ret = 0x80000023;
	} else {
		ret = func_00000894(ctx, codec);
		if (ret >= 0) {
			*out = ret;
			ret = 0;
		}
	}
	K1_RESTORE(oldk1);
	return ret;
}

int sceAudiocodecGetEDRAM(AudiocodecCtx *ctx, int codec)
{
	int ret = 0;
	unsigned int p;
	unsigned int oldk1;

	if (ctx == 0)
		return 0x807F0001;
	K1_SAVE(oldk1);
	if (!k1StaBufOk(ctx, 0x6C)) {
		ret = 0x80000023;
		goto end;
	}
	if ((unsigned int)(codec - 0x1000) >= 5) {
		ret = 0x80000004;
		goto end;
	}
	p = (unsigned int)sceMeMalloc((ctx->neededMem + 0x3F) | 0x3F);
	ctx->allocMem = p;
	ctx->edram = (p + 0x3F) & ~0x3F;
	if (ctx->edram == 0)
		ret = 0x807F0003;
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceAudiocodecReleaseEDRAM(AudiocodecCtx *ctx)
{
	int ret = 0;
	unsigned int oldk1;
	int ok;

	if (ctx == 0)
		return 0x807F0001;
	K1_SAVE(oldk1);
	if (!k1StaBufOk(ctx, 0x6C)) {
		ret = 0x80000023;
		goto end;
	}
	if (!k1DynBufOk(ctx->edram, ctx->neededMem)) {
		ret = 0x80000023;
		goto end;
	}
	ok = __builtin_allegrex_ext(ctx->allocMem, 0, 29) <= 0x1FFFFF;
	if (!ok) {
		ret = 0x807F0004;
		goto end;
	}
	sceMeFree((void *)ctx->allocMem);
	ctx->allocMem = 0;
	ctx->edram = 0;
end:
	K1_RESTORE(oldk1);
	return ret;
}

int func_000007B4(AudiocodecCtx *ctx, int codec)
{
	int ret = 0x80000004;
	int size;

	switch (codec) {
	case 0x1000:
		if (ctx->unk30 != 0)
			size = 0x100A;
		else
			size = ctx->unk40 + 2;
		break;
	case 0x1001:
		size = ctx->unk30 * 2 + 1;
		break;
	case 0x1002:
		if (ctx->unk38 == 9999) {
			size = sceAudiocodecGetInfo(ctx, 0x1002);
			if (size < 0)
				break;
		}
		size = func_00000958(ctx->unk38, ctx->unk3C, ctx->unk44, ctx->unk48, &ctx->unk28);
		break;
	case 0x1003:
		size = 0x600;
		break;
	case 0x1004:
		size = func_00000958(ctx->unk30, ctx->unk34, ctx->unk3C, ctx->unk40, &ctx->unk28);
		break;
	default:
		goto end;
	}
	ret = size;
end:
	return ret;
}

int func_00000894(AudiocodecCtx *ctx, int codec)
{
	int ret = 0x80000004;
	int size;

	switch (codec) {
	case 0x1000:
		if (ctx->unk38 == 1)
			size = 0x2000;
		else
			size = ctx->unk48 << 12;
		break;
	case 0x1001:
	case 0x1003:
		size = 0x1000;
		break;
	case 0x1002:
		if (ctx->unk38 == 9999) {
			size = sceAudiocodecGetInfo(ctx, 0x1002);
			if (size < 0)
				break;
		}
		if (ctx->unk38 == 1)
			size = 0x1200;
		else
			size = 0x900;
		break;
	case 0x1004:
		size = 0x1200;
		break;
	default:
		goto end;
	}
	ret = size;
end:
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", func_00000958);

int func_00000A40(int ver, int idx)
{
	int ret = 0;

	if ((unsigned int)ver < 2 && idx >= 0 && idx < 15)
		ret = D_00000D1C[ver / 2][idx];
	return ret;
}

int func_00000A94(int ver, int idx)
{
	int ret = 0;

	if ((unsigned int)ver < 3 && idx >= 0 && idx < 4)
		ret = D_00000D94[ver][idx];
	return ret;
}

int module_start(void)
{
	return 0;
}

int module_stop(void)
{
	return 0;
}

INCLUDE_RODATA("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", D_00000D1C);

INCLUDE_RODATA("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", D_00000D94);
