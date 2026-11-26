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
	if (D_0001375C != 0)
		return 0x80440001;
	D_00014AB4 = D_00013764;
	D_00014AB0 = D_000137D4;
	wclr_i(D_000145E4, sizeof(D_000145E4));
	wclr_i(D_00014844, sizeof(D_00014844));
	D_00014AA4.ch = sceAudioChReserve(-1, 0x1c0, 0);
	if (D_00014AA4.ch < 0)
		return 0x80440001;
	D_00014AB8[0] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00014AB8[0] < 0) {
		sceAudioChRelease(D_00014AA4.ch);
		return 0x80440001;
	}
	D_00014AB8[1] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00014AB8[1] < 0) {
		sceAudioChRelease(D_00014AA4.ch);
		sceAudioChRelease(D_00014AB8[0]);
		return 0x80440001;
	}
	D_00014AB8[2] = sceAudioChReserve(-1, 0x100, 0);
	if (D_00014AB8[2] < 0) {
		sceAudioChRelease(D_00014AA4.ch);
		sceAudioChRelease(D_00014AB8[0]);
		sceAudioChRelease(D_00014AB8[1]);
		return 0x80440001;
	}
	D_0001375C = 1;
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
		v = &D_000145E4[ch];
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
		v = &D_000145E4[ch];
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
	D_000145E4[ch].vol_l = (int)(left << 12) / 127;
	D_000145E4[ch].vol_r = (int)(right << 12) / 127;
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
	if (D_000145E4[ch].vol_l <= 0)
		*left = 0;
	else if (D_000145E4[ch].vol_l >= 128)
		*left = (D_000145E4[ch].vol_l - 1) / 32;
	else
		*left = D_000145E4[ch].vol_l / 32;
	if (D_000145E4[ch].vol_r <= 0)
		*right = 0;
	else if (D_000145E4[ch].vol_r >= 128)
		*right = (D_000145E4[ch].vol_r - 1) / 32;
	else
		*right = D_000145E4[ch].vol_r / 32;
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
	D_000145E4[ch].vol_l = left;
	D_000145E4[ch].vol_r = right;
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
	*left = D_000145E4[ch].vol_l;
	*right = D_000145E4[ch].vol_r;
	return 0;
}

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_000145E4[ch].stat == 0)
		*rest = 0;
	else if (!(D_000145E4[ch].flags & 0x400))
		*rest = D_000145E4[ch].size - D_000145E4[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_000145E4[ch].stat;
}

