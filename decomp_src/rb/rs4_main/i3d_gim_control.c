/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"

int pow2(int n)
{
	float f = n;
	int b = *(int *)&f;
	if (b & 0x7FFFFF)
		b += 0x800000;
	return 1 << ((b >> 23) - 127);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3dGimPictureActivate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rRoot__MakePresetPacket);

int **I3rModel__GetWork_PSP();
int I3rRoot__ClearPresetPacket(char *r)
{
	int *w = *I3rModel__GetWork_PSP(r + 0x10);
	unsigned int n = w[1];
	int *p = (int *)w[0];
	unsigned int i;
	for (i = 0; i < n; i++)
		*p++ = 0;
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rRoot__AssignTex);

typedef struct { float m[16]; } Mat44;
int I3rRoot__CopyLocalBasicTransformA(int *root, Mat44 *dst)
{
	unsigned int i, n;
	Mat44 *src;

	n = *(unsigned int *)(root[6] + 0x34) << 8 >> 8;
	src = *(Mat44 **)(root[4] + 0x10);
	for (i = 0; i < n; i++) {
		__asm__ volatile(
			"lv.q C000.q,0(%1)\n"
			"lv.q C010.q,16(%1)\n"
			"lv.q C020.q,32(%1)\n"
			"lv.q C030.q,48(%1)\n"
			"sv.q C000.q,0(%0)\n"
			"sv.q C010.q,16(%0)\n"
			"sv.q C020.q,32(%0)\n"
			"sv.q C030.q,48(%0)\n"
			: : "r"(&dst[i]), "r"(&src[i]) : "memory");
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rRoot__ConvertLocalToModelA);

extern const float D_001090B8;
typedef struct { float c[4]; } Sphere;
typedef struct { int pad[4]; Sphere *sphere; } RootCS;
int I3rRoot__CopyClipSphereA(RootCS *root, float *center, float *radius)
{
	Sphere *s = root->sphere;
	const float *one = &D_001090B8;

	*radius = s->c[3];
	__asm__ volatile(
		"lv.q C000.q,0(%1)\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(center), "r"(s) : "memory");
	center[3] = *one;
	return 0;
}

const float D_001090B8 = 1.0f;

typedef struct { float *key; int pad[3]; } MatEnt;
int I3rRoot__OffsetMaterialKey(int *root, int i, float d)
{
    MatEnt *t = *(MatEnt **)(root[6] + 8);
    float *m;
    t += i;
    m = t->key;
    if (m) *m += d;
    return 0;
}

int I3rRoot__OffsetAllMaterialKey(int *root, float d)
{
    unsigned int i, n;
    int *r = root + 4;
    n = *(unsigned int *)(r[2] + 4) << 8 >> 8;
    for (i = 0; i < n; i++) {
        MatEnt *t = *(MatEnt **)(r[2] + 8);
        float *m;
        t += i;
        m = t->key;
        if (m) *m += d;
    }
    return 0;
}

int I3rRoot__UpdateMarkedMaterial(int *root)
{
    int i, n;
    int *r = root + 4;
    n = *(unsigned int *)(r[2] + 4) << 8 >> 8;
    for (i = 0; i < n; i++) {
        MatEnt *t = *(MatEnt **)(r[2] + 8);
        char *m;
        t += i;
        m = (char *)t->key;
        if (*(unsigned char *)(m + 0xC)) (*(short *)(m + 8))++;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3rRoot__ReplaceStqMapEntity);

int I3rLayer__GetOffset(void *l)
{
	void *a;
	int r;
	if (I3rLayer__IsExistAdjustStq(l) == 0) {
		r = 0;
		goto end;
	}
	a = (void *)I3rLayer__GetAdjustStq(l);
	if (I3rAdjustStq__IsExistOffset(a) == 0) {
		r = 0;
		goto end;
	}
	r = *(int *)I3rAdjustStq__GetOffset(a);
end:
	return r;
}

int I3rLayer__GetRepeat(void *l)
{
	void *a;
	int r;
	if (I3rLayer__IsExistAdjustStq(l) == 0) {
		r = 0;
		goto end;
	}
	a = (void *)I3rLayer__GetAdjustStq(l);
	if (I3rAdjustStq__IsExistRepeat(a) == 0) {
		r = 0;
		goto end;
	}
	r = *(int *)I3rAdjustStq__GetRepeat(a);
end:
	return r;
}

int I3rLayer__GetRotate(void *l)
{
	void *a;
	int r;
	if (I3rLayer__IsExistAdjustStq(l) == 0) {
		r = 0;
		goto end;
	}
	a = (void *)I3rLayer__GetAdjustStq(l);
	if (I3rAdjustStq__IsExistRotate(a) == 0) {
		r = 0;
		goto end;
	}
	r = *(int *)I3rAdjustStq__GetRotate(a);
end:
	return r;
}

int I3rLayer__SetOffset(void *l, int v)
{
	void *a;
	if (I3rLayer__IsExistAdjustStq(l) == 0)
		return 1;
	a = I3rLayer__GetAdjustStq(l);
	if (I3rAdjustStq__IsExistOffset(a) == 0)
		return 1;
	*(int *)I3rAdjustStq__GetOffset(a) = v;
	return 0;
}

int I3rLayer__SetRepeat(void *l, int v)
{
	void *a;
	if (I3rLayer__IsExistAdjustStq(l) == 0)
		return 1;
	a = I3rLayer__GetAdjustStq(l);
	if (I3rAdjustStq__IsExistRepeat(a) == 0)
		return 1;
	*(int *)I3rAdjustStq__GetRepeat(a) = v;
	return 0;
}

int I3rLayer__SetRotate(void *l, int v)
{
	void *a;
	if (I3rLayer__IsExistAdjustStq(l) == 0)
		return 1;
	a = I3rLayer__GetAdjustStq(l);
	if (I3rAdjustStq__IsExistRotate(a) == 0)
		return 1;
	*(int *)I3rAdjustStq__GetRotate(a) = v;
	return 0;
}

void I3dVecClearA();
void I3dLightStatusParam__ClearA(int *f)
{
	I3dVecClearA(f);
	f[4] = 0;
	f[5] = 0;
	f[6] = 0;
	f[7] = 0;
	f[8] = 0;
	f[9] = 0;
}

typedef struct { float dir[4]; float col[4]; } I3dDirLight;
typedef struct { char pad[0x10]; unsigned int nDir; I3dDirLight *pDir; char p2[0x10]; void *render; } I3dLightStatus;
void *I3dRender__ReserveTrashQwc(void *, int);
void I3dVecNormalizeXYZ(float *, const float *);
int I3dLightStatus__SetDirLight(I3dLightStatus *ls, unsigned int n, I3dDirLight *src)
{
	ls->nDir = n;
	if (n == 0) {
		ls->pDir = 0;
	} else {
		I3dDirLight *dst = I3dRender__ReserveTrashQwc(ls->render, n * 2);
		unsigned int i;

		for (i = 0; i < n; i++) {
			I3dDirLight *d = &dst[i], *s = &src[i];
			I3dVecNormalizeXYZ(d->dir, s->dir);
			__asm__ volatile(
				"lv.q C000.q,0(%1)\n"
				"sv.q C000.q,0(%0)\n"
				: : "r"(d->col), "r"(s->col) : "memory");
		}
		ls->pDir = dst;
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_gim_control", I3dLightStatus__SetPointLight);

typedef struct { float pos[4]; float dir[4]; float col[4]; float spread, angle, p2, p3; } I3dSpotLight;
typedef struct { char pad[0x20]; unsigned int nSpot; I3dSpotLight *pSpot; void *render; } I3dLightStatusS;
extern const float D_001090BC;
extern const float D_001090C0;
extern const float D_001090C4;
extern const float D_001090C8;
float cosf(float);
float sinf(float);
int I3dLightStatus__SetSpotLight(I3dLightStatusS *ls, unsigned int n, I3dSpotLight *src)
{
	ls->nSpot = n;
	if (n == 0) {
		ls->pSpot = 0;
	} else {
		I3dSpotLight *dst = I3dRender__ReserveTrashQwc(ls->render, n * 4);
		unsigned int i;

		for (i = 0; i < n; i++) {
			I3dSpotLight *d = &dst[i], *s = &src[i];
			float a, b, ca, cb;

			__asm__ volatile(
				"lv.q C000.q,0(%1)\n"
				"sv.q C000.q,0(%0)\n"
				: : "r"(d->pos), "r"(s->pos) : "memory");
			I3dVecNormalizeXYZ(d->dir, s->dir);
			__asm__ volatile(
				"lv.q C000.q,0(%1)\n"
				"sv.q C000.q,0(%0)\n"
				: : "r"(d->col), "r"(s->col) : "memory");
			a = s->angle;
			b = s->spread;
			if (D_001090BC < a)
				a = D_001090BC;
			if (a < D_001090C0)
				a = D_001090C0;
			if (D_001090BC < b)
				b = D_001090BC;
			if (b < D_001090C0)
				b = D_001090C0;
			if (a * D_001090C4 < b)
				b = a * D_001090C4;
			cb = cosf(b);
			ca = cosf(a);
			d->spread = ca;
			d->angle = D_001090C8 / (cb - ca);
			d->p2 = ca * ca;
			d->p3 = D_001090C8 / sinf(a);
		}
		ls->pSpot = dst;
	}
	return 0;
}

const float D_001090BC = 1.5697963f;
const float D_001090C0 = 0.001f;
const float D_001090C4 = 0.95f;
const float D_001090C8 = 1.0f;

void I3dLightStatus__SetAmbientLight()
{
	__asm__ volatile(
		"lv.q C000.q,0($5)\n"
		"sv.q C000.q,0($4)\n"
		"move $2,$0\n"
		: : : "memory");
}
