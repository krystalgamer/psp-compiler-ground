/* cflags: -O2 -frename-registers -fno-strict-aliasing -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "atrac.h"
/* --- end declarations --- */

void func_00003148(AtracInfo *info, AtracBufInfo *out)
{
	out->buf = info->unk40;
	out->unk4 = 0;
	out->unk8 = 0;
	out->unkC = 0;
}

void func_00003160(AtracInfo *info, AtracBufInfo *out)
{
	out->unk10 = info->unk40;
	out->unk14 = 0;
	out->unk18 = 0;
	out->unk1C = 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/reset", func_00003178);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/reset", func_000031CC);

int func_00003334(AtracInfo *info, unsigned int pos, unsigned int x, unsigned int y)
{
	AtracBufInfo bi;

	func_000031CC(info, pos, &bi);
	if (x < bi.unk8 || bi.unk4 < x)
		return 0x80630016;
	if (y < bi.unk18 || bi.unk14 < y)
		return 0x80630017;
	info->unkC = pos;
	info->unk20 = func_00002064(info, pos);
	info->loopNum = 0;
	info->unk28 = func_00001FAC(info, pos);
	func_00003538(info, pos, x, y);
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/reset", func_0000340C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/reset", func_00003538);
