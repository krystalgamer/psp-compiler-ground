/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct JsBuf {
    unsigned char *cur;
    unsigned char *end;
} JsBuf;
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
M2C_UNK mes_eval(int, int, int, int, int);          /* extern */
M2C_UNK mes_stack_init(M2C_UNK);                    /* extern */
M2C_UNK mes_window_set_global_property(int);        /* extern */


JsBuf *js_common_buffer_open(unsigned char *p, int len) {
    JsBuf *b;

    b = MEM_malloc(0, sizeof(JsBuf));
    if (b != NULL) {
        if (p == NULL || len == 0) {
            b->cur = NULL;
            b->end = NULL;
        } else {
            b->cur = p;
            b->end = p + len - 1;
        }
    }
    return b;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_common_buffer_close(int arg0) {
    MEM_free(0, arg0);
}

int js_common_buffer_getc(JsBuf *b) {
    if (b->cur != NULL && b->cur <= b->end) {
        return *b->cur++;
    }
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_common_eval(int arg0, int arg1, int arg2, int arg3, int arg4) {
    mes_stack_init(0x4000);
    mes_window_set_global_property(arg0);
    mes_eval(arg0, arg1, arg2, arg3, arg4);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_common", js_common_execute);
