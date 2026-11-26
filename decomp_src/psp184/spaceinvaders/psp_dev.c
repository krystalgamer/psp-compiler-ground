/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char g_matrix_buf;
extern int g_packet;
extern unsigned char g_packet_buf;
M2C_UNK camera_control();                           /* extern */
M2C_UNK gmo_disp();                                 /* extern */
M2C_UNK inv_particle_disp();                        /* extern */
M2C_UNK inv_star_disp();                            /* extern */
M2C_UNK light_cnt();                                /* extern */
M2C_UNK light_debug_disp();                         /* extern */
M2C_UNK sprite_3d_disp();                           /* extern */
M2C_UNK sprite_bg_disp();                           /* extern */
M2C_UNK sprite_scr_disp();                          /* extern */
M2C_UNK sprite_syncsort();                          /* extern */
extern unsigned char deb_print;


#ifndef NULL
#define NULL ((void *)0)
#endif
void sceKernelExitGame(void);
extern int power_callback_flag;
unsigned long genrand_int32(void);
int utility_update_shutdown(void);
int sceGeEdramGetSize(void);
void *sceGeEdramGetAddr(void);
void myHeapInit(int addr, int size);

int exit_func(void) {
    UtilityClose();
    sceKernelExitGame();
    return 0;
}

extern int power_callback_flag;
unsigned long genrand_int32(void);
int utility_update_shutdown(void);
int sceGeEdramGetSize(void);
void *sceGeEdramGetAddr(void);
void myHeapInit(int addr, int size);
static int powercallback(int unknown, int pwrflags, void *common)
{
	genrand_int32();
	if (pwrflags < 0)
		utility_update_shutdown();
	power_callback_flag = pwrflags;
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_sxit_callback);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_edram_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_init);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuInit(void);
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);

void psp_init2(void) {
    sceGuTerm();
    sceGuInit();
    sceGuStart(0, &g_packet_buf, 0x100000);
    sceGuDrawBuffer(0, NULL, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, (void *)0x44000, 0x200);
    sceGuDepthBuffer((void *)0x88000, 0x200);
    sceGuOffset(0x710U, 0x778U);
    sceGuFinish();
    sceGuSync(0, 0);
    sceGumSetMatrixStack(&g_matrix_buf, 4, 4, 8, 0);
    sceGuDisplay(1);
    g_packet = 0;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif

void psp_draw_objects(void) {
    sprite_syncsort();
    sprite_bg_disp();
    camera_control();
    light_cnt();
    light_debug_disp();
    inv_star_disp();
    gmo_disp();
    inv_particle_disp();
    sprite_3d_disp();
    sprite_scr_disp();
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_loopstart);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_dev", psp_loopend);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void psp_debug_init(void) {
    memset(&deb_print, 0, 0x1388U);
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int sceKernelGetSystemTimeLow(void);
void time_wait(unsigned int arg0) {
    unsigned int temp_s0;
    unsigned int temp_v0;

    temp_s0 = sceKernelGetSystemTimeLow();
loop_1:
    temp_v0 = sceKernelGetSystemTimeLow();
    if (temp_v0 >= temp_s0) {
        if (arg0 >= (unsigned int) (temp_v0 - temp_s0)) {
            goto loop_1;
        }
    }
}
