/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char D_00109C00;
extern unsigned char D_00109C50;
M2C_UNK sgxFlush();                                 /* extern */
M2C_UNK sgxTickProc(float);                           /* extern */
extern int gSgxMallocFunc;
extern int gSgxFreeFunc;
extern int gSgxPrintFunc;
extern int gSgxDebugFlags;
extern int D_0011FBE4;
extern int D_0011FBE8;
extern int D_0011FBF0;
extern int D_0011FC00;

int IntersectSubOBBA()
{
	__asm__ volatile(
		"lv.q C010.q,0($4)\n"
		"lv.q C020.q,0($5)\n"
		"lv.q C030.q,0($6)\n"
		"lv.q C100.q,0($7)\n"
		"lv.q C110.q,16($7)\n"
		"lv.q C120.q,32($7)\n"
		"vabs.t C020.t,C020.t\n"
		"vdot.t S000.s,C010.t,C100.t\n"
		"vdot.t S001.s,C010.t,C110.t\n"
		"vdot.t S002.s,C010.t,C120.t\n"
		"vabs.t C000.t,C000.t\n"
		"vcrs.t C300.t,C020.t,C030.t\n"
		"vcrs.t C310.t,C030.t,C020.t\n"
		"vadd.t C320.t,C300.t,C310.t\n"
		"vcmp.t GT,C000.t,C320.t\n"
		".set noreorder\n"
		"bvfl 4,1f\n"
		"li $2,1\n"
		".set reorder\n"
		"li $2,0\n"
		"1:\n"
		"sltiu $2,$2,1\n"
		: : : "memory");
}

