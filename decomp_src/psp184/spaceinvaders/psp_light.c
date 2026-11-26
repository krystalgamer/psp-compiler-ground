/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char D_003538BC;


INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", D_0007A844);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", D_0007A854);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", D_0007A860);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", light_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", light_cnt);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", light_debug_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", light_timer_start);

#ifndef NULL
#define NULL ((void *)0)
#endif

void light_timer_start_no(int arg0, int arg1) {
    void *temp_a0;

    temp_a0 = (arg0 << 7) + &D_003538BC;
    M2C_FIELD(temp_a0, int *, 0x38) = arg1;
    M2C_FIELD(temp_a0, signed char *, 0) = 1;
    M2C_FIELD(temp_a0, int *, 0x30) = 1;
    M2C_FIELD(temp_a0, int *, 0x34) = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", light_timer_ctl);
