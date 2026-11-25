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

extern int D_005612EC;
extern int D_0008BF30;
extern char D_005612F4[];
extern char D_00561364[];
extern SceWaveVoice D_00562174[8];
extern SceWaveVoice D_005623D4[8];
extern SceWaveMain D_00562634;
extern void *D_00562640;
extern void *D_00562644;
extern int D_00562648[3];

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
int sceAudioGetChannelRestLen(int channel);
int sceKernelCreateThread(const char *name, void *entry, int initPriority, int stackSize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
int sceKernelDelayThread(unsigned int delay);
int sceKernelWaitThreadEnd(int thid, unsigned int *timeout);
int sceKernelDeleteThread(int thid);
int sceKernelExitThread(int status);
static int func_0001EA80(unsigned int args, void *argp);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", sceWaveInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", sceWaveSetVoice);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", sceWaveGetVolume);

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_00562174[ch].stat == 0)
		*rest = 0;
	else if (!(D_00562174[ch].flags & 0x400))
		*rest = D_00562174[ch].size - D_00562174[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_00562174[ch].stat;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", sceWavePlay);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", sceWavePlayEx);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", D_00030954);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", sceWaveStart);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", sceWaveEnd);

int sceWaveExit(void)
{
	if (D_005612EC != 1)
		return 0x80440002;
	sceAudioChRelease(D_00562634.ch);
	sceAudioChRelease(D_00562648[0]);
	sceAudioChRelease(D_00562648[1]);
	sceAudioChRelease(D_00562648[2]);
	D_00562640 = NULL;
	D_00562644 = NULL;
	D_005612EC = 0;
	return 0;
}

int sceWaveSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left >= 128)
		return 0x8044000A;
	if (right >= 128)
		return 0x8044000A;
	D_00562174[ch].vol_l = (int)(left << 12) / 127;
	D_00562174[ch].vol_r = (int)(right << 12) / 127;
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
	D_00562174[ch].vol_l = left;
	D_00562174[ch].vol_r = right;
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
	*left = D_00562174[ch].vol_l;
	*right = D_00562174[ch].vol_r;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_00562174[ch].flags = (D_00562174[ch].flags & ~0xff) | mode;
	return 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", sceWaveStop);

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_00562174[ch].stat != 0) {
		D_005623D4[ch].stat = 0;
		D_00562174[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_00562174[ch].stat == 0)
		D_00562174[ch].stat = 1;
	return 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", sceWaveAllStop);

int sceWaveAudioSetSample(unsigned int ch, int samplecount)
{
	if (ch >= 4)
		return 0x80440010;
	if ((unsigned int)(samplecount - 64) > 0xff80)
		return 0x80440011;
	if (samplecount & 0x3f)
		return 0x80440011;
	return sceAudioSetChannelDataLen(D_00562648[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_00562648[ch], left, right);
}

int sceWaveAudioSetFormat(unsigned int ch, int format)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioChangeChannelConfig(D_00562648[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLen(D_00562648[ch]);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_00562648[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_00562648[ch], left, right, buf);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", func_0001EA80);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", func_0001EB5C);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", func_0001ED14);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", func_0001EE58);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", func_0001F0F4);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", func_0001F60C);
