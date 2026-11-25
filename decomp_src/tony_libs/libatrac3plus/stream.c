/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "atrac.h"
/* --- end declarations --- */

unsigned int func_00002F10(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
	unsigned int r = a + c;

	if (r >= b) {
		unsigned int m = (b - a) % d;
		if (b < m + c)
			r = 0;
		else
			r = (r - b) + m;
	}
	return r;
}

unsigned int func_00002F50(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
	unsigned int r = 0;

	if ((b + c < a) & (c < d))
		r = b + c;
	return r;
}

unsigned int func_00002F74(unsigned int a, unsigned int b, unsigned int start, unsigned int end, unsigned int lim)
{
	unsigned int x;

	if (b >= lim)
		return 0;
	x = a + b;
	if (x < end + 1)
		return x;
	return start + (x - end - 1) % (end - start + 1);
}

unsigned int func_00002FC0(AtracInfo *info)
{
	unsigned int ret = 0;

	switch (info->state) {
	case 3:
		ret = func_0000303C(info);
		break;
	case 4:
		ret = func_00003064(info);
		break;
	case 5:
		if (info->unkC > info->unk1C)
			ret = func_0000303C(info);
		else
			ret = func_00003064(info);
		break;
	}
	return ret;
}

unsigned int func_0000303C(AtracInfo *info)
{
	unsigned int end = info->unk28 + info->unk3C;
	unsigned int ret = 0;

	if (end < info->unk30)
		ret = info->unk30 - end;
	return ret;
}

unsigned int func_00003064(AtracInfo *info)
{
	unsigned int end = func_0000201C(info, info->unk1C);
	unsigned int pos = info->unk28 + info->unk3C;
	unsigned int ret;

	if (pos < end + 1) {
		ret = end - pos + 1;
	} else {
		unsigned int len = end - func_00001FAC(info, info->unk18) + 1;
		ret = len - (info->unk28 + info->unk3C - end - 1) % len;
	}
	return ret;
}

unsigned int func_000030FC(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
	unsigned int ret = 0;

	if (a + c < b) {
		ret = b - (a + c);
	} else {
		unsigned int m = (b - a) % d;
		if (b >= m + c)
			ret = b - m - c;
	}
	return ret;
}
