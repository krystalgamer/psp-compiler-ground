#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3DecodeInit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3GetHeader);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3GetLastError);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3FindSync);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3GetDecodeOption);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3SetDecodeOption);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3SetEqualizer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", extractInt4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", br_tbl);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", fr_tbl);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3GetDecodeInfo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3DecodeStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3DecodeFrame);

void null_frame_proc(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3MuteStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3MuteEnd);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", D_0010F198);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", D_0010F19C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", D_0010F1A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", D_0010F1A4);
