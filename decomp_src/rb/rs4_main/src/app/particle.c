/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK _memFree(void *, M2C_UNK *, M2C_UNK);       /* extern */

float cusGetFloat(int, M2C_UNK, M2C_UNK *, float);      /* extern */

M2C_UNK copLetMat(int, int);
extern unsigned char D_000FE0C4;

extern unsigned char D_000FE0C4;

extern unsigned char D_000FE0C4;

extern unsigned char D_000FE0C4;

extern int g_nInst;
void partSetInst(int arg0) {
    g_nInst = arg0;
}

extern char D_000FDE18[], D_000FDE1C[], D_000FDE24[], D_000FDE2C[], D_000FDE34[], D_000FDE3C[], D_000FDE44[], D_000FDE4C[], D_000FDE54[], D_000FDE5C[], D_000FDE64[], D_000FDE6C[];
char *cusGetString(int name, char *section, char *key, char *out, int size, char *def);
int cusSetSection(int, char *);
int _PartCusConvEnv(float *e, int cus)
{
	char name[0x200];

	cusGetString(cus, D_000FDE1C, "EnvName", name, 0x200, D_000FDE18);
	if (name[0] == 0)
		return 0;
	if (cusSetSection(cus, name) != 1)
		return 0;
	e[4] = cusGetFloat(cus, 0, D_000FDE24, 0.0f);
	e[5] = cusGetFloat(cus, 0, D_000FDE2C, 0.0f);
	e[6] = cusGetFloat(cus, 0, D_000FDE34, 0.0f);
	e[7] = 0.0f;
	e[0] = cusGetFloat(cus, 0, D_000FDE3C, e[7]);
	e[1] = cusGetFloat(cus, 0, D_000FDE44, 0.0f);
	e[2] = cusGetFloat(cus, 0, D_000FDE4C, 0.0f);
	e[3] = 0.0f;
	e[8] = cusGetFloat(cus, 0, D_000FDE54, e[3]);
	e[9] = cusGetFloat(cus, 0, D_000FDE5C, 0.0f);
	e[10] = cusGetFloat(cus, 0, D_000FDE64, 0.0f);
	e[11] = cusGetFloat(cus, 0, D_000FDE6C, 0.0f);
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE24);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE34);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE5C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE64);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE6C);

int _PartCusConvPart_c(void *arg0, int arg1) {
    float temp_f0;

    temp_f0 = cusGetFloat(arg1, 0, "AgeMax", -1.0f);
    M2C_FIELD(arg0, float *, 4) = temp_f0;
    if (temp_f0 < 0.0f) {
        return 0;
    }
    M2C_FIELD(arg0, float *, 8) = cusGetFloat(arg1, 0, "AgeMin", temp_f0);
    M2C_FIELD(arg0, float *, 0xC) = cusGetFloat(arg1, 0, "SizeRange", 0.0f);
    M2C_FIELD(arg0, float *, 0x10) = cusGetFloat(arg1, 0, "SpdLeanX", 0.0f);
    M2C_FIELD(arg0, float *, 0x14) = cusGetFloat(arg1, 0, "SpdLeanY", 0.0f);
    M2C_FIELD(arg0, float *, 0x18) = cusGetFloat(arg1, 0, "SpdLeanZ", 0.0f);
    M2C_FIELD(arg0, float *, 0x1C) = 0.0f;
    M2C_FIELD(arg0, float *, 0x30) = cusGetFloat(arg1, 0, "SpdRangeL", 0.0f);
    M2C_FIELD(arg0, float *, 0x20) = cusGetFloat(arg1, 0, "SpdTurbX", 0.0f);
    M2C_FIELD(arg0, float *, 0x24) = cusGetFloat(arg1, 0, "SpdTurbY", 0.0f);
    M2C_FIELD(arg0, float *, 0x28) = cusGetFloat(arg1, 0, "SpdTurbZ", 0.0f);
    M2C_FIELD(arg0, float *, 0x2C) = 0.0f;
    M2C_FIELD(arg0, float *, 0x34) = cusGetFloat(arg1, 0, "SpdRadiR", 0.0f);
    M2C_FIELD(arg0, float *, 0x38) = cusGetFloat(arg1, 0, "SpdRangeR", 0.0f);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDEFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF08);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF28);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF58);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF64);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF70);

extern char D_000FDEFC[], D_000FDF08[], D_000FDF10[], D_000FDF18[], D_000FDF20[], D_000FDF28[], D_000FDF30[], D_000FDF38[], D_000FDF40[], D_000FDF4C[], D_000FDF58[], D_000FDF64[], D_000FDF70[];

