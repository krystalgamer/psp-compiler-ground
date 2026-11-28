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
        ps_halt("Parser : cmk_mbox_send(ps_i2412) failed");
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_i2914(int arg0) {
    ps_setExMsg(EX_MSG_BOX_NO[1], arg0);
    return buf_ps_sts;
}
