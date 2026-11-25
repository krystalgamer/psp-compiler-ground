/* cflags: -O2 -frename-registers -fno-strict-aliasing -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "atrac.h"
/* --- end declarations --- */

int func_000022F8(AtracInfo *info, unsigned char *buf, unsigned int bufSize, unsigned int b, WaveFmt *fmt)
{
	int g;
	unsigned int a;
	unsigned int c;
	unsigned int d;
	int e;
	int f;
	int type;
	int ret;

	a = 0;
	e = 0;
	f = -1;
	g = -1;
	type = func_000016E4(buf, bufSize, fmt, &a, &c, &d, &e, &f, &g);
	if (type == -1 || type == 1)
		return 0x80630006;
	ret = func_00002504(info, type);
	if (ret != 0)
		return ret;
	return func_00002408(info, fmt, buf, a, bufSize, b, c, d, e, f, g);
}

int func_00002408(AtracInfo *info, WaveFmt *fmt, unsigned char *buf, unsigned int a, unsigned int bufSize, unsigned int b, unsigned int c, unsigned int d, int e, int f, int g)
{
	int ret;

	func_00002550(info, e, fmt);
	if (info->sampleSize == 0)
		return 0x80630008;
	func_000025A4(info, c, d, e, f, g);
	func_00002690(info, (unsigned int)buf, bufSize, b, d, a);
	if ((ret = func_000026C0(info)) != 0)
		return ret;
	return func_00002764(info, bufSize, b);
}

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

void func_000025A4(AtracInfo *info, unsigned int endSample, unsigned int dataSize, int skip0, int loopStart, int loopEnd)
{
	int skip = func_0000222C(info);
	int n = func_0000220C(info);
	if (endSample != 0)
		info->unk14 = endSample + skip0 + skip - 1;
	else
		info->unk14 = (dataSize / info->sampleSize) * n - 1;
	info->loopNum = 0;
	info->unkC = skip0 + skip;
	info->unk20 = (skip0 + skip) / n;
	if (loopStart < 0) {
		info->unk18 = 0;
		info->unk1C = 0;
	} else {
		info->unk18 = loopStart + skip;
		info->unk1C = loopEnd + skip;
	}
}

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

int func_000026C0(AtracInfo *info)
{
	int n;

	if (info->unk18 >= info->unk14)
		return 0x80630008;
	if (info->unk14 < info->unk1C)
		return 0x80630008;
	n = func_0000220C(info);
	if ((info->unk30 - info->unk2C) / info->sampleSize < (info->unk14 + n) / n)
		return 0x80630008;
	return 0;
}

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
