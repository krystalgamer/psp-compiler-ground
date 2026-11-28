/* cflags: -O1 */
#include "common.h"
#include "iom_global.h"
#include "m2c_macros.h"
int iom_translateMsg(void *msg);
M2C_UNK iom_sendMsg(void *, int);                   /* extern */


int UTL_mfileread(void *f, void *buf, int n);
typedef struct { int len; char *str; } LOCD;
typedef struct { int x0; int type; int x8; int xC; int code; int a1; int x18; int size; LOCD *data; } IMSGL;
unsigned int strlen(const char *s);
void *memcpy(void *d, const void *s, unsigned int n);
typedef struct { int code; char *msg; } IERRT;
extern const IERRT D_0013F41C[];
extern const IERRT D_0013F46C[];
extern int G_sendflag;
char *strcpy(char *d, const char *s);
typedef struct { int x0; int type; int x8; int xC; int code; int a1; int x18; int size; char *data; } IMSGF;
int iom_sendRequestFailed(IMSGF *msg, int err) {
    unsigned int idx = -0x12C - err;
    const IERRT *t;
    int mq;
    int code;
    IMSGF *m;

    if (idx >= 10) {
        return 0;
    }
    if (msg->type == 2) {
        t = D_0013F41C;
        mq = iom.mqReply;
        code = 0x22;
    } else if (msg->type == 4) {
        t = D_0013F41C;
        mq = iom.mq8;
        code = 0x504;
    } else if (iom_translateMsg(msg) == 0xF || iom_translateMsg(msg) == 0x10 || iom_translateMsg(msg) == 0x11) {
        t = D_0013F46C;
        mq = iom.mqReply;
        code = 0x22;
    } else {
        return 0;
    }
    m = iom_newMsg(msg);
    if (m == NULL) {
        return -0x12D;
    }
    m->code = code;
    m->a1 = t[idx].code;
    m->size = strlen(t[idx].msg);
    m->data = iom_malloc(m->size + 1);
    if (m->data == NULL) {
        iom_freeMsg(m);
        return -0x12D;
    }
    strcpy(m->data, t[idx].msg);
    iom_sendMsg(m, mq);
    G_sendflag = 1;
    return 0;
}

int iom_sendRequestComplete(void *msg) {
    int mq;
    int code;
    void *m;
    if (M2C_FIELD(msg, int *, 4) == 2) {
        mq = iom.mqReply;
        code = 0x23;
    } else if (M2C_FIELD(msg, int *, 4) == 4) {
        mq = iom.mq8;
        code = 0x502;
    } else if (iom_translateMsg(msg) == 0xF) {
        mq = iom.mqReply;
        code = 0x23;
    } else {
        return 0;
    }
    m = iom_newMsg(msg);
    if (m == NULL) {
        return -0x12D;
    }
    M2C_FIELD(m, int *, 0x10) = code;
    M2C_FIELD(m, int *, 0x14) = 0;
    iom_sendMsg(m, mq);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_sendReceiveStatus(void *arg0, int arg1, int arg2, int arg3) {
    int temp_v0_2;
    int var_v0;
    void *temp_s2;
    void *temp_v0;

    temp_s2 = M2C_FIELD(arg0, void **, 0x20);
    temp_v0 = iom_newMsg(arg0);
    var_v0 = -0x12D;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0x10) = 0x26;
        M2C_FIELD(temp_v0, int *, 0x14) = arg1;
        M2C_FIELD(temp_v0, int *, 0x1C) = 0x10;
        temp_v0_2 = iom_malloc(0x10);
        M2C_FIELD(temp_v0, int *, 0x20) = temp_v0_2;
        if (temp_v0_2 == 0) {
            iom_freeMsg(temp_v0);
            return -0x12D;
        }
        M2C_FIELD(M2C_FIELD(temp_v0, int *, 0x20), int *, 0) = arg2;
        M2C_FIELD(M2C_FIELD(temp_v0, int *, 0x20), int *, 4) = arg3;
        M2C_FIELD(M2C_FIELD(temp_v0, int *, 0x20), int *, 8) = (int) M2C_FIELD(temp_s2, int *, 0);
        M2C_FIELD(M2C_FIELD(temp_v0, int *, 0x20), int *, 0xC) = (int) M2C_FIELD(temp_s2, int *, 4);
        iom_sendMsg(temp_v0, iom.mqReply);
        var_v0 = 0;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}

