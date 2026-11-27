/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char mes_number_method;

M2C_UNK fmod();                                     /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_alloc_int32);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_alloc_uint32);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_alloc);

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_is_number(int arg0) {
    int var_a0;
    unsigned int temp_v0;

    temp_v0 = arg0 & 3;
    var_a0 = (unsigned int) (arg0 - 0x10) < 0xDU;
    if (temp_v0 != 0) {
        var_a0 = 0;
        if (temp_v0 < 3U) {
            var_a0 = 1;
        }
    }
    return var_a0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_num);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_floor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_fdiv);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_number_fmod(void) {
    fmod();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_add);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_minus);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_mul);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_div);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_mod);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_equal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_less);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B760);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B764);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B768);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B76C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B770);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B774);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B778);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B77C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B780);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B784);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B788);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B78C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B790);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B794);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B798);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B79C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7B4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_from_string);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_number_initialize(void) {
    mes_gc_register(&mes_number_method, 0x10, 0x64, 0x64);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_constructor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_special);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7C4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_str);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_value_of);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_fixed_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_fixed);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_exponential_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_exponential);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_precision_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_precision);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_to_string);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B7FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B80C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", mes_number_setup);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_number", D_0013B830);
