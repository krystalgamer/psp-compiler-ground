/* cflags: -O2 -frename-registers -fno-strict-aliasing -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "atrac.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/setdata", func_000022F8);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/setdata", func_00002408);

int func_00002504(AtracInfo *info, int type)
{
	int ret = 0;

	switch (type) {
	case 3:
		if (info->codec != 0x1001)
			ret = 0x80630007;
		break;
	case 5:
		if (info->codec != 0x1000)
			ret = 0x80630007;
		break;
	default:
		ret = 0x80630008;
		break;
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/setdata", func_00002550);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/setdata", func_000025A4);

void func_00002690(AtracInfo *info, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
	info->unk28 = a5;
	info->unk2C = a5;
	info->unk30 = a4 + a5;
	info->unk38 = 1;
	info->unk3C = a2 - a5;
	info->unk40 = a1;
	info->unk44 = a3;
	info->unk48 = a5;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/setdata", func_000026C0);

int func_00002764(AtracInfo *info, unsigned int a, unsigned int b)
{
	if (b >= info->unk30) {
		if (a >= info->unk30)
			info->state = 1;
		else
			info->state = 2;
	} else {
		if (info->unk3C < info->sampleSize * 3)
			return 0x80630011;
		if (info->unk1C == 0) {
			info->state = 3;
		} else if (info->unk1C == info->unk14) {
			info->state = 4;
		} else {
			unsigned int x = func_0000201C(info, info->unk1C) - info->unk2C + 1;
			info->state = 5;
			if (x < info->unk3C)
				info->unk3C = x;
			info->unk4C = 0;
			info->unk50 = 0;
			info->unk54 = 0;
		}
	}
	return 0;
}

unsigned int func_00002820(unsigned int a, unsigned int b, unsigned int c)
{
	unsigned int r = a + b;

	if (r >= c)
		r = b;
	return r;
}
