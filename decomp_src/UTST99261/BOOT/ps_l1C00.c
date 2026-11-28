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
extern char D_00137764[];
extern int mq_ps;
extern int mq_ps_su;
extern int buf_sessionUI;
extern int buf_localUI;
extern int buf_Loding_Stop_FLG;
extern int SSLFlg;
int OS_mq_send(int q, void *buf, int len, unsigned int prio);
M2C_UNK RequestEnd(msg)
PsIpc *msg;
{
    PsIpc m;
    struct {
        int x00;
        PsIpc body;
    } q;
    struct {
        int x00;
        PsIpc body;
    } out;
    int f2;
    int f17;
    int f1A;

    f2 = 0;
    f17 = 0;
    f1A = 0;
    initMPU_SIG_LAYOUT_COMPLETE(&m);
    m.x04 = buf_sessionUI;
    m.x14 = buf_localUI;
    ps_sndmsg(&m, 1);
    m.x04 = msg->x04;
    m.x08 = msg->x08;
    m.x10 = msg->x10;
    m.x14 = msg->x14;
    m.x18 = msg->x18;
    m.x1C = msg->x1C;
    m.type = 2;
    m.cmd = 5;
    ps_sndmsg(&m, 1);
    while (GetMQUEUE(mq_ps_su, &q)) {
        switch (q.body.cmd) {
        case 2:
            if (f2 == 0) {
                out.body = q.body;
                if (OS_mq_send(mq_ps, &q, sizeof(out), 0) < 0) {
                    ps_halt(D_00137764);
                }
                f2 = 1;
            } else if (q.body.x1C != 0) {
                MEM_free(0, q.body.x1C);
            }
            break;
        case 0x17:
            if (f17 == 0) {
                out.body = q.body;
                if (OS_mq_send(mq_ps, &q, sizeof(out), 0) < 0) {
                    ps_halt("Parser : cmk_mbox_send(ps_i2309) failed");
                }
                f17 = 1;
            } else if (q.body.x1C != 0) {
                MEM_free(0, q.body.x1C);
            }
            break;
        case 0x1A:
            if (f1A == 0) {
                out.body = q.body;
                if (OS_mq_send(mq_ps, &q, sizeof(out), 0) < 0) {
                    ps_halt("Parser : cmk_mbox_send(ps_i2309) failed");
                }
                f1A = 1;
            } else if (q.body.x1C != 0) {
                MEM_free(0, q.body.x1C);
            }
            break;
        default:
            if (q.body.x1C != 0) {
                MEM_free(0, q.body.x1C);
            }
            break;
        }
    }
    Accession = 0;
    buf_Loding_Stop_FLG = 0;
    SSLFlg = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *HST_getHeadHistoryNode(void);
int HST_setSessionID(void *arg0, int arg1);
void *HST_searchTargetNameHistoryNode(void *a, void *b);
void *HST_searchSessionIDHistoryNode(int sid);
void initMPI_SIG_REQUEST_ABORTED(void *arg0);
void *HST_searchRequestFlagHistoryNode(int flag);
int HST_getSessionID(void *arg0);
void *ps_ExternalSearchRequestFlag(int arg0, int arg1);
void initMPL_REQ_ABORT_PAGE(void *arg0);
int OS_mq_getattr(int id, void *);
int OS_mq_setattr(int id, void *, void *);
int OS_mq_receive(int id, char *buf, int len, unsigned int *prio);
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

