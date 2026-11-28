/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK I3dPk3dSprite__SetTransformMatrix(int, int); /* extern */
int I3dRenderStage__GetCurrentViewStatus(int);      /* extern */
int I3dViewStatus__GetViewToWorldMatrixA(int);      /* extern */
M2C_UNK iI3dGuDrawSpline_PSP_61A38();               /* extern */
M2C_UNK I3dGuSetMatrix_PSP();                       /* extern */


short *AddVertexV(short *p, float *v)
{
	short t[8] __attribute__((aligned(16)));

	__asm__ volatile(
		"lv.q C010.q,0(%1)\n"
		"vmul.q C000.q,C010.q,C520.q\n"
		"vadd.q C000.q,C000.q,C530.q\n"
		"vf2iz.q C000.q,C000.q,0\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(t), "r"(v) : "memory");
	p[0] = t[0];
	p[1] = t[2];
	p[2] = t[4];
	return p + 3;
}

short *AddVertexVTU(short *p, float *v, float *uv)
{
	short t[8] __attribute__((aligned(16)));

	__asm__ volatile(
		"lv.q C010.q,0(%1)\n"
		"vmul.q C000.q,C010.q,C520.q\n"
		"vadd.q C000.q,C000.q,C530.q\n"
		"vf2iz.q C000.q,C000.q,0\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(t), "r"(v) : "memory");
	__asm__ volatile(
		"lv.q C010.q,0(%1)\n"
		"vf2iz.q C000.q,C010.q,0\n"
		"mfv $8,S000.s\n"
		"sh $8,0(%0)\n"
		"mfv $8,S001.s\n"
		"sh $8,2(%0)\n"
		: : "r"(p), "r"(uv) : "$8", "memory");
	p[2] = t[0];
	p[3] = t[2];
	p[4] = t[4];
	return p + 5;
}

void AddVertexCV()
{
	__asm__ volatile(
		"addiu $29,$29,-16\n"
		"lv.q C010.q,0($6)\n"
		"vmul.q C000.q,C010.q,C520.q\n"
		"vadd.q C000.q,C000.q,C530.q\n"
		"vf2iz.q C000.q,C000.q,0\n"
		"sv.q C000.q,0($29)\n"
		"lhu $6,4($29)\n"
		"lhu $7,8($29)\n"
		"lhu $3,0($29)\n"
		"addiu $2,$4,12\n"
		"lv.q C000.q,0($5)\n"
		"vsat0.q C000.q,C000.q\n"
		"vscl.q C000.q,C000.q,S701.s\n"
		"vf2iz.q C000.q,C000.q,23\n"
		"vi2uc.q S000.s,C000.q\n"
		"mfv $5,S000.s\n"
		"sh $3,4($4)\n"
		"sw $5,0($4)\n"
		"sh $6,6($4)\n"
		"sh $7,8($4)\n"
		"addiu $29,$29,16\n"
		: : : "memory");
}

void AddVertexCVTU()
{
	__asm__ volatile(
		"addiu $29,$29,-16\n"
		"lv.q C010.q,0($6)\n"
		"vmul.q C000.q,C010.q,C520.q\n"
		"vadd.q C000.q,C000.q,C530.q\n"
		"vf2iz.q C000.q,C000.q,0\n"
		"sv.q C000.q,0($29)\n"
		"lv.q C010.q,0($7)\n"
		"vf2iz.q C000.q,C010.q,0\n"
		"mfv $8,S000.s\n"
		"sh $8,0($4)\n"
		"mfv $8,S001.s\n"
		"sh $8,2($4)\n"
		"lhu $6,4($29)\n"
		"lhu $7,8($29)\n"
		"lhu $3,0($29)\n"
		"addiu $2,$4,16\n"
		"lv.q C000.q,0($5)\n"
		"vsat0.q C000.q,C000.q\n"
		"vscl.q C000.q,C000.q,S701.s\n"
		"vf2iz.q C000.q,C000.q,23\n"
		"vi2uc.q S000.s,C000.q\n"
		"mfv $5,S000.s\n"
		"sh $3,8($4)\n"
		"sw $5,4($4)\n"
		"sh $6,10($4)\n"
		"sh $7,12($4)\n"
		"addiu $29,$29,16\n"
		: : : "memory");
}

unsigned int *I3dGuGetMemory_PSP(unsigned int *, int);
unsigned int *I3dGuDrawArray_PSP(unsigned int *, int, int, int, void *, void *);
unsigned int I3dColPackA8B8G8R8();
unsigned int *I3dGuEnableTexture_PSP(unsigned int *, int);
static inline unsigned int *PkColorX(unsigned int *p, unsigned int c)
{
	p[0] = 0x55000000 | __builtin_allegrex_ext(c, 0, 24);
	p[1] = 0x58000000 | (c >> 24);
	return p + 2;
}
static inline unsigned int *PkCmdX(unsigned int *p, unsigned int v)
{
	*p = v;
	return p + 1;
}
unsigned int *I3dPk2dPrim_DrawSpriteF(unsigned int *p, float *v0, float *v1, void *col)
{
	short *vtx = (short *)(p + 2);
	short *q;
	p = I3dGuGetMemory_PSP(p, 12);
	q = AddVertexV(vtx, v0);
	AddVertexV(q, v1);
	p = PkColorX(p, I3dColPackA8B8G8R8(col));
	*p++ = 0x1E000000;
	return I3dGuDrawArray_PSP(p, 6, 0x800100, 2, 0, vtx);
}

unsigned int *I3dPk2dPrim_DrawSpriteFTU(unsigned int *p, float *v0, float *v1, float *uv0, float *uv1, void *col)
{
	short *vtx = (short *)(p + 2);
	short *q;
	p = I3dGuGetMemory_PSP(p, 0x14);
	q = AddVertexVTU(vtx, v0, uv0);
	AddVertexVTU(q, v1, uv1);
	p = PkColorX(p, I3dColPackA8B8G8R8(col));
	p = I3dGuEnableTexture_PSP(p, 1);
	return I3dGuDrawArray_PSP(p, 6, 0x800102, 2, 0, vtx);
}

unsigned int *I3dPk2dPrim_DrawTriF(unsigned int *p, float *v0, float *v1, float *v2, void *col)
{
	short *vtx = (short *)(p + 2);
	short *q;
	p = I3dGuGetMemory_PSP(p, 0x12);
	q = AddVertexV(vtx, v0);
	q = AddVertexV(q, v1);
	AddVertexV(q, v2);
	p = PkColorX(p, I3dColPackA8B8G8R8(col));
	*p++ = 0x1E000000;
	return I3dGuDrawArray_PSP(p, 3, 0x800100, 3, 0, vtx);
}

unsigned int *I3dPk2dPrim_DrawTriFTU(unsigned int *p, float *v0, float *v1, float *v2, float *uv0, float *uv1, float *uv2, void *col)
{
	short *vtx = (short *)(p + 2);
	short *q;
	p = I3dGuGetMemory_PSP(p, 0x1E);
	q = AddVertexVTU(vtx, v0, uv0);
	q = AddVertexVTU(q, v1, uv1);
	AddVertexVTU(q, v2, uv2);
	p = PkColorX(p, I3dColPackA8B8G8R8(col));
	p = I3dGuEnableTexture_PSP(p, 1);
	return I3dGuDrawArray_PSP(p, 3, 0x800102, 3, 0, vtx);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawTriG);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawTriGTU);

unsigned int *I3dPk2dPrim_DrawLineF(unsigned int *p, float *v0, float *v1, void *col)
{
	short *vtx = (short *)(p + 2);
	short *q;
	p = I3dGuGetMemory_PSP(p, 12);
	q = AddVertexV(vtx, v0);
	AddVertexV(q, v1);
	p = PkColorX(p, I3dColPackA8B8G8R8(col));
	*p++ = 0x1E000000;
	return I3dGuDrawArray_PSP(p, 1, 0x800100, 2, 0, vtx);
}

unsigned int *I3dPk2dPrim_DrawLineFTU(unsigned int *p, float *v0, float *v1, float *uv0, float *uv1, void *col)
{
	short *vtx = (short *)(p + 2);
	short *q;
	p = I3dGuGetMemory_PSP(p, 0x14);
	q = AddVertexVTU(vtx, v0, uv0);
	AddVertexVTU(q, v1, uv1);
	p = PkColorX(p, I3dColPackA8B8G8R8(col));
	p = I3dGuEnableTexture_PSP(p, 1);
	return I3dGuDrawArray_PSP(p, 1, 0x800102, 2, 0, vtx);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawLineG);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk2dPrim_DrawLineGTU);

