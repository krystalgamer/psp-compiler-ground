#include "common.h"
#include "m2c_macros.h"
int make_msg_LP1();                                 /* extern */
M2C_UNK putLLIST(M2C_UNK *, int);                   /* extern */
extern unsigned char REQUEST_LLIST;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", divOverText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", divOverText_pre);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", createTextBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", divTextBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", divPreTextBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", integrateTextBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", lo_initTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", lo_freeTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", lo_setTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", lo_clearTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", initJSEnv);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", destroyJSEnv);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", initJSEvent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", sendJSEvent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", sendJSBubbleUpEvent);

#ifndef NULL
#define NULL ((void *)0)
#endif

void proc_msg_JL1(void) {
    putLLIST(&REQUEST_LLIST, make_msg_LP1());
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL5);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL6);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL7);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL8);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL9);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL10);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL11);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL12);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL13);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL14);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL15);