void I3dcsSub_ProjectVectorXYZA()
{
	__asm__ volatile(
		"lv.q C010.q,0($6)\n"
		"lv.q C100.q,0($5)\n"
		"lv.q C110.q,16($5)\n"
		"lv.q C120.q,32($5)\n"
		"vdot.t S000.s,C010.t,C100.t\n"
		"vdot.t S001.s,C010.t,C110.t\n"
		"vdot.t S002.s,C010.t,C120.t\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void I3dVecSubA(float *, const float *, const float *);
void I3dVecCrossA(float *, const float *, const float *);

int I3dcs_IsIntersectLineOBBA(const float *org, const float *dir, const float *ext, const float *obb)
{
	float v[4] __attribute__((aligned(16)));
	float pd[4] __attribute__((aligned(16)));
	I3dVecSubA(v, org, obb + 12);
	I3dVecCrossA(v, dir, v);
	I3dcsSub_ProjectVectorXYZA(pd, obb, dir);
	return IntersectSubOBBA(v, pd, ext, obb);
}

int I3dcs_IsIntersectRayOBBA(const float *org, const float *dir, const float *ext, const float *obb)
{
	float cr[4] __attribute__((aligned(16)));
	float v[4] __attribute__((aligned(16)));
	float po[4] __attribute__((aligned(16)));
	float pd[4] __attribute__((aligned(16)));

	I3dVecSubA(v, org, obb + 12);
	I3dcsSub_ProjectVectorXYZA(pd, obb, dir);
	I3dcsSub_ProjectVectorXYZA(po, obb, v);
	__asm__ volatile(
		"lv.q C010.q,0(%1)\n"
		"lv.q C020.q,0(%2)\n"
		"vmul.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(cr), "r"(po), "r"(pd) : "memory");
	__asm__ volatile(
		"lv.q C010.q,0(%0)\n"
		"vabs.q C000.q,C010.q\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(po) : "memory");
	{
		float a0 = po[0], a1 = po[1], a2 = po[2];
		float e0 = ext[0], e1 = ext[1], e2 = ext[2];
		float m0 = cr[0], m1 = cr[1], m2 = cr[2];
		if ((e0 < a0 && m0 >= 0.0f) || (e1 < a1 && m1 >= 0.0f) || (e2 < a2 && m2 >= 0.0f))
			return 0;
	}
	I3dVecCrossA(cr, dir, v);
	return IntersectSubOBBA(cr, pd, ext, obb);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_IsIntersectSegOBBA);

int I3dcs_IsIntersectRLineOBBA(const float *s, const float *d, const float *ext, const float *obb)
{
	float e[3];
	e[0] = ext[0] + s[3];
	e[1] = ext[1] + s[3];
	e[2] = ext[2] + s[3];
	return I3dcs_IsIntersectLineOBBA(s, d, e, obb);
}

int I3dcs_IsIntersectRRayOBBA(const float *s, const float *d, const float *ext, const float *obb)
{
	float e[3];
	e[0] = ext[0] + s[3];
	e[1] = ext[1] + s[3];
	e[2] = ext[2] + s[3];
	return I3dcs_IsIntersectRayOBBA(s, d, e, obb);
}

int I3dcs_IsIntersectCapOBBA(const float *s, const float *d, const float *ext, const float *obb)
{
	float e[3];
	e[0] = ext[0] + s[3];
	e[1] = ext[1] + s[3];
	e[2] = ext[2] + s[3];
	return I3dcs_IsIntersectSegOBBA(s, d, e, obb);
}

float I3dVecDotA(const float *, const float *);
int I3dcs_IsIntersectSphereOBBA(const float *sph, const float *ext, const float *obb)
{
	float d[4] __attribute__((aligned(16)));
	float v[4] __attribute__((aligned(16)));
	float m[4] __attribute__((aligned(16)));

	I3dVecSubA(d, sph, obb + 12);
	v[0] = I3dVecDotA(d, obb);
	v[1] = I3dVecDotA(d, obb + 4);
	v[2] = I3dVecDotA(d, obb + 8);
	v[3] = sph[3];
	__asm__ volatile(
		"lv.q C010.q,0(%0)\n"
		"vabs.q C000.q,C010.q\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(v) : "memory");
	I3dVecSubA(v, v, ext);
	__asm__ volatile(
		"lv.q C010.q,0(%1)\n"
		"lv.q C020.q,0(%1)\n"
		"vmul.q C000.q,C010.q,C020.q\n"
		"sv.q C000.q,0(%0)\n"
		: : "r"(m), "r"(v) : "memory");
	if (v[0] <= 0.0f) {
		if (v[1] <= 0.0f) {
			if (v[2] <= 0.0f)
				return 1;
			return v[2] <= v[3];
		}
		if (v[2] <= 0.0f)
			return v[1] <= v[3];
		return m[1] + m[2] <= m[3];
	}
	if (v[1] <= 0.0f) {
		if (v[2] <= 0.0f)
			return v[0] <= v[3];
		return m[0] + m[2] <= m[3];
	}
	if (v[2] <= 0.0f)
		return m[0] + m[1] <= m[3];
	return m[0] + m[1] + m[2] <= m[3];
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", I3dcs_IsIntersectOBBOBBA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", Clip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", BoxClipCheckA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_obb", GetIntersectOBBSubA);

extern const float D_00109BDC, D_00109BE0;
int GetIntersectOBBSubA();
int I3dcs_GetIntersectLineOBBA(const float *o, const float *d, const float *e, const float *b, float *pmin, float *pmax)
{
	float t[2];
	int r;
	t[0] = D_00109BDC;
	t[1] = D_00109BE0;
	r = GetIntersectOBBSubA(o, d, e, b, &t[0], &t[1]);
	if (pmin)
		*pmin = t[0];
	if (pmax)
		*pmax = t[1];
	return r;
}
const float D_00109BDC = -9.99999968e+37f;
const float D_00109BE0 = 9.99999968e+37f;

extern const float D_00109BE4;
int I3dcs_GetIntersectRayOBBA(const float *o, const float *d, const float *e, const float *b, float *pmin, float *pmax)
{
	float t[2];
	int r;
	t[0] = 0.0f;
	t[1] = D_00109BE4;
	r = GetIntersectOBBSubA(o, d, e, b, &t[0], &t[1]);
	if (pmin)
		*pmin = t[0];
	if (pmax)
		*pmax = t[1];
	return r;
}
const float D_00109BE4 = 9.99999968e+37f;

extern const float D_00109BE8;
int I3dcs_GetIntersectSegOBBA(const float *o, const float *d, const float *e, const float *b, float *pmin, float *pmax)
{
	float t[2];
	int r;
	t[0] = 0.0f;
	t[1] = D_00109BE8;
	r = GetIntersectOBBSubA(o, d, e, b, &t[0], &t[1]);
	if (pmin)
		*pmin = t[0];
	if (pmax)
		*pmax = t[1];
	return r;
}
const float D_00109BE8 = 1.0f;
