/* cflags: -Os -fno-strength-reduce */
#include "common.h"

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/ptx", D_000FB948);

typedef struct { void *data; unsigned int size; int _8, _c; } PtxEnt;
typedef struct {
	char ID[4];
	unsigned short _4;
	unsigned char nTex, nClut;
	unsigned char texFmt, clutFmt;
	unsigned short _a;
	int _c;
	PtxEnt *tex;
	PtxEnt *clut;
} Ptx;
typedef struct { unsigned char t[32]; } PtxSwz;
typedef struct { unsigned int w[32]; } PtxBlk;
extern const PtxSwz D_000FB948;
int memcmp(const void *, const void *, unsigned int);
void consPrintf(const char *, ...);
int ptxInit(Ptx *pPtx)
{
	int tf, cf;
	PtxSwz swz;
	unsigned int buf[32];

	if (!(pPtx))
		consPrintf("cassert : %s %d : %s : %s\n", "src/fw/ptx.c", 0x16, "ptxInit", "pPtx");
	if (!(memcmp("Ptex", pPtx->ID, sizeof(pPtx->ID)) == 0))
		consPrintf("cassert : %s %d : %s : %s\n", "src/fw/ptx.c", 0x17, "ptxInit", "memcmp(\"Ptex\", pPtx->ID, sizeof(pPtx->ID)) == 0");
	if (pPtx->tex)
		pPtx->tex = (PtxEnt *)((char *)pPtx->tex + (int)pPtx);
	if (pPtx->clut)
		pPtx->clut = (PtxEnt *)((char *)pPtx->clut + (int)pPtx);
	{
		PtxEnt *t = pPtx->tex;
		PtxEnt *c = pPtx->clut;
		int n;
		if (t)
			for (n = pPtx->nTex; n; n--, t++)
				t->data = (char *)t->data + (int)pPtx;
		if (c)
			for (n = pPtx->nClut; n; n--, c++)
				c->data = (char *)c->data + (int)pPtx;
	}
	tf = 3;
	cf = 3;
	switch (pPtx->texFmt) {
	case 0x20:
		tf = 3;
		break;
	case 0x10:
		tf = 1;
		break;
	default:
		consPrintf("cassert : %s %d : %s : %s\n", "src/fw/ptx.c", 0x2D, "ptxInit", "FALSE");
		break;
	}
	switch (pPtx->clutFmt) {
	case 0x20:
		cf = 3;
		break;
	case 0x10:
		cf = 1;
		break;
	case 8:
		cf = 5;
		break;
	case 4:
		cf = 4;
		break;
	default:
		consPrintf("cassert : %s %d : %s : %s\n", "src/fw/ptx.c", 0x35, "ptxInit", "FALSE");
		break;
	}
	pPtx->clutFmt = cf;
	pPtx->texFmt = tf;
	{
		PtxEnt *t, *c;
		unsigned int w;
		unsigned char *p;
		t = pPtx->tex;
		c = pPtx->clut;
		if (t && pPtx->texFmt == 3) {
			int n;
			for (n = pPtx->nTex; n; n--, t++) {
				p = t->data;
				for (w = t->size >> 2; w; w--, p += 4) {
					unsigned char a = p[3];
					p[3] = a != 0 ? a * 2 - 1 : a;
				}
			}
		}
		if (c && pPtx->clutFmt == 3) {
			int n;
			for (n = pPtx->nClut; n; n--, c++) {
				p = c->data;
				for (w = t->size >> 2; w; w--, p += 4) {
					unsigned char a = p[3];
					p[3] = a != 0 ? a * 2 - 1 : a;
				}
			}
		}
	}
	swz = D_000FB948;
	{
		PtxEnt *t = pPtx->tex;
		int n;
		unsigned int w;
		if (t && pPtx->texFmt == 3) {
			int n;
			for (n = pPtx->nTex; n; n--, t++) {
				unsigned int *p = t->data;
				for (w = t->size >> 2; w; w -= 32, p += 32) {
					unsigned int i;
					for (i = 0; i < 32; i++)
						buf[i] = p[swz.t[i]];
					*(PtxBlk *)p = *(PtxBlk *)buf;
				}
			}
		}
	}
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/ptx", D_000FB9E4);
