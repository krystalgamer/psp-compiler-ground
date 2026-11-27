/* cflags: -Os */
#include "common.h"
/* declarations recovered from DWARF */
union _anon1;
union _anon1 { /* size 0x4 */
    void *vp;
    int *ip;
};
typedef union _anon1 xuPtr;
typedef unsigned int u_int;



void *xuTexMode(void *pkt, int tpf, int maxlod, int mc, int hsm);
static int xuSetC2(int rt, int rs);
static int xuSetC1(int rt, int rs);
static int xuSetC0(int rt, int rs);
static int xuSetD0(int rt, int rs);
void *xuTexFilter(void *pkt, int min, int mag);
void *xuTexFunc(void *pkt, int func, int component);
void *xuTexEnvColor(void *pkt, unsigned int col);
void *xuTexWrap(void *pkt, int uwrap, int vwrap);
void *xuTexLevelMode(void *pkt, int calc, float offset);
static int xuSetS0(int rt, int rs);
void *xuTexMapMode(void *pkt, int map, int lu, int lv);
void *xuTexSync(void *pkt);
void *xuTexFlush(void *pkt);
void *xuTexImage(void *pkt, int level, int width, int height, int w, const void *tbp);
static int lzc(u_int rs);
void *xuTexScale(void *pkt, float su, float sv);
static int xuSetF0(int rt, int rs);
static int f2i(float rs);
void *xuTexOffset(void *pkt, float tu, float tv);
void *xuClutMode(void *pkt, int cpf, int shift, int mask, int csa);
void *xuClutLoad(void *pkt, int np, const void *cbp);

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

void *xuTexMode(void *pkt, int tpf, int maxlod, int mc, int hsm)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC2(xuSetC1(xuSetC0(0xC2000000, hsm), mc), maxlod);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0xC3000000, tpf);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuTexFilter(void *pkt, int min, int mag)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC1(xuSetC0(0xC6000000, min), mag);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuTexFunc(void *pkt, int func, int component)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC1(xuSetC0(0xC9000000, func), component);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuTexEnvColor(void *pkt, unsigned int col)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0xCA000000, col);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuTexWrap(void *pkt, int uwrap, int vwrap)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC1(xuSetC0(0xC7000000, uwrap), vwrap);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuTexLevelMode(void *pkt, int calc, float offset)
{
	xuPtr pCmd;
	int ofs = (int)(offset * 16.0f);
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC2(xuSetS0(0xC8000000, calc), ofs);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuTexMapMode(void *pkt, int map, int lu, int lv)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0xC0000000, map);
	pCmd.ip++;
	*pCmd.ip = xuSetC1(xuSetC0(0xC1000000, lu), lv);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuTexSync(void *pkt)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = 0xCC000000;
	pCmd.ip++;
	return pCmd.vp;
}

void *xuTexFlush(void *pkt)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = 0xCB000000;
	pCmd.ip++;
	return pCmd.vp;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_TextureParameter", xuTexImage);

void *xuTexScale(void *pkt, float su, float sv)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetF0(0x48000000, f2i(su));
	pCmd.ip++;
	*pCmd.ip = xuSetF0(0x49000000, f2i(sv));
	pCmd.ip++;
	return pCmd.vp;
}

void *xuTexOffset(void *pkt, float tu, float tv)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetF0(0x4A000000, f2i(tu));
	pCmd.ip++;
	*pCmd.ip = xuSetF0(0x4B000000, f2i(tv));
	pCmd.ip++;
	return pCmd.vp;
}

void *xuClutMode(void *pkt, int cpf, int shift, int mask, int csa)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetC2(xuSetC1(xuSetC0(0xC5000000, cpf | (shift << 2)), mask), csa);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuClutLoad(void *pkt, int np, const void *cbp)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0xB0000000, (int)cbp);
	pCmd.ip++;
	*pCmd.ip = xuSetC2(0xB1000000, (unsigned int)cbp >> 24);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0xC4000000, np);
	pCmd.ip++;
	return pCmd.vp;
}

