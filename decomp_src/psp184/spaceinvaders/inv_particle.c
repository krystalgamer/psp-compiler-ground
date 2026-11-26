#include "common.h"
#include "m2c_macros.h"
extern unsigned char inv_particle;
extern int inv_particle_max;


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void inv_particle_all_init(void) {
    memset(&inv_particle, 0, 0xFDC00U);
    inv_particle_max = 0;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", D_0007CEE8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", D_0007CEEC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", D_0007CEF0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", D_0007CEF4);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", inv_particle_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", inv_particle_check);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", inv_particle_control);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", inv_particle_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", inv_particle_syncsort);
