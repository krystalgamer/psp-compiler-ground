/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_00101B98;
extern unsigned char D_00101BB8;
extern unsigned char D_00101BD4;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101B98);

int SoundGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_00101BB8, &D_00101B98, 0x10, "SoundGetNum", &D_00101BD4);
    }
    return M2C_FIELD(arg0, int *, 0x88);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101BB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101BD4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", SoundSetTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101BEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101C14);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", SoundGetTask);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", SoundTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101C58);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101C5C);
