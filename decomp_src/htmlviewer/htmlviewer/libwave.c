/* cflags: -O2 -frename-registers */
#include "common.h"
#include "libwave_sdk.h"

static __inline__ void wclr_i(void *dst, unsigned int n)
{
	char *p = dst;
	unsigned int i;

	for (i = 0; i < n; i++)
		*p++ = 0;
}

int sceWaveInit(void)
{
	if (D_0069F1B4 != 0)
		return 0x80440001;
	D_006A050C = D_0069F1BC;
	D_006A0508 = D_0069F22C;
	wclr_i(D_006A003C, sizeof(D_006A003C));
	wclr_i(D_006A029C, sizeof(D_006A029C));
	D_006A04FC.ch = sceAudioChReserve(-1, 0x1c0, 0);
	if (D_006A04FC.ch < 0)
		return 0x80440001;
	D_006A0510[0] = sceAudioChReserve(-1, 0x100, 0);
	if (D_006A0510[0] < 0) {
		sceAudioChRelease(D_006A04FC.ch);
		return 0x80440001;
	}
	D_006A0510[1] = sceAudioChReserve(-1, 0x100, 0);
	if (D_006A0510[1] < 0) {
		sceAudioChRelease(D_006A04FC.ch);
		sceAudioChRelease(D_006A0510[0]);
		return 0x80440001;
	}
	D_006A0510[2] = sceAudioChReserve(-1, 0x100, 0);
	if (D_006A0510[2] < 0) {
		sceAudioChRelease(D_006A04FC.ch);
		sceAudioChRelease(D_006A0510[0]);
		sceAudioChRelease(D_006A0510[1]);
		return 0x80440001;
	}
	D_0069F1B4 = 1;
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
		v = &D_006A003C[ch];
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
		v = &D_006A003C[ch];
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
	D_006A003C[ch].vol_l = (int)(left << 12) / 127;
	D_006A003C[ch].vol_r = (int)(right << 12) / 127;
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
	if (D_006A003C[ch].vol_l <= 0)
		*left = 0;
	else if (D_006A003C[ch].vol_l >= 128)
		*left = (D_006A003C[ch].vol_l - 1) / 32;
	else
		*left = D_006A003C[ch].vol_l / 32;
	if (D_006A003C[ch].vol_r <= 0)
		*right = 0;
	else if (D_006A003C[ch].vol_r >= 128)
		*right = (D_006A003C[ch].vol_r - 1) / 32;
	else
		*right = D_006A003C[ch].vol_r / 32;
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
	D_006A003C[ch].vol_l = left;
	D_006A003C[ch].vol_r = right;
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
	*left = D_006A003C[ch].vol_l;
	*right = D_006A003C[ch].vol_r;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_006A003C[ch].stat == 0)
		*rest = 0;
	else if (!(D_006A003C[ch].flags & 0x400))
		*rest = D_006A003C[ch].size - D_006A003C[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_006A003C[ch].stat;
}

int sceWavePlay(unsigned int ch, int left, int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left < 0 || left >= 128)
		return 0x8044000A;
	if (right < 0 || right >= 128)
		return 0x8044000A;
	if (D_006A003C[ch].data == NULL && !(D_006A003C[ch].flags & 0x400))
		return 0x80440006;
	if (D_006A003C[ch].stat != 0) {
		D_006A003C[ch].flags |= 0x110000;
		D_006A029C[ch].stat = 1;
		D_006A029C[ch].vol_l = left * 0x1000 / 127;
		D_006A029C[ch].vol_r = right * 0x1000 / 127;
		D_006A029C[ch].pos = 0;
		D_006A029C[ch].unk30 = 0;
		D_006A029C[ch].unk34 = 0;
		D_006A029C[ch].unk28 = 0;
		D_006A029C[ch].unk2C = 0;
	} else {
		D_006A003C[ch].stat = 1;
		D_006A003C[ch].vol_l = left * 0x1000 / 127;
		D_006A003C[ch].vol_r = right * 0x1000 / 127;
		D_006A003C[ch].pos = 0;
		D_006A003C[ch].unk30 = 0;
		D_006A003C[ch].unk34 = 0;
		D_006A003C[ch].unk28 = 0;
		D_006A003C[ch].unk2C = 0;
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
	if (D_006A003C[ch].data == NULL && !(D_006A003C[ch].flags & 0x400))
		return 0x80440006;
	if (D_006A003C[ch].stat != 0) {
		D_006A003C[ch].flags |= 0x110000;
		D_006A029C[ch].stat = 1;
		D_006A029C[ch].vol_l = left;
		D_006A029C[ch].vol_r = right;
		D_006A029C[ch].pos = 0;
		D_006A029C[ch].unk30 = 0;
		D_006A029C[ch].unk34 = 0;
		D_006A029C[ch].unk28 = 0;
		D_006A029C[ch].unk2C = 0;
	} else {
		D_006A003C[ch].stat = 1;
		D_006A003C[ch].vol_l = left;
		D_006A003C[ch].vol_r = right;
		D_006A003C[ch].pos = 0;
		D_006A003C[ch].unk30 = 0;
		D_006A003C[ch].unk34 = 0;
		D_006A003C[ch].unk28 = 0;
		D_006A003C[ch].unk2C = 0;
	}
	return 0;
}

int sceWaveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_006A003C[ch].stat != 0) {
			D_006A003C[ch].flags |= 0x120000;
			D_006A029C[ch].stat = 0;
			D_006A029C[ch].pos = 0;
			D_006A029C[ch].unk30 = 0;
			D_006A029C[ch].unk34 = 0;
			D_006A029C[ch].unk28 = 0;
			D_006A029C[ch].unk2C = 0;
		} else {
			D_006A003C[ch].pos = 0;
			D_006A003C[ch].unk30 = 0;
			D_006A003C[ch].unk34 = 0;
			D_006A003C[ch].unk28 = 0;
			D_006A003C[ch].unk2C = 0;
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
	return sceAudioSetChannelDataLen(D_006A0510[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_006A0510[ch], left, right);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_006A0510[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_006A0510[ch], left, right, buf);
}

int sceWaveStart(int prio)
{
	if (D_0069F1B4 != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return func_00006280(prio);
}

int sceKernelDeleteThread(int thid);
int sceWaveEnd(void)
{
	int i;

	if (D_0069F1B4 != 3)
		return 0x80440004;
	for (i = 0; i < 8; i++)
		sceWaveStop(i);
	D_0069F1B8 = 1;
	sceKernelWaitThreadEnd(D_006A04FC.thid, NULL);
	sceKernelDeleteThread(D_006A04FC.thid);
	D_0069F1B8 = 0;
	D_0069F1B4 = 1;
	return 0;
}

int sceWaveExit(void)
{
	if (D_0069F1B4 != 1)
		return 0x80440002;
	sceAudioChRelease(D_006A04FC.ch);
	sceAudioChRelease(D_006A0510[0]);
	sceAudioChRelease(D_006A0510[1]);
	sceAudioChRelease(D_006A0510[2]);
	D_006A0508 = NULL;
	D_006A050C = NULL;
	D_0069F1B4 = 0;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_006A003C[ch].flags = (D_006A003C[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_006A003C[ch].stat != 0) {
		D_006A029C[ch].stat = 0;
		D_006A003C[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_006A003C[ch].stat == 0)
		D_006A003C[ch].stat = 1;
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
	return sceAudioChangeChannelConfig(D_006A0510[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLength(D_006A0510[ch]);
}

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libwave", D_000F362C);
INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libwave", D_000F3644);
static int func_00006280(int prio)
{
	D_0069F1B8 = 0;
	D_006A04FC.thid = sceKernelCreateThread("SceWaveMain", func_00006324, prio, 0x1000, 0, NULL);
	if (D_006A04FC.thid < 0)
		return 0x80440003;
	D_006A04FC.prio = prio;
	if (sceKernelStartThread(D_006A04FC.thid, sizeof(SceWaveMain), &D_006A04FC) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_0069F1B4 = 3;
	return 0;
}

static int func_00006324(unsigned int args, void *argp)
{
	SceWaveMain *m = (SceWaveMain *)argp;
	int i = 0;
	int j;

	while (D_0069F1B8 == 0) {
		if (func_00006440(D_0069F23C[i]) == 0) {
			sceKernelDelayThread(10000);
			continue;
		}
		for (j = 1; j < 16; j++)
			func_00006440(D_0069F23C[i] + j * 0x70);
		sceAudioOutputBlocking(m->ch, 0x8000, D_0069F23C[i]);
		i = (i + 1) % 2;
	}
	sceAudioOutputBlocking(m->ch, 0, NULL);
	sceKernelExitThread(0);
	return 0;
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libwave", func_00006440);

/* VAG (PS-ADPCM) block decoder: 28 samples from a 16-byte block */
extern const signed char D_000F3644[2][5];
static int func_00006628(short *dst, unsigned char *vag, int *hist1, int *hist2)
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
	f0 = D_000F3644[0][predict];
	f1 = D_000F3644[1][predict];
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

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libwave", func_0000676C);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libwave", func_00006A18);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/libwave", func_00006F88);

