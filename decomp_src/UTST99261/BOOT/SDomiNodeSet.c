/* cflags: -O1 */
#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeSet", PrepareArray);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeSet", SDomiNodeSet_Initialize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeSet", SDomiNodeSet_Finalize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeSet", SDomiNodeSet_length);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeSet", SDomiNodeSet_item);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNodeSet", SDomiNodeSet_Free);
