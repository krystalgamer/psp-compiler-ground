/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
extern int buf_sessionURL;
extern int save_sessionURL;
extern int layout_id;
extern int iom_id;
extern int mq_layout;
extern int mq_iom;
extern int mq_ps;
extern int mq_js;
extern int mq_ps_su;
extern int mq_ui;
extern int SaveURI;
extern int SaveREF;
extern int FATAL_ERR_MSG;
extern int RECIEVE_MSG;
extern void *ContntHeader;
extern int UI_END[9];
extern int Accession;
extern int buf_sessionUI;
extern int buf_localUI;
extern int SSLFlg;
extern int buf_Loding_Stop_FLG;
extern int NOTARGET;
void *HST_searchSessionIDHistoryNode(int);          /* extern */
extern int buf_ps_sts;

M2C_UNK ps_dmy();                                   /* extern */


int OS_mq_getattr(int id, void *);
int OS_mq_setattr(int id, void *, void *);
int OS_mq_receive(int id, char *buf, int len, unsigned int *prio);
void MEM_free(void *, void *p);
int OS_thread_join(int th, void **retp);
void ps_ParseDomBuildFree(void);
void HST_flushHistoryGarbageList(void);
int HST_freeAuthorizationDB(void);
int HST_freeHistory(void);
int HST_httpHeaderFree(int arg);
void ps_freeRecvInfo(void);
int ps_deleteExMsgBoxList(void);
int OS_mq_send(int id, const char *buf, int len, unsigned int prio);
int ps_sndmsg(PsIpc *msg, int dest);
void ps_save(PsIpc *msg, int sid);
void initMPU_SIG_LAYOUT_COMPLETE(void *arg0);
int HST_getHistoryWithOffset(int arg0);
int ps_sessionURL(void);
void initMPI_SIG_REQUEST_ABORTED(void *arg0);
void ps_sendGetStop(PsIpc *m);
void initMPL_REQ_ABORT_PAGE(void *arg0);
void ps_cleaning_mq(int *mq) {
    struct {
        int x00;
        PsIpc body;
    } m;
    int attr[4];

    if (mq == NULL) {
        return;
    }
    for (;;) {
        OS_mq_getattr(*mq, attr);
        attr[0] |= 0x4000;
        OS_mq_setattr(*mq, attr, 0);
        if (OS_mq_receive(*mq, &m, sizeof(m), 0) < 0) {
            attr[0] &= ~0x4000;
            OS_mq_setattr(*mq, attr, 0);
            return;
        }
        if (m.body.x1C != 0) {
            MEM_free(0, m.body.x1C);
        }
        attr[0] &= ~0x4000;
        OS_mq_setattr(*mq, attr, 0);
    }
}

int ps_l1105(void) {
    int st;

    OS_thread_join(layout_id, &st);
    OS_thread_join(iom_id, &st);
    ps_cleaning_mq(&mq_layout);
    ps_cleaning_mq(&mq_iom);
    ps_cleaning_mq(&mq_ps);
    ps_cleaning_mq(&mq_js);
    ps_cleaning_mq(&mq_ps_su);
    ps_ParseDomBuildFree();
    HST_flushHistoryGarbageList();
    HST_freeAuthorizationDB();
    HST_freeHistory();
    ps_FreeLocation();
    if (SaveURI != 0) {
        MEM_free(0, SaveURI);
    }
    if (SaveREF != 0) {
        MEM_free(0, SaveREF);
    }
    if (FATAL_ERR_MSG != 0) {
        MEM_free(0, FATAL_ERR_MSG);
    }
    if (RECIEVE_MSG != 0) {
        MEM_free(0, RECIEVE_MSG);
    }
    if (ContntHeader != NULL) {
        HST_httpHeaderFree(ContntHeader);
    }
    ps_freeRecvInfo();
    ps_deleteExMsgBoxList();
    UI_END[1] = 2;
    UI_END[2] = buf_sessionUI;
    UI_END[3] = 0;
    UI_END[4] = 1;
    UI_END[5] = 0;
    UI_END[6] = buf_localUI;
    UI_END[7] = 0;
    UI_END[8] = 0;
    OS_mq_send(mq_ui, UI_END, 0x24, 0);
    return buf_ps_sts;
}

int ps_l1203(PsIpc *msg) {
    PsIpc m;

    m.type = 2;
    m.x04 = msg->x04;
    m.x08 = 0;
    m.cmd = 0xC;
    m.x10 = msg->x10;
    m.x14 = msg->x14;
    m.x18 = 0;
    m.x1C = 0;
    ps_sndmsg(&m, 1);
    return buf_ps_sts;
}

int ps_l1211(PsIpc *msg) {
    PsIpc m;

    m.type = 2;
    m.x04 = msg->x04;
    m.x08 = 0;
    m.cmd = 0xC;
    m.x10 = msg->x10;
    m.x14 = msg->x14;
    m.x18 = 0;
    m.x1C = 0;
    ps_sndmsg(&m, 1);
    return 3;
}

int ps_l1213(PsIpc *msg) {
    ps_save(msg, 0);
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1307);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l1308(void *arg0) {
    void *temp_v0;

    temp_v0 = HST_searchSessionIDHistoryNode(M2C_FIELD(arg0, int *, 4));
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0x3C) = 5;
    }
    return buf_ps_sts;
}

int ps_l1310(PsIpc *msg) {
    PsIpc m;

    initMPU_SIG_LAYOUT_COMPLETE(&m);
    m.x04 = buf_sessionUI;
    m.x14 = buf_localUI;
    ps_sndmsg(&m, 1);
    SSLFlg = 0;
    buf_Loding_Stop_FLG = 0;
    return 3;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l1312(void *arg0) {
    M2C_FIELD(HST_searchSessionIDHistoryNode(M2C_FIELD(arg0, int *, 4)), int *, 0x3C) = 5;
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_l1403(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_l140E(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_l1413(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_l1503(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_l150D(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_l1513(void) {
    ps_dmy();
}

int ps_l1703(PsIpc *msg) {
    PsIpc m;

    if (msg->x10 != 0 && HST_getHistoryWithOffset(msg->x10) == 0) {
        return buf_ps_sts;
    }
    m.x04 = msg->x04;
    m.x08 = msg->x08;
    m.x10 = msg->x10;
    m.x14 = msg->x14;
    m.x18 = msg->x18;
    m.x1C = msg->x1C;
    m.type = 2;
    m.cmd = 0x14;
    m.x14 = ps_sessionURL();
    ps_sndmsg(&m, 1);
    save_sessionURL = buf_sessionURL;
    return 0x17;
}

int ps_l1706(PsIpc *msg) {
    PsIpc m;

    initMPI_SIG_REQUEST_ABORTED(&m);
    ps_sendGetStop(&m);
    NOTARGET = 0;
    ps_save(msg, 0);
    return 10;
}

int ps_l1707(PsIpc *msg) {
    PsIpc m;

    initMPL_REQ_ABORT_PAGE(&m);
    ps_sndmsg(&m, 4);
    NOTARGET = 0;
    ps_save(msg, 0);
    return 11;
}

int ps_l1708(PsIpc *msg) {
    PsIpc m;

    initMPI_SIG_REQUEST_ABORTED(&m);
    ps_sendGetStop(&m);
    m.cmd = 0x304;
    m.x04 = 0;
    m.x10 = 0;
    ps_sndmsg(&m, 4);
    NOTARGET = 0;
    ps_save(msg, 0);
    return 12;
}

int ps_l1717(PsIpc *msg) {
    NOTARGET = 0;
    ps_save(msg, 0);
    return 0x17;
}

