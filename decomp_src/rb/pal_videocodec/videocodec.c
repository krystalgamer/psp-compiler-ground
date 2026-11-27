/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "common.h"
#include "videocodec.h"
/* --- end declarations --- */

int func_00000000(int off)
{
	int ret;

	ret = sceMePower_driver_B6FE3E62(1);
	if (ret != 0)
		return ret;
	if (off == 0)
		ret = sceMePowerControlAvcPower(1);
	return ret;
}

int sceVideocodecGetEDRAM(VideocodecCtx *ctx)
{
	int ret;
	unsigned int size;
	unsigned int p;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	ret = 0x806201FE;
	if (!k1StaBufOk(ctx, 0x54)) {
		ret = 0x80000023;
		goto end;
	}
	size = (ctx->unk18 + 0x3F) | 0x3F;
	if (ctx->mem == 0) {
		p = (unsigned int)sceMeCalloc(size, 1);
		ctx->mem = p;
		if (p != 0) {
			ctx->unk14 = ((p + 0x3F) >> 6) << 6;
			ret = 0;
		}
	}
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceVideocodecReleaseEDRAM(VideocodecCtx *ctx)
{
	int ret;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	ret = 0x806201FE;
	if (!k1StaBufOk(ctx, 0x54)) {
		ret = 0x80000023;
		goto end;
	}
	if (ctx->mem != 0) {
		sceMeFree((void *)ctx->mem);
		ctx->mem = 0;
		ctx->unk14 = 0;
		ret = 0;
	}
end:
	K1_RESTORE(oldk1);
	return ret;
}

INCLUDE_ASM("tmp/asm/rb/pal_videocodec/nonmatchings/videocodec", sceVideocodecOpen);

INCLUDE_ASM("tmp/asm/rb/pal_videocodec/nonmatchings/videocodec", sceVideocodecInit);

INCLUDE_ASM("tmp/asm/rb/pal_videocodec/nonmatchings/videocodec", sceVideocodecDecode);

INCLUDE_ASM("tmp/asm/rb/pal_videocodec/nonmatchings/videocodec", sceVideocodecStop);

INCLUDE_ASM("tmp/asm/rb/pal_videocodec/nonmatchings/videocodec", sceVideocodecDelete);

INCLUDE_ASM("tmp/asm/rb/pal_videocodec/nonmatchings/videocodec", sceVideocodecSetMemory);

INCLUDE_ASM("tmp/asm/rb/pal_videocodec/nonmatchings/videocodec", sceVideocodecScanHeader);

INCLUDE_ASM("tmp/asm/rb/pal_videocodec/nonmatchings/videocodec", sceVideocodecGetVersion);

int module_start(void)
{
	return 0;
}

int module_stop(void)
{
	sceMePower_driver_B6FE3E62(0);
	sceMePowerControlAvcPower(0);
	return 0;
}
int func_00000AB8(void)
{
	sceMePower_driver_B6FE3E62(0);
	sceMePowerControlAvcPower(0);
	return 0;
}


int func_00000AE0(VideocodecCtx *ctx, unsigned int type)
{
	unsigned int size;

	if (!k1StaBufOk(ctx, 0x54))
		return 0x80000023;
	switch (type) {
	case 0:
		size = 0x28;
		break;
	case 1:
	case 2:
		size = 0x100;
		break;
	default:
		return 0x806201FE;
	}
	if (!k1StaBufOk((void *)ctx->unk10, size))
		return 0x80000023;
	return 0;
}

int func_00000B48(VideocodecCtx *ctx, unsigned int type)
{
	int ret;
	unsigned int size;

	if (!k1StaBufOk(ctx, 0x54) || !k1DynBufOk(ctx->unk14, ctx->unk18) || !k1DynBufOk(ctx->unk1C, ctx->unk20))
		return 0x80000023;
	switch (type) {
	case 0:
		size = 0x28;
		break;
	case 1:
	case 2:
		size = 0x100;
		break;
	default:
		return 0x806201FE;
	}
	if (!k1StaBufOk((void *)ctx->unk10, size))
		return 0x80000023;
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/pal_videocodec/nonmatchings/videocodec", func_00000C18);

void func_00000DE4(VideocodecCtx *ctx, unsigned int type)
{
	if (type == 0) {
		VideocodecCtx *p = (VideocodecCtx *)ctx->unk10;

		sceKernelDcacheInvalidateRange((void *)ctx->unk2C, (p->unk20 * 0x2C + 0x3F) & ~0x3F);
		sceKernelDcacheInvalidateRange((void *)ctx->unk30, 0x40);
		if (ctx->unk38 != 0)
			sceKernelDcacheInvalidateRange((void *)ctx->unk38, (p->unk20 * 0x148 + 0x3F) & ~0x3F);
	}
}

INCLUDE_ASM("tmp/asm/rb/pal_videocodec/nonmatchings/videocodec", func_00000E7C);
