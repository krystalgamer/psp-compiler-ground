/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
extern int buf_sessionUI;
extern int buf_localUI;
extern int SSLFlg;
extern int buf_Loding_Stop_FLG;
extern int NOTARGET;
void *HST_searchSessionIDHistoryNode(int);          /* extern */
extern int buf_ps_sts;

M2C_UNK ps_dmy();                                   /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_cleaning_mq);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1105);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", ps_l1703);

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

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1100", D_00135C58);
