/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
int consPrintf();
extern unsigned char D_000FF7F4;
extern unsigned char D_000FF81C;
extern unsigned char D_000FF838;


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF7F4);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ProgramGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FF81C, &D_000FF7F4, 0x16, "ProgramGetNum", &D_000FF838);
    }
    return M2C_FIELD(arg0, int *, 0x94);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF81C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF838);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", ProgramSetTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF850);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF878);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", ProgramGetTask);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", ProgramTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF8BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF8C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF8C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF8CC);
