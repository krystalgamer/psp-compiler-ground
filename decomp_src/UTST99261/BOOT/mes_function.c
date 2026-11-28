/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern void *mes_classes[];
extern unsigned int mes_ids[];
extern void *mes_function_table;
int mes_function_constructor();
void mes_object_set(void *obj, unsigned int id, int value, int flags);
void mes_native_setup(void *ctx, void *o, void *table, int n);
typedef struct MesNative {
    int f0, f4;
    int f8;
} MesNative;
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
    MesNative *n = mes_native_new(ctx, (*(int *)((char *)&mes_ids + 0x108)), mes_function_undefined, 0, 0);

    n->f8 = x;
    (*(MesNative * *)((char *)mes_classes + 0x14)) = n;
}

void mes_function_setup(void *ctx)
{
    MesNative *proto = (*(MesNative * *)((char *)mes_classes + 0x14));
    MesNative *ctor;

    ctor = mes_native_new(ctx, mes_ids[5], mes_function_constructor, 1, 1);
    mes_object_set(*(void **)((char *)ctx + 0xC), mes_ids[5], (int)ctor, 7);
    mes_object_set(ctor, mes_ids[59], (int)proto, 7);
    mes_object_set(proto, mes_ids[40], (int)ctor, 2);
    mes_native_setup(ctx, proto, &mes_function_table, 3);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", D_0013B870);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", D_0013B87C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_function", D_0013B884);
