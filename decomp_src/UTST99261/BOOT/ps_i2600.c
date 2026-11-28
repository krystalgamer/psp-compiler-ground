/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
extern int EX_MSG_BOX_NO[2];
extern int mq_ps_su;
extern int mq_ps;
extern int Security;
extern int buf_Message_Show_FLG;
PsLocation *ps_SetLocation();
extern int DOCUMENT_WRITE;
extern int LAYOUT_STOP;
extern int buf_Loding_Stop_FLG;
extern int SaveUnitId;
extern int RECIEVE_MSG;
int *ps_ExternalSearchSessionHistoryNode();
int *ps_ExternalSearchSessionParentHistoryNode();
int *HST_getJSURI();
int *HST_getCSSURI();
extern int CONTENT_SAVE;
extern int CONTENT_GETCNT;
extern int CONTENT_GETTMEP;
extern int GET_HEAD_STAT;
extern int GET_HEAD_STOP;
extern int GET_HEAD_SESSIONID;
extern int *ContntHeader;
extern int ContntType;
extern int SubmitExtn;
extern int UPDATE_TYPE;
extern int *SaveTRAGETURI;
extern int NOTARGET;
int *HST_httpHeaderDisassemble();
extern int SSLFlg;
extern int SSL_Next_STS;
extern int Accession;
extern int SaveURI;
extern int SaveREF;
extern int Layout_Cont;
extern int psCacheMode;
int ps_i241A(PsIpc *msg);
extern int buf_sessionUI;
extern int buf_localUI;
extern int SAVE_STOP;
extern int On_Save;
extern void *gPREF_UI;
extern int mq_js;
extern int mq_layout;
extern int LAYOUT_END[9];
extern int before_ps_sts;
extern int buf_Message_cnt;
extern int buf_ps_sts;
M2C_UNK ps_setExMsg(int, int);                      /* extern */
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */

M2C_UNK ps_i2314();                                 /* extern */

int ps_i2606(PsIpc *msg) {
    PsIpc m;
    int *info;
    int d;

    d = msg->x1C;
    if (d != 0) {
        info = MEM_calloc(0, 0xC);
        ps_setRecvInfo(msg->x04, d);
        info[0] = ps_getRecvRate(&info[1], &info[2]);
        m.type = 2;
        m.x04 = buf_sessionUI;
        m.x08 = 0;
        m.cmd = 4;
        m.x10 = 0;
        m.x14 = buf_localUI;
        m.x18 = 0xC;
        m.x1C = (int)info;
        ps_sndmsg(&m, 1);
    }
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_i2607(PsIpc *msg) {
    ps_i2606(msg);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_i2608(PsIpc *msg) {
    ps_i2606(msg);
}

int ps_i2609(PsIpc *msg) {
    PsIpc m;
    int *d;
    int *info;
    int rate;

    if (SAVE_STOP == 0) {
        d = (int *)msg->x1C;
        if (CONTENT_SAVE == 0) {
            if (d[1] == 0) {
                rate = 0;
            } else {
                rate = d[0] * 100 / d[1];
            }
        } else {
            if (CONTENT_GETCNT != d[3]) {
                CONTENT_GETTMEP++;
                CONTENT_GETCNT = d[3];
            }
            rate = 0;
            if (d[2] != 0 && d[1] != 0) {
                rate = d[0] * 100 / (d[1] * d[2]) + (CONTENT_GETTMEP * 100 - 100) / d[2];
            }
        }
        info = MEM_malloc(0, 0xC);
        if (info == NULL) {
            ps_halt("ps_i2606(E_malloc) failed");
        }
        if (rate > 100) {
            rate = 100;
        }
        info[0] = rate;
        info[1] = d[0];
        info[2] = d[1];
        m.type = 2;
        m.x04 = buf_sessionUI;
        m.x08 = 0;
        m.cmd = 4;
        m.x10 = 0;
        m.x14 = buf_localUI;
        m.x18 = 0xC;
        m.x1C = (int)info;
        ps_sndmsg(&m, 1);
    }
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    return buf_ps_sts;
}

int ps_i2612(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt("Parser : cmk_mbox_send(ps_i2612) failed");
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_i2614(int arg0) {
    ps_setExMsg(EX_MSG_BOX_NO[1], arg0);
    return buf_ps_sts;
}

int ps_i261A(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt("Parser : cmk_mbox_send(ps_i2612) failed");
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_freeRecvInfo(void) {
    RecvInfo *p;
    RecvInfo *next;

    p = rcvInfo;
    while (p != NULL) {
        next = p->next;
        MEM_free(0, p);
        p = next;
    }
    rcvInfo = NULL;
}

void ps_setRecvInfo(int id, int *data) {
    RecvInfo *p;
    RecvInfo *prev;

    prev = NULL;
    for (p = rcvInfo; p != NULL; p = p->next) {
        if (p->id == id) {
            break;
        }
        prev = p;
    }
    if (p == NULL) {
        p = MEM_malloc(0, sizeof(RecvInfo));
        if (p == NULL) {
            return;
        }
        if (prev != NULL) {
            prev->next = p;
        }
        if (rcvInfo == NULL) {
            rcvInfo = p;
        }
        p->d[0] = 0;
        p->d[1] = 0;
        p->d[2] = 0;
        p->d[3] = 0;
        p->next = NULL;
        p->id = id;
    }
    p->d[0] = data[0];
    p->d[1] = data[1];
    p->d[2] = data[2];
    p->d[3] = data[3];
}

int ps_getRecvRate(int *total, int *size) {
    RecvInfo *p;
    int localGot;
    int localSize;
    int maxv;
    int count;
    int rate1;
    int rate2;
    int sum;
    int r;

    localGot = 0;
    localSize = 0;
    maxv = 0;
    count = 0;
    rate1 = 0;
    rate2 = 0;
    sum = 0;
    for (p = rcvInfo; p != NULL; p = p->next) {
        if (p->id <= 0x08000000) {
            localGot += p->d[0];
            if (p->d[1] == 0) {
                localSize += p->d[0];
            } else {
                localSize += p->d[1];
            }
        } else {
            count++;
            if (p->d[0] >= p->d[1]) {
                sum += 100;
            } else if (p->d[1] != 0) {
                sum += p->d[0] * 100 / p->d[1];
            }
            if (p->d[2] > maxv) {
                maxv = p->d[2];
            }
        }
        *total += p->d[0];
        *size += p->d[1];
    }
    if (count > maxv) {
        maxv = count;
    }
    if (localSize != 0) {
        rate1 = localGot * 100 / localSize * 30 / 100;
    }
    if (maxv != 0) {
        rate2 = sum / maxv * 70 / 100;
    }
    r = rate1 + rate2;
    if (r > 100) {
        r = 99;
    }
    return r;
}
