/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
typedef struct { float x, y, z; } FVEC3;
typedef struct { float x, y, z, w; } FVEC4;
typedef struct { FVEC4 x, y, z, w; } FMAT4;
float sinf(float x);
float cosf(float x);
#define DEG2RAD(a) ((a) / 180.0f * 3.1415927f)
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

void pad_init(); void psp_malloc_init(); void file_init(); void psp_debug_init(); void psp_sxit_callback();
void light_init(); void gmo_init(); void camera_init(); void tex_init(); void inv_laser_all_init(); void inv_ring_all_init();
void inv_star_init(); void inv_screffect_all_init(); void inv_particle_all_init(); void init_genrand(unsigned long s);
void inv_nowloading_tex_load(); void inv_font_all_init(); void inv_font_tex_set(int, int); int bmp_file_load();
void psp_loopstart(); void psp_loopend(); void inv_nowloading_disp2(); void inv_save_data_init(); void sound_init(); void se_load(); void mpeg_init();
void sceGimPictureSetMemoryManager(); void sceGimPictureSetMemoryManager2(); void sceGmoModelSetMemoryManager(); void sceGmoModelSetMemoryManager2();
void *psp_malloc(); void psp_free(); void *psp_malloc16(); void *myHeapAlloc(); void myHeapFree();
void psp_init(void) {
    pad_init();
    psp_malloc_init();
    file_init();
    psp_debug_init();
    sceGuInit();
    sceGuStart(0, &g_packet_buf, 0x100000);
    sceGuDrawBuffer(0, NULL, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, (void *)0x44000, 0x200);
    sceGuDepthBuffer((void *)0x88000, 0x200);
    sceGuOffset(0x710U, 0x778U);
    sceGuFinish();
    sceGuSync(0, 0);
    sceGumSetMatrixStack(&g_matrix_buf, 4, 4, 8, 0);
    psp_edram_init();
    sceGimPictureSetMemoryManager(psp_malloc, psp_free);
    sceGimPictureSetMemoryManager2(psp_malloc16, psp_free);
    sceGmoModelSetMemoryManager(psp_malloc, psp_free);
    sceGmoModelSetMemoryManager2(myHeapAlloc, myHeapFree);
    psp_sxit_callback();
    light_init();
    gmo_init();
    camera_init();
    tex_init();
    inv_laser_all_init();
    inv_ring_all_init();
    inv_star_init();
    inv_screffect_all_init();
    inv_particle_all_init();
    init_genrand(0);
    sceGuDisplay(1);
    inv_nowloading_tex_load("loading.bmp");
    inv_font_all_init();
    inv_font_tex_set(bmp_file_load("font.bmp"), 2);
    psp_loopstart();
    inv_nowloading_disp2();
    psp_loopend();
    psp_loopstart();
    inv_nowloading_disp2();
    psp_loopend();
    inv_save_data_init();
    sound_init();
    se_load();
    mpeg_init();
    psp_loopstart();
    psp_loopend();
    psp_loopstart();
    psp_loopend();
}

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

typedef struct { int m[16]; } DITHER_T;
/* the dither matrix is 16-byte aligned (ScePspIMatrix4); while this unit is mixed, pad explicitly */
const int D_0007A6B8[2] = { 0, 0 };
const DITHER_T D_0007A6C0 = { { -4, 0, -3, 1, 2, -2, 3, -1, -3, 1, -4, 0, 3, -1, 2, -2 } };

const FVEC3 D_0007A700 = { 0.0f, 0.0f, 50.0f };

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