int cusGetInt(int, int, char *, int);
int _PartCusConvPart2D(char *p, int cus)
{
	char name[0x200];
	int r;

	cusGetString(cus, D_000FDE1C, D_000FDEFC, name, 0x200, D_000FDE18);
	if (name[0] == 0)
		return 0;
	r = cusSetSection(cus, name);
	if (r != 1)
		return 0;
	if ((*(int *)p = cusGetInt(cus, 0, D_000FDF08, -1)) != 0)
		return 0;
	r = _PartCusConvPart_c(p, cus);
	if (r == 0)
		return 0;
	*(float *)(p + 0x40) = cusGetFloat(cus, 0, D_000FDF10, -1.0f);
	*(float *)(p + 0x44) = cusGetFloat(cus, 0, D_000FDF18, -1.0f);
	*(int *)(p + 0x48) = cusGetInt(cus, 0, D_000FDF20, 0);
	*(float *)(p + 0x50) = cusGetFloat(cus, 0, D_000FDF28, 1.0f);
	*(float *)(p + 0x54) = cusGetFloat(cus, 0, D_000FDF30, 1.0f);
	*(float *)(p + 0x58) = cusGetFloat(cus, 0, D_000FDF38, 1.0f);
	*(float *)(p + 0x5C) = cusGetFloat(cus, 0, D_000FDF40, 1.0f);
	*(float *)(p + 0x60) = cusGetFloat(cus, 0, D_000FDF4C, 0.0f);
	*(float *)(p + 0x64) = cusGetFloat(cus, 0, D_000FDF58, 0.0f);
	*(float *)(p + 0x68) = cusGetFloat(cus, 0, D_000FDF64, 0.0f);
	*(float *)(p + 0x6C) = cusGetFloat(cus, 0, D_000FDF70, 0.0f);
	*(float *)(p + 0x70) = cusGetFloat(cus, 0, "BaseRot", 0.0f) * 0.01745329238f;
	*(float *)(p + 0x74) = cusGetFloat(cus, 0, "RangeRot", 0.0f) * 0.01745329238f;
	*(float *)(p + 0x78) = cusGetFloat(cus, 0, "BaseRotSpd", 0.0f) * 0.01745329238f;
	*(float *)(p + 0x7C) = cusGetFloat(cus, 0, "RangeRotSpd", 0.0f) * 0.01745329238f;
	return r;
}

int _PartCusConvPart3D(char *p, int cus)
{
	char name[0x200];
	int r;

	cusGetString(cus, D_000FDE1C, D_000FDEFC, name, 0x200, D_000FDE18);
	if (name[0] == 0)
		return 0;
	r = cusSetSection(cus, name);
	if (r != 1)
		return 0;
	if ((*(int *)p = cusGetInt(cus, 0, D_000FDF08, -1)) != 1)
		return 0;
	r = _PartCusConvPart_c(p, cus);
	if (r == 0)
		return 0;
	*(float *)(p + 0x40) = cusGetFloat(cus, 0, D_000FDF10, -1.0f);
	*(float *)(p + 0x44) = cusGetFloat(cus, 0, D_000FDF18, -1.0f);
	*(int *)(p + 0x48) = cusGetInt(cus, 0, D_000FDF20, 0);
	*(float *)(p + 0x50) = cusGetFloat(cus, 0, D_000FDF28, 1.0f);
	*(float *)(p + 0x54) = cusGetFloat(cus, 0, D_000FDF30, 1.0f);
	*(float *)(p + 0x58) = cusGetFloat(cus, 0, D_000FDF38, 1.0f);
	*(float *)(p + 0x5C) = cusGetFloat(cus, 0, D_000FDF40, 1.0f);
	*(float *)(p + 0x60) = cusGetFloat(cus, 0, D_000FDF4C, 0.0f);
	*(float *)(p + 0x64) = cusGetFloat(cus, 0, D_000FDF58, 0.0f);
	*(float *)(p + 0x68) = cusGetFloat(cus, 0, D_000FDF64, 0.0f);
	*(float *)(p + 0x6C) = cusGetFloat(cus, 0, D_000FDF70, 0.0f);
	*(float *)(p + 0x70) = cusGetFloat(cus, 0, "RotRangeX", 0.0f) * 0.01745329238f;
	*(float *)(p + 0x74) = cusGetFloat(cus, 0, "RotRangeY", 0.0f) * 0.01745329238f;
	*(float *)(p + 0x78) = cusGetFloat(cus, 0, "RotRangeZ", 0.0f) * 0.01745329238f;
	*(float *)(p + 0x7C) = 0.0f;
	*(float *)(p + 0x80) = cusGetFloat(cus, 0, "RotSpdX", *(float *)(p + 0x7C)) * 0.01745329238f;
	*(float *)(p + 0x84) = cusGetFloat(cus, 0, "RotSpdY", 0.0f) * 0.01745329238f;
	*(float *)(p + 0x88) = cusGetFloat(cus, 0, "RotSpdZ", 0.0f) * 0.01745329238f;
	*(float *)(p + 0x8C) = 0.0f;
	*(float *)(p + 0x90) = cusGetFloat(cus, 0, "RotSpdRX", *(float *)(p + 0x8C)) * 0.01745329238f;
	*(float *)(p + 0x94) = cusGetFloat(cus, 0, "RotSpdRY", 0.0f) * 0.01745329238f;
	*(float *)(p + 0x98) = cusGetFloat(cus, 0, "RotSpdRZ", 0.0f) * 0.01745329238f;
	*(float *)(p + 0x9C) = 0.0f;
	return r;
}

