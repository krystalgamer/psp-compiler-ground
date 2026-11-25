/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
typedef struct {
	int unk0;
	int channel;
	int unk8;
	int unkC;
	int unk10;
	int unk14;
	int unk18;
	int unk1C;
	int unk20;
	int loopNum;
	int unk28;
	int unk2C;
	int unk30;
	int state;
	char pad38[0x58 - 0x38];
} AtracInfo;

typedef struct {
	unsigned int codec[26];
	char pad68[0xF0 - 0x68];
	AtracInfo info;
} AtracCtx;

extern AtracCtx D_00003930[4];

int func_000020B8(AtracInfo *info);
int func_000029E4(AtracInfo *info);
int func_0000220C(AtracInfo *info);
int func_00002180(AtracInfo *info);
int func_00001F7C(AtracInfo *info);
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
	if ((unsigned int)(info->unk30 - info->unk28) < (unsigned int)info->unk8
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

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00001D94);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00001DFC);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00001E8C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00001F04);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00001F7C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00001FAC);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_0000201C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002064);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000020B8);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_0000214C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002180);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_0000220C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_0000222C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_0000224C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002260);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002288);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000022B0);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000022F8);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002408);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002504);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002550);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000025A4);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002690);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000026C0);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002764);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002820);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002838);

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

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002F10);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002F50);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002F74);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00002FC0);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_0000303C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00003064);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000030FC);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00003148);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00003160);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00003178);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_000031CC);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00003334);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_0000340C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/libatrac3plus", func_00003538);
