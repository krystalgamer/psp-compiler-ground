/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int HST_getHeadHistoryNode();                       /* extern */
M2C_UNK handleMouseEvent(int);                      /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", sendJSUnloadEvent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", abortResourceLoading);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", setPageLoadedState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL1);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL5);

#ifndef NULL
#define NULL ((void *)0)
#endif

void proc_msg_PL6(int arg0) {
    if (HST_getHeadHistoryNode() != 0) {
        handleMouseEvent(arg0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL7);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL8);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL11);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL15);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL13);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL16);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL17);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", getInputDataFromMsg);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL18);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_PL19);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", proc_msg_TM);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_msgBranch_ps", D_001338FC);
