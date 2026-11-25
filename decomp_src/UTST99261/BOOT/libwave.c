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

extern int D_002E6584;
extern int D_0008BF30;
extern char D_002E658C[];
extern char D_002E65FC[];
extern SceWaveVoice D_002E740C[8];
extern SceWaveVoice D_002E766C[8];
extern SceWaveMain D_002E78CC;
extern void *D_002E78D8;
extern void *D_002E78DC;
extern int D_002E78E0[3];

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
static int func_000FC99C(unsigned int args, void *argp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", sceWaveInit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", sceWaveSetVoice);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", sceWaveGetVolume);

int sceWaveGetRestByte(unsigned int ch, int *rest)
{
	if (ch >= 8)
		return 0x80440005;
	if (rest == NULL)
		return 0x8044000C;
	if (D_002E740C[ch].stat == 0)
		*rest = 0;
	else if (!(D_002E740C[ch].flags & 0x400))
		*rest = D_002E740C[ch].size - D_002E740C[ch].pos;
	else
		*rest = 0;
	return 0;
}

int sceWaveGetStat(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	return D_002E740C[ch].stat;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", sceWavePlay);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", sceWavePlayEx);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", D_00145770);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", sceWaveStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", sceWaveEnd);

int sceWaveExit(void)
{
	if (D_002E6584 != 1)
		return 0x80440002;
	sceAudioChRelease(D_002E78CC.ch);
	sceAudioChRelease(D_002E78E0[0]);
	sceAudioChRelease(D_002E78E0[1]);
	sceAudioChRelease(D_002E78E0[2]);
	D_002E78D8 = NULL;
	D_002E78DC = NULL;
	D_002E6584 = 0;
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
	D_002E740C[ch].vol_l = (int)(left << 12) / 127;
	D_002E740C[ch].vol_r = (int)(right << 12) / 127;
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
	D_002E740C[ch].vol_l = left;
	D_002E740C[ch].vol_r = right;
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
	*left = D_002E740C[ch].vol_l;
	*right = D_002E740C[ch].vol_r;
	return 0;
}

int sceWaveSetLoopMode(unsigned int ch, int mode)
{
	if (ch >= 8)
		return 0x80440005;
	if ((unsigned int)(mode - 1) >= 2)
		return 0x80440008;
	D_002E740C[ch].flags = (D_002E740C[ch].flags & ~0xff) | mode;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", sceWaveStop);

int sceWavePause(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_002E740C[ch].stat != 0) {
		D_002E766C[ch].stat = 0;
		D_002E740C[ch].flags |= 0x140000;
	}
	return 0;
}

int sceWaveReplay(unsigned int ch)
{
	if (ch >= 8)
		return 0x80440005;
	if (D_002E740C[ch].stat == 0)
		D_002E740C[ch].stat = 1;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", sceWaveAllStop);

int sceWaveAudioSetSample(unsigned int ch, int samplecount)
{
	if (ch >= 4)
		return 0x80440010;
	if ((unsigned int)(samplecount - 64) > 0xff80)
		return 0x80440011;
	if (samplecount & 0x3f)
		return 0x80440011;
	return sceAudioSetChannelDataLen(D_002E78E0[ch], samplecount);
}

int sceWaveAudioSetVolume(unsigned int ch, unsigned int left, unsigned int right)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioChangeChannelVolume(D_002E78E0[ch], left, right);
}

int sceWaveAudioSetFormat(unsigned int ch, int format)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioChangeChannelConfig(D_002E78E0[ch], format);
}

int sceWaveAudioGetRestSample(unsigned int ch)
{
	if (ch >= 4)
		return 0x80440010;
	return sceAudioGetChannelRestLen(D_002E78E0[ch]);
}

int sceWaveAudioWrite(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPanned(D_002E78E0[ch], left, right, buf);
}

int sceWaveAudioWriteBlocking(unsigned int ch, unsigned int left, unsigned int right, void *buf)
{
	if (ch >= 4)
		return 0x80440010;
	if (left > 0x8000)
		return 0x8044000A;
	if (right > 0x8000)
		return 0x8044000A;
	return sceAudioOutputPannedBlocking(D_002E78E0[ch], left, right, buf);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", func_000FC99C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", func_000FCA78);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", func_000FCC30);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", func_000FCD74);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", func_000FD010);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", func_000FD528);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __fixunsdfsi);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __udivdi3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __extendsfdf2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", _fpadd_parts);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __adddf3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __subdf3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __muldf3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __divdf3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __eqdf2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __nedf2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __gtdf2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __gedf2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __ltdf2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __ledf2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __floatsidf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __fixdfsi);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __negdf2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __make_dp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __truncdfsf2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __unpack_f);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __make_fp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __pack_d);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __unpack_d);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __fpcmp_parts_d);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __pack_f);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", D_00145788);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", D_0014578C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", D_00145790);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", D_00145794);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", D_00145798);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", D_0014579C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __thenan_df);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/libwave", __clz_tab);
