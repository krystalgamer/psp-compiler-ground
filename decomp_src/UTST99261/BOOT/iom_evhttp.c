/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct { int mq; u8 pad[0xFC]; int x100; } IOMG_T;
#define IOMG ((IOMG_T *)&iom)
extern int (*D_0013F290[])(void *msg, void *data);
void UTL_initqueue(M2C_UNK *);                   /* extern */
int http_attach(M2C_UNK, int);                      /* extern */
extern int D_005850FC;
extern unsigned char D_005851FC;
int http_detach();                                  /* extern */
M2C_UNK iom_sendMsg(int, int);                      /* extern */
M2C_UNK iom_setCache(int, int);                     /* extern */
M2C_UNK iom_setCookie2(void *);                     /* extern */
extern int iom;
void *UTL_dequeue(M2C_UNK *);                       /* extern */
int UTL_mfiledelete(int);                           /* extern */
M2C_UNK http_delete(int);                           /* extern */
int iom_addHttpCtx(void *);                         /* extern */
M2C_UNK iom_sendRequestFailed(void *, int);         /* extern */

M2C_UNK iom_evGetMethod();                          /* extern */


char *iom_malloc(int size);
char *strcpy(char *, const char *);
unsigned int strlen(const char *);
char *http_getresponseheader_SetCookie(int h, int i);
int iom_setCookie(char *url, char *cookie, int flag);
extern int D_00585204;
extern int G_sendflag;
typedef struct { int state; int x4[4]; void *msg; int x18[8]; } HCTXE;
typedef struct { int x0; int x4; void *msg; } HQE;
extern HCTXE D_005851C4[];
void *UTL_peekqueue(void *q, void *e);
void UTL_relqueue(void *q, void *e);
void *iom_freeMsg(void *msg);
int iom_mfree(void *p);
typedef struct { int mq; u8 pad[0xBC]; HCTXE ctx[1]; int xF8; int xFC; int x100; } IOMX_T;
void *iom_newMsg(void *);
void UTL_enqueue(void *q, void *e);
extern char D_0013F38C[];
extern int D_00585108;
int sprintf(char *, const char *, ...);
typedef struct { int len0; char *s0; int len1; char *s1; int len2; char *s2; } HCBD;
typedef struct { void *f; int pos; int size; int xC; int x10; int x14; int x18[2]; } LFILE;
extern char D_0013F3AC[];
extern char D_0013F3B4[];
extern char D_0013F3BC[];
int strncasecmp(const char *a, const char *b, unsigned int n);
char *iom_strnmcat(char *dst, int n, ...);
int iom_accessLocalfile(char *url, int a, LFILE *lf);
int iom_sendContent(void *msg, int a1, void *mf, int len);
int iom_sendRequestComplete(void *msg);
int iom_translateMsg(void *msg);
int iom_sendReceiveStatus(void *a, int b, int c, int d);
int iom_saveFilesave(void *a, int b, void *ctx, LFILE *src, int half);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", D_0013F290);

