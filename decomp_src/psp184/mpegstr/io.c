#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdIoInit);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdIoTerm);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryPollSema);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryReadFile);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryReadFileCB);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryReadSector);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryReadSectorCB);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_000125B0);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_000125D4);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_000125F8);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryOpen);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_00012610);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_00012624);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryOpenCB);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryRead);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_0001266C);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_00012684);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/io", D_000126A4);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryReadCB);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryGetStat);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/io", DvdUmdRetryGetStatCB);
