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

extern volatile int D_002F1B20;
extern char D_002F1B28[];
extern char D_002F1B98[];
extern SceWaveVoice D_002F29A8[8];
extern SceWaveVoice D_002F2C08[8];
extern SceWaveMain D_002F2E68;
extern void *D_002F2E74;
extern void *D_002F2E78;
extern int D_002F2E7C[3];

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
static int func_00009720(unsigned int args, void *argp);
extern volatile int D_002F1B24;
extern char D_002F1BA8[2][0x700];
extern const signed char D_000174B4[2][5];
static void func_000097FC(char *buf);
static int func_000099B4(short *dst, unsigned char *src, int *h1, int *h2);
static void func_00009AF8(int ch, void *dst);
static void func_00009D94(int ch, void *dst);
static void func_0000A2AC(int ch, void *buf, void *src);

static inline int _waveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_002F29A8[ch].stat != 0) {
			D_002F29A8[ch].flags |= 0x120000;
			D_002F2C08[ch].stat = 0;
			D_002F2C08[ch].pos = 0;
			D_002F2C08[ch].unk30 = 0;
			D_002F2C08[ch].unk34 = 0;
			D_002F2C08[ch].unk28 = 0;
			D_002F2C08[ch].unk2C = 0;
		} else {
			D_002F29A8[ch].pos = 0;
			D_002F29A8[ch].unk30 = 0;
			D_002F29A8[ch].unk34 = 0;
			D_002F29A8[ch].unk28 = 0;
			D_002F29A8[ch].unk2C = 0;
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

int sceWaveInit(void)
{
	if (D_002F1B20 != 0)
		return 0x80440001;
	D_002F2E78 = D_002F1B28;
	D_002F2E74 = D_002F1B98;
	wclr(D_002F29A8, sizeof(D_002F29A8));
	wclr(D_002F2C08, sizeof(D_002F2C08));
	D_002F2E68.ch = sceAudioChReserve(-1, 0x1c0, 0);
	if (D_002F2E68.ch < 0)
		return 0x80440001;
	D_002F2E7C[0] = sceAudioChReserve(-1, 0x100, 0);
	if (D_002F2E7C[0] < 0) {
		sceAudioChRelease(D_002F2E68.ch);
		return 0x80440001;
	}
	D_002F2E7C[1] = sceAudioChReserve(-1, 0x100, 0);
	if (D_002F2E7C[1] < 0) {
		sceAudioChRelease(D_002F2E68.ch);
		sceAudioChRelease(D_002F2E7C[0]);
		return 0x80440001;
	}
	D_002F2E7C[2] = sceAudioChReserve(-1, 0x100, 0);
	if (D_002F2E7C[2] < 0) {
		sceAudioChRelease(D_002F2E68.ch);
		sceAudioChRelease(D_002F2E7C[0]);
		sceAudioChRelease(D_002F2E7C[1]);
		return 0x80440001;
	}
	D_002F1B20 = 1;
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
		v = &D_002F29A8[ch];
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
		v = &D_002F29A8[ch];
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
	if (D_002F29A8[ch].vol_l <= 0)
		*left = 0;
	else if (D_002F29A8[ch].vol_l >= 128)
		*left = (D_002F29A8[ch].vol_l - 1) / 32;
	else
		*left = D_002F29A8[ch].vol_l / 32;
	if (D_002F29A8[ch].vol_r <= 0)
		*right = 0;
	else if (D_002F29A8[ch].vol_r >= 128)
		*right = (D_002F29A8[ch].vol_r - 1) / 32;
	else
		*right = D_002F29A8[ch].vol_r / 32;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_002F29A8[ch].stat == 0)
		*rest = 0;
	else if (!(D_002F29A8[ch].flags & 0x400))
		*rest = D_002F29A8[ch].size - D_002F29A8[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_002F29A8[ch].stat;
}

int sceWavePlay(unsigned int ch, int left, int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left < 0 || left >= 128)
		return 0x8044000A;
	if (right < 0 || right >= 128)
		return 0x8044000A;
	if (D_002F29A8[ch].data == NULL && !(D_002F29A8[ch].flags & 0x400))
		return 0x80440006;
	if (D_002F29A8[ch].stat != 0) {
		D_002F29A8[ch].flags |= 0x110000;
		D_002F2C08[ch].stat = 1;
		D_002F2C08[ch].vol_l = left * 0x1000 / 127;
		D_002F2C08[ch].vol_r = right * 0x1000 / 127;
		D_002F2C08[ch].pos = 0;
		D_002F2C08[ch].unk30 = 0;
		D_002F2C08[ch].unk34 = 0;
		D_002F2C08[ch].unk28 = 0;
		D_002F2C08[ch].unk2C = 0;
	} else {
		D_002F29A8[ch].stat = 1;
		D_002F29A8[ch].vol_l = left * 0x1000 / 127;
		D_002F29A8[ch].vol_r = right * 0x1000 / 127;
		D_002F29A8[ch].pos = 0;
		D_002F29A8[ch].unk30 = 0;
		D_002F29A8[ch].unk34 = 0;
		D_002F29A8[ch].unk28 = 0;
		D_002F29A8[ch].unk2C = 0;
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
	if (D_002F29A8[ch].data == NULL && !(D_002F29A8[ch].flags & 0x400))
		return 0x80440006;
	if (D_002F29A8[ch].stat != 0) {
		D_002F29A8[ch].flags |= 0x110000;
		D_002F2C08[ch].stat = 1;
		D_002F2C08[ch].vol_l = left;
		D_002F2C08[ch].vol_r = right;
		D_002F2C08[ch].pos = 0;
		D_002F2C08[ch].unk30 = 0;
		D_002F2C08[ch].unk34 = 0;
		D_002F2C08[ch].unk28 = 0;
		D_002F2C08[ch].unk2C = 0;
	} else {
		D_002F29A8[ch].stat = 1;
		D_002F29A8[ch].vol_l = left;
		D_002F29A8[ch].vol_r = right;
		D_002F29A8[ch].pos = 0;
		D_002F29A8[ch].unk30 = 0;
		D_002F29A8[ch].unk34 = 0;
		D_002F29A8[ch].unk28 = 0;
		D_002F29A8[ch].unk2C = 0;
	}
	return 0;
}

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/libwave", D_000174B4);

static inline int _waveThreadStart(int prio)
{
	D_002F1B24 = 0;
	D_002F2E68.thid = sceKernelCreateThread("SceWaveMain", func_00009720, prio, 0x1000, 0, NULL);
	if (D_002F2E68.thid < 0)
		return 0x80440003;
	D_002F2E68.prio = prio;
	if (sceKernelStartThread(D_002F2E68.thid, sizeof(SceWaveMain), &D_002F2E68) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_002F1B20 = 3;
	return 0;
}

int sceWaveStart(int prio)
{
	if (D_002F1B20 != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return _waveThreadStart(prio);
}

int sceWaveEnd(void)
{
	int i;

	if (D_002F1B20 != 3)
		return 0x80440004;
	for (i = 0; i < 8; i++)
		_waveStop(i);
	D_002F1B24 = 1;
	sceKernelWaitThreadEnd(D_002F2E68.thid, NULL);
	sceKernelDeleteThread(D_002F2E68.thid);
	D_002F1B24 = 0;
	D_002F1B20 = 1;
	return 0;
}

int sceWaveExit(void)
{
	if (D_002F1B20 != 1)
		return 0x80440002;
	sceAudioChRelease(D_002F2E68.ch);
	sceAudioChRelease(D_002F2E7C[0]);
	sceAudioChRelease(D_002F2E7C[1]);
	sceAudioChRelease(D_002F2E7C[2]);
	D_002F2E74 = NULL;
	D_002F2E78 = NULL;
	D_002F1B20 = 0;
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
	D_002F29A8[ch].vol_l = (int)(left << 12) / 127;
	D_002F29A8[ch].vol_r = (int)(right << 12) / 127;
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
	D_002F29A8[ch].vol_l = left;
	D_002F29A8[ch].vol_r = right;
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
	*left = D_002F29A8[ch].vol_l;
	*right = D_002F29A8[ch].vol_r;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_002F29A8[ch].flags = (D_002F29A8[ch].flags & ~0xff) | mode;
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
	if (D_002F29A8[ch].stat != 0) {
		D_002F2C08[ch].stat = 0;
		D_002F29A8[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_002F29A8[ch].stat == 0)
		D_002F29A8[ch].stat = 1;
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
	return sceAudioSetChannelDataLen(D_002F2E7C[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_002F2E7C[ch], left, right);
}

int sceWaveAudioSetFormat(unsigned int ch, int format)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioChangeChannelConfig(D_002F2E7C[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLen(D_002F2E7C[ch]);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_002F2E7C[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_002F2E7C[ch], left, right, buf);
}

static int func_00009720(unsigned int args, void *argp)
{
	SceWaveMain *m = (SceWaveMain *)argp;
	int i = 0;
	int j;

	while (D_002F1B24 == 0) {
		for (j = 0; j < 16; j++)
			func_000097FC(D_002F1BA8[i] + j * 0x70);
		sceAudioOutputBlocking(m->ch, 0x8000, D_002F1BA8[i]);
		i = (i + 1) % 2;
	}
	sceAudioOutputBlocking(m->ch, 0, NULL);
	sceKernelExitThread(0);
	return 0;
}

typedef int (*SceWaveCallback)(int ch, void *buf, int size, int arg);

static void func_000097FC(char *buf)
{
	int ch;

	wclr(buf, 0x70);
	for (ch = 0; ch < 8; ch++) {
		if (D_002F29A8[ch].stat == 0)
			continue;
		if (!(D_002F29A8[ch].flags & 0x400)) {
			if (!(D_002F29A8[ch].flags & 0x100)) {
				if (D_002F29A8[ch].data != NULL)
					func_00009AF8(ch, D_002F2E78);
			} else {
				if (D_002F29A8[ch].data != NULL)
					func_00009D94(ch, D_002F2E78);
			}
		} else {
			if (D_002F29A8[ch].unk44 != 0) {
				wclr(D_002F2E78, 0x70);
				if (!(D_002F29A8[ch].flags & 0x100)) {
					if (((SceWaveCallback)D_002F29A8[ch].unk44)(ch, D_002F2E74, 0x10, D_002F29A8[ch].unk48))
						D_002F29A8[ch].stat = 0;
					func_000099B4(D_002F2E78, D_002F2E74, &D_002F29A8[ch].unk30, &D_002F29A8[ch].unk34);
				} else {
					if (((SceWaveCallback)D_002F29A8[ch].unk44)(ch, D_002F2E78, 0x70, D_002F29A8[ch].unk48))
						D_002F29A8[ch].stat = 0;
				}
			}
		}
		func_0000A2AC(ch, buf, D_002F2E78);
	}
}

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libwave", func_000099B4);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libwave", func_00009AF8);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libwave", func_00009D94);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/libwave", func_0000A2AC);
