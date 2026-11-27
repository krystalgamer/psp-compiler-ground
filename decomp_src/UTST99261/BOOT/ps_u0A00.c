/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
extern int buf_sessionUI;
extern int buf_localUI;
extern int buf_ps_sts;



extern int Security;
extern int buf_Message_Show_FLG;
extern int before_ps_sts;
extern int buf_Message_cnt;
void sendMPL_REQ_DATA_ATTR(PsIpc *msg) {
    PsIpc m;

    buf_sessionUI = msg->x04;
    buf_localUI = msg->x14;
    m.type = 2;
    m.x04 = ps_sessionGen();
    m.x08 = 0;
    m.cmd = 0x307;
    m.x10 = 0;
    m.x14 = 0;
    m.x18 = msg->x18;
    m.x1C = msg->x1C;
    ps_sndmsg(&m, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_u0A03(PsIpc *msg) {
    sendMPL_REQ_DATA_ATTR(msg);
    return 0xF;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_u0A06(PsIpc *msg) {
    sendMPL_REQ_DATA_ATTR(msg);
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", ps_u0B03);

int ps_u0C03(PsIpc *msg) {
    PsIpc m;
    void *node;
    int len;
    int *buf;

    node = HST_getHeadHistoryNode();
    if (node != NULL) {
        len = HST_getTitlelen(node);
        buf = MEM_malloc(0, len + 4);
        if (buf == NULL) {
            ps_halt("(char*)E_malloc(ps_u0C03) failed");
        }
        memset(buf, 0, len + 4);
        buf[0] = len;
        if (len != 0) {
            memcpy(buf + 1, HST_getTitle(node), len);
        }
        m.type = 2;
        m.x04 = msg->x04;
        m.x08 = msg->x08;
        m.cmd = 0xD;
        m.x10 = msg->x10;
        m.x14 = msg->x14;
        m.x18 = len + 4;
        m.x1C = (int)buf;
        ps_sndmsg(&m, 1);
    }
    return buf_ps_sts;
}

int getBuffSize(int n) {
    int r;

    r = 0;
    if (n % 4 != 0) {
        if (n / 4 * 4 == n - 1) {
            r = 3;
        } else if (n % 4 == 2) {
            r = 2;
        } else {
            r = 1;
        }
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", ps_u0E13);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ps_u3103(void) {
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_u0A00", ps_u3216);

int ps_u3517(PsIpc *msg) {
    PsIpc d;
    int *p;
    char *s;
    int sec;

    ps_saveCacheMode(1);
    ps_JSMailBoxfree();
    ps_FreeLocation();
    p = (int *)msg->x1C;
    s = MEM_malloc(0, p[3] + 1);
    memset(s, 0, p[3] + 1);
    memcpy(s, (void *)p[4], p[3]);
    sec = icmpstr(s, "https://", 8);
    MEM_free(0, s);
    if (((sec == 1 && Security == 0) || (sec == 0 && Security == 1)) && buf_Message_Show_FLG == 0) {
        if (Security == 0) {
            if (initMPU_REQ_SHOW_DIALOG(&d, 6) == 0) {
                ps_halt("initMPU_REQ_SHOW_DIALOG failed");
            }
            d.x14 = 0x80000002;
        } else {
            if (initMPU_REQ_SHOW_DIALOG(&d, 7) == 0) {
                ps_halt("initMPU_REQ_SHOW_DIALOG failed");
            }
            d.x14 = 0x80000003;
        }
        d.x04 = msg->x04;
        ps_sndmsg(&d, 1);
        ps_save(msg, 0);
        buf_Message_Show_FLG = 1;
        before_ps_sts = buf_ps_sts;
        buf_Message_cnt++;
        return 0x13;
    }
    return ps_submit(msg);
}

int ps_l1001(void) {
    PsIpc m;

    m.type = 2;
    m.x04 = ps_sessionGen();
    m.x08 = 0;
    m.cmd = 0;
    m.x10 = 0;
    m.x14 = 0;
    m.x18 = 0;
    m.x1C = 0;
    ps_sndmsg(&m, 5);
    return 2;
}

