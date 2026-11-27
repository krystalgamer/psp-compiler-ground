/* cflags: -O1 */
#include "common.h"
typedef struct HttpReqMsg {
    int f0;
    int f4;
    int type;
    int fC;
} HttpReqMsg;
extern int _http_attached;
extern int gReqMbxID;
extern int gSndReqTID;
void *MEM_malloc(int heap, unsigned int size);
int sceKernelSendMbx(int id, void *msg);
int sceKernelWaitThreadEnd(int tid, unsigned int *timeout);
int sceKernelDeleteMbx(int id);

int http_detach(void)
{
    HttpReqMsg *m;

    if (_http_attached == 1) {
        m = MEM_malloc(0, sizeof(HttpReqMsg));
        if (m == NULL)
            return -1;
        m->f0 = 0;
        m->f4 = 0;
        m->fC = 0;
        m->type = 2;
        if (sceKernelSendMbx(gReqMbxID, m) < 0)
            return -1;
        if (sceKernelWaitThreadEnd(gSndReqTID, 0) < 0)
            return -1;
        if (sceKernelDeleteMbx(gReqMbxID) != 0)
            return -1;
        _http_attached = 0;
    }
    return 0;
}
