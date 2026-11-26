/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int Node_getBox();                                  /* extern */
M2C_UNK htmlTagBranchAfter(int);                    /* extern */
int Util_HTMLDocument_getBody(int);                 /* extern */
M2C_UNK applyCSSExtStyleSheetToBox(int, int);       /* extern */
M2C_UNK applyCSSInlinePropertyToBox(int, int);      /* extern */
M2C_UNK attr_BACKGROUND(int, int);                  /* extern */
M2C_UNK attr_BGCOLOR(int, int);                     /* extern */
M2C_UNK attr_LINK(int, int);                        /* extern */
M2C_UNK attr_MARGINHEIGHT(int, int);                /* extern */
M2C_UNK attr_MARGINWIDTH(int, int);                 /* extern */
M2C_UNK attr_TEXT(int, int);                        /* extern */
M2C_UNK attr_VLINK(int, int);                       /* extern */
M2C_UNK nodeTreeLoop(int, int);                     /* extern */
int getTargetBodyBox();                             /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_tree", createBodyBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_tree", nodeProc);

#ifndef NULL
#define NULL ((void *)0)
#endif

void nodeProcAfter(int arg0) {
    if (arg0 != 0) {
        if (Node_getBox() != 0) {
            htmlTagBranchAfter(arg0);
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_tree", nodeTreeLoop);

#ifndef NULL
#define NULL ((void *)0)
#endif

void makeBodyBoxTree(void *arg0, int arg1, int arg2) {
    int temp_s2;
    int temp_v0;

    temp_s2 = M2C_FIELD(arg0, int *, 0x68);
    temp_v0 = Util_HTMLDocument_getBody(temp_s2);
    if (temp_v0 != 0) {
        attr_MARGINWIDTH(temp_v0, arg1);
        attr_MARGINHEIGHT(temp_v0, arg1);
        attr_BGCOLOR(temp_v0, arg1);
        attr_BACKGROUND(temp_v0, arg1);
        attr_TEXT(temp_v0, arg1);
        attr_LINK(temp_v0, arg1);
        attr_VLINK(temp_v0, arg1);
        applyCSSExtStyleSheetToBox(temp_v0, arg1);
        applyCSSInlinePropertyToBox(temp_v0, arg1);
    }
    nodeTreeLoop(temp_s2, arg2);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_tree", getTargetBodyBox);

#ifndef NULL
#define NULL ((void *)0)
#endif

void makeBoxTree(void *arg0, int arg1) {
    int temp_v0;

    temp_v0 = getTargetBodyBox();
    if (temp_v0 != 0) {
        if (M2C_FIELD(arg0, int *, 0x6C) == 0) {
            M2C_FIELD(arg0, int *, 0x6C) = temp_v0;
        }
        makeBodyBoxTree(arg0, temp_v0, arg1);
    }
}
