/* cflags: -O2 -frename-registers */
#include "common.h"
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

extern volatile int D_0012E6F4;
extern volatile int D_0012E6F8;
extern char D_0012E6FC[];
extern char D_0012E76C[];
extern SceWaveVoice D_0012F57C[8];
extern SceWaveVoice D_0012F7DC[8];
extern SceWaveMain D_0012FA3C;
extern void *D_0012FA48;
extern void *D_0012FA4C;
extern int D_0012FA50[3];

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
extern char D_0012E77C[2][0x700];
typedef int (*SceWaveCallback)(int ch, void *buf, int size, int arg);
static int func_0009B950(char *buf);
static int func_0009BB38(short *dst, unsigned char *src, int *h1, int *h2);
static void func_0009BC70(int ch, void *dst);
static void func_0009BF1C(int ch, void *dst);
static void func_0009C48C(int ch, short *out, short *src);
static int func_0009B838(unsigned int args, void *argp);




static __inline__ void wclr_i(void *dst, unsigned int n)
{
	char *p = dst;
	unsigned int i;

	for (i = 0; i < n; i++)
		*p++ = 0;
}

int sceWaveInit(void)
{
	if (D_0012E6F4 != 0)
		return 0x80440001;
	D_0012FA4C = D_0012E6FC;
	D_0012FA48 = D_0012E76C;
	wclr_i(D_0012F57C, sizeof(D_0012F57C));
	wclr_i(D_0012F7DC, sizeof(D_0012F7DC));
	D_0012FA3C.ch = sceAudioChReserve(-1, 0x1c0, 0);
	if (D_0012FA3C.ch < 0)
		return 0x80440001;
	D_0012FA50[0] = sceAudioChReserve(-1, 0x100, 0);
	if (D_0012FA50[0] < 0) {
		sceAudioChRelease(D_0012FA3C.ch);
		return 0x80440001;
	}
	D_0012FA50[1] = sceAudioChReserve(-1, 0x100, 0);
	if (D_0012FA50[1] < 0) {
		sceAudioChRelease(D_0012FA3C.ch);
		sceAudioChRelease(D_0012FA50[0]);
		return 0x80440001;
	}
	D_0012FA50[2] = sceAudioChReserve(-1, 0x100, 0);
	if (D_0012FA50[2] < 0) {
		sceAudioChRelease(D_0012FA3C.ch);
		sceAudioChRelease(D_0012FA50[0]);
		sceAudioChRelease(D_0012FA50[1]);
		return 0x80440001;
	}
	D_0012E6F4 = 1;
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
		if (size == 0)
			return 0x80440007;
		v = &D_0012F57C[ch];
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
		v = &D_0012F57C[ch];
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
	D_0012F57C[ch].vol_l = (int)(left << 12) / 127;
	D_0012F57C[ch].vol_r = (int)(right << 12) / 127;
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
	if (D_0012F57C[ch].vol_l <= 0)
		*left = 0;
	else if (D_0012F57C[ch].vol_l >= 128)
		*left = (D_0012F57C[ch].vol_l - 1) / 32;
	else
		*left = D_0012F57C[ch].vol_l / 32;
	if (D_0012F57C[ch].vol_r <= 0)
		*right = 0;
	else if (D_0012F57C[ch].vol_r >= 128)
		*right = (D_0012F57C[ch].vol_r - 1) / 32;
	else
		*right = D_0012F57C[ch].vol_r / 32;
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
	D_0012F57C[ch].vol_l = left;
	D_0012F57C[ch].vol_r = right;
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
	*left = D_0012F57C[ch].vol_l;
	*right = D_0012F57C[ch].vol_r;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_0012F57C[ch].stat == 0)
		*rest = 0;
	else if (!(D_0012F57C[ch].flags & 0x400))
		*rest = D_0012F57C[ch].size - D_0012F57C[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_0012F57C[ch].stat;
}

int sceWavePlay(unsigned int ch, int left, int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left < 0 || left >= 128)
		return 0x8044000A;
	if (right < 0 || right >= 128)
		return 0x8044000A;
	if (D_0012F57C[ch].data == NULL && !(D_0012F57C[ch].flags & 0x400))
		return 0x80440006;
	if (D_0012F57C[ch].stat != 0) {
		D_0012F57C[ch].flags |= 0x110000;
		D_0012F7DC[ch].stat = 1;
		D_0012F7DC[ch].vol_l = left * 0x1000 / 127;
		D_0012F7DC[ch].vol_r = right * 0x1000 / 127;
		D_0012F7DC[ch].pos = 0;
		D_0012F7DC[ch].unk30 = 0;
		D_0012F7DC[ch].unk34 = 0;
		D_0012F7DC[ch].unk28 = 0;
		D_0012F7DC[ch].unk2C = 0;
	} else {
		D_0012F57C[ch].stat = 1;
		D_0012F57C[ch].vol_l = left * 0x1000 / 127;
		D_0012F57C[ch].vol_r = right * 0x1000 / 127;
		D_0012F57C[ch].pos = 0;
		D_0012F57C[ch].unk30 = 0;
		D_0012F57C[ch].unk34 = 0;
		D_0012F57C[ch].unk28 = 0;
		D_0012F57C[ch].unk2C = 0;
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
	if (D_0012F57C[ch].data == NULL && !(D_0012F57C[ch].flags & 0x400))
		return 0x80440006;
	if (D_0012F57C[ch].stat != 0) {
		D_0012F57C[ch].flags |= 0x110000;
		D_0012F7DC[ch].stat = 1;
		D_0012F7DC[ch].vol_l = left;
		D_0012F7DC[ch].vol_r = right;
		D_0012F7DC[ch].pos = 0;
		D_0012F7DC[ch].unk30 = 0;
		D_0012F7DC[ch].unk34 = 0;
		D_0012F7DC[ch].unk28 = 0;
		D_0012F7DC[ch].unk2C = 0;
	} else {
		D_0012F57C[ch].stat = 1;
		D_0012F57C[ch].vol_l = left;
		D_0012F57C[ch].vol_r = right;
		D_0012F57C[ch].pos = 0;
		D_0012F57C[ch].unk30 = 0;
		D_0012F57C[ch].unk34 = 0;
		D_0012F57C[ch].unk28 = 0;
		D_0012F57C[ch].unk2C = 0;
	}
	return 0;
}

int sceWaveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_0012F57C[ch].stat != 0) {
			D_0012F57C[ch].flags |= 0x120000;
			D_0012F7DC[ch].stat = 0;
			D_0012F7DC[ch].pos = 0;
			D_0012F7DC[ch].unk30 = 0;
			D_0012F7DC[ch].unk34 = 0;
			D_0012F7DC[ch].unk28 = 0;
			D_0012F7DC[ch].unk2C = 0;
		} else {
			D_0012F57C[ch].pos = 0;
			D_0012F57C[ch].unk30 = 0;
			D_0012F57C[ch].unk34 = 0;
			D_0012F57C[ch].unk28 = 0;
			D_0012F57C[ch].unk2C = 0;
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
	return sceAudioSetChannelDataLen(D_0012FA50[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_0012FA50[ch], left, right);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_0012FA50[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_0012FA50[ch], left, right, buf);
}

int sceWaveStart(int prio)
{
	if (D_0012E6F4 != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return func_0009B794(prio);
}

int sceKernelDeleteThread(int thid);
int sceWaveEnd(void)
{
	int i;

	if (D_0012E6F4 != 3)
		return 0x80440004;
	for (i = 0; i < 8; i++)
		sceWaveStop(i);
	D_0012E6F8 = 1;
	sceKernelWaitThreadEnd(D_0012FA3C.thid, NULL);
	sceKernelDeleteThread(D_0012FA3C.thid);
	D_0012E6F8 = 0;
	D_0012E6F4 = 1;
	return 0;
}

int sceWaveExit(void)
{
	if (D_0012E6F4 != 1)
		return 0x80440002;
	sceAudioChRelease(D_0012FA3C.ch);
	sceAudioChRelease(D_0012FA50[0]);
	sceAudioChRelease(D_0012FA50[1]);
	sceAudioChRelease(D_0012FA50[2]);
	D_0012FA48 = NULL;
	D_0012FA4C = NULL;
	D_0012E6F4 = 0;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_0012F57C[ch].flags = (D_0012F57C[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_0012F57C[ch].stat != 0) {
		D_0012F7DC[ch].stat = 0;
		D_0012F57C[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_0012F57C[ch].stat == 0)
		D_0012F57C[ch].stat = 1;
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
	return sceAudioChangeChannelConfig(D_0012FA50[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLength(D_0012FA50[ch]);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/libwave", D_0010C108);

static int func_0009B794(int prio)
{
	D_0012E6F8 = 0;
	D_0012FA3C.thid = sceKernelCreateThread("SceWaveMain", func_0009B838, prio, 0x1000, 0, NULL);
	if (D_0012FA3C.thid < 0)
		return 0x80440003;
	D_0012FA3C.prio = prio;
	if (sceKernelStartThread(D_0012FA3C.thid, sizeof(SceWaveMain), &D_0012FA3C) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_0012E6F4 = 3;
	return 0;
}

static int func_0009B838(unsigned int args, void *argp)
{
	SceWaveMain *m = (SceWaveMain *)argp;
	int i = 0;
	int j;

	while (D_0012E6F8 == 0) {
		if (func_0009B950(D_0012E77C[i]) == 0) {
			sceKernelDelayThread(10000);
			continue;
		}
		for (j = 1; j < 16; j++)
			func_0009B950(D_0012E77C[i] + j * 0x70);
		sceAudioOutputBlocking(m->ch, 0x8000, D_0012E77C[i]);
		i = (i + 1) % 2;
	}
	sceAudioOutputBlocking(m->ch, 0, NULL);
	sceKernelExitThread(0);
	return 0;
}


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libwave", func_0009B950);

extern const signed char D_0010C108[2][5];
static int func_0009BB38(short *dst, unsigned char *vag, int *hist1, int *hist2)
{
	short *out;
	int predict, shift, flags;
	int s1, s2, f0, f1, i, k;
	int d0, d1;

	k = 2;
	flags = vag[0];
	predict = flags >> 4;
	shift = flags & 0xF;
	flags = vag[1];
	s1 = *hist1;
	s2 = *hist2;
	f0 = D_0010C108[0][predict];
	f1 = D_0010C108[1][predict];
	if (flags == 7)
		return flags;
	out = dst;
	for (i = 0; i < 14; i++) {
		signed char b = vag[k++];

		d0 = (((b << 28) >> (shift + 10)) + (s1 * f0 + s2 * f1)) >> 6;
		if (d0 > 32767) d0 = 32767;
		if (d0 < -32768) d0 = -32768;
		*out++ = d0;
		d1 = (((b & ~0xF) << (14 - shift)) + (d0 * f0 + s1 * f1)) >> 6;
		if (d1 > 32767) d1 = 32767;
		if (d1 < -32768) d1 = -32768;
		*out++ = d1;
		s2 = d0;
		s1 = d1;
	}
	*hist1 = s1;
	*hist2 = s2;
	return flags;
}





INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libwave", func_0009BC70);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libwave", func_0009BF1C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libwave", func_0009C48C);

