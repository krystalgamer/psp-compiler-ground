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

extern int gpsCntxtTable;
void *parseNewMultiCtxt(void);
void *parseNewCtxt(void);
int parseRegistBuffer();
int *parseContentStart();
int *parseContentContinue();
int *parseContentEnd();
void *parseSearchSessionID();
int asciiToUcs2();
void parseExtStyleSheet();
int *parseTEXTStart();
int *parseBINARYStart();
int parseRegistURI();
int parseReloadURI();
int *parseContentContinueJS();
int *parseJSDocumentEncode();
int parseMoveFrontURI();
int parseMoveBackURI();
int parseReplaceURI();
void parseSavedContents();
void parseReleaseResource();
void *MEM_realloc(void *pool, void *p, unsigned int size);
static inline int ps_isNotExtSession(int id) {
    if (id > 0x08000000 && id <= 0x10000000) {
        return 0;
    }
    return 1;
}

int ps_i2D06(PsIpc *msg) {
    PsIpc m;
    PsDomBuild b;
    PsIpc d;
    int *head;
    int *p;
    int *node;
    PsLocation *loc;
    int *r;
    int sec;

    sec = 0;
    head = HST_getHeadHistoryNode();
    if (head == NULL) {
        ps_halt("HST_getHeadHistoryNode FAILED\n");
    }
    if (ps_isNotExtSession(msg->x04)) {
        p = (int *)msg->x1C;
        if (msg->x14 != 0) {
            node = ps_ExternalSearchSessionHistoryNode(msg->x04, msg->x14);
        } else {
            node = HST_searchSessionIDHistoryNode(msg->x04);
        }
        if (node == NULL) {
            return buf_ps_sts;
        }
        if (HST_setCurURI(node, p[1], p[0]) == -1) {
            ps_halt("HST_setCurURI FAILED\n");
        }
        loc = ps_SetLocation(msg->x04, msg->x08, msg->x14, p[0], p[1]);
        if (loc->x0C >= 10) {
            if (msg->x14 == 0 && HST_getDomObject(node) == 0) {
                memset(&b, 0, 0x40);
                b.x[0] = node[1];
                b.x[1] = node[0];
                b.x[2] = node[5];
                b.x[3] = node[4];
                b.x[4] = node[7];
                b.x[5] = node[6];
                b.x[6] = 0x1A;
                b.x[7] = (int)"<html><body></body></html>";
                b.x[9] = msg->x04;
                b.x[11] = 0;
                b.x[12] = 0;
                b.x[13] = Accession;
                r = parseDomBuild(&b);
                if (r != NULL) {
                    MEM_free(0, r);
                }
                initMPL_REQ_LOAD_PAGE(&m);
                m.x04 = msg->x04;
                m.x08 = 0;
                ps_sndmsg(&m, 4);
            }
            initMPI_SIG_REQUEST_ABORTED(&m);
            m.x04 = msg->x04;
            m.x10 = 1;
            m.x14 = msg->x14;
            ps_sndmsg(&m, 5);
        } else {
            if (icmpstr(p[1], "https://", 8) == 1) {
                sec = 1;
            }
            if (((sec == 1 && Security == 0) || (sec == 0 && Security == 1)) && buf_Message_Show_FLG == 0) {
                if (Security == 0) {
                    if (initMPU_REQ_SHOW_DIALOG(&d, 6) == 0) {
                        ps_halt("initMPU_REQ_SHOW_DIALOG failed");
                    }
                    d.x14 = 0x80000004;
                } else {
                    if (initMPU_REQ_SHOW_DIALOG(&d, 7) == 0) {
                        ps_halt("initMPU_REQ_SHOW_DIALOG failed");
                    }
                    d.x14 = 0x80000005;
                }
                d.x04 = msg->x04;
                ps_sndmsg(&d, 1);
                buf_Message_Show_FLG = 1;
                before_ps_sts = buf_ps_sts;
                buf_Message_cnt++;
                if (msg->x1C != 0) {
                    MEM_free(0, msg->x1C);
                }
                return 0x13;
            }
            if (msg->x04 == head[18]) {
                m.type = 2;
                m.x04 = msg->x04;
                m.x08 = 0;
                m.cmd = 0x16;
                m.x10 = msg->x10;
                m.x14 = msg->x14;
                m.x18 = msg->x18;
                m.x1C = msg->x1C;
                ps_sndmsg(&m, 1);
            }
            if (msg->x14 != 0) {
                ps_ExternalSearchSessionParentHistoryNode(msg->x04, msg->x14);
            } else {
                HST_searchSessionIDHistoryNode(msg->x04);
            }
            ps_LocationGetSend(node);
            if (msg->x04 == head[18]) {
                return buf_ps_sts;
            }
        }
    }
    if (msg->x1C != 0) {
        MEM_free(0, msg->x1C);
    }
    return buf_ps_sts;
}

int ps_i2D12(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt("Parser : cmk_mbox_send(ps_i2D12) failed");
    }
    return buf_ps_sts;
}

