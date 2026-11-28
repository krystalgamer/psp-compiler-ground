/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
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
extern char D_0013794C[];
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
void MEM_free(M2C_UNK, void *);                  /* extern */

M2C_UNK ps_i2314();                                 /* extern */

void *HST_searchSessionIDHistoryNode(int sid);
int *parseDomBuild(int *msg);
void ps_halt(char *msg);
int HST_setCharSet(void *arg0, int arg1);
int HST_setRequestResult(void *arg0, int arg1);
void initMPL_REQ_LOAD_PAGE(void *arg0);
int ps_sndmsg(PsIpc *msg, int dest);
void ps_DomTerm(int sid);
int HST_getDomObject(void *arg0);
void *HST_searchRequestFlagHistoryNode(int flag);
void *ps_ExternalSearchRequestFlag(int arg0, int arg1);
void initMPU_SIG_RECV_COMPLETE(void *arg0);
int OS_mq_send(int id, const char *buf, int len, unsigned int prio);
int ps_sessionGen(void);
int HST_setUnitId(void *arg0, int arg1);
int HST_setRequestFlag(void *arg0, int arg1);
int HST_getJSURIlen(void *arg0);
int HST_getCSSURIlen(void *arg0);
int ps_JSMailBoxClean(void);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2200", D_0013794C);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2200", ps_i220A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2200", ps_i220C);

int ps_i2212(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt("Parser : cmk_mbox_send(ps_i2212) failed");
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

int ps_i2219(PsIpc *msg) {
    PsDomBuild b;
    PsIpc lp;
    int *node;
    void *r;

    b.x[0] = ((int *)SaveURI)[0];
    b.x[1] = ((int *)SaveURI)[1];
    b.x[2] = ((int *)SaveREF)[0];
    b.x[3] = ((int *)SaveREF)[1];
    b.x[4] = 0;
    b.x[5] = 0;
    b.x[6] = 0;
    b.x[7] = 0;
    b.x[8] = 0;
    b.x[9] = ps_sessionGen();
    b.x[11] = 0;
    b.x[12] = 4;
    b.x[13] = Accession;
    b.x[15] = 0;
    r = parseDomBuild(&b);
    node = HST_searchSessionIDHistoryNode(b.x[9]);
    if (node == NULL) {
        ps_halt("ps_i2206(session ERR) failed");
    }
    HST_setUnitId(node, SaveUnitId);
    b.x[0] = node[1];
    b.x[1] = node[0];
    b.x[2] = node[5];
    b.x[3] = node[4];
    b.x[4] = node[7];
    b.x[5] = node[6];
    b.x[6] = msg->x18;
    b.x[7] = msg->x1C;
    b.x[11] = 3;
    b.x[12] = 0;
    b.x[13] = Accession;
    node[15] = 4;
    if (r != NULL) {
        MEM_free(0, r);
    }
    r = parseDomBuild(&b);
    initMPL_REQ_LOAD_PAGE(&lp);
    lp.x04 = b.x[9];
    ps_sndmsg(&lp, 4);
    initMPL_REQ_LOAD_PAGE(&lp);
    lp.x04 = b.x[9];
    lp.x10 = 1;
    ps_sndmsg(&lp, 4);
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    if (SaveURI != 0) {
        MEM_free(0, SaveURI);
    }
    if (SaveREF != 0) {
        MEM_free(0, SaveREF);
    }
    if (SaveTRAGETURI != 0) {
        MEM_free(0, SaveTRAGETURI);
    }
    if (r != NULL) {
        MEM_free(0, r);
    }
    if (RECIEVE_MSG != 0) {
        MEM_free(0, RECIEVE_MSG);
        RECIEVE_MSG = 0;
    }
    SaveURI = 0;
    SaveREF = 0;
    SaveTRAGETURI = 0;
    return 7;
}

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
            ps_halt("Parser : cmk_mbox_send(ps_i2412) failed");
        }
        return buf_ps_sts;
    }
    node = ps_ExternalSearchSessionHistoryNode(msg->x04, msg->x14);
    if (node == NULL) {
        ps_halt("ExternalHistory NULL\n");
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
