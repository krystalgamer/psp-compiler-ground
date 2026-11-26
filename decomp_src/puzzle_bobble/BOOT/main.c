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

#ifdef NON_MATCHING
/* Close (diff 2, 1.5.1 only): the far/near loads for sceGumPerspective are scheduled in the
 * other order (f15 before f14). Converting it also needs D_0002DBB8/DBC4 (the eye/up
 * initializers) dropped and D_0002DBD0..DBEC (main's floats) moved after this function. */
typedef struct { float x, y, z; } ScePspFVector3;
extern int g_menu_frame;
extern int g_menu_filter;
extern int g_menu_subdiv;
extern char g_packet_buf[];
void sceGuStart(int, void *, int);
void sceGuClear(int);
void sceGuDrawBuffer(int, void *, int);
void sceGuDepthBuffer(void *, int);
void sceGuOffset(unsigned int, unsigned int);
void sceGuViewport(int, int, int, int);
void sceGuDepthRange(int, int);
void sceGuEnable(int);
void sceGuScissor(int, int, int, int);
void sceGuClearColor(unsigned int);
void sceGuClearDepth(unsigned int);
void sceGuClearStencil(unsigned int);
void sceGumMatrixMode(int);
void sceGumLoadIdentity(void);
void sceGumLookAt(ScePspFVector3 *, ScePspFVector3 *, ScePspFVector3 *);
void sceGumPerspective(float, float, float, float);
void sceGuAmbient(unsigned int);
void sceGuMaterial(int, unsigned int);
void sceGuBlendFunc(int, int, int, unsigned int, unsigned int);
void sceGuTexFunc(int, int);
void sceGuTexWrap(int, int);
void sceGuTexFilter(int, int);
void sceGuPatchDivide(int, int);
void begin_scene(void)
{
	int psm = !g_menu_frame ? 3 : 1;
	int fbp = (g_frame & 1) ? 0x88000 : 0;

	sceGuStart(0, g_packet_buf, 0x80000);
	sceGuClear(7);
	sceGuDrawBuffer(psm, (void *)fbp, 512);
	sceGuDepthBuffer((void *)0x110000, 512);
	sceGuOffset(2048 - 480 / 2, 2048 - 272 / 2);
	sceGuViewport(2048, 2048, 480, 272);
	sceGuDepthRange(0xE000, 0x1000);
	sceGuEnable(2);
	sceGuScissor(0, 0, 480, 272);
	sceGuClearColor(0xFF800000);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuClear(7);
	sceGumMatrixMode(1);
	sceGumLoadIdentity();
	{
		ScePspFVector3 eye = { 0.0f, 0.0f, 50.0f };
		ScePspFVector3 center = { 0.0f, 0.0f, 0.0f };
		ScePspFVector3 up = { 0.0f, 1.0f, 0.0f };

		sceGumLookAt(&eye, &center, &up);
	}
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(60.0f * 3.14f / 180.0f, 480.0f / 272.0f, 10.0f, 1000000.0f);
	sceGumMatrixMode(2);
	sceGuDisable(7);
	sceGuDisable(10);
	sceGuAmbient(0xFF404040);
	sceGuMaterial(1, -1);
	sceGuEnable(4);
	sceGuEnable(6);
	sceGuEnable(9);
	sceGuEnable(8);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuTexFunc(0, 1);
	sceGuTexWrap(1, 1);
	switch (g_menu_filter) {
	case 0:
		sceGuTexFilter(7, 1);
		break;
	case 1:
		sceGuTexFilter(5, 1);
		break;
	case 2:
		sceGuTexFilter(4, 0);
		break;
	}
	sceGuPatchDivide(g_menu_subdiv, g_menu_subdiv);
	sceGumMatrixMode(2);
	sceGumLoadIdentity();
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/main", begin_scene);
#endif

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
