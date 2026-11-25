/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "videocodec.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", sceVideocodecGetEDRAM);

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", sceVideocodecReleaseEDRAM);

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", sceVideocodecOpen);

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", sceVideocodecInit);

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", sceVideocodecDecode);

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", sceVideocodecStop);

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", sceVideocodecDelete);

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", sceVideocodecSetMemory);

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", sceVideocodecScanHeader);

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", sceVideocodecGetVersion);

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

int func_00000A80(VideocodecCtx *ctx, unsigned int type)
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

int func_00000AE8(VideocodecCtx *ctx, unsigned int type)
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

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", func_00000BB8);

void func_00000D84(VideocodecCtx *ctx, unsigned int type)
{
	if (type == 0) {
		VideocodecCtx *p = (VideocodecCtx *)ctx->unk10;

		sceKernelDcacheInvalidateRange((void *)ctx->unk2C, (p->unk20 * 0x2C + 0x3F) & ~0x3F);
		sceKernelDcacheInvalidateRange((void *)ctx->unk30, 0x40);
		if (ctx->unk38 != 0)
			sceKernelDcacheInvalidateRange((void *)ctx->unk38, (p->unk20 * 0x148 + 0x3F) & ~0x3F);
	}
}

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", func_00000E1C);
