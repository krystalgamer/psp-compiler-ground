/* cflags: -O1 */
#include "common.h"
#include "http_lib.h"
#include "http_os.h"
#include "m2c_macros.h"
typedef struct HttpReqMsg {
    int f0;                           /* 0x0 */
    int f4;                           /* 0x4 */
    int type;                         /* 0x8 */
    void *arg;                        /* 0xC */
} HttpReqMsg;
extern int gReqMbxID;
int sceHttpGetStatusCode(int req, int *status);
int sceHttpDeleteRequest(int id);
int sceKernelSendMbx(int id, void *msg);
int http_delreqresource(int h);
typedef struct HtHdr {
    int f0;
    int f4;
    char *name;                       /* 0x8 */
    char *value;                      /* 0xC */
} HtHdr;
void *UTL_peekqueue(void *q, void *prev);
int strcasecmp(const char *a, const char *b);
void *srchThreadTbl(int id);
typedef struct DumyArg {
    void (*func)(void *);
    void *arg;
} DumyArg;


int strncasecmp(const char *a, const char *b, unsigned int n);
int OS_thread_mutex_lock(OSMutex *m);
int OS_thread_mutex_unlock(OSMutex *m);
unsigned int strlen(const char *);
int sceKernelTerminateThread(int);
int sceKernelDeleteThread(int);
void delThreadTbl(void *);
int http_state(int h)
{
    int st;
    HttpObj *o = HTTP_OBJ(h);
    int r;
    int ps;
    int status;
    HttpReqMsg *m;

    if (h == 0)
        return -100;
    OS_thread_mutex_lock(o->mutex);
    st = o->f1C;
    ps = o->state;
    if (o->f24 == 1 && st == 2) {
        r = sceHttpGetStatusCode(o->req, &status);
        if (r < 0)
            goto err;
        if ((unsigned int)(status - 300) < 100 && (o->rule & 4)) {
            r = sceHttpDeleteRequest(o->req);
            if (r != 0)
                goto fail;
            o->req = -1;
            r = http_delreqresource(h);
            if (r < 0) {
fail:
                OS_thread_mutex_unlock(o->mutex2);
err:
                if (o->error == 0)
                    o->error = r;
                goto unlock;
            }
            OS_thread_mutex_unlock(o->mutex2);
            st = 1;
            goto done;
        }
    } else if (ps == -1) {
        if (st == 1) {
            o->f1C = st;
            o->state = 3;
            OS_thread_mutex_unlock(o->mutex);
            m = MEM_malloc(0, sizeof(HttpReqMsg));
            if (m == NULL) {
                if (o->error == 0)
                    o->error = -103;
                return o->error;
            }
            m->type = 1;
            m->arg = o;
            r = sceKernelSendMbx(gReqMbxID, m);
            st = 1;
            if (r < 0) {
                if (o->error == 0)
                    o->error = r;
                return o->error;
            }
            goto done;
        }
        if (st == 3) {
            o->f24 = st;
unlock:
            OS_thread_mutex_unlock(o->mutex);
            return o->error;
        }
    }
done:
    o->f24 = st;
    OS_thread_mutex_unlock(o->mutex);
    return st;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", htlib_setheaderkey);

char *htlib_getheadervalue(void *q, const char *name, int idx)
{
    int n = 0;
    HtHdr *h;

    for (h = UTL_peekqueue(q, NULL); h != NULL; h = UTL_peekqueue(q, h))
        if (strcasecmp(h->name, name) == 0) {
            if (n >= idx)
                return h->value;
            n++;
        }
    return NULL;
}

char *htlib_strnmcat(char *dst, int n, ...)
{
    __builtin_va_list ap;
    char *d;
    int i, j, len;
    char *s;

    __builtin_stdarg_start(ap, n);
    d = dst;
    for (i = 0; i < n; i++) {
        len = __builtin_va_arg(ap, int);
        s = __builtin_va_arg(ap, char *);
        if (s != NULL)
            for (j = 0; j < len && s[j] != 0; j++)
                *d++ = s[j];
    }
    *d = 0;
    return dst;
}

char *htlib_getstrheadervalue(char *buf, int len, char *name, int nth)
{
    int nlen;
    int i;
    char *p;
    char *v;
    int vlen;
    char *r;

    nlen = strlen(name);
    while (len > 0) {
        i = 0;
        while (i < len && buf[i] != '\n')
            i++;
        if (len < i)
            break;
        if (buf[i] == '\0' || buf[i] == '\n') {
            if (i > nlen && strncasecmp(buf, name, nlen) == 0) {
              if (nth == 0) {
                p = buf + nlen;
                while (*p == ' ' || *p == '\t')
                    p++;
                p += (*p == ':');
                while (*p == ' ' || *p == '\t')
                    p++;
                v = p;
                while (*p != '\0' && *p != '\r' && *p != '\n')
                    p++;
                len = p - v;
                r = MEM_malloc(0, len + 1);
                if (r == NULL)
                    return NULL;
                htlib_strnmcat(r, 1, len, v);
                return r;
            } else nth--;}
            len -= i;
            len--;
            buf += i + 1;
        } else
            break;
    }
    return NULL;
}

int dumyFunc(int a, DumyArg *p)
{
    p->func(p->arg);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_state", OS_thread_create);

void OS_thread_exit(void *ret)
{
    OSThread *t = (OSThread *)(OS_thread_self() * 2);

    t->retval = ret;
    sceKernelSignalSema(t->sema, 1);
    sceKernelExitThread(0);
}

int OS_thread_join(int th, void **retp)
{
    OSThread *t = (OSThread *)(th * 2);

    if (sceKernelWaitSema(t->sema, 1, NULL) < 0)
        return 6;
    sceKernelTerminateThread(t->f0);
    if (sceKernelDeleteThread(t->f0) < 0)
        return 6;
    sceKernelDeleteSema(t->sema);
    if (retp != NULL)
        *retp = t->retval;
    delThreadTbl(t);
    MEM_free(0, t);
    return 0;
}

int OS_thread_self(void)
{
    int id = sceKernelGetThreadId();
    void *t;

    if (id < 0)
        return -1;
    if (id == 1)
        return 1;
    t = srchThreadTbl(id);
    if (t == NULL)
        return -1;
    return (int)t >> 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_init(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_destroy(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_setschedparam(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_getschedparam(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_setstacksize(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_attr_getstacksize(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_setschedparam(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int OS_thread_getschedparam(void) {
    return 0;
}

OSMutex *OS_thread_mutex_create(void)
{
    return MEM_malloc(0, sizeof(OSMutex));
}

void OS_thread_mutex_destroy(OSMutex *m)
{
    if (m != NULL) {
        if (*m >= 0)
            sceKernelDeleteSema(*m);
        MEM_free(0, m);
    }
}

int OS_thread_mutex_init(OSMutex *m, void *attr)
{
    int id;

    if (m == NULL)
        return 6;
    id = sceKernelCreateSema("pspBrowser-mutex", 0, 1, 1, 0);
    if (id < 0)
        return 3;
    *m = id;
    return 0;
}

int OS_thread_mutex_lock(OSMutex *m)
{
    int ret = 6;

    if (m != NULL)
        ret = sceKernelWaitSema(*m, 1, 0) < 0 ? 7 : 0;
    return ret;
}

int OS_thread_mutex_trylock(OSMutex *m)
{
    int ret = 6;

    if (m != NULL)
        ret = sceKernelPollSema(*m, 1) < 0 ? 7 : 0;
    return ret;
}

int OS_thread_mutex_unlock(OSMutex *m)
{
    SceKernelSemaInfo info;
    int r;

    if (m == NULL)
        return 6;
    info.size = sizeof(info);
    r = sceKernelReferSemaStatus(*m, &info);
    if (info.currentCount != 1)
        r = sceKernelSignalSema(*m, 1);
    if (r < 0)
        return 1;
    return 0;
}
