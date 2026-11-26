/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
extern int buf_sessionUI;
extern int buf_localUI;
extern int SAVE_STOP;
extern int On_Save;
extern void *gPREF_UI;
extern int mq_js;
extern int mq_layout;
extern int LAYOUT_END[9];
extern char D_00137964[];
extern char D_00137A54[];
extern char D_00137CC0[];
extern char D_00137CE8[];
extern char D_00137D90[];
extern int before_ps_sts;
extern int buf_Message_cnt;
extern int buf_ps_sts;
M2C_UNK ps_setExMsg(int, int);                      /* extern */
extern int D_00584FB8;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
extern void *rcvInfo;

M2C_UNK ps_i2314();                                 /* extern */
M2C_UNK ps_i2606();                                 /* extern */


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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_l3912);

int ps_i2002(PsIpc *msg) {
    PsIpc m;

    m.type = 2;
    m.x04 = buf_sessionUI;
    m.x08 = 0;
    m.cmd = 0;
    m.x10 = 0;
    m.x14 = buf_localUI;
    m.x18 = msg->x18;
    m.x1C = msg->x1C;
    ps_sndmsg(&m, 1);
    return 3;
}

int ps_i2104(PsIpc *msg) {
    LAYOUT_END[1] = 2;
    LAYOUT_END[2] = ps_sessionGen();
    LAYOUT_END[3] = 0;
    LAYOUT_END[4] = 0x302;
    LAYOUT_END[5] = 0;
    LAYOUT_END[6] = 0;
    LAYOUT_END[7] = 0;
    LAYOUT_END[8] = 0;
    OS_mq_send(mq_layout, LAYOUT_END, 0x24, 0);
    return 5;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2206);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2208);

int ps_i2209(PsIpc *msg) {
    PsIpc m;
    char *pref;

    initMPU_SIG_RECV_COMPLETE(&m);
    m.x04 = buf_sessionUI;
    m.x10 = 1;
    m.x14 = buf_localUI;
    ps_sndmsg(&m, 1);
    pref = gPREF_UI;
    if (pref != NULL) {
        *(int *)(pref + 0x68) = 0;
    }
    On_Save = 0;
    SAVE_STOP = 0;
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i220A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i220C);

int ps_i2212(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt(D_00137964);
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_i2214(void) {
    ps_i2314();
}

int ps_i2215(PsIpc *msg) {
    PsIpc m;

    m.type = 2;
    m.x04 = 0;
    m.x08 = 0;
    m.cmd = 0x10;
    m.x10 = 1;
    m.x14 = 0;
    m.x18 = 0;
    m.x1C = 0;
    ps_sndmsg(&m, 1);
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2219);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i221A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2306);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2308);

int ps_i2309(PsIpc *msg) {
    PsIpc m;

    if (SAVE_STOP != 0) {
        return buf_ps_sts;
    }
    initMPU_SIG_RECV_COMPLETE(&m);
    m.x04 = buf_sessionUI;
    m.x14 = buf_localUI;
    ps_sndmsg(&m, 1);
    On_Save = 0;
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i230A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i230C);

int ps_i2312(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt(D_00137A54);
    }
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2314);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ps_i2315(void) {
    return 3;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2319);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i231A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2406);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2412);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2414);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2414_auth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i241A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2606);

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_i2607(void) {
    ps_i2606();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_i2608(void) {
    ps_i2606();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2609);

int ps_i2612(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt(D_00137CC0);
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_i2614(int arg0) {
    ps_setExMsg(D_00584FB8, arg0);
    return buf_ps_sts;
}

int ps_i261A(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt(D_00137CC0);
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_freeRecvInfo(void) {
    void *temp_s0;
    void *var_a1;

    var_a1 = rcvInfo;
    if (var_a1 != NULL) {
        do {
            temp_s0 = M2C_FIELD(var_a1, void **, 0x14);
            MEM_free(0, var_a1);
            var_a1 = temp_s0;
        } while (temp_s0 != NULL);
    }
    rcvInfo = NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_setRecvInfo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_getRecvRate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2906);

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
        ps_halt(D_00137CE8);
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ps_i2914(int arg0) {
    ps_setExMsg(D_00584FB8, arg0);
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2D06);

int ps_i2D12(PsIpc *msg) {
    struct {
        int x00;
        PsIpc body;
    } m;

    m.body = *msg;
    if (OS_mq_send(mq_js, &m, sizeof(m), 0) < 0) {
        ps_halt(D_00137D90);
    }
    return buf_ps_sts;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2D14);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", parseDomBuild);
