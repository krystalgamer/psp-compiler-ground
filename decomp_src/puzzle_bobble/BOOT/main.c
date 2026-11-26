#include "common.h"
#include "m2c_macros.h"

M2C_UNK memalign(M2C_UNK, int);                     /* extern */
M2C_UNK free();                                     /* extern */
int sceDisplayGetVcount();                          /* extern */
extern int frameCount;
extern int VCount;
extern int g_frame;
extern int g_vbl_count;
extern int g_vbl_step;
extern int g_vbl_time;
extern int g_cpu_load;
extern int g_gpu_load;
int printf(const char *, ...);
int sceKernelExitGame(void);
int sceKernelDelayThreadCB(unsigned int);
unsigned int sceKernelGetSystemTimeLow(void);
int sceGuSync(int, int);
int sceDisplayWaitVblankCB(void);
void *sceGuSwapBuffers(void);
void *sceGuGetMemory(int);
void sceGuDrawArray(int, int, int, const void *, const void *);
M2C_UNK sceGuDisable(M2C_UNK);                      /* extern */
M2C_UNK sceGuFinish();                              /* extern */


void malloc16(int arg0) {
    memalign(0x10, arg0);
}

void free16(void) {
    free();
}

int exit_func(int arg1, int arg2, void *common)
{
	printf("** %s(0x%08x)\n", "exit_func", *(int *)common);
	sceKernelExitGame();
	for (;;)
		sceKernelDelayThreadCB(10000);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", main);

void vsyncCountInit(void) {
    frameCount = sceDisplayGetVcount();
}

int vsyncGetCount(void) {
    int temp_a0;
    int temp_v0;
    int temp_v1;

    temp_v0 = sceDisplayGetVcount();
    temp_v1 = frameCount;
    frameCount = temp_v0;
    temp_a0 = temp_v0 - temp_v1;
    VCount = temp_a0;
    return temp_a0;
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBB8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBC4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBD0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBD4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBD8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBDC);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBE0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBE4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBE8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", D_0002DBEC);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", begin_scene);

void end_scene(void) {
    sceGuDisable(9);
    sceGuDisable(1);
    sceGuFinish();
}

void swap_buffers(void)
{
	int cpu_time, gpu_time, vbl_time, vbl_count;

	cpu_time = sceKernelGetSystemTimeLow();
	sceGuSync(0, 0);
	gpu_time = sceKernelGetSystemTimeLow();
	sceDisplayWaitVblankCB();
	sceGuSwapBuffers();
	g_frame++;
	vbl_time = sceKernelGetSystemTimeLow();
	vbl_count = sceDisplayGetVcount();
	if (g_vbl_count >= 0) {
		g_vbl_step = vbl_count - g_vbl_count;
		g_cpu_load = (cpu_time - g_vbl_time) * 100 / 16667;
		g_gpu_load = (gpu_time - g_vbl_time) * 100 / 16667;
	}
	g_vbl_time = vbl_time;
	g_vbl_count = vbl_count;
}

void dummy_swap(void)
{
	int cpu_time, gpu_time, vbl_time, vbl_count;

	cpu_time = sceKernelGetSystemTimeLow();
	gpu_time = sceKernelGetSystemTimeLow();
	vbl_time = sceKernelGetSystemTimeLow();
	vbl_count = sceDisplayGetVcount();
	if (g_vbl_count >= 0) {
		g_vbl_step = vbl_count - g_vbl_count;
		g_cpu_load = (cpu_time - g_vbl_time) * 100 / 16667;
		g_gpu_load = (gpu_time - g_vbl_time) * 100 / 16667;
	}
	g_vbl_time = vbl_time;
	g_vbl_count = vbl_count;
}

void draw_rect(int x, int y, int w, int h, int color)
{
	int format = 0x800118;
	short *vertex = sceGuGetMemory(16);

	vertex[0] = color;
	vertex[1] = x;
	vertex[2] = y;
	vertex[3] = 0;
	vertex[4] = color;
	vertex[5] = x + w;
	vertex[6] = y + h;
	vertex[7] = 0;
	sceGuDrawArray(6, format, 2, 0, vertex);
}
