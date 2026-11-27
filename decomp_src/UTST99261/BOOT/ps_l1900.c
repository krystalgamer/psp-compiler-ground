/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
extern int buf_sessionURL;
extern int save_sessionURL;
extern int buf_sessionUI;
extern int buf_localUI;
extern int buf_ps_sts;



void sendMPU_RPL_DATA_ATTR(PsIpc *msg) {
    PsIpc m;

    m.type = 2;
    m.x04 = buf_sessionUI;
    m.x08 = 0;
    m.cmd = 0xB;
    m.x10 = msg->x10;
    m.x14 = buf_localUI;
    m.x18 = msg->x18;
    m.x1C = msg->x1C;
    ps_sndmsg(&m, 1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l1903(PsIpc *msg) {
    sendMPU_RPL_DATA_ATTR(msg);
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_l190F(PsIpc *msg) {
    sendMPU_RPL_DATA_ATTR(msg);
    return 3;
}

int ps_l1913(PsIpc *msg) {
    ps_save(msg, 0);
    return buf_ps_sts;
}

int ps_l1A03(PsIpc *msg) {
    PsIpc m;

    buf_sessionUI = msg->x04;
    buf_localUI = msg->x14;
    m.x04 = msg->x04;
    m.x08 = msg->x08;
    m.x10 = msg->x10;
    m.x14 = msg->x14;
    m.x18 = msg->x18;
    m.x1C = msg->x1C;
    m.type = 2;
    m.cmd = 0x15;
    m.x14 = ps_sessionURL();
    ps_sndmsg(&m, 1);
    save_sessionURL = buf_sessionURL;
    return 0x17;
}

int ps_l1A06(PsIpc *msg) {
    PsIpc m;

    initMPI_SIG_REQUEST_ABORTED(&m);
    ps_sendGetStop(&m);
    ps_save(msg, 0);
    return 10;
}

int ps_l1A07(PsIpc *msg) {
    PsIpc m;

    initMPL_REQ_ABORT_PAGE(&m);
    ps_sndmsg(&m, 4);
    ps_save(msg, 0);
    return 11;
}

int ps_l1A08(PsIpc *msg) {
    PsIpc m;

    initMPI_SIG_REQUEST_ABORTED(&m);
    ps_sendGetStop(&m);
    m.cmd = 0x304;
    m.x04 = 0;
    m.x10 = 0;
    ps_sndmsg(&m, 4);
    ps_save(msg, 0);
    return 12;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l1900", ps_l1B12);

