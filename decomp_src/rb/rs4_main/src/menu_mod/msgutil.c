/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sceUtilityMsgDialogInitStart(M2C_UNK *);    /* extern */
extern unsigned char msgdialog_param;
extern int sample_type_11A6BC;

void consPrintf(const char *, ...);
M2C_UNK gameCtrlUnlock();void *memset(void *s, int c, unsigned int n);

void gameDisSoftReset(void);
void gameCtrlLock();
void gameEnSoftReset(void);
int UtilityLink();
int utility_update_msgdialog();
void OnPush_MsgDialogNumber(int arg0);

void drawPrintf(const char *, ...);
int sceUtilityMsgDialogGetStatus();

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/msgutil", utility_update_msgdialog);

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

int MsgStart(int x)
{
	consPrintf("MsgStart : 0x%x\n", x);
	gameDisSoftReset();
	gameCtrlLock();
	if (UtilityLink(utility_update_msgdialog)) {
		OnPush_MsgDialogNumber(x);
		return 1;
	}
	gameEnSoftReset();
	return 0;
}

void MsgEnd(void) {
    UtilityUnlink();
    gameCtrlUnlock();
    gameEnSoftReset();
    consPrintf("MsgEnd\n");
}

int MsgState(void) {
    drawPrintf("%s : state=%d, type=%d\n", "MsgState", sceUtilityMsgDialogGetStatus(), sample_type_11A6BC);
    return sample_type_11A6BC == 4;
}
