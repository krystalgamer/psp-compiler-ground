/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
extern char D_00137AD8[];
extern char D_00137B00[];
extern char D_001379AC[];
extern char D_001379D4[];
int *ps_ExternalSearchSessionHistoryNode();
int *ps_ExternalSearchSessionParentHistoryNode();
int *HST_getJSURI();
int *HST_getCSSURI();
extern char D_0013794C[];
extern char D_00137CA4[];
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
extern char D_00137C10[];
extern char D_001379EC[];
extern char D_00137A7C[];
extern char D_00137AAC[];
int ps_i241A(PsIpc *msg);
extern int buf_sessionUI;
extern int buf_localUI;
extern int SAVE_STOP;
extern int On_Save;
extern void *gPREF_UI;
extern int mq_js;
extern int mq_layout;
extern int LAYOUT_END[9];
extern char D_00137964[];
extern char D_00137A54[];
extern char D_00137CC0[];
extern char D_00137CE8[];
extern char D_00137D90[];
extern int before_ps_sts;
extern int buf_Message_cnt;
extern int buf_ps_sts;
M2C_UNK ps_setExMsg(int, int);                      /* extern */
extern int D_00584FB8;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */

M2C_UNK ps_i2314();                                 /* extern */


void sendMPU_REQ_SHOW_DIALOG(PsIpc *msg) {
    PsIpc m;

    m.type = 2;
    m.x04 = msg->x04;
    m.x08 = msg->x08;
    m.cmd = 0xE;
    m.x10 = msg->x10;
    m.x14 = msg->x14;
    m.x18 = msg->x18;
    m.x1C = msg->x1C;
    ps_sndmsg(&m, 1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l3803(PsIpc *msg) {
    sendMPU_REQ_SHOW_DIALOG(msg);
    before_ps_sts = buf_ps_sts;
    buf_Message_cnt += 1;
    return 0x13;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l3812(PsIpc *msg) {
    sendMPU_REQ_SHOW_DIALOG(msg);
    before_ps_sts = buf_ps_sts;
    buf_Message_cnt += 1;
    return 0x13;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l3813(PsIpc *msg) {
    sendMPU_REQ_SHOW_DIALOG(msg);
    buf_Message_cnt += 1;
    return 0x13;
}

int ps_l3903(PsIpc *msg) {
    PsIpc m;

    initMPL_REQ_LOAD_PAGE(&m);
    m.x04 = msg->x04;
    m.x10 = 2;
    ps_sndmsg(&m, 4);
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_l3912);

int ps_i2002(PsIpc *msg) {
    PsIpc m;

    m.type = 2;
    m.x04 = buf_sessionUI;
    m.x08 = 0;
    m.cmd = 0;
    m.x10 = 0;
    m.x14 = buf_localUI;
    m.x18 = msg->x18;
    m.x1C = msg->x1C;
    ps_sndmsg(&m, 1);
    return 3;
}

int ps_i2104(PsIpc *msg) {
    LAYOUT_END[1] = 2;
    LAYOUT_END[2] = ps_sessionGen();
    LAYOUT_END[3] = 0;
    LAYOUT_END[4] = 0x302;
    LAYOUT_END[5] = 0;
    LAYOUT_END[6] = 0;
    LAYOUT_END[7] = 0;
    LAYOUT_END[8] = 0;
    OS_mq_send(mq_layout, LAYOUT_END, 0x24, 0);
    return 5;
}

int ps_i2206(PsIpc *msg) {
    PsIpc m;
    PsDomBuild b;
    int *node;
    int *r;

    r = NULL;
    node = HST_searchSessionIDHistoryNode(msg->x04);
    if (node == NULL) {
        if (msg->x18 != 0) {
            MEM_free(0, msg->x1C);
        }
        return buf_ps_sts;
    }
    b.x[0] = node[1];
    b.x[1] = node[0];
    b.x[2] = node[5];
    b.x[3] = node[4];
    b.x[4] = node[7];
    b.x[5] = node[6];
    b.x[6] = msg->x18;
    b.x[7] = msg->x1C;
    b.x[9] = msg->x04;
    b.x[11] = 0;
    b.x[12] = 0;
    b.x[13] = Accession;
    node[15] = 4;
    if (msg->x18 != 0 && *(char *)msg->x1C != 0) {
        r = parseDomBuild(&b);
        if (*r != 0) {
            ps_halt(D_0013794C);
        }
    }
    HST_setCharSet(node, 100);
    HST_setRequestResult(node, 1);
    initMPL_REQ_LOAD_PAGE(&m);
    m.x04 = msg->x04;
    ps_sndmsg(&m, 4);
    ps_DomTerm(msg->x04);
    initMPL_REQ_LOAD_PAGE(&m);
    m.x04 = msg->x04;
    m.x10 = 1;
    ps_sndmsg(&m, 4);
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    if (r != NULL) {
        MEM_free(0, r);
    }
    return 7;
}

int ps_i2208(PsIpc *msg) {
    PsIpc m;
    PsDomBuild b;
    int *node;
    int *r;
    int i;

    r = NULL;
    node = HST_searchSessionIDHistoryNode(msg->x04);
    if (node == NULL) {
        if (msg->x18 != 0) {
            MEM_free(0, msg->x1C);
        }
        return buf_ps_sts;
    }
    if (HST_getDomObject(node) == 0) {
        b.x[0] = node[1];
        b.x[1] = node[0];
        b.x[2] = node[5];
        b.x[3] = node[4];
        b.x[4] = node[7];
        b.x[5] = node[6];
        b.x[6] = msg->x18;
        b.x[7] = msg->x1C;
        b.x[9] = msg->x04;
        b.x[11] = 0;
        b.x[12] = 0;
        b.x[13] = Accession;
        if (msg->x18 != 0 && *(char *)msg->x1C != 0) {
            r = parseDomBuild(&b);
            if (*r != 0) {
                ps_halt(D_0013794C);
            }
        }
        HST_setCharSet(node, 100);
        initMPL_REQ_LOAD_PAGE(&m);
        m.x04 = msg->x04;
        ps_sndmsg(&m, 4);
        if (r != NULL) {
            MEM_free(0, r);
        }
    }
    node[15] = 4;
    ps_DomTerm(msg->x04);
    initMPL_REQ_LOAD_PAGE(&m);
    m.x04 = msg->x04;
    m.x10 = 1;
    ps_sndmsg(&m, 4);
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    for (i = 1; i < 7; i++) {
        if (i == 4 || i == 5) {
            continue;
        }
        node = HST_searchRequestFlagHistoryNode(i);
        if (node != NULL) {
            return 8;
        }
        node = ps_ExternalSearchRequestFlag(i, 1);
        if (node != NULL) {
            return 8;
        }
        node = ps_ExternalSearchRequestFlag(i, 2);
        if (node != NULL) {
            return 8;
        }
    }
    return 7;
}

int ps_i2209(PsIpc *msg) {
    PsIpc m;
    char *pref;

    initMPU_SIG_RECV_COMPLETE(&m);
    m.x04 = buf_sessionUI;
    m.x10 = 1;
    m.x14 = buf_localUI;
    ps_sndmsg(&m, 1);
    pref = gPREF_UI;
    if (pref != NULL) {
        *(int *)(pref + 0x68) = 0;
    }
    On_Save = 0;
    SAVE_STOP = 0;
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i220A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i220C);

int ps_i2212(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt(D_00137964);
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_i2214(void) {
    ps_i2314();
}

int ps_i2215(PsIpc *msg) {
    PsIpc m;

    m.type = 2;
    m.x04 = 0;
    m.x08 = 0;
    m.cmd = 0x10;
    m.x10 = 1;
    m.x14 = 0;
    m.x18 = 0;
    m.x1C = 0;
    ps_sndmsg(&m, 1);
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2219);

int ps_i221A(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;
    PsIpc lp;
    int *node;
    int *parent;
    int jsLen;
    int cssLen;
    int i;
    int busy;
    int r;

    busy = 0;
    if (msg->x14 == 0) {
        m.body = *msg;
        if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
            ps_halt(D_001379AC);
        }
        return buf_ps_sts;
    }
    node = ps_ExternalSearchSessionHistoryNode(msg->x04, msg->x14);
    if (node == NULL) {
        ps_halt(D_001379D4);
    }
    HST_setRequestFlag(node, 4);
    parent = ps_ExternalSearchSessionParentHistoryNode(msg->x04, msg->x14);
    jsLen = HST_getJSURIlen(parent);
    cssLen = HST_getCSSURIlen(parent);
    for (i = 0; i < jsLen; i++) {
        node = HST_getJSURI(parent, i + 1);
        if (node[15] != 4) {
            busy = 1;
            break;
        }
    }
    for (i = 0; i < cssLen; i++) {
        node = HST_getCSSURI(parent, i + 1);
        if (node[15] != 4) {
            busy = 1;
            break;
        }
    }
    if (busy == 0 && parent[15] == 4) {
        initMPL_REQ_LOAD_PAGE(&lp);
        lp.x04 = parent[18];
        lp.x10 = 1;
        ps_sndmsg(&lp, 4);
    }
    r = ps_JSMailBoxClean();
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    return r;
}

int ps_i2306(PsIpc *msg) {
    PsIpc m;
    PsDomBuild b;
    int *node;
    void *r;

    node = HST_searchSessionIDHistoryNode(msg->x04);
    if (node == NULL) {
        if (msg->x18 != 0) {
            MEM_free(0, msg->x1C);
        }
        return buf_ps_sts;
    }
    node[15] = 3;
    b.x[0] = node[1];
    b.x[1] = node[0];
    b.x[2] = node[5];
    b.x[3] = node[4];
    b.x[4] = node[7];
    b.x[5] = node[6];
    b.x[6] = 0x1A;
    b.x[7] = (int)D_001379EC;
    b.x[9] = msg->x04;
    b.x[10] = 0;
    b.x[11] = 0;
    b.x[12] = 0;
    b.x[13] = Accession;
    r = parseDomBuild(&b);
    if (r != NULL) {
        MEM_free(0, r);
    }
    sendMPL_REQ_LOAD_PAGE(&m, msg->x04);
    return 7;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2308);

int ps_i2309(PsIpc *msg) {
    PsIpc m;

    if (SAVE_STOP != 0) {
        return buf_ps_sts;
    }
    initMPU_SIG_RECV_COMPLETE(&m);
    m.x04 = buf_sessionUI;
    m.x14 = buf_localUI;
    ps_sndmsg(&m, 1);
    On_Save = 0;
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i230A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i230C);

int ps_i2312(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt(D_00137A54);
    }
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2314);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ps_i2315(void) {
    return 3;
}

int ps_i2319(PsIpc *msg) {
    PsIpc c;
    PsIpc a;
    PsDomBuild b;
    void *node;
    int *buf;
    int len;
    void *r;

    MEM_free(0, SaveURI);
    MEM_free(0, SaveREF);
    SaveURI = 0;
    SaveREF = 0;
    node = HST_getHeadHistoryNode();
    if (node == NULL) {
        ps_halt(D_00137A7C);
    }
    len = HST_getCurURIlen(node);
    buf = MEM_malloc(0, len + 4);
    if (buf == NULL) {
        ps_halt(D_00137AAC);
    }
    buf[0] = len;
    memcpy(buf + 1, HST_getCurURI(node), buf[0]);
    b.x[0] = buf[0];
    b.x[1] = (int)(buf + 1);
    b.x[2] = 0;
    b.x[3] = 0;
    b.x[4] = 0;
    b.x[5] = 0;
    b.x[6] = 0;
    b.x[7] = 0;
    b.x[8] = 0;
    b.x[9] = 0;
    b.x[11] = 0;
    b.x[12] = 0xB;
    b.x[13] = 0;
    r = parseDomBuild(&b);
    if (r != NULL) {
        MEM_free(0, r);
    }
    ps_getsend(node, psCacheMode, 0, 0);
    sendStart(&a, &c, buf);
    Layout_Cont = 0;
    ps_freeRecvInfo();
    return 6;
}

int ps_i231A(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;
    PsIpc lp;
    int *node;
    int *parent;
    int jsLen;
    int cssLen;
    int i;
    int busy;

    busy = 0;
    if (msg->x14 == 0) {
        m.body = *msg;
        if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
            ps_halt(D_00137AD8);
        }
        return buf_ps_sts;
    }
    node = ps_ExternalSearchSessionHistoryNode(msg->x04, msg->x14);
    if (node == NULL) {
        ps_halt(D_00137B00);
    }
    HST_setRequestFlag(node, 4);
    parent = ps_ExternalSearchSessionParentHistoryNode(msg->x04, msg->x14);
    jsLen = HST_getJSURIlen(parent);
    cssLen = HST_getCSSURIlen(parent);
    for (i = 0; i < jsLen; i++) {
        node = HST_getJSURI(parent, i + 1);
        if (node[15] != 4) {
            busy = 1;
            break;
        }
    }
    for (i = 0; i < cssLen; i++) {
        node = HST_getCSSURI(parent, i + 1);
        if (node[15] != 4) {
            busy = 1;
            break;
        }
    }
    if (busy == 0 && parent[15] == 4) {
        ps_DomTerm(parent[18]);
        initMPL_REQ_LOAD_PAGE(&lp);
        lp.x04 = parent[18];
        lp.x10 = 1;
        ps_sndmsg(&lp, 4);
    }
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2406);

int ps_i2412(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    if (msg->x14 != 2) {
        m.body = *msg;
        if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
            ps_halt(D_00137C10);
        }
    } else {
        buf_ps_sts = ps_i241A(msg);
    }
    return buf_ps_sts;
}

int ps_i2414(PsIpc *msg) {
    PsIpc m;
    int r;
    int *uri;
    int t;
    int a;
    int ty;

    ps_setExMsg(D_00584FB8, msg);
    if (GET_HEAD_STAT == 0) {
        GET_HEAD_STAT = 1;
        if (ContntHeader != NULL) {
            HST_httpHeaderFree(ContntHeader);
        }
        ContntHeader = HST_httpHeaderDisassemble(msg->x1C, msg->x18);
        ContntType = UTL_guessMIMEType(ContntHeader[3]);
        if (ContntType == -1) {
            ContntType = SubmitExtn;
        }
        SubmitExtn = -1;
        r = ps_i2414_auth(msg);
        if (r != -1) {
            return r;
        }
        if (ContntType != 5 && ContntType != 6 && ContntType != 2 && ContntType != 3 && ContntType != 4) {
            initMPI_SIG_REQUEST_ABORTED(&m);
            m.x04 = GET_HEAD_SESSIONID;
            m.x10 = 0;
            ps_sndmsg(&m, 5);
            return 0x14;
        }
        if (ContntType == 5 || ContntType == 6) {
            a = 0;
            if (GET_HEAD_STOP == 1) {
                ps_freeExMsgBox(D_00584FB8);
                GET_HEAD_STOP = 0;
                return 3;
            }
            ty = (UPDATE_TYPE != 0) ? 2 : 1;
            t = 0;
            uri = SaveTRAGETURI;
            if (uri[0] != 0 && NOTARGET == 0) {
                t = uri[1];
                a = uri[0];
            }
            ps_sendAbortPage(0, 0, ty, t, a);
        }
    }
    return 0x14;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2414_auth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i241A);

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
            ps_halt(D_00137CA4);
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
        ps_halt(D_00137CC0);
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_i2614(int arg0) {
    ps_setExMsg(D_00584FB8, arg0);
    return buf_ps_sts;
}

int ps_i261A(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt(D_00137CC0);
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

int ps_i2906(PsIpc *msg) {
    PsIpc m;

    if ((msg->x04 > 0x08000000 && msg->x04 <= 0x10000000) || HST_searchSessionIDHistoryNode(msg->x04) == NULL) {
        MEM_free(0, msg->x1C);
    } else if (SSLFlg == 0) {
        SSLFlg = 1;
        m.x04 = msg->x04;
        m.x08 = msg->x08;
        m.x10 = msg->x10;
        m.x14 = msg->x14;
        m.x18 = msg->x18;
        m.x1C = msg->x1C;
        m.type = 2;
        m.cmd = 0x11;
        ps_sndmsg(&m, 1);
        if (msg->x10 == 1) {
            SSL_Next_STS = buf_ps_sts;
            return 0x16;
        }
    } else if (msg->x1C != 0) {
        MEM_free(0, msg->x1C);
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_i2909(void *arg0) {
    int temp_a1;

    temp_a1 = M2C_FIELD(arg0, int *, 0x1C);
    if (temp_a1 != 0) {
        MEM_free(0, temp_a1);
    }
    return buf_ps_sts;
}

int ps_i2912(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt(D_00137CE8);
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_i2914(int arg0) {
    ps_setExMsg(D_00584FB8, arg0);
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2D06);

int ps_i2D12(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt(D_00137D90);
    }
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2D14);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", parseDomBuild);
