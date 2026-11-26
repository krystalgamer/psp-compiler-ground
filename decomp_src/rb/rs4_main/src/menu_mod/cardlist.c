/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK _memFree(int, M2C_UNK *, M2C_UNK);          /* extern */
extern unsigned char D_00101FCC;
extern int l_atCardList;
extern int l_nCardIDMax;
extern int l_nCardNum;
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *, unsigned int);      /* extern */
extern unsigned char D_00102244;
void *cardlistFindOne();                            /* extern */
extern unsigned char D_001021A0;

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

#ifndef NULL
#define NULL ((void *)0)
#endif

int cardlistTerm(void) {
    l_nCardIDMax = 0;
    l_nCardNum = 0;
    _memFree(l_atCardList, &D_00101FCC, 0x142);
    l_atCardList = 0;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int cardlistGetMaxCardID(void) {
    return l_nCardIDMax;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int cardlistGetCardNum(void) {
    return l_nCardNum;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistFindOne);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_001021A0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetOne);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetPtr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetOneByInstructID);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102244);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetOneBySaveID);

#ifndef NULL
#define NULL ((void *)0)
#endif

int cardlistGetPtrBySaveID(unsigned int arg0) {
    if (arg0 < (unsigned int) l_nCardNum) {
        return l_atCardList + (arg0 * 0xB60);
    }
    consPrintf(&D_00102244, "cardlistGetPtrBySaveID", arg0);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int cardlistSetInstructID(int arg0, int arg1) {
    int var_v1;
    void *temp_v0;

    temp_v0 = cardlistFindOne();
    var_v1 = 1;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0x22C) = arg1;
    } else {
        consPrintf(&D_001021A0, "cardlistSetInstructID", arg0);
        var_v1 = 0;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int cardlistGetInstructID(int arg0) {
    void *temp_v0;

    temp_v0 = cardlistFindOne();
    if (temp_v0 != NULL) {
        return M2C_FIELD(temp_v0, int *, 0x22C);
    }
    consPrintf(&D_001021A0, "cardlistGetInstructID", arg0);
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int cardlistGetSaveID(int arg0) {
    void *temp_v0;

    temp_v0 = cardlistFindOne();
    if (temp_v0 != NULL) {
        return M2C_FIELD(temp_v0, int *, 0x230);
    }
    consPrintf(&D_001021A0, "cardlistGetSaveID", arg0);
    return -1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetCardIDFromSaveID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetResultEfcTtrStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetRarityTtrStr);

#ifndef NULL
#define NULL ((void *)0)
#endif

int cardlistGetCardNameBySaveID(unsigned int arg0) {
    if (arg0 < (unsigned int) l_nCardNum) {
        return l_atCardList + (arg0 * 0xB60);
    }
    consPrintf(&D_00102244, "cardlistGetCardNameBySaveID", arg0);
    return 0;
}

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
