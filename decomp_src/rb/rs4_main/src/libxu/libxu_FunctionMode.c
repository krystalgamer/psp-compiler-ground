#include "common.h"
extern unsigned int D_001147F8[];
extern unsigned int D_0011484C[];
/* declarations recovered from DWARF */
union _anon1;
union _anon1 { /* size 0x4 */
    void *vp;
    int *ip;
};
typedef union _anon1 xuPtr;



void *xuEnable(void *pkt, int cap);
void *xuDisable(void *pkt, int cap);

/* libxu's xu.h helpers: inline asm ins (two source lines each in the line table) */
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

void *xuEnable(void *pkt, int cap)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = D_001147F8[cap];
	pCmd.ip++;
	return pCmd.vp;
}

void *xuDisable(void *pkt, int cap)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = D_0011484C[cap];
	pCmd.ip++;
	return pCmd.vp;
}

