#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_streq);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_streq2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_streq3);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_streq4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_strcp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_strcp2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_free);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_pos);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_put);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_puts);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_puti);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_put_string);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_eq);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_string_eq2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_expt);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_is_white_space);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_is_line_terminator);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_is_blank);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_is_alpha_digit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_is_word_char);

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_util_digit(int arg0) {
    int var_a0;

    var_a0 = (arg0 & 0xFFFF) - 0x30;
    if ((unsigned int) (var_a0 & 0xFFFF) >= 0xAU) {
        var_a0 = -1;
    }
    return var_a0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_util_octal(int arg0) {
    int var_a0;

    var_a0 = (arg0 & 0xFFFF) - 0x30;
    if ((unsigned int) (var_a0 & 0xFFFF) >= 8U) {
        var_a0 = -1;
    }
    return var_a0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_hex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_hex_char);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_vals);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_vals_free);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_vals_mark);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_char_in);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_to_upper);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", mes_util_to_lower);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", D_0013A450);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_util", D_0013A454);
