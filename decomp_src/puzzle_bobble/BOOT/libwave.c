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

/* state and stop flag, shared with the audio thread */
extern volatile int D_005612EC;
extern volatile int D_005612F0;
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
extern const signed char D_00030954[2][5];
extern char D_00561374[2][0x700];
static void func_0001EB5C(char *buf);
static int func_0001ED14(short *dst, unsigned char *src, int *h1, int *h2);
static void func_0001EE58(int ch, void *dst);
static void func_0001F0F4(int ch, void *dst);
static void func_0001F60C(int ch, void *buf, void *src);

/* sceWaveStop's body, inlined into sceWaveAllStop too */
static inline int _waveStop(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_00562174[ch].stat != 0) {
		D_00562174[ch].flags |= 0x120000;
		D_005623D4[ch].stat = 0;
		D_005623D4[ch].pos = 0;
		D_005623D4[ch].unk30 = 0;
		D_005623D4[ch].unk34 = 0;
		D_005623D4[ch].unk28 = 0;
		D_005623D4[ch].unk2C = 0;
	} else {
		D_00562174[ch].pos = 0;
		D_00562174[ch].unk30 = 0;
		D_00562174[ch].unk34 = 0;
		D_00562174[ch].unk28 = 0;
		D_00562174[ch].unk2C = 0;
	}
	return 0;
}

static __inline__ void wclr(void *dst, int n)
{
	char *p = dst;

	while (--n >= 0)
		*p++ = 0;
}

int sceWaveInit(void)
{
	if (D_005612EC != 0)
		return 0x80440001;
	D_00562644 = D_005612F4;
	D_00562640 = D_00561364;
	wclr(D_00562174, sizeof(D_00562174));
	wclr(D_005623D4, sizeof(D_005623D4));
	D_00562634.ch = sceAudioChReserve(-1, 0x1c0, 0);
	if (D_00562634.ch < 0)
		return 0x80440001;
	D_00562648[0] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00562648[0] < 0) {
		sceAudioChRelease(D_00562634.ch);
		return 0x80440001;
	}
	D_00562648[1] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00562648[1] < 0) {
		sceAudioChRelease(D_00562634.ch);
		sceAudioChRelease(D_00562648[0]);
		return 0x80440001;
	}
	D_00562648[2] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00562648[2] < 0) {
		sceAudioChRelease(D_00562634.ch);
		sceAudioChRelease(D_00562648[0]);
		sceAudioChRelease(D_00562648[1]);
		return 0x80440001;
	}
	D_005612EC = 1;
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
		v = &D_00562174[ch];
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
		v = &D_00562174[ch];
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
	if (D_00562174[ch].vol_l <= 0)
		*left = 0;
	else if (D_00562174[ch].vol_l >= 128)
		*left = (D_00562174[ch].vol_l - 1) / 32;
	else
		*left = D_00562174[ch].vol_l / 32;
	if (D_00562174[ch].vol_r <= 0)
		*right = 0;
	else if (D_00562174[ch].vol_r >= 128)
		*right = (D_00562174[ch].vol_r - 1) / 32;
	else
		*right = D_00562174[ch].vol_r / 32;
	return 0;
}

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

