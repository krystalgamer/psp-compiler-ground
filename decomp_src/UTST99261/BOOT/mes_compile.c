#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_vars_list);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_vars);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_args);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_find_vars);

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_compile_in_catch(void *arg0, int arg1) {
    int var_a0;
    void *var_v1;

    var_v1 = M2C_FIELD(arg0, void **, 0x1C);
    var_a0 = 0;
    if (var_v1 != NULL) {
loop_1:
        var_a0 = 1;
        if (M2C_FIELD(var_v1, int *, 4) != arg1) {
            var_v1 = M2C_FIELD(var_v1, void **, 0);
            if (var_v1 == NULL) {
                var_a0 = 0;
            } else {
                goto loop_1;
            }
        }
    }
    return var_a0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_set_var);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_get_var);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_get_inc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_op);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_op2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_function);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_expression);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_lhs_expression);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_nest);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_nest_pop);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_nest_out);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_nest_out_try);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_nest_in_try);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_function_declaration);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_statement);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile_body);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", mes_compile);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_compile", D_0013B36C);
