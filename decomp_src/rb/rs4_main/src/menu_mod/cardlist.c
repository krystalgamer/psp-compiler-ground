/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
int cardlistCpyTtr2Int32();                         /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetCardID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistCpyTtr2Ucs4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistCpyTtr2Ascii);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00101F4C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistCpyTtr2Float32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistCpyTtr2Int32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistCpyTtr2Bool);

#ifndef NULL
#define NULL ((void *)0)
#endif

int cardlistCpyTtr2Enum(void) {
    return cardlistCpyTtr2Int32() - 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00101F94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00101F9C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00101FB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00101FCC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00101FE4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102004);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102014);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102038);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102040);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistRefresh);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetMaxCardID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetCardNum);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistFindOne);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_001021A0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetOne);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetPtr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetOneByInstructID);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102244);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetOneBySaveID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetPtrBySaveID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistSetInstructID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetInstructID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetSaveID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetCardIDFromSaveID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetResultEfcTtrStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetRarityTtrStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetCardNameBySaveID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetCardName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", ShuffleRandAlloc);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102340);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetOfficialDeck);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetEnemyDeck);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetBonusCard);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102594);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102598);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_0010259C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_001025A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_001025A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_001025A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_001025AC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cccUcs4ToUtf8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cccTtrToUcs4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cccTtrToUtf8);
