/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char gDomiNodeSetEmpty;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeArray", NodeComparator);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeArray", SDomiNodeArray_Finalize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeArray", SDomiNodeArray_DeleteAll);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeArray", SDomiNodeArray_InheritObjInfo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeArray", SDomiNodeArray_FreeTrash);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeArray", SDomiNodeArray_Find);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeArray", SDomiNodeArray_Remove);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeArray", SDomiNodeArray_Put);

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *AcsExterngDomiNodeSetEmpty(void) {
    return &gDomiNodeSetEmpty;
}
