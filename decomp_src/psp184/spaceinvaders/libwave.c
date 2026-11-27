/* cflags: -O2 -frename-registers */
#include "common.h"
#include "libwave_sdk.h"

static __inline__ void wclr(void *dst, int n)
{
	char *p = dst;
	int i;

	for (i = 0; i < n; i++)
		*p++ = 0;
}

int sceWaveInit(void)
{
	if (D_003523D4 != 0)
		return 0x80440001;
	D_0035372C = D_003523DC;
	D_00353728 = D_0035244C;
	wclr(D_0035325C, sizeof(D_0035325C));
	wclr(D_003534BC, sizeof(D_003534BC));
	D_0035371C.ch = sceAudioChReserve(-1, 0x1c0, 0);
	if (D_0035371C.ch < 0)
		return 0x80440001;
	D_00353730[0] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00353730[0] < 0) {
		sceAudioChRelease(D_0035371C.ch);
		return 0x80440001;
	}
	D_00353730[1] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00353730[1] < 0) {
		sceAudioChRelease(D_0035371C.ch);
		sceAudioChRelease(D_00353730[0]);
		return 0x80440001;
	}
	D_00353730[2] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00353730[2] < 0) {
		sceAudioChRelease(D_0035371C.ch);
		sceAudioChRelease(D_00353730[0]);
		sceAudioChRelease(D_00353730[1]);
		return 0x80440001;
	}
	D_003523D4 = 1;
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
		v = &D_0035325C[ch];
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
		v = &D_0035325C[ch];
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
	D_0035325C[ch].vol_l = (int)(left << 12) / 127;
	D_0035325C[ch].vol_r = (int)(right << 12) / 127;
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
	if (D_0035325C[ch].vol_l <= 0)
		*left = 0;
	else if (D_0035325C[ch].vol_l >= 128)
		*left = (D_0035325C[ch].vol_l - 1) / 32;
	else
		*left = D_0035325C[ch].vol_l / 32;
	if (D_0035325C[ch].vol_r <= 0)
		*right = 0;
	else if (D_0035325C[ch].vol_r >= 128)
		*right = (D_0035325C[ch].vol_r - 1) / 32;
	else
		*right = D_0035325C[ch].vol_r / 32;
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
	D_0035325C[ch].vol_l = left;
	D_0035325C[ch].vol_r = right;
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
	*left = D_0035325C[ch].vol_l;
	*right = D_0035325C[ch].vol_r;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_0035325C[ch].stat == 0)
		*rest = 0;
	else if (!(D_0035325C[ch].flags & 0x400))
		*rest = D_0035325C[ch].size - D_0035325C[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_0035325C[ch].stat;
}

int sceWavePlay(unsigned int ch, int left, int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left < 0 || left >= 128)
		return 0x8044000A;
	if (right < 0 || right >= 128)
		return 0x8044000A;
	if (D_0035325C[ch].data == NULL && !(D_0035325C[ch].flags & 0x400))
		return 0x80440006;
	if (D_0035325C[ch].stat != 0) {
		D_0035325C[ch].flags |= 0x110000;
		D_003534BC[ch].stat = 1;
		D_003534BC[ch].vol_l = left * 0x1000 / 127;
		D_003534BC[ch].vol_r = right * 0x1000 / 127;
		D_003534BC[ch].pos = 0;
		D_003534BC[ch].unk30 = 0;
		D_003534BC[ch].unk34 = 0;
		D_003534BC[ch].unk28 = 0;
		D_003534BC[ch].unk2C = 0;
	} else {
		D_0035325C[ch].stat = 1;
		D_0035325C[ch].vol_l = left * 0x1000 / 127;
		D_0035325C[ch].vol_r = right * 0x1000 / 127;
		D_0035325C[ch].pos = 0;
		D_0035325C[ch].unk30 = 0;
		D_0035325C[ch].unk34 = 0;
		D_0035325C[ch].unk28 = 0;
		D_0035325C[ch].unk2C = 0;
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
	if (D_0035325C[ch].data == NULL && !(D_0035325C[ch].flags & 0x400))
		return 0x80440006;
	if (D_0035325C[ch].stat != 0) {
		D_0035325C[ch].flags |= 0x110000;
		D_003534BC[ch].stat = 1;
		D_003534BC[ch].vol_l = left;
		D_003534BC[ch].vol_r = right;
		D_003534BC[ch].pos = 0;
		D_003534BC[ch].unk30 = 0;
		D_003534BC[ch].unk34 = 0;
		D_003534BC[ch].unk28 = 0;
		D_003534BC[ch].unk2C = 0;
	} else {
		D_0035325C[ch].stat = 1;
		D_0035325C[ch].vol_l = left;
		D_0035325C[ch].vol_r = right;
		D_0035325C[ch].pos = 0;
		D_0035325C[ch].unk30 = 0;
		D_0035325C[ch].unk34 = 0;
		D_0035325C[ch].unk28 = 0;
		D_0035325C[ch].unk2C = 0;
	}
	return 0;
}

int sceWaveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_0035325C[ch].stat != 0) {
			D_0035325C[ch].flags |= 0x120000;
			D_003534BC[ch].stat = 0;
			D_003534BC[ch].pos = 0;
			D_003534BC[ch].unk30 = 0;
			D_003534BC[ch].unk34 = 0;
			D_003534BC[ch].unk28 = 0;
			D_003534BC[ch].unk2C = 0;
		} else {
			D_0035325C[ch].pos = 0;
			D_0035325C[ch].unk30 = 0;
			D_0035325C[ch].unk34 = 0;
			D_0035325C[ch].unk28 = 0;
			D_0035325C[ch].unk2C = 0;
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
	return sceAudioSetChannelDataLen(D_00353730[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_00353730[ch], left, right);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_00353730[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_00353730[ch], left, right, buf);
}

int sceWaveStart(int prio)
{
	if (D_003523D4 != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return func_0006C324(prio);
}

int sceWaveEnd(void)
{
	int i;

	if (D_003523D4 != 3)
		return 0x80440004;
	for (i = 0; i < 8; i++)
		sceWaveStop(i);
	D_003523D8 = 1;
	sceKernelWaitThreadEnd(D_0035371C.thid, NULL);
	sceKernelDeleteThread(D_0035371C.thid);
	D_003523D8 = 0;
	D_003523D4 = 1;
	return 0;
}

int sceWaveExit(void)
{
	if (D_003523D4 != 1)
		return 0x80440002;
	sceAudioChRelease(D_0035371C.ch);
	sceAudioChRelease(D_00353730[0]);
	sceAudioChRelease(D_00353730[1]);
	sceAudioChRelease(D_00353730[2]);
	D_00353728 = NULL;
	D_0035372C = NULL;
	D_003523D4 = 0;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_0035325C[ch].flags = (D_0035325C[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_0035325C[ch].stat != 0) {
		D_003534BC[ch].stat = 0;
		D_0035325C[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_0035325C[ch].stat == 0)
		D_0035325C[ch].stat = 1;
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
	return sceAudioChangeChannelConfig(D_00353730[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLength(D_00353730[ch]);
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/libwave", D_0007FB28);
static int func_0006C324(int prio)
{
	D_003523D8 = 0;
	D_0035371C.thid = sceKernelCreateThread("SceWaveMain", func_0006C3C8, prio, 0x1000, 0, NULL);
	if (D_0035371C.thid < 0)
		return 0x80440003;
	D_0035371C.prio = prio;
	if (sceKernelStartThread(D_0035371C.thid, sizeof(SceWaveMain), &D_0035371C) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_003523D4 = 3;
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libwave", func_0006C3C8);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libwave", func_0006C4E4);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libwave", func_0006C6BC);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libwave", func_0006C800);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libwave", func_0006CA9C);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/libwave", func_0006CFB4);

