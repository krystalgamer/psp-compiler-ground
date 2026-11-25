#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int SceSize;
typedef void *ScePVoid;
typedef int SceInt32;
typedef long long int SceIores;
typedef unsigned int SceUInt32;
typedef int SceUID;
struct _anon1;
struct _anon1 { /* size 0x10 */
    SceInt32 atracId;
    SceInt32 fd;
    volatile int endflag;
    SceUInt32 pos;
};

extern char aucReadBuf[131074];
extern short int outputBuf[16384];
extern short int sasBuf[512];
extern struct _anon1 gPlayArg;

static SceInt32 play_atrac3plus(SceSize args, ScePVoid argp);
SceUID at3_bgm_play(const char *filename);
int at3_bgm_play_end(int fadeout_mode);

/* SDK functions (tools/sdk_protos.h) */
int sceIoClose(int fd);
int printf(const char *fmt, ...);


void release_arg(void) {
    int temp_v0;
    int temp_v0_2;

    if ((gPlayArg.fd < 0) || (temp_v0 = sceIoClose(gPlayArg.fd), (temp_v0 >= 0))) {

    } else {
        printf("error in sceIoClose (error code = 0x%X)\n", temp_v0);
    }
    if ((gPlayArg.atracId < 0) || (temp_v0_2 = sceAtracReleaseAtracID(gPlayArg.atracId), (temp_v0_2 >= 0))) {

    } else {
        printf("error in release ATRAC ID (error code = 0x%X)\n", temp_v0_2);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/soundthread", play_atrac3plus);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/soundthread", at3_bgm_play);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3mix/nonmatchings/soundthread", at3_bgm_play_end);
