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

void *xuDrawArray(void *pkt, int prim, int type, int count, const void *index, const void *p)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0x02000000, (int)index);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0x01000000, (int)p);
	pCmd.ip++;
	*pCmd.ip = xuSetC2(0x10000000, (unsigned int)p >> 24);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0x12000000, type);
	pCmd.ip++;
	*pCmd.ip = xuSetC2(xuSetS0(0x04000000, count), prim);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuDrawBezier(void *pkt, int type, int ucount, int vcount, const void *index, const void *p)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0x02000000, (int)index);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0x01000000, (int)p);
	pCmd.ip++;
	*pCmd.ip = xuSetC2(0x10000000, (unsigned int)p >> 24);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0x12000000, type);
	pCmd.ip++;
	*pCmd.ip = xuSetC1(xuSetC0(0x05000000, ucount), vcount);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuDrawSpline(void *pkt, int type, int ucount, int vcount, int uflag, int vflag, const void *index, const void *p)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0x02000000, (int)index);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0x01000000, (int)p);
	pCmd.ip++;
	*pCmd.ip = xuSetC2(0x10000000, (unsigned int)p >> 24);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0x12000000, type);
	pCmd.ip++;
	*pCmd.ip = xuSetC2(xuSetC1(xuSetC0(0x06000000, ucount), vcount), uflag | (vflag << 2));
	pCmd.ip++;
	return pCmd.vp;
}

void *xuPatchDivide(void *pkt, int udiv, int vdiv)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC1(xuSetC0(0x36000000, udiv), vdiv);
	pCmd.ip++;
	return pCmd.vp;
}

extern int D_001147DC[];
void *xuPatchPrim(void *pkt, int prim)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC0(0x37000000, D_001147DC[prim]);
	pCmd.ip++;
	return pCmd.vp;
}
