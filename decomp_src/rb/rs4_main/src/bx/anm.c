/* lang: c++ */
/* cflags: -Os */
#include "common.h"
extern "C" {

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", D_00108E74);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxCleanup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmInitEx);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", D_00108E98);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", D_00108EA0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmInitAssign);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmExec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmSetFrame);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmGetFrame);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmSetLoop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmGetLoop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmSetPause);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmGetPause);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmSetSpeed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmGetSpeed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmGetEndFrame);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmSetEndFrame);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmTexReAssign);

} /* extern "C": m2c drafts with mangled names, kept as C linkage */
