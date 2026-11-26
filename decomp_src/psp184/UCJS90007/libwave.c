/* cflags: -O2 -frename-registers */
#include "common.h"
#include "libwave_sdk.h"

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", sceWaveInit);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", sceWaveSetVoice);

int sceWaveSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left >= 128)
		return 0x8044000A;
	if (right >= 128)
		return 0x8044000A;
	D_0008CCEC[ch].vol_l = (int)(left << 12) / 127;
	D_0008CCEC[ch].vol_r = (int)(right << 12) / 127;
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
	if (D_0008CCEC[ch].vol_l <= 0)
		*left = 0;
	else if (D_0008CCEC[ch].vol_l >= 128)
		*left = (D_0008CCEC[ch].vol_l - 1) / 32;
	else
		*left = D_0008CCEC[ch].vol_l / 32;
	if (D_0008CCEC[ch].vol_r <= 0)
		*right = 0;
	else if (D_0008CCEC[ch].vol_r >= 128)
		*right = (D_0008CCEC[ch].vol_r - 1) / 32;
	else
		*right = D_0008CCEC[ch].vol_r / 32;
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
	D_0008CCEC[ch].vol_l = left;
	D_0008CCEC[ch].vol_r = right;
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
	*left = D_0008CCEC[ch].vol_l;
	*right = D_0008CCEC[ch].vol_r;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_0008CCEC[ch].stat == 0)
		*rest = 0;
	else if (!(D_0008CCEC[ch].flags & 0x400))
		*rest = D_0008CCEC[ch].size - D_0008CCEC[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_0008CCEC[ch].stat;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", sceWavePlay);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", sceWavePlayEx);

int sceWaveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_0008CCEC[ch].stat != 0) {
			D_0008CCEC[ch].flags |= 0x120000;
			D_0008CF4C[ch].stat = 0;
			D_0008CF4C[ch].pos = 0;
			D_0008CF4C[ch].unk30 = 0;
			D_0008CF4C[ch].unk34 = 0;
			D_0008CF4C[ch].unk28 = 0;
			D_0008CF4C[ch].unk2C = 0;
		} else {
			D_0008CCEC[ch].pos = 0;
			D_0008CCEC[ch].unk30 = 0;
			D_0008CCEC[ch].unk34 = 0;
			D_0008CCEC[ch].unk28 = 0;
			D_0008CCEC[ch].unk2C = 0;
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
	return sceAudioSetChannelDataLen(D_0008D1C0[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_0008D1C0[ch], left, right);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_0008D1C0[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_0008D1C0[ch], left, right, buf);
}

int sceWaveStart(int prio)
{
	if (D_0008BE64 != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return func_00020498(prio);
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", sceWaveEnd);

int sceWaveExit(void)
{
	if (D_0008BE64 != 1)
		return 0x80440002;
	sceAudioChRelease(D_0008D1AC.ch);
	sceAudioChRelease(D_0008D1C0[0]);
	sceAudioChRelease(D_0008D1C0[1]);
	sceAudioChRelease(D_0008D1C0[2]);
	D_0008D1B8 = NULL;
	D_0008D1BC = NULL;
	D_0008BE64 = 0;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_0008CCEC[ch].flags = (D_0008CCEC[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_0008CCEC[ch].stat != 0) {
		D_0008CF4C[ch].stat = 0;
		D_0008CCEC[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_0008CCEC[ch].stat == 0)
		D_0008CCEC[ch].stat = 1;
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
	return sceAudioChangeChannelConfig(D_0008D1C0[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLength(D_0008D1C0[ch]);
}

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", D_0003018C);
INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", D_000301A4);
static int func_00020498(int prio)
{
	D_0008BE68 = 0;
	D_0008D1AC.thid = sceKernelCreateThread("SceWaveMain", func_0002053C, prio, 0x1000, 0, NULL);
	if (D_0008D1AC.thid < 0)
		return 0x80440003;
	D_0008D1AC.prio = prio;
	if (sceKernelStartThread(D_0008D1AC.thid, sizeof(SceWaveMain), &D_0008D1AC) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_0008BE64 = 3;
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", func_0002053C);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", func_00020658);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", func_00020840);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", func_00020984);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", func_00020C30);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/libwave", func_000211A0);

