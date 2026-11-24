#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mpeg", mpegInit);

void mpegExit(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mpeg", mepgAdd);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mpeg", mpegExec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mpeg", mpegEnd);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mpeg", mpegCallback);
