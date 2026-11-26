/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
M2C_UNK mes_eval(int, int, int, int, int);          /* extern */
M2C_UNK mes_stack_init(M2C_UNK);                    /* extern */
M2C_UNK mes_window_set_global_property(int);        /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_common", js_common_buffer_open);

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_common_buffer_close(int arg0) {
    MEM_free(0, arg0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_common", js_common_buffer_getc);

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_common_eval(int arg0, int arg1, int arg2, int arg3, int arg4) {
    mes_stack_init(0x4000);
    mes_window_set_global_property(arg0);
    mes_eval(arg0, arg1, arg2, arg3, arg4);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_common", js_common_execute);
