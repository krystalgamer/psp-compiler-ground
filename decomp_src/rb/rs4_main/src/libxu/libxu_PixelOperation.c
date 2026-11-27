#include "common.h"
/* declarations recovered from DWARF */
union _anon1;
union _anon1 { /* size 0x4 */
    void *vp;
    int *ip;
};
typedef union _anon1 xuPtr;



void *xuColorFunc(void *pkt, int func, unsigned int cref, unsigned int cmsk);
static int xuSetD0(int rt, int rs);
void *xuAlphaFunc(void *pkt, int func, int aref, int amsk);
static int xuSetC2(int rt, int rs);
static int xuSetC1(int rt, int rs);
static int xuSetC0(int rt, int rs);
void *xuDepthFunc(void *pkt, int func);
void *xuDepthMask(void *pkt, int flag);
void *xuScissor(void *pkt, int x, int y, int width, int height);
void *xuStencilFunc(void *pkt, int func, int sref, int smsk);
void *xuStencilOp(void *pkt, int sfail, int zfail, int zpass);
void *xuBlendFunc(void *pkt, int equ, int asel, int bsel, int afix, int bfix);
void *xuLogicalOp(void *pkt, int lop);
void *xuPixelMask(void *pkt, unsigned int pmsk);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_PixelOperation", xuColorFunc);

void *xuAlphaFunc(void *pkt, int func, int aref, int amsk)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC2(xuSetC1(xuSetC0(0xDB000000, func), aref), amsk);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuDepthFunc(void *pkt, int func)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0xDE000000, func);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuDepthMask(void *pkt, int flag)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0xE7000000, flag);
	pCmd.ip++;
	return pCmd.vp;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_PixelOperation", xuScissor);

void *xuStencilFunc(void *pkt, int func, int sref, int smsk)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC2(xuSetC1(xuSetC0(0xDC000000, func), sref), smsk);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuStencilOp(void *pkt, int sfail, int zfail, int zpass)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC2(xuSetC1(xuSetC0(0xDD000000, sfail), zfail), zpass);
	pCmd.ip++;
	return pCmd.vp;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_PixelOperation", xuBlendFunc);

void *xuLogicalOp(void *pkt, int lop)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0xE6000000, lop);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuPixelMask(void *pkt, unsigned int pmsk)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0xE8000000, pmsk);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0xE9000000, pmsk >> 24);
	pCmd.ip++;
	return pCmd.vp;
}

