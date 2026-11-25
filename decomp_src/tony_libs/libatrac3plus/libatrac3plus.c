/* cflags: -O2 -frename-registers -fno-strict-aliasing -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
typedef struct {
	int codec;
	int channel;
	unsigned int sampleSize;
	unsigned int unkC;
	unsigned int unk10;
	unsigned int unk14;
	unsigned int unk18;
	unsigned int unk1C;
	int unk20;
	int loopNum;
	unsigned int unk28;
	unsigned int unk2C;
	unsigned int unk30;
	int state;
	int unk38;
	unsigned int unk3C;
	unsigned int unk40;
	unsigned int unk44;
	unsigned int unk48;
	unsigned int unk4C;
	unsigned int unk50;
	char pad54[0x58 - 0x54];
} AtracInfo;

typedef struct {
	unsigned int d1;
	unsigned int d2;
	unsigned char d4[8];
} Guid;

typedef struct {
	unsigned short unk0;
	unsigned short nChannels;
	unsigned int unk4;
	unsigned int unk8;
	unsigned short nBlockAlign;
} WaveFmt;

typedef struct {
	unsigned int buf;
	unsigned int unk4;
	unsigned int unk8;
	unsigned int unkC;
	unsigned int unk10;
	unsigned int unk14;
	unsigned int unk18;
	unsigned int unk1C;
} AtracBufInfo;

typedef struct {
	unsigned int codec[26];
	char pad68[0xF0 - 0x68];
	AtracInfo info;
} AtracCtx;

static inline int frameSamples(AtracInfo *info)
{
	int n = 0x800;

	if (info->codec == 0x1001)
		n = 0x400;
	return n;
}

static inline int frameSkip(AtracInfo *info)
{
	int n = 0x170;

	if (info->codec == 0x1001)
		n = 0x45;
	return n;
}

extern AtracCtx D_00003930[4];

int func_000020B8(AtracInfo *info);
int func_000029E4(AtracInfo *info);
int func_0000220C(AtracInfo *info);
int func_00002180(AtracInfo *info);
int func_00001F7C(AtracInfo *info);
unsigned int func_000022B0(AtracInfo *info);
int func_00001F04(const unsigned char *a, const unsigned char *b, unsigned int n);
int func_0000201C(AtracInfo *info, unsigned int pos);
int func_0000222C(AtracInfo *info);
void func_00002884(AtracInfo *info);
void func_00002938(AtracInfo *info);
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracGetAtracID);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracReleaseAtracID);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracSetHalfwayBuffer);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracSetDataAndGetID);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracSetHalfwayBufferAndGetID);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracDecodeData);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracGetStreamDataInfo);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracAddStreamData);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracGetSecondBufferInfo);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracSetSecondBuffer);

int sceAtracGetSoundSample(unsigned int id, int *endSample, int *loopStart, int *loopEnd)
{
	AtracInfo *info;
	int start;

	if (id >= 4 || !D_00003930[id].codec[0])
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

	if (id >= 4 || !D_00003930[id].codec[0])
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
	if (id >= 4 || !D_00003930[id].codec[0])
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	if (!func_00001F7C(&D_00003930[id].info))
		return 0x80630021;
	D_00003930[id].info.loopNum = loopNum;
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracGetBufferInfoForReseting);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracResetPlayPosition);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00000D3C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00000E0C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00000E90);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00000EF8);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000010DC);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_0000114C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", module_start);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", module_stop);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", sceAtracSetData);

int sceAtracGetRemainFrame(unsigned int id, int *out)
{
	if (id >= 4 || !D_00003930[id].codec[0])
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
		if (D_00003930[id].codec[0]) {
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
	if (id >= 4 || !D_00003930[id].codec[0])
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	*out = func_0000220C(&D_00003930[id].info);
	return 0;
}

int sceAtracGetNextSample(unsigned int id, int *out)
{
	if (id >= 4 || !D_00003930[id].codec[0])
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	*out = func_00002180(&D_00003930[id].info);
	return 0;
}

int sceAtracGetBitrate(unsigned int id, int *out)
{
	if (id >= 4 || !D_00003930[id].codec[0])
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	*out = func_000020B8(&D_00003930[id].info);
	return 0;
}

int sceAtracGetLoopStatus(unsigned int id, int *loopNum, int *status)
{
	if (id >= 4 || !D_00003930[id].codec[0])
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	*loopNum = D_00003930[id].info.loopNum;
	*status = func_00001F7C(&D_00003930[id].info);
	return 0;
}

int sceAtracGetInternalErrorInfo(unsigned int id, int *out)
{
	if (id >= 4 || !D_00003930[id].codec[0])
		return 0x80630005;
	if (!D_00003930[id].info.state)
		return 0x80630010;
	*out = *(D_00003930[id].codec + 19);
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00001640);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000016E4);

int func_00001D94(Guid *a, Guid *b)
{
	int ret = 0;

	if (a->d1 == b->d1 && a->d2 == b->d2 && func_00001F04(a->d4, b->d4, 8) == 0)
		ret = 1;
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00001DFC);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00001E8C);

int func_00001F04(const unsigned char *a, const unsigned char *b, unsigned int size)
{
	long long n = size;

	for (; n > 0; n--) {
		if (*a != *b)
			return *a < *b ? -1 : 1;
		a++;
		b++;
	}
	return 0;
}

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

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000020B8);

unsigned int func_0000214C(AtracInfo *info)
{
	return info->unkC % frameSamples(info);
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002180);

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

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000022F8);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002408);

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

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002550);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000025A4);

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

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000026C0);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002764);

unsigned int func_00002820(unsigned int a, unsigned int b, unsigned int c)
{
	unsigned int r = a + b;

	if (r >= c)
		r = b;
	return r;
}

int func_00002838(AtracInfo *info)
{
	func_00002884(info);
	if ((unsigned int)(info->state - 1) >= 2)
		func_00002938(info);
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002884);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002938);

INCLUDE_RODATA("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", D_00003834);

INCLUDE_RODATA("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", D_00003844);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000029E4);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002AC0);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002BA0);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002C5C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002CC8);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002D18);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002DD0);

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

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002FC0);

unsigned int func_0000303C(AtracInfo *info)
{
	unsigned int end = info->unk28 + info->unk3C;
	unsigned int ret = 0;

	if (end < info->unk30)
		ret = info->unk30 - end;
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00003064);

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

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00003178);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000031CC);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00003334);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_0000340C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00003538);