int iom_sendContent(void *msg, int a1, void *mf, int len) {
    int mq;
    int code;
    void *m;

    if (len <= 0) {
        return 0;
    }
    if (M2C_FIELD(msg, int *, 4) == 2) {
        mq = iom.mqReply;
        if (M2C_FIELD(msg, int *, 0x10) == 2) {
            code = 0x24;
        } else if (M2C_FIELD(msg, int *, 0x10) == 3) {
            code = 0x25;
        } else if (M2C_FIELD(msg, int *, 0x10) == 10) {
            code = 0x2A;
        } else {
            return 0;
        }
    } else if (M2C_FIELD(msg, int *, 4) == 4) {
        mq = iom.mq8;
        if (M2C_FIELD(msg, int *, 0x10) == 0x10) {
            code = 0x501;
        } else if (M2C_FIELD(msg, int *, 0x10) == 0x12) {
            code = 0x503;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
    m = iom_newMsg(msg);
    if (m == NULL) {
        return -0x12D;
    }
    M2C_FIELD(m, int *, 0x10) = code;
    M2C_FIELD(m, int *, 0x14) = a1;
    M2C_FIELD(m, void **, 0x20) = iom_malloc(len);
    if (M2C_FIELD(m, void **, 0x20) == NULL) {
        iom_freeMsg(m);
        return -0x12D;
    }
    M2C_FIELD(m, int *, 0x1C) = UTL_mfileread(mf, M2C_FIELD(m, void **, 0x20), len);
    iom_sendMsg(m, mq);
    return 0;
}

int iom_sendLocation(IMSGL *msg, int a1, char *url, char *url2) {
    int code;
    int mq;
    IMSGL *m;

    if (msg->type == 2 || (msg->type == 5 && iom_translateMsg(msg) == 0xF)) {
        code = 0x2D;
        mq = iom.mqReply;
    } else if (msg->type == 4) {
        code = 0x506;
        mq = iom.mq8;
    } else {
        return -0x12E;
    }
    m = iom_newMsg(msg);
    if (m == NULL) {
        return -0x12D;
    }
    m->code = code;
    m->a1 = a1;
    m->size = strlen(url) + 8;
    m->data = iom_malloc(m->size);
    if (m->data == NULL) {
        iom_freeMsg(m);
        return -0x12D;
    }
    m->data->len = strlen(url);
    m->data->str = (char *)m->data + 8;
    memcpy(m->data->str, url, strlen(url));
    iom_sendMsg(m, mq);
    if (msg->type == 2) {
        m = iom_newMsg(msg);
        if (m != NULL) {
            mq = iom.mq8;
            m->code = 0x506;
            m->a1 = -1;
            m->size = strlen(url2) + 8;
            m->data = iom_malloc(m->size);
            if (m->data == NULL) {
                iom_freeMsg(m);
                return 0;
            }
            m->data->len = strlen(url2);
            m->data->str = (char *)m->data + 8;
            memcpy(m->data->str, url2, strlen(url2));
            iom_sendMsg(m, mq);
        }
    }
    return 0;
}

const char D_0013F400[] = "<html><body></body></html>";

const IERRT D_0013F41C[10] = {
    {400, D_0013F400},
    {400, D_0013F400},
    {400, D_0013F400},
    {400, D_0013F400},
    {404, D_0013F400},
    {404, D_0013F400},
    {404, D_0013F400},
    {400, D_0013F400},
    {-1, D_0013F400},
    {400, D_0013F400},
};

const IERRT D_0013F46C[10] = {
    {400, D_0013F400},
    {400, D_0013F400},
    {400, D_0013F400},
    {400, D_0013F400},
    {404, D_0013F400},
    {404, D_0013F400},
    {404, D_0013F400},
    {400, D_0013F400},
    {-1, D_0013F400},
    {400, D_0013F400},
};

const char D_0013F4BC[] = "byte code";
