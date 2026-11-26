#include "common.h"
#include "m2c_macros.h"
extern unsigned char gSnull;
extern unsigned char gSDnull;
extern unsigned char gSHnull;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiStrAcu", ResizeAllocation);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiStrAcu", SDomiStrAcu_Initialize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiStrAcu", SDomiStrAcu_Finalize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiStrAcu", SDomiStrAcu_Reset);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiStrAcu", SDomiStrAcu_Truncate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiStrAcu", SDomiStrAcu_Allocate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiStrAcu", SDomiStrAcu_Insert);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiStrAcu", SDomiStrAcu_Delete);

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *AcsExterngSnull(void) {
    return &gSnull;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *AcsExterngSDnull(void) {
    return &gSDnull;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *AcsExterngSHnull(void) {
    return &gSHnull;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiStrAcu", gSnull);
