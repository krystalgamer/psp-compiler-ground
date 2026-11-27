/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
extern unsigned char D_000FF2BC;
extern unsigned char D_000FF2E0;
extern unsigned char D_000FF2FC;


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF2BC);

#ifndef NULL
#define NULL ((void *)0)
#endif

int EffectGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FF2E0, &D_000FF2BC, 0x22, "EffectGetNum", &D_000FF2FC);
    }
    return M2C_FIELD(arg0, int *, 0x8C);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF2E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF2FC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", EffectSetTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF314);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF33C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", EffectGetTask);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", EffectTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF380);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF384);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF388);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF38C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF394);
