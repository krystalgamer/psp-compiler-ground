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
int sceKernelReferSemaStatus(int id, HttpSemaInfo *info);
int sceKernelSignalSema(int id, int n);
int sceHttpAddExtraHeader(int id, char *name, char *value, int mode);

int http_setrequestheader_Authorization(int h, char **up);
int http_setproxyheader_Authorization(int h, char **up);
int http_setrequestheader_ContentLength(int h, char *v);
int http_setproxyheader_ContentLength(int h, char *v);
int sceHttpDeleteHeader(int id, const char *name);
extern char htlib_cstrCONTENTLENGTH[];
void http_connect_error_end(HttpObj *o);
int sprintf(char *, const char *, ...);
typedef struct HttpSrv { int f0; char *host; char *user; char *pass; char *path; int f14[3]; unsigned short port; } HttpSrv;
int strcmp(const char *, const char *);
int OS_thread_mutex_lock(void *m);
int OS_thread_mutex_unlock(void *m);
int sceUriParse(void *uri, const char *url, void *pool, unsigned int *need, unsigned int size);
void *UTL_mfilecreate(int size);
int http_deleteresponseresource(int h);
typedef struct HttpUriBuf { int w[11]; } HttpUriBuf;
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect);

int http_connect_init(int h, char *url)
{
    HttpObj *o = HTTP_OBJ(h);
    int r;
    unsigned int need;
    unsigned int used;

    OS_thread_mutex_lock(o->mutex);
    if (o->f1C == 0) {
        if (o->fCC != NULL)
            MEM_free(0, o->fCC);
        o->fCC = NULL;
    } else if (o->f1C == 3) {
        if (o->fC8 != NULL) {
            if (o->fCC != NULL)
                MEM_free(0, o->fCC);
            (*(HttpUriBuf *)((char *)o + 0x9C)) = (*(HttpUriBuf *)((char *)o + 0x70));
            o->fCC = o->fC8;
            o->fC8 = NULL;
        }
    }
    OS_thread_mutex_unlock(o->mutex);
    r = sceUriParse(NULL, url, NULL, &need, 0);
    if (r < 0) {
        http_connect_error_end(o);
        if (o->error == 0)
            o->error = r;
        return o->error;
    }
    if (o->fC8 != NULL)
        MEM_free(0, o->fC8);
    o->fC8 = MEM_malloc(0, need);
    if (o->fC8 == NULL) {
        http_connect_error_end(o);
        if (o->error == 0)
            o->error = -0x67;
        return o->error;
    }
    r = sceUriParse((char *)o + 0x70, url, o->fC8, &used, need);
    if (r < 0) {
        http_connect_error_end(o);
        if (o->error == 0)
            o->error = r;
        return o->error;
    }
    if ((*(int *)((char *)o + 0x80)) == 0 || (r = http_deleteresponseresource(h)) != 0) {
        http_connect_error_end(o);
        if (o->error == 0)
            o->error = -0x64;
        return o->error;
    }
    o->f8 = UTL_mfilecreate(0x800);
    if (o->f8 == NULL) {
        http_connect_error_end(o);
        if (o->error == 0)
            o->error = -0x67;
        return o->error;
    }
    if (o->f30 != NULL) {
        MEM_free(0, o->f30);
        o->f30 = NULL;
    }
    if (o->proxy != NULL) {
        MEM_free(0, o->proxy);
        o->proxy = NULL;
    }
    if (o->statusline != NULL)
        MEM_free(0, o->statusline);
    o->statusline = NULL;
    o->statuslen = 0;
    o->pport = 0;
    (*(int *)((char *)o + 0x68)) = 0;
    (*(int *)((char *)o + 0x6C)) = 0;
    return 0;
}

int http_connect_checkServer(HttpSrv *a, HttpSrv *b)
{
    if (a->host == NULL || a->path == NULL || b->host == NULL || b->path == NULL)
        return -1;
    if (strcmp(a->host, b->host) != 0)
        return -1;
    if (a->user == NULL || b->user == NULL) {
        if (a->user != NULL || b->user != NULL)
            return -1;
    } else if (strcmp(a->user, b->user) != 0)
        return -1;
    if (a->pass == NULL || b->pass == NULL) {
        if (a->pass != NULL || b->pass != NULL)
            return -1;
    } else if (strcmp(a->pass, b->pass) != 0)
        return -1;
    if (strcmp(a->path, b->path) != 0)
        return -1;
    if (a->port != b->port)
        return -1;
    return 0;
}

int http_connect_SetAutoHead(int h, int body, unsigned int len, int method)
{
    HttpObj *o = HTTP_OBJ(h);
    int r;
    char buf[48];

    if (o->proxy == NULL)
        r = http_setrequestheader_Authorization(h, &o->user);
    else
        r = http_setproxyheader_Authorization(h, &o->puser);
    if (r != 0)
        return r;
    if (o->rule & 2) {
        if (method == 1 || body != 0) {
            h = (int)o >> 1;
            sprintf(buf, "%u", len);
            if (o->proxy == NULL)
                r = http_setrequestheader_ContentLength(h, buf);
            else
                r = http_setproxyheader_ContentLength(h, buf);
            if (r < 0)
                return r;
        }
    } else {
        r = sceHttpDeleteHeader(o->req, htlib_cstrCONTENTLENGTH);
        if (r != 0) {
            http_connect_error_end(o);
            if (o->error == 0)
                o->error = r;
            return o->error;
        }
    }
    return 0;
}

int http_connect_setAllReqHead(int h)
{
    HttpObj *o = HTTP_OBJ(h);
    HttpHdr *p;
    int r;

    if (h == 0)
        return -100;
    if (o->proxy == NULL)
        p = o->hdrs;
    else
        p = o->phdrs;
    for (; p != NULL; p = p->next) {
        r = sceHttpAddExtraHeader(o->req, p->name, p->value, 0);
        if (r < 0) {
            http_connect_error_end(o);
            if (o->error == 0)
                o->error = r;
            return o->error;
        }
    }
    return 0;
}

void http_connect_error_end(HttpObj *o)
{
    HttpSemaInfo info;

    info.size = sizeof(info);
    sceKernelReferSemaStatus(o->sema, &info);
    if (info.count == 0)
        sceKernelSignalSema(o->sema, 1);
}
