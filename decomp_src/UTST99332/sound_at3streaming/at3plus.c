#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/at3plus", release_arg);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/at3plus", play_atrac3plus);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/at3plus", at3_bgm_play);

struct _anon1 {
	int atracId;
	int fd;
	volatile int endflag;
	unsigned int pos;
};
extern struct _anon1 gPlayArg;

int at3_bgm_play_end(int fadeout_mode)
{
	if (fadeout_mode) {
		gPlayArg.endflag = 0x100;
	} else {
		gPlayArg.endflag = -1;
	}

	return 0;
}
