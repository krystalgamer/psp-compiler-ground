#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", __mulMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", __setMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", __checkUpdate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumSetMatrixStack);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumSetCurMatrix);

void sceGumUpdateMatrix(void);
void sceGumUpdateMatrix(void)
{
	__checkUpdate();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumLoadContext);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumStoreContext);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumLoadIdentity);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumRotateX);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumRotateY);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumRotateZ);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumRotateXYZ);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumRotateZYX);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumTranslate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumScale);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumMultMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumPerspective);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumOrtho);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumLookAt);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumMatrixMode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumPushMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumPopMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumLoadMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/libgum", sceGumStoreMatrix);

void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices)
{
	__checkUpdate();
	sceGuDrawArray(prim, vtype, count, indices, vertices);
}

void sceGuDrawArrayN(int prim, int vtype, int count, int a3, const void *indices, const void *vertices);
void sceGumDrawArrayN(int prim, int vtype, int count, int a3, const void *indices, const void *vertices);
void sceGumDrawArrayN(int prim, int vtype, int count, int n, const void *indices, const void *vertices)
{
	__checkUpdate();
	sceGuDrawArrayN(prim, vtype, count, n, indices, vertices);
}

void sceGuDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices)
{
	__checkUpdate();
	sceGuDrawBezier(vtype, ucount, vcount, indices, vertices);
}

void sceGuDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices)
{
	__checkUpdate();
	sceGuDrawSpline(vtype, ucount, vcount, uedge, vedge, indices, vertices);
}
