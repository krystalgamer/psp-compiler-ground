/* cflags: -Os */
#include "common.h"

void xuInit(void) {
}

void xuTerm(void) {
}

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

void *xuFinish(void *pkt)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = 0x0F000000;
	pCmd.ip++;
	return pCmd.vp;
}

void *xuSignal(void *pkt)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = 0x0E000000;
	pCmd.ip++;
	return pCmd.vp;
}

void *xuCallList(void *pkt, const void *p)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC2(0x10000000, (unsigned int)p >> 24);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0x0A000000, (int)p);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuJumpList(void *pkt, const void *p)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC2(0x10000000, (unsigned int)p >> 24);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0x08000000, (int)p);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuReturn(void *pkt)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = 0x0B000000;
	pCmd.ip++;
	return pCmd.vp;
}

void *xuNop(void *pkt)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = 0;
	pCmd.ip++;
	return pCmd.vp;
}
