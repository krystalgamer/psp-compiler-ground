/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern int UPDATE_TYPE;
extern int GET_HEAD_SESSIONID;
extern int Accession;
extern int RELOAD_FLG;
extern int CHARSET_CODE;
M2C_UNK RequestEnd();                               /* extern */
extern int LAYOUT_STOP;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", RequestEnd);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l1C03(void) {
    RequestEnd();
    return 3;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l1C0B(void) {
    RequestEnd();
    return 3;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l1C0C(void) {
    LAYOUT_STOP = 1;
    return 0xC;
}

void ps_setUpdateType(int *req) {
    int t;
    int *node;
    int *n2;

    if (req == NULL) {
        return;
    }
    if (UPDATE_TYPE == 0) {
        req[12] = 4;
        return;
    }
    t = UPDATE_TYPE;
    if (t == 1) {
        node = (int *)HST_getHeadHistoryNode();
        if (node[12] == t) {
            req[12] = 4;
            return;
        }
        HST_setSessionID(node, GET_HEAD_SESSIONID);
        req[12] = 5;
        Accession = 1;
        RELOAD_FLG = 1;
        CHARSET_CODE = node[17];
        req[13] = 1;
        return;
    }
    n2 = (int *)HST_getHeadHistoryNode();
    if (req[5] == 0 || (n2 = (int *)HST_searchTargetNameHistoryNode(req[5], req[4])) != NULL) {
        HST_setSessionID(n2, GET_HEAD_SESSIONID);
    }
    req[12] = 10;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137764);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", ps_l1C14);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", ps_l1C18);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", ps_l1F12);

