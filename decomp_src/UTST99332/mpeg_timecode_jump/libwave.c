/* cflags: -O2 -frename-registers */
#include "common.h"

typedef struct {
	void *data;
	unsigned int size;
	int vol_l;
	int vol_r;
	int unk10;
	int unk14;
	int flags;
	int stat;
	int pos;
	int unk24;
	int unk28;
	int unk2C;
	int unk30;
	int unk34;
	int unk38;
	int unk3C;
	int unk40;
	int unk44;
	int unk48;
} SceWaveVoice;

typedef struct {
	int thid;
	int ch;
	int prio;
} SceWaveMain;

extern int D_00011834;
extern int D_00011838;
extern char D_0001183C[];
extern char D_000118AC[];
extern SceWaveVoice D_000126BC[8];
extern SceWaveVoice D_0001291C[8];
extern SceWaveMain D_00012B7C;
extern void *D_00012B88;
extern void *D_00012B8C;
extern int D_00012B90[3];

int sceAudioChReserve(int channel, int samplecount, int format);
int sceAudioChRelease(int channel);
int sceAudioSetChannelDataLen(int channel, int samplecount);
int sceAudioChangeChannelVolume(int channel, int leftvol, int rightvol);

int sceWaveGetStat(unsigned int ch);
int sceWaveStop(unsigned int ch);
int sceAudioOutputPanned(int channel, int leftvol, int rightvol, void *buffer);
int sceAudioOutputPannedBlocking(int channel, int leftvol, int rightvol, void *buffer);
int sceAudioOutputBlocking(int channel, int vol, void *buffer);
int sceAudioChangeChannelConfig(int channel, int format);
int sceAudioGetChannelRestLength(int channel);
int sceKernelCreateThread(const char *name, void *entry, int initPriority, int stackSize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
int sceKernelDelayThread(unsigned int delay);
int sceKernelWaitThreadEnd(int thid, unsigned int *timeout);
int sceKernelDeleteThread(int thid);
int sceKernelExitThread(int status);
static int func_000044B4(unsigned int args, void *argp);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", sceWaveInit);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", sceWaveSetVoice);

int sceWaveSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left >= 128)
		return 0x8044000A;
	if (right >= 128)
		return 0x8044000A;
	D_000126BC[ch].vol_l = (int)(left << 12) / 127;
	D_000126BC[ch].vol_r = (int)(right << 12) / 127;
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
	if (D_000126BC[ch].vol_l <= 0)
		*left = 0;
	else if (D_000126BC[ch].vol_l >= 128)
		*left = (D_000126BC[ch].vol_l - 1) / 32;
	else
		*left = D_000126BC[ch].vol_l / 32;
	if (D_000126BC[ch].vol_r <= 0)
		*right = 0;
	else if (D_000126BC[ch].vol_r >= 128)
		*right = (D_000126BC[ch].vol_r - 1) / 32;
	else
		*right = D_000126BC[ch].vol_r / 32;
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
	D_000126BC[ch].vol_l = left;
	D_000126BC[ch].vol_r = right;
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
	*left = D_000126BC[ch].vol_l;
	*right = D_000126BC[ch].vol_r;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_000126BC[ch].stat == 0)
		*rest = 0;
	else if (!(D_000126BC[ch].flags & 0x400))
		*rest = D_000126BC[ch].size - D_000126BC[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_000126BC[ch].stat;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", sceWavePlay);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", sceWavePlayEx);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", sceWaveStop);

int sceWaveAudioSetSample(unsigned int ch, int samplecount)
{
	if (ch >= 4)
		return 0x80440010;
	if ((unsigned int)(samplecount - 64) > 0xff80)
		return 0x80440011;
	if (samplecount & 0x3f)
		return 0x80440011;
	return sceAudioSetChannelDataLen(D_00012B90[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_00012B90[ch], left, right);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_00012B90[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_00012B90[ch], left, right, buf);
}

int sceWaveStart(int prio)
{
	if (D_00011834 != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return func_00004410(prio);
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", sceWaveEnd);

int sceWaveExit(void)
{
	if (D_00011834 != 1)
		return 0x80440002;
	sceAudioChRelease(D_00012B7C.ch);
	sceAudioChRelease(D_00012B90[0]);
	sceAudioChRelease(D_00012B90[1]);
	sceAudioChRelease(D_00012B90[2]);
	D_00012B88 = NULL;
	D_00012B8C = NULL;
	D_00011834 = 0;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_000126BC[ch].flags = (D_000126BC[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_000126BC[ch].stat != 0) {
		D_0001291C[ch].stat = 0;
		D_000126BC[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_000126BC[ch].stat == 0)
		D_000126BC[ch].stat = 1;
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
	return sceAudioChangeChannelConfig(D_00012B90[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLength(D_00012B90[ch]);
}

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", D_00010914);

static int func_00004410(int prio)
{
	D_00011838 = 0;
	D_00012B7C.thid = sceKernelCreateThread("SceWaveMain", func_000044B4, prio, 0x1000, 0, NULL);
	if (D_00012B7C.thid < 0)
		return 0x80440003;
	D_00012B7C.prio = prio;
	if (sceKernelStartThread(D_00012B7C.thid, sizeof(SceWaveMain), &D_00012B7C) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_00011834 = 3;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", func_000044B4);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", func_000045D0);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", func_000047A8);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", func_000048EC);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", func_00004B88);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/libwave", func_000050A0);
