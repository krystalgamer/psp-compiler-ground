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


INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00135C80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137410);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137430);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137458);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137488);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001374B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001374E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137510);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137568);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137580);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001375A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001375C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001375F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137618);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137648);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137654);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137674);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137694);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001376B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001376D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001376F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_0013770C);

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

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001378D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001378F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137910);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137934);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_0013794C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137964);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_0013798C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001379AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001379D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_001379EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137A08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137A2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137A54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137A7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137AAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137AD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137B00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137B18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137B1C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137B20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137B44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137B60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137B80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137B8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137B98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137BB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137BDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137BF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137C10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137C38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137C50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137C60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137C80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137CA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137CC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137CE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137D10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137D30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137D48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137D64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137D70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137D90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1C00", D_00137DB8);
