#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_class_init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_class_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_class_instance_of);

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_class_get(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_class_property_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_class_property_get2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_class_property_set);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_class_property_set2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_class_property_setup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_class_private_set);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_class_private_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_class_call);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_user_mark);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_user_free);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_user_index);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_user_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_user_put);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_class", mes_class_initialize);
