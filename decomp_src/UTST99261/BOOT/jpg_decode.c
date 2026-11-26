/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_decode", decodeHuffmanCode_2FCA4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_decode", decodeHuffmanBlock);

#ifndef NULL
#define NULL ((void *)0)
#endif
int reviseValue_30008(int arg0) {
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_decode", translateRGB_30028);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_decode", decodeMCU);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_decode", decodeJPG);
