/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
extern signed char D_00133950;


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
void MEM_free();
int utf8ToUcs2();
int OS_mq_send();

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int type;                   /* 0xC */
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
} LOBODY;

typedef struct {
    int hdr;
    LOBODY body;
} MQMSG;

typedef struct {
    u8 unk0[0x50];
    MQMSG *tmplJS;              /* 0x50 */
    u8 unk54[0x20];
    MQMSG *tmplUI;              /* 0x74 */
    u8 unk78[0x4];
    int mqJS;                   /* 0x7C */
    u8 unk80[0x8];
    int mq88;                   /* 0x88 */
    int mq8C;                   /* 0x8C */
} SLOGLOBAL;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int type;                   /* 0xC */
    int sent;                   /* 0x10 */
    int unk14;
    int unk18;
    int doc;                    /* 0x1C */
    int unk20;
    LOBODY body;                /* 0x24 */
} SNODE;

extern unsigned char REQUEST_LLIST;
void *getNextLLIST();
void delLLIST();
int countRequestedLLIST();
void msgSendToOtherTask(LOBODY *msg, int mq);

extern SLOGLOBAL lo_global;
unsigned int strlen(const char *s);

void *make_layoutMsg_template(int arg0, int arg1, int arg2) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = MEM_malloc(0, 0x44);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        memset(temp_v0, 0, 0x44U);
        M2C_FIELD(temp_v0, int *, 0xC) = arg0;
        M2C_FIELD(temp_v0, int *, 0x24) = 4;
        M2C_FIELD(temp_v0, int *, 0x28) = arg1;
        M2C_FIELD(temp_v0, int *, 0x30) = arg2;
        var_v0 = temp_v0;
    }
    return var_v0;
}

void msgSendToOtherTask(LOBODY *msg, int mq) {
    MQMSG m;

    if (mq == lo_global.mqJS) {
        if (msg->type == 0x11) {
            m = *lo_global.tmplJS;
        }
    } else if (msg->type == 0x403) {
        m = *lo_global.tmplUI;
    }
    m.body = *msg;
    OS_mq_send(mq, &m, sizeof(MQMSG), 0);
}

