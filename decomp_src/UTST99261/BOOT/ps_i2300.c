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
    b.x[7] = (int)"<html><body></body></html>";
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

int ps_i2308(PsIpc *msg) {
    PsIpc m;
    struct {
        int x00;
        PsIpc body;
    } q;
    int *node;
    int *n;
    int r;
    int i;
    int js;
    int css;
    int flag;

    node = NULL;
    flag = 0;
    if (msg->x14 != 0) {
        n = ps_ExternalSearchSessionHistoryNode(msg->x04, msg->x14);
        if (n == NULL) {
            goto notfound;
        }
        HST_setRequestFlag(n, 4);
    } else {
        node = HST_searchSessionIDHistoryNode(msg->x04);
        if (node == NULL) {
        notfound:
            if (msg->x18 != 0) {
                MEM_free(0, msg->x1C);
            }
            return buf_ps_sts;
        }
        if (msg->x08 == 1) {
            r = ps_ParseDomBuildCall(msg);
            if (r != 0) {
                q.body = *msg;
                if (OS_mq_send(mq_js, &q, sizeof(q), 0) < 0) {
                    ps_halt("Parser : mq_js,(char*)&pmbox failed");
                }
                return r;
            }
        }
        node[15] = 4;
    }
    if (msg->x14 == 0) {
        js = HST_getJSURIlen(node);
        css = HST_getCSSURIlen(node);
        if ((js | css) == 0) {
            flag = 0;
            goto term;
        }
        for (i = 0; i < js; i++) {
            if (HST_getJSURI(node, i + 1)[15] != 4) {
                flag = 1;
                break;
            }
        }
        for (i = 0; i < css; i++) {
            if (HST_getCSSURI(node, i + 1)[15] != 4) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
        term:
            ps_DomTerm(msg->x04);
            initMPL_REQ_LOAD_PAGE(&m);
            m.x04 = msg->x04;
            m.x10 = 1;
            ps_sndmsg(&m, 4);
        }
    } else {
        node = ps_ExternalSearchSessionParentHistoryNode(msg->x04, msg->x14);
        js = HST_getJSURIlen(node);
        css = HST_getCSSURIlen(node);
        for (i = 0; i < js; i++) {
            if (HST_getJSURI(node, i + 1)[15] != 4) {
                flag = 1;
                break;
            }
        }
        for (i = 0; i < css; i++) {
            if (HST_getCSSURI(node, i + 1)[15] != 4) {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && node[15] == 4) {
            ps_DomTerm(node[0x48 / 4]);
            initMPL_REQ_LOAD_PAGE(&m);
            m.x04 = node[0x48 / 4];
            m.x10 = 1;
            ps_sndmsg(&m, 4);
        }
    }
    for (i = 1; i < 7; i++) {
        if (i == 4 || i == 5) {
            continue;
        }
        node = HST_searchRequestFlagHistoryNode(i);
        if (node != NULL) {
            return 8;
        }
    }
    for (i = 1; i < 4; i++) {
        if (i == 2) {
            continue;
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

static inline int ps_isZeroSession(int id) {
    if (id == 0) {
        return 1;
    }
    return 0;
}

static inline int *ps_searchMsgNode(PsIpc *msg) {
    if (msg->x14 != 0) {
        return ps_ExternalSearchSessionHistoryNode(msg->x04, msg->x14);
    }
    return HST_searchSessionIDHistoryNode(msg->x04);
}

int ps_i230A(PsIpc *msg) {
    PsIpc m;
    struct {
        int x00;
        PsIpc body;
    } q;
    struct {
        int x00;
        PsIpc body;
    } out;
    int sent1;
    int sent2;
    int *node;
    int i;
    int ret;

    sent1 = 0;
    sent2 = 0;
    if (ps_isZeroSession(msg->x04)) {
        goto out;
    }
    node = ps_searchMsgNode(msg);
    if (node == NULL) {
        if (msg->x18 != 0) {
            MEM_free(0, msg->x1C);
        }
        goto out;
    }
    if (node[15] == 8) {
    out:
        ret = buf_ps_sts;
        goto end;
    }
    HST_setRequestFlag(node, 0);
    for (i = 1; i < 7; i++) {
        if (HST_searchRequestFlagHistoryNode(i) != 0) {
            ret = 9;
            goto end;
        }
        if (ps_ExternalSearchRequestFlag(i, 1) != 0) {
            ret = 9;
            goto end;
        }
        if (ps_ExternalSearchRequestFlag(i, 2) != 0) {
            ret = 9;
            goto end;
        }
    }
    sendComplete(&m);
    while (GetMQUEUE(mq_ps_su, &q) != 0) {
        switch (q.body.cmd) {
        case 2:
            if (sent1 == 0) {
                out.body = q.body;
                if (OS_mq_send(mq_ps, &q, sizeof(out), 0) < 0) {
                    ps_halt("Parser : cmk_mbox_send(ps_i2309) failed");
                }
                sent1 = 1;
                continue;
            }
            break;
        case 0x17:
            if (sent2 == 0) {
                out.body = q.body;
                if (OS_mq_send(mq_ps, &q, sizeof(out), 0) < 0) {
                    ps_halt("Parser : cmk_mbox_send(ps_i2309) failed");
                }
                sent2 = 1;
                continue;
            }
            break;
        }
        if (q.body.x1C != 0) {
            MEM_free(0, q.body.x1C);
        }
    }
    buf_Loding_Stop_FLG = 0;
    SSLFlg = 0;
    ret = 3;
end:
    return ret;
}

int ps_i230C(PsIpc *msg) {
    int *node;

    if (msg->x14 != 0) {
        node = ps_ExternalSearchSessionHistoryNode(msg->x04, msg->x14);
    } else {
        node = HST_searchSessionIDHistoryNode(msg->x04);
    }
    if (node == NULL) {
        if (msg->x18 != 0) {
            MEM_free(0, msg->x1C);
        }
        return buf_ps_sts;
    }
    if (node[15] == 8) {
        return buf_ps_sts;
    }
    HST_setRequestFlag(node, 0);
    return 0xB;
}

int ps_i2312(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt("Parser : cmk_mbox_send(ps_i2312) failed");
    }
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2300", ps_i2314);

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
        ps_halt("Parser : HST_getHeadHistoryNode ERROR failed");
    }
    len = HST_getCurURIlen(node);
    buf = MEM_malloc(0, len + 4);
    if (buf == NULL) {
        ps_halt("Parser : (char*)E_malloc(ps_u0203) failed");
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
        ps_DomTerm(parent[18]);
        initMPL_REQ_LOAD_PAGE(&lp);
        lp.x04 = parent[18];
        lp.x10 = 1;
        ps_sndmsg(&lp, 4);
    }
    return buf_ps_sts;
}
