/* cflags: -O1 */
#include "common.h"
typedef struct HttpPrefUI {
    char pad[0x3C];
    int prio;                         /* 0x3C */
} HttpPrefUI;
extern HttpPrefUI *gPREF_UI;
extern int _http_attached;
extern int gReqMbxID;
extern int gSndReqTID;
void http_sndreq_main(void *arg);
int sceKernelCreateMbx(const char *name, int attr, void *opt);
int sceKernelCreateThread(const char *name, void *entry, int prio, int stack, int attr, void *opt);
int sceKernelStartThread(int id, int len, void *arg);
int sceKernelDeleteThread(int id);
typedef struct DumyArg {
    void (*func)(void *);
    void *arg;
} DumyArg;

int dumyFunc_req(int a, DumyArg *p)
{
    p->func(p->arg);
    return 0;
}

int http_attach(void)
{
    DumyArg arg;
    int id;
    int prio;

    if (_http_attached != 1) {
        id = sceKernelCreateMbx("pspBrowser-sndReqMBX", 0, NULL);
        if (id < 0)
            return -1;
        gReqMbxID = id;
        arg.func = http_sndreq_main;
        prio = gPREF_UI->prio;
        gSndReqTID = sceKernelCreateThread("pspBrowser-HttpSndReq", dumyFunc_req, prio, 0x2000, 0x204000, NULL);
        if (gSndReqTID < 0)
            return -1;
        if (sceKernelStartThread(gSndReqTID, 8, &arg) < 0) {
            sceKernelDeleteThread(gSndReqTID);
            return -1;
        }
        _http_attached = 1;
    }
    return _http_attached == 1 ? 0 : -100;
}
