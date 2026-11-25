#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned char SceUChar8;
typedef int SceInt32;
struct _anon1;
typedef int SceUID;
struct _anon1 { /* size 0x14 */
    SceInt32 atracID;
    SceUID fd;
    SceUID statusflag;
    SceInt32 outputChannel;
    SceInt32 iEndSample;
};
typedef struct _anon1 SceAtracArg;
typedef int SceSSize;
typedef unsigned int SceUInt32;
typedef unsigned int SceSize;
typedef void *ScePVoid;
struct _anon2;
struct _anon2 { /* size 0x20 */
    SceUChar8 *pucWritePositionFirstBuf;
    SceUInt32 uiWritableByteFirstBuf;
    SceUInt32 uiMinWriteByteFirstBuf;
    SceUInt32 uiReadPositionFirstBuf;
    SceUChar8 *pucWritePositionSecondBuf;
    SceUInt32 uiWritableByteSecondBuf;
    SceUInt32 uiMinWriteByteSecondBuf;
    SceUInt32 uiReadPositionSecondBuf;
};
typedef struct _anon2 SceBufferInfo;
typedef short int SceShort16;
typedef float SceFloat;



SceInt32 init_atrac3plus(SceUChar8 *filename, SceUChar8 *pucFirstBuf, SceInt32 iFirstBufferSize, SceUChar8 *pucSecondBuf, SceInt32 iSecondBufSize, SceInt32 iOutputChannel, SceAtracArg *pPlayArg);
SceInt32 play_atrac3plus(SceSize args, ScePVoid argp);
static void at3plus_addData(SceInt32 atracId, SceInt32 fd);
static void at3plus_DisplayDecodePosition(SceAtracArg *pPlayArg);
static void reset_position(SceAtracArg *pPlayArg);
static SceUInt32 getPlayMode(SceUID statusflag, SceUInt32 playMode);
static void fadeoutOperation(SceShort16 *pusValue, SceInt32 iFadeoutBorderSample, SceInt32 iMuteBorderSample);

/* SDK functions (tools/sdk_protos.h) */
int sceIoClose(int fd);
int printf(const char *fmt, ...);


INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", init_atrac3plus);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F6C0);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F6E0);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F70C);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F738);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F760);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F78C);

INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", play_atrac3plus);

extern signed char D_0001F7F4;

void finish_atrac3plus(SceAtracArg *pPlayArg) {
    int temp_v0;

    temp_v0 = sceKernelSetEventFlag(pPlayArg->statusflag, 2);
    if (temp_v0 >= 0) {

    } else {
        printf(&D_0001F7F4, temp_v0);
    }
}

extern signed char D_0001F7F4;

void restart_atrac3plus(SceAtracArg *pPlayArg) {
    int temp_v0;

    temp_v0 = sceKernelSetEventFlag(pPlayArg->statusflag, 1);
    if (temp_v0 >= 0) {

    } else {
        printf(&D_0001F7F4, temp_v0);
    }
}

INCLUDE_RODATA("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", D_0001F7F4);

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
    if (pPlayArg->statusflag >= 0) {
        sceKernelDeleteEventFlag(pPlayArg->statusflag);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", at3plus_addData);

INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", at3plus_DisplayDecodePosition);

INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", reset_position);

INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", getPlayMode);

INCLUDE_ASM("tmp/asm/UTST99332/sound_stringsound/nonmatchings/at3plus", fadeoutOperation);
