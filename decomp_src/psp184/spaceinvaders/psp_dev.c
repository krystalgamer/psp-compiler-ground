/* cflags: -O2 */
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

extern int double_buffer;
extern int exit_cb;
extern int gPowerCallBackId;
extern unsigned char g_launch_buf;
int sceGeEdramGetSize(void);
void *sceGeEdramGetAddr(void);
int exit_func(void);
static int powercallback(int unknown, int pwrflags, void *common);
int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sceKernelRegisterExitCallback(int cbid);
int scePowerRegisterCallback(int slot, int cbid);
void psp_begin_scene(void);
void psp_end_scene(void);
void sceGuCallList(const void *list);
int sceGuFinish(void);
int sceKernelPowerTick(int type);
int pad_read(void);

extern int game_count;
extern float game_cursol_alpha;
void psp_draw_objects(void);
void psp_swap_buffers(void);
void file_async_control(void);
float sinf(float x);

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

void psp_sxit_callback(void)
{
	int arg[4];

	arg[0] = 0x100;
	exit_cb = sceKernelCreateCallback("name", exit_func, arg);
	sceKernelRegisterExitCallback(exit_cb);
	gPowerCallBackId = sceKernelCreateCallback("POWER", powercallback, 0);
	scePowerRegisterCallback(0, gPowerCallBackId);
}

extern int double_buffer;
extern int exit_cb;
extern int gPowerCallBackId;
extern unsigned char g_launch_buf;
int sceGeEdramGetSize(void);
void *sceGeEdramGetAddr(void);
int exit_func(void);
static int powercallback(int unknown, int pwrflags, void *common);
int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sceKernelRegisterExitCallback(int cbid);
int scePowerRegisterCallback(int slot, int cbid);
void psp_begin_scene(void);
void psp_end_scene(void);
void sceGuCallList(const void *list);
int sceGuFinish(void);
int sceKernelPowerTick(int type);
int pad_read(void);
void psp_edram_init(void)
{
	int size;
	int off;

	size = sceGeEdramGetSize();
	off = 0x154000;
	myHeapInit((int)sceGeEdramGetAddr() + off, size - off);
}

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

void psp_loopstart(void)
{
	if (double_buffer) {
		sceGuStart(0, &g_launch_buf, 0x1000);
		psp_begin_scene();
		if (g_packet >= 0)
			sceGuCallList(&g_packet_buf + (g_packet << 20));
		psp_end_scene();
		sceGuFinish();
		g_packet = g_packet == 0;
		sceGuStart(1, &g_packet_buf + (g_packet << 20), 0x100000);
	} else {
		sceGuStart(0, &g_packet_buf, 0x100000);
		psp_begin_scene();
	}
	sceKernelPowerTick(0);
	pad_read();
}

extern int game_count;
extern float game_cursol_alpha;
void psp_draw_objects(void);
void psp_swap_buffers(void);
void file_async_control(void);
float sinf(float x);
void psp_loopend(void)
{
	if (double_buffer) {
		psp_draw_objects();
	} else {
		psp_draw_objects();
		psp_end_scene();
	}
	sceGuFinish();
	psp_swap_buffers();
	file_async_control();
	genrand_int32();
	game_count++;
	game_cursol_alpha = sinf((float)((game_count % 45) * 4) / 180.0f * 3.1415927f);
}

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
