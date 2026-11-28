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

extern volatile int D_000431B8;
extern volatile int D_000431BC;
extern char D_000431C0[];
extern char D_00043230[];
extern SceWaveVoice D_00044040[8];
extern SceWaveVoice D_000442A0[8];
extern SceWaveMain D_00044500;
extern void *D_0004450C;
extern void *D_00044510;
extern int D_00044514[3];

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
static int func_00009724(unsigned int args, void *argp);

static __inline__ void wclr(void *dst, int n)
{
	char *p = dst;
	int i;

	for (i = 0; i < n; i++)
		*p++ = 0;
}

static __inline__ void wcpy(void *dst, const void *src, int n)
{
	char *d = dst;
	const char *s = src;
	int i;

	for (i = 0; i < n; i++)
		*d++ = *s++;
}

int sceWaveInit(void)
{
	int i;
	char *p;

	if (D_000431B8 != 0)
		return 0x80440001;
	D_00044510 = D_000431C0;
	D_0004450C = D_00043230;
	wclr(D_00044040, sizeof(D_00044040));
	wclr(D_000442A0, sizeof(D_000442A0));
	D_00044500.ch = sceAudioChReserve(-1, 0x1c0, 0);
	if (D_00044500.ch < 0)
		return 0x80440001;
	D_00044514[0] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00044514[0] < 0) {
		sceAudioChRelease(D_00044500.ch);
		return 0x80440001;
	}
	D_00044514[1] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00044514[1] < 0) {
		sceAudioChRelease(D_00044500.ch);
		sceAudioChRelease(D_00044514[0]);
		return 0x80440001;
	}
	D_00044514[2] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00044514[2] < 0) {
		sceAudioChRelease(D_00044500.ch);
		sceAudioChRelease(D_00044514[0]);
		sceAudioChRelease(D_00044514[1]);
		return 0x80440001;
	}
	D_000431B8 = 1;
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
		v = &D_00044040[ch];
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
		v = &D_00044040[ch];
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
	D_00044040[ch].vol_l = (int)(left << 12) / 127;
	D_00044040[ch].vol_r = (int)(right << 12) / 127;
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
	if (D_00044040[ch].vol_l <= 0)
		*left = 0;
	else if (D_00044040[ch].vol_l >= 128)
		*left = (D_00044040[ch].vol_l - 1) / 32;
	else
		*left = D_00044040[ch].vol_l / 32;
	if (D_00044040[ch].vol_r <= 0)
		*right = 0;
	else if (D_00044040[ch].vol_r >= 128)
		*right = (D_00044040[ch].vol_r - 1) / 32;
	else
		*right = D_00044040[ch].vol_r / 32;
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
	D_00044040[ch].vol_l = left;
	D_00044040[ch].vol_r = right;
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
	*left = D_00044040[ch].vol_l;
	*right = D_00044040[ch].vol_r;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_00044040[ch].stat == 0)
		*rest = 0;
	else if (!(D_00044040[ch].flags & 0x400))
		*rest = D_00044040[ch].size - D_00044040[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_00044040[ch].stat;
}