int _PartCusConvEmit(float *e, int cus)
{
	char name[0x200];

	if (cusSetSection(cus, D_000FDE1C) != 1)
		return 0;
	e[0] = cusGetFloat(cus, 0, "OpPerSec", 0.0f);
	if (e[0] == 0.0f)
		return 0;
	e[2] = cusGetFloat(cus, 0, "Radius", -1.0f);
	if (e[2] < 0.0f)
		return 0;
	e[1] = cusGetFloat(cus, 0, "Age", 0.0f);
	if (e[1] < 0.0f)
		e[1] = 0.0f;
	e[3] = cusGetFloat(cus, 0, "RadMin", 0.0f);
	e[4] = cusGetFloat(cus, 0, "RYpX", 1.0f);
	e[5] = cusGetFloat(cus, 0, "RZpX", 1.0f);
	e[7] = cusGetFloat(cus, 0, "AlpBStart", 1.0f);
	e[8] = cusGetFloat(cus, 0, "AlpBMaxW", 0.3f);
	e[9] = cusGetFloat(cus, 0, "AlpBFdOutW", 0.7f);
	e[10] = cusGetFloat(cus, 0, "AlpBEnd", 1.0f);
	e[11] = cusGetFloat(cus, 0, "SclBStart", 1.0f);
	e[12] = cusGetFloat(cus, 0, "SclBMaxW", 0.3f);
	e[13] = cusGetFloat(cus, 0, "SclBFdOutW", 0.7f);
	e[14] = cusGetFloat(cus, 0, "SclBEnd", 1.0f);
	e[15] = cusGetFloat(cus, 0, "OpsBStart", 1.0f);
	e[16] = cusGetFloat(cus, 0, "OpsBMaxW", 0.3f);
	e[17] = cusGetFloat(cus, 0, "OpsBFdOutW", 0.7f);
	e[18] = cusGetFloat(cus, 0, "OpsBEnd", 1.0f);
	((int *)e)[6] = cusGetInt(cus, 0, "Afct", 1);
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE0C4);

extern unsigned char D_000FE100;
unsigned int I3dPicture__Get_wPixel(void *pic, int lv);
unsigned int I3dPicture__Get_hPixel(void *pic, int lv);
typedef struct { void *res; int u, v; float w, h; } PartTex;
typedef struct { int inst; PartTex tex; } Part2DBase;
void *_partInit2DBaseCntx(int inst, char *res)
{
	Part2DBase *p = _memAlloc(sizeof(Part2DBase), &D_000FE0C4, 0x199);
	PartTex *t;
	void *pic;

	if (!(p != NULL))
		consPrintf(&D_000FE100, &D_000FE0C4, 0x19B, "_partInit2DBaseCntx", "pPart2DBCntx!= NULL");
	t = &p->tex;
	p->inst = inst;
	t->res = res;
	pic = (void *)(((*(int *)(res + 0x10) + 15) & ~15) + 16);
	t->v = 0;
	t->u = 0;
	t->w = I3dPicture__Get_wPixel(pic, 0);
	t->h = I3dPicture__Get_hPixel(pic, 0);
	return p;
}

int _partFree2DBaseCntx(void *p)
{
	_memFree(p, &D_000FE0C4, 0x1C0);
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE100);

