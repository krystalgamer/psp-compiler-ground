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

extern volatile int D_00012A6C;
extern volatile int D_00012A70;
extern char D_00012A74[];
extern char D_00012AE4[];
extern SceWaveVoice D_000138F4[8];
extern SceWaveVoice D_00013B54[8];
extern SceWaveMain D_00013DB4;
extern void *D_00013DC0;
extern void *D_00013DC4;
extern int D_00013DC8[3];

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
static int func_00005578(unsigned int args, void *argp);

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

	if (D_00012A6C != 0)
		return 0x80440001;
	D_00013DC4 = D_00012A74;
	D_00013DC0 = D_00012AE4;
	wclr(D_000138F4, sizeof(D_000138F4));
	wclr(D_00013B54, sizeof(D_00013B54));
	D_00013DB4.ch = sceAudioChReserve(-1, 0x1c0, 0);
	if (D_00013DB4.ch < 0)
		return 0x80440001;
	D_00013DC8[0] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00013DC8[0] < 0) {
		sceAudioChRelease(D_00013DB4.ch);
		return 0x80440001;
	}
	D_00013DC8[1] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00013DC8[1] < 0) {
		sceAudioChRelease(D_00013DB4.ch);
		sceAudioChRelease(D_00013DC8[0]);
		return 0x80440001;
	}
	D_00013DC8[2] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00013DC8[2] < 0) {
		sceAudioChRelease(D_00013DB4.ch);
		sceAudioChRelease(D_00013DC8[0]);
		sceAudioChRelease(D_00013DC8[1]);
		return 0x80440001;
	}
	D_00012A6C = 1;
	return 0;
}

int sceWaveSetVoice(unsigned int ch, void *data, int size, int flags)
{
	SceWaveVoice *v;

	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)size > 0x1800000)
		return 0x80440007;
	if (sceWaveGetStat(ch) != 0)
		return 0x80440009;
	if (!(flags & 0x400)) {
		if (data == NULL)
			return 0x80440006;
		if (size <= 0)
			return 0x80440007;
		v = &D_000138F4[ch];
		v->data = data;
		v->size = size;
		v->flags = flags;
		v->pos = 0;
		v->stat = 0;
		v->vol_l = 0x1000;
		v->vol_r = 0x1000;
		v->unk3C = 0x70;
		v->unk30 = 0;
		v->unk34 = 0;
		v->unk28 = 0;
		v->unk2C = 0;
		v->unk24 = 0;
		v->unk10 = 0;
		v->unk14 = 0;
		v->unk40 = 0;
	} else {
		if (data != NULL)
			return 0x80440006;
		if (size != 0)
			return 0x80440007;
		v = &D_000138F4[ch];
		v->data = data;
		v->size = size;
		v->flags = flags;
		v->pos = 0;
		v->stat = 0;
		v->vol_l = 0x1000;
		v->vol_r = 0x1000;
		v->unk3C = 0x70;
		v->unk30 = 0;
		v->unk34 = 0;
		v->unk28 = 0;
		v->unk2C = 0;
		v->unk24 = 0;
		v->unk10 = 0;
		v->unk14 = 0;
		v->unk40 = 0;
	}
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
	D_000138F4[ch].vol_l = (int)(left << 12) / 127;
	D_000138F4[ch].vol_r = (int)(right << 12) / 127;
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
	if (D_000138F4[ch].vol_l <= 0)
		*left = 0;
	else if (D_000138F4[ch].vol_l >= 128)
		*left = (D_000138F4[ch].vol_l - 1) / 32;
	else
		*left = D_000138F4[ch].vol_l / 32;
	if (D_000138F4[ch].vol_r <= 0)
		*right = 0;
	else if (D_000138F4[ch].vol_r >= 128)
		*right = (D_000138F4[ch].vol_r - 1) / 32;
	else
		*right = D_000138F4[ch].vol_r / 32;
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
	D_000138F4[ch].vol_l = left;
	D_000138F4[ch].vol_r = right;
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
	*left = D_000138F4[ch].vol_l;
	*right = D_000138F4[ch].vol_r;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_000138F4[ch].stat == 0)
		*rest = 0;
	else if (!(D_000138F4[ch].flags & 0x400))
		*rest = D_000138F4[ch].size - D_000138F4[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_000138F4[ch].stat;
}

