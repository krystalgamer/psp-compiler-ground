#include "common.h"
#include "m2c_macros.h"

extern int D_00109480;
M2C_UNK I3dRender__ProcessSortTagCmd(void *);       /* extern */
M2C_UNK I3dWritebackDcache();                       /* extern */
M2C_UNK I3dCacheManager__Construct(void *, void *, M2C_UNK, void *); /* extern */
extern unsigned char I3dPkDefaultTermTag;


int I3dRender__EndScene_PkAllocTex(void *r, int a)
{
	return a;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRender__Present(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dRenderGetStructSize(int arg0) {
    int var_v0;

    var_v0 = -1;
    if (arg0 == 0) {
        var_v0 = D_00109480;
    }
    return var_v0;
}

int I3dRender__SetCallBack_PkTermTag(char *r, void *f, void *a)
{
	*(void **)(r + 0x1B0) = f;
	*(void **)(r + 0x1B4) = a;
	return 0;
}

int I3dRender__SetTexInfo(char *r, int a, int b)
{
	*(int *)(r + 0xFC) = a;
	*(int *)(r + 0x100) = b;
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRender__GetDisplayListStartPoint(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x118);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRender__GetTrashRest(void *arg0) {
    return __builtin_allegrex_max(__builtin_allegrex_ext(M2C_FIELD(arg0, int *, 0xF8), 0, 0x1E) - __builtin_allegrex_ext(M2C_FIELD(arg0, int *, 0xF4), 0, 0x1E), 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRender__CheckTrashRest(void *arg0, int arg1) {
    return __builtin_allegrex_max(__builtin_allegrex_ext(M2C_FIELD(arg0, int *, 0xF8), 0, 0x1E) - __builtin_allegrex_ext(arg1, 0, 0x1E), 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRender__GetTrashOverRun(void *arg0) {
    int temp_v0;

    temp_v0 = __builtin_allegrex_ext(M2C_FIELD(arg0, int *, 0xF8), 0, 0x1E) - __builtin_allegrex_ext(M2C_FIELD(arg0, int *, 0xF4), 0, 0x1E);
    return (temp_v0 >= 0) ? 0 : -temp_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", I3dRender__ReserveTrashQwc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", I3dRender__ReserveTrashQwcUca);

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dRender__OpenTrash(void) {
    return (I3dRender__OpenTrashUca() + 0x7F) & 0x3FFFFF80;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void I3dRender__CloseTrash(void *arg0, int arg1) {
    I3dRender__CloseTrashUca(arg0, ((arg1 + 0x7F) & 0x3FFFFF80) | 0x40000000);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRender__OpenTrashUca(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xF4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRender__CloseTrashUca(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0xF4) = arg1;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", I3dRender__InitTexCache);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", I3dRender__JoinPacketEntry);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", I3dRenderStage__CallPacketEntry);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", I3dRender__BeginScene);

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dRender__EndScene(void *arg0) {
    M2C_FIELD(arg0, int *, 0x1C4) = 0;
    M2C_FIELD(arg0, int *, 0x1C8) = 0;
    M2C_FIELD(arg0, int *, 0x1CC) = 0;
    M2C_FIELD(arg0, int *, 0x1D0) = 0;
    I3dWritebackDcache();
    M2C_FIELD(arg0, int *, 0x1BC) = 0;
    I3dRender__ProcessSortTagCmd(arg0);
    I3dWritebackDcache();
    return (M2C_FIELD(arg0, int *, 0x1BC) == 0) ? 0 : 9;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRender__AdjustScissor(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x1B8) = fparg0;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", I3dRender__CreateRenderStage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", I3dRender__CreateSorter);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRender__Destruct(void *arg0) {
    I3dCacheManager__Destruct(arg0);
    I3dCacheManager__Destruct(arg0 + 0x70);
    return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", D_00109480);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

int I3dRender__Construct(void *arg0, int arg1, int arg2, int arg3) {
    memset(arg0, 0, 0x1FCU);
    I3dCacheManager__Construct(arg0, arg0 + 0x11C, 1, arg0 + 0x160);
    I3dCacheManager__Construct(arg0 + 0x70, arg0 + 0x164, 1, arg0 + 0x1A8);
    M2C_FIELD(arg0, int *, 0xEC) = arg1;
    M2C_FIELD(arg0, int *, 0xF0) = arg2;
    M2C_FIELD(arg0, int *, 0xE4) = arg3;
    M2C_FIELD(arg0, float *, 0x1B8) = 0.35f;
    M2C_FIELD(arg0, M2C_UNK **, 0x1B0) = &I3dPkDefaultTermTag;
    M2C_FIELD(arg0, int *, 0x1AC) = 0;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", I3dRender__EndScene_RequestAllocTex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", I3dVertexAnimParam__Clear);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", I3rMaterialOperationGroup__MakePresetPacket_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render", I3dRenderStage__RenderI3rA);