unsigned int *I3dPk2dPrim_DrawPointF(unsigned int *p, float *v, void *col)
{
	short *vtx = (short *)(p + 2);
	p = I3dGuGetMemory_PSP(p, 6);
	AddVertexV(vtx, v);
	p = PkColorX(p, I3dColPackA8B8G8R8(col));
	*p++ = 0x1E000000;
	return I3dGuDrawArray_PSP(p, 0, 0x800100, 1, 0, vtx);
}

unsigned int *I3dPk2dPrim_DrawPointFTU(unsigned int *p, float *v, float *uv, void *col)
{
	short *vtx = (short *)(p + 2);
	p = I3dGuGetMemory_PSP(p, 10);
	AddVertexVTU(vtx, v, uv);
	p = PkColorX(p, I3dColPackA8B8G8R8(col));
	p = I3dGuEnableTexture_PSP(p, 1);
	return I3dGuDrawArray_PSP(p, 0, 0x800102, 1, 0, vtx);
}

void I3dPk2dPrim_SetOffset()
{
	__asm__ volatile(
		"lv.q C530.q,0($4)\n"
		: : : "memory");
}

void I3dPk2dPrim_SetScale()
{
	__asm__ volatile(
		"lv.q C520.q,0($4)\n"
		: : : "memory");
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", CreateArray);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dPrim__SetTransform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dPrim__DrawTriStrip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dPrim__DrawTriStripQ_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dPrim__DrawLineStrip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawSphere);

extern int LastW;
M2C_UNK I3dPk3dSprite__SetTransformMatrix(int p, int m)
{
	__asm__ volatile(
		"lv.q C600.q,0(%0)\n"
		"lv.q C610.q,16(%0)\n"
		"lv.q C620.q,32(%0)\n"
		: : "r"(m) : "memory");
	LastW = 0;
	return p;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dSprite__SetStParam);

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dPk3dSprite__SetBillBoardMatrix(int arg0, int arg1) {
    I3dPk3dSprite__SetTransformMatrix(arg0, I3dViewStatus__GetViewToWorldMatrixA(I3dRenderStage__GetCurrentViewStatus(arg1)));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dSprite__SetBillBoardMatrixWithZoom);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dSprite__Init);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dPk3dSprite__Term(int arg0) {
    return arg0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPk3dSprite__Draw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawScissorStripA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawScissorStripFA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawScissorLineStripA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawScissorLineStripFA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawArray_PSP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawBezier_PSP);

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dPkDrawSpline_PSP(void) {
    iI3dGuDrawSpline_PSP_61A38();
}

