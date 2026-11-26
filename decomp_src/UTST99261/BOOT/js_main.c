/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern char D_001339E0[];
M2C_UNK JSDestroyInternal(int);                     /* extern */
int JSEventLoop();                                  /* extern */
M2C_UNK JSInitInternal();                           /* extern */
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
M2C_UNK OS_thread_exit(M2C_UNK);                    /* extern */
extern int js_err_msg;


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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JS_halt);

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
