/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
extern signed char D_000F9BF0;
extern unsigned char Seed;


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", D_000F9BF0);

#ifndef NULL
#define NULL ((void *)0)
#endif

void consPrintf(const char *fmt, ...);
void copInit(void) {
    consPrintf(&D_000F9BF0, "copInit");
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void copTerm(void) {
    consPrintf(&D_000F9BF0, "copTerm");
}

void copSetSeed(unsigned long long s)
{
	*(unsigned long long *)&Seed = s;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void copSetSeedHL(int arg0, int arg1) {
    M2C_FIELD(&Seed, int *, 0) = arg0;
    M2C_FIELD(&Seed, int *, 4) = arg1;
}

unsigned long long copGetSeed(void)
{
	return *(unsigned long long *)&Seed;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void copGetSeedHL(int *arg0, int *arg1) {
    *arg0 = M2C_FIELD(&Seed, int *, 0);
    *arg1 = M2C_FIELD(&Seed, int *, 4);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRand);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRandS);

extern const float D_000F9C04;
typedef struct { float f[8]; int i; unsigned int b : 12; unsigned int r : 20; } CopAttr;
void copInitAttr(CopAttr *a)
{
	a->f[0] = D_000F9C04;
	a->f[1] = D_000F9C04;
	a->f[2] = D_000F9C04;
	a->f[3] = D_000F9C04;
	a->f[4] = D_000F9C04;
	a->f[5] = D_000F9C04;
	a->f[6] = D_000F9C04;
	a->f[7] = D_000F9C04;
	a->i = 0;
	a->b = 0;
}

const float D_000F9C04 = 1.0f;

extern const float D_000F9C08;

float copCosSin(float *cs, float ang)
{
	union { int i; float f; } r;
	ang *= D_000F9C08;
	__asm__ volatile(
		".set noreorder\n"
		"mtv %1,S000.s\n"
		"vsin.s S010.s,S000.s\n"
		"vcos.s S011.s,S000.s\n"
		"vdot.p S000.s,C010.p,C010.p\n"
		"vrsq.s S000.s,S000.s\n"
		"vcmp.s ES,S000.s,S000.s\n"
		"bvf 0,1f\n"
		"nop\n"
		"vzero.s S000.s\n"
		"1:\n"
		"vscl.p C010.p,C010.p,S000.s\n"
		"mfv %0,S010.s\n"
		"beqz %2,2f\n"
		"nop\n"
		"lv.q C000.q,0(%2)\n"
		"vmov.p C012.p,C002.p\n"
		"sv.q C010.q,0(%2)\n"
		"2:\n"
		".set reorder\n"
		: "=r"(r.i) : "r"(ang), "r"(cs) : "memory");
	return r.f;
}

const float D_000F9C08 = 0.63661975f;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAtan);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAcos);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAsin);

void copUnitMat()
{
	__asm__ volatile(
		"vmidt.q M000.q\n"
		"sv.q C000.q,0($4)\n"
		"sv.q C010.q,16($4)\n"
		"sv.q C020.q,32($4)\n"
		"sv.q C030.q,48($4)\n"
		: : : "memory");
}

void copLetMat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C030.q,48($4)\n"
		"sv.q C000.q,0($5)\n"
		"sv.q C010.q,16($5)\n"
		"sv.q C020.q,32($5)\n"
		"sv.q C030.q,48($5)\n"
		: : : "memory");
}

void copLetMat3()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"sv.q C000.q,0($5)\n"
		"sv.q C010.q,16($5)\n"
		"sv.q C020.q,32($5)\n"
		: : : "memory");
}

void copRevMat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C030.q,48($4)\n"
		"sv.q R000.q,0($5)\n"
		"sv.q R001.q,16($5)\n"
		"sv.q R002.q,32($5)\n"
		"sv.q R003.q,48($5)\n"
		: : : "memory");
}

void copRevMat3()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C100.q,48($4)\n"
		"vzero.t C030.t\n"
		"sv.q R000.q,0($5)\n"
		"sv.q R001.q,16($5)\n"
		"sv.q R002.q,32($5)\n"
		"sv.q C100.q,48($5)\n"
		: : : "memory");
}

