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

extern volatile int D_00007428;
extern char D_00007430[];
extern char D_000074A0[];
extern SceWaveVoice D_000082B0[8];
extern SceWaveVoice D_00008510[8];
extern SceWaveMain D_00008770;
extern void *D_0000877C;
extern void *D_00008780;
extern int D_00008784[3];

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
static int func_00005440(unsigned int args, void *argp);
extern volatile int D_0000742C;
extern char D_000074B0[2][0x700];
extern const signed char D_00007304[2][5];
static void func_0000551C(char *buf);
static int func_000056D4(short *dst, unsigned char *src, int *h1, int *h2);
static void func_00005818(int ch, void *dst);
static void func_00005AB4(int ch, void *dst);
static void func_00005FCC(int ch, void *buf, void *src);

static inline int _waveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_000082B0[ch].stat != 0) {
			D_000082B0[ch].flags |= 0x120000;
			D_00008510[ch].stat = 0;
			D_00008510[ch].pos = 0;
			D_00008510[ch].unk30 = 0;
			D_00008510[ch].unk34 = 0;
			D_00008510[ch].unk28 = 0;
			D_00008510[ch].unk2C = 0;
		} else {
			D_000082B0[ch].pos = 0;
			D_000082B0[ch].unk30 = 0;
			D_000082B0[ch].unk34 = 0;
			D_000082B0[ch].unk28 = 0;
			D_000082B0[ch].unk2C = 0;
		}
		ret = 0;
	}
	return ret;
}

static __inline__ void wclr(void *dst, int n)
{
	char *p = dst;

	while (--n >= 0)
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
	if (D_00007428 != 0)
		return 0x80440001;
	D_00008780 = D_00007430;
	D_0000877C = D_000074A0;
	wclr(D_000082B0, sizeof(D_000082B0));
	wclr(D_00008510, sizeof(D_00008510));
	D_00008770.ch = sceAudioChReserve(-1, 0x1c0, 0);
	if (D_00008770.ch < 0)
		return 0x80440001;
	D_00008784[0] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00008784[0] < 0) {
		sceAudioChRelease(D_00008770.ch);
		return 0x80440001;
	}
	D_00008784[1] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00008784[1] < 0) {
		sceAudioChRelease(D_00008770.ch);
		sceAudioChRelease(D_00008784[0]);
		return 0x80440001;
	}
	D_00008784[2] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00008784[2] < 0) {
		sceAudioChRelease(D_00008770.ch);
		sceAudioChRelease(D_00008784[0]);
		sceAudioChRelease(D_00008784[1]);
		return 0x80440001;
	}
	D_00007428 = 1;
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
		v = &D_000082B0[ch];
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
		v = &D_000082B0[ch];
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

int sceWaveGetVolume(unsigned int ch, int *left, int *right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left == NULL)
		return 0x8044000A;
	if (right == NULL)
		return 0x8044000A;
	if (D_000082B0[ch].vol_l <= 0)
		*left = 0;
	else if (D_000082B0[ch].vol_l >= 128)
		*left = (D_000082B0[ch].vol_l - 1) / 32;
	else
		*left = D_000082B0[ch].vol_l / 32;
	if (D_000082B0[ch].vol_r <= 0)
		*right = 0;
	else if (D_000082B0[ch].vol_r >= 128)
		*right = (D_000082B0[ch].vol_r - 1) / 32;
	else
		*right = D_000082B0[ch].vol_r / 32;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_000082B0[ch].stat == 0)
		*rest = 0;
	else if (!(D_000082B0[ch].flags & 0x400))
		*rest = D_000082B0[ch].size - D_000082B0[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_000082B0[ch].stat;
}

