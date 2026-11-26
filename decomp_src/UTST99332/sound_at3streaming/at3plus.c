#include "common.h"

struct _anon1 {
	int atracId;
	int fd;
	volatile int endflag;
	unsigned int pos;
};
extern struct _anon1 gPlayArg;

int sceIoWaitAsync(int fd, long long *res);
int sceIoClose(int fd);
int sceAtracReleaseAtracID(int atracID);
int printf(const char *fmt, ...);

void release_arg(void)
{
	int status;

	if (gPlayArg.fd >= 0) {
		long long dummy;

		sceIoWaitAsync(gPlayArg.fd, &dummy);

		status = sceIoClose(gPlayArg.fd);
		if (status < 0) {
			printf("error in sceIoClose (error code = 0x%X)\n", status);
		}
	}

	if (gPlayArg.atracId >= 0) {
		status = sceAtracReleaseAtracID(gPlayArg.atracId);
		if (status < 0) {
			printf("error in release ATRAC ID (error code = 0x%X)\n", status);
		}
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/at3plus", play_atrac3plus);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/at3plus", at3_bgm_play);


int at3_bgm_play_end(int fadeout_mode)
{
	if (fadeout_mode) {
		gPlayArg.endflag = 0x100;
	} else {
		gPlayArg.endflag = -1;
	}

	return 0;
}