void copSclMat()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C030.q,48($4)\n"
		"vscl.q C000.q,C000.q,S100.s\n"
		"vscl.q C010.q,C010.q,S101.s\n"
		"vscl.q C020.q,C020.q,S102.s\n"
		"vscl.q C030.q,C030.q,S103.s\n"
		"sv.q C000.q,0($6)\n"
		"sv.q C010.q,16($6)\n"
		"sv.q C020.q,32($6)\n"
		"sv.q C030.q,48($6)\n"
		: : : "memory");
}

void copSclMat3()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C030.q,48($4)\n"
		"vscl.t C000.t,C000.t,S100.s\n"
		"vscl.t C010.t,C010.t,S101.s\n"
		"vscl.t C020.t,C020.t,S102.s\n"
		"sv.q C000.q,0($6)\n"
		"sv.q C010.q,16($6)\n"
		"sv.q C020.q,32($6)\n"
		"sv.q C030.q,48($6)\n"
		: : : "memory");
}

void copSclMatH()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C030.q,48($4)\n"
		"vmul.q C000.q,C000.q,C100.q\n"
		"vmul.q C010.q,C010.q,C100.q\n"
		"vmul.q C020.q,C020.q,C100.q\n"
		"vmul.q C030.q,C030.q,C100.q\n"
		"sv.q C000.q,0($6)\n"
		"sv.q C010.q,16($6)\n"
		"sv.q C020.q,32($6)\n"
		"sv.q C030.q,48($6)\n"
		: : : "memory");
}

void copSclMatH3()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C030.q,48($4)\n"
		"vmul.t C000.t,C000.t,C100.t\n"
		"vmul.t C010.t,C010.t,C100.t\n"
		"vmul.t C020.t,C020.t,C100.t\n"
		"sv.q C000.q,0($6)\n"
		"sv.q C010.q,16($6)\n"
		"sv.q C020.q,32($6)\n"
		"sv.q C030.q,48($6)\n"
		: : : "memory");
}

void copMulMat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C030.q,48($4)\n"
		"lv.q C100.q,0($5)\n"
		"lv.q C110.q,16($5)\n"
		"lv.q C120.q,32($5)\n"
		"lv.q C130.q,48($5)\n"
		"vmmul.q M200.q,M000.q,M100.q\n"
		"sv.q C200.q,0($6)\n"
		"sv.q C210.q,16($6)\n"
		"sv.q C220.q,32($6)\n"
		"sv.q C230.q,48($6)\n"
		: : : "memory");
}

void copMulMat3()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C030.q,48($4)\n"
		"lv.q C100.q,0($5)\n"
		"lv.q C110.q,16($5)\n"
		"lv.q C120.q,32($5)\n"
		"vmmul.t M200.t,M000.t,M100.t\n"
		"vmov.t R203.t,R103.t\n"
		"sv.q C200.q,0($6)\n"
		"sv.q C210.q,16($6)\n"
		"sv.q C220.q,32($6)\n"
		"sv.q C030.q,48($6)\n"
		: : : "memory");
}

void copNomMat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C030.q,48($4)\n"
		"vdot.t S100.s,C020.t,C020.t\n"
		"vrsq.s S100.s,S100.s\n"
		"vcmp.s ES,S100.s,S100.s\n"
		".set noreorder\n"
		"bvf 0,1f\n"
		"nop\n"
		".set reorder\n"
		"vzero.s S100.s\n"
		"1:\n"
		"vscl.t C020.t,C020.t,S100.s\n"
		"vcrsp.t C000.t,C010.t,C020.t\n"
		"vdot.t S100.s,C000.t,C000.t\n"
		"vrsq.s S100.s,S100.s\n"
		"vcmp.s ES,S100.s,S100.s\n"
		".set noreorder\n"
		"bvf 0,2f\n"
		"nop\n"
		".set reorder\n"
		"vzero.s S100.s\n"
		"2:\n"
		"vscl.t C000.t,C000.t,S100.s\n"
		"vcrsp.t C010.t,C020.t,C000.t\n"
		"vzero.t R003.t\n"
		"sv.q C000.q,0($5)\n"
		"sv.q C010.q,16($5)\n"
		"sv.q C020.q,32($5)\n"
		"sv.q C030.q,48($5)\n"
		: : : "memory");
}

