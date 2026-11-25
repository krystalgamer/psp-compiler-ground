#include "common.h"

/* declarations recovered from DWARF */
typedef int SceInt32;
typedef int SceUID;
struct _anon1;
struct _anon1 { /* size 0x10 */
    SceInt32 atracID;
    SceUID finishflag;
    SceInt32 outputChannel;
    SceInt32 iEndSample;
};
typedef struct _anon1 SceAtracArg;

extern int bgm_at3;
extern int bgm_at3size;
extern SceUID thread_id01;
extern SceAtracArg atracArg;

int at3start(void);
int at3end(void);


void init_sound(void) {
    sceWaveInit();
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3main", at3start);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3main", D_0001E84C);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3main", D_0001E86C);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3main", D_0001E88C);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3main", at3end);
