#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", exit_func);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", powercallback);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_sxit_callback);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_edram_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_init2);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A6C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A700);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A70C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A718);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A724);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A730);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A73C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A748);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A754);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A760);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A768);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A774);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A77C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A788);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A794);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A7A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A7AC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", D_0007A7B8);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_begin_scene);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_end_scene);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_swap_buffers);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_draw_objects);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_loopstart);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_loopend);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_debug_init);

void debug_text(void) {
}

void debug_poly_col(void) {
}

void debug_poly_rgba(void) {
}

void psp_debug_disp(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", square_draw);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", mat_local2world);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", MatrixVectorMultiply);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", mat_local2screen);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", vec_rot_xyz);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", vec_rot_zyx);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", vec_roll_yxz);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", vec_roll_zxy);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", vec_roll_yxz_rv);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", vec_roll_zxy_rv);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", vec_one);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", vec_axis_rot);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", time_wait);