typedef struct { unsigned s:8; unsigned t:7; unsigned pad:9; unsigned cmd:8; } PdCmd;
unsigned int *I3dPkPatchDivide_PSP(unsigned int *p, unsigned int s, unsigned int t)
{
	union { unsigned int w; PdCmd c; } u;
	u.w = s | 0x36000000;
	u.c.t = t;
	*p = u.w;
	return p + 1;
}

unsigned int *I3dPkPatchPrim_PSP(unsigned int *p, int prim)
{
    unsigned int v;
    if (prim == 4) v = 0x37000000;
    else if (prim == 2) v = 0x37000001;
    else v = 0x37000002;
    *p = v;
    return p + 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dPkSetMatrix_PSP(void) {
    I3dGuSetMatrix_PSP();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dPkDrawSphereMarkerA);

extern const int g_aiVtx[];
extern const int g_aSkip[];
extern const float g_aPosTbl[];
extern const float D_00109164;
void I3dPkDrawScissorLineStripFA(void *, int, const void *, int, int, float (*)[4], const int *);
void I3dPkDrawBoxMarkerA(void *pk, int a1, const void *a2, const float *c, const float *h, int color)
{
	float v[16][4] __attribute__((aligned(16)));
	float p[8][4] __attribute__((aligned(16)));
	int i;

	for (i = 0; i < 8; i++) {
		p[i][0] = h[0] * g_aPosTbl[i & 1] + c[0];
		p[i][1] = h[1] * g_aPosTbl[i & 2] + c[1];
		p[i][2] = h[2] * g_aPosTbl[i & 4] + c[2];
		p[i][3] = D_00109164;
	}
	for (i = 0; i < 16; i++) {
		__asm__ volatile(
			"lv.q C000.q,0(%1)\n"
			"sv.q C000.q,0(%0)\n"
			: : "r"(v[i]), "r"(p[g_aiVtx[i]]) : "memory");
	}
	I3dPkDrawScissorLineStripFA(pk, a1, a2, 16, color, v, g_aSkip);
}

const float D_00109164 = 1.0f;

extern const float D_00109168;
void I3dMatMulA(float *, const float *, const float *);
void I3dMatCopyA(float *, const float *);
void I3dPkDrawObbMarkerA(void *pk, int a1, const float *mat, const float *obb, int color)
{
	float v[16][4] __attribute__((aligned(16)));
	float p[8][4] __attribute__((aligned(16)));
	float m[16] __attribute__((aligned(16)));
	int i;

	for (i = 0; i < 8; i++) {
		p[i][0] = g_aPosTbl[i & 1];
		p[i][1] = g_aPosTbl[i & 2];
		p[i][2] = g_aPosTbl[i & 4];
		p[i][3] = D_00109168;
	}
	for (i = 0; i < 16; i++) {
		__asm__ volatile(
			"lv.q C000.q,0(%1)\n"
			"sv.q C000.q,0(%0)\n"
			: : "r"(v[i]), "r"(p[g_aiVtx[i]]) : "memory");
	}
	if (mat)
		I3dMatMulA(m, obb, mat);
	else
		I3dMatCopyA(m, obb);
	I3dPkDrawScissorLineStripFA(pk, a1, m, 16, color, v, g_aSkip);
}

const float D_00109168 = 1.0f;
const float D_0010916C = 0.0f; /* padding before the 16-aligned D_00109170 */

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", iI3dGuDrawSpline_PSP_61A38);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRender__SetSoftwareScissor_PSP(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x1C0) = (int) (arg1 & 0xFF);
    return 0;
}

void I3dGeomInit(void);
int I3dRenderInitMain(void)
{
	I3dGeomInit();
	__asm__ volatile(
		"vone.q C520.q\n"
		"vzero.q C530.q\n"
		"vzero.q C600.q\n"
		"vzero.q C610.q\n"
		"vzero.q C620.q\n"
		: : : "memory");
	return 0;
}

unsigned int *I3dPkDefaultTermTag(unsigned int *p)
{
	*p++ = 0xB000000;
	return p;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", I3dRender__SetTexBuff_PSP);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", D_00109170);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", D_00109200);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", D_00109210);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", D_00109220);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aSphereIndex);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aSphereVertex);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aPosTable);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aDefaultArrayTex);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aArrayNoTex);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", D_001093D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", D_001093E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aiVtx);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aSkip);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_packet_util", g_aPosTbl);
