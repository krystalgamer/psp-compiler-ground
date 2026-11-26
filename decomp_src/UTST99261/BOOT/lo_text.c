/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
M2C_UNK OS_timer_clear(int);                        /* extern */
M2C_UNK OS_timer_stop(int);                         /* extern */
extern void *D_00584CDC;
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
int OS_timer_set(int, int, int, int, int, int, int); /* extern */
M2C_UNK OS_timer_start(int);                        /* extern */
void *HST_searchSessionIDHistoryNode(int);          /* extern */
int checkBoxValidity(int);                          /* extern */
void *Node_getBox(int);                             /* extern */
M2C_UNK actSetFocusByBox(int, void *, M2C_UNK);     /* extern */
int getBodyBox(void *);                             /* extern */
int getInputType(int);                              /* extern */
M2C_UNK selectText(void *);                         /* extern */

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

#ifndef NULL
#define NULL ((void *)0)
#endif

void lo_freeTimer(void) {
    void *temp_s0;
    void *temp_s2;
    void *var_s1;

    temp_s2 = D_00584CDC;
    var_s1 = M2C_FIELD(M2C_FIELD(temp_s2, void **, 4), void **, 8);
    if (var_s1 != NULL) {
        do {
            temp_s0 = M2C_FIELD(var_s1, void **, 8);
            OS_timer_stop(M2C_FIELD(var_s1, int *, 4));
            OS_timer_clear(M2C_FIELD(var_s1, int *, 4));
            MEM_free(0, var_s1);
            var_s1 = temp_s0;
        } while (temp_s0 != NULL);
    }
    MEM_free(0, M2C_FIELD(temp_s2, void **, 4));
    MEM_free(0, temp_s2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int lo_setTimer(int arg0, int arg1, int arg2, int arg3) {
    int temp_v0;
    void *temp_s0;
    void *temp_v0_2;
    void *var_s0;

    temp_s0 = D_00584CDC;
    temp_v0 = OS_timer_set(M2C_FIELD(temp_s0, int *, 8), arg0, arg1, arg2, arg3, arg1, arg2);
    OS_timer_start(temp_v0);
    var_s0 = M2C_FIELD(temp_s0, void **, 4);
    if (M2C_FIELD(var_s0, int *, 8) != 0) {
        do {
            var_s0 = M2C_FIELD(var_s0, void **, 8);
        } while (M2C_FIELD(var_s0, int *, 8) != 0);
    }
    temp_v0_2 = MEM_malloc(0, 0xC);
    M2C_FIELD(temp_v0_2, int *, 0) = temp_v0;
    M2C_FIELD(temp_v0_2, int *, 4) = temp_v0;
    M2C_FIELD(temp_v0_2, int *, 8) = 0;
    M2C_FIELD(var_s0, void **, 8) = temp_v0_2;
    return temp_v0;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif

void proc_msg_JL6(void *arg0) {
    int temp_a0;
    void *temp_v0;

    temp_v0 = HST_searchSessionIDHistoryNode(M2C_FIELD(arg0, int *, 4));
    if (temp_v0 != NULL) {
        temp_a0 = M2C_FIELD(temp_v0, int *, 0x6C);
        if ((temp_a0 != 0) && (checkBoxValidity(temp_a0) != 0)) {
            putLLIST(&REQUEST_LLIST, make_msg_LP16(arg0));
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL7);

#ifndef NULL
#define NULL ((void *)0)
#endif

void proc_msg_JL8(void *arg0) {
    M2C_UNK var_s2;
    int temp_a0;
    void *temp_v0;
    void *var_s0;

    var_s2 = 0;
    temp_v0 = Node_getBox(M2C_FIELD(arg0, int *, 0x1C));
    var_s0 = temp_v0;
    if (getInputType(M2C_FIELD(temp_v0, int *, 0x28)) == 3) {
        var_s0 = M2C_FIELD(var_s0, void **, 0xC);
    }
    temp_a0 = getBodyBox(var_s0);
    if (M2C_FIELD(arg0, int *, 0x10) == 0) {
        var_s2 = 1;
    }
    actSetFocusByBox(temp_a0, var_s0, var_s2);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL9);

#ifndef NULL
#define NULL ((void *)0)
#endif

void proc_msg_JL10(void *arg0) {
    void *temp_v0;

    temp_v0 = Node_getBox(M2C_FIELD(arg0, int *, 0x1C));
    if ((M2C_FIELD(temp_v0, short *, 0x38) == 0xD) && (M2C_FIELD(temp_v0, short *, 0x3E) == 0) && (getInputType(M2C_FIELD(temp_v0, int *, 0x28)) != 3)) {
        selectText(temp_v0);
        actSetFocusByBox(getBodyBox(temp_v0), temp_v0, 1);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL11);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL12);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL13);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL14);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_text", proc_msg_JL15);
