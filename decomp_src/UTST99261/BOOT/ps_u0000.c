/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
extern int IOM_END[9];
extern int mq_iom;
extern void *gPREF_UI;
extern int SAVE_STOP;
extern int GET_HEAD_SESSIONID;
extern int GET_HEAD_STOP;
int ps_sessionGen();                                /* extern */
M2C_UNK setParseMassageToDestTask(M2C_UNK, int, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern int buf_localUI;
extern int buf_sessionUI;
extern int buf_ps_sts;

M2C_UNK ps_dmy();                                   /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

int OS_mq_send(int id, const char *buf, int len, unsigned int prio);
int ps_isMoveHistory(int off, int sid, int local);
void MEM_free(void *, void *p);
void initMPI_SIG_REQUEST_ABORTED(void *arg0);
void ps_sendGetStop(PsIpc *m);
void ps_save(PsIpc *msg, int sid);
void initMPL_REQ_ABORT_PAGE(void *arg0);
int ps_sndmsg(PsIpc *msg, int dest);
int ps_u0000(void *arg0) {
    buf_sessionUI = M2C_FIELD(arg0, int *, 4);
    buf_localUI = M2C_FIELD(arg0, int *, 0x14);
    setParseMassageToDestTask(4, ps_sessionGen(), 0, 0x301, 0, 0, 0, 0);
    return 1;
}

int ps_u0103(PsIpc *msg) {
    buf_sessionUI = msg->x04;
    buf_localUI = msg->x14;
    IOM_END[1] = 2;
    IOM_END[2] = ps_sessionGen();
    IOM_END[3] = 0;
    IOM_END[4] = 1;
    IOM_END[5] = 0;
    IOM_END[6] = 0;
    IOM_END[7] = 0;
    IOM_END[8] = 0;
    OS_mq_send(mq_iom, IOM_END, 0x24, 0);
    return 4;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", D_00137410);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", D_00137430);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", D_00137458);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", D_00137488);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", D_001374B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", D_001374E4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0203);

int ps_u0206(PsIpc *msg) {
    PsIpc m;

    if (ps_isMoveHistory(msg->x10, msg->x04, msg->x14) == 0) {
        if (msg->x1C != 0) {
            MEM_free(0, msg->x1C);
        }
        return buf_ps_sts;
    }
    initMPI_SIG_REQUEST_ABORTED(&m);
    ps_sendGetStop(&m);
    ps_save(msg, 0);
    return 10;
}

int ps_u0207(PsIpc *msg) {
    PsIpc m;

    if (ps_isMoveHistory(msg->x10, msg->x04, msg->x14) == 0) {
        if (msg->x1C != 0) {
            MEM_free(0, msg->x1C);
        }
        return buf_ps_sts;
    }
    initMPL_REQ_ABORT_PAGE(&m);
    ps_sndmsg(&m, 4);
    ps_save(msg, 0);
    return 0xB;
}

int ps_u0208(PsIpc *msg) {
    PsIpc m;

    if (ps_isMoveHistory(msg->x10, msg->x04, msg->x14) == 0) {
        if (msg->x1C != 0) {
            MEM_free(0, msg->x1C);
        }
        return buf_ps_sts;
    }
    initMPI_SIG_REQUEST_ABORTED(&m);
    ps_sendGetStop(&m);
    m.cmd = 0x304;
    m.x04 = 0;
    m.x10 = 0;
    ps_sndmsg(&m, 4);
    ps_save(msg, 0);
    return 0xC;
}

int ps_u0212(PsIpc *msg) {
    PsIpc m;

    if (ps_isMoveHistory(msg->x10, msg->x04, msg->x14) == 0) {
        if (msg->x1C != 0) {
            MEM_free(0, msg->x1C);
        }
        return buf_ps_sts;
    }
    initMPI_SIG_REQUEST_ABORTED(&m);
    ps_sendGetStop(&m);
    m.cmd = 0x304;
    m.x04 = 0;
    m.x10 = 0;
    ps_sndmsg(&m, 4);
    ps_save(msg, 0);
    return 0xC;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0000", ps_u0217);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_u0303(void *arg0) {
    buf_sessionUI = M2C_FIELD(arg0, int *, 4);
    buf_localUI = M2C_FIELD(arg0, int *, 0x14);
    setParseMassageToDestTask(4, ps_sessionGen(), 0, 0x305, M2C_FIELD(arg0, int *, 0x10), 0, 0, 0);
    return 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_u0306(void *arg0) {
    buf_sessionUI = M2C_FIELD(arg0, int *, 4);
    buf_localUI = M2C_FIELD(arg0, int *, 0x14);
    setParseMassageToDestTask(4, ps_sessionGen(), 0, 0x305, M2C_FIELD(arg0, int *, 0x10), 0, 0, 0);
    return buf_ps_sts;
}

int ps_u0506(PsIpc *msg) {
    PsIpc m;

    initMPI_SIG_REQUEST_ABORTED(&m);
    ps_sendGetStop(&m);
    return 10;
}

int ps_u0507(PsIpc *msg) {
    PsIpc m;

    initMPL_REQ_ABORT_PAGE(&m);
    ps_sndmsg(&m, 4);
    return 11;
}

int ps_u0508(PsIpc *msg) {
    PsIpc m;

    initMPI_SIG_REQUEST_ABORTED(&m);
    m.x10 = 1;
    ps_sendGetStop(&m);
    m.cmd = 0x304;
    m.x04 = 0;
    m.x10 = 0;
    ps_sndmsg(&m, 4);
    return 12;
}

int ps_u0509(PsIpc *msg) {
    PsIpc m;
    char *pref;

    initMPI_SIG_REQUEST_ABORTED(&m);
    m.x10 = 0;
    ps_sndmsg(&m, 5);
    pref = gPREF_UI;
    if (pref != NULL) {
        *(int *)(pref + 0x68) = 1;
    }
    SAVE_STOP = 1;
    return 9;
}

int ps_u0512(PsIpc *msg) {
    PsIpc m;

    initMPI_SIG_REQUEST_ABORTED(&m);
    ps_sendGetStop(&m);
    m.cmd = 0x304;
    m.x04 = 0;
    m.x10 = 0;
    ps_sndmsg(&m, 4);
    return 12;
}

int ps_u0514(PsIpc *msg) {
    PsIpc m;

    initMPI_SIG_REQUEST_ABORTED(&m);
    m.x04 = GET_HEAD_SESSIONID;
    m.x10 = 0;
    ps_sndmsg(&m, 5);
    GET_HEAD_STOP = 1;
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int ps_u0703(void) {
    return 3;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_u0803(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_u0806(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_u0903(void) {
    ps_dmy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_u0906(void) {
    ps_dmy();
}