typedef struct { int inst; PartTex tex; } Part3DBase;
void *_partInit3DBaseCntx(int inst, char *res)
{
	Part3DBase *p = _memAlloc(sizeof(Part3DBase), &D_000FE0C4, 0x1D6);
	PartTex *t;
	void *pic;

	if (!(p != NULL))
		consPrintf(&D_000FE100, &D_000FE0C4, 0x1D8, "_partInit3DBaseCntx", "pPart3DBCntx!= NULL");
	t = &p->tex;
	p->inst = inst;
	t->res = res;
	pic = (void *)(((*(int *)(res + 0x10) + 15) & ~15) + 16);
	t->v = 0;
	t->u = 0;
	t->w = I3dPicture__Get_wPixel(pic, 0);
	t->h = I3dPicture__Get_hPixel(pic, 0);
	return p;
}

int _partFree3DBaseCntx(void *p)
{
	_memFree(p, &D_000FE0C4, 0x1FD);
	return 1;
}

extern unsigned char D_000FE100;
int _partEzEnvelope(float *out, float a, float b, float c, float d, float w)
{
	if (!(0.0f <= w))
		consPrintf(&D_000FE100, &D_000FE0C4, 0x21A, "_partEzEnvelope", "0.0f<= w");
	if (w < b) {
		*out = (a - 1.0f) * (1.0f - w / b) + 1.0f;
		return 0;
	}
	if (1.0f <= w) {
		*out = d;
		return 1.0f < w;
	}
	if (c < w) {
		*out = (d - 1.0f) * (w - c) / (1.0f - c) + 1.0f;
		return 0;
	}
	*out = 1.0f;
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partCusConvExt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partInitEnvCntx);

int partFreeEnvCntx(void *p)
{
	if (p != NULL) {
		_memFree(p, &D_000FE0C4, 0x2E3);
	}
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE190);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partInitEmitCntx);

int partFreeEmitCntx(void *arg0) {
    int **temp_v1;
    int temp_a1;

    temp_v1 = M2C_FIELD(arg0, int ***, 0x80);
    if (temp_v1 != NULL) {
        temp_a1 = **temp_v1;
        switch (temp_a1) {                          /* irregular */
        case 0:
            _partFree2DBaseCntx(temp_v1);
            break;
        case 1:
            _partFree3DBaseCntx(temp_v1);
            break;
        }
    }
    _memFree(arg0, &D_000FE0C4, 0x34A);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE210);

void i3dPosture2Mat(int arg0, int arg1);
int _partEzEnvelope(float *out, float a, float b, float c, float d, float t);
int partEmitAnimate(char *e)
{
	char *env = *(char **)(e + 0x7C);
	float old, v, s;

	i3dPosture2Mat((int)e, (int)(e + 0x40));
	old = *(float *)(e + 0x70);
	*(float *)(e + 0x70) = old + *(float *)(e + 0x78) * 0.01668335125f;
	v = 1.0f;
	if (*(float *)(env + 4) > 0.0f)
		_partEzEnvelope(&v, *(float *)(env + 0x3C), *(float *)(env + 0x40), *(float *)(env + 0x44), *(float *)(env + 0x48), *(float *)(e + 0x70) / *(float *)(env + 4));
	s = v * *(float *)(e + 0x74);
	return (int)(s * *(float *)(e + 0x70)) - (int)(s * old);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partInitPart2DCntx);

