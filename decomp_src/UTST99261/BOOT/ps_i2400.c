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
extern char D_00137C10[];
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
extern int D_00584FB8;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */

M2C_UNK ps_i2314();                                 /* extern */

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", D_00137B18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", D_00137B1C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", D_00137B20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", D_00137B44);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", ps_i2406);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", D_00137BF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", D_00137C10);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", ps_i2414_auth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_i2400", ps_i241A);