void copNomMatY()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C030.q,48($4)\n"
		"vdot.t S100.s,C010.t,C010.t\n"
		"vrsq.s S100.s,S100.s\n"
		"vcmp.s ES,S100.s,S100.s\n"
		".set noreorder\n"
		"bvf 0,1f\n"
		"nop\n"
		".set reorder\n"
		"vzero.s S100.s\n"
		"1:\n"
		"vscl.t C010.t,C010.t,S100.s\n"
		"vcrsp.t C000.t,C010.t,C020.t\n"
		"vdot.t S100.s,C000.t,C000.t\n"
		"vrsq.s S100.s,S100.s\n"
		"vcmp.s ES,S100.s,S100.s\n"
		".set noreorder\n"
		"bvf 0,2f\n"
		"nop\n"
		".set reorder\n"
		"vzero.s S100.s\n"
		"2:\n"
		"vscl.t C000.t,C000.t,S100.s\n"
		"vcrsp.t C020.t,C000.t,C010.t\n"
		"vzero.t R003.t\n"
		"sv.q C000.q,0($5)\n"
		"sv.q C010.q,16($5)\n"
		"sv.q C020.q,32($5)\n"
		"sv.q C030.q,48($5)\n"
		: : : "memory");
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRotMat);

float copCosSin(float *cs, float ang);
void copRotMatX(float *m, float ang)
{
	float cs[4];
	copCosSin(cs, ang);
	__asm__ volatile(
		"vmidt.q M000.q\n"
		"sv.q C000.q,0(%0)\n"
		"sv.q C010.q,16(%0)\n"
		"sv.q C020.q,32(%0)\n"
		"sv.q C030.q,48(%0)\n"
		: : "r"(m) : "memory");
	m[5] = cs[1];
	m[6] = cs[0];
	m[9] = -cs[0];
	m[10] = cs[1];
}

float copCosSin(float *cs, float ang);
void copRotMatY(float *m, float ang)
{
	float cs[4];
	copCosSin(cs, ang);
	__asm__ volatile(
		"vmidt.q M000.q\n"
		"sv.q C000.q,0(%0)\n"
		"sv.q C010.q,16(%0)\n"
		"sv.q C020.q,32(%0)\n"
		"sv.q C030.q,48(%0)\n"
		: : "r"(m) : "memory");
	m[0] = cs[1];
	m[2] = -cs[0];
	m[8] = cs[0];
	m[10] = cs[1];
}

float copCosSin(float *cs, float ang);
void copRotMatZ(float *m, float ang)
{
	float cs[4];
	copCosSin(cs, ang);
	__asm__ volatile(
		"vmidt.q M000.q\n"
		"sv.q C000.q,0(%0)\n"
		"sv.q C010.q,16(%0)\n"
		"sv.q C020.q,32(%0)\n"
		"sv.q C030.q,48(%0)\n"
		: : "r"(m) : "memory");
	m[0] = cs[1];
	m[1] = cs[0];
	m[4] = -cs[0];
	m[5] = cs[1];
}

void copRotMat(float *ang, float *x, float *y, float *z);
void copAngMatXYZ(float *ang, float *m)
{
	float x[16], y[16], z[16];
	copRotMat(ang, x, y, z);
	copMulMat3(z, y, m);
	copMulMat3(m, x, m);
}

void copRotMat(float *ang, float *x, float *y, float *z);
void copAngMatXZY(float *ang, float *m)
{
	float x[16], y[16], z[16];
	copRotMat(ang, x, y, z);
	copMulMat3(y, z, m);
	copMulMat3(m, x, m);
}

void copRotMat(float *ang, float *x, float *y, float *z);
void copAngMatYXZ(float *ang, float *m)
{
	float x[16], y[16], z[16];
	copRotMat(ang, x, y, z);
	copMulMat3(z, x, m);
	copMulMat3(m, y, m);
}

void copRotMat(float *ang, float *x, float *y, float *z);
void copAngMatYZX(float *ang, float *m)
{
	float x[16], y[16], z[16];
	copRotMat(ang, x, y, z);
	copMulMat3(x, z, m);
	copMulMat3(m, y, m);
}

void copRotMat(float *ang, float *x, float *y, float *z);
void copAngMatZXY(float *ang, float *m)
{
	float x[16], y[16], z[16];
	copRotMat(ang, x, y, z);
	copMulMat3(y, x, m);
	copMulMat3(m, z, m);
}

