/* cflags: -O1 */
#include "common.h"
#include "http_lib.h"
extern int _http_attached;
void *memset(void *s, int c, unsigned int n);
int sceHttpCreateTemplate(const char *agent, int ver, int proxy);
int sceHttpEnableKeepAlive(int id);
int sceHttpDisableRedirect(int id);
int sceHttpDisableCookie(int id);
int sceHttpDisableCache(int id);
void *OS_thread_mutex_create(void);
int OS_thread_mutex_init(void *m, void *attr);
void OS_thread_mutex_destroy(void *m);
int OS_thread_mutex_lock(void *m);
int OS_thread_mutex_unlock(void *m);
void UTL_initqueue(void *q);
typedef struct HttpReqMsg {
    int f0;
    int f4;
    int type;                         /* 0x8 */
    void *arg;                        /* 0xC */
} HttpReqMsg;
extern int gReqMbxID;
int sceKernelReceiveMbx(int id, void *msg, void *timeout);
int sceKernelExitDeleteThread(int status);
void http_msg_send_request(void *arg);
void MEM_free(int heap, void *p);

int http_new(int ver)
{
    HttpObj *o = NULL;
    int r;

    if (_http_attached != 1) {
        if (o->error == 0)
            o->error = -100;
        return 0;
    }
    o = MEM_malloc(0, sizeof(HttpObj));
    if (o == NULL) {
        if (o->error == 0)
            o->error = -103;
        return 0;
    }
    memset(o, 0, sizeof(HttpObj));
    if (ver == 10)
        o->f28 = 0;
    else
        o->f28 = 1;
    r = sceHttpCreateTemplate(NULL, o->f28, 1);
    if (r < 0)
        goto err;
    o->tmpl = r;
    if ((r = sceHttpEnableKeepAlive(r)) != 0)
        goto err;
    if ((r = sceHttpDisableRedirect(o->tmpl)) != 0)
        goto err;
    if ((r = sceHttpDisableCookie(o->tmpl)) != 0)
        goto err;
    if ((r = sceHttpDisableCache(o->tmpl)) != 0) {
err:
        if (o->error == 0)
            o->error = r;
        return 0;
    }
    o->f8 = NULL;
    o->f30 = NULL;
    o->rule = 15;
    o->mutex = OS_thread_mutex_create();
    if (o->mutex == NULL)
        return 0;
    if (OS_thread_mutex_init(o->mutex, NULL) != 0) {
        OS_thread_mutex_destroy(o->mutex);
        o->mutex = NULL;
        return 0;
    }
    OS_thread_mutex_lock(o->mutex);
    o->f1C = 0;
    o->state = 0;
    OS_thread_mutex_unlock(o->mutex);
    o->sema = -1;
    o->fC8 = NULL;
    o->fCC = NULL;
    o->conn = -1;
    o->req = 0;
    o->hdrs = NULL;
    o->phdrs = NULL;
    UTL_initqueue((char *)o + 0x14);
    o->f2C = NULL;
    o->mutex2 = OS_thread_mutex_create();
    if (o->mutex2 == NULL)
        return 0;
    if (OS_thread_mutex_init(o->mutex2, NULL) == 0)
        return (int)o >> 1;
    OS_thread_mutex_destroy(o->mutex2);
    o->mutex2 = NULL;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_new", http_msg_send_request);

void http_msg_endThread(void) {
}

void http_sndreq_main(void)
{
    HttpReqMsg *m;
    HttpReqMsg *p;
    int run = 1;

    do {
        if (sceKernelReceiveMbx(gReqMbxID, &m, NULL) < 0)
            return;
        p = m;
        switch (p->type) {
        case 1:
            http_msg_send_request(p->arg);
            break;
        case 2:
            http_msg_endThread();
            run = 0;
            break;
        }
        MEM_free(0, p);
    } while (run);
    sceKernelExitDeleteThread(0);
}
