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


#include "parse_ps.h"
extern int mq_js;
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

int ps_l1F12(PsIpc *msg) {
    PsIpc m;
    PsMqMsg mm;
    int attr[4];
    int *node;
    int *n;
    int i;
    int flag;

    flag = 0;
    node = HST_searchSessionIDHistoryNode(msg->x04);
    if (node == NULL) {
        ps_halt("ps_i2406(session ERR) failed");
    }
    initMPI_SIG_REQUEST_ABORTED(&m);
    m.x10 = 1;
    for (i = 1; i < 7; i++) {
        HST_searchRequestFlagHistoryNode(i);
        while ((n = HST_searchRequestFlagHistoryNode(i)) != NULL) {
            m.x14 = 0;
            m.x04 = HST_getSessionID(n);
            if (m.x04 == 0) {
                ps_halt("HST_getSessionID failed");
            }
            flag = 1;
            ps_sndmsg(&m, 5);
            n[0x3C / 4] = 8;
        }
        while ((n = ps_ExternalSearchRequestFlag(i, 1)) != NULL) {
            m.x14 = 1;
            m.x04 = HST_getSessionID(n);
            if (m.x04 == 0) {
                ps_halt("HST_getSessionID failed");
            }
            flag = 1;
            ps_sndmsg(&m, 5);
            n[0x3C / 4] = 8;
        }
        while ((n = ps_ExternalSearchRequestFlag(i, 2)) != NULL) {
            m.x14 = 2;
            m.x04 = HST_getSessionID(n);
            if (m.x04 == 0) {
                ps_halt("HST_getSessionID failed");
            }
            flag = 1;
            ps_sndmsg(&m, 5);
            n[0x3C / 4] = 8;
        }
    }
    node[0x3C / 4] = 8;
    initMPL_REQ_ABORT_PAGE(&m);
    m.x04 = msg->x04;
    ps_sndmsg(&m, 4);
    for (;;) {
        OS_mq_getattr(mq_js, attr);
        attr[0] |= 0x4000;
        OS_mq_setattr(mq_js, attr, 0);
        if (OS_mq_receive(mq_js, &mm, 0x24, 0) < 0) {
            break;
        }
        attr[0] &= ~0x4000;
        OS_mq_setattr(mq_js, attr, 0);
        if (mm.data != NULL) {
            MEM_free(0, mm.data);
        }
    }
    attr[0] &= ~0x4000;
    OS_mq_setattr(mq_js, attr, 0);
    if (flag == 1) {
        return 0xC;
    }
    return 0xB;
}

