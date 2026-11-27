/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
extern unsigned char D_000FF3AC;
extern unsigned char D_000FF3CC;
extern unsigned char D_000FF3E8;


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF3AC);

#ifndef NULL
#define NULL ((void *)0)
#endif

int EventGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FF3CC, &D_000FF3AC, 0xF, "EventGetNum", &D_000FF3E8);
    }
    return M2C_FIELD(arg0, int *, 0x54);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF3CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF3E8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", EventSetTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF400);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF428);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", EventGetTask);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", EventTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF46C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF470);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF474);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF490);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF494);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF498);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF49C);
