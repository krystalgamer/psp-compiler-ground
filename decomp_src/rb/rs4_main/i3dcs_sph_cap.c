#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_sph_cap", GenerateOrthonormalBasis);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_sph_cap", I3dcs_GetIntersectLineCylExA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_sph_cap", I3dcs_GetIntersectLineCapA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_sph_cap", I3dcs_GetIntersectLineCylA);

int I3dcs_GetIntersectRayCylA(const float *c, const float *d, const float *cap, const float *x, float *pmin, float *pmax)
{
	float t[2];
	int r = I3dcs_GetIntersectLineCylA(c, d, cap, x, &t[0], &t[1]);
	if (r == 0 || t[1] < 0.0f)
		return 0;
	if (t[0] < 0.0f)
		r ^= 1;
	if (pmin)
		*pmin = t[0];
	if (pmax)
		*pmax = t[1];
	return r;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_sph_cap", I3dcs_GetIntersectSegCylA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_sph_cap", I3dcs_IsIntersectCylRLineA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_sph_cap", I3dcs_IsIntersectCylRRayA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_sph_cap", I3dcs_IsIntersectCylCapA);

int I3dcs_GetIntersectRayCapA(const float *c, const float *d, const float *cap, const float *x, float *pmin, float *pmax)
{
	float t[2];
	int r = I3dcs_GetIntersectLineCapA(c, d, cap, x, &t[0], &t[1]);
	if (r == 0 || t[1] < 0.0f)
		return 0;
	if (t[0] < 0.0f)
		r ^= 1;
	if (pmin)
		*pmin = t[0];
	if (pmax)
		*pmax = t[1];
	return r;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_sph_cap", I3dcs_GetIntersectSegCapA);

int I3dcs_GetIntersectRLineCapA(const float *c, const float *a1, const float *cap, void *a3, void *a4, void *a5)
{
	float s[4] __attribute__((aligned(16)));
	I3dVecCopyA(s, cap);
	s[3] += c[3];
	return I3dcs_GetIntersectLineCapA(c, a1, s, a3, a4, a5);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_sph_cap", I3dcs_GetIntersectRRayCapA);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_sph_cap", I3dcs_GetIntersectCapCapA);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3dcs_sph_cap", D_00109BC0);