void copRotMat(float *ang, float *x, float *y, float *z);
void copAngMatZYX(float *ang, float *m)
{
	float x[16], y[16], z[16];
	copRotMat(ang, x, y, z);
	copMulMat3(x, y, m);
	copMulMat3(m, z, m);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copInterMat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copInterMatAng);

void copLetVec()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.s S003.s,12($5)\n"
		"sv.q C000.q,0($5)\n"
		: : : "memory");
}

void copVecF0()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.s S003.s,12($5)\n"
		"vi2f.t C000.t,C000.t,0\n"
		"sv.q C000.q,0($5)\n"
		: : : "memory");
}

void copVecF4()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.s S003.s,12($5)\n"
		"vi2f.t C000.t,C000.t,4\n"
		"sv.q C000.q,0($5)\n"
		: : : "memory");
}

void copVecI0()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.s S003.s,12($5)\n"
		"vf2iz.t C000.t,C000.t,0\n"
		"sv.q C000.q,0($5)\n"
		: : : "memory");
}

void copVecI4()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.s S003.s,12($5)\n"
		"vf2iz.t C000.t,C000.t,4\n"
		"sv.q C000.q,0($5)\n"
		: : : "memory");
}

void copMinVec()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"lv.s S023.s,12($6)\n"
		"vmin.t C020.t,C000.t,C010.t\n"
		"sv.q C020.q,0($6)\n"
		: : : "memory");
}

void copMaxVec()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"lv.s S023.s,12($6)\n"
		"vmax.t C020.t,C000.t,C010.t\n"
		"sv.q C020.q,0($6)\n"
		: : : "memory");
}

void copAddVec()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"lv.s S023.s,12($6)\n"
		"vadd.t C020.t,C000.t,C010.t\n"
		"sv.q C020.q,0($6)\n"
		: : : "memory");
}

void copSubVec()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"lv.s S023.s,12($6)\n"
		"vsub.t C020.t,C000.t,C010.t\n"
		"sv.q C020.q,0($6)\n"
		: : : "memory");
}

void copMltVec()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"lv.s S023.s,12($6)\n"
		"vmul.t C020.t,C000.t,C010.t\n"
		"sv.q C020.q,0($6)\n"
		: : : "memory");
}

void copLenVec()
{
	__asm__ volatile(
		".set noreorder\n"
		"lv.q C000.q,0($4)\n"
		"vdot.t S010.s,C000.t,C000.t\n"
		"vsqrt.s S010.s,S010.s\n"
		"vcmp.s EN,S010.s,S010.s\n"
		"bvf 0,1f\n"
		"nop\n"
		"vzero.s S010.s\n"
		"1:\n"
		"mfv $2,S010.s\n"
		"mtc1 $2,$f0\n"
		".set reorder\n"
		: : : "memory");
}

void copNomVec()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.s S023.s,12($5)\n"
		"vdot.t S030.s,C000.t,C000.t\n"
		"vrsq.s S030.s,S030.s\n"
		"vcmp.s ES,S030.s,S030.s\n"
		".set noreorder\n"
		"bvf 0,1f\n"
		"nop\n"
		".set reorder\n"
		"vzero.s S030.s\n"
		"1:\n"
		"vscl.t C020.t,C000.t,S030.s\n"
		"sv.q C020.q,0($5)\n"
		: : : "memory");
}

void copStrVec()
{
	__asm__ volatile(
		"mfc1 $2,$f12\n"
		"lv.q C000.q,0($4)\n"
		"mtv $2,S010.s\n"
		"lv.s S023.s,12($5)\n"
		"vdot.t S030.s,C000.t,C000.t\n"
		"vrsq.s S030.s,S030.s\n"
		"vcmp.s ES,S030.s,S030.s\n"
		".set noreorder\n"
		"bvf 0,1f\n"
		"nop\n"
		".set reorder\n"
		"vzero.s S030.s\n"
		"1:\n"
		"vmul.s S030.s,S030.s,S010.s\n"
		"vscl.t C020.t,C000.t,S030.s\n"
		"sv.q C020.q,0($5)\n"
		: : : "memory");
}

void copSclVec()
{
	__asm__ volatile(
		"mfc1 $2,$f12\n"
		"lv.q C000.q,0($4)\n"
		"mtv $2,S010.s\n"
		"lv.s S023.s,12($5)\n"
		"vscl.t C020.t,C000.t,S010.s\n"
		"sv.q C020.q,0($5)\n"
		: : : "memory");
}