int sceWavePlay(unsigned int ch, int left, int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left < 0 || left >= 128)
		return 0x8044000A;
	if (right < 0 || right >= 128)
		return 0x8044000A;
	if (D_00562174[ch].data == NULL && !(D_00562174[ch].flags & 0x400))
		return 0x80440006;
	if (D_00562174[ch].stat != 0) {
		D_00562174[ch].flags |= 0x110000;
		D_005623D4[ch].stat = 1;
		D_005623D4[ch].vol_l = left * 0x1000 / 127;
		D_005623D4[ch].vol_r = right * 0x1000 / 127;
		D_005623D4[ch].pos = 0;
		D_005623D4[ch].unk30 = 0;
		D_005623D4[ch].unk34 = 0;
		D_005623D4[ch].unk28 = 0;
		D_005623D4[ch].unk2C = 0;
	} else {
		D_00562174[ch].stat = 1;
		D_00562174[ch].vol_l = left * 0x1000 / 127;
		D_00562174[ch].vol_r = right * 0x1000 / 127;
		D_00562174[ch].pos = 0;
		D_00562174[ch].unk30 = 0;
		D_00562174[ch].unk34 = 0;
		D_00562174[ch].unk28 = 0;
		D_00562174[ch].unk2C = 0;
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
	if (D_00562174[ch].data == NULL && !(D_00562174[ch].flags & 0x400))
		return 0x80440006;
	if (D_00562174[ch].stat != 0) {
		D_00562174[ch].flags |= 0x110000;
		D_005623D4[ch].stat = 1;
		D_005623D4[ch].vol_l = left;
		D_005623D4[ch].vol_r = right;
		D_005623D4[ch].pos = 0;
		D_005623D4[ch].unk30 = 0;
		D_005623D4[ch].unk34 = 0;
		D_005623D4[ch].unk28 = 0;
		D_005623D4[ch].unk2C = 0;
	} else {
		D_00562174[ch].stat = 1;
		D_00562174[ch].vol_l = left;
		D_00562174[ch].vol_r = right;
		D_00562174[ch].pos = 0;
		D_00562174[ch].unk30 = 0;
		D_00562174[ch].unk34 = 0;
		D_00562174[ch].unk28 = 0;
		D_00562174[ch].unk2C = 0;
	}
	return 0;
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", D_00030954);

static inline int _waveThreadStart(int prio)
{
	D_005612F0 = 0;
	D_00562634.thid = sceKernelCreateThread("SceWaveMain", func_0001EA80, prio, 0x1000, 0, NULL);
	if (D_00562634.thid < 0)
		return 0x80440003;
	D_00562634.prio = prio;
	if (sceKernelStartThread(D_00562634.thid, sizeof(SceWaveMain), &D_00562634) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_005612EC = 3;
	return 0;
}

int sceWaveStart(int prio)
{
	if (D_005612EC != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return _waveThreadStart(prio);
}

int sceWaveEnd(void)
{
	int i;

	if (D_005612EC != 3)
		return 0x80440004;
	for (i = 0; i < 8; i++)
		_waveStop(i);
	D_005612F0 = 1;
	sceKernelWaitThreadEnd(D_00562634.thid, NULL);
	sceKernelDeleteThread(D_00562634.thid);
	D_005612F0 = 0;
	D_005612EC = 1;
	return 0;
}

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

int sceWaveStop(unsigned int ch)
{
	return _waveStop(ch);
}

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

static int func_0001EA80(unsigned int args, void *argp)
{
	SceWaveMain *m = (SceWaveMain *)argp;
	int i = 0;
	int j;

	while (D_005612F0 == 0) {
		for (j = 0; j < 16; j++)
			func_0001EB5C(D_00561374[i] + j * 0x70);
		sceAudioOutputBlocking(m->ch, 0x8000, D_00561374[i]);
		i = (i + 1) % 2;
	}
	sceAudioOutputBlocking(m->ch, 0, NULL);
	sceKernelExitThread(0);
	return 0;
}

typedef int (*SceWaveCallback)(int ch, void *buf, int size, int arg);

static void func_0001EB5C(char *buf)
{
	int ch;

	wclr(buf, 0x70);
	for (ch = 0; ch < 8; ch++) {
		if (D_00562174[ch].stat == 0)
			continue;
		if (!(D_00562174[ch].flags & 0x400)) {
			if (!(D_00562174[ch].flags & 0x100)) {
				if (D_00562174[ch].data != NULL)
					func_0001EE58(ch, D_00562644);
			} else {
				if (D_00562174[ch].data != NULL)
					func_0001F0F4(ch, D_00562644);
			}
		} else {
			if (D_00562174[ch].unk44 != 0) {
				wclr(D_00562644, 0x70);
				if (!(D_00562174[ch].flags & 0x100)) {
					if (((SceWaveCallback)D_00562174[ch].unk44)(ch, D_00562640, 0x10, D_00562174[ch].unk48))
						D_00562174[ch].stat = 0;
					func_0001ED14(D_00562644, D_00562640, &D_00562174[ch].unk30, &D_00562174[ch].unk34);
				} else {
					if (((SceWaveCallback)D_00562174[ch].unk44)(ch, D_00562644, 0x70, D_00562174[ch].unk48))
						D_00562174[ch].stat = 0;
				}
			}
		}
		func_0001F60C(ch, buf, D_00562644);
	}
}

#ifdef NON_MATCHING
/* VAG ADPCM block decoder, diff 46 (statement order from perm.py): same instructions,
 * callee-saved registers differ (original: s0 flag, s1 -16 mask, s2 h1, s3 h2). */
static int func_0001ED14(short *dst, unsigned char *src, int *h1, int *h2)
{
	int p, shift, filter, flag, c0, c1, s1, s2, n, k, d, v, w;

	s1 = *h1;
	p = src[0];
	shift = p & 0xF;
	filter = p >> 4;
	s2 = *h2;
	c0 = D_00030954[0][filter];
	c1 = D_00030954[1][filter];
	flag = src[1];
	n = 14;
	k = 2;
	if (flag == 7)
		return 7;
	while (--n >= 0) {
		d = (signed char)src[k++];
		v = (((d << 28) >> (shift + 10)) + s1 * c0 + s2 * c1) >> 6;
		if (v > 32767) v = 32767;
		if (v < -32768) v = -32768;
		s2 = s1;
		s1 = v;
		w = (((d & ~0xF) << (14 - shift)) + s1 * c0 + s2 * c1) >> 6;
		if (w > 32767) w = 32767;
		if (w < -32768) w = -32768;
		*dst++ = v;
		*dst++ = w;
		s2 = s1;
		s1 = w;
	}
	*h1 = s1;
	*h2 = s2;
	return flag;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", func_0001ED14);
#endif

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", func_0001EE58);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", func_0001F0F4);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/libwave", func_0001F60C);
