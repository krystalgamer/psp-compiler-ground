/* cflags: -O1 */
#include "common.h"
#include "iom_types.h"
#include "m2c_macros.h"
extern int D_00139D90[];
extern int D_00139DC4[];
int iom_detachCache(void);
int iom_detachCookie(void);
int iom_detachHttpCtx(void);
void MEM_free(M2C_UNK, void *);                  /* extern */
extern void *IOM_CONFIG[12];
extern void *fatalErrMsg;
extern void *fatalErrRepMsg;
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK iom_mfree(int);                             /* extern */


typedef struct IomErr { int code; char *msg; } IomErr;
void iom_end(void);
void iom_finalizeEnvironment(void);
int OS_mq_open(char *name, int flags);
void OS_thread_exit(void *ret);
void iom_sendMsg(IOMMSG *msg, int mq);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_main", D_00139D0C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_main", iom_initializeEnvironment);

#ifndef NULL
#define NULL ((void *)0)
#endif

void iom_finalizeEnvironment(void) {
    void *temp_a1;

    if (IOM_CONFIG[0] != NULL) {
        MEM_free(0, IOM_CONFIG[0]);
    }
    if (IOM_CONFIG[1] != NULL) {
        MEM_free(0, IOM_CONFIG[1]);
    }
    if (IOM_CONFIG[2] != NULL) {
        MEM_free(0, IOM_CONFIG[2]);
    }
    if (IOM_CONFIG[3] != NULL) {
        MEM_free(0, IOM_CONFIG[3]);
    }
    if (IOM_CONFIG[4] != NULL) {
        MEM_free(0, IOM_CONFIG[4]);
    }
    if (IOM_CONFIG[5] != NULL) {
        MEM_free(0, IOM_CONFIG[5]);
    }
    if (IOM_CONFIG[6] != NULL) {
        MEM_free(0, IOM_CONFIG[6]);
    }
    if (IOM_CONFIG[7] != NULL) {
        MEM_free(0, IOM_CONFIG[7]);
    }
    if (IOM_CONFIG[8] != NULL) {
        MEM_free(0, IOM_CONFIG[8]);
    }
    if (IOM_CONFIG[9] != NULL) {
        MEM_free(0, IOM_CONFIG[9]);
    }
    if (IOM_CONFIG[10] != NULL) {
        MEM_free(0, IOM_CONFIG[10]);
    }
    if (IOM_CONFIG[11] != NULL) {
        MEM_free(0, IOM_CONFIG[11]);
    }
    if (fatalErrMsg != NULL) {
        temp_a1 = M2C_FIELD(fatalErrMsg, void **, 0x20);
        if (temp_a1 != NULL) {
            MEM_free(0, temp_a1);
        }
        MEM_free(0, fatalErrMsg);
    }
    if (fatalErrRepMsg != NULL) {
        MEM_free(0, fatalErrRepMsg);
    }
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_main", D_00139D30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_main", D_00139D38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_main", D_00139D44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_main", D_00139D4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_main", D_00139D54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_main", D_00139D5C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_main", D_00139D68);

void iom_halt(void) {
    IOMMSG m;
    int prio;
    int q;
    IOMMSG *f;
    IOMBODY *b;
    IomErr *e;

    if (fatalErrMsg != NULL) {
        f = fatalErrMsg;
        b = &f->b;
        b->x4 = 5;
        b->code = 0xFFFF;
        e = b->data;
        if (e != NULL) {
            e->code = -1;
            e->msg = "AllocationError(IOM)";
        }
        q = OS_mq_open("/tmp/mq_ui", 1);
        OS_mq_send(q, fatalErrMsg, 0x24, 0);
        OS_mq_close(q);
        fatalErrMsg = NULL;
    }
    for (;;) {
        OS_mq_receive(iom.mq, &m, 0x24, &prio);
        if (m.b.x4 == 2 && m.b.code == 1) {
            iom_end();
            iom_finalizeEnvironment();
            OS_thread_exit(NULL);
        } else if (m.b.data != NULL) {
            MEM_free(0, m.b.data);
            m.b.data = NULL;
        }
    }
}

void iom_end(void) {
    IOMMSG *m;
    iom_detachCache();
    iom_detachCookie();
    iom_detachHttpCtx();
    iom.x100 = 0;
    m = fatalErrRepMsg;
    fatalErrRepMsg = NULL;
    m->b.code = 0x21;
    iom_sendMsg(m, iom.mqReply);
    OS_mq_close(iom.mqReply);
    OS_mq_close(iom.mq8);
    OS_mq_close(iom.mq);
}

int iom_translateMsg(IOMMSG *msg) {
    if (msg->b.x4 == 2 && (unsigned int)msg->b.code < 0xD) {
        return D_00139D90[msg->b.code];
    }
    if (msg->b.x4 == 4 && (unsigned int)(msg->b.code - 0x10) < 3) {
        return D_00139DC4[msg->b.code - 0x10];
    }
    if (msg->b.x4 == 5 && (unsigned int)msg->b.code < 0x13) {
        return msg->b.code;
    }
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *iom_newMsg(void *arg0) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = MEM_malloc(0, 0x24);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0) = 0;
        M2C_FIELD(temp_v0, int *, 8) = 0;
        M2C_FIELD(temp_v0, int *, 0xC) = 0;
        M2C_FIELD(temp_v0, int *, 0x10) = 0;
        M2C_FIELD(temp_v0, int *, 0x14) = 0;
        M2C_FIELD(temp_v0, int *, 0x18) = 0;
        M2C_FIELD(temp_v0, int *, 0x1C) = 0;
        M2C_FIELD(temp_v0, int *, 0x20) = 0;
        M2C_FIELD(temp_v0, int *, 4) = 5;
        if (arg0 != NULL) {
            M2C_FIELD(temp_v0, int *, 8) = (int) M2C_FIELD(arg0, int *, 8);
            M2C_FIELD(temp_v0, int *, 0xC) = (int) M2C_FIELD(arg0, int *, 0xC);
            M2C_FIELD(temp_v0, int *, 0x14) = (int) M2C_FIELD(arg0, int *, 0x14);
            M2C_FIELD(temp_v0, int *, 0x18) = (int) M2C_FIELD(arg0, int *, 0x18);
        }
        var_v0 = temp_v0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_freeMsg(void *arg0) {
    int temp_a0;

    if (arg0 != NULL) {
        temp_a0 = M2C_FIELD(arg0, int *, 0x20);
        if (temp_a0 != 0) {
            iom_mfree(temp_a0);
        }
        MEM_free(0, arg0);
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_main", iom_sendMsg);

IOMMSG *iom_recvMsg(int mq) {
    IOMMSG *msg;
    int attr[4];
    unsigned int prio;
    msg = MEM_malloc(0, 0x24);
    OS_mq_getattr(mq, attr);
    OS_mq_receive(mq, msg, 0x24, &prio);
    return msg;
}

IOMMSG *iom_waitMsg(int code, int mq) {
    IOMMSG *msg;
    IOMBODY *b;
    unsigned int prio;
    msg = MEM_malloc(0, 0x24);
    b = &msg->b;
    for (;;) {
        OS_mq_receive(mq, msg, 0x24, &prio);
        if (b->code == code) {
            return msg;
        }
        if (b->data != NULL) {
            MEM_free(0, b->data);
        }
    }
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_main", D_00139D90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_main", D_00139DC4);