typedef struct { int mode; float fovy; FVEC3 pos; FVEC3 rot; FVEC3 hist[8]; float far; FVEC3 center; FVEC3 up; int f9C; } CAMERA_D;
extern CAMERA_D camera;
void sceGuViewport(int cx, int cy, int width, int height);
void sceGuDepthRange(int near, int far);
void sceGuScissor(int x, int y, int w, int h);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuClear(int flags);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumLookAt(FVEC3 *eye, FVEC3 *center, FVEC3 *up);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGuFog(float near, float far, unsigned int color);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuDepthFunc(int function);
void sceGuFrontFace(int order);
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGuSetDither(const DITHER_T *matrix);
void sceGuShadeModel(int mode);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void psp_begin_scene(void)
{
	DITHER_T dith = D_0007A6C0;
	FVEC3 eye, center;

	sceGuViewport(2048, 2048, 480, 272);
	sceGuDepthRange(0xE000, 0x1000);
	sceGuScissor(0, 0, 480, 272);
	sceGuEnable(2);
	sceGuClearColor(0xFF000000);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuClear(7);
	sceGumMatrixMode(1);
	sceGumLoadIdentity();
	if (camera.mode == 0) {
		eye = D_0007A700;
		center.x = 0;
		center.y = 0;
		center.z = 0;
		sceGumLookAt(&eye, &center, &camera.up);
	} else {
		sceGumLookAt(&camera.pos, &camera.center, &camera.up);
	}
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(camera.fovy, 480.0f / 272.0f, 10.0f, 1000000.0f);
	sceGumMatrixMode(2);
	sceGuFog(2000.0f, 20000.0f, 0xFF000000);
	sceGuEnable(7);
	sceGuAlphaFunc(7, 0, 255);
	sceGuEnable(0);
	sceGuDepthFunc(7);
	sceGuEnable(1);
	sceGuFrontFace(1);
	sceGuEnable(5);
	sceGuEnable(20);
	sceGuEnable(16);
	sceGuPatchDivide(4, 4);
	sceGuDisable(9);
	sceGuSetDither(&dith);
	sceGuEnable(6);
	sceGuEnable(8);
	sceGuShadeModel(1);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuEnable(4);
}

extern int D_005FB7BC, debug_print, game_cpu_disp, game_time, inv_bg_disp_time;
extern int inv_laser_disp_max, inv_laser_disp_time, inv_ring_disp_max, inv_ring_disp_time;
extern int inv_particle_disp_max, inv_particle_disp_time, inv_screfc_disp_max, inv_screfc_disp_time;
extern int inv_scrdisp_disp_max, inv_scrdisp_disp_time, gmo_file_max, gmo_disp_max, gmo_disp_time;
extern int tex_file_max, sprite_disp_max, sprite_disp_time, billbord_disp_max, billbord_disp_time;
extern int g_cpu_load, g_gpu_load;
extern unsigned int malloc_max_size;
extern int sce_newlib_heap_kb_size, myHeap_size, myHeap_freesize;
extern char D_0007A70C[], D_0007A718[], D_0007A724[], D_0007A730[], D_0007A73C[], D_0007A748[], D_0007A754[];
extern char D_0007A760[], D_0007A768[], D_0007A774[], D_0007A77C[], D_0007A788[], D_0007A794[], D_0007A7A0[];
extern char D_0007A7AC[], D_0007A7B8[];
int sprintf(char *buf, const char *fmt, ...);
void debug_text();
void debug_poly_col();
void psp_debug_disp(void);
void psp_end_scene(void)
{
	char buf[64];

	if (D_005FB7BC == 0) {
		debug_print = 0;
		game_cpu_disp = 0;
	}
	if (game_cpu_disp) {
		sprintf(buf, D_0007A794, g_cpu_load);
		debug_text(10, 230, buf);
		debug_poly_col(82, 231, g_cpu_load, 7, 0x8F00);
		sprintf(buf, D_0007A7A0, g_gpu_load);
		debug_text(10, 240, buf);
		debug_poly_col(82, 241, g_gpu_load, 7, 0x800F);
		sprintf(buf, D_0007A7AC, malloc_max_size >> 10, sce_newlib_heap_kb_size - (malloc_max_size >> 10));
		debug_text(10, 250, buf);
		sprintf(buf, D_0007A7B8, myHeap_size / 1024, myHeap_freesize / 1024);
		debug_text(10, 260, buf);
	}
	if (game_cpu_disp == 2) {
		sprintf(buf, D_0007A70C, game_time);
		debug_text(390, 150, buf);
		debug_poly_col(380, 158, 100, 2, 0x8F82);
		sprintf(buf, D_0007A718, inv_bg_disp_time);
		debug_text(390, 160, buf);
		sprintf(buf, D_0007A724, inv_laser_disp_max, inv_laser_disp_time);
		debug_text(390, 170, buf);
		sprintf(buf, D_0007A730, inv_ring_disp_max, inv_ring_disp_time);
		debug_text(390, 180, buf);
		sprintf(buf, D_0007A73C, inv_particle_disp_max, inv_particle_disp_time);
		debug_text(390, 190, buf);
		sprintf(buf, D_0007A748, inv_screfc_disp_max, inv_screfc_disp_time);
		debug_text(390, 200, buf);
		sprintf(buf, D_0007A754, inv_scrdisp_disp_max, inv_scrdisp_disp_time);
		debug_text(390, 210, buf);
		debug_poly_col(380, 218, 100, 2, 0x8F82);
		sprintf(buf, D_0007A760, gmo_file_max);
		debug_text(390, 220, buf);
		sprintf(buf, D_0007A768, gmo_disp_max, gmo_disp_time);
		debug_text(390, 230, buf);
		debug_poly_col(380, 238, 100, 2, 0x8F82);
		sprintf(buf, D_0007A774, tex_file_max);
		debug_text(390, 240, buf);
		sprintf(buf, D_0007A77C, sprite_disp_max, sprite_disp_time);
		debug_text(390, 250, buf);
		sprintf(buf, D_0007A788, billbord_disp_max, billbord_disp_time);
		debug_text(390, 260, buf);
	}
	psp_debug_disp();
}

