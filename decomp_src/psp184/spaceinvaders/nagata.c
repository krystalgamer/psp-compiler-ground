#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", rot2pos_x);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", rot2pos_y);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", rot2posf_x);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", rot2posf_y);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", pos2rot);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", pos2rotf);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", pos_length_check);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", pos_fast_length_check);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", pos_fast_length_xyz_check);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", math_truncated);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", vec_length);

#ifndef NULL
#define NULL ((void *)0)
#endif
int vec_length_fast(int arg0, int arg1) {
    return (arg0 * arg0) + (arg1 * arg1);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", num2str);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sjis_check(void *arg0) {
    return (unsigned int) ((M2C_FIELD(arg0, signed char *, 1) + (M2C_FIELD(arg0, signed char *, 0) << 8)) & 0xFFFF) > 0x813FU;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", num_digit_get0);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", num_digit_get);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", addr_to_int);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A594);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A598);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A59C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5A4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5AC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5B4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5BC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5C4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5C8);
