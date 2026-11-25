/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "atrac.h"
/* --- end declarations --- */

int sceAtracGetAtracID(int codec)
{
	int intr = sceKernelCpuSuspendIntr();
	int ret = 0x80630003;
	int i;

	if (codec == 0x1000) {
		for (i = 0; i < 2; i++) {
			if (D_00003930[i].inUse == 0) {
				ret = i;
				D_00003930[i].inUse = 1;
				D_00003930[i].info.state = 0;
				break;
			}
		}
	} else if (codec == 0x1001) {
		for (i = 2; i < 4; i++) {
			if (D_00003930[i].inUse == 0) {
				ret = i;
				D_00003930[i].inUse = 1;
				D_00003930[i].info.state = 0;
				break;
			}
		}
	} else {
		ret = 0x80630004;
	}
	sceKernelCpuResumeIntr(intr);
	return ret;
}

int sceAtracReleaseAtracID(unsigned int id)
{
	int ret;
	int intr;

	if (id >= 4)
		return 0x80630005;
	ret = 0x80630005;
	intr = sceKernelCpuSuspendIntr();
	if (D_00003930[id].inUse != 0) {
		D_00003930[id].inUse = 0;
		ret = 0;
	}
	sceKernelCpuResumeIntr(intr);
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracSetHalfwayBuffer);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracSetDataAndGetID);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracSetHalfwayBufferAndGetID);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracDecodeData);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracGetStreamDataInfo);

int sceAtracAddStreamData(unsigned int id, unsigned int n)
{
	AtracInfo *info;
	unsigned int avail;

	if (id >= 4 || !D_00003930[id].inUse)
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	info = &D_00003930[id].info;
	if (info->state == 1)
		return 0x80630009;
	if (info->state == 2)
		avail = info->unk30 - (info->unk2C + info->unk3C);
	else
		avail = func_00002C5C(info);
	if (avail < n)
		return 0x80630018;
	info->unk3C += n;
	if (info->state == 2 && info->unk2C + info->unk3C >= info->unk30)
		info->state = 1;
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracGetSecondBufferInfo);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracSetSecondBuffer);

int sceAtracGetSoundSample(unsigned int id, int *endSample, int *loopStart, int *loopEnd)
{
	AtracInfo *info;
	int start;

	if (id >= 4 || !D_00003930[id].inUse)
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	info = &D_00003930[id].info;
	start = info->unk10;
	*endSample = info->unk14 - start;
	if (info->unk1C == 0) {
		*loopStart = -1;
		*loopEnd = -1;
	} else {
		*loopStart = info->unk18 - start;
		*loopEnd = info->unk1C - start;
	}
	return 0;
}

int sceAtracGetNextDecodePosition(unsigned int id, unsigned int *pos)
{
	AtracInfo *info;

	if (id >= 4 || !D_00003930[id].inUse)
		return 0x80630005;
	info = &D_00003930[id].info;
	if (!info->state)
		return 0x80630010;
	if ((unsigned int)(info->unk30 - info->unk28) < (unsigned int)info->sampleSize
	    || (unsigned int)info->unk14 < (unsigned int)info->unkC)
		return 0x80630024;
	*pos = info->unkC - info->unk10;
	return 0;
}

int sceAtracSetLoopNum(unsigned int id, int loopNum)
{
	if (id >= 4 || !D_00003930[id].inUse)
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	if (!func_00001F7C(&D_00003930[id].info))
		return 0x80630021;
	D_00003930[id].info.loopNum = loopNum;
	return 0;
}

