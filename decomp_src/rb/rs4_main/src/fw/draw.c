/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sceKernelCpuResumeIntr(int);                /* extern */
int sceKernelCpuSuspendIntr();                      /* extern */
extern unsigned int DrawPC;
M2C_UNK resOvlProcInst(int, int, int, int, int, int); /* extern */
extern int CurrentInst;

extern int Env;
extern unsigned char InstBuf;
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *, int);      /* extern */
extern void *pReadInst;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", drawStart);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *sceGuSwapBuffers(void);

int drawSwap(void) {
    int temp_s0;

    temp_s0 = Env ^ 1;
    Env = temp_s0;
    sceGuSwapBuffers();
    return temp_s0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *drawGetEnv(void) {
    return &Env;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", drawDispCallback);

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int sceKernelGetSystemTimeLow(void);

void drawGuCallback(int arg0) {
    int temp_s0;

    if (arg0 == 0x52) {
        temp_s0 = sceKernelCpuSuspendIntr();
        DrawPC = sceKernelGetSystemTimeLow();
        sceKernelCpuResumeIntr(temp_s0);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", drawXchg);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuClutLoad(int num_blocks, const void *cbp);
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

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB948);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", ptxInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB9E4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", resInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FB9F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FBA08);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FBA24);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FBA2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FBA38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", D_000FBA40);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", resTerm);

#ifndef NULL
#define NULL ((void *)0)
#endif

void *resGetInst(int arg0) {
    return (arg0 << 5) + &InstBuf;
}

typedef struct { int *p; int pad[7]; } InstEnt;
int resGetChildEntry(int i)
{
	int *c;
	if (CurrentInst >= i) {
		c = (int *)((InstEnt *)&InstBuf)[i].p[1];
		if (c)
			return c[1];
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", resChkData);

#ifndef NULL
#define NULL ((void *)0)
#endif

void resSetOvlProcTbl(int arg0) {
    consPrintf("%s : %p\n", "resSetOvlProcTbl", arg0);
    if (pReadInst != NULL) {
        M2C_FIELD(pReadInst, int *, 8) = arg0;
        pReadInst = NULL;
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", resOvlProcInst);

#ifndef NULL
#define NULL ((void *)0)
#endif

void resOvlProcCurrent(int arg0, int arg1, int arg2, int arg3) {
    resOvlProcInst(CurrentInst, arg0, arg1, arg2, arg3, arg0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", resOvlProcAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/draw", resReadInstThr);
