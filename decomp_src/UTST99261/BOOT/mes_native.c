#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_native", mes_native_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_native", mes_native_setup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_native", mes_native_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_native", mes_native_put);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_native", mes_native_mark);

#ifndef NULL
#define NULL ((void *)0)
#endif
void mes_native_free(void *arg0) {
    mes_object_free(arg0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_native", mes_native_initialize);
