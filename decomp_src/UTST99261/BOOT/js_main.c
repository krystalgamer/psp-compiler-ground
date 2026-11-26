/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
#include "dom_esp.h"
extern int *js_err_msg;
extern void *jsapi_lock;
extern char D_001339E0[];
M2C_UNK JSDestroyInternal(int);                     /* extern */
int JSEventLoop();                                  /* extern */
M2C_UNK JSInitInternal();                           /* extern */
M2C_UNK OS_thread_exit(M2C_UNK);                    /* extern */


void JSStartInternal(int x) {
    int m[8];

    SetIpcMember(m, 8, x, 1, 0x801, 0, 0, 0);
    JSSendMail(m, D_001339E0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSRunInternal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSFreeJSPtrInternal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSHandleEventInternal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSDestroyInternal);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", D_001339E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", D_001339EC);

void JS_halt(void) {
    int *g;
    JSMsg m;
    JSMsgBody b;
    JSMsg *msg;
    JSMsgBody *bp;

    g = get_global_ptr();
    msg = (JSMsg *)g[0];
    bp = &msg->body;
    bp->type = 8;
    bp->cmd = 0xFFFF;
    bp->x18 = 0;
    bp->x1C = 0;
    if (js_err_msg != NULL) {
        js_err_msg[0] = -1;
        js_err_msg[1] = (int)"AllocationError(JS)";
        bp->x18 = 8;
        bp->x1C = (int)js_err_msg;
        js_err_msg = NULL;
    }
    OS_mq_send(g[8], (void *)g[0], 0x24, 0);
    MEM_free(0, (void *)g[0]);
    g[0] = 0;
    OS_thread_mutex_unlock(jsapi_lock);
    if (g[4] == 0) {
        do {
            if (OS_mq_receive(g[5], &m, 0x24, 0) < 0) {
                break;
            }
            b = m.body;
        } while (b.type != 4 || b.cmd != 0x403);
    }
    mes_id_free();
    JSDestroyInternal(b.x04);
    OS_thread_exit(0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSInitInternal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSEventLoop);

#ifndef NULL
#define NULL ((void *)0)
#endif

int esp_jsThread(void) {
    int temp_s1;

    js_err_msg = 0;
    JSInitInternal();
    temp_s1 = JSEventLoop();
    if (js_err_msg != 0) {
        MEM_free(0, js_err_msg);
    }
    JSDestroyInternal(temp_s1);
    OS_thread_exit(0);
    return 0;
}
