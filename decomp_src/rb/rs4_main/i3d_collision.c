#include "common.h"
#include "m2c_macros.h"
float fabsf(float);
extern float g_I3cIntersectEpsilon;
extern signed char g_bI3cStrictScale;
float I3dcs_GetSqrDistLineSegA(const float *, const float *, const float *, const float *, float *, float *);
float I3dcs_GetSqrDistRaySegA(const float *, const float *, const float *, const float *, float *, float *);
float I3dcs_GetSqrDistSegSegA(const float *, const float *, const float *, const float *, float *, float *);
int I3dcs_GetIntersectLineCylA(int, int, int, int, M2C_UNK, M2C_UNK); /* extern */
int I3dcs_GetIntersectRayCylA(int, int, int, int, M2C_UNK, M2C_UNK); /* extern */
int I3dcs_GetIntersectSegCylA(int, int, int, int, M2C_UNK, M2C_UNK); /* extern */


void I3cLineParam_CnvAxis()
{
	__asm__ volatile(
		"lv.q C100.q,0($6)\n"
		"lv.q C200.q,0($5)\n"
		"lv.q C210.q,16($5)\n"
		"lv.q C220.q,32($5)\n"
		"lv.q C230.q,48($5)\n"
		"lv.q C110.q,16($6)\n"
		"vtfm3.t C010.t,E200.t,C100.t\n"
		"vadd.t C000.t,C010.t,C230.t\n"
		"vmov.s S003.s,S103.s\n"
		"vtfm3.t C010.t,E200.t,C110.t\n"
		"vmov.s S013.s,S113.s\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		: : : "memory");
}

int IntersectSub_LineTri(void *, void *, void *, void *, void *, unsigned char, int);
int I3cIntersectSub_RadiusPrim(void *, void *, void *, void *, void *, unsigned char, void *, int);
int I3cIntersect_Main(void *, void *, void *, void *, void *, int);

float I3dcs_GetSqrDistPointLineA(const float *, const float *, const float *, float *);
float I3dcs_GetSqrDistPointRayA(const float *, const float *, const float *, float *);
float I3dcs_GetSqrDistPointSegA(const float *, const float *, const float *, float *);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", IntersectSub_LineTri);

int I3cLine_IntersectTriA(void *a, void *b, void *c, void *d, void *e, unsigned char f, void *g) {
    return IntersectSub_LineTri(a, b, c, d, e, f, 0);
}

int I3cRay_IntersectTriA(void *a, void *b, void *c, void *d, void *e, unsigned char f, void *g) {
    return IntersectSub_LineTri(a, b, c, d, e, f, 1);
}

int I3cSegment_IntersectTriA(void *a, void *b, void *c, void *d, void *e, unsigned char f, void *g) {
    return IntersectSub_LineTri(a, b, c, d, e, f, 3);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cSphere_IntersectTriA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersectSub_RadiusPrim);

int I3cRLine_IntersectTriA(void *a, void *b, void *c, void *d, void *e, unsigned char f, void *g) {
    return I3cIntersectSub_RadiusPrim(a, b, c, d, e, f, g, 0);
}

int I3cRRay_IntersectTriA(void *a, void *b, void *c, void *d, void *e, unsigned char f, void *g) {
    return I3cIntersectSub_RadiusPrim(a, b, c, d, e, f, g, 1);
}

int I3cCapsule_IntersectTriA(void *a, void *b, void *c, void *d, void *e, unsigned char f, void *g) {
    return I3cIntersectSub_RadiusPrim(a, b, c, d, e, f, g, 2);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_ScanAABB_Node);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cIntersect_Main);

int I3dcs_IsIntersectSphereBoxA();
int I3cSphere_IntersectTriA();
int I3cIntersect_SphereA(void *a, void *b, void *c) {
    return I3cIntersect_Main(a, b, c, (void *)I3dcs_IsIntersectSphereBoxA, (void *)I3cSphere_IntersectTriA, 1);
}

