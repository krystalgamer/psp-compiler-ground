/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "videocodec.h"
/* --- end declarations --- */

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

int sceVideocodecOpen(VideocodecCtx *ctx, unsigned int type)
{
	int ret;
	unsigned int size;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	ret = func_00000A80(ctx, type);
	if (ret != 0)
		goto fail;
	ret = 0x806201FE;
	if (type >= 3)
		goto fail;
	ctx->unk0 = 0x04090701;
	size = 0;
	if (type == 0)
		size = 0x28;
	else if (type < 3)
		size = 0x100;
	if (size)
		sceKernelDcacheWritebackInvalidateRange((void *)ctx->unk10, size);
	ret = sceMeVideo_driver_B655AD4E(type, ctx);
	switch (ret) {
	case 0:
		ret = 0;
		break;
	case -1:
		ret = 0x806201FE;
		break;
	case -2:
		ret = 0x80620002;
		break;
	case -3:
		ret = 0x80628001;
		break;
	case -4:
		ret = 0x80628002;
		break;
	default:
		ret = 0x80628002;
		break;
	}
	if (ret == 0)
		goto end;
fail:
	sceMePower_driver_B6FE3E62(0);
	sceMePowerControlAvcPower(0);
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceVideocodecInit(VideocodecCtx *ctx, unsigned int type)
{
	int ret;
	unsigned int size;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	ret = func_00000AE8(ctx, type);
	if (ret != 0)
		goto end;
	ret = 0x806201FE;
	if (type >= 3)
		goto end;
	size = 0;
	if (type == 0)
		size = 0x28;
	else if (type < 3)
		size = 0x100;
	if (size) {
		sceKernelDcacheWritebackInvalidateRange((void *)ctx->unk10, size);
		wbInvNotMe(ctx->unk14, ctx->unk18);
		sceKernelDcacheWritebackInvalidateRange((void *)ctx->unk1C, ctx->unk20);
	}
	ret = sceMeVideo_driver_06F0236A(type, ctx);
	switch (ret) {
	case 0:
		ret = 0;
		break;
	case -1:
		ret = 0x806201FE;
		break;
	case -2:
		ret = 0x80620002;
		break;
	case -3:
		ret = 0x80628001;
		break;
	case -4:
		ret = 0x80628002;
		break;
	default:
		ret = 0x80628002;
		break;
	}
end:
	K1_RESTORE(oldk1);
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/videocodec/nonmatchings/videocodec", sceVideocodecDecode);

int sceVideocodecStop(VideocodecCtx *ctx, unsigned int type)
{
	int ret;
	unsigned int size;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	ret = func_00000E1C(ctx, type);
	if (ret != 0)
		goto end;
	ret = 0x806201FE;
	if (type >= 3)
		goto end;
	size = 0;
	if (type == 0)
		size = 0x28;
	else if (type < 3) {
		wbInvNotMe(ctx->unk14, ctx->unk18);
		size = 0x100;
	}
	if (size)
		sceKernelDcacheWritebackInvalidateRange((void *)ctx->unk10, size);
	ret = sceMeVideo_driver_DE2E7E89(type, ctx);
	func_00000D84(ctx, type);
	switch (ret) {
	case 0:
		ret = 0;
		break;
	case -1:
		ret = 0x806201FE;
		break;
	case -2:
		ret = 0x80620002;
		break;
	case -3:
		ret = 0x80628001;
		break;
	case -4:
		ret = 0x80628002;
		break;
	default:
		ret = 0x80628002;
		break;
	}
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceVideocodecDelete(VideocodecCtx *ctx, unsigned int type)
{
	int ret;
	unsigned int size;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	ret = func_00000A80(ctx, type) != 0;
	if (ret != 0)
		goto end;
	ret = 0x806201FE;
	if (type >= 3)
		goto end;
	size = 0;
	if (type == 0)
		size = 0x28;
	else if (type < 3)
		size = 0x100;
	if (size)
		sceKernelDcacheWritebackInvalidateRange((void *)ctx->unk10, size);
	ret = sceMeVideo_driver_E67F4E0A(type, ctx);
	switch (ret) {
	case 0:
		ret = 0;
		break;
	case -1:
		ret = 0x806201FE;
		break;
	case -2:
		ret = 0x80620002;
		break;
	case -3:
		ret = 0x80628001;
		break;
	case -4:
		ret = 0x80628002;
		break;
	default:
		ret = 0x80628002;
		break;
	}
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceVideocodecSetMemory(VideocodecCtx *ctx, unsigned int type)
{
	int ret;
	int r;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	ret = func_00000A80(ctx, type);
	if (ret != 0) {
		ret = 0x80000023;
		goto end;
	}
	ret = 0x806201FE;
	if (type == 0) {
		sceKernelDcacheWritebackInvalidateRange((void *)ctx->unk10, 0x28);
		ret = sceMeVideo_driver_1C6A60E1(0, 1, ctx);
		switch (ret) {
		case 0:
			ret = 0;
			break;
		case -1:
			ret = 0x806201FE;
			break;
		case -2:
			ret = 0x80620002;
			break;
		case -3:
			ret = 0x80628001;
			break;
		case -4:
			ret = 0x80628002;
			break;
		default:
			ret = 0x80628002;
			break;
		}
	}
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceVideocodecScanHeader(VideocodecCtx *ctx, unsigned int type)
{
	int ret;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (!k1StaBufOk(ctx, 0x54) || !k1StaBufOk((void *)ctx->unk10, 0x100) || !k1DynBufOk(ctx->unk24, ctx->unk28)) {
		ret = 0x80000023;
		goto end;
	}
	if (type != 0) {
		if (type < 3) {
			sceKernelDcacheWritebackInvalidateRange((void *)ctx->unk10, 0x100);
			wbInvNotMe(ctx->unk24, ctx->unk28);
			ret = sceMeVideo_driver_1C6A60E1(type, 2, ctx);
			switch (ret) {
			case 0:
				ret = 0;
				break;
			case -1:
				ret = 0x806201FE;
				break;
			case -2:
				ret = 0x80620002;
				break;
			case -3:
				ret = 0x80628001;
				break;
			case -4:
				ret = 0x80628002;
				break;
			default:
				ret = 0x80628002;
				break;
			}
			goto end;
		}
	}
	ret = 0x806201FE;
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceVideocodecGetVersion(VideocodecCtx *ctx, unsigned int type)
{
	int ret;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (!k1StaBufOk(ctx, 0x54)) {
		ret = 0x80000023;
		goto end;
	}
	ret = 0x806201FE;
	if (type < 3) {
		ret = sceMeVideo_driver_1C6A60E1(type, 3, ctx);
		switch (ret) {
		case 0:
			ret = 0;
			break;
		case -1:
			ret = 0x806201FE;
			break;
		case -2:
			ret = 0x80620002;
			break;
		case -3:
			ret = 0x80628001;
			break;
		case -4:
			ret = 0x80628002;
			break;
		default:
			ret = 0x80628002;
			break;
		}
	}
end:
	K1_RESTORE(oldk1);
	return ret;
}

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