int sceWavePlay(unsigned int ch, int left, int right)
{
	if (ch >= 8)
		return 0x80440005;
	if (left < 0 || left >= 128)
		return 0x8044000A;
	if (right < 0 || right >= 128)
		return 0x8044000A;
	if (D_000145E4[ch].data == NULL && !(D_000145E4[ch].flags & 0x400))
		return 0x80440006;
	if (D_000145E4[ch].stat != 0) {
		D_000145E4[ch].flags |= 0x110000;
		D_00014844[ch].stat = 1;
		D_00014844[ch].vol_l = left * 0x1000 / 127;
		D_00014844[ch].vol_r = right * 0x1000 / 127;
		D_00014844[ch].pos = 0;
		D_00014844[ch].unk30 = 0;
		D_00014844[ch].unk34 = 0;
		D_00014844[ch].unk28 = 0;
		D_00014844[ch].unk2C = 0;
	} else {
		D_000145E4[ch].stat = 1;
		D_000145E4[ch].vol_l = left * 0x1000 / 127;
		D_000145E4[ch].vol_r = right * 0x1000 / 127;
		D_000145E4[ch].pos = 0;
		D_000145E4[ch].unk30 = 0;
		D_000145E4[ch].unk34 = 0;
		D_000145E4[ch].unk28 = 0;
		D_000145E4[ch].unk2C = 0;
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
	if (D_000145E4[ch].data == NULL && !(D_000145E4[ch].flags & 0x400))
		return 0x80440006;
	if (D_000145E4[ch].stat != 0) {
		D_000145E4[ch].flags |= 0x110000;
		D_00014844[ch].stat = 1;
		D_00014844[ch].vol_l = left;
		D_00014844[ch].vol_r = right;
		D_00014844[ch].pos = 0;
		D_00014844[ch].unk30 = 0;
		D_00014844[ch].unk34 = 0;
		D_00014844[ch].unk28 = 0;
		D_00014844[ch].unk2C = 0;
	} else {
		D_000145E4[ch].stat = 1;
		D_000145E4[ch].vol_l = left;
		D_000145E4[ch].vol_r = right;
		D_000145E4[ch].pos = 0;
		D_000145E4[ch].unk30 = 0;
		D_000145E4[ch].unk34 = 0;
		D_000145E4[ch].unk28 = 0;
		D_000145E4[ch].unk2C = 0;
	}
	return 0;
}

int sceWaveStop(unsigned int ch)
{
	int ret = 0x80440005;

	if (ch < 8) {
		if (D_000145E4[ch].stat != 0) {
			D_000145E4[ch].flags |= 0x120000;
			D_00014844[ch].stat = 0;
			D_00014844[ch].pos = 0;
			D_00014844[ch].unk30 = 0;
			D_00014844[ch].unk34 = 0;
			D_00014844[ch].unk28 = 0;
			D_00014844[ch].unk2C = 0;
		} else {
			D_000145E4[ch].pos = 0;
			D_000145E4[ch].unk30 = 0;
			D_000145E4[ch].unk34 = 0;
			D_000145E4[ch].unk28 = 0;
			D_000145E4[ch].unk2C = 0;
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
	return sceAudioSetChannelDataLen(D_00014AB8[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_00014AB8[ch], left, right);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_00014AB8[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_00014AB8[ch], left, right, buf);
}

int sceWaveStart(int prio)
{
	if (D_0001375C != 1)
		return 0x80440003;
	if ((unsigned int)(prio - 8) >= 0x70)
		return 0x80440012;
	return func_0000592C(prio);
}

int sceKernelDeleteThread(int thid);
int sceWaveEnd(void)
{
	int i;

	if (D_0001375C != 3)
		return 0x80440004;
	for (i = 0; i < 8; i++)
		sceWaveStop(i);
	D_00013760 = 1;
	sceKernelWaitThreadEnd(D_00014AA4.thid, NULL);
	sceKernelDeleteThread(D_00014AA4.thid);
	D_00013760 = 0;
	D_0001375C = 1;
	return 0;
}

int sceWaveExit(void)
{
	if (D_0001375C != 1)
		return 0x80440002;
	sceAudioChRelease(D_00014AA4.ch);
	sceAudioChRelease(D_00014AB8[0]);
	sceAudioChRelease(D_00014AB8[1]);
	sceAudioChRelease(D_00014AB8[2]);
	D_00014AB0 = NULL;
	D_00014AB4 = NULL;
	D_0001375C = 0;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_000145E4[ch].flags = (D_000145E4[ch].flags & ~0xff) | mode;
	return 0;
}

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_000145E4[ch].stat != 0) {
		D_00014844[ch].stat = 0;
		D_000145E4[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_000145E4[ch].stat == 0)
		D_000145E4[ch].stat = 1;
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
	return sceAudioChangeChannelConfig(D_00014AB8[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLength(D_00014AB8[ch]);
}

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/libwave", D_0001290C);
static int func_0000592C(int prio)
{
	D_00013760 = 0;
	D_00014AA4.thid = sceKernelCreateThread("SceWaveMain", func_000059D0, prio, 0x1000, 0, NULL);
	if (D_00014AA4.thid < 0)
		return 0x80440003;
	D_00014AA4.prio = prio;
	if (sceKernelStartThread(D_00014AA4.thid, sizeof(SceWaveMain), &D_00014AA4) != 0)
		return 0x80440003;
	sceKernelDelayThread(10000);
	D_0001375C = 3;
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/libwave", func_000059D0);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/libwave", func_00005AEC);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/libwave", func_00005CD4);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/libwave", func_00005E18);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/libwave", func_000060C4);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/libwave", func_00006634);

