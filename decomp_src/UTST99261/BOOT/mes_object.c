#include "common.h"
#include "m2c_macros.h"
M2C_UNK mes_object_free_page(int);                  /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_search);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_prop);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_page_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_insert_one);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_insert_page);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_insert);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_set);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_canput);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_delete_one);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_delete_page);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_delete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_prop_next);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_setup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_mark_page);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_mark);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_free_page);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_object_free(void *arg0) {
    mes_object_free_page(M2C_FIELD(arg0, int *, 4));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_initialize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_object);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_to_string);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_value_of);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_has_own_property);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_is_prototype_of);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_property_is_enumerable);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_class_setup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_object_setup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_initialize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_free);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_setup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_stack_init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_stack_check);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", D_0013B384);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", D_0013B390);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", D_0013B3A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", D_0013B3A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", D_0013B3B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", D_0013B3C8);