extern void *dbp;
extern int g_cpu_load, g_frame, g_gpu_load, g_vbl_count, g_vbl_step;
extern int g_vbl_time;
unsigned int sceKernelGetSystemTimeLow(void);
int sceGuSync(int mode, int what);
int sceDisplayWaitVblankStartCB(void);
void *sceGuSwapBuffers(void);
int sceDisplayGetVcount(void);
void psp_swap_buffers(void)
{
	int t0, t1, t2;
	int vc;

	t0 = sceKernelGetSystemTimeLow();
	sceGuSync(0, 0);
	t1 = sceKernelGetSystemTimeLow();
	sceDisplayWaitVblankStartCB();
	dbp = sceGuSwapBuffers();
	g_frame++;
	t2 = sceKernelGetSystemTimeLow();
	vc = sceDisplayGetVcount();
	if (g_vbl_count >= 0) {
		g_vbl_step = vc - g_vbl_count;
		g_cpu_load = (t0 - g_vbl_time) * 100 / 16667;
		g_gpu_load = (t1 - g_vbl_time) * 100 / 16667;
	}
	g_vbl_time = t2;
	g_vbl_count = vc;
}

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

typedef struct { short u, v; short x, y, z; } SQVTX;
void *sceGuGetMemory(int size);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuEnable(int state);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void square_draw(int x, int y, int w, int h, int col)
{
	short *v = sceGuGetMemory(16);

	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuEnable(4);
	v[0] = col;
	v[1] = x;
	v[2] = y;
	v[3] = 0;
	v[4] = col;
	v[5] = x + w;
	v[6] = y + h;
	v[7] = 0;
	sceGuDrawArray(6, 0x800118, 2, NULL, v);
}

void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumStoreMatrix(FMAT4 *m);
void mat_local2world(float *v, float *o)
{
	FMAT4 m;

	sceGumPushMatrix();
	sceGumStoreMatrix(&m);
	sceGumPopMatrix();
	o[0] = m.x.x * v[0] + m.y.x * v[1] + m.z.x * v[2] + m.w.x * v[3];
	o[1] = m.x.y * v[0] + m.y.y * v[1] + m.z.y * v[2] + m.w.y * v[3];
	o[2] = m.x.z * v[0] + m.y.z * v[1] + m.z.z * v[2] + m.w.z * v[3];
}

void MatrixVectorMultiply(FVEC4 *o, FMAT4 *m, FVEC4 *v)
{
	o->x = v->x * m->x.x + v->y * m->y.x + v->z * m->z.x + v->w * m->w.x;
	o->y = v->x * m->x.y + v->y * m->y.y + v->z * m->z.y + v->w * m->w.y;
	o->z = v->x * m->x.z + v->y * m->y.z + v->z * m->z.z + v->w * m->w.z;
	o->w = v->x * m->x.w + v->y * m->y.w + v->z * m->z.w + v->w * m->w.w;
}

