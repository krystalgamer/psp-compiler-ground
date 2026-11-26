#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_list", mes_list_cons);

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_list_member(void *arg0, int arg1) {
    int var_v1;
    void *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    if (var_a0 != NULL) {
loop_1:
        var_v1 = 1;
        if (M2C_FIELD(var_a0, int *, 4) != arg1) {
            var_a0 = M2C_FIELD(var_a0, void **, 0);
            if (var_a0 == NULL) {
                var_v1 = 0;
            } else {
                goto loop_1;
            }
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_list", mes_list_free);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_list", mes_list_free2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_list", mes_list_mark);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_list", mes_list_tail_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_list", mes_list_tail_add);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_list", mes_list_tail_find);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_list", mes_list_tail_to_vals);
