/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct MesNative {
    int f0, f4;
    int f8;
} MesNative;
extern int D_00585320;
extern MesNative *D_00585344;
int mes_function_undefined();
MesNative *mes_native_new(void *ctx, int proto, int (*fn)(), int a, int b);


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

void mes_function_class_setup(void *ctx, int x)
{
    MesNative *n = mes_native_new(ctx, D_00585320, mes_function_undefined, 0, 0);

    n->f8 = x;
    D_00585344 = n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", mes_function_setup);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", D_0013B870);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", D_0013B87C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", D_0013B884);
