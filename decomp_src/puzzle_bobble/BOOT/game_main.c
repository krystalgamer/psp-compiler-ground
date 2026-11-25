#include "common.h"

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", game_init);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", game_main);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", KeySync);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", GetKeyStat);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", GetKeyHit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", LoadFileList);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", ret_GameStat);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", BNum0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", BNum1);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", BNum2);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", BNum3);
