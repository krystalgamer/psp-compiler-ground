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
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect_init);

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
