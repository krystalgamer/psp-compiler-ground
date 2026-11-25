/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "atrac.h"
/* --- end declarations --- */

int func_00001F7C(AtracInfo *info)
{
	int ret = 0;

	if (info->unk1C != 0 && (info->loopNum != 0 || info->unk1C >= info->unkC))
		ret = 1;
	return ret;
}

unsigned int func_00001FAC(AtracInfo *info, unsigned int pos)
{
	int n = frameSamples(info);
	int skip = frameSkip(info);
	unsigned int off = (pos / n - 1) * info->sampleSize;

	if (pos % n < skip && off != 0)
		off -= info->sampleSize;
	return off + info->unk2C;
}

int func_0000201C(AtracInfo *info, unsigned int pos)
{
	unsigned int off = ((pos / frameSamples(info)) + 1) * info->sampleSize - 1;

	return off + info->unk2C;
}

int func_00002064(AtracInfo *info, unsigned int pos)
{
	int n = frameSamples(info);
	int ret = 1;
	int skip = frameSkip(info);

	if (pos % n < skip)
		ret = 2;
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/info", func_000020B8);

unsigned int func_0000214C(AtracInfo *info)
{
	return info->unkC % frameSamples(info);
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/info", func_00002180);

int func_0000220C(AtracInfo *info)
{
	return frameSamples(info);
}

int func_0000222C(AtracInfo *info)
{
	int n = 0x170;

	if (info->codec == 0x1001)
		n = 0x45;
	return n;
}

unsigned int func_0000224C(unsigned int a, unsigned int b)
{
	if (b >= a)
		b = a;
	return b;
}

void func_00002260(int *dst, int *src, int n)
{
	while (n != 0) {
		*dst++ = *src++;
		n--;
	}
}

void func_00002288(unsigned char *dst, unsigned char *src, int n)
{
	while (n != 0) {
		*dst++ = *src++;
		n--;
	}
}

unsigned int func_000022B0(AtracInfo *info)
{
	unsigned int ret = 0;
	int n = frameSamples(info);
	unsigned int end = ((info->unkC + n) & -n) - 1;

	if (info->unk14 < end)
		ret = end - info->unk14;
	return ret;
}