void sceGumMatrixMode(int mode);
void sceGumLoadMatrix(const FMAT4 *m);
void sceGumMultMatrix(const FMAT4 *m);
void mat_local2screen(FVEC3 *v, FVEC3 *o)
{
	FMAT4 m, proj, view, model;
	FVEC4 in, out;

	sceGumMatrixMode(0);
	sceGumStoreMatrix(&proj);
	sceGumMatrixMode(1);
	sceGumStoreMatrix(&view);
	sceGumMatrixMode(2);
	sceGumStoreMatrix(&model);
	sceGumPushMatrix();
	sceGumLoadMatrix(&proj);
	sceGumMultMatrix(&view);
	sceGumMultMatrix(&model);
	sceGumStoreMatrix(&m);
	sceGumPopMatrix();
	in.x = v->x;
	in.y = v->y;
	in.z = v->z;
	in.w = 1.0f;
	MatrixVectorMultiply(&out, &m, &in);
	if (out.w > -0.01f && out.w < 0.01f)
		out.w = 0.01f;
	o->x = out.x * 240.0f / out.w + 240.0f;
	o->y = -out.y * 136.0f / out.w + 136.0f;
	o->z = out.w;
}

float sinf(float x);
float cosf(float x);
void vec_rot_xyz(FVEC3 *base, FVEC3 *r, FVEC3 *o, float len)
{
	FVEC3 p, a, b, c;

	p.x = 0.0f;
	p.y = 0.0f;
	p.z = len;
	a.x = p.x;
	a.y = p.y * cosf(DEG2RAD(-r->x)) + p.z * sinf(DEG2RAD(-r->x));
	a.z = p.y * -sinf(DEG2RAD(-r->x)) + p.z * cosf(DEG2RAD(-r->x));
	b.x = a.x * cosf(DEG2RAD(-r->y)) - sinf(DEG2RAD(-r->y)) * a.z;
	b.y = a.y;
	b.z = a.x * sinf(DEG2RAD(-r->y)) + a.z * cosf(DEG2RAD(-r->y));
	c.x = b.x * cosf(DEG2RAD(-r->z)) + b.y * sinf(DEG2RAD(-r->z));
	c.y = b.x * -sinf(DEG2RAD(-r->z)) + b.y * cosf(DEG2RAD(-r->z));
	c.z = b.z;
	o->x = base->x + c.x;
	o->y = base->y + c.y;
	o->z = base->z + c.z;
}

void vec_rot_zyx(FVEC3 *base, FVEC3 *r, FVEC3 *o, float len)
{
	FVEC3 p = { 0.0f, 0.0f, len };
	FVEC3 a, b, c;

	c.x = p.x * cosf(DEG2RAD(-r->z)) + p.y * sinf(DEG2RAD(-r->z));
	c.y = p.x * -sinf(DEG2RAD(-r->z)) + p.y * cosf(DEG2RAD(-r->z));
	c.z = p.z;
	b.x = c.x * cosf(DEG2RAD(-r->y)) - sinf(DEG2RAD(-r->y)) * c.z;
	b.y = c.y;
	b.z = c.x * sinf(DEG2RAD(-r->y)) + c.z * cosf(DEG2RAD(-r->y));
	a.x = b.x;
	a.y = b.y * cosf(DEG2RAD(-r->x)) + b.z * sinf(DEG2RAD(-r->x));
	a.z = b.y * -sinf(DEG2RAD(-r->x)) + b.z * cosf(DEG2RAD(-r->x));
	o->x = base->x + a.x;
	o->y = base->y + a.y;
	o->z = base->z + a.z;
}

void vec_roll_yxz(FVEC3 *v, FVEC3 *r, FVEC3 *o)
{
	FVEC3 a, b;

	b.x = v->x * cosf(DEG2RAD(r->y)) - sinf(DEG2RAD(r->y)) * v->z;
	b.y = v->y;
	b.z = v->x * sinf(DEG2RAD(r->y)) + v->z * cosf(DEG2RAD(r->y));
	a.x = b.x;
	a.y = b.y * cosf(DEG2RAD(r->x)) + b.z * sinf(DEG2RAD(r->x));
	a.z = b.y * -sinf(DEG2RAD(r->x)) + b.z * cosf(DEG2RAD(r->x));
	o->x = a.x * cosf(DEG2RAD(r->z)) + a.y * sinf(DEG2RAD(r->z));
	o->y = a.x * -sinf(DEG2RAD(r->z)) + a.y * cosf(DEG2RAD(r->z));
	o->z = a.z;
}

