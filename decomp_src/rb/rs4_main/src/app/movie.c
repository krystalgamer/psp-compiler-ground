/* cflags: -Os */
#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movPutCB);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movDecodeVideo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movDecodeAudio);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movAudio);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDD64);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partAsm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partRelease);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDD7C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDD8C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDDB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDDBC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDDC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDDCC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partSetDrawMat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partAnimate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partDraw);
