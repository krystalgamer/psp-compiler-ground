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