void copIntVec()
{
	__asm__ volatile(
		"mfc1 $2,$f12\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"mtv $2,S020.s\n"
		"lv.s S033.s,12($6)\n"
		"vsub.t C010.t,C010.t,C000.t\n"
		"vscl.t C010.t,C010.t,S020.s\n"
		"vadd.t C030.t,C000.t,C010.t\n"
		"sv.q C030.q,0($6)\n"
		: : : "memory");
}

void copDotVec()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"vdot.t S020.s,C000.t,C010.t\n"
		"mfv $2,S020.s\n"
		"mtc1 $2,$f0\n"
		: : : "memory");
}

void copOutVec()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"lv.s S023.s,12($6)\n"
		"vcrsp.t C020.t,C000.t,C010.t\n"
		"sv.q C020.q,0($6)\n"
		: : : "memory");
}

void copDistVec()
{
	__asm__ volatile(
		".set noreorder\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"vsub.t C000.t,C010.t,C000.t\n"
		"vdot.t S010.s,C000.t,C000.t\n"
		"vsqrt.s S010.s,S010.s\n"
		"vcmp.s EN,S010.s,S010.s\n"
		"bvf 0,1f\n"
		"nop\n"
		"vzero.s S010.s\n"
		"1:\n"
		"mfv $2,S010.s\n"
		"mtc1 $2,$f0\n"
		".set reorder\n"
		: : : "memory");
}

void copRotVec()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.s S113.s,12($6)\n"
		"vtfm3.t C110.t,E000.t,C100.t\n"
		"sv.q C110.q,0($6)\n"
		: : : "memory");
}

void copRotTraVec()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C030.q,48($4)\n"
		"vtfm3.t C110.t,E000.t,C100.t\n"
		"vadd.t C110.t,C030.t,C110.t\n"
		"lv.s S113.s,12($6)\n"
		"sv.q C110.q,0($6)\n"
		: : : "memory");
}

void copPersVec()
{
	__asm__ volatile(
		"lv.q C100.q,0($5)\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C030.q,48($4)\n"
		"vtfm4.q C110.q,E000.q,C100.q\n"
		"vone.s S000.s\n"
		"vdiv.s S113.s,S000.s,S113.s\n"
		"vscl.t C120.t,C110.t,S113.s\n"
		"lv.s S123.s,12($6)\n"
		"sv.q C120.q,0($6)\n"
		"mfv $2,S113.s\n"
		"mtc1 $2,$f0\n"
		: : : "memory");
}

void copUnitQuat()
{
	__asm__ volatile(
		"vzero.t C000.t\n"
		"vone.s S003.s\n"
		"sv.q C000.q,0($4)\n"
		: : : "memory");
}

void copLetQuat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"sv.q C000.q,0($5)\n"
		: : : "memory");
}

void copMinQuat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"vmin.q C020.q,C000.q,C010.q\n"
		"sv.q C020.q,0($6)\n"
		: : : "memory");
}

void copMaxQuat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"vmax.q C020.q,C000.q,C010.q\n"
		"sv.q C020.q,0($6)\n"
		: : : "memory");
}

void copAddQuat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"vadd.q C020.q,C000.q,C010.q\n"
		"sv.q C020.q,0($6)\n"
		: : : "memory");
}

void copSubQuat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"vsub.q C020.q,C000.q,C010.q\n"
		"sv.q C020.q,0($6)\n"
		: : : "memory");
}

void copMltQuat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"vmul.q C020.q,C000.q,C010.q\n"
		"sv.q C020.q,0($6)\n"
		: : : "memory");
}

void copNomQuat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"vdot.q S030.s,C000.q,C000.q\n"
		"vrsq.s S030.s,S030.s\n"
		"vcmp.s ES,S030.s,S030.s\n"
		".set noreorder\n"
		"bvf 0,1f\n"
		"nop\n"
		".set reorder\n"
		"vzero.s S030.s\n"
		"1:\n"
		"vscl.q C020.q,C000.q,S030.s\n"
		"sv.q C020.q,0($5)\n"
		: : : "memory");
}

