#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdIoInit);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdIoTerm);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdRetryPollSema);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdRetryReadFile);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdRetryReadFileCB);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdRetryReadSector);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdRetryReadSectorCB);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/io", D_000125E0);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/io", D_00012604);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/io", D_00012628);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdRetryOpen);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/io", D_00012640);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/io", D_00012654);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdRetryOpenCB);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdRetryRead);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/io", D_0001269C);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/io", D_000126B4);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/io", D_000126D4);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdRetryReadCB);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdRetryGetStat);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/io", DvdUmdRetryGetStatCB);
