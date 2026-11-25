/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "audiocodec.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", sceAudiocodecCheckNeedMem);

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", sceAudiocodecInit);

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", sceAudiocodecDecode);

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", sceAudiocodecGetInfo);

int sceAudiocodec_6CD2A861(AudiocodecCtx *ctx, int codec, int *out)
{
	int ret;
	unsigned int oldk1;

	if (ctx == 0)
		return 0x807F0001;
	if (out == 0)
		return 0x807F0001;
	K1_SAVE(oldk1);
	if (K1_USER() && K1_BADPTR(out, 4)) {
		ret = 0x80000023;
	} else {
		ret = func_000007B4(ctx, codec);
		if (ret >= 0) {
			*out = ret;
			ret = 0;
		}
	}
	K1_RESTORE(oldk1);
	return ret;
}

int sceAudiocodecAlcExtendParameter(AudiocodecCtx *ctx, int codec, int *out)
{
	int ret;
	unsigned int oldk1;

	if (ctx == 0)
		return 0x807F0001;
	if (out == 0)
		return 0x807F0001;
	K1_SAVE(oldk1);
	if (K1_USER() && K1_BADPTR(out, 4)) {
		ret = 0x80000023;
	} else {
		ret = func_00000894(ctx, codec);
		if (ret >= 0) {
			*out = ret;
			ret = 0;
		}
	}
	K1_RESTORE(oldk1);
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", sceAudiocodecGetEDRAM);

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", sceAudiocodecReleaseEDRAM);

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", func_000007B4);

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", func_00000894);

INCLUDE_ASM("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", func_00000958);

int func_00000A40(int ver, int idx)
{
	int ret = 0;

	if ((unsigned int)ver < 2 && idx >= 0 && idx < 15)
		ret = D_00000D1C[ver / 2][idx];
	return ret;
}

int func_00000A94(int ver, int idx)
{
	int ret = 0;

	if ((unsigned int)ver < 3 && idx >= 0 && idx < 4)
		ret = D_00000D94[ver][idx];
	return ret;
}

int module_start(void)
{
	return 0;
}

int module_stop(void)
{
	return 0;
}

INCLUDE_RODATA("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", D_00000D1C);

INCLUDE_RODATA("tmp/asm/tony_libs/audiocodec/nonmatchings/audiocodec", D_00000D94);