void msgSend(void) {
    SNODE *n;
    SNODE *next;
    LOBODY *b;
    int *cnt;

    n = getNextLLIST(&REQUEST_LLIST, NULL);
    while (n != NULL) {
        if (n->sent == 1) {
            n = getNextLLIST(&REQUEST_LLIST, n);
            continue;
        }
        b = &n->body;
        switch (n->type) {
        case 2:
            msgSendToOtherTask(b, lo_global.mqJS);
            next = getNextLLIST(&REQUEST_LLIST, n);
            delLLIST(&REQUEST_LLIST, n);
            MEM_free(0, n);
            n = next;
            break;
        case 5:
            if (b != NULL) {
                cnt = (int *)b->unk1C;
                if (cnt != NULL) {
                    *cnt = countRequestedLLIST(&REQUEST_LLIST, n->doc);
                }
            }
            msgSendToOtherTask(b, lo_global.mq88);
            n->sent = 1;
            n = getNextLLIST(&REQUEST_LLIST, n);
            break;
        case 8:
            msgSendToOtherTask(b, lo_global.mq8C);
            next = getNextLLIST(&REQUEST_LLIST, n);
            delLLIST(&REQUEST_LLIST, n);
            MEM_free(0, n);
            n = next;
            break;
        default:
            return;
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LP1(void *arg0) {
    M2C_FIELD(make_layoutMsg_template(2, M2C_FIELD(arg0, int *, 4), 0x10), int *, 0x34) = (int) M2C_FIELD(arg0, int *, 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LP2(void *arg0) {
    make_layoutMsg_template(2, M2C_FIELD(arg0, int *, 4), 0x11);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LP3(void *arg0, int arg1) {
    M2C_FIELD(make_layoutMsg_template(2, M2C_FIELD(arg0, int *, 4), 0x12), int *, 0x34) = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int make_msg_LP4(int arg0) {
    int temp_v0;
    int var_v1;

    temp_v0 = make_layoutMsg_template(2, arg0, 0x13);
    var_v1 = 0;
    if (temp_v0 != 0) {
        var_v1 = temp_v0;
    }
    return var_v1;
}

void *make_msg_LP7(void *msg, char *url) {
    int size;
    int *d;
    int n;
    void *m;

    if (msg == NULL || url == NULL) {
        return NULL;
    }
    size = strlen(url) + 9;
    d = MEM_malloc(0, size);
    if (d == NULL) {
        return NULL;
    }
    memset(d, 0, size);
    n = strlen(url);
    d[0] = n;
    d[1] = (int)(d + 2);
    memcpy(d + 2, url, n);
    m = make_layoutMsg_template(2, M2C_FIELD(msg, int *, 4), 0x16);
    M2C_FIELD(m, int *, 0x38) = M2C_FIELD(msg, int *, 0x14);
    M2C_FIELD(m, int *, 0x3C) = size;
    M2C_FIELD(m, int **, 0x40) = d;
    return m;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_sndmsg", make_msg_LP8);

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LP10(int arg0, int arg1, int arg2) {
    void *temp_v0;

    temp_v0 = make_layoutMsg_template(2, 0, 0x19);
    M2C_FIELD(temp_v0, int *, 0x34) = (int) (arg0 != 1);
    M2C_FIELD(temp_v0, int *, 0x3C) = arg2;
    M2C_FIELD(temp_v0, int *, 0x40) = arg1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_sndmsg", make_msg_LP11);

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LP12(void *arg0) {
    M2C_FIELD(make_layoutMsg_template(2, M2C_FIELD(arg0, int *, 4), 0x1B), int *, 0x40) = (int) M2C_FIELD(arg0, int *, 0x1C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LP13(void *arg0) {
    make_layoutMsg_template(2, M2C_FIELD(arg0, int *, 4), 0x1C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LP16(void *arg0) {
    void *temp_v0;

    temp_v0 = make_layoutMsg_template(2, M2C_FIELD(arg0, int *, 4), 0x1F);
    M2C_FIELD(temp_v0, int *, 0x34) = (int) M2C_FIELD(arg0, int *, 0x10);
    M2C_FIELD(temp_v0, int *, 0x3C) = (int) M2C_FIELD(arg0, int *, 0x18);
    M2C_FIELD(temp_v0, int *, 0x40) = (int) M2C_FIELD(arg0, int *, 0x1C);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_sndmsg", make_msg_LP17);

void *make_msg_LP18(void *msg) {
    void *m;
    int *d;
    void *buf;

    m = make_layoutMsg_template(2, M2C_FIELD(msg, int *, 4), 0x39);
    d = M2C_FIELD(msg, int **, 0x1C);
    M2C_FIELD(m, int *, 0x3C) = *d * 2;
    buf = MEM_malloc(0, *d * 2);
    memcpy(buf, d + 1, *d * 2);
    M2C_FIELD(m, void **, 0x40) = buf;
    MEM_free(0, M2C_FIELD(msg, void **, 0x1C));
    return m;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *make_msg_LP19(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    void *temp_v0;
    void *temp_v0_2;
    void *var_v0;

    temp_v0 = make_layoutMsg_template(2, arg0, 0x3A);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        temp_v0_2 = MEM_malloc(0, 0x18);
        M2C_FIELD(temp_v0_2, int *, 0) = arg1;
        M2C_FIELD(temp_v0_2, int *, 4) = arg2;
        M2C_FIELD(temp_v0_2, int *, 8) = arg3;
        M2C_FIELD(temp_v0_2, int *, 0xC) = arg4;
        M2C_FIELD(temp_v0_2, int *, 0x10) = arg5;
        M2C_FIELD(temp_v0_2, int *, 0x14) = arg6;
        M2C_FIELD(temp_v0, int *, 0x3C) = 0x18;
        M2C_FIELD(temp_v0, void **, 0x40) = temp_v0_2;
        var_v0 = temp_v0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
char *strcpy(char *d, const char *s);

void *make_msg_LP20(int arg0, int arg1, int arg2, int arg3, signed char *arg4) {
    signed char *var_a1;
    unsigned int var_s3;
    void *temp_v0;
    void *temp_v0_2;
    void *var_v0;

    temp_v0 = make_layoutMsg_template(2, arg0, 0x3B);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        var_s3 = 0;
        if (arg4 != NULL) {
            var_s3 = strlen(arg4);
        }
        temp_v0_2 = MEM_malloc(0, var_s3 + 0x15);
        M2C_FIELD(temp_v0_2, int *, 0) = arg1;
        M2C_FIELD(temp_v0_2, int *, 4) = arg2;
        M2C_FIELD(temp_v0_2, int *, 8) = arg3;
        M2C_FIELD(temp_v0_2, unsigned int *, 0xC) = var_s3;
        M2C_FIELD(temp_v0_2, signed char **, 0x10) = (signed char *) (temp_v0_2 + 0x14);
        var_a1 = arg4;
        if (arg4 == NULL) {
            var_a1 = &D_00133950;
        }
        strcpy(M2C_FIELD(temp_v0_2, signed char **, 0x10), var_a1);
        M2C_FIELD(temp_v0, int *, 0x3C) = (int) (var_s3 + 0x15);
        M2C_FIELD(temp_v0, void **, 0x40) = temp_v0_2;
        var_v0 = temp_v0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_sndmsg", make_msg_LP21);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_sndmsg", D_00133950);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_sndmsg", make_msg_LP22);

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LP23(int arg0) {
    make_layoutMsg_template(2, arg0, 0x3E);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LI1(void) {
    make_layoutMsg_template(5, 0, 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LI2(int arg0) {
    make_layoutMsg_template(5, arg0, 0x11);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LI3(void) {
    make_layoutMsg_template(5, 0, 0x12);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LJ6(void *arg0, int arg1) {
    M2C_FIELD(make_layoutMsg_template(8, M2C_FIELD(arg0, int *, 4), 0x406), int *, 0x34) = (int) (arg1 == 0);
}

void *make_msg_LJ7(void *msg) {
    void *m;
    u8 *d;
    int len;
    int size;
    int *buf;

    size = 0;
    buf = NULL;
    m = make_layoutMsg_template(8, M2C_FIELD(msg, int *, 4), 0x407);
    M2C_FIELD(m, int *, 0x34) = M2C_FIELD(msg, int *, 0x10);
    d = M2C_FIELD(msg, u8 **, 0x1C);
    if (*(int *)d == 2) {
        len = ((int *)d)[1];
        d += (len + 3) / 4 * 4 + 8;
        len = *(int *)d;
        d += 4;
        if (len > 0) {
            size = len * 2 + 6;
            buf = MEM_malloc(0, size);
            buf[0] = utf8ToUcs2((u16 *)(buf + 1), d, len);
            ((u16 *)(buf + 1))[buf[0]] = 0;
        }
    }
    M2C_FIELD(m, int *, 0x3C) = size;
    M2C_FIELD(m, int **, 0x40) = buf;
    return m;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LJ8(void *arg0, int arg1) {
    M2C_FIELD(make_layoutMsg_template(8, M2C_FIELD(arg0, int *, 4), 0x408), int *, 0x34) = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void make_msg_LJ9(void *arg0, int arg1) {
    M2C_FIELD(make_layoutMsg_template(8, M2C_FIELD(arg0, int *, 4), 0x409), int *, 0x40) = arg1;
}
