/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "atrac.h"
/* --- end declarations --- */

int func_00002838(AtracInfo *info)
{
	func_00002884(info);
	if ((unsigned int)(info->state - 1) >= 2)
		func_00002938(info);
	return 0;
}

void func_00002884(AtracInfo *info)
{
	int n = func_00002180(info);

	info->unk28 += info->sampleSize;
	if (info->unk20 != 0) {
		info->unk20--;
		return;
	}
	info->unkC += n;
	if (func_00001F7C(info) == 1 && info->unkC > info->unk1C) {
		info->unk28 = func_00001FAC(info, info->unk18);
		info->unk20 = func_00002064(info, info->unk18);
		info->unkC = info->unk18;
		if (info->loopNum > 0)
			info->loopNum--;
	}
}

void func_00002938(AtracInfo *info)
{
	unsigned int size = info->sampleSize;

	info->unk3C -= size;
	if (info->unk38 == 1)
		info->unk48 = func_00002820(info->unk48, size, info->unk44);
	else
		info->unk54 = func_00002820(info->unk54, size, info->unk50);
	if (func_00001F7C(info) == 0 && info->state == 5 && info->unk38 == 1) {
		info->unk38 = 2;
		info->unk54 = 0;
		info->unk3C = info->unk50;
	}
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_000029E4);

unsigned int func_00002AC0(AtracInfo *info)
{
	unsigned int base = info->unk40;
	unsigned int off = 0;

	switch (info->state) {
	case 3:
		if (info->unk28 + info->unk3C < info->unk30)
			off = func_00002F10(info->unk48, info->unk44, info->unk3C, info->sampleSize);
		break;
	case 4:
		off = func_00002F10(info->unk48, info->unk44, info->unk3C, info->sampleSize);
		break;
	case 5:
		if (info->unkC > info->unk1C) {
			base = info->unk4C;
			if (info->unk28 + info->unk3C < info->unk30)
				off = func_00002F10(info->unk54, info->unk50, info->unk3C, info->sampleSize);
		} else {
			off = func_00002F10(info->unk48, info->unk44, info->unk3C, info->sampleSize);
		}
		break;
	}
	return base + off;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002BA0);

unsigned int func_00002C5C(AtracInfo *info)
{
	unsigned int r;
	unsigned int n;

	if (info->unk38 == 2)
		r = func_000030FC(info->unk54, info->unk50, info->unk3C, info->sampleSize);
	else
		r = func_000030FC(info->unk48, info->unk44, info->unk3C, info->sampleSize);
	n = func_00002FC0(info);
	if (n < r)
		return n;
	return r;
}

int func_00002CC8(AtracInfo *info)
{
	int ret = -2;

	if (info->unk3C < info->unk30 - info->unk28) {
		ret = info->unk3C / info->sampleSize;
		if ((unsigned int)ret >= info->unk20)
			ret -= info->unk20;
		else
			ret = 0;
	}
	return ret;
}

int func_00002D18(AtracInfo *info)
{
	int ret = func_00002DD0(info);

	if (info->loopNum >= 0) {
		unsigned int end = func_0000201C(info, info->unk1C);
		unsigned int pos = info->unk28 + info->unk3C;

		if (pos >= end + 1) {
			unsigned int n = pos - end - 1;
			unsigned int s = func_00001FAC(info, info->unk18);
			if ((int)(n / (end - s + 1)) >= info->loopNum)
				ret = -3;
		}
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002DD0);
