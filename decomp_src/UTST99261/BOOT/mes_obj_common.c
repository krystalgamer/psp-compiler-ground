#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_obj_common_constructor_not_allowed(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", mes_obj_common_to_string);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", mes_val2domstr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", isAllowedAsPropertyName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", setNewPropertyReference);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", deleteOldPropertyReference);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", mes_obj_common_addNewReferenceByNameOrId);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", makeHref);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", D_0013F4C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", D_0013F4CC);
