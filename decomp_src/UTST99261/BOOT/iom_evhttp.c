/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct { int mq; u8 pad[0xFC]; int x100; } IOMG_T;
#define IOMG ((IOMG_T *)&iom)
extern int (*D_0013F290[])(void *msg, void *data);
M2C_UNK UTL_initqueue(M2C_UNK *);                   /* extern */
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_addHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_stopHttpCtx);

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_freeStateHttpCtx(void *arg0) {
    M2C_FIELD(arg0, int *, 0x20) = 0;
    iom_freeMsg(arg0);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_initStateHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_setupStateHttpCtx);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_connectingStateHttpCtx);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_httpCallback);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_evGetMethod);

#ifndef NULL
#define NULL ((void *)0)
#endif

void iom_evPostMethod(void) {
    iom_evGetMethod();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evhttp", iom_evHeadMethod);

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
