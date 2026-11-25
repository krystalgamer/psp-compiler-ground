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

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/reset", func_00003334);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/reset", func_0000340C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/reset", func_00003538);
