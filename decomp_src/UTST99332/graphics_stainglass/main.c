#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
int puts(const char *s);
int sceDisplayWaitVblankStart(void);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
int sceGuFinish(void);
void sceGuFog(float near, float far, unsigned int color);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuSpecular(float power);
void sceGuStart(int type, void *list, int size);
void *sceGuSwapBuffers(void);
int sceGuSync(int mode, int what);
void sceGuTerm(void);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelDcacheWritebackInvalidateAll(void);
int sceKernelSleepThread(void);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", ResetAllPositioning);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", PositioningMultMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", PositioningStoreMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", draw_dragon_with_camera_transform);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", MainThread);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", D_000133D0);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", StartMainThread);

int main(void) {
    StartMainThread();
    return 0;
}