int iom_evHttpCtx(void *msg) {
    void *d = M2C_FIELD(msg, void **, 0x20);
    return D_0013F290[*(int *)d](msg, d);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_attachHttpCtx(void) {
    UTL_initqueue(&D_005851FC);
    return (((int) ~http_attach(0x320, D_005850FC) >> 0x1F) & 0x12C) - 0x12C;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_detachHttpCtx(void) {
    return (((int) ~http_detach() >> 0x1F) & 0x12C) - 0x12C;
}

int iom_addHttpCtx(void *msg) {
    HQE *e;
    HCTXE *c;
    int i;
    void *m;
    HQE *q;
    int t;

    t = M2C_FIELD(msg, int *, 4);
    if (t == 2 || t == 4) {
        for (e = UTL_peekqueue(&D_005851FC, NULL); e != NULL; e = UTL_peekqueue(&D_005851FC, e)) {
            if (M2C_FIELD(msg, int *, 4) == M2C_FIELD(e->msg, int *, 4) && M2C_FIELD(msg, int *, 8) == M2C_FIELD(e->msg, int *, 8))
                return -0x12E;
        }
        for (i = 0; i < 1; i++) {
            c = &D_005851C4[i];
            if (c->state != 0 && c->state != 6) {
                if (M2C_FIELD(msg, int *, 4) == M2C_FIELD(c->msg, int *, 4) && M2C_FIELD(msg, int *, 8) == M2C_FIELD(c->msg, int *, 8))
                    return -0x12E;
            }
        }
    }
    for (i = 0; i < 1; i++) {
        if (((IOMX_T *)&iom)->ctx[i].state == 0) {
            if (((IOMX_T *)&iom)->x100 != 0)
                return -0x133;
            m = iom_newMsg(NULL);
            if (m == NULL)
                return -0x12D;
            ((IOMX_T *)&iom)->ctx[i].state = 1;
            ((IOMX_T *)&iom)->ctx[i].msg = msg;
            ((IOMX_T *)&iom)->ctx[i].x18[7] = 0;
            M2C_FIELD(m, int *, 0x10) = 0x12;
            M2C_FIELD(m, void **, 0x20) = &D_005851C4[i];
            iom_sendMsg((int)m, iom);
            break;
        }
    }
    if (i < 1)
        goto end;
    m = iom_malloc(0xC);
    if (m == NULL)
        return -0x12D;
    ((HQE *)m)->msg = msg;
    UTL_enqueue(&D_005851FC, m);
end:
    return 0;
}

void iom_stopHttpCtx(void *msg) {
    HQE *e;
    HQE *n;
    HCTXE *c;
    int i;

    for (e = UTL_peekqueue(&D_005851FC, NULL); e != NULL; e = n) {
        n = UTL_peekqueue(&D_005851FC, e);
        if (msg == NULL || (M2C_FIELD(msg, int *, 4) == M2C_FIELD(e->msg, int *, 4) && (M2C_FIELD(msg, int *, 0x14) == 0 || (M2C_FIELD(msg, int *, 0x14) == 1 && M2C_FIELD(msg, int *, 8) == M2C_FIELD(e->msg, int *, 8))))) {
            UTL_relqueue(&D_005851FC, e);
            iom_sendRequestFailed(e->msg, -0x133);
            e->msg = iom_freeMsg(e->msg);
            iom_mfree(e);
        }
    }
    for (i = 0; i < 1; i++) {
        c = &D_005851C4[i];
        if (c->state != 0 && c->state != 6) {
            if (msg == NULL || (M2C_FIELD(msg, int *, 4) == M2C_FIELD(c->msg, int *, 4) && (M2C_FIELD(msg, int *, 0x14) == 0 || (M2C_FIELD(msg, int *, 0x14) == 1 && M2C_FIELD(msg, int *, 8) == M2C_FIELD(c->msg, int *, 8))))) {
                iom_sendRequestFailed(c->msg, -0x133);
                c->state = 6;
            }
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_freeStateHttpCtx(void *arg0) {
    M2C_FIELD(arg0, int *, 0x20) = 0;
    iom_freeMsg(arg0);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_initStateHttpCtx);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", D_0013F2C0);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_setupStateHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_connectingStateHttpCtx);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", D_0013F2E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", D_0013F2E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", D_0013F2F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", D_0013F2F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", D_0013F2F8);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_downloadStateHttpCtx);

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_cacheStateHttpCtx(int arg0, void *arg1) {
    iom_setCache(M2C_FIELD(arg1, int *, 0x10), arg1 + 0x18);
    iom_setCookie2(arg1);
    M2C_FIELD(arg1, int *, 0) = 6;
    iom_sendMsg(arg0, iom);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_doneStateHttpCtx(void *arg0, void *arg1) {
    int temp_a0;
    int temp_v0_2;
    void *temp_v0;

    M2C_FIELD(arg1, int *, 0x10) = iom_mfree(M2C_FIELD(arg1, int *, 0x10));
    M2C_FIELD(arg1, void **, 0x14) = iom_freeMsg(M2C_FIELD(arg1, void **, 0x14));
    M2C_FIELD(arg1, int *, 0x18) = UTL_mfiledelete(M2C_FIELD(arg1, int *, 0x18));
    M2C_FIELD(arg1, int *, 0) = 0;
    M2C_FIELD(arg1, int *, 0xC) = 0;
    M2C_FIELD(arg1, int *, 0x34) = 0;
    M2C_FIELD(arg0, int *, 0x20) = 0;
    iom_freeMsg(arg0);
    temp_v0 = UTL_dequeue(&D_005851FC);
    if (temp_v0 != NULL) {
        temp_v0_2 = iom_addHttpCtx(M2C_FIELD(temp_v0, void **, 8));
        if (temp_v0_2 < 0) {
            iom_sendRequestFailed(M2C_FIELD(temp_v0, void **, 8), temp_v0_2);
            M2C_FIELD(temp_v0, void **, 8) = iom_freeMsg(M2C_FIELD(temp_v0, void **, 8));
        }
        iom_mfree((int) temp_v0);
        return 0;
    }
    temp_a0 = M2C_FIELD(arg1, int *, 8);
    if (temp_a0 != 0) {
        http_delete(temp_a0);
        M2C_FIELD(arg1, int *, 8) = 0;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_setHttpRequestHeader);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", D_0013F38C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", D_0013F390);

int iom_httpToLocalError(int e) {
    int r = 0;
    if (e < 0) {
        switch (e) {
        case -0x66:
            r = -0x135;
            break;
        case -0x65:
            r = -0x134;
            break;
        case -0x67:
            r = -0x12D;
            break;
        case -0x64:
            r = -0x12E;
            break;
        default:
            r = -0x12C;
            break;
        }
    }
    return r;
}

void iom_httpCallback(void *h, int type, ...) {
    __builtin_va_list ap;
    int code;
    char *a;
    char *b;
    char *c;
    char *d;
    int n;
    HCBD *p;
    void *m;

    __builtin_va_start(ap, type);
    if (type == 1) {
        code = __builtin_va_arg(ap, int);
        a = __builtin_va_arg(ap, char *);
        b = __builtin_va_arg(ap, char *);
        c = __builtin_va_arg(ap, char *);
        d = __builtin_va_arg(ap, char *);
        if (a == NULL)
            a = D_0013F38C;
        if (b == NULL)
            b = D_0013F38C;
        if (c == NULL)
            c = D_0013F38C;
        if (d == NULL)
            d = D_0013F38C;
        n = strlen(a);
        n += strlen(b);
        n += strlen(c);
        n += strlen(d);
        n += 0x1E;
        p = (HCBD *)iom_malloc(n);
        if (p != NULL) {
            m = iom_newMsg(M2C_FIELD(h, void **, 0x14));
            if (m != NULL) {
            M2C_FIELD(m, int *, 0x10) = 0x29;
            M2C_FIELD(m, int *, 0x14) = (unsigned)code >> 31;
            M2C_FIELD(m, int *, 0x1C) = 0x18;
            M2C_FIELD(m, void **, 0x20) = p;
            p->len0 = strlen(a);
            p->s0 = (char *)(p + 1);
            strcpy(p->s0, a);
            p->len1 = strlen(b);
            p->s1 = p->s0 + p->len0 + 1;
            strcpy(p->s1, b);
            p->len2 = strlen(c) + strlen(d) + 3;
            p->s2 = p->s1 + p->len1 + 1;
            sprintf(p->s2, "%s - %s", c, d);
            iom_sendMsg((int)m, D_00585108);
            } else
                iom_mfree(p);
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_location);

int iom_setCookie2(void *ctx) {
    char *url;
    char *c;
    int i;

    url = iom_malloc(strlen(M2C_FIELD(ctx, char **, 0x10)) + 1);
    if (url == NULL)
        return -0x12D;
    for (i = 0; (c = http_getresponseheader_SetCookie(M2C_FIELD(ctx, int *, 8), i)) != NULL; i++) {
        strcpy(url, M2C_FIELD(ctx, char **, 0x10));
        iom_setCookie(url, c, 1);
    }
    iom_mfree(url);
    return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", D_0013F3AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", D_0013F3B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", D_0013F3BC);

int iom_evGetMethod(msg)
    void *msg;
{
    LFILE lf;
    void *r = M2C_FIELD(msg, void **, 0x20);
    char *url;
    int err;

    url = iom_malloc(M2C_FIELD(r, int *, 0x10) + 1);
    if (url == NULL) {
        iom_sendRequestFailed(msg, -0x12D);
    } else {
        iom_strnmcat(url, 1, M2C_FIELD(r, int *, 0x10), M2C_FIELD(r, char **, 0x14));
        if (M2C_FIELD(msg, int *, 0x14) == 2) {
            iom_sendRequestFailed(msg, -0x12C);
        } else if (strncasecmp(url, D_0013F3AC, 5) == 0 || strncasecmp(url, D_0013F3B4, 6) == 0) {
            err = iom_addHttpCtx(msg);
            if (err < 0) {
                iom_sendRequestFailed(msg, err);
            } else {
                msg = NULL;
            }
        } else if (strncasecmp(url, D_0013F3BC, 5) == 0) {
            err = iom_accessLocalfile(url, 1, &lf);
            if (err < 0) {
                iom_sendRequestFailed(msg, err);
            } else if (iom_translateMsg(msg) == 0xF) {
                err = iom_saveFilesave(msg, 200, M2C_FIELD(msg, char **, 0x20) + 0x28, &lf, 0);
                if (err >= 0) {
                    iom_sendRequestComplete(msg);
                } else {
                    iom_sendRequestFailed(msg, err);
                }
                UTL_mfiledelete((int)lf.f);
            } else if (iom_translateMsg(msg) == 0x10 || iom_translateMsg(msg) == 0x11) {
                iom_sendRequestFailed(msg, -0x12C);
            } else {
                iom_sendReceiveStatus(msg, 200, 0, lf.size);
                if (lf.x14 != 0 && M2C_FIELD(msg, int *, 4) == 2 && (iom_translateMsg(msg) == 3 || iom_translateMsg(msg) == 4))
                    M2C_FIELD(msg, int *, 0xC) = 0;
                if (M2C_FIELD(msg, int *, 0xC) == 1) {
                    err = iom_sendContent(msg, 200, lf.f, lf.pos);
                    if (err >= 0)
                        err = iom_sendContent(msg, 200, lf.f, lf.size);
                } else {
                    err = iom_sendContent(msg, 200, lf.f, lf.pos + lf.size);
                }
                if (err < 0) {
                    iom_sendRequestFailed(msg, err);
                } else {
                    iom_sendReceiveStatus(msg, 200, lf.size, lf.size);
                    iom_sendRequestComplete(msg);
                }
                UTL_mfiledelete((int)lf.f);
            }
        } else {
            iom_sendRequestFailed(msg, -0x12E);
        }
        iom_mfree(url);
    }
    iom_freeMsg(msg);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void iom_evPostMethod(void) {
    iom_evGetMethod();
}

int iom_evHeadMethod(void *msg) {
    LFILE lf;
    void *r = M2C_FIELD(msg, void **, 0x20);
    char *url;
    int err;

    url = iom_malloc(M2C_FIELD(r, int *, 0x10) + 1);
    if (url == NULL) {
        iom_sendRequestFailed(msg, -0x12D);
    } else {
        iom_strnmcat(url, 1, M2C_FIELD(r, int *, 0x10), M2C_FIELD(r, char **, 0x14));
        if (M2C_FIELD(msg, int *, 0x14) == 2) {
            iom_sendRequestFailed(msg, -0x12C);
        } else if (strncasecmp(url, D_0013F3AC, 5) == 0 || strncasecmp(url, D_0013F3B4, 6) == 0) {
            err = iom_addHttpCtx(msg);
            if (err < 0) {
                iom_sendRequestFailed(msg, err);
            } else {
                msg = NULL;
            }
        } else if (strncasecmp(url, D_0013F3BC, 5) == 0) {
            err = iom_accessLocalfile(url, 0, &lf);
            if (err < 0) {
                iom_sendRequestFailed(msg, err);
            } else {
                err = iom_sendContent(msg, 200, lf.f, lf.pos);
                if (err < 0) {
                    iom_sendRequestFailed(msg, err);
                    UTL_mfiledelete((int)lf.f);
                } else {
                    iom_sendRequestComplete(msg);
                    UTL_mfiledelete((int)lf.f);
                }
            }
        } else {
            iom_sendRequestFailed(msg, -0x12E);
        }
        iom_mfree(url);
    }
    iom_freeMsg(msg);
    return 0;
}

int iom_evLoadStop(void *msg) {
    void **p;
    void *m;
    p = iom_malloc(4);
    if (p != NULL) {
        *p = msg;
        m = iom_newMsg(msg);
        if (m != NULL) {
            goto ok;
        }
        iom_mfree(p);
    }
    iom_sendRequestFailed(msg, -0x12D);
    iom_freeMsg(msg);
    return 0;
ok:
    IOMG->x100 = 1;
    M2C_FIELD(m, int *, 0x10) = 7;
    M2C_FIELD(m, void ***, 0x20) = p;
    iom_sendMsg(m, IOMG->mq);
    return 0;
}

int iom_evLoadStop2(void *msg) {
    void *h = M2C_FIELD(M2C_FIELD(msg, void **, 0x20), void **, 0);
    void *ctx;
    int flag;
    int st;
    int t;

    iom_freeMsg(msg);
    ctx = h;
    D_00585204 = 0;
    G_sendflag = 0;
    iom_stopHttpCtx(ctx);
    flag = G_sendflag;
    G_sendflag = 0;
    st = M2C_FIELD(ctx, int *, 4);
    if (st == 2) {
        M2C_FIELD(ctx, int *, 4) = 5;
        iom_stopHttpCtx(ctx);
        M2C_FIELD(ctx, int *, 4) = st;
    }
    t = flag | G_sendflag;
    G_sendflag = 0;
    if (t == 0)
        iom_sendRequestFailed(ctx, -0x133);
    G_sendflag = 0;
    iom_freeMsg(ctx);
    return 0;
}