int partFree2DCntx(void *p)
{
	_memFree(p, &D_000FE0C4, 0x402);
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", _partPartCommonAnimate);

int _partPartCommonAnimate(void *p, float *dt, float *a, float *b);
int partPart2DAnimate(char *p)
{
	float dt, sx, sy;

	dt = *(float *)(p + 0x28) * 0.01668335125f;
	if (_partPartCommonAnimate(p, &dt, &sx, &sy))
		return 1;
	*(float *)(p + 0x74) += *(float *)(p + 0x78) * dt;
	while (*(float *)(p + 0x74) < 0.0f)
		*(float *)(p + 0x74) += 6.283185482f;
	while (*(float *)(p + 0x74) > 6.283185482f)
		*(float *)(p + 0x74) -= 6.283185482f;
	*(float *)(p + 0x5C) = *(float *)(p + 0x34) * sx;
	*(float *)(p + 0x48) = *(float *)(p + 0x38) * sy;
	return 0;
}

typedef struct { float m[16]; } PartMat;
typedef struct {
	float sx, sy, sz;
	int pad;
	float uv[4];
	float a;
	unsigned int f0 : 8;
	unsigned int blend : 2;
	unsigned int f1 : 1;
	unsigned int f2 : 1;
	unsigned int f3 : 20;
} PartSprt;
typedef struct {
	float pos[4];
	char pad[0x30];
	float sx, sy, scale;
	int blend;
	float uv[4];
	int tex[5];
	float a;
} Part2D;
void copUnitMat(PartMat *m);
void copLetVec(void *src, void *dst);
void i3dDrawTexCut(int a, int b, int c);

void partDrawPart2D(Part2D *p)
{
	PartMat m;
	PartSprt s;

	copUnitMat(&m);
	copLetVec(p, &m.m[12]);
	s.sx = p->sx * p->scale;
	s.sy = p->sy * p->scale;
	s.sz = 1.0f;
	s.a = p->a;
	s.uv[0] = p->uv[0];
	s.uv[1] = p->uv[1];
	s.uv[2] = p->uv[2];
	s.uv[3] = p->uv[3];
	s.blend = p->blend;
	s.f2 = 0;
	i3dDrawTexCut((int)p->tex, (int)&m, (int)&s);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partInitPart3DCntx);

int partFree3DCntx(void *p)
{
	_memFree(p, &D_000FE0C4, 0x533);
	return 1;
}

int _partPartCommonAnimate(void *p, float *dt, float *a, float *b);
void *memset(void *, int, unsigned int);
void copInterQuat(float *dst, void *src, float *q, float t);
void copMulQuat(void *a, float *b, void *c);
int partPart3DAnimate(char *p)
{
	float dt, sx, sy;
	float q[4];

	dt = *(float *)(p + 0x28) * 0.01668335125f;
	if (_partPartCommonAnimate(p, &dt, &sx, &sy))
		return 1;
	memset(q, 0, sizeof(q));
	q[3] = 0.1f;
	copInterQuat(q, p + 0x90, q, dt);
	copMulQuat(p + 0x80, q, p + 0x80);
	*(float *)(p + 0x5C) = *(float *)(p + 0x34) * sx;
	*(float *)(p + 0x48) = *(float *)(p + 0x38) * sy;
	return 0;
}

void copQuatMat(void *q, PartMat *m);
void partDrawPart3D(Part2D *p)
{
	PartMat m;
	PartSprt s;

	copUnitMat(&m);
	copQuatMat((char *)p + 0x80, &m);
	copLetVec(p, &m.m[12]);
	s.sx = p->sx * p->scale;
	s.sy = p->sy * p->scale;
	s.sz = 1.0f;
	s.a = 0.0f;
	s.uv[0] = p->uv[0];
	s.uv[1] = p->uv[1];
	s.uv[2] = p->uv[2];
	s.uv[3] = p->uv[3];
	s.blend = p->blend;
	s.f2 = 1;
	i3dDrawTexCut((int)p->tex, (int)&m, (int)&s);
}

float partEmitGetOps(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x74);
}

float partEmitGetSpd(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x78);
}

float partEmitGetTime(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x70);
}

int partEmitGetAfct(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x7C), int *, 0x18);
}

void partEmitSetOps(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x74) = fparg0;
}

void partEmitSetSpd(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x78) = fparg0;
}

void partEmitSetMaster(int arg0, int arg1) {
    copLetMat(arg1, arg0);
}

float partPart2DGetAge(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x20);
}

float partPart2DGetWidth(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x40);
}

float partPart2DGetHeight(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x44);
}

float partPart2DGetRot(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x74);
}

float partPart2DGetRotSpd(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x78);
}

float partPart2DGetScale(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x48);
}

float partPart2DGetTime(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x24);
}

float partPart3DGetAge(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x20);
}

float partPart3DGetWidth(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x40);
}

float partPart3DGetHeight(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x44);
}

float partPart3DGetScale(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x48);
}

float partPart3DGetTime(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x24);
}

void partPart2DSetRot(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x74) = fparg0;
}

void partPart2DSetRotSpd(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x78) = fparg0;
}

void partPart2DSetScale(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x48) = fparg0;
}

void partPart3DSetScale(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x48) = fparg0;
}

int partPart2DGetPtPos(int arg0) {
    return arg0;
}

int partPart2DGetPtTexCut(int arg0) {
    return arg0 + 0x60;
}

int partPart2DGetPtCol(int arg0) {
    return arg0 + 0x50;
}

int partPart3DGetPtPos(int arg0) {
    return arg0;
}

int partPart3DGetPtTexCut(int arg0) {
    return arg0 + 0x60;
}

int partPart3DGetPtCol(int arg0) {
    return arg0 + 0x50;
}

int partPart3DGetPtMat(int arg0) {
    return arg0 + 0xA0;
}
