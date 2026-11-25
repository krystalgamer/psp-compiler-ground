/* cflags: -O2 -frename-registers -fno-merge-constants */
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

void func_00003178(AtracInfo *info, AtracBufInfo *out)
{
	int end = func_0000201C(info, info->unk1C);

	out->unk10 = info->unk4C;
	out->unk14 = info->unk50;
	out->unk18 = info->unk50;
	out->unk1C = end + 1;
}

void func_000031CC(AtracInfo *info, unsigned int pos, AtracBufInfo *out)
{
	switch (info->state) {
	default:
	case 0:
	case 1:
		func_00003148(info, out);
		func_00003160(info, out);
		break;
	case 2: {
		unsigned int start = info->unk2C + info->unk3C;
		int n = func_0000220C(info);
		unsigned int x = info->unk2C + (pos / n + 1) * info->sampleSize;
		unsigned int end = info->unk30;
		unsigned int base = info->unk40;

		out->unkC = start;
		out->buf = base + start;
		out->unk4 = end - start;
		if (x >= start)
			out->unk8 = x - start;
		else
			out->unk8 = 0;
		func_00003160(info, out);
		break;
	}
	case 3:
	case 4:
		out->buf = info->unk40;
		out->unkC = func_00001FAC(info, pos);
		out->unk4 = func_0000224C(info->unk44, info->unk30 - out->unkC);
		out->unk8 = (func_00002064(info, pos) + 1) * info->sampleSize;
		func_00003160(info, out);
		break;
	case 5:
		func_0000340C(info, pos, out);
		break;
	}
}

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

void func_0000340C(AtracInfo *info, unsigned int pos, AtracBufInfo *out)
{
	unsigned int start = func_00001FAC(info, pos);
	unsigned int end = func_0000201C(info, info->unk1C);

	if (end > start) {
		unsigned int len = end - start + 1;

		out->unkC = start;
		out->buf = info->unk40;
		out->unk4 = func_0000224C(info->unk44, len);
		out->unk8 = func_0000224C(out->unk4, (func_00002064(info, pos) + 1) * info->sampleSize);
		if (info->unk38 == 1)
			func_00003160(info, out);
		else
			func_00003178(info, out);
	} else {
		func_00003148(info, out);
		out->unk1C = start;
		out->unk10 = info->unk4C;
		out->unk14 = func_0000224C(info->unk50, info->unk30 - start);
		out->unk18 = (func_00002064(info, pos) + 1) * info->sampleSize;
	}
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/reset", func_00003538);
