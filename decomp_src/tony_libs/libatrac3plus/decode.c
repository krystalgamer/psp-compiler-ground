/* cflags: -O2 -frename-registers -fno-strict-aliasing -fno-merge-constants */
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

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002AC0);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002BA0);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002C5C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002CC8);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002D18);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002DD0);