int sceAtracGetBufferInfoForReseting(unsigned int id, unsigned int pos, AtracBufInfo *out)
{
	AtracInfo *info;

	if (id >= 4 || !D_00003930[id].inUse)
		return 0x80630005;
	info = &D_00003930[id].info;
	if (!info->state)
		return 0x80630010;
	if (info->state == 5 && info->unk50 == 0)
		return 0x80630012;
	{
		unsigned int p = pos + info->unk10;

		if (info->unk14 < p)
			return 0x80630015;
		func_000031CC(info, p, out);
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracResetPlayPosition);

int func_00000D3C(AtracCtx *ctx, WaveFmt *fmt)
{
	AtracInfo *info = &ctx->info;
	unsigned int *codec = ctx->codec;
	int ret;

	if (info->codec == 0x1001) {
		ret = func_00000E90(info->sampleSize, fmt->unk14, &codec[10]);
		if (ret < 0)
			return ret;
	} else {
		unsigned char *d = (unsigned char *)&codec[10];
		unsigned char *src = fmt->unk2A;
		int i;

		codec[5] = 1;
		for (i = 0; i < 2; i++)
			*d++ = *src++;
		codec[12] = 0;
	}
	ret = sceAudiocodecInit(codec, info->codec);
	if (ret != 0)
		goto out;
	ret = func_00000E0C(ctx);
out:
	if (ret == 0x807F0002)
		ret = 0x80630002;
	return ret;
}

int func_00000E0C(AtracCtx *ctx)
{
	unsigned char raw[0x2040];
	int a;
	int b;
	unsigned char *buf = (unsigned char *)(((unsigned int)raw + 63) & ~63);
	unsigned int n = ctx->info.unk20;
	unsigned int i;
	int ret;

	ret = 0;
	for (i = 0; i < n; i++) {
		ret = func_00000EF8(ctx, buf, &a, &b);
		if (ret != 0)
			break;
	}
	return ret;
}

int func_00000E90(unsigned int size, unsigned int key, unsigned int *out)
{
	unsigned int i;

	for (i = 0; i < 3; i++) {
		if (D_00003890[i].sampleSize == size && D_00003890[i].key == key)
			break;
	}
	if (i >= 3)
		return 0x80630008;
	*out = D_00003890[i].value;
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00000EF8);

unsigned int func_000010DC(AtracInfo *info)
{
	if (info->state - 1 < 2)
		return info->unk40 + info->unk28;
	if (info->unk38 == 1)
		return func_0000114C(info->unk40, info->unk48, info->unk44, info->sampleSize);
	return func_0000114C(info->unk4C, info->unk54, info->unk50, info->sampleSize);
}

unsigned int func_0000114C(unsigned int base, unsigned int pos, unsigned int end, unsigned int size)
{
	unsigned int ret = base + pos;

	if (end < pos + size) {
		int n = 0;

		if (pos < end)
			n = end - pos;
		func_00002288((unsigned char *)base, (unsigned char *)ret, n);
		ret = base;
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", module_start);

int module_stop(void)
{
	AtracCtx *c = D_00003930;
	int i;

	for (i = 0; i < 4; i++, c++) {
		if (c->edram != 0x200000)
			sceAudiocodecReleaseEDRAM(c->codec);
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracSetData);

int sceAtracGetRemainFrame(unsigned int id, int *out)
{
	if (id >= 4 || !D_00003930[id].inUse)
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	*out = func_000029E4(&D_00003930[id].info);
	return 0;
}

int sceAtracGetChannel(unsigned int id, int *ch)
{
	int ret = 0x80630005;

	if (id < 4) {
		if (D_00003930[id].inUse) {
			ret = 0x80630010;
			if (D_00003930[id].info.state) {
				ret = 0;
				*ch = D_00003930[id].info.channel;
			}
		}
	}
	return ret;
}

int sceAtracGetMaxSample(unsigned int id, int *out)
{
	if (id >= 4 || !D_00003930[id].inUse)
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	*out = func_0000220C(&D_00003930[id].info);
	return 0;
}

int sceAtracGetNextSample(unsigned int id, int *out)
{
	if (id >= 4 || !D_00003930[id].inUse)
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	*out = func_00002180(&D_00003930[id].info);
	return 0;
}

int sceAtracGetBitrate(unsigned int id, int *out)
{
	if (id >= 4 || !D_00003930[id].inUse)
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	*out = func_000020B8(&D_00003930[id].info);
	return 0;
}

int sceAtracGetLoopStatus(unsigned int id, int *loopNum, int *status)
{
	if (id >= 4 || !D_00003930[id].inUse)
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	*loopNum = D_00003930[id].info.loopNum;
	*status = func_00001F7C(&D_00003930[id].info);
	return 0;
}

int sceAtracGetInternalErrorInfo(unsigned int id, int *out)
{
	if (id >= 4 || !D_00003930[id].inUse)
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	*out = *(D_00003930[id].codec + 2);
	return 0;
}

int func_00001640(AtracCtx *ctx, int codec)
{
	int type = 0x1001;
	int ret;

	ctx->edram = 0x200000;
	ctx->inUse = 1;
	if (codec == 0x1000) {
		((unsigned char *)ctx->codec)[0x28] = 0x28;
		((unsigned char *)ctx->codec)[0x29] = 0x5C;
		type = 0x1000;
	}
	ret = sceAudiocodecCheckNeedMem(ctx->codec, type);
	if (ret >= 0) {
		ret = sceAudiocodecGetEDRAM(ctx->codec, type);
		if (ret >= 0) {
			ctx->info.codec = codec;
			ctx->inUse = 0;
		}
	}
	return ret;
}
