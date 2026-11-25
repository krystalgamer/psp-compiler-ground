#include "common.h"
#include <stdio.h>
#include <thread.h>
#include <libwave.h>
#include "game.h"

int sceWaveSetVolume(int voice, int vol_l, int vol_r);
int bgm_play(int no);

extern int NextBgm;
extern int PlayFlag;
extern unsigned char *VagBuff;
extern int VoiceSize[128];
extern int VoiceMax;
extern int TestSoundNo;
extern unsigned char *VagAdd[128];
extern int iFadeOutFlag;
extern int VoiceCh;


INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EA74);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EA80);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EA8C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EA98);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EAA4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EAB0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", D_0002EABC);

void vag_read(void);

int sound_init(void)
{
	int ret;
	int i;

	ret = sceWaveInit();
	if (ret != 0) {
		printf("sceWaveInit error:%d\n", ret);
		return -1;
	}
	iFadeOutFlag = 0;
	for (i = 0; i < 8; i++)
		sceWaveSetVolume(i, 127, 127);
	sceWaveAudioSetVolume(0, 0x7fff, 0x7fff);
	sceWaveAudioSetVolume(1, 0x7fff, 0x7fff);
	sceWaveAudioSetVolume(2, 0x7fff, 0x7fff);
	VoiceMax = 0;
	TestSoundNo = 0;
	VoiceCh = 0;
	vag_read();
	printf("wave int\n");
	if (sceWaveStart(18) != 0) {
		printf("sceWaveStart error\n");
		return -1;
	}
	return 0;
}

void vag_read(void)
{
	int size = 0x64000;
	int i;
	int sz;

	if (load_file("wave/vag.pak", (void **)&VagBuff, &size) == 0) {
		printf("vag.pak read error!\n");
		do
			sceKernelDelayThreadCB(200000);
		while (load_file("wave/vag.pak", (void **)&VagBuff, &size) == 0);
	}
	VoiceMax = VagBuff[0];
	VagAdd[0] = VagBuff + VoiceMax * 4 + 0x34;
	for (i = 0; i < VoiceMax; i++) {
		VoiceSize[i] = ((VagBuff[i * 4 + 7] * 256 + VagBuff[i * 4 + 6]) * 256 + VagBuff[i * 4 + 5]) * 256 + VagBuff[i * 4 + 4];
		VagAdd[i + 1] = VagAdd[i] + VoiceSize[i];
	}
	printf("VOICE MAX = %d\n", VoiceMax);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", bgm_stop);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", bgm_play);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", se_play);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/sound", snd_test);

void next_bgm(void) {
    if ((PlayFlag == 0) && (NextBgm >= 0)) {
        printf("NEXT PLAY = %d\n", NextBgm);
        bgm_play(NextBgm);
        NextBgm = -1;
    }
}
