/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK _memFree(int, M2C_UNK *, M2C_UNK);          /* extern */
extern unsigned char D_001025E8;
extern int l_patAssortDB;


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001025CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001025E8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", databaseFameRefresh);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", databaseAssortNameRefresh);

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

#ifndef NULL
#define NULL ((void *)0)
#endif

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