int ps_i2D14(PsIpc *msg) {
    PsIpc m;
    PsIpc d;
    int *p;
    PsLocation *loc;
    int sec;

    sec = 0;
    if (ps_isNotExtSession(msg->x04)) {
        p = (int *)msg->x1C;
        loc = ps_SetLocation(msg->x04, msg->x08, msg->x14, p[0], p[1]);
        if (loc->x0C >= 10) {
            initMPI_SIG_REQUEST_ABORTED(&m);
            m.x04 = msg->x04;
            m.x10 = 1;
            m.x14 = msg->x14;
            ps_sndmsg(&m, 5);
        } else {
            if (icmpstr(p[1], "https://", 8) == 1) {
                sec = 1;
            }
            if (((sec == 1 && Security == 0) || (sec == 0 && Security == 1)) && buf_Message_Show_FLG == 0) {
                if (Security == 0) {
                    if (initMPU_REQ_SHOW_DIALOG(&d, 6) == 0) {
                        ps_halt("initMPU_REQ_SHOW_DIALOG failed");
                    }
                    d.x14 = 0x80000006;
                } else {
                    if (initMPU_REQ_SHOW_DIALOG(&d, 7) == 0) {
                        ps_halt("initMPU_REQ_SHOW_DIALOG failed");
                    }
                    d.x14 = 0x80000007;
                }
                d.x04 = msg->x04;
                ps_sndmsg(&d, 1);
                buf_Message_Show_FLG = 1;
                before_ps_sts = 0x14;
                buf_Message_cnt++;
                if (msg->x1C != 0) {
                    MEM_free(0, msg->x1C);
                }
                return 0x13;
            }
            ps_HeadSend(strlen(loc->buf), loc->buf, ((int *)SaveREF)[0], ((int *)SaveREF)[1], 0, msg->x04, SaveUnitId);
        }
    }
    if (msg->x1C != 0) {
        MEM_free(0, msg->x1C);
    }
    return buf_ps_sts;
}

int *parseDomBuild(int *msg) {
    int *ret;
    void *ctx;
    u16 *buf;
    int n;

    ret = NULL;
    switch (msg[12]) {
    case 0:
        switch (msg[11]) {
        case 0:
            if (gpsCntxtTable == 0) {
                gpsCntxtTable = (int)parseNewMultiCtxt();
            }
            ctx = parseNewCtxt();
            parseRegistBuffer(msg[9], ctx, gpsCntxtTable);
            ret = parseContentStart(ctx, msg);
            break;
        case 1:
            ret = parseContentContinue(parseSearchSessionID(msg[9], gpsCntxtTable), msg);
            break;
        case 2:
            ret = parseContentEnd(parseSearchSessionID(msg[9], gpsCntxtTable), msg);
            break;
        }
        break;
    case 1:
        buf = MEM_malloc(0, msg[6] * 4 + 4);
        n = asciiToUcs2(buf, msg[7], msg[6]);
        buf[n] = 0;
        buf = MEM_realloc(0, buf, n * 2 + 2);
        parseExtStyleSheet(msg[9], buf);
        MEM_free(0, buf);
        ret = MEM_malloc(0, 0x14);
        ret[1] = 0;
        ret[2] = 0;
        ret[3] = 0;
        ret[4] = 0;
        ret[0] = 0;
        break;
    case 2:
        if (gpsCntxtTable == 0) {
            gpsCntxtTable = (int)parseNewMultiCtxt();
        }
        ctx = parseNewCtxt();
        parseRegistBuffer(msg[9], ctx, gpsCntxtTable);
        ret = parseTEXTStart(ctx, msg);
        break;
    case 3:
        if (gpsCntxtTable == 0) {
            gpsCntxtTable = (int)parseNewMultiCtxt();
        }
        ctx = parseNewCtxt();
        parseRegistBuffer(msg[9], ctx, gpsCntxtTable);
        ret = parseBINARYStart(ctx, msg);
        break;
    case 4:
        gpsCntxtTable = parseRegistURI(gpsCntxtTable, msg);
        break;
    case 5:
        gpsCntxtTable = parseReloadURI(gpsCntxtTable, msg);
        break;
    case 6:
        ctx = parseSearchSessionID(msg[9], gpsCntxtTable);
        if (ctx == NULL) {
            return NULL;
        }
        ret = parseContentContinueJS(ctx, msg);
        break;
    case 7:
        ret = parseJSDocumentEncode(parseSearchSessionID(msg[9], gpsCntxtTable), msg);
        break;
    case 8:
        gpsCntxtTable = parseMoveFrontURI(gpsCntxtTable, msg);
        break;
    case 9:
        gpsCntxtTable = parseMoveBackURI(gpsCntxtTable, msg);
        break;
    case 10:
        gpsCntxtTable = parseReplaceURI(gpsCntxtTable, msg);
        break;
    case 11:
        parseSavedContents(gpsCntxtTable, msg);
        return ret;
    case 12:
        parseReleaseResource(gpsCntxtTable, msg);
        break;
    }
    return ret;
}
