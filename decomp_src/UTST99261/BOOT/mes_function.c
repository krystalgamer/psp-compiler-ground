#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", mes_function_constructor);

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_function_undefined(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", mes_function_apply);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", mes_function_call);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", mes_function_to_string);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", mes_function_class_setup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", mes_function_setup);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", D_0013B870);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", D_0013B87C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", D_0013B884);