int I3dcs_IsIntersectLineBoxA();
int I3cLine_IntersectTriA();
int I3cIntersect_LineA(void *a, void *b, void *c) {
    return I3cIntersect_Main(a, b, c, (void *)I3dcs_IsIntersectLineBoxA, (void *)I3cLine_IntersectTriA, 0);
}

int I3dcs_IsIntersectRayBoxA();
int I3cRay_IntersectTriA();
int I3cIntersect_RayA(void *a, void *b, void *c) {
    return I3cIntersect_Main(a, b, c, (void *)I3dcs_IsIntersectRayBoxA, (void *)I3cRay_IntersectTriA, 0);
}

void I3dcs_IsIntersectSegBoxA();
int I3cIntersect_SegmentA(void *a, void *b, void *c) {
    return I3cIntersect_Main(a, b, c, (void *)I3dcs_IsIntersectSegBoxA, (void *)I3cSegment_IntersectTriA, 0);
}

int I3dcs_IsIntersectRLineBoxA();
int I3cRLine_IntersectTriA();
int I3cIntersect_RLineA(void *a, void *b, void *c) {
    return I3cIntersect_Main(a, b, c, (void *)I3dcs_IsIntersectRLineBoxA, (void *)I3cRLine_IntersectTriA, 1);
}

int I3dcs_IsIntersectRRayBoxA();
int I3cRRay_IntersectTriA();
int I3cIntersect_RRayA(void *a, void *b, void *c) {
    return I3cIntersect_Main(a, b, c, (void *)I3dcs_IsIntersectRRayBoxA, (void *)I3cRRay_IntersectTriA, 1);
}

int I3dcs_IsIntersectCapBoxA();
int I3cCapsule_IntersectTriA();
int I3cIntersect_CapsuleA(void *a, void *b, void *c) {
    return I3cIntersect_Main(a, b, c, (void *)I3dcs_IsIntersectCapBoxA, (void *)I3cCapsule_IntersectTriA, 1);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cSSS_IntersectTriA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cRSS_IntersectTriA);

int I3dcs_IsIntersectCapBoxA();
int I3cSSS_IntersectTriA();
int I3cIntersect_SSSA(void *a, void *b, void *c) {
    return I3cIntersect_Main(a, b, c, (void *)I3dcs_IsIntersectCapBoxA, (void *)I3cSSS_IntersectTriA, 1);
}

