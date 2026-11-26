/* cflags: -O1 */
#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", parseTEXTStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", parseBINARYStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", parseContentStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", parseContentContinue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", parseContentContinueJS);

int *parseJSDocumentEncode(int *enc, int *src) {
    void *buf;
    int n;
    int *d;

    buf = MEM_malloc(0, src[6] * 4);
    n = parseConvertEncode(buf, src[7], src[6], enc[2]);
    d = MEM_malloc(0, 0x14);
    d[3] = 0;
    d[4] = 0;
    d[0] = 1;
    d[2] = (int)buf;
    d[1] = n;
    return d;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", parseContentEnd);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", D_00137DEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", D_00137DF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", D_00137E04);