void copIntQuat()
{
	__asm__ volatile(
		"mfc1 $2,$f12\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"mtv $2,S020.s\n"
		"vsub.q C010.q,C010.q,C000.q\n"
		"vscl.q C010.q,C010.q,S020.s\n"
		"vadd.q C030.q,C000.q,C010.q\n"
		"sv.q C030.q,0($6)\n"
		: : : "memory");
}

void copSclQuat()
{
	__asm__ volatile(
		"mfc1 $2,$f12\n"
		"lv.q C000.q,0($4)\n"
		"mtv $2,S010.s\n"
		"vscl.q C020.q,C000.q,S010.s\n"
		"sv.q C020.q,0($5)\n"
		: : : "memory");
}

void copDotQuat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"vdot.q S020.s,C000.q,C010.q\n"
		"mfv $2,S020.s\n"
		"mtc1 $2,$f0\n"
		: : : "memory");
}

void copMulQuat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"vqmul.q C020.q,C010.q,C000.q\n"
		"vdot.q S030.s,C020.q,C020.q\n"
		"vrsq.s S030.s,S030.s\n"
		"vcmp.s ES,S030.s,S030.s\n"
		".set noreorder\n"
		"bvf 0,1f\n"
		"nop\n"
		".set reorder\n"
		"vzero.s S030.s\n"
		"1:\n"
		"vscl.q C020.q,C020.q,S030.s\n"
		"sv.q C020.q,0($6)\n"
		: : : "memory");
}

void copQuatMat()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.s S303.s,12($5)\n"
		"lv.s S313.s,28($5)\n"
		"lv.s S323.s,44($5)\n"
		"vone.s S013.s\n"
		"vadd.t C010.t,C000.t,C000.t\n"
		"vscl.q C100.q,C000.q,S010.s\n"
		"vscl.q C110.q,C000.q,S011.s\n"
		"vscl.q C120.q,C000.q,S012.s\n"
		"vadd.s S130.s,S100.s,S111.s\n"
		"vadd.s S131.s,S111.s,S122.s\n"
		"vadd.s S132.s,S122.s,S100.s\n"
		"vsub.s S300.s,S013.s,S131.s\n"
		"vsub.s S301.s,S110.s,S123.s\n"
		"vadd.s S302.s,S120.s,S113.s\n"
		"vadd.s S310.s,S110.s,S123.s\n"
		"vsub.s S311.s,S013.s,S132.s\n"
		"vsub.s S312.s,S121.s,S103.s\n"
		"vsub.s S320.s,S120.s,S113.s\n"
		"vadd.s S321.s,S121.s,S103.s\n"
		"vsub.s S322.s,S013.s,S130.s\n"
		"sv.q C300.q,0($5)\n"
		"sv.q C310.q,16($5)\n"
		"sv.q C320.q,32($5)\n"
		: : : "memory");
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copMatQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copInterQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copInterQuatAng);

int copTargetPos(void *m, void *p, void *q, void *out)
{
	register unsigned int a __asm__("$2");
	register unsigned int b __asm__("$3");
	register unsigned int c __asm__("$4");
	__asm__ volatile(
		".set noreorder\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,16($4)\n"
		"lv.q C020.q,32($4)\n"
		"lv.q C100.q,0($5)\n"
		"lv.q C110.q,0($6)\n"
		"vsub.t C120.t,C110.t,C100.t\n"
		"vdot.t S130.s,C120.t,C120.t\n"
		"vrsq.s S131.s,S130.s\n"
		"vcmp.s ES,S131.s,S131.s\n"
		"bvf 0,1f\n"
		"nop\n"
		"vzero.s S131.s\n"
		"1:\n"
		"vscl.t C120.t,C120.t,S131.s\n"
		"vdot.t S200.s,C000.t,C120.t\n"
		"vdot.t S201.s,C010.t,C120.t\n"
		"vdot.t S202.s,C020.t,C120.t\n"
		"vsqrt.s S203.s,S130.s\n"
		"vcmp.s EN,S203.s,S203.s\n"
		"bvf 0,2f\n"
		"nop\n"
		"vzero.s S203.s\n"
		"2:\n"
		"beqz $7,3f\n"
		"nop\n"
		"sv.q C200.q,0($7)\n"
		"3:\n"
		"mfv $2,S200.s\n"
		"mfv $3,S201.s\n"
		"mfv $4,S202.s\n"
		".set reorder\n"
		: "=r"(a), "=r"(b), "=r"(c) : : "memory");
	return (a >> 31) | ((b >> 30) & 2) | ((c >> 29) & 4);
}

