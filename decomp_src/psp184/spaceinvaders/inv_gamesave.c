/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char save_data;


INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", inv_save_data_init);

#ifndef NULL
#define NULL ((void *)0)
#endif

int inv_save_data_sum_check(void) {
    int var_a1;
    int var_v1;
    unsigned char *var_a0;
    unsigned char temp_v0;

    var_a0 = &save_data;
    var_a1 = 0;
    var_v1 = 0x45F;
    do {
        temp_v0 = *var_a0;
        var_v1 -= 1;
        var_a0 += 1;
        var_a1 += temp_v0;
    } while (var_v1 >= 0);
    return var_a1;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E8E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E8F4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E900);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E90C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E918);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E924);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E930);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E93C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E948);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E94C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E95C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E96C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E980);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E994);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E9A8);
