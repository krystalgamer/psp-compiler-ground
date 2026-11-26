#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memLock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memUnlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memGetCntxSize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memGetAlignSize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memLog);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memAlloc);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FADB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FADB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FADC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FADE0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FAE0C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memRealloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memReallocMBL);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memAllocZero);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memAllocMBL);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memAllocZeroMBL);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memDiag);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memDiag);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memSnap);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB0D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB0F0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memClean);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memBreak);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memList);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB180);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB19C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB1C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB1D0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvHeadAlive);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB210);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvNextAlive);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvCall);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvKill);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvFree);
