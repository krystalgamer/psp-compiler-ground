/* cflags: -O1 */
#include "common.h"
#include "iom_types.h"
#include "m2c_macros.h"
typedef struct LOCALRES { void *file; int x4; int x8; int xC; int x10; int x14; } LOCALRES;
extern char D_0013F3EC[];
int UTL_guessMIMETypeFromName();
char *URL_toLocalFileName(char *url);
void *readCFData(char *name, int *size);
void *UTL_mfilecreate(int size);
int UTL_mfilewrite(void *f, void *buf, int len);
unsigned int strlen(const char *s);
void MEM_free(void *pool, void *p);
typedef struct MQATTR { int x0; int x4; int x8; int xC; } MQATTR;
extern int D_00585108;
extern int D_0058510C;
extern int D_00585204;
int OS_mq_open(char *name, int flags, int mode, MQATTR *attr);
int iom_attachHttpCtx(void);
int iom_attachCache(void);
int iom_attachCookie(void);
void iom_stopHttpCtx(int);
int iom_freeMsg(IOMMSG *msg);
IOMMSG *iom_newMsg(IOMMSG *msg);
void iom_sendMsg(IOMMSG *msg, int mq);



void iom_end(void);
int iom_evStartup(IOMMSG *msg) {
    MQATTR attr = { 0, 0x80, 0x24, 0 };
    int q;
    int r;
    IOMMSG *m;
    q = OS_mq_open("/tmp/mq_ps", 0x202, 0x1A4, &attr);
    if (q == 0) {
        goto fail;
    }
    D_00585108 = q;
    q = OS_mq_open("/tmp/mq_lo", 0x202, 0x1A4, &attr);
    if (q == 0) {
        goto fail;
    }
    D_0058510C = q;
    if ((r = iom_attachHttpCtx()) < 0 || (r = iom_attachCache()) < 0 || (r = iom_attachCookie()) < 0) {
        iom_freeMsg(msg);
        return r;
    }
    D_00585204 = 0;
    m = iom_newMsg(msg);
    if (m == NULL) {
    fail:
        iom_freeMsg(msg);
        return -0x12D;
    }
    m->b.code = 0x20;
    iom_sendMsg(m, D_00585108);
    iom_freeMsg(msg);
    return 0;
}

int iom_evExit(IOMMSG *msg) {
    iom.x100 = 1;
    iom_stopHttpCtx(0);
    msg->b.x4 = 5;
    msg->b.code = 2;
    iom_sendMsg(msg, iom.mq);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int iom_evEnd(void *arg0) {
    iom_end();
    iom_freeMsg(arg0);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_evException(IOMMSG *msg) {
    iom_freeMsg(msg);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/iom_evstartup", iom_accessLocalfile);
