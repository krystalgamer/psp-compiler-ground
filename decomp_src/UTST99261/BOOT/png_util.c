/* cflags: -O1 */
#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", checkSignature);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", png_createContext);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", png_destroyContext);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", png_initializeContext);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", png_setBuffer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", png_readHeader);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", png_decode);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", D_001326E8);
