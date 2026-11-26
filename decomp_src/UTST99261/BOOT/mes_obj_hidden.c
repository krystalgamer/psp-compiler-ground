#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_hidden", mes_hidden_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_hidden", mes_hidden_put);

void mes_hidden_mark(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_hidden", mes_hidden_class_init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_hidden", mes_hidden_new);