int sceWavePlay(unsigned int ch, int left, int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left < 0 || left >= 128)
		return 0x8044000A;
	if (right < 0 || right >= 128)
		return 0x8044000A;
	if (D_000138F4[ch].data == NULL && !(D_000138F4[ch].flags & 0x400))
		return 0x80440006;
	if (D_000138F4[ch].stat != 0) {
		D_000138F4[ch].flags |= 0x110000;
		D_00013B54[ch].stat = 1;
		D_00013B54[ch].vol_l = left * 0x1000 / 127;
		D_00013B54[ch].vol_r = right * 0x1000 / 127;
		D_00013B54[ch].pos = 0;
		D_00013B54[ch].unk30 = 0;
		D_00013B54[ch].unk34 = 0;
		D_00013B54[ch].unk28 = 0;
		D_00013B54[ch].unk2C = 0;
	} else {
		D_000138F4[ch].stat = 1;
		D_000138F4[ch].vol_l = left * 0x1000 / 127;
		D_000138F4[ch].vol_r = right * 0x1000 / 127;
		D_000138F4[ch].pos = 0;
		D_000138F4[ch].unk30 = 0;
		D_000138F4[ch].unk34 = 0;
		D_000138F4[ch].unk28 = 0;
		D_000138F4[ch].unk2C = 0;
	}
	return 0;
}

int sceWavePlayEx(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left > 0x1000)
		return 0x8044000A;
	if (right > 0x1000)
		return 0x8044000A;
	if (D_000138F4[ch].data == NULL && !(D_000138F4[ch].flags & 0x400))
		return 0x80440006;
	if (D_000138F4[ch].stat != 0) {
		D_000138F4[ch].flags |= 0x110000;
		D_00013B54[ch].stat = 1;
		D_00013B54[ch].vol_l = left;
		D_00013B54[ch].vol_r = right;
		D_00013B54[ch].pos = 0;
		D_00013B54[ch].unk30 = 0;
		D_00013B54[ch].unk34 = 0;
		D_00013B54[ch].unk28 = 0;
		D_00013B54[ch].unk2C = 0;
	} else {
		D_000138F4[ch].stat = 1;
		D_000138F4[ch].vol_l = left;
		D_000138F4[ch].vol_r = right;
		D_000138F4[ch].pos = 0;
		D_000138F4[ch].unk30 = 0;
		D_000138F4[ch].unk34 = 0;
		D_000138F4[ch].unk28 = 0;
		D_000138F4[ch].unk2C = 0;
	}
	return 0;
}

int sceWaveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_000138F4[ch].stat != 0) {
			D_000138F4[ch].flags |= 0x120000;
			D_00013B54[ch].stat = 0;
			D_00013B54[ch].pos = 0;
			D_00013B54[ch].unk30 = 0;
			D_00013B54[ch].unk34 = 0;
			D_00013B54[ch].unk28 = 0;
			D_00013B54[ch].unk2C = 0;
		} else {
			D_000138F4[ch].pos = 0;
			D_000138F4[ch].unk30 = 0;
			D_000138F4[ch].unk34 = 0;
			D_000138F4[ch].unk28 = 0;
			D_000138F4[ch].unk2C = 0;
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
	return sceAudioSetChannelDataLen(D_00013DC8[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_00013DC8[ch], left, right);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_00013DC8[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_00013DC8[ch], left, right, buf);
}

int sceWaveStart(int prio)
{
	if (D_00012A6C != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return func_000054D4(prio);
}

int sceWaveEnd(void)
{
	int i;

	if (D_00012A6C != 3)
		return 0x80440004;
	for (i = 0; i < 8; i++)
		sceWaveStop(i);
	D_00012A70 = 1;
	sceKernelWaitThreadEnd(D_00013DB4.thid, NULL);
	sceKernelDeleteThread(D_00013DB4.thid);
	D_00012A70 = 0;
	D_00012A6C = 1;
	return 0;
}

int sceWaveExit(void)
{
	if (D_00012A6C != 1)
		return 0x80440002;
	sceAudioChRelease(D_00013DB4.ch);
	sceAudioChRelease(D_00013DC8[0]);
	sceAudioChRelease(D_00013DC8[1]);
	sceAudioChRelease(D_00013DC8[2]);
	D_00013DC0 = NULL;
	D_00013DC4 = NULL;
	D_00012A6C = 0;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_000138F4[ch].flags = (D_000138F4[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_000138F4[ch].stat != 0) {
		D_00013B54[ch].stat = 0;
		D_000138F4[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_000138F4[ch].stat == 0)
		D_000138F4[ch].stat = 1;
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
	return sceAudioChangeChannelConfig(D_00013DC8[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLength(D_00013DC8[ch]);
}

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/libwave", D_00011CD0);

static int func_000054D4(int prio)
{
	D_00012A70 = 0;
	D_00013DB4.thid = sceKernelCreateThread("SceWaveMain", func_00005578, prio, 0x1000, 0, NULL);
	if (D_00013DB4.thid < 0)
		return 0x80440003;
	D_00013DB4.prio = prio;
	if (sceKernelStartThread(D_00013DB4.thid, sizeof(SceWaveMain), &D_00013DB4) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_00012A6C = 3;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/libwave", func_00005578);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/libwave", func_00005694);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/libwave", func_0000586C);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/libwave", func_000059B0);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/libwave", func_00005C4C);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/libwave", func_00006164);