int sceWavePlay(unsigned int ch, int left, int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left < 0 || left >= 128)
		return 0x8044000A;
	if (right < 0 || right >= 128)
		return 0x8044000A;
	if (D_000082B0[ch].data == NULL && !(D_000082B0[ch].flags & 0x400))
		return 0x80440006;
	if (D_000082B0[ch].stat != 0) {
		D_000082B0[ch].flags |= 0x110000;
		D_00008510[ch].stat = 1;
		D_00008510[ch].vol_l = left * 0x1000 / 127;
		D_00008510[ch].vol_r = right * 0x1000 / 127;
		D_00008510[ch].pos = 0;
		D_00008510[ch].unk30 = 0;
		D_00008510[ch].unk34 = 0;
		D_00008510[ch].unk28 = 0;
		D_00008510[ch].unk2C = 0;
	} else {
		D_000082B0[ch].stat = 1;
		D_000082B0[ch].vol_l = left * 0x1000 / 127;
		D_000082B0[ch].vol_r = right * 0x1000 / 127;
		D_000082B0[ch].pos = 0;
		D_000082B0[ch].unk30 = 0;
		D_000082B0[ch].unk34 = 0;
		D_000082B0[ch].unk28 = 0;
		D_000082B0[ch].unk2C = 0;
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
	if (D_000082B0[ch].data == NULL && !(D_000082B0[ch].flags & 0x400))
		return 0x80440006;
	if (D_000082B0[ch].stat != 0) {
		D_000082B0[ch].flags |= 0x110000;
		D_00008510[ch].stat = 1;
		D_00008510[ch].vol_l = left;
		D_00008510[ch].vol_r = right;
		D_00008510[ch].pos = 0;
		D_00008510[ch].unk30 = 0;
		D_00008510[ch].unk34 = 0;
		D_00008510[ch].unk28 = 0;
		D_00008510[ch].unk2C = 0;
	} else {
		D_000082B0[ch].stat = 1;
		D_000082B0[ch].vol_l = left;
		D_000082B0[ch].vol_r = right;
		D_000082B0[ch].pos = 0;
		D_000082B0[ch].unk30 = 0;
		D_000082B0[ch].unk34 = 0;
		D_000082B0[ch].unk28 = 0;
		D_000082B0[ch].unk2C = 0;
	}
	return 0;
}

INCLUDE_RODATA("tmp/asm/umdt/movietest/nonmatchings/libwave", D_00007304);

