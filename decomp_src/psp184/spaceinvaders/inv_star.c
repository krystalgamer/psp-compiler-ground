#include "common.h"
#include "m2c_macros.h"
extern int inv_bg;


INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_star", inv_star_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_star", inv_star_set);

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_star_dispset(int arg0) {
    inv_bg = arg0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_star", inv_star_disp);
