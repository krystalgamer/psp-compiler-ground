/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sceKernelCpuResumeIntr(int);                /* extern */
int sceKernelCpuSuspendIntr();                      /* extern */
extern unsigned int DrawPC;

extern int Env;
void *sceGuSwapBuffers(void);

extern int VSyncCt;
unsigned int sceKernelGetSystemTimeLow(void);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuClutLoad(int num_blocks, const void *cbp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", drawInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB840);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB850);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB86C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB87C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB88C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB8AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB8CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB8D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB8E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB8F4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", drawTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", drawStart);

int drawSwap(void) {
    int temp_s0;

    temp_s0 = Env ^ 1;
    Env = temp_s0;
    sceGuSwapBuffers();
    return temp_s0;
}

M2C_UNK *drawGetEnv(void) {
    return &Env;
}

void drawDispCallback(int a, int b)
{
	int s;
	if (b == 0x13) {
		s = sceKernelCpuSuspendIntr();
		VSyncCt++;
		sceKernelCpuResumeIntr(s);
	}
}

void drawGuCallback(int arg0) {
    int temp_s0;

    if (arg0 == 0x52) {
        temp_s0 = sceKernelCpuSuspendIntr();
        DrawPC = sceKernelGetSystemTimeLow();
        sceKernelCpuResumeIntr(temp_s0);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", drawXchg);

int drawSetTexture(void *arg0) {
    unsigned short temp_a1;
    void **temp_s2;
    void *temp_s1;

    temp_s2 = M2C_FIELD(arg0, void ***, 0x10);
    temp_s1 = M2C_FIELD(arg0, void **, 0x14);
    sceGuClutMode((unsigned int) M2C_FIELD(arg0, unsigned char *, 8), 0U, 0xFFU, 0U);
    sceGuClutLoad(0x10, *temp_s2);
    sceGuTexMode((int) M2C_FIELD(arg0, unsigned char *, 9), 0, 0, 0);
    temp_a1 = M2C_FIELD(temp_s1, unsigned short *, 0xC);
    sceGuTexImage(0, (int) temp_a1, (int) M2C_FIELD(temp_s1, unsigned short *, 0xE), (int) temp_a1, M2C_FIELD(temp_s1, void **, 0));
    sceGuTexFilter(0, 0);
    sceGuTexFunc(0, 1);
    sceGuTexWrap(1, 1);
    sceGuTexMapMode(0, 0U, 0U);
    return 0;
}

void drawPrintf(int a, ...)
{
}

void drawPrint(void) {
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB934);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB938);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB93C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB940);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB944);
