#include "common.h"

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/main", ringbufferCallBack);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/main", MovieTestEntry);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/main", MovieTest);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/main", startCheck);

INCLUDE_RODATA("tmp/asm/umdt/movietest/nonmatchings/main", D_00006CC4);

INCLUDE_RODATA("tmp/asm/umdt/movietest/nonmatchings/main", D_00006CE0);

INCLUDE_RODATA("tmp/asm/umdt/movietest/nonmatchings/main", D_00006CFC);

INCLUDE_RODATA("tmp/asm/umdt/movietest/nonmatchings/main", D_00006D24);

INCLUDE_RODATA("tmp/asm/umdt/movietest/nonmatchings/main", D_00006D38);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/main", playMovie);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/main", readHeader);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/main", MovieTestVersion);
