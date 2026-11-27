#include "common.h"

/* declarations recovered from DWARF */
typedef char SceChar8;
typedef unsigned char SceUChar8;
typedef int SceInt32;
struct _anon1;
struct _anon1 { /* size 0xc */
    SceInt32 atracId;
    SceInt32 fd;
    SceInt32 outputChannel;
};
typedef struct _anon1 ScePlayArg;
typedef int SceSSize;
typedef unsigned int SceSize;
typedef void *ScePVoid;
typedef unsigned int SceUInt32;

extern int iFadeFlag;
extern int finishflag;

SceInt32 init_atrac3plus(SceChar8 *filename, SceUChar8 *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 ioutputChannel, ScePlayArg *pPlayArg);
SceInt32 play_atrac3plus(SceSize args, ScePVoid argp);
static void release_at3playArgID(ScePlayArg *pPlayArg);
static void at3plus_addData(SceInt32 atracId, SceInt32 fd);
void at3plus_setfade(int fade);
void at3plus_finish(void);


INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/at3plus", init_atrac3plus);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/at3plus", play_atrac3plus);

int sceIoClose(int fd);
int printf(const char *fmt, ...);
static void release_at3playArgID(ScePlayArg *pPlayArg)
{
	SceInt32 status;

	if (pPlayArg->atracId >= 0) {
		status = sceAtracReleaseAtracID(pPlayArg->atracId);
		if (status < 0)
			printf("status = 0x%x (in sceAtracReleaseAtracID)\n", status);
	}
	if (pPlayArg->fd >= 0) {
		status = sceIoClose(pPlayArg->fd);
		if (status < 0)
			printf("status = 0x%x (in sceIoClose)\n", status);
	}
}

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/at3plus", at3plus_addData);

void at3plus_setfade(int fade)
{
	iFadeFlag = fade;
}

void at3plus_finish(void)
{
	finishflag = 1;
}
