/* cflags: -O1 */
#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", current_dct);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeHuffmanCode_307A4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeHuffmanBlock_DC_first);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeHuffmanBlock_DC_subsequent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeHuffmanBlock_AC_first);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeHuffmanBlock_AC_subsequent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", reviseValue_30F54);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", translateRGB_30F74);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeMCU_multi);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeMCU_single);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", inverseDCT_MCU);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeProgressiveJPG);
