/* cflags: -Os */
#include "common.h"

typedef union { void *vp; int *ip; } xuPtr;
static inline int xuSetD0(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 0, 24" : "+r"(rt) : "r"(rs));
	return rt;
}
static inline int xuSetS0(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 0, 16" : "+r"(rt) : "r"(rs));
	return rt;
}
static inline int xuSetC0(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 0, 8" : "+r"(rt) : "r"(rs));
	return rt;
}
static inline int xuSetC1(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 8, 8" : "+r"(rt) : "r"(rs));
	return rt;
}
static inline int xuSetC2(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 16, 8" : "+r"(rt) : "r"(rs));
	return rt;
}
static inline int xuSetF0(int rt, int rs)
{
	__asm__ __volatile__ ("srl %1, %1, 8\n\tins %0, %1, 0, 24" : "+r"(rt), "+r"(rs));
	return rt;
}
static inline int f2i(float rs)
{
	union { float f; int i; } u;
	u.f = rs;
	return u.i;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_SetBuffer", xuViewport);

void *xuDrawBuffer(void *pkt, int fpf, void *fbp, int fbw)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0x9C000000, (int)fbp);
	pCmd.ip++;
	*pCmd.ip = xuSetC2(xuSetS0(0x9D000000, fbw), (unsigned int)fbp >> 24);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0xD2000000, fpf);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuDepthBuffer(void *pkt, void *zbp, int zbw)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0x9E000000, (int)zbp);
	pCmd.ip++;
	*pCmd.ip = xuSetC2(xuSetS0(0x9F000000, zbw), (unsigned int)zbp >> 24);
	pCmd.ip++;
	return pCmd.vp;
}
