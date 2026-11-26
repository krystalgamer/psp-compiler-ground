#include "common.h"
#include "m2c_macros.h"
M2C_UNK bcopy();                                    /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_memory_copy(void) {
    bcopy();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_memory", mes_memory_zero);
