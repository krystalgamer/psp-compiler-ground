#include "common.h"
#include "m2c_macros.h"
M2C_UNK UDomiMemory_Free(int);                      /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiPtrArray", SDomiPtrArray_Initialize);

#ifndef NULL
#define NULL ((void *)0)
#endif

void SDomiPtrArray_Finalize(void) {
    SDomiPtrArray_Free();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void SDomiPtrArray_Free(void *arg0) {
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0;
    UDomiMemory_Free(M2C_FIELD(arg0, int *, 0xC));
    M2C_FIELD(arg0, int *, 0xC) = 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiPtrArray", SDomiPtrArray_GetItem);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiPtrArray", SDomiPtrArray_Replace);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiPtrArray", SDomiPtrArray_Insert);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiPtrArray", SDomiPtrArray_Remove);
