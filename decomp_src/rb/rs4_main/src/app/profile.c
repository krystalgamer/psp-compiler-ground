/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
unsigned int cccTtrToUcs4(void *, int, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
int resGetDatLocal(M2C_UNK, M2C_UNK);               /* extern */
extern unsigned char D_000FE318;
extern unsigned char D_000FE334;
extern int l_uTick;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", profileDefaultNameSet);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", D_000FE318);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", D_000FE334);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", D_000FE348);

#ifndef NULL
#define NULL ((void *)0)
#endif

void profileDefaultParamSet(void *arg0) {
    M2C_FIELD(arg0, short *, 0x206) = 0x3E8;
    M2C_FIELD(arg0, int *, 0x208) = 0x3E8;
    M2C_FIELD(arg0, short *, 0x202) = 0;
    M2C_FIELD(arg0, int *, 0x20C) = 0;
    M2C_FIELD(arg0, int *, 0x210) = 0;
    M2C_FIELD(arg0, int *, 0x214) = 0;
    M2C_FIELD(arg0, int *, 0x218) = 0;
    M2C_FIELD(arg0, int *, 0x21C) = 0;
    M2C_FIELD(arg0, int *, 0x220) = 0;
    if (cccTtrToUcs4(arg0 + 0x80, resGetDatLocal(1, 0x53), "SINGLE_93", 0, 0) >= 0x20U) {
        consPrintf(&D_000FE318, &D_000FE334, 0x50, "profileDefaultParamSet", "Len < (Profile_TextByte/sizeof(ucs4))");
    }
    if (cccTtrToUcs4(arg0 + 0x100, resGetDatLocal(1, 0x53), "SINGLE_94", 0, 0) >= 0x20U) {
        consPrintf(&D_000FE318, &D_000FE334, 0x52, "profileDefaultParamSet", "Len < (Profile_TextByte/sizeof(ucs4))");
    }
    if (cccTtrToUcs4(arg0 + 0x180, resGetDatLocal(1, 0x53), "SINGLE_95", 0, 0) >= 0x20U) {
        consPrintf(&D_000FE318, &D_000FE334, 0x54, "profileDefaultParamSet", "Len < (Profile_TextByte/sizeof(ucs4))");
    }
    M2C_FIELD(arg0, short *, 0x200) = 1;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif

int randGetTick(void) {
    return l_uTick;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", randSetSeedByMacAddr);
