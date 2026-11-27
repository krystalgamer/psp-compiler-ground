/* cflags: -O1 */
#include "common.h"
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_new", http_new);

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
