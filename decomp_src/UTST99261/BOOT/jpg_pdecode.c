/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", current_dct);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeHuffmanCode_307A4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeHuffmanBlock_DC_first);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeHuffmanBlock_DC_subsequent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeHuffmanBlock_AC_first);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeHuffmanBlock_AC_subsequent);

#ifndef NULL
#define NULL ((void *)0)
#endif
int reviseValue_30F54(int arg0) {
    int var_v1;

    var_v1 = 0;
    if (arg0 >= 0) {
        var_v1 = 0xFF;
        if (arg0 < 0x100) {
            var_v1 = arg0 & 0xFF;
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", translateRGB_30F74);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeMCU_multi);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeMCU_single);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", inverseDCT_MCU);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeProgressiveJPG);
