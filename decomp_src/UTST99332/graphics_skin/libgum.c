#include "common.h"
#include "m2c_macros.h"
M2C_UNK __checkUpdate();                            /* extern */


INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", __mulMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", __setMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", __checkUpdate);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumSetMatrixStack);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumSetCurMatrix);

#define NULL ((void *)0)

void sceGumUpdateMatrix(void);

void sceGumUpdateMatrix(void) {
    __checkUpdate();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumLoadContext);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumStoreContext);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumLoadIdentity);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumRotateX);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumRotateY);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumRotateZ);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumRotateXYZ);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumRotateZYX);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumTranslate);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumScale);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumMultMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumPerspective);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumOrtho);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumLookAt);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumMatrixMode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumPushMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumPopMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumLoadMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/libgum", sceGumStoreMatrix);

void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices)
{
	__checkUpdate();
	sceGuDrawArray(prim, vtype, count, indices, vertices);
}

void sceGuDrawArrayN(int prim, int vtype, int count, int a3, const void *indices, const void *vertices);
void sceGumDrawArrayN(int prim, int vtype, int count, int a3, const void *indices, const void *vertices);
void sceGuDrawArrayN(int prim, int vtype, int count, int a3, const void *indices, const void *vertices);
void sceGumDrawArrayN(int prim, int vtype, int count, int a3, const void *indices, const void *vertices);
void sceGumDrawArrayN(int prim, int vtype, int count, int n, const void *indices, const void *vertices)
{
	__checkUpdate();
	sceGuDrawArrayN(prim, vtype, count, n, indices, vertices);
}

void sceGuDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGuDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices)
{
	__checkUpdate();
	sceGuDrawBezier(vtype, ucount, vcount, indices, vertices);
}

void sceGuDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGuDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices)
{
	__checkUpdate();
	sceGuDrawSpline(vtype, ucount, vcount, uedge, vedge, indices, vertices);
}
