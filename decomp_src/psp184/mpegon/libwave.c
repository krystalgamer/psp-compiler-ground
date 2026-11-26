/* cflags: -O2 -frename-registers */
#include "common.h"
#include "libwave_sdk.h"

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/libwave", sceWaveInit);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/libwave", sceWaveSetVoice);

int sceWaveSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left >= 128)
		return 0x8044000A;
	if (right >= 128)
		return 0x8044000A;
	D_00014614[ch].vol_l = (int)(left << 12) / 127;
	D_00014614[ch].vol_r = (int)(right << 12) / 127;
	return 0;
}

int sceWaveGetVolume(unsigned int ch, int *left, int *right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left == NULL)
		return 0x8044000A;
	if (right == NULL)
		return 0x8044000A;
	if (D_00014614[ch].vol_l <= 0)
		*left = 0;
	else if (D_00014614[ch].vol_l >= 128)
		*left = (D_00014614[ch].vol_l - 1) / 32;
	else
		*left = D_00014614[ch].vol_l / 32;
	if (D_00014614[ch].vol_r <= 0)
		*right = 0;
	else if (D_00014614[ch].vol_r >= 128)
		*right = (D_00014614[ch].vol_r - 1) / 32;
	else
		*right = D_00014614[ch].vol_r / 32;
	return 0;
}

int sceWaveSetVolumeEx(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left > 0x1000)
		return 0x8044000A;
	if (right > 0x1000)
		return 0x8044000A;
	D_00014614[ch].vol_l = left;
	D_00014614[ch].vol_r = right;
	return 0;
}

int sceWaveGetVolumeEx(unsigned int ch, int *left, int *right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left == NULL)
		return 0x8044000A;
	if (right == NULL)
		return 0x8044000A;
	*left = D_00014614[ch].vol_l;
	*right = D_00014614[ch].vol_r;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_00014614[ch].stat == 0)
		*rest = 0;
	else if (!(D_00014614[ch].flags & 0x400))
		*rest = D_00014614[ch].size - D_00014614[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_00014614[ch].stat;
}

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/libwave", sceWavePlay);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/libwave", sceWavePlayEx);

int sceWaveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_00014614[ch].stat != 0) {
			D_00014614[ch].flags |= 0x120000;
			D_00014874[ch].stat = 0;
			D_00014874[ch].pos = 0;
			D_00014874[ch].unk30 = 0;
			D_00014874[ch].unk34 = 0;
			D_00014874[ch].unk28 = 0;
			D_00014874[ch].unk2C = 0;
		} else {
			D_00014614[ch].pos = 0;
			D_00014614[ch].unk30 = 0;
			D_00014614[ch].unk34 = 0;
			D_00014614[ch].unk28 = 0;
			D_00014614[ch].unk2C = 0;
		}
		ret = 0;
	}
	return ret;
}

int sceWaveAudioSetSample(unsigned int ch, int samplecount)
{
	if (ch >= 4)
		return 0x80440010;
	if ((unsigned int)(samplecount - 64) > 0xff80)
		return 0x80440011;
	if (samplecount & 0x3f)
		return 0x80440011;
	return sceAudioSetChannelDataLen(D_00014AE8[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_00014AE8[ch], left, right);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_00014AE8[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_00014AE8[ch], left, right, buf);
}

int sceWaveStart(int prio)
{
	if (D_0001378C != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return func_00005934(prio);
}

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/libwave", sceWaveEnd);

int sceWaveExit(void)
{
	if (D_0001378C != 1)
		return 0x80440002;
	sceAudioChRelease(D_00014AD4.ch);
	sceAudioChRelease(D_00014AE8[0]);
	sceAudioChRelease(D_00014AE8[1]);
	sceAudioChRelease(D_00014AE8[2]);
	D_00014AE0 = NULL;
	D_00014AE4 = NULL;
	D_0001378C = 0;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_00014614[ch].flags = (D_00014614[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_00014614[ch].stat != 0) {
		D_00014874[ch].stat = 0;
		D_00014614[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_00014614[ch].stat == 0)
		D_00014614[ch].stat = 1;
	return 0;
}

void sceWaveAllStop(void)
{
	int i;

	for (i = 0; i < 8; i++)
		sceWaveStop(i);
}

int sceWaveAudioSetFormat(unsigned int ch, int format)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioChangeChannelConfig(D_00014AE8[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLength(D_00014AE8[ch]);
}

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/libwave", D_0001293C);
static int func_00005934(int prio)
{
	D_00013790 = 0;
	D_00014AD4.thid = sceKernelCreateThread("SceWaveMain", func_000059D8, prio, 0x1000, 0, NULL);
	if (D_00014AD4.thid < 0)
		return 0x80440003;
	D_00014AD4.prio = prio;
	if (sceKernelStartThread(D_00014AD4.thid, sizeof(SceWaveMain), &D_00014AD4) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_0001378C = 3;
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/libwave", func_000059D8);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/libwave", func_00005AF4);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/libwave", func_00005CDC);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/libwave", func_00005E20);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/libwave", func_000060CC);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/libwave", func_0000663C);

