/* cflags: -O1 */
#include "common.h"
#include "http_lib.h"
typedef struct HttpSemaInfo {
    int size;
    char name[32];
    int attr;
    int init;
    int count;                        /* 0x2C */
    int max;
    int wait;
} HttpSemaInfo;
int OS_thread_mutex_lock(void *m);
int OS_thread_mutex_unlock(void *m);
int sceHttpAbortRequest(int id);
int sceHttpDeleteRequest(int id);
int sceHttpDeleteConnection(int id);
int sceKernelReferSemaStatus(int id, HttpSemaInfo *info);
int sceKernelWaitSema(int id, int n, void *timeout);
int sceKernelSignalSema(int id, int n);
int http_deleteresponseresource(int h);
int http_delreqresource(int h);

int http_shutdown(int h, int how)
{
    HttpObj *o = HTTP_OBJ(h);
    HttpSemaInfo info;
    int r;

    if (h == 0)
        return -100;
    OS_thread_mutex_lock(o->mutex);
    o->f24 = 0;
    if (o->state == 4 || o->state == 6)
        sceHttpAbortRequest(o->req);
    info.size = sizeof(info);
    sceKernelReferSemaStatus(o->sema, &info);
    OS_thread_mutex_unlock(o->mutex);
    if (sceKernelWaitSema(o->sema, 1, NULL) < 0) {
        if (o->error == 0)
            o->error = -100;
        return o->error;
    }
    OS_thread_mutex_lock(o->mutex);
    info.size = sizeof(info);
    sceKernelReferSemaStatus(o->sema, &info);
    if (info.count == 0)
        sceKernelSignalSema(o->sema, 1);
    r = http_deleteresponseresource(h);
    if (r != 0) {
        OS_thread_mutex_unlock(o->mutex);
        return r;
    }
    if (o->state != 0) {
        o->state = 0;
        if (o->req >= 0) {
            r = sceHttpDeleteRequest(o->req);
            if (r < 0) {
                OS_thread_mutex_unlock(o->mutex2);
                goto err;
            }
            o->req = -1;
            r = http_delreqresource(h);
            if (r < 0) {
                OS_thread_mutex_unlock(o->mutex2);
                OS_thread_mutex_unlock(o->mutex);
                return r;
            }
        }
        OS_thread_mutex_unlock(o->mutex2);
        if (o->conn >= 0) {
            r = sceHttpDeleteConnection(o->conn);
            if (r < 0) {
err:
                if (o->error == 0)
                    o->error = r;
                OS_thread_mutex_unlock(o->mutex);
                return o->error;
            }
            o->conn = -1;
        }
        if (o->fC8 != NULL) {
            MEM_free(0, o->fC8);
            o->fC8 = NULL;
            if (o->fCC != NULL) {
                MEM_free(0, o->fCC);
                o->fCC = NULL;
            }
        }
    }
    o->f1C = 0;
    OS_thread_mutex_unlock(o->mutex);
    return 0;
}
