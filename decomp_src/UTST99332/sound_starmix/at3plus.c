#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned char SceUChar8;
typedef int SceInt32;
struct _anon1;
typedef int SceUID;
struct _anon1 { /* size 0x14 */
    SceInt32 atracID;
    SceUID fd;
    SceUID finishflag;
    SceInt32 outputChannel;
    SceInt32 iEndSample;
};
typedef struct _anon1 SceAtracArg;
typedef int SceSSize;
typedef unsigned int SceSize;
typedef void *ScePVoid;
typedef unsigned int SceUInt32;



SceInt32 init_atrac3plus(SceUChar8 *filename, SceUChar8 *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 iOutputChannel, SceAtracArg *pPlayArg);
SceInt32 play_atrac3plus(SceSize args, ScePVoid argp);
static void at3plus_addData(SceInt32 atracId, SceInt32 fd);
static void at3plus_DisplayDecodePosition(SceAtracArg *pPlayArg);

/* SDK functions (tools/sdk_protos.h) */
int sceIoClose(int fd);
int printf(const char *fmt, ...);


INCLUDE_ASM("tmp/asm/UTST99332/sound_starmix/nonmatchings/at3plus", init_atrac3plus);

INCLUDE_ASM("tmp/asm/UTST99332/sound_starmix/nonmatchings/at3plus", play_atrac3plus);

void finish_atrac3plus(SceAtracArg *pPlayArg) {
    int temp_v0;

    temp_v0 = sceKernelSetEventFlag(pPlayArg->finishflag, 1);
    if (temp_v0 >= 0) {

    } else {
        printf("status = 0x%x(in sceKernelSetEventFlag)\n", temp_v0);
    }
}

void release_arg(SceAtracArg *pPlayArg) {
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    temp_v0 = pPlayArg->atracID;
    if ((temp_v0 < 0) || (temp_v0_2 = sceAtracReleaseAtracID(temp_v0), (temp_v0_2 >= 0))) {

    } else {
        printf("status = 0x%x(in sceAtracReleaseID)\n", temp_v0_2);
    }
    if ((pPlayArg->fd < 0) || (temp_v0_3 = sceIoClose(pPlayArg->fd), (temp_v0_3 >= 0))) {

    } else {
        printf("status = 0x%x(in sceIoClose)\n", temp_v0_3);
    }
    if (pPlayArg->finishflag >= 0) {
        sceKernelDeleteEventFlag(pPlayArg->finishflag);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_starmix/nonmatchings/at3plus", at3plus_addData);

extern char decode_position[]; /* static char decode_position[] in at3plus_DisplayDecodePosition (.data is asm) */
int sprintf(char *buf, const char *fmt, ...);
int sceAtracGetNextDecodePosition(SceInt32 atracID, SceUInt32 *puiSamplePosition);

static void at3plus_DisplayDecodePosition(SceAtracArg *pPlayArg)
{
	SceUInt32 uiSamplePosition;
	SceInt32 status;

	status = sceAtracGetNextDecodePosition(pPlayArg->atracID, &uiSamplePosition);

	if (status < 0) {
		printf("sceAtracGetNextDecodePosition = 0x%x\n", status);
	}

	sprintf(decode_position, "Decoding Position  %10d/%10d\n", uiSamplePosition, pPlayArg->iEndSample);
}
