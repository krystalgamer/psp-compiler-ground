/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sceUtilityMsgDialogInitStart(M2C_UNK *);    /* extern */
extern unsigned char msgdialog_param;
extern int sample_type_11A6BC;

int consPrintf();
M2C_UNK gameCtrlUnlock();                           /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/msgutil", utility_update_msgdialog);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void OnPush_MsgDialogNumber(int arg0) {
    sample_type_11A6BC = 4;
    memset(&msgdialog_param, 0, 0x244U);
    M2C_FIELD(&msgdialog_param, int *, 0) = 0x244;
    M2C_FIELD(&msgdialog_param, int *, 4) = UtilGetMessageLang();
    M2C_FIELD(&msgdialog_param, int *, 8) = UtilGetAssign();
    M2C_FIELD(&msgdialog_param, int *, 0xC) = 0x15;
    M2C_FIELD(&msgdialog_param, int *, 0x10) = 0x17;
    M2C_FIELD(&msgdialog_param, int *, 0x14) = 0x16;
    M2C_FIELD(&msgdialog_param, int *, 0x38) = arg0;
    M2C_FIELD(&msgdialog_param, int *, 0x18) = 0x14;
    M2C_FIELD(&msgdialog_param, int *, 0x34) = 0;
    sceUtilityMsgDialogInitStart(&msgdialog_param);
}

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
