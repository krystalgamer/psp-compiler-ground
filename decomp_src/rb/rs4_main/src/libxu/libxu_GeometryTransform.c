/* cflags: -Os */
#include "common.h"
/* declarations recovered from DWARF */
union _anon1;
union _anon1 { /* size 0x4 */
    void *vp;
    int *ip;
};
typedef union _anon1 xuPtr;



void *xuDepthRange(void *pkt, int r_near, int r_far);
static int xuSetD0(int rt, int rs);
static int xuSetF0(int rt, int rs);
static int f2i(float rs);
void *xuOffset(void *pkt, int x, int y);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_GeometryTransform", xuDepthRange);

void *xuOffset(void *pkt, int x, int y)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0x4C000000, x << 4);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0x4D000000, y << 4);
	pCmd.ip++;
	return pCmd.vp;
}

