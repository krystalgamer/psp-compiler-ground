/* cflags: -Os */
#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", profileDefaultNameSet);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", D_000FE318);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", D_000FE334);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", D_000FE348);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", profileDefaultParamSet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", profileGetRankingTtrStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", profileGetRankingTtrStr2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", profileGetPerOfWins);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", profileGetPerOfSuccess);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", profileGetPerOfJanken);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", randInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", randDumpSeed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", randDumpSeedAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", randSetSeed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", randGetSeed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", randU);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", randS);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", randSave);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", randLoad);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", randGetTick);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", randSetSeedByMacAddr);
