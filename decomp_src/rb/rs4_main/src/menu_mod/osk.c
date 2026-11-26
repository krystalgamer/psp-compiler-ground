/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK gameCtrlLock();                             /* extern */
M2C_UNK gameDisSoftReset();                         /* extern */
M2C_UNK gameCtrlUnlock();                           /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", setOskUtilityPraram);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103130);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", textUcs4toUcs2Alloc);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103158);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103168);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", textUcs2toUcs4Free);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", setOskUtilityParam);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031B8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", getOskUtilityTextResult);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103228);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103258);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", dumpOskUtilityTextResult);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", utility_update_osk);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", OnPush_OSK);

#ifndef NULL
#define NULL ((void *)0)
#endif

void Lock(int arg0) {
    int *temp_v0;

    gameDisSoftReset();
    gameCtrlLock();
    temp_v0 = gameGetCntx();
    M2C_FIELD(temp_v0, int *, 4) = (int) (M2C_FIELD(temp_v0, int *, 4) | (arg0 != 0));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void Unlock(int arg0) {
    int *temp_v0;

    temp_v0 = gameGetCntx();
    M2C_FIELD(temp_v0, int *, 8) = (int) (M2C_FIELD(temp_v0, int *, 8) | (arg0 != 0));
    gameCtrlUnlock();
    gameEnSoftReset();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", OskStart);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", OskEnd);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", OskState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", Sub_ProfileEdit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001033C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001033DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001033F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103404);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103408);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103420);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103438);