static inline int _waveThreadStart(int prio)
{
	D_0000742C = 0;
	D_00008770.thid = sceKernelCreateThread("SceWaveMain", func_00005440, prio, 0x1000, 0, NULL);
	if (D_00008770.thid < 0)
		return 0x80440003;
	D_00008770.prio = prio;
	if (sceKernelStartThread(D_00008770.thid, sizeof(SceWaveMain), &D_00008770) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_00007428 = 3;
	return 0;
}

int sceWaveStart(int prio)
{
	if (D_00007428 != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return _waveThreadStart(prio);
}

int sceWaveEnd(void)
{
	int i;

	if (D_00007428 != 3)
		return 0x80440004;
	for (i = 0; i < 8; i++)
		_waveStop(i);
	D_0000742C = 1;
	sceKernelWaitThreadEnd(D_00008770.thid, NULL);
	sceKernelDeleteThread(D_00008770.thid);
	D_0000742C = 0;
	D_00007428 = 1;
	return 0;
}

int sceWaveExit(void)
{
	if (D_00007428 != 1)
		return 0x80440002;
	sceAudioChRelease(D_00008770.ch);
	sceAudioChRelease(D_00008784[0]);
	sceAudioChRelease(D_00008784[1]);
	sceAudioChRelease(D_00008784[2]);
	D_0000877C = NULL;
	D_00008780 = NULL;
	D_00007428 = 0;
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
	D_000082B0[ch].vol_l = (int)(left << 12) / 127;
	D_000082B0[ch].vol_r = (int)(right << 12) / 127;
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
	D_000082B0[ch].vol_l = left;
	D_000082B0[ch].vol_r = right;
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
	*left = D_000082B0[ch].vol_l;
	*right = D_000082B0[ch].vol_r;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_000082B0[ch].flags = (D_000082B0[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWaveStop(unsigned int ch)
{
	return _waveStop(ch);
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_000082B0[ch].stat != 0) {
		D_00008510[ch].stat = 0;
		D_000082B0[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_000082B0[ch].stat == 0)
		D_000082B0[ch].stat = 1;
	return 0;
}

void sceWaveAllStop(void)
{
	int i;

	for (i = 0; i < 8; i++)
		_waveStop(i);
}

int sceWaveAudioSetSample(unsigned int ch, int samplecount)
{
	if (ch >= 4)
		return 0x80440010;
	if ((unsigned int)(samplecount - 64) > 0xff80)
		return 0x80440011;
	if (samplecount & 0x3f)
		return 0x80440011;
	return sceAudioSetChannelDataLen(D_00008784[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_00008784[ch], left, right);
}

int sceWaveAudioSetFormat(unsigned int ch, int format)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioChangeChannelConfig(D_00008784[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLen(D_00008784[ch]);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_00008784[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_00008784[ch], left, right, buf);
}

static int func_00005440(unsigned int args, void *argp)
{
	SceWaveMain *m = (SceWaveMain *)argp;
	int i = 0;
	int j;

	while (D_0000742C == 0) {
		for (j = 0; j < 16; j++)
			func_0000551C(D_000074B0[i] + j * 0x70);
		sceAudioOutputBlocking(m->ch, 0x8000, D_000074B0[i]);
		i = (i + 1) % 2;
	}
	sceAudioOutputBlocking(m->ch, 0, NULL);
	sceKernelExitThread(0);
	return 0;
}

typedef int (*SceWaveCallback)(int ch, void *buf, int size, int arg);

static void func_0000551C(char *buf)
{
	int ch;

	wclr(buf, 0x70);
	for (ch = 0; ch < 8; ch++) {
		if (D_000082B0[ch].stat == 0)
			continue;
		if (!(D_000082B0[ch].flags & 0x400)) {
			if (!(D_000082B0[ch].flags & 0x100)) {
				if (D_000082B0[ch].data != NULL)
					func_00005818(ch, D_00008780);
			} else {
				if (D_000082B0[ch].data != NULL)
					func_00005AB4(ch, D_00008780);
			}
		} else {
			if (D_000082B0[ch].unk44 != 0) {
				wclr(D_00008780, 0x70);
				if (!(D_000082B0[ch].flags & 0x100)) {
					if (((SceWaveCallback)D_000082B0[ch].unk44)(ch, D_0000877C, 0x10, D_000082B0[ch].unk48))
						D_000082B0[ch].stat = 0;
					func_000056D4(D_00008780, D_0000877C, &D_000082B0[ch].unk30, &D_000082B0[ch].unk34);
				} else {
					if (((SceWaveCallback)D_000082B0[ch].unk44)(ch, D_00008780, 0x70, D_000082B0[ch].unk48))
						D_000082B0[ch].stat = 0;
				}
			}
		}
		func_00005FCC(ch, buf, D_00008780);
	}
}

static int func_000056D4(short *dst, unsigned char *vag, int *hist1, int *hist2)
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
	f0 = D_00007304[0][predict];
	f1 = D_00007304[1][predict];
	if (flags == 7)
		return flags;
	out = dst;
	for (i = 0; i < 14; i++) {
		signed char b = vag[k++];

		d0 = (((b << 28) >> (shift + 10)) + (s1 * f0 + s2 * f1)) >> 6;
		if (d0 > 32767) d0 = 32767;
		if (d0 < -32768) d0 = -32768;
		d1 = (((b & ~0xF) << (14 - shift)) + (d0 * f0 + s1 * f1)) >> 6;
		if (d1 > 32767) d1 = 32767;
		if (d1 < -32768) d1 = -32768;
		*out++ = d0;
		*out++ = d1;
		s2 = d0;
		s1 = d1;
	}
	*hist1 = s1;
	*hist2 = s2;
	return flags;
}

static void func_00005818(int ch, void *dst)
{
	char *data = D_000082B0[ch].data;
	int ret;

	wclr(dst, 0x70);
	switch ((unsigned char)D_000082B0[ch].flags) {
	case 0:
		if (D_000082B0[ch].pos + 16 <= (int)D_000082B0[ch].size) {
			wcpy(D_0000877C, data + D_000082B0[ch].pos, 16);
			D_000082B0[ch].pos += 16;
			func_000056D4(dst, D_0000877C, &D_000082B0[ch].unk30, &D_000082B0[ch].unk34);
		} else {
			D_000082B0[ch].pos = 0;
			D_000082B0[ch].stat = 0;
		}
		break;
	case 1:
		if ((int)D_000082B0[ch].size < 16)
			break;
		for (;;) {
			if (D_000082B0[ch].pos + 16 <= (int)D_000082B0[ch].size) {
				int i = 0;
				char *d = D_0000877C;
				char *s = data + D_000082B0[ch].pos;
			cl:
				*d++ = *s++;
				i++;
				if (i < 16)
					goto cl;
				goto decode;
			}
			break;
		}
		D_000082B0[ch].pos = D_000082B0[ch].unk10;
		wcpy(D_0000877C, data + D_000082B0[ch].pos, 16);
		goto decode;
	case 2:
		if ((int)D_000082B0[ch].size < 16)
			break;
		if (D_000082B0[ch].pos + 16 <= (int)D_000082B0[ch].size) {
			wcpy(D_0000877C, data + D_000082B0[ch].pos, 16);
		} else {
			D_000082B0[ch].pos = 0;
			D_000082B0[ch].stat = 0;
			break;
		}
	decode:
		ret = func_000056D4(dst, D_0000877C, &D_000082B0[ch].unk30, &D_000082B0[ch].unk34);
		switch (ret) {
		case 6:
			D_000082B0[ch].unk10 = D_000082B0[ch].pos;
			D_000082B0[ch].pos += 16;
			break;
		case 3:
			D_000082B0[ch].unk14 = D_000082B0[ch].pos;
			D_000082B0[ch].pos = D_000082B0[ch].unk10;
			break;
		default:
			D_000082B0[ch].pos += 16;
			break;
		}
		break;
	}
}

static void func_00005AB4(int ch, void *dst)
{
	char *data = D_000082B0[ch].data;

	if (!(D_000082B0[ch].flags & 1)) {
		if (!(D_000082B0[ch].flags & 0x200)) {
			if (D_000082B0[ch].pos + 0x38 <= (int)D_000082B0[ch].size) {
				wcpy(dst, data + D_000082B0[ch].pos, 0x38);
				D_000082B0[ch].pos += 0x38;
			} else {
				int m;

				wclr(dst, 0x70);
				m = D_000082B0[ch].size - D_000082B0[ch].pos;
				wcpy(dst, data + D_000082B0[ch].pos, m);
				D_000082B0[ch].pos = 0;
				D_000082B0[ch].stat = 0;
			}
		} else {
			if (D_000082B0[ch].pos + 0x70 <= (int)D_000082B0[ch].size) {
				wcpy(dst, data + D_000082B0[ch].pos, 0x70);
				D_000082B0[ch].pos += 0x70;
			} else {
				int m;

				wclr(dst, 0x70);
				m = D_000082B0[ch].size - D_000082B0[ch].pos;
				wcpy(dst, data + D_000082B0[ch].pos, m);
				D_000082B0[ch].pos = 0;
				D_000082B0[ch].stat = 0;
			}
		}
	} else {
		for (;;) {
			if (!(D_000082B0[ch].flags & 0x200)) {
				if ((int)D_000082B0[ch].size >= 0x38) {
					if (D_000082B0[ch].pos + 0x38 < (int)D_000082B0[ch].size) {
						wcpy(dst, data + D_000082B0[ch].pos, 0x38);
						D_000082B0[ch].pos += 0x38;
					} else {
						int m = D_000082B0[ch].size - D_000082B0[ch].pos;

						wcpy(dst, data + D_000082B0[ch].pos, m);
						D_000082B0[ch].pos = 0;
						wcpy((char *)dst + m, data, 0x38 - m);
						D_000082B0[ch].pos = 0x38 - m;
					}
				} else {
					int n, rem;

					n = D_000082B0[ch].size - D_000082B0[ch].pos;
					wcpy(dst, data + D_000082B0[ch].pos, n);
					D_000082B0[ch].pos = 0;
					rem = 0x38 - n;
					for (;;) {
						if ((int)D_000082B0[ch].size < rem) {
							wcpy((char *)dst + n, data, D_000082B0[ch].size);
							n += D_000082B0[ch].size;
							rem -= D_000082B0[ch].size;
						} else {
							wcpy((char *)dst + n, data, rem);
							D_000082B0[ch].pos += rem;
							break;
						}
					}
				}
				return;
			}
			break;
		}
		if ((int)D_000082B0[ch].size >= 0x70) {
			if (D_000082B0[ch].pos + 0x70 < (int)D_000082B0[ch].size) {
				wcpy(dst, data + D_000082B0[ch].pos, 0x70);
				D_000082B0[ch].pos += 0x70;
			} else {
				int m = D_000082B0[ch].size - D_000082B0[ch].pos;

				wcpy(dst, data + D_000082B0[ch].pos, m);
				D_000082B0[ch].pos = 0;
				wcpy((char *)dst + m, data, 0x70 - m);
				D_000082B0[ch].pos = 0x70 - m;
			}
		} else {
			int n, rem;

			n = D_000082B0[ch].size - D_000082B0[ch].pos;
			wcpy(dst, data + D_000082B0[ch].pos, n);
			D_000082B0[ch].pos = 0;
			rem = 0x70 - n;
			for (;;) {
				if ((int)D_000082B0[ch].size < rem) {
					wcpy((char *)dst + n, data, D_000082B0[ch].size);
					n += D_000082B0[ch].size;
					rem -= D_000082B0[ch].size;
				} else {
					wcpy((char *)dst + n, data, rem);
					D_000082B0[ch].pos += rem;
					break;
				}
			}
		}
	}
}

static void func_00005FCC(int ch, void *out_, void *src_)
{
	short *out = (short *)out_;
	short *src = (short *)src_;
	int i;
	int l, r, x;

	for (i = 0; i < 28; i++) {
		if (D_000082B0[ch].flags & 0x100000) {
			D_000082B0[ch].unk38 = (D_000082B0[ch].unk3C - D_000082B0[ch].unk40) * 127 / D_000082B0[ch].unk3C;
			if (D_000082B0[ch].unk38 < 0)
				D_000082B0[ch].unk38 = 0;
			D_000082B0[ch].unk40++;
			if (D_000082B0[ch].unk40 >= D_000082B0[ch].unk3C) {
				D_000082B0[ch].flags &= ~0x100000;
				D_000082B0[ch].unk40 = 0;
				if (D_000082B0[ch].flags & 0x10000) {
					D_000082B0[ch].flags &= ~0x10000;
					D_000082B0[ch].stat = D_00008510[ch].stat;
					D_000082B0[ch].pos = D_00008510[ch].pos;
					D_000082B0[ch].vol_l = D_00008510[ch].vol_l;
					D_000082B0[ch].vol_r = D_00008510[ch].vol_r;
					D_000082B0[ch].unk30 = D_00008510[ch].unk30;
					D_000082B0[ch].unk34 = D_00008510[ch].unk34;
					D_000082B0[ch].unk28 = D_00008510[ch].unk28;
					D_000082B0[ch].unk2C = D_00008510[ch].unk2C;
				} else if (D_000082B0[ch].flags & 0x20000) {
					D_000082B0[ch].flags &= ~0x20000;
					D_000082B0[ch].stat = D_00008510[ch].stat;
					D_000082B0[ch].pos = D_00008510[ch].pos;
					D_000082B0[ch].unk30 = D_00008510[ch].unk30;
					D_000082B0[ch].unk34 = D_00008510[ch].unk34;
					D_000082B0[ch].unk28 = D_00008510[ch].unk28;
					D_000082B0[ch].unk2C = D_00008510[ch].unk2C;
				} else if (D_000082B0[ch].flags & 0x40000) {
					D_000082B0[ch].flags &= ~0x40000;
					D_000082B0[ch].stat = D_00008510[ch].stat;
				}
			}
		} else {
			D_000082B0[ch].unk38 = 127;
		}
		if (!(D_000082B0[ch].flags & 0x100)) {
			l = D_000082B0[ch].vol_l * D_000082B0[ch].unk38 / 127;
			r = D_000082B0[ch].vol_r * D_000082B0[ch].unk38 / 127;
			l = l * src[i] / 4096;
			r = r * src[i] / 4096;
		} else if (!(D_000082B0[ch].flags & 0x200)) {
			l = D_000082B0[ch].vol_l * D_000082B0[ch].unk38 / 127;
			r = D_000082B0[ch].vol_r * D_000082B0[ch].unk38 / 127;
			l = l * src[i] / 4096;
			r = r * src[i] / 4096;
		} else {
			l = D_000082B0[ch].vol_l * D_000082B0[ch].unk38 / 127;
			r = D_000082B0[ch].vol_r * D_000082B0[ch].unk38 / 127;
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
