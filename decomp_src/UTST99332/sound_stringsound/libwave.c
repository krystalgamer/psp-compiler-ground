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

extern volatile int D_00043938;
extern volatile int D_0004393C;
extern char D_00043940[];
extern char D_000439B0[];
extern SceWaveVoice D_000447C0[8];
extern SceWaveVoice D_00044A20[8];
extern SceWaveMain D_00044C80;
extern void *D_00044C8C;
extern void *D_00044C90;
extern int D_00044C94[3];

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
static int func_00009C4C(unsigned int args, void *argp);

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

	if (D_00043938 != 0)
		return 0x80440001;
	D_00044C90 = D_00043940;
	D_00044C8C = D_000439B0;
	wclr(D_000447C0, sizeof(D_000447C0));
	wclr(D_00044A20, sizeof(D_00044A20));
	D_00044C80.ch = sceAudioChReserve(-1, 0x1c0, 0);
	if (D_00044C80.ch < 0)
		return 0x80440001;
	D_00044C94[0] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00044C94[0] < 0) {
		sceAudioChRelease(D_00044C80.ch);
		return 0x80440001;
	}
	D_00044C94[1] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00044C94[1] < 0) {
		sceAudioChRelease(D_00044C80.ch);
		sceAudioChRelease(D_00044C94[0]);
		return 0x80440001;
	}
	D_00044C94[2] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00044C94[2] < 0) {
		sceAudioChRelease(D_00044C80.ch);
		sceAudioChRelease(D_00044C94[0]);
		sceAudioChRelease(D_00044C94[1]);
		return 0x80440001;
	}
	D_00043938 = 1;
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
		v = &D_000447C0[ch];
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
		v = &D_000447C0[ch];
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
	D_000447C0[ch].vol_l = (int)(left << 12) / 127;
	D_000447C0[ch].vol_r = (int)(right << 12) / 127;
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
	if (D_000447C0[ch].vol_l <= 0)
		*left = 0;
	else if (D_000447C0[ch].vol_l >= 128)
		*left = (D_000447C0[ch].vol_l - 1) / 32;
	else
		*left = D_000447C0[ch].vol_l / 32;
	if (D_000447C0[ch].vol_r <= 0)
		*right = 0;
	else if (D_000447C0[ch].vol_r >= 128)
		*right = (D_000447C0[ch].vol_r - 1) / 32;
	else
		*right = D_000447C0[ch].vol_r / 32;
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
	D_000447C0[ch].vol_l = left;
	D_000447C0[ch].vol_r = right;
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
	*left = D_000447C0[ch].vol_l;
	*right = D_000447C0[ch].vol_r;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_000447C0[ch].stat == 0)
		*rest = 0;
	else if (!(D_000447C0[ch].flags & 0x400))
		*rest = D_000447C0[ch].size - D_000447C0[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_000447C0[ch].stat;
}

int sceWavePlay(unsigned int ch, int left, int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left < 0 || left >= 128)
		return 0x8044000A;
	if (right < 0 || right >= 128)
		return 0x8044000A;
	if (D_000447C0[ch].data == NULL && !(D_000447C0[ch].flags & 0x400))
		return 0x80440006;
	if (D_000447C0[ch].stat != 0) {
		D_000447C0[ch].flags |= 0x110000;
		D_00044A20[ch].stat = 1;
		D_00044A20[ch].vol_l = left * 0x1000 / 127;
		D_00044A20[ch].vol_r = right * 0x1000 / 127;
		D_00044A20[ch].pos = 0;
		D_00044A20[ch].unk30 = 0;
		D_00044A20[ch].unk34 = 0;
		D_00044A20[ch].unk28 = 0;
		D_00044A20[ch].unk2C = 0;
	} else {
		D_000447C0[ch].stat = 1;
		D_000447C0[ch].vol_l = left * 0x1000 / 127;
		D_000447C0[ch].vol_r = right * 0x1000 / 127;
		D_000447C0[ch].pos = 0;
		D_000447C0[ch].unk30 = 0;
		D_000447C0[ch].unk34 = 0;
		D_000447C0[ch].unk28 = 0;
		D_000447C0[ch].unk2C = 0;
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
	if (D_000447C0[ch].data == NULL && !(D_000447C0[ch].flags & 0x400))
		return 0x80440006;
	if (D_000447C0[ch].stat != 0) {
		D_000447C0[ch].flags |= 0x110000;
		D_00044A20[ch].stat = 1;
		D_00044A20[ch].vol_l = left;
		D_00044A20[ch].vol_r = right;
		D_00044A20[ch].pos = 0;
		D_00044A20[ch].unk30 = 0;
		D_00044A20[ch].unk34 = 0;
		D_00044A20[ch].unk28 = 0;
		D_00044A20[ch].unk2C = 0;
	} else {
		D_000447C0[ch].stat = 1;
		D_000447C0[ch].vol_l = left;
		D_000447C0[ch].vol_r = right;
		D_000447C0[ch].pos = 0;
		D_000447C0[ch].unk30 = 0;
		D_000447C0[ch].unk34 = 0;
		D_000447C0[ch].unk28 = 0;
		D_000447C0[ch].unk2C = 0;
	}
	return 0;
}

int sceWaveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_000447C0[ch].stat != 0) {
			D_000447C0[ch].flags |= 0x120000;
			D_00044A20[ch].stat = 0;
			D_00044A20[ch].pos = 0;
			D_00044A20[ch].unk30 = 0;
			D_00044A20[ch].unk34 = 0;
			D_00044A20[ch].unk28 = 0;
			D_00044A20[ch].unk2C = 0;
		} else {
			D_000447C0[ch].pos = 0;
			D_000447C0[ch].unk30 = 0;
			D_000447C0[ch].unk34 = 0;
			D_000447C0[ch].unk28 = 0;
			D_000447C0[ch].unk2C = 0;
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
	return sceAudioSetChannelDataLen(D_00044C94[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_00044C94[ch], left, right);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_00044C94[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_00044C94[ch], left, right, buf);
}

int sceWaveStart(int prio)
{
	if (D_00043938 != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return func_00009BA8(prio);
}

int sceWaveEnd(void)
{
	int i;

	if (D_00043938 != 3)
		return 0x80440004;
	for (i = 0; i < 8; i++)
		sceWaveStop(i);
	D_0004393C = 1;
	sceKernelWaitThreadEnd(D_00044C80.thid, NULL);
	sceKernelDeleteThread(D_00044C80.thid);
	D_0004393C = 0;
	D_00043938 = 1;
	return 0;
}

int sceWaveExit(void)
{
	if (D_00043938 != 1)
		return 0x80440002;
	sceAudioChRelease(D_00044C80.ch);
	sceAudioChRelease(D_00044C94[0]);
	sceAudioChRelease(D_00044C94[1]);
	sceAudioChRelease(D_00044C94[2]);
	D_00044C8C = NULL;
	D_00044C90 = NULL;
	D_00043938 = 0;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_000447C0[ch].flags = (D_000447C0[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_000447C0[ch].stat != 0) {
		D_00044A20[ch].stat = 0;
		D_000447C0[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_000447C0[ch].stat == 0)
		D_000447C0[ch].stat = 1;
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
	return sceAudioChangeChannelConfig(D_00044C94[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLength(D_00044C94[ch]);
}

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/libwave", D_000208C4);

static int func_00009BA8(int prio)
{
	D_0004393C = 0;
	D_00044C80.thid = sceKernelCreateThread("SceWaveMain", func_00009C4C, prio, 0x1000, 0, NULL);
	if (D_00044C80.thid < 0)
		return 0x80440003;
	D_00044C80.prio = prio;
	if (sceKernelStartThread(D_00044C80.thid, sizeof(SceWaveMain), &D_00044C80) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_00043938 = 3;
	return 0;
}

extern char D_000439C0[2][0x700];
static int func_00009D68(char *buf);

static int func_00009C4C(unsigned int args, void *argp)
{
	SceWaveMain *m = (SceWaveMain *)argp;
	int i = 0;
	int j;

	while (D_0004393C == 0) {
		if (func_00009D68(D_000439C0[i]) == 0) {
			sceKernelDelayThread(10000);
			continue;
		}
		for (j = 1; j < 16; j++)
			func_00009D68(D_000439C0[i] + j * 0x70);
		sceAudioOutputBlocking(m->ch, 0x8000, D_000439C0[i]);
		i = (i + 1) % 2;
	}
	sceAudioOutputBlocking(m->ch, 0, NULL);
	sceKernelExitThread(0);
	return 0;
}

static void func_00009F40(void *dst, void *src, int *a, int *b);
static void func_0000A084(int ch, void *buf);
static void func_0000A320(int ch, void *buf);
static void func_0000A838(int ch, char *dst, void *src);
typedef int (*SceWaveCallback)(int ch, void *buf, int size, int arg);

static int func_00009D68(char *buf)
{
	int ch;
	int n = 0;

	wclr(buf, 0x70);
	for (ch = 0; ch < 8; ch++) {
		if (D_000447C0[ch].stat == 0)
			continue;
		n++;
		if (!(D_000447C0[ch].flags & 0x400)) {
			if (!(D_000447C0[ch].flags & 0x100)) {
				if (D_000447C0[ch].data != NULL)
					func_0000A084(ch, D_00044C90);
			} else {
				if (D_000447C0[ch].data != NULL)
					func_0000A320(ch, D_00044C90);
			}
		} else {
			if (D_000447C0[ch].unk44 != 0) {
				wclr(D_00044C90, 0x70);
				if (!(D_000447C0[ch].flags & 0x100)) {
					if (((SceWaveCallback)D_000447C0[ch].unk44)(ch, D_00044C8C, 0x10, D_000447C0[ch].unk48))
						D_000447C0[ch].stat = 0;
					func_00009F40(D_00044C90, D_00044C8C, &D_000447C0[ch].unk30, &D_000447C0[ch].unk34);
				} else {
					if (((SceWaveCallback)D_000447C0[ch].unk44)(ch, D_00044C90, 0x70, D_000447C0[ch].unk48))
						D_000447C0[ch].stat = 0;
				}
			}
		}
		func_0000A838(ch, buf, D_00044C90);
	}
	return n;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/libwave", func_00009F40);

INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/libwave", func_0000A084);

INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/libwave", func_0000A320);

INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/libwave", func_0000A838);
