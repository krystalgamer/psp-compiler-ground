#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_put);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_op);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_opw);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_opn);

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_byte_code_label_new(void *arg0) {
    int var_v0;

    var_v0 = -1;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, int *, 0x18) + 1;
        M2C_FIELD(arg0, int *, 0x18) = var_v0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_label_add);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_label_def);

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned char mes_byte_code_reachable(void *arg0) {
    unsigned char var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, unsigned char *, 0x1C);
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_jump);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_jump_size);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_label_fix);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_free);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_chunk_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_byte_code", mes_byte_code_pack);
