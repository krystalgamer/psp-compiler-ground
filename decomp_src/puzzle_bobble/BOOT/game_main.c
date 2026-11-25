#include "common.h"
#include "m2c_macros.h"

M2C_UNK init_gims();                                /* extern */
M2C_UNK puts(M2C_UNK *);                            /* extern */
extern int FuncInit;
extern int GameStat;
extern int state;
extern int press;


void game_init(void) {
    GameStat = 0;
    FuncInit = 0;
    init_gims();
    puts("gim_init ok");
    puts("SIG_READ DONE ok");
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", game_main);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", KeySync);

int GetKeyStat(void) {
    return state;
}

int GetKeyHit(void) {
    return press;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", LoadFileList);

int ret_GameStat(void) {
    return GameStat;
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", BNum0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", BNum1);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", BNum2);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/game_main", BNum3);
