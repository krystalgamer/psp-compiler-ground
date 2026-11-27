/* cflags: -O1 */
#include "common.h"
#include "http_lib.h"
int http_shutdown(int h, int how);
int http_setuser(int h, char *user, char *passwd);
int http_delreqresource(int h);
int sceKernelDeleteSema(int id);
int sceHttpDeleteRequest(int id);
int sceHttpDeleteConnection(int id);
int sceHttpDeleteTemplate(int id);
int OS_thread_mutex_unlock(void *m);
int OS_thread_mutex_destroy(void *m);
void *UTL_mfiledelete(void *f);

int http_delete(int h)
{
    HttpObj *o = HTTP_OBJ(h);
    int r;

    if (h == 0)
        return -100;
    if (o->sema >= 0) {
        http_shutdown(h, 0);
        sceKernelDeleteSema(o->sema);
        o->sema = -1;
    }
    if (o->req >= 0) {
        sceHttpDeleteRequest(o->req);
        o->req = -1;
        http_delreqresource(h);
        OS_thread_mutex_unlock(o->mutex2);
    }
    if (o->conn >= 0) {
        sceHttpDeleteConnection(o->conn);
        o->conn = -1;
    }
    r = sceHttpDeleteTemplate(o->tmpl);
    if (r != 0 && o->error == 0)
        o->error = r;
    o->tmpl = -1;
    if (o->mutex != NULL) {
        OS_thread_mutex_destroy(o->mutex);
        o->mutex = NULL;
    }
    if (o->fC8 != NULL) {
        MEM_free(0, o->fC8);
        o->fC8 = NULL;
    }
    if (o->fCC != NULL) {
        MEM_free(0, o->fCC);
        o->fCC = NULL;
    }
    http_setuser(h, NULL, NULL);
    if (o->f8 != NULL)
        o->f8 = UTL_mfiledelete(o->f8);
    if (o->f30 != NULL)
        MEM_free(0, o->f30);
    if (o->statusline != NULL)
        MEM_free(0, o->statusline);
    if (o->mutex2 != NULL) {
        OS_thread_mutex_destroy(o->mutex2);
        o->mutex2 = NULL;
    }
    MEM_free(0, o);
    return 0;
}