int I3dcs_IsIntersectRRayBoxA();
int I3cRSS_IntersectTriA();
int I3cIntersect_RSSA(void *a, void *b, void *c) {
    return I3cIntersect_Main(a, b, c, (void *)I3dcs_IsIntersectRRayBoxA, (void *)I3cRSS_IntersectTriA, 1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3cIntersect_SetEpsilon(float fparg0) {
    g_I3cIntersectEpsilon = fparg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

float I3cIntersect_GetEpsilon(void) {
    return g_I3cIntersectEpsilon;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3cIntersect_SetStrictScale(signed char arg0) {
    g_bI3cStrictScale = arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

unsigned char I3cIntersect_GetStrictScale(void) {
    return g_bI3cStrictScale;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", CalcBlendRatio);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3cCbService_GetIntersectPointParam);

void I3dcs_GetSqrDistPointPointA()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"vsub.q C100.q,C000.q,C010.q\n"
		"vdot.t S110.s,C100.t,C100.t\n"
		"mfv $6,S110.s\n"
		"mtc1 $6,$f0\n"
		: : : "memory");
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistPointLineA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistPointRayA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistPointSegA);

extern const float D_00109B2C;
extern const float D_00109B30;
float I3dcs_GetSqrDistLineLineA(const float *p0, const float *d0, const float *p1, const float *d1, float *ps, float *pt)
{
	float a00, a01, a11, b0, b1, c, det, s, t, d;

	__asm__ volatile(
		"lv.q C000.q,0(%0)\n"
		"lv.q C010.q,0(%2)\n"
		"lv.q C020.q,0(%1)\n"
		"lv.q C030.q,0(%3)\n"
		"vsub.q C100.q,C010.q,C000.q\n"
		"vdot.t S110.s,C020.t,C020.t\n"
		"vdot.t S111.s,C020.t,C030.t\n"
		"vdot.t S112.s,C030.t,C030.t\n"
		"vdot.t S120.s,C100.t,C020.t\n"
		"vdot.t S121.s,C100.t,C030.t\n"
		"vdot.t S122.s,C100.t,C100.t\n"
		: : "r"(p0), "r"(d0), "r"(p1), "r"(d1) : "memory");
	__asm__ volatile("mfv $6,S110.s\nmtc1 $6,%0\n" : "=f"(a00) : : "$6");
	__asm__ volatile("mfv $6,S111.s\nmtc1 $6,%0\n" : "=f"(a01) : : "$6");
	__asm__ volatile("mfv $6,S112.s\nmtc1 $6,%0\n" : "=f"(a11) : : "$6");
	__asm__ volatile("mfv $6,S120.s\nmtc1 $6,%0\n" : "=f"(b0) : : "$6");
	__asm__ volatile("mfv $6,S121.s\nmtc1 $6,%0\n" : "=f"(b1) : : "$6");
	__asm__ volatile("mfv $6,S122.s\nmtc1 $6,%0\n" : "=f"(c) : : "$6");
	t = 0.0f;
	det = fabsf(a00 * a11 - a01 * a01);
	if (det >= D_00109B2C) {
		float inv = D_00109B30 / det;
		s = (a11 * b0 - a01 * b1) * inv;
		t = (a01 * b0 - a00 * b1) * inv;
		d = s * (a00 * s - a01 * t - (b0 + b0)) + t * (a11 * t - a01 * s + (b1 + b1)) + c;
	} else {
		s = b0 / a00;
		d = c - b0 * s;
	}
	d = fabsf(d);
	if (ps)
		*ps = s;
	if (pt)
		*pt = t;
	return d;
}

const float D_00109B2C = 1e-4f;

const float D_00109B30 = 1.0f;

extern const float D_00109B34;
extern const float D_00109B38;
float I3dcs_GetSqrDistLineRayA(const float *p0, const float *d0, const float *p1, const float *d1, float *ps, float *pt)
{
	float a00, a01, a11, b0, b1, c, det, s, t, d;

	__asm__ volatile(
		"lv.q C000.q,0(%0)\n"
		"lv.q C010.q,0(%2)\n"
		"lv.q C020.q,0(%1)\n"
		"lv.q C030.q,0(%3)\n"
		"vsub.q C100.q,C010.q,C000.q\n"
		"vdot.t S110.s,C020.t,C020.t\n"
		"vdot.t S111.s,C020.t,C030.t\n"
		"vdot.t S112.s,C030.t,C030.t\n"
		"vdot.t S120.s,C100.t,C020.t\n"
		"vdot.t S121.s,C100.t,C030.t\n"
		"vdot.t S122.s,C100.t,C100.t\n"
		: : "r"(p0), "r"(d0), "r"(p1), "r"(d1) : "memory");
	__asm__ volatile("mfv $6,S110.s\nmtc1 $6,%0\n" : "=f"(a00) : : "$6");
	__asm__ volatile("mfv $6,S111.s\nmtc1 $6,%0\n" : "=f"(a01) : : "$6");
	__asm__ volatile("mfv $6,S112.s\nmtc1 $6,%0\n" : "=f"(a11) : : "$6");
	__asm__ volatile("mfv $6,S120.s\nmtc1 $6,%0\n" : "=f"(b0) : : "$6");
	__asm__ volatile("mfv $6,S121.s\nmtc1 $6,%0\n" : "=f"(b1) : : "$6");
	__asm__ volatile("mfv $6,S122.s\nmtc1 $6,%0\n" : "=f"(c) : : "$6");
	det = fabsf(a00 * a11 - a01 * a01);
	if (det >= D_00109B34) {
		t = a01 * b0 - a00 * b1;
		if (t >= 0.0f) {
			float inv = D_00109B38 / det;
			s = (a11 * b0 - a01 * b1) * inv;
			t *= inv;
			d = s * (a00 * s - a01 * t - (b0 + b0)) + t * (a11 * t - a01 * s + (b1 + b1)) + c;
		} else {
			t = 0.0f;
			s = b0 / a00;
			d = c - b0 * s;
		}
	} else {
		t = 0.0f;
		s = b0 / a00;
		d = c - b0 * s;
	}
	d = fabsf(d);
	if (ps)
		*ps = s;
	if (pt)
		*pt = t;
	return d;
}

const float D_00109B34 = 1e-4f;

const float D_00109B38 = 1.0f;

extern const float D_00109B3C;
extern const float D_00109B40;
float I3dcs_GetSqrDistLineSegA(const float *p0, const float *d0, const float *p1, const float *d1, float *ps, float *pt)
{
	float a00, a01, a11, b0, b1, c, det, s, t, d;

	__asm__ volatile(
		"lv.q C000.q,0(%0)\n"
		"lv.q C010.q,0(%2)\n"
		"lv.q C020.q,0(%1)\n"
		"lv.q C030.q,0(%3)\n"
		"vsub.q C100.q,C010.q,C000.q\n"
		"vdot.t S110.s,C020.t,C020.t\n"
		"vdot.t S111.s,C020.t,C030.t\n"
		"vdot.t S112.s,C030.t,C030.t\n"
		"vdot.t S120.s,C100.t,C020.t\n"
		"vdot.t S121.s,C100.t,C030.t\n"
		"vdot.t S122.s,C100.t,C100.t\n"
		: : "r"(p0), "r"(d0), "r"(p1), "r"(d1) : "memory");
	__asm__ volatile("mfv $6,S110.s\nmtc1 $6,%0\n" : "=f"(a00) : : "$6");
	__asm__ volatile("mfv $6,S111.s\nmtc1 $6,%0\n" : "=f"(a01) : : "$6");
	__asm__ volatile("mfv $6,S112.s\nmtc1 $6,%0\n" : "=f"(a11) : : "$6");
	__asm__ volatile("mfv $6,S120.s\nmtc1 $6,%0\n" : "=f"(b0) : : "$6");
	__asm__ volatile("mfv $6,S121.s\nmtc1 $6,%0\n" : "=f"(b1) : : "$6");
	__asm__ volatile("mfv $6,S122.s\nmtc1 $6,%0\n" : "=f"(c) : : "$6");
	det = fabsf(a00 * a11 - a01 * a01);
	if (det >= D_00109B3C) {
		t = a01 * b0 - a00 * b1;
		if (t >= 0.0f) {
			if (t <= det) {
				float inv = D_00109B40 / det;
				s = (a11 * b0 - a01 * b1) * inv;
				t *= inv;
				d = s * (a00 * s - a01 * t - (b0 + b0)) + t * (a11 * t - a01 * s + (b1 + b1)) + c;
			} else {
				float tmp = a01 + b0;
				t = D_00109B40;
				s = tmp / a00;
				d = a11 - tmp * s + (b1 + b1) + c;
			}
		} else {
			t = 0.0f;
			s = b0 / a00;
			d = c - b0 * s;
		}
	} else {
		t = 0.0f;
		s = b0 / a00;
		d = c - b0 * s;
	}
	if (ps)
		*ps = s;
	if (pt)
		*pt = t;
	return fabsf(d);
}

const float D_00109B3C = 1e-4f;

const float D_00109B40 = 1.0f;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistRayRayA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistRaySegA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetSqrDistSegSegA);

int I3dcs_IsIntersectSphereBoxA(const float *sph, const float *unused, const float *ext)
{
	float a[4] __attribute__((aligned(16)));
	float v[4] __attribute__((aligned(16)));
	float m[4] __attribute__((aligned(16)));

	__asm__ volatile(
		"lv.q C010.q,0(%1)\n"
		"vabs.q C000.q,C010.q\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(a), "r"(sph) : "memory");
	I3dVecSubA(v, a, ext);
#define SQ() \
	v[3] = a[3]; \
	__asm__ volatile( \
		"lv.q C010.q,0(%1)\n" \
		"lv.q C020.q,0(%1)\n" \
		"vmul.q C000.q,C010.q,C020.q\n" \
		"sv.q C000.q,0(%0)\n" \
		: : "r"(m), "r"(v) : "memory")
	if (v[0] <= 0.0f) {
		if (v[1] <= 0.0f) {
			if (v[2] <= 0.0f)
				return 1;
			return v[2] <= a[3];
		}
		if (v[2] <= 0.0f)
			return v[1] <= a[3];
		SQ();
		return m[1] + m[2] <= m[3];
	}
	if (v[1] <= 0.0f) {
		if (v[2] <= 0.0f)
			return v[0] <= a[3];
		SQ();
		return m[0] + m[2] <= m[3];
	}
	SQ();
	if (v[2] <= 0.0f)
		return m[0] + m[1] <= m[3];
	return m[0] + m[1] + m[2] <= m[3];
#undef SQ
}

void I3dcs_IsIntersectSegBoxA()
{
	__asm__ volatile(
		".set noreorder\n"
		"lv.q C020.q,0($5)\n"
		"lv.q C010.q,0($4)\n"
		"lv.q C030.q,0($6)\n"
		"vpfxt 1/2,1/2,1/2,1/2\n"
		"vmul.t C100.t,C020.t,C000.t\n"
		"vadd.t C110.t,C010.t,C100.t\n"
		"vabs.t C120.t,C100.t\n"
		"vabs.t C130.t,C110.t\n"
		"vadd.t C200.t,C030.t,C120.t\n"
		"vcmp.t GT,C130.t,C200.t\n"
		"bvt 4,1f\n"
		"li $2,0\n"
		"vcrsp.t C210.t,C100.t,C110.t\n"
		"vabs.t C210.t,C210.t\n"
		"vcrs.t C300.t,C030.t,C120.t\n"
		"vcrs.t C310.t,C120.t,C030.t\n"
		"vadd.t C320.t,C300.t,C310.t\n"
		"vcmp.t GT,C210.t,C320.t\n"
		"bvfl 4,1f\n"
		"li $2,1\n"
		"1:\n"
		".set reorder\n"
		: : : "memory");
}

int I3dcs_IsIntersectLineBoxA()
{
	__asm__ volatile(
		".set noreorder\n"
		"lv.q C020.q,0($5)\n"
		"lv.q C030.q,0($4)\n"
		"lv.q C010.q,0($6)\n"
		"vabs.t C100.t,C020.t\n"
		"vcrsp.t C110.t,C020.t,C030.t\n"
		"vabs.t C110.t,C110.t\n"
		"vcrs.t C300.t,C010.t,C100.t\n"
		"vcrs.t C310.t,C100.t,C010.t\n"
		"vadd.t C320.t,C300.t,C310.t\n"
		"vcmp.t GT,C110.t,C320.t\n"
		"bvfl 4,1f\n"
		"li $2,1\n"
		"li $2,0\n"
		"1:\n"
		".set reorder\n"
		: : : "memory");
}

int I3dcs_IsIntersectRayBoxA(const float *p, const float *d, const float *ext)
{
	float ex = ext[0], ey = ext[1], ez = ext[2];
	float ap[4] __attribute__((aligned(16)));
	float pd[4] __attribute__((aligned(16)));

	__asm__ volatile(
		"lv.q C010.q,0(%1)\n"
		"vabs.q C000.q,C010.q\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(ap), "r"(p) : "memory");
	__asm__ volatile(
		"lv.q C010.q,0(%1)\n"
		"lv.q C020.q,0(%2)\n"
		"vmul.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(pd), "r"(p), "r"(d) : "memory");
	{
		float a0 = ap[0], a1 = ap[1], a2 = ap[2];
		float m0 = pd[0], m1 = pd[1], m2 = pd[2];
		if ((ex < a0 && m0 >= 0.0f) || (ey < a1 && m1 >= 0.0f) || (ez < a2 && m2 >= 0.0f))
			return 0;
	}
	return I3dcs_IsIntersectLineBoxA(p, d, ext);
}

int I3dcs_IsIntersectCapBoxA(const float *a, const float *b, const float *box) {
    float t[4];
    int i;
    for (i = 0; i < 3; i++) t[i] = box[i] + a[3];
    return ((int (*)(const float *, const float *, const float *))I3dcs_IsIntersectSegBoxA)(a, b, t);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectRRayBoxA);

int I3dcs_IsIntersectRLineBoxA()
{
	__asm__ volatile(
		".set noreorder\n"
		"lv.q C010.q,0($4)\n"
		"lv.q C020.q,0($5)\n"
		"lv.q C030.q,0($6)\n"
		"vcrsp.t C100.t,C020.t,C010.t\n"
		"vabs.t C100.t,C100.t\n"
		"vabs.t C020.t,C020.t\n"
		"vpfxt w,w,w,w\n"
		"vadd.q C030.q,C030.q,C010.q\n"
		"vcrs.t C300.t,C030.t,C020.t\n"
		"vcrs.t C310.t,C020.t,C030.t\n"
		"vadd.t C320.t,C300.t,C310.t\n"
		"vcmp.t GT,C100.t,C320.t\n"
		"bvfl 4,1f\n"
		"li $2,1\n"
		"li $2,0\n"
		"1:\n"
		".set reorder\n"
		: : : "memory");
}

int I3dcs_IsIntersectSphereSphereA(const float *s, const float *t) {
    float r = s[3] + t[3];
    return ((float (*)(const float *, const float *))I3dcs_GetSqrDistPointPointA)(s, t) <= r * r;
}

int I3dcs_IsIntersectSphereLineA(const float *s, const float *a, const float *b) {
    float r = s[3];
    int ret = 1;
    if (!(I3dcs_GetSqrDistPointLineA(s, a, b, NULL) <= r * r)) ret = 0;
    return ret;
}

int I3dcs_IsIntersectSphereRayA(const float *s, const float *a, const float *b) {
    float r = s[3];
    int ret = 1;
    if (!(I3dcs_GetSqrDistPointRayA(s, a, b, NULL) <= r * r)) ret = 0;
    return ret;
}

int I3dcs_IsIntersectSphereSegA(const float *s, const float *a, const float *b) {
    float r = s[3];
    int ret = 1;
    if (!(I3dcs_GetSqrDistPointSegA(s, a, b, NULL) <= r * r)) ret = 0;
    return ret;
}

int I3dcs_IsIntersectSphereRLineA(const float *s, const float *a, const float *b) {
    float r = s[3] + a[3];
    return I3dcs_GetSqrDistPointLineA(s, a, b, NULL) <= r * r;
}

int I3dcs_IsIntersectSphereRRayA(const float *s, const float *a, const float *b) {
    float r = s[3] + a[3];
    return I3dcs_GetSqrDistPointRayA(s, a, b, NULL) <= r * r;
}

int I3dcs_IsIntersectSphereCapA(const float *s, const float *a, const float *b) {
    float r = s[3] + a[3];
    return I3dcs_GetSqrDistPointSegA(s, a, b, NULL) <= r * r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
int I3dcs_IsIntersectCapLineA(void *arg0, int arg1, int arg2, int arg3) {
    float temp_f20;
    float temp_f20_2;
    int var_v0;

    temp_f20 = M2C_FIELD(arg0, float *, 0xC);
    temp_f20_2 = temp_f20 * temp_f20;
    var_v0 = 1;
    if (!(I3dcs_GetSqrDistLineSegA(arg2, arg3, arg0, arg1, 0, 0) <= temp_f20_2)) {
        var_v0 = 0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
int I3dcs_IsIntersectCapRayA(void *arg0, int arg1, int arg2, int arg3) {
    float temp_f20;
    float temp_f20_2;
    int var_v0;

    temp_f20 = M2C_FIELD(arg0, float *, 0xC);
    temp_f20_2 = temp_f20 * temp_f20;
    var_v0 = 1;
    if (!(I3dcs_GetSqrDistRaySegA(arg2, arg3, arg0, arg1, 0, 0) <= temp_f20_2)) {
        var_v0 = 0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
int I3dcs_IsIntersectCapSegA(void *arg0, int arg1, int arg2, int arg3) {
    float temp_f20;
    float temp_f20_2;
    int var_v0;

    temp_f20 = M2C_FIELD(arg0, float *, 0xC);
    temp_f20_2 = temp_f20 * temp_f20;
    var_v0 = 1;
    if (!(I3dcs_GetSqrDistSegSegA(arg2, arg3, arg0, arg1, 0, 0) <= temp_f20_2)) {
        var_v0 = 0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
int I3dcs_IsIntersectCapRLineA(void *arg0, int arg1, void *arg2, int arg3) {
    float temp_f20;
    int var_v0;

    temp_f20 = M2C_FIELD(arg0, float *, 0xC) + M2C_FIELD(arg2, float *, 0xC);
    var_v0 = 1;
    if (!(I3dcs_GetSqrDistLineSegA(arg2, arg3, arg0, arg1, 0, 0) <= (temp_f20 * temp_f20))) {
        var_v0 = 0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
int I3dcs_IsIntersectCapRRayA(void *arg0, int arg1, void *arg2, int arg3) {
    float temp_f20;
    int var_v0;

    temp_f20 = M2C_FIELD(arg0, float *, 0xC) + M2C_FIELD(arg2, float *, 0xC);
    var_v0 = 1;
    if (!(I3dcs_GetSqrDistRaySegA(arg2, arg3, arg0, arg1, 0, 0) <= (temp_f20 * temp_f20))) {
        var_v0 = 0;
    }
    return var_v0;
}

int I3dcs_IsIntersectCapCapA(const float *a, const float *b, const float *c, const float *d) {
    float r = a[3] + c[3];
    int ret = 1;
    if (!(I3dcs_GetSqrDistSegSegA(a, b, c, d, NULL, NULL) <= r * r)) ret = 0;
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetIntersectLineSphereA);

int I3dcs_GetIntersectRaySphereA(const float *c, const float *d, const float *s, float *pmin, float *pmax)
{
	float t[2];
	int r = I3dcs_GetIntersectLineSphereA(c, d, s, &t[0], &t[1]);
	if (r == 0)
		return 0;
	if (pmin)
		*pmin = t[0];
	if (pmax)
		*pmax = t[1];
	if (t[0] < 0.0f) {
		if (t[1] < 0.0f)
			return 0;
		r--;
	}
	return r;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_GetIntersectSegSphereA);

int I3dcs_GetIntersectCapSphereA(const float *c, const float *a1, const float *sph, void *a3, void *a4)
{
	float s[4] __attribute__((aligned(16)));
	I3dVecCopyA(s, sph);
	s[3] += c[3];
	return I3dcs_GetIntersectSegSphereA(c, a1, s, a3, a4);
}

int I3dcs_GetIntersectRLineSphereA(const float *c, const float *a1, const float *sph, void *a3, void *a4)
{
	float s[4] __attribute__((aligned(16)));
	I3dVecCopyA(s, sph);
	s[3] += c[3];
	return I3dcs_GetIntersectLineSphereA(c, a1, s, a3, a4);
}

int I3dcs_GetIntersectRRaySphereA(const float *c, const float *a1, const float *sph, void *a3, void *a4)
{
	float s[4] __attribute__((aligned(16)));
	I3dVecCopyA(s, sph);
	s[3] += c[3];
	return I3dcs_GetIntersectRaySphereA(c, a1, s, a3, a4);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_collision", I3dcs_IsIntersectCylSphereA);

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dcs_IsIntersectCylLineA(int arg0, int arg1, int arg2, int arg3) {
    return I3dcs_GetIntersectLineCylA(arg2, arg3, arg0, arg1, 0, 0) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dcs_IsIntersectCylRayA(int arg0, int arg1, int arg2, int arg3) {
    return I3dcs_GetIntersectRayCylA(arg2, arg3, arg0, arg1, 0, 0) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dcs_IsIntersectCylSegA(int arg0, int arg1, int arg2, int arg3) {
    return I3dcs_GetIntersectSegCylA(arg2, arg3, arg0, arg1, 0, 0) != 0;
}
