#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3", mp3Init);

void mp3Exit(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3", mp3Add);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3", mp3Exec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3", mp3End);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3", mp3Callback);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3", D_0010E514);
