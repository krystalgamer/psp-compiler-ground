/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);

extern unsigned char D_000FABEC, D_000FAC08, D_000FAC3C;
int elmTerm();
typedef struct { int Ofs; int Num; short Elm[1]; } ElmCntx;
typedef struct { void *Ptr; unsigned short Id; } HdlEnt;
typedef struct { ElmCntx *pElm; int pad; HdlEnt Ent[1]; } HdlCntx;
short elmCall(void *pCntx);
int elmFree(void *pCntx, short Elm);
extern unsigned char D_000FAC88;
int _memFree();

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", D_000FABEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", D_000FAC08);

void *_memAlloc(int size, const char *file, int line);
void *memset(void *, int, unsigned int);
int elmInit(int Num);
extern unsigned char D_000FAC44, D_000FAC5C;
int *hdlInit(int Num)
{
	int *pCntx;
	int size;
	int e;

	if (Num <= 0)
		consPrintf(&D_000FABEC, &D_000FAC08, 0x24, "hdlInit", "Num >= 1");
	if (Num > 0x8000)
		consPrintf(&D_000FABEC, &D_000FAC08, 0x25, "hdlInit", "Num <= 0x8000");
	size = Num * 8 + 8;
	pCntx = _memAlloc(size, &D_000FAC08, 0x29);
	if (pCntx == NULL)
		consPrintf(&D_000FABEC, &D_000FAC08, 0x2A, "hdlInit", &D_000FAC3C);
	consPrintf(&D_000FAC44, "hdlInit", pCntx, size);
	if (pCntx != NULL) {
		memset(pCntx, 0, size);
		e = elmInit(Num);
		if (e == 0)
			consPrintf(&D_000FABEC, &D_000FAC08, 0x33, "hdlInit", &D_000FAC5C);
		*pCntx = e;
	}
	return pCntx;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", D_000FAC3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", D_000FAC44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", D_000FAC5C);

int hdlTerm(int *h)
{
	if (h == NULL) {
		consPrintf(&D_000FABEC, &D_000FAC08, 0x42, "hdlTerm", &D_000FAC3C);
	}
	consPrintf("%s : 0x%08x\n", "hdlTerm", h);
	if (h == NULL) {
		return 0;
	}
	elmTerm(*h);
	_memFree(h, &D_000FAC08, 0x4C);
	return 1;
}

int hdlMake(HdlCntx *pCntx, void *Ptr)
{
	int Num;
	short Elm;
	int ret;
	unsigned short Id;
	HdlEnt *p;

	if (pCntx == NULL)
		consPrintf(&D_000FABEC, &D_000FAC08, 0x5A, "hdlMake", &D_000FAC3C);
	if (Ptr == NULL)
		consPrintf(&D_000FABEC, &D_000FAC08, 0x5B, "hdlMake", "Ptr");
	Num = pCntx->pElm->Num;
	Elm = elmCall(pCntx->pElm);
	if (Elm >= 0 && Elm < Num) {
		HdlEnt *Ent = pCntx->Ent;
		p = Ent;
		p += Elm;
		p->Ptr = Ptr;
		Id = p->Id + 1;
		p->Id = Id;
		ret = (Id | (Elm << 16)) + 0x67890000;
	} else {
		consPrintf(&D_000FABEC, &D_000FAC08, 0x6C, "hdlMake", &D_000FAC88);
		ret = 0;
	}
	return ret;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", D_000FAC88);

int hdlFree(HdlCntx *pCntx, int Hdl)
{
	ElmCntx *pElm;
	HdlEnt *Ent, *p;
	short Elm;
	int Num;
	unsigned short Id;
	int ret;

	if (pCntx == NULL)
		consPrintf(&D_000FABEC, &D_000FAC08, 0x79, "hdlFree", &D_000FAC3C);
	if (Hdl == 0)
		ret = 0;
	else {
		pElm = pCntx->pElm;
		Hdl -= 0x67890000;
		Elm = Hdl >> 16;
		Num = pElm->Num;
		if (Elm >= 0 && Elm < Num) {
			Ent = pCntx->Ent;
			p = Ent;
			p += Elm;
			Id = p->Id;
			if (Id == (Hdl & 0xFFFF)) {
				p->Id = Id + 1;
				elmFree(pElm, Elm);
				ret = 1;
			} else
				ret = 0;
		} else {
			consPrintf(&D_000FABEC, &D_000FAC08, 0x91, "hdlFree", &D_000FAC88);
			ret = 0;
		}
	}
	return ret;
}

void *hdlPtr(HdlCntx *pCntx, int Hdl)
{
	ElmCntx *pElm;
	HdlEnt *Ent, *p;
	short Elm;
	int Num;
	void *ret;

	if (pCntx == NULL)
		consPrintf(&D_000FABEC, &D_000FAC08, 0xA1, "hdlPtr", &D_000FAC3C);
	if (Hdl == 0)
		ret = NULL;
	else {
		pElm = pCntx->pElm;
		Hdl -= 0x67890000;
		Elm = Hdl >> 16;
		Num = pElm->Num;
		if (Elm >= 0 && Elm < Num) {
			Ent = pCntx->Ent;
			p = Ent;
			p += Elm;
			if (p->Id == (Hdl & 0xFFFF))
				ret = p->Ptr;
			else
				ret = NULL;
		} else {
			consPrintf(&D_000FABEC, &D_000FAC08, 0xB4, "hdlPtr", &D_000FAC88);
			ret = NULL;
		}
	}
	return ret;
}
