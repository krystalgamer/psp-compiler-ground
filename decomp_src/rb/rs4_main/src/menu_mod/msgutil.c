#include "common.h"
#include "m2c_macros.h"
M2C_UNK consPrintf(M2C_UNK *);                      /* extern */
M2C_UNK gameCtrlUnlock();                           /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/msgutil", utility_update_msgdialog);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/msgutil", OnPush_MsgDialogNumber);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/msgutil", MsgStart);

#ifndef NULL
#define NULL ((void *)0)
#endif

void MsgEnd(void) {
    UtilityUnlink();
    gameCtrlUnlock();
    gameEnSoftReset();
    consPrintf("MsgEnd\n");
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/msgutil", MsgState);