void copLinePos()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"vsub.t C110.t,C010.t,C000.t\n"
		"vsub.t C120.t,C020.t,C000.t\n"
		"vcrsp.t C130.t,C110.t,C120.t\n"
		"mfv $2,S131.s\n"
		"mtc1 $2,$f0\n"
		: : : "memory");
}

void copGrdVec()
{
	__asm__ volatile(
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"lv.q C030.q,0($7)\n"
		"vsub.t C110.t,C010.t,C000.t\n"
		"vsub.t C120.t,C020.t,C000.t\n"
		"vcrsp.t C100.t,C110.t,C120.t\n"
		"vsub.t C130.t,C030.t,C000.t\n"
		"vmul.t C200.t,C100.t,C130.t\n"
		"vadd.s S210.s,S200.s,S202.s\n"
		"vdiv.s S211.s,S210.s,S101.s\n"
		"vsub.s S212.s,S211.s,S001.s\n"
		"vneg.s S212.s,S212.s\n"
		"mfv $2,S212.s\n"
		"mtc1 $2,$f0\n"
		: : : "memory");
}

void copCrossChk()
{
	__asm__ volatile(
		".set noreorder\n"
		"lv.q C000.q,0($4)\n"
		"lv.q C010.q,0($5)\n"
		"lv.q C020.q,0($6)\n"
		"lv.q C100.q,0($7)\n"
		"lv.q C110.q,0($8)\n"
		"move $2,$0\n"
		"vmin.t C200.t,C000.t,C010.t\n"
		"vmin.t C200.t,C200.t,C020.t\n"
		"vmin.t C210.t,C100.t,C110.t\n"
		"vmax.t C220.t,C000.t,C010.t\n"
		"vmax.t C220.t,C220.t,C020.t\n"
		"vmax.t C230.t,C100.t,C110.t\n"
		"vcmp.t GT,C200.t,C230.t\n"
		"bvt 4,2f\n"
		"nop\n"
		"vcmp.t GT,C210.t,C220.t\n"
		"bvt 4,2f\n"
		"nop\n"
		"vsub.t C200.t,C010.t,C000.t\n"
		"vsub.t C210.t,C020.t,C000.t\n"
		"vsub.t C220.t,C100.t,C000.t\n"
		"vsub.t C230.t,C110.t,C000.t\n"
		"vcrsp.t C030.t,C200.t,C210.t\n"
		"vdot.t S120.s,C030.t,C220.t\n"
		"vdot.t S121.s,C030.t,C230.t\n"
		"vpfxt 0,0,0,0\n"
		"vcmp.p GE,C120.p,C000.p\n"
		"bvt 5,2f\n"
		"nop\n"
		"vpfxt 0,0,0,0\n"
		"vcmp.p LE,C120.p,C000.p\n"
		"bvt 5,2f\n"
		"nop\n"
		"vsub.t C300.t,C000.t,C100.t\n"
		"vsub.t C310.t,C010.t,C100.t\n"
		"vsub.t C320.t,C020.t,C100.t\n"
		"vsub.t C330.t,C110.t,C100.t\n"
		"vcrsp.t C400.t,C300.t,C310.t\n"
		"vcrsp.t C410.t,C310.t,C320.t\n"
		"vcrsp.t C420.t,C320.t,C300.t\n"
		"vdot.t S430.s,C400.t,C330.t\n"
		"vdot.t S431.s,C410.t,C330.t\n"
		"vdot.t S432.s,C420.t,C330.t\n"
		"vpfxt 0,0,0,0\n"
		"vcmp.t GE,C430.t,C000.t\n"
		"bvt 5,1f\n"
		"nop\n"
		"vpfxt 0,0,0,0\n"
		"vcmp.t LE,C430.t,C000.t\n"
		"bvf 5,2f\n"
		"nop\n"
		"1:\n"
		"vsub.s S122.s,S120.s,S121.s\n"
		"vdiv.s S123.s,S120.s,S122.s\n"
		"vscl.t C500.t,C330.t,S123.s\n"
		"vadd.t C510.t,C100.t,C500.t\n"
		"sv.q C510.q,0($9)\n"
		"move $2,$9\n"
		"2:\n"
		".set reorder\n"
		: : : "memory");
}
