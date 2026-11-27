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

int ps_l3912(PsIpc *msg) {
    PsIpc m;
    PsIpc lp;
    PsDomBuild b;
    PsDomResult dflt;
    PsDomResult *r;
    int *node;
    int *buf;

    node = HST_searchSessionIDHistoryNode(msg->x04);
    if (node == NULL) {
        ps_halt("ps_l3912(session ERR) failed");
    }
    DOCUMENT_WRITE = 1;
    b.x[0] = node[1];
    b.x[1] = node[0];
    b.x[2] = node[5];
    b.x[3] = node[4];
    b.x[4] = node[7];
    b.x[5] = node[6];
    b.x[6] = msg->x18;
    b.x[7] = msg->x1C;
    b.x[9] = msg->x04;
    b.x[11] = 1;
    b.x[12] = 6;
    b.x[13] = Accession;
    b.x[14] = 0;
    r = parseDomBuild(&b);
    if (r == NULL) {
        dflt.type = 0;
        dflt.len = 0;
        dflt.data = NULL;
        dflt.x0C = 0;
        dflt.x10 = 0;
        r = &dflt;
    }
    initMPL_REQ_LOAD_PAGE(&lp);
    lp.x04 = msg->x04;
    lp.x10 = 2;
    ps_sndmsg(&lp, 4);
    switch (r->type) {
    case 1:
        buf = MEM_malloc(0, r->len * 2 + 0xC);
        if (buf == NULL) {
            ps_halt("(char*)E_malloc(ps_l3912) failed");
        }
        buf[1] = r->len;
        buf[2] = (int)(buf + 3);
        memcpy(buf + 3, r->data, r->len * 2);
        buf[0] = node[26];
        MEM_free(0, r->data);
        m.type = 2;
        m.x04 = msg->x04;
        m.x08 = 1;
        m.cmd = 0x30B;
        m.x10 = 0;
        m.x14 = 0;
        m.x18 = r->len * 2 + 0xC;
        m.x1C = (int)buf;
        ps_sndmsg(&m, 4);
        break;
    case 0:
        break;
    case 2:
        if (HST_getJSURI(node, HST_getJSURIlen(node)) == NULL) {
            ps_halt("ExternalHistory = NULL\n");
        }
        break;
    case 3:
        if (HST_getCSSURI(node, HST_getCSSURIlen(node)) == NULL) {
            ps_halt("ExternalHistory = NULL\n");
        }
        break;
    default:
        ps_halt("ps_l3912(ERROR VALUE) failed.");
        break;
    }
    if (r != NULL && r != &dflt) {
        MEM_free(0, r);
    }
    MEM_free(0, msg->x1C);
    return buf_ps_sts;
}