int sceWavePlay(unsigned int ch, int left, int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left < 0 || left >= 128)
		return 0x8044000A;
	if (right < 0 || right >= 128)
		return 0x8044000A;
	if (D_00044040[ch].data == NULL && !(D_00044040[ch].flags & 0x400))
		return 0x80440006;
	if (D_00044040[ch].stat != 0) {
		D_00044040[ch].flags |= 0x110000;
		D_000442A0[ch].stat = 1;
		D_000442A0[ch].vol_l = left * 0x1000 / 127;
		D_000442A0[ch].vol_r = right * 0x1000 / 127;
		D_000442A0[ch].pos = 0;
		D_000442A0[ch].unk30 = 0;
		D_000442A0[ch].unk34 = 0;
		D_000442A0[ch].unk28 = 0;
		D_000442A0[ch].unk2C = 0;
	} else {
		D_00044040[ch].stat = 1;
		D_00044040[ch].vol_l = left * 0x1000 / 127;
		D_00044040[ch].vol_r = right * 0x1000 / 127;
		D_00044040[ch].pos = 0;
		D_00044040[ch].unk30 = 0;
		D_00044040[ch].unk34 = 0;
		D_00044040[ch].unk28 = 0;
		D_00044040[ch].unk2C = 0;
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
	if (D_00044040[ch].data == NULL && !(D_00044040[ch].flags & 0x400))
		return 0x80440006;
	if (D_00044040[ch].stat != 0) {
		D_00044040[ch].flags |= 0x110000;
		D_000442A0[ch].stat = 1;
		D_000442A0[ch].vol_l = left;
		D_000442A0[ch].vol_r = right;
		D_000442A0[ch].pos = 0;
		D_000442A0[ch].unk30 = 0;
		D_000442A0[ch].unk34 = 0;
		D_000442A0[ch].unk28 = 0;
		D_000442A0[ch].unk2C = 0;
	} else {
		D_00044040[ch].stat = 1;
		D_00044040[ch].vol_l = left;
		D_00044040[ch].vol_r = right;
		D_00044040[ch].pos = 0;
		D_00044040[ch].unk30 = 0;
		D_00044040[ch].unk34 = 0;
		D_00044040[ch].unk28 = 0;
		D_00044040[ch].unk2C = 0;
	}
	return 0;
}

int sceWaveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_00044040[ch].stat != 0) {
			D_00044040[ch].flags |= 0x120000;
			D_000442A0[ch].stat = 0;
			D_000442A0[ch].pos = 0;
			D_000442A0[ch].unk30 = 0;
			D_000442A0[ch].unk34 = 0;
			D_000442A0[ch].unk28 = 0;
			D_000442A0[ch].unk2C = 0;
		} else {
			D_00044040[ch].pos = 0;
			D_00044040[ch].unk30 = 0;
			D_00044040[ch].unk34 = 0;
			D_00044040[ch].unk28 = 0;
			D_00044040[ch].unk2C = 0;
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
	return sceAudioSetChannelDataLen(D_00044514[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_00044514[ch], left, right);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_00044514[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_00044514[ch], left, right, buf);
}

int sceWaveStart(int prio)
{
	if (D_000431B8 != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return func_00009680(prio);
}

int sceWaveEnd(void)
{
	int i;

	if (D_000431B8 != 3)
		return 0x80440004;
	for (i = 0; i < 8; i++)
		sceWaveStop(i);
	D_000431BC = 1;
	sceKernelWaitThreadEnd(D_00044500.thid, NULL);
	sceKernelDeleteThread(D_00044500.thid);
	D_000431BC = 0;
	D_000431B8 = 1;
	return 0;
}

int sceWaveExit(void)
{
	if (D_000431B8 != 1)
		return 0x80440002;
	sceAudioChRelease(D_00044500.ch);
	sceAudioChRelease(D_00044514[0]);
	sceAudioChRelease(D_00044514[1]);
	sceAudioChRelease(D_00044514[2]);
	D_0004450C = NULL;
	D_00044510 = NULL;
	D_000431B8 = 0;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_00044040[ch].flags = (D_00044040[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_00044040[ch].stat != 0) {
		D_000442A0[ch].stat = 0;
		D_00044040[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_00044040[ch].stat == 0)
		D_00044040[ch].stat = 1;
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
	return sceAudioChangeChannelConfig(D_00044514[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLength(D_00044514[ch]);
}

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3doubleplay/nonmatchings/libwave", D_000201B4);

static int func_00009680(int prio)
{
	D_000431BC = 0;
	D_00044500.thid = sceKernelCreateThread("SceWaveMain", func_00009724, prio, 0x1000, 0, NULL);
	if (D_00044500.thid < 0)
		return 0x80440003;
	D_00044500.prio = prio;
	if (sceKernelStartThread(D_00044500.thid, sizeof(SceWaveMain), &D_00044500) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_000431B8 = 3;
	return 0;
}

extern char D_00043240[2][0x700];
static int func_00009840(char *buf);

static int func_00009724(unsigned int args, void *argp)
{
	SceWaveMain *m = (SceWaveMain *)argp;
	int i = 0;
	int j;

	while (D_000431BC == 0) {
		if (func_00009840(D_00043240[i]) == 0) {
			sceKernelDelayThread(10000);
			continue;
		}
		for (j = 1; j < 16; j++)
			func_00009840(D_00043240[i] + j * 0x70);
		sceAudioOutputBlocking(m->ch, 0x8000, D_00043240[i]);
		i = (i + 1) % 2;
	}
	sceAudioOutputBlocking(m->ch, 0, NULL);
	sceKernelExitThread(0);
	return 0;
}

static int func_00009A18(short *dst, unsigned char *vag, int *hist1, int *hist2);
static void func_00009B5C(int ch, void *buf);
static void func_00009DF8(int ch, void *buf);
static void func_0000A310(int ch, char *dst, void *src);
typedef int (*SceWaveCallback)(int ch, void *buf, int size, int arg);

static int func_00009840(char *buf)
{
	int ch;
	int n = 0;

	wclr(buf, 0x70);
	for (ch = 0; ch < 8; ch++) {
		if (D_00044040[ch].stat == 0)
			continue;
		n++;
		if (!(D_00044040[ch].flags & 0x400)) {
			if (!(D_00044040[ch].flags & 0x100)) {
				if (D_00044040[ch].data != NULL)
					func_00009B5C(ch, D_00044510);
			} else {
				if (D_00044040[ch].data != NULL)
					func_00009DF8(ch, D_00044510);
			}
		} else {
			if (D_00044040[ch].unk44 != 0) {
				wclr(D_00044510, 0x70);
				if (!(D_00044040[ch].flags & 0x100)) {
					if (((SceWaveCallback)D_00044040[ch].unk44)(ch, D_0004450C, 0x10, D_00044040[ch].unk48))
						D_00044040[ch].stat = 0;
					func_00009A18(D_00044510, D_0004450C, &D_00044040[ch].unk30, &D_00044040[ch].unk34);
				} else {
					if (((SceWaveCallback)D_00044040[ch].unk44)(ch, D_00044510, 0x70, D_00044040[ch].unk48))
						D_00044040[ch].stat = 0;
				}
			}
		}
		func_0000A310(ch, buf, D_00044510);
	}
	return n;
}

extern const signed char D_000201B4[2][5];

static int func_00009A18(short *dst, unsigned char *vag, int *hist1, int *hist2)
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
	f0 = D_000201B4[0][predict];
	f1 = D_000201B4[1][predict];
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

static void func_00009B5C(int ch, void *dst)
{
	char *data = D_00044040[ch].data;
	int ret;

	wclr(dst, 0x70);
	switch ((unsigned char)D_00044040[ch].flags) {
	case 0:
		if (D_00044040[ch].pos + 16 <= (int)D_00044040[ch].size) {
			wcpy(D_0004450C, data + D_00044040[ch].pos, 16);
			D_00044040[ch].pos += 16;
			func_00009A18(dst, D_0004450C, &D_00044040[ch].unk30, &D_00044040[ch].unk34);
		} else {
			D_00044040[ch].pos = 0;
			D_00044040[ch].stat = 0;
		}
		break;
	case 1:
		if ((int)D_00044040[ch].size < 16)
			break;
		for (;;) {
			if (D_00044040[ch].pos + 16 <= (int)D_00044040[ch].size) {
				int i = 0;
				char *d = D_0004450C;
				char *s = data + D_00044040[ch].pos;
			cl:
				*d++ = *s++;
				i++;
				if (i < 16)
					goto cl;
				goto decode;
			}
			break;
		}
		D_00044040[ch].pos = D_00044040[ch].unk10;
		wcpy(D_0004450C, data + D_00044040[ch].pos, 16);
		goto decode;
	case 2:
		if ((int)D_00044040[ch].size < 16)
			break;
		if (D_00044040[ch].pos + 16 <= (int)D_00044040[ch].size) {
			wcpy(D_0004450C, data + D_00044040[ch].pos, 16);
		} else {
			D_00044040[ch].pos = 0;
			D_00044040[ch].stat = 0;
			break;
		}
	decode:
		ret = func_00009A18(dst, D_0004450C, &D_00044040[ch].unk30, &D_00044040[ch].unk34);
		switch (ret) {
		case 6:
			D_00044040[ch].unk10 = D_00044040[ch].pos;
			D_00044040[ch].pos += 16;
			break;
		case 3:
			D_00044040[ch].unk14 = D_00044040[ch].pos;
			D_00044040[ch].pos = D_00044040[ch].unk10;
			break;
		default:
			D_00044040[ch].pos += 16;
			break;
		}
		break;
	}
}

static void func_00009DF8(int ch, void *dst)
{
	char *data = D_00044040[ch].data;

	if (!(D_00044040[ch].flags & 1)) {
		if (!(D_00044040[ch].flags & 0x200)) {
			if (D_00044040[ch].pos + 0x38 <= (int)D_00044040[ch].size) {
				wcpy(dst, data + D_00044040[ch].pos, 0x38);
				D_00044040[ch].pos += 0x38;
			} else {
				int m;

				wclr(dst, 0x70);
				m = D_00044040[ch].size - D_00044040[ch].pos;
				wcpy(dst, data + D_00044040[ch].pos, m);
				D_00044040[ch].pos = 0;
				D_00044040[ch].stat = 0;
			}
		} else {
			if (D_00044040[ch].pos + 0x70 <= (int)D_00044040[ch].size) {
				wcpy(dst, data + D_00044040[ch].pos, 0x70);
				D_00044040[ch].pos += 0x70;
			} else {
				int m;

				wclr(dst, 0x70);
				m = D_00044040[ch].size - D_00044040[ch].pos;
				wcpy(dst, data + D_00044040[ch].pos, m);
				D_00044040[ch].pos = 0;
				D_00044040[ch].stat = 0;
			}
		}
	} else {
		for (;;) {
			if (!(D_00044040[ch].flags & 0x200)) {
				if ((int)D_00044040[ch].size >= 0x38) {
					if (D_00044040[ch].pos + 0x38 < (int)D_00044040[ch].size) {
						wcpy(dst, data + D_00044040[ch].pos, 0x38);
						D_00044040[ch].pos += 0x38;
					} else {
						int m = D_00044040[ch].size - D_00044040[ch].pos;

						wcpy(dst, data + D_00044040[ch].pos, m);
						D_00044040[ch].pos = 0;
						wcpy((char *)dst + m, data, 0x38 - m);
						D_00044040[ch].pos = 0x38 - m;
					}
				} else {
					int n, rem;

					n = D_00044040[ch].size - D_00044040[ch].pos;
					wcpy(dst, data + D_00044040[ch].pos, n);
					D_00044040[ch].pos = 0;
					rem = 0x38 - n;
					for (;;) {
						if ((int)D_00044040[ch].size < rem) {
							wcpy((char *)dst + n, data, D_00044040[ch].size);
							n += D_00044040[ch].size;
							rem -= D_00044040[ch].size;
						} else {
							wcpy((char *)dst + n, data, rem);
							D_00044040[ch].pos += rem;
							break;
						}
					}
				}
				return;
			}
			break;
		}
		if ((int)D_00044040[ch].size >= 0x70) {
			if (D_00044040[ch].pos + 0x70 < (int)D_00044040[ch].size) {
				wcpy(dst, data + D_00044040[ch].pos, 0x70);
				D_00044040[ch].pos += 0x70;
			} else {
				int m = D_00044040[ch].size - D_00044040[ch].pos;

				wcpy(dst, data + D_00044040[ch].pos, m);
				D_00044040[ch].pos = 0;
				wcpy((char *)dst + m, data, 0x70 - m);
				D_00044040[ch].pos = 0x70 - m;
			}
		} else {
			int n, rem;

			n = D_00044040[ch].size - D_00044040[ch].pos;
			wcpy(dst, data + D_00044040[ch].pos, n);
			D_00044040[ch].pos = 0;
			rem = 0x70 - n;
			for (;;) {
				if ((int)D_00044040[ch].size < rem) {
					wcpy((char *)dst + n, data, D_00044040[ch].size);
					n += D_00044040[ch].size;
					rem -= D_00044040[ch].size;
				} else {
					wcpy((char *)dst + n, data, rem);
					D_00044040[ch].pos += rem;
					break;
				}
			}
		}
	}
}

static void func_0000A310(int ch, char *out_, void *src_)
{
	short *out = (short *)out_;
	short *src = (short *)src_;
	int i;
	int l, r, x;

	for (i = 0; i < 28; i++) {
		if (D_00044040[ch].flags & 0x100000) {
			D_00044040[ch].unk38 = (D_00044040[ch].unk3C - D_00044040[ch].unk40) * 127 / D_00044040[ch].unk3C;
			if (D_00044040[ch].unk38 < 0)
				D_00044040[ch].unk38 = 0;
			D_00044040[ch].unk40++;
			if (D_00044040[ch].unk40 >= D_00044040[ch].unk3C) {
				D_00044040[ch].flags &= ~0x100000;
				D_00044040[ch].unk40 = 0;
				if (D_00044040[ch].flags & 0x10000) {
					D_00044040[ch].flags &= ~0x10000;
					D_00044040[ch].stat = D_000442A0[ch].stat;
					D_00044040[ch].pos = D_000442A0[ch].pos;
					D_00044040[ch].vol_l = D_000442A0[ch].vol_l;
					D_00044040[ch].vol_r = D_000442A0[ch].vol_r;
					D_00044040[ch].unk30 = D_000442A0[ch].unk30;
					D_00044040[ch].unk34 = D_000442A0[ch].unk34;
					D_00044040[ch].unk28 = D_000442A0[ch].unk28;
					D_00044040[ch].unk2C = D_000442A0[ch].unk2C;
				} else if (D_00044040[ch].flags & 0x20000) {
					D_00044040[ch].flags &= ~0x20000;
					D_00044040[ch].stat = D_000442A0[ch].stat;
					D_00044040[ch].pos = D_000442A0[ch].pos;
					D_00044040[ch].unk30 = D_000442A0[ch].unk30;
					D_00044040[ch].unk34 = D_000442A0[ch].unk34;
					D_00044040[ch].unk28 = D_000442A0[ch].unk28;
					D_00044040[ch].unk2C = D_000442A0[ch].unk2C;
				} else if (D_00044040[ch].flags & 0x40000) {
					D_00044040[ch].flags &= ~0x40000;
					D_00044040[ch].stat = D_000442A0[ch].stat;
				}
			}
		} else {
			D_00044040[ch].unk38 = 127;
		}
		if (!(D_00044040[ch].flags & 0x100)) {
			l = D_00044040[ch].vol_l * D_00044040[ch].unk38 / 127;
			r = D_00044040[ch].vol_r * D_00044040[ch].unk38 / 127;
			l = l * src[i] / 4096;
			r = r * src[i] / 4096;
		} else if (!(D_00044040[ch].flags & 0x200)) {
			l = D_00044040[ch].vol_l * D_00044040[ch].unk38 / 127;
			r = D_00044040[ch].vol_r * D_00044040[ch].unk38 / 127;
			l = l * src[i] / 4096;
			r = r * src[i] / 4096;
		} else {
			l = D_00044040[ch].vol_l * D_00044040[ch].unk38 / 127;
			r = D_00044040[ch].vol_r * D_00044040[ch].unk38 / 127;
			l = l * src[i * 2] / 4096;
			r = r * src[i * 2 + 1] / 4096;
		}
		x = out[i * 2];
		x += l;
		if (x > 32767)
			x = 32767;
		if (x < -32768)
			x = -32768;
		out[i * 2] = x;
		x = out[i * 2 + 1];
		x += r;
		if (x > 32767)
			x = 32767;
		if (x < -32768)
			x = -32768;
		out[i * 2 + 1] = x;
	}
}
