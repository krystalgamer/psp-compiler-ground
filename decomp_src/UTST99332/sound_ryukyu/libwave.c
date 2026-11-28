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

extern volatile int D_000454AC;
extern volatile int D_000454B0;
extern char D_000454B4[];
extern char D_00045524[];
extern SceWaveVoice D_00046334[8];
extern SceWaveVoice D_00046594[8];
extern SceWaveMain D_000467F4;
extern void *D_00046800;
extern void *D_00046804;
extern int D_00046808[3];

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
static int func_000062CC(unsigned int args, void *argp);

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

	if (D_000454AC != 0)
		return 0x80440001;
	D_00046804 = D_000454B4;
	D_00046800 = D_00045524;
	wclr(D_00046334, sizeof(D_00046334));
	wclr(D_00046594, sizeof(D_00046594));
	D_000467F4.ch = sceAudioChReserve(-1, 0x1c0, 0);
	if (D_000467F4.ch < 0)
		return 0x80440001;
	D_00046808[0] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00046808[0] < 0) {
		sceAudioChRelease(D_000467F4.ch);
		return 0x80440001;
	}
	D_00046808[1] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00046808[1] < 0) {
		sceAudioChRelease(D_000467F4.ch);
		sceAudioChRelease(D_00046808[0]);
		return 0x80440001;
	}
	D_00046808[2] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00046808[2] < 0) {
		sceAudioChRelease(D_000467F4.ch);
		sceAudioChRelease(D_00046808[0]);
		sceAudioChRelease(D_00046808[1]);
		return 0x80440001;
	}
	D_000454AC = 1;
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
		v = &D_00046334[ch];
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
		v = &D_00046334[ch];
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
	D_00046334[ch].vol_l = (int)(left << 12) / 127;
	D_00046334[ch].vol_r = (int)(right << 12) / 127;
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
	if (D_00046334[ch].vol_l <= 0)
		*left = 0;
	else if (D_00046334[ch].vol_l >= 128)
		*left = (D_00046334[ch].vol_l - 1) / 32;
	else
		*left = D_00046334[ch].vol_l / 32;
	if (D_00046334[ch].vol_r <= 0)
		*right = 0;
	else if (D_00046334[ch].vol_r >= 128)
		*right = (D_00046334[ch].vol_r - 1) / 32;
	else
		*right = D_00046334[ch].vol_r / 32;
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
	D_00046334[ch].vol_l = left;
	D_00046334[ch].vol_r = right;
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
	*left = D_00046334[ch].vol_l;
	*right = D_00046334[ch].vol_r;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_00046334[ch].stat == 0)
		*rest = 0;
	else if (!(D_00046334[ch].flags & 0x400))
		*rest = D_00046334[ch].size - D_00046334[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_00046334[ch].stat;
}

int sceWavePlay(unsigned int ch, int left, int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left < 0 || left >= 128)
		return 0x8044000A;
	if (right < 0 || right >= 128)
		return 0x8044000A;
	if (D_00046334[ch].data == NULL && !(D_00046334[ch].flags & 0x400))
		return 0x80440006;
	if (D_00046334[ch].stat != 0) {
		D_00046334[ch].flags |= 0x110000;
		D_00046594[ch].stat = 1;
		D_00046594[ch].vol_l = left * 0x1000 / 127;
		D_00046594[ch].vol_r = right * 0x1000 / 127;
		D_00046594[ch].pos = 0;
		D_00046594[ch].unk30 = 0;
		D_00046594[ch].unk34 = 0;
		D_00046594[ch].unk28 = 0;
		D_00046594[ch].unk2C = 0;
	} else {
		D_00046334[ch].stat = 1;
		D_00046334[ch].vol_l = left * 0x1000 / 127;
		D_00046334[ch].vol_r = right * 0x1000 / 127;
		D_00046334[ch].pos = 0;
		D_00046334[ch].unk30 = 0;
		D_00046334[ch].unk34 = 0;
		D_00046334[ch].unk28 = 0;
		D_00046334[ch].unk2C = 0;
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
	if (D_00046334[ch].data == NULL && !(D_00046334[ch].flags & 0x400))
		return 0x80440006;
	if (D_00046334[ch].stat != 0) {
		D_00046334[ch].flags |= 0x110000;
		D_00046594[ch].stat = 1;
		D_00046594[ch].vol_l = left;
		D_00046594[ch].vol_r = right;
		D_00046594[ch].pos = 0;
		D_00046594[ch].unk30 = 0;
		D_00046594[ch].unk34 = 0;
		D_00046594[ch].unk28 = 0;
		D_00046594[ch].unk2C = 0;
	} else {
		D_00046334[ch].stat = 1;
		D_00046334[ch].vol_l = left;
		D_00046334[ch].vol_r = right;
		D_00046334[ch].pos = 0;
		D_00046334[ch].unk30 = 0;
		D_00046334[ch].unk34 = 0;
		D_00046334[ch].unk28 = 0;
		D_00046334[ch].unk2C = 0;
	}
	return 0;
}

int sceWaveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_00046334[ch].stat != 0) {
			D_00046334[ch].flags |= 0x120000;
			D_00046594[ch].stat = 0;
			D_00046594[ch].pos = 0;
			D_00046594[ch].unk30 = 0;
			D_00046594[ch].unk34 = 0;
			D_00046594[ch].unk28 = 0;
			D_00046594[ch].unk2C = 0;
		} else {
			D_00046334[ch].pos = 0;
			D_00046334[ch].unk30 = 0;
			D_00046334[ch].unk34 = 0;
			D_00046334[ch].unk28 = 0;
			D_00046334[ch].unk2C = 0;
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
	return sceAudioSetChannelDataLen(D_00046808[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_00046808[ch], left, right);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_00046808[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_00046808[ch], left, right, buf);
}

int sceWaveStart(int prio)
{
	if (D_000454AC != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return func_00006228(prio);
}

int sceWaveEnd(void)
{
	int i;

	if (D_000454AC != 3)
		return 0x80440004;
	for (i = 0; i < 8; i++)
		sceWaveStop(i);
	D_000454B0 = 1;
	sceKernelWaitThreadEnd(D_000467F4.thid, NULL);
	sceKernelDeleteThread(D_000467F4.thid);
	D_000454B0 = 0;
	D_000454AC = 1;
	return 0;
}

int sceWaveExit(void)
{
	if (D_000454AC != 1)
		return 0x80440002;
	sceAudioChRelease(D_000467F4.ch);
	sceAudioChRelease(D_00046808[0]);
	sceAudioChRelease(D_00046808[1]);
	sceAudioChRelease(D_00046808[2]);
	D_00046800 = NULL;
	D_00046804 = NULL;
	D_000454AC = 0;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_00046334[ch].flags = (D_00046334[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_00046334[ch].stat != 0) {
		D_00046594[ch].stat = 0;
		D_00046334[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_00046334[ch].stat == 0)
		D_00046334[ch].stat = 1;
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
	return sceAudioChangeChannelConfig(D_00046808[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLength(D_00046808[ch]);
}

INCLUDE_RODATA("tmp/asm/UTST99332/sound_ryukyu/nonmatchings/libwave", D_00012718);

static int func_00006228(int prio)
{
	D_000454B0 = 0;
	D_000467F4.thid = sceKernelCreateThread("SceWaveMain", func_000062CC, prio, 0x1000, 0, NULL);
	if (D_000467F4.thid < 0)
		return 0x80440003;
	D_000467F4.prio = prio;
	if (sceKernelStartThread(D_000467F4.thid, sizeof(SceWaveMain), &D_000467F4) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_000454AC = 3;
	return 0;
}

extern char D_00045534[2][0x700];
static int func_000063E8(char *buf);

static int func_000062CC(unsigned int args, void *argp)
{
	SceWaveMain *m = (SceWaveMain *)argp;
	int i = 0;
	int j;

	while (D_000454B0 == 0) {
		if (func_000063E8(D_00045534[i]) == 0) {
			sceKernelDelayThread(10000);
			continue;
		}
		for (j = 1; j < 16; j++)
			func_000063E8(D_00045534[i] + j * 0x70);
		sceAudioOutputBlocking(m->ch, 0x8000, D_00045534[i]);
		i = (i + 1) % 2;
	}
	sceAudioOutputBlocking(m->ch, 0, NULL);
	sceKernelExitThread(0);
	return 0;
}

static int func_000065C0(short *dst, unsigned char *vag, int *hist1, int *hist2);
static void func_00006704(int ch, void *buf);
static void func_000069A0(int ch, void *buf);
static void func_00006EB8(int ch, char *dst, void *src);
typedef int (*SceWaveCallback)(int ch, void *buf, int size, int arg);

static int func_000063E8(char *buf)
{
	int ch;
	int n = 0;

	wclr(buf, 0x70);
	for (ch = 0; ch < 8; ch++) {
		if (D_00046334[ch].stat == 0)
			continue;
		n++;
		if (!(D_00046334[ch].flags & 0x400)) {
			if (!(D_00046334[ch].flags & 0x100)) {
				if (D_00046334[ch].data != NULL)
					func_00006704(ch, D_00046804);
			} else {
				if (D_00046334[ch].data != NULL)
					func_000069A0(ch, D_00046804);
			}
		} else {
			if (D_00046334[ch].unk44 != 0) {
				wclr(D_00046804, 0x70);
				if (!(D_00046334[ch].flags & 0x100)) {
					if (((SceWaveCallback)D_00046334[ch].unk44)(ch, D_00046800, 0x10, D_00046334[ch].unk48))
						D_00046334[ch].stat = 0;
					func_000065C0(D_00046804, D_00046800, &D_00046334[ch].unk30, &D_00046334[ch].unk34);
				} else {
					if (((SceWaveCallback)D_00046334[ch].unk44)(ch, D_00046804, 0x70, D_00046334[ch].unk48))
						D_00046334[ch].stat = 0;
				}
			}
		}
		func_00006EB8(ch, buf, D_00046804);
	}
	return n;
}

extern const signed char D_00012718[2][5];

static int func_000065C0(short *dst, unsigned char *vag, int *hist1, int *hist2)
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
	f0 = D_00012718[0][predict];
	f1 = D_00012718[1][predict];
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

static void func_00006704(int ch, void *dst)
{
	char *data = D_00046334[ch].data;
	int ret;

	wclr(dst, 0x70);
	switch ((unsigned char)D_00046334[ch].flags) {
	case 0:
		if (D_00046334[ch].pos + 16 <= (int)D_00046334[ch].size) {
			wcpy(D_00046800, data + D_00046334[ch].pos, 16);
			D_00046334[ch].pos += 16;
			func_000065C0(dst, D_00046800, &D_00046334[ch].unk30, &D_00046334[ch].unk34);
		} else {
			D_00046334[ch].pos = 0;
			D_00046334[ch].stat = 0;
		}
		break;
	case 1:
		if ((int)D_00046334[ch].size < 16)
			break;
		for (;;) {
			if (D_00046334[ch].pos + 16 <= (int)D_00046334[ch].size) {
				int i = 0;
				char *d = D_00046800;
				char *s = data + D_00046334[ch].pos;
			cl:
				*d++ = *s++;
				i++;
				if (i < 16)
					goto cl;
				goto decode;
			}
			break;
		}
		D_00046334[ch].pos = D_00046334[ch].unk10;
		wcpy(D_00046800, data + D_00046334[ch].pos, 16);
		goto decode;
	case 2:
		if ((int)D_00046334[ch].size < 16)
			break;
		if (D_00046334[ch].pos + 16 <= (int)D_00046334[ch].size) {
			wcpy(D_00046800, data + D_00046334[ch].pos, 16);
		} else {
			D_00046334[ch].pos = 0;
			D_00046334[ch].stat = 0;
			break;
		}
	decode:
		ret = func_000065C0(dst, D_00046800, &D_00046334[ch].unk30, &D_00046334[ch].unk34);
		switch (ret) {
		case 6:
			D_00046334[ch].unk10 = D_00046334[ch].pos;
			D_00046334[ch].pos += 16;
			break;
		case 3:
			D_00046334[ch].unk14 = D_00046334[ch].pos;
			D_00046334[ch].pos = D_00046334[ch].unk10;
			break;
		default:
			D_00046334[ch].pos += 16;
			break;
		}
		break;
	}
}

static void func_000069A0(int ch, void *dst)
{
	char *data = D_00046334[ch].data;

	if (!(D_00046334[ch].flags & 1)) {
		if (!(D_00046334[ch].flags & 0x200)) {
			if (D_00046334[ch].pos + 0x38 <= (int)D_00046334[ch].size) {
				wcpy(dst, data + D_00046334[ch].pos, 0x38);
				D_00046334[ch].pos += 0x38;
			} else {
				int m;

				wclr(dst, 0x70);
				m = D_00046334[ch].size - D_00046334[ch].pos;
				wcpy(dst, data + D_00046334[ch].pos, m);
				D_00046334[ch].pos = 0;
				D_00046334[ch].stat = 0;
			}
		} else {
			if (D_00046334[ch].pos + 0x70 <= (int)D_00046334[ch].size) {
				wcpy(dst, data + D_00046334[ch].pos, 0x70);
				D_00046334[ch].pos += 0x70;
			} else {
				int m;

				wclr(dst, 0x70);
				m = D_00046334[ch].size - D_00046334[ch].pos;
				wcpy(dst, data + D_00046334[ch].pos, m);
				D_00046334[ch].pos = 0;
				D_00046334[ch].stat = 0;
			}
		}
	} else {
		for (;;) {
			if (!(D_00046334[ch].flags & 0x200)) {
				if ((int)D_00046334[ch].size >= 0x38) {
					if (D_00046334[ch].pos + 0x38 < (int)D_00046334[ch].size) {
						wcpy(dst, data + D_00046334[ch].pos, 0x38);
						D_00046334[ch].pos += 0x38;
					} else {
						int m = D_00046334[ch].size - D_00046334[ch].pos;

						wcpy(dst, data + D_00046334[ch].pos, m);
						D_00046334[ch].pos = 0;
						wcpy((char *)dst + m, data, 0x38 - m);
						D_00046334[ch].pos = 0x38 - m;
					}
				} else {
					int n, rem;

					n = D_00046334[ch].size - D_00046334[ch].pos;
					wcpy(dst, data + D_00046334[ch].pos, n);
					D_00046334[ch].pos = 0;
					rem = 0x38 - n;
					for (;;) {
						if ((int)D_00046334[ch].size < rem) {
							wcpy((char *)dst + n, data, D_00046334[ch].size);
							n += D_00046334[ch].size;
							rem -= D_00046334[ch].size;
						} else {
							wcpy((char *)dst + n, data, rem);
							D_00046334[ch].pos += rem;
							break;
						}
					}
				}
				return;
			}
			break;
		}
		if ((int)D_00046334[ch].size >= 0x70) {
			if (D_00046334[ch].pos + 0x70 < (int)D_00046334[ch].size) {
				wcpy(dst, data + D_00046334[ch].pos, 0x70);
				D_00046334[ch].pos += 0x70;
			} else {
				int m = D_00046334[ch].size - D_00046334[ch].pos;

				wcpy(dst, data + D_00046334[ch].pos, m);
				D_00046334[ch].pos = 0;
				wcpy((char *)dst + m, data, 0x70 - m);
				D_00046334[ch].pos = 0x70 - m;
			}
		} else {
			int n, rem;

			n = D_00046334[ch].size - D_00046334[ch].pos;
			wcpy(dst, data + D_00046334[ch].pos, n);
			D_00046334[ch].pos = 0;
			rem = 0x70 - n;
			for (;;) {
				if ((int)D_00046334[ch].size < rem) {
					wcpy((char *)dst + n, data, D_00046334[ch].size);
					n += D_00046334[ch].size;
					rem -= D_00046334[ch].size;
				} else {
					wcpy((char *)dst + n, data, rem);
					D_00046334[ch].pos += rem;
					break;
				}
			}
		}
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_ryukyu/nonmatchings/libwave", func_00006EB8);