void vec_roll_zxy(FVEC3 *v, FVEC3 *r, FVEC3 *o)
{
	FVEC3 a, b;

	b.x = v->x * cosf(DEG2RAD(r->z)) + v->y * sinf(DEG2RAD(r->z));
	b.y = v->x * -sinf(DEG2RAD(r->z)) + v->y * cosf(DEG2RAD(r->z));
	b.z = v->z;
	a.x = b.x;
	a.y = b.y * cosf(DEG2RAD(r->x)) + b.z * sinf(DEG2RAD(r->x));
	a.z = b.y * -sinf(DEG2RAD(r->x)) + b.z * cosf(DEG2RAD(r->x));
	o->x = a.x * cosf(DEG2RAD(r->y)) - sinf(DEG2RAD(r->y)) * a.z;
	o->y = a.y;
	o->z = a.x * sinf(DEG2RAD(r->y)) + a.z * cosf(DEG2RAD(r->y));
}

void vec_roll_yxz_rv(FVEC3 *v, FVEC3 *r, FVEC3 *o)
{
	FVEC3 a, b;

	b.x = v->x * cosf(DEG2RAD(-r->y)) - sinf(DEG2RAD(-r->y)) * v->z;
	b.y = v->y;
	b.z = v->x * sinf(DEG2RAD(-r->y)) + v->z * cosf(DEG2RAD(-r->y));
	a.x = b.x;
	a.y = b.y * cosf(DEG2RAD(-r->x)) + b.z * sinf(DEG2RAD(-r->x));
	a.z = b.y * -sinf(DEG2RAD(-r->x)) + b.z * cosf(DEG2RAD(-r->x));
	o->x = a.x * cosf(DEG2RAD(-r->z)) + a.y * sinf(DEG2RAD(-r->z));
	o->y = a.x * -sinf(DEG2RAD(-r->z)) + a.y * cosf(DEG2RAD(-r->z));
	o->z = a.z;
}

void vec_roll_zxy_rv(FVEC3 *v, FVEC3 *r, FVEC3 *o)
{
	FVEC3 a, b;

	b.x = v->x * cosf(DEG2RAD(-r->z)) + v->y * sinf(DEG2RAD(-r->z));
	b.y = v->x * -sinf(DEG2RAD(-r->z)) + v->y * cosf(DEG2RAD(-r->z));
	b.z = v->z;
	a.x = b.x;
	a.y = b.y * cosf(DEG2RAD(-r->x)) + b.z * sinf(DEG2RAD(-r->x));
	a.z = b.y * -sinf(DEG2RAD(-r->x)) + b.z * cosf(DEG2RAD(-r->x));
	o->x = a.x * cosf(DEG2RAD(-r->y)) - sinf(DEG2RAD(-r->y)) * a.z;
	o->y = a.y;
	o->z = a.x * sinf(DEG2RAD(-r->y)) + a.z * cosf(DEG2RAD(-r->y));
}

float sqrtf(float x);
void vec_one(FVEC3 *v, FVEC3 *o)
{
	float l = sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);

	o->x = v->x / l;
	o->y = v->y / l;
	o->z = v->z / l;
}

void vec_one(FVEC3 *v, FVEC3 *o);
void vec_axis_rot(FVEC3 *p, FVEC3 *ax, FVEC3 *o, float ang)
{
	FVEC3 n;
	float rad, x, y, z, xx, yy, zz, s, c;

	vec_one(ax, &n);
	x = n.x;
	y = n.y;
	z = n.z;
	xx = x * x;
	yy = y * y;
	zz = z * z;
	rad = DEG2RAD(ang);
	s = sinf(rad);
	c = cosf(rad);
	o->x = (p->x - ax->x) * xx + (1.0f - xx) * c + (p->y - ax->y) * (x * y * (1.0f - c) - z * s) + (p->z - ax->z) * (x * z * (1.0f - c) + y * s) + ax->x;
	o->y = (p->x - ax->x) * (x * y * (1.0f - c) + z * s) + ((p->y - ax->y) * yy + (1.0f - yy) * c) + (p->z - ax->z) * (y * z * (1.0f - c) - x * s) + ax->y;
	o->z = (p->x - ax->x) * (x * z * (1.0f - c) - y * s) + (p->y - ax->y) * (y * z * (1.0f - c) + x * s) + ((p->z - ax->z) * zz + (1.0f - zz) * c) + ax->z;
}

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
