#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", loadModule);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", unloadModule);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", ringbufferCallBack);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", mpeg_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", mpeg_end);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", mpeg_main);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", readHeader);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", readPspStream);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", startCheck);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", playMovie);
