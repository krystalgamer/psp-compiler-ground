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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect_init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect_checkServer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_connect", http_connect_SetAutoHead);

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
