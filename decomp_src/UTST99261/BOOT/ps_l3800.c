/* cflags: -O1 */
#include "common.h"
#include "parse_ps.h"
#include "m2c_macros.h"
extern int SSLFlg;
extern int SSL_Next_STS;
extern int Accession;
extern int SaveURI;
extern int SaveREF;
extern int Layout_Cont;
extern int psCacheMode;
extern char D_00137C10[];
extern char D_001379EC[];
extern char D_00137A7C[];
extern char D_00137AAC[];
int ps_i241A(PsIpc *msg);
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

int ps_i2306(PsIpc *msg) {
    PsIpc m;
    PsDomBuild b;
    int *node;
    void *r;

    node = HST_searchSessionIDHistoryNode(msg->x04);
    if (node == NULL) {
        if (msg->x18 != 0) {
            MEM_free(0, msg->x1C);
        }
        return buf_ps_sts;
    }
    node[15] = 3;
    b.x[0] = node[1];
    b.x[1] = node[0];
    b.x[2] = node[5];
    b.x[3] = node[4];
    b.x[4] = node[7];
    b.x[5] = node[6];
    b.x[6] = 0x1A;
    b.x[7] = (int)D_001379EC;
    b.x[9] = msg->x04;
    b.x[10] = 0;
    b.x[11] = 0;
    b.x[12] = 0;
    b.x[13] = Accession;
    r = parseDomBuild(&b);
    if (r != NULL) {
        MEM_free(0, r);
    }
    sendMPL_REQ_LOAD_PAGE(&m, msg->x04);
    return 7;
}

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

int ps_i2319(PsIpc *msg) {
    PsIpc c;
    PsIpc a;
    PsDomBuild b;
    void *node;
    int *buf;
    int len;
    void *r;

    MEM_free(0, SaveURI);
    MEM_free(0, SaveREF);
    SaveURI = 0;
    SaveREF = 0;
    node = HST_getHeadHistoryNode();
    if (node == NULL) {
        ps_halt(D_00137A7C);
    }
    len = HST_getCurURIlen(node);
    buf = MEM_malloc(0, len + 4);
    if (buf == NULL) {
        ps_halt(D_00137AAC);
    }
    buf[0] = len;
    memcpy(buf + 1, HST_getCurURI(node), buf[0]);
    b.x[0] = buf[0];
    b.x[1] = (int)(buf + 1);
    b.x[2] = 0;
    b.x[3] = 0;
    b.x[4] = 0;
    b.x[5] = 0;
    b.x[6] = 0;
    b.x[7] = 0;
    b.x[8] = 0;
    b.x[9] = 0;
    b.x[11] = 0;
    b.x[12] = 0xB;
    b.x[13] = 0;
    r = parseDomBuild(&b);
    if (r != NULL) {
        MEM_free(0, r);
    }
    ps_getsend(node, psCacheMode, 0, 0);
    sendStart(&a, &c, buf);
    Layout_Cont = 0;
    ps_freeRecvInfo();
    return 6;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i231A);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2406);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2414);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i2414_auth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_i241A);

int ps_i2606(PsIpc *msg) {
    PsIpc m;
    int *info;
    int d;

    d = msg->x1C;
    if (d != 0) {
        info = MEM_calloc(0, 0xC);
        ps_setRecvInfo(msg->x04, d);
        info[0] = ps_getRecvRate(&info[1], &info[2]);
        m.type = 2;
        m.x04 = buf_sessionUI;
        m.x08 = 0;
        m.cmd = 4;
        m.x10 = 0;
        m.x14 = buf_localUI;
        m.x18 = 0xC;
        m.x1C = (int)info;
        ps_sndmsg(&m, 1);
    }
    if (msg->x18 != 0) {
        MEM_free(0, msg->x1C);
    }
    return buf_ps_sts;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_i2607(PsIpc *msg) {
    ps_i2606(msg);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ps_i2608(PsIpc *msg) {
    ps_i2606(msg);
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
    RecvInfo *p;
    RecvInfo *next;

    p = rcvInfo;
    while (p != NULL) {
        next = p->next;
        MEM_free(0, p);
        p = next;
    }
    rcvInfo = NULL;
}

void ps_setRecvInfo(int id, int *data) {
    RecvInfo *p;
    RecvInfo *prev;

    prev = NULL;
    for (p = rcvInfo; p != NULL; p = p->next) {
        if (p->id == id) {
            break;
        }
        prev = p;
    }
    if (p == NULL) {
        p = MEM_malloc(0, sizeof(RecvInfo));
        if (p == NULL) {
            return;
        }
        if (prev != NULL) {
            prev->next = p;
        }
        if (rcvInfo == NULL) {
            rcvInfo = p;
        }
        p->d[0] = 0;
        p->d[1] = 0;
        p->d[2] = 0;
        p->d[3] = 0;
        p->next = NULL;
        p->id = id;
    }
    p->d[0] = data[0];
    p->d[1] = data[1];
    p->d[2] = data[2];
    p->d[3] = data[3];
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/ps_l3800", ps_getRecvRate);

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
