/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK I3dVecCopyA(int, int);                      /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_vertex_anim", BinSearchSection_FloatArray);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_vertex_anim", I3rArrayKeyFrameFloatEntity__Solve);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_vertex_anim", I3rAnimFloat__Solve);

typedef struct { float a[4]; float b[4]; } I3rKeyV4;
typedef struct { float first[4]; float last[4]; int p0; I3rKeyV4 *keys; float *times; int p1; unsigned short num; } I3rArrayKeyFrameVector4Entity;
int BinSearchSection_FloatArray(float *, unsigned int, float);
void I3rArrayKeyFrameVector4Entity__Solve(I3rArrayKeyFrameVector4Entity *e, float *out, float t)
{
	unsigned int n = e->num;
	float *times = e->times;
	int i;

	if (n == 0) {
		__asm__ volatile(
			"lv.q C000.q,0(%1)\n"
			"sv.q C000.q,0(%0)\n"
			: : "r"(out), "r"(e->last) : "memory");
		return;
	}
	i = BinSearchSection_FloatArray(times, n, t);
	if (i < 0) {
		__asm__ volatile(
			"lv.q C000.q,0(%1)\n"
			"sv.q C000.q,0(%0)\n"
			: : "r"(out), "r"(e->last) : "memory");
	} else if (i >= (int)n - 1) {
		__asm__ volatile(
			"lv.q C000.q,0(%1)\n"
			"sv.q C000.q,0(%0)\n"
			: : "r"(out), "r"(e->first) : "memory");
	} else {
		I3rKeyV4 *k = &e->keys[i];
		out[0] = k->a[0] * t + k->b[0];
		out[1] = k->a[1] * t + k->b[1];
		out[2] = k->a[2] * t + k->b[2];
		out[3] = k->a[3] * t + k->b[3];
	}
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3rAnimVector4__Solve(void *arg0, float *arg1, float t) {
    I3rArrayKeyFrameVector4Entity *temp_v0;

    temp_v0 = **(I3rArrayKeyFrameVector4Entity ***)((char *)arg0 + 8);
    if (temp_v0 != 0) {
        I3rArrayKeyFrameVector4Entity__Solve(temp_v0, arg1, t);
    } else {
        I3dVecCopyA((int)arg1, M2C_FIELD(arg0, int *, 0));
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_vertex_anim", I3rArrayAnimVector4__Solve);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_vertex_anim", I3rArrayAnimVector4__SolveAndMadd);
