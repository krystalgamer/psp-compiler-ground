/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK cardlistCpyTtr2Ucs4(int, int, int, M2C_UNK); /* extern */
int resGetDatLocal(M2C_UNK, M2C_UNK);               /* extern */
extern int l_nAssortNum;

M2C_UNK _memFree(int, M2C_UNK *, M2C_UNK);          /* extern */
extern unsigned char D_001025E8;
extern int l_patAssortDB;
void *memset(void *s, int c, unsigned int n);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001025CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001025E8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", databaseFameRefresh);

int databaseAssortNameRefresh(void) {
    int temp_s0;
    int temp_s1;
    int var_s2;

    var_s2 = 0;
    if (l_nAssortNum > 0) {
        do {
            temp_s0 = var_s2 * 0xC0;
            memset(temp_s0 + l_patAssortDB + 0x40, 0, 0x20U);
            temp_s1 = var_s2 + 1;
            cardlistCpyTtr2Ucs4(l_patAssortDB + temp_s0 + 0x40, resGetDatLocal(1, 0x4D), temp_s1, 0x20);
            var_s2 = temp_s1;
        } while (temp_s1 < l_nAssortNum);
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102638);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", databaseInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001026FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102704);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102718);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102728);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102730);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_0010273C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102740);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102744);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102748);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", databaseRefresh);

int databaseTerm(void) {
    if (l_patAssortDB != 0) {
        _memFree(l_patAssortDB, &D_001025E8, 0xA2);
    }
    l_patAssortDB = 0;
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", databaseChkRankingBattle);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", databaseCalcRanking);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", databaseChkAssort);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001027E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001027E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001027E8);
