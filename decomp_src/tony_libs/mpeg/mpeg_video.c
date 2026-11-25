/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

unsigned int func_00007500(int type);
/* --- end declarations --- */

int func_00005BF4(void)
{
	int out;
	int ret;

	D_00007BC0 = &D_00007C00;
	memset(&D_00007C00, 0, sizeof(VideoCtx));
	D_00007C80.unk0 = 0;
	D_00007C80.unk4 = 0;
	D_00007C80.unk8 = 0;
	D_00007C80.unkC = 0;
	D_00007C80.unk10 = 0;
	D_00007C80.unk14 = 0;
	D_00007C80.unk18 = 0;
	D_00007C80.unk1C = 0;
	D_00007C80.unk20 = 0;
	D_00007C80.unk24 = 0;
	D_00007BC0->info = (int)&D_00007C80;
	D_00007BC4 = &D_00007C80;
	ret = func_00005CA8(&out);
	if (ret != 0)
		return ret;
	ret = sceVideocodecGetEDRAM(D_00007BC0, 0);
	if (ret == 0)
		return 0;
	D_00007BC0->edram = 0;
	return ret;
}

int func_00005CA8(int *out)
{
	int ret;

	ret = sceVideocodecOpen(D_00007BC0, 0);
	*out = D_00007BC0->unk18;
	return ret;
}

int func_00005CEC(VideoCtx *ctx, VideoInfo *info, void *buf0, void *buf1, int a4, int *edram, int a6, int a7, int a8, int a9, int a10)
{
	int ret;

	func_00005AE0(D_00007D84);
	info->unk0 = 0;
	info->unk4 = 0;
	info->unk8 = 0;
	info->unkC = 0;
	info->unk10 = 0;
	info->unk14 = 0;
	info->unk18 = 0;
	info->unk1C = 0;
	info->unk20 = 0;
	info->unk24 = 0;
	memset(buf0, 0, 0xB0);
	memset(buf1, 0, 0x64);
	ctx->info = (int)info;
	ctx->unk2C = buf0;
	ctx->unk30 = buf1;
	ctx->unk3C = 4;
	ctx->unk38 = a4;
	ret = sceVideocodecOpen(ctx, 0);
	if (ret != 0)
		goto err;
	ctx->edram = *edram;
	ctx->unk1C = a6;
	ret = sceVideocodecInit(ctx, 0);
	if (ret != 0)
		goto err;
	ctx->unk40 = a7;
	ctx->unk44 = a8;
	ctx->unk48 = a9;
	ctx->unk4C = a10;
	ret = sceVideocodecSetMemory(ctx, 0);
	if (ret == 0) {
		func_00005B7C(D_00007D84);
		return 0;
	}
err:
	func_00005B7C(D_00007D84);
	return ret;
}

void func_00005E54(void)
{
	sceVideocodecReleaseEDRAM(D_00007BC0);
}

int func_00005E78(int *out)
{
	int ret;

	func_00005AE0(D_00007D84);
	ret = func_00005CA8(out);
	func_00005B7C(D_00007D84);
	return ret;
}

int func_00005EC8(void)
{
	return D_00007BC0->edram;
}

void func_00005ED8(unsigned char *p, int size)
{
	int i;

	for (i = 0; i < size / 16; i++) {
		func_0000603C(p);
		p += 16;
	}
}

int func_00005F2C(VideoCtx *ctx)
{
	int ret;

	func_00005AE0(D_00007D84);
	ret = sceVideocodecDecode(ctx, 0);
	func_00005B7C(D_00007D84);
	return ret;
}

int func_00005F80(VideoCtx *ctx)
{
	int ret;

	func_00005AE0(D_00007D84);
	ret = sceVideocodecStop(ctx, 0);
	func_00005B7C(D_00007D84);
	return ret;
}

int func_00005FD4(VideoCtx *ctx)
{
	int ret;

	func_00005AE0(D_00007D84);
	ret = sceVideocodecDelete(ctx, 0);
	if (ret != 0) {
		func_00005B7C(D_00007D84);
		return ret;
	}
	func_00005B7C(D_00007D84);
	return 0;
}

void func_0000603C(unsigned char *p)
{
	unsigned char t0 = p[0];
	unsigned char t15 = p[15];
	unsigned char t1 = p[1];
	unsigned char t14 = p[14];
	unsigned char t2 = p[2];
	unsigned char t13 = p[13];
	unsigned char t3 = p[3];
	unsigned char t12 = p[12];
	unsigned char t4 = p[4];
	unsigned char t11 = p[11];
	unsigned char t5 = p[5];
	unsigned char t10 = p[10];
	unsigned char t6 = p[6];
	unsigned char t9 = p[9];
	unsigned char t7 = p[7];
	unsigned char t8 = p[8];

	p[0] = t15;
	p[15] = t0;
	p[1] = t14;
	p[14] = t1;
	p[2] = t13;
	p[13] = t2;
	p[3] = t12;
	p[12] = t3;
	p[4] = t11;
	p[11] = t4;
	p[5] = t10;
	p[10] = t5;
	p[6] = t9;
	p[9] = t6;
	p[7] = t8;
	p[8] = t7;
}
