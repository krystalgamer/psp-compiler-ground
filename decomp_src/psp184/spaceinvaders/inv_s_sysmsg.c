/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK startMsgDialog(int);                        /* extern */
extern unsigned char msgdialog_param_28E1FC;


#ifndef NULL
#define NULL ((void *)0)
#endif
void sceKernelExitGame(void);
int ExitFunction_16448(void) {
    sceKernelExitGame();
    return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_sysmsg", utility_update_msgdialog_16468);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_sysmsg", sub_thread_164DC);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_sysmsg", OnPush_MsgDialogNumber);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_sysmsg", sysmsg_errornum);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_sysmsg", startMsgDialog);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void MsgDialogNormal(int arg0) {
    memset(&msgdialog_param_28E1FC, 0, 0x244U);
    M2C_FIELD(&msgdialog_param_28E1FC, int *, 0x23C) = 1;
    startMsgDialog(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void MsgDialogNormal_YesNo_Yes(int arg0) {
    memset(&msgdialog_param_28E1FC, 0, 0x244U);
    M2C_FIELD(&msgdialog_param_28E1FC, int *, 0x23C) = 0x11;
    startMsgDialog(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void MsgDialogNormal_YesNo_No(int arg0) {
    memset(&msgdialog_param_28E1FC, 0, 0x244U);
    M2C_FIELD(&msgdialog_param_28E1FC, int *, 0x23C) = 0x111;
    startMsgDialog(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void MsgDialogError(int arg0) {
    memset(&msgdialog_param_28E1FC, 0, 0x244U);
    M2C_FIELD(&msgdialog_param_28E1FC, int *, 0x23C) = 0;
    startMsgDialog(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void MsgDialogError_YesNo_Yes(int arg0) {
    memset(&msgdialog_param_28E1FC, 0, 0x244U);
    M2C_FIELD(&msgdialog_param_28E1FC, int *, 0x23C) = 0x10;
    startMsgDialog(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void MsgDialogError_YesNo_No(int arg0) {
    memset(&msgdialog_param_28E1FC, 0, 0x244U);
    M2C_FIELD(&msgdialog_param_28E1FC, int *, 0x23C) = 0x110;
    startMsgDialog(arg0);
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_sysmsg", D_0007B804);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_sysmsg", sysmsg_string);
