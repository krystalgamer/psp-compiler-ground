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

extern volatile int D_0007ADB4;
extern volatile int D_0007ADB8;
extern char D_0007ADBC[];
extern char D_0007AE2C[];
extern SceWaveVoice D_0007BC3C[8];
extern SceWaveVoice D_0007BE9C[8];
extern SceWaveMain D_0007C0FC;
extern void *D_0007C108;
extern void *D_0007C10C;
extern int D_0007C110[3];

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
static int func_00009BA8(unsigned int args, void *argp);

static __inline__ void wclr(void *dst, int n)
{
	char *p = dst;
	int i;

	for (i = 0; i < n; i++)
		*p++ = 0;
}

int sceWaveInit(void)
{
	int i;
	char *p;

	if (D_0007ADB4 != 0)
		return 0x80440001;
	D_0007C10C = D_0007ADBC;
	D_0007C108 = D_0007AE2C;
	wclr(D_0007BC3C, sizeof(D_0007BC3C));
	wclr(D_0007BE9C, sizeof(D_0007BE9C));
	D_0007C0FC.ch = sceAudioChReserve(-1, 0x1c0, 0);
	if (D_0007C0FC.ch < 0)
		return 0x80440001;
	D_0007C110[0] = sceAudioChReserve(-1, 0x100, 0);
	if (D_0007C110[0] < 0) {
		sceAudioChRelease(D_0007C0FC.ch);
		return 0x80440001;
	}
	D_0007C110[1] = sceAudioChReserve(-1, 0x100, 0);
	if (D_0007C110[1] < 0) {
		sceAudioChRelease(D_0007C0FC.ch);
		sceAudioChRelease(D_0007C110[0]);
		return 0x80440001;
	}
	D_0007C110[2] = sceAudioChReserve(-1, 0x100, 0);
	if (D_0007C110[2] < 0) {
		sceAudioChRelease(D_0007C0FC.ch);
		sceAudioChRelease(D_0007C110[0]);
		sceAudioChRelease(D_0007C110[1]);
		return 0x80440001;
	}
	D_0007ADB4 = 1;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/libwave", sceWaveSetVoice);

int sceWaveSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left >= 128)
		return 0x8044000A;
	if (right >= 128)
		return 0x8044000A;
	D_0007BC3C[ch].vol_l = (int)(left << 12) / 127;
	D_0007BC3C[ch].vol_r = (int)(right << 12) / 127;
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
	if (D_0007BC3C[ch].vol_l <= 0)
		*left = 0;
	else if (D_0007BC3C[ch].vol_l >= 128)
		*left = (D_0007BC3C[ch].vol_l - 1) / 32;
	else
		*left = D_0007BC3C[ch].vol_l / 32;
	if (D_0007BC3C[ch].vol_r <= 0)
		*right = 0;
	else if (D_0007BC3C[ch].vol_r >= 128)
		*right = (D_0007BC3C[ch].vol_r - 1) / 32;
	else
		*right = D_0007BC3C[ch].vol_r / 32;
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
	D_0007BC3C[ch].vol_l = left;
	D_0007BC3C[ch].vol_r = right;
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
	*left = D_0007BC3C[ch].vol_l;
	*right = D_0007BC3C[ch].vol_r;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_0007BC3C[ch].stat == 0)
		*rest = 0;
	else if (!(D_0007BC3C[ch].flags & 0x400))
		*rest = D_0007BC3C[ch].size - D_0007BC3C[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_0007BC3C[ch].stat;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/libwave", sceWavePlay);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/libwave", sceWavePlayEx);

int sceWaveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_0007BC3C[ch].stat != 0) {
			D_0007BC3C[ch].flags |= 0x120000;
			D_0007BE9C[ch].stat = 0;
			D_0007BE9C[ch].pos = 0;
			D_0007BE9C[ch].unk30 = 0;
			D_0007BE9C[ch].unk34 = 0;
			D_0007BE9C[ch].unk28 = 0;
			D_0007BE9C[ch].unk2C = 0;
		} else {
			D_0007BC3C[ch].pos = 0;
			D_0007BC3C[ch].unk30 = 0;
			D_0007BC3C[ch].unk34 = 0;
			D_0007BC3C[ch].unk28 = 0;
			D_0007BC3C[ch].unk2C = 0;
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
	return sceAudioSetChannelDataLen(D_0007C110[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_0007C110[ch], left, right);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_0007C110[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_0007C110[ch], left, right, buf);
}

int sceWaveStart(int prio)
{
	if (D_0007ADB4 != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return func_00009B04(prio);
}

int sceWaveEnd(void)
{
	int i;

	if (D_0007ADB4 != 3)
		return 0x80440004;
	for (i = 0; i < 8; i++)
		sceWaveStop(i);
	D_0007ADB8 = 1;
	sceKernelWaitThreadEnd(D_0007C0FC.thid, NULL);
	sceKernelDeleteThread(D_0007C0FC.thid);
	D_0007ADB8 = 0;
	D_0007ADB4 = 1;
	return 0;
}

int sceWaveExit(void)
{
	if (D_0007ADB4 != 1)
		return 0x80440002;
	sceAudioChRelease(D_0007C0FC.ch);
	sceAudioChRelease(D_0007C110[0]);
	sceAudioChRelease(D_0007C110[1]);
	sceAudioChRelease(D_0007C110[2]);
	D_0007C108 = NULL;
	D_0007C10C = NULL;
	D_0007ADB4 = 0;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_0007BC3C[ch].flags = (D_0007BC3C[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_0007BC3C[ch].stat != 0) {
		D_0007BE9C[ch].stat = 0;
		D_0007BC3C[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_0007BC3C[ch].stat == 0)
		D_0007BC3C[ch].stat = 1;
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
	return sceAudioChangeChannelConfig(D_0007C110[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLength(D_0007C110[ch]);
}

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3mix/nonmatchings/libwave", D_00020E94);

static int func_00009B04(int prio)
{
	D_0007ADB8 = 0;
	D_0007C0FC.thid = sceKernelCreateThread("SceWaveMain", func_00009BA8, prio, 0x1000, 0, NULL);
	if (D_0007C0FC.thid < 0)
		return 0x80440003;
	D_0007C0FC.prio = prio;
	if (sceKernelStartThread(D_0007C0FC.thid, sizeof(SceWaveMain), &D_0007C0FC) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_0007ADB4 = 3;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/libwave", func_00009BA8);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/libwave", func_00009CC4);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/libwave", func_00009E9C);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/libwave", func_00009FE0);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/libwave", func_0000A27C);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/libwave", func_0000A794);
