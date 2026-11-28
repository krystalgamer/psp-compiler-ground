/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void resOvlProcInst();
extern int CurrentInst;
extern unsigned char InstBuf;
void consPrintf(const char *, ...);
extern void *pReadInst;

typedef struct { int *p; int pad[7]; } InstEnt;

typedef void (*OvlFn)(int, int, int);
typedef struct { int a, b; OvlFn *tbl; int pad[5]; } InstEnt2;

int thrEntry();
void _resReadInst();

extern int CurrentInst;
void consPrintf(const char *, ...);
M2C_UNK resReadRefer(int, int, int);                /* extern */
extern unsigned char D_000FB9F8;
extern unsigned char D_000FBA08;
void *resGetDatSect(int, int, int);                 /* extern */
extern unsigned char D_000FBD40;
extern unsigned char D_000FBF14;
extern unsigned char D_000FBF20;
extern unsigned char D_000FBF2C;

extern int pResTerm;

M2C_UNK resReadInst(int);                           /* extern */
M2C_UNK thrChange(void *);
extern unsigned char InstBuf;

extern unsigned char D_000FBF80;

int strcmp(const char *, const char *);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FB9F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBA08);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBA24);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBA2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBA38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBA40);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resTerm);

void *resGetInst(int arg0) {
    return (arg0 << 5) + &InstBuf;
}

int resGetChildEntry(int i)
{
	int *c;
	if (CurrentInst >= i) {
		c = (int *)((InstEnt *)&InstBuf)[i].p[1];
		if (c)
			return c[1];
	}
	return 0;
}

int resChkData(int *d)
{
	unsigned int n = (unsigned int)d[1] >> 2;
	int *p = (int *)d[0];
	int s = 0;
	for (; n; n--) {
		s ^= *p;
		s += *p;
		p++;
	}
	return s;
}

void resSetOvlProcTbl(int arg0) {
    consPrintf("%s : %p\n", "resSetOvlProcTbl", arg0);
    if (pReadInst != NULL) {
        M2C_FIELD(pReadInst, int *, 8) = arg0;
        pReadInst = NULL;
    }
}

void resOvlProcInst(i, j, a, b, c, d)
int i, j, a, b, c, d;
{
	OvlFn *t = ((InstEnt2 *)&InstBuf)[i].tbl;
	if (t)
		t[j](a, b, c);
}

void resOvlProcCurrent(int arg0, int arg1, int arg2, int arg3) {
    resOvlProcInst(CurrentInst, arg0, arg1, arg2, arg3, arg0);
}

void resOvlProcAll(int a, int b, int c, int d)
{
	int i;
	for (i = 0; i <= CurrentInst; i++)
		resOvlProcInst(i, a, b, c, d);
}

int resReadInstThr(int thr, int inst)
{
	int arg[4];
	arg[0] = inst;
	return thrEntry(thr, _resReadInst, arg, 1);
}

                          /* extern */

void _resReadInst(void *arg0) {
    int temp_s0;
    int var_s1;

    var_s1 = 10;
    do {
        thrChange(arg0);
        var_s1 -= 1;
    } while (var_s1 != 0);
    temp_s0 = M2C_FIELD(arg0, int *, 0x40);
    if (M2C_FIELD(arg0, int *, 0xC) != 1) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0xFE, "_resReadInst", "pThr->Arg == resReadInst_Args");
    }
    resReadInst(temp_s0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReadInst);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBAEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBAF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBB18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBB20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBB2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBB40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBB5C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBB90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBBA8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBBC0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBBCC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReleaseInst);

int resGetCurrentInst(void) {
    return CurrentInst;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resInitInst);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBC4C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReadLocal);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBCA0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBCB8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReadOrder);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBCE8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReadTable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReadString);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBD40);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReadReferThr);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBD5C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBD68);

void _resReadRefer(void *arg0) {
    int temp_s1;

    temp_s1 = M2C_FIELD(arg0, int *, 0xC);
    if (arg0 == NULL) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x2E3, "_resReadRefer", "pThr");
    }
    if (temp_s1 != 3) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x2E4, "_resReadRefer", "Arg == resReadRefer_Args");
    }
    resReadRefer(M2C_FIELD(arg0, int *, 0x40), M2C_FIELD(arg0, int *, 0x44), M2C_FIELD(arg0, int *, 0x48));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReadRefer);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBDD8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBDF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBE10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBE40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBE58);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReleaseRefer);

int resGetEntrySect(int arg0, int arg1) {
    if (arg0 < 0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x360, "resGetEntrySect", "Inst >= Inst_System");
    }
    if (CurrentInst < arg0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x361, "resGetEntrySect", "Inst <= CurrentInst");
    }
    if (arg1 < 0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x362, "resGetEntrySect", "Sect >= Sect_Instruct");
    }
    if (arg1 >= 7) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x363, "resGetEntrySect", "Sect < Sect_Num");
    }
    return M2C_FIELD(M2C_FIELD(M2C_FIELD((char *)&InstBuf + (arg0 << 5), char **, 0), char **, 4) + arg1 * 8, int *, 4);
}

int resGetEntryLocal(int a)
{
	return resGetEntrySect(a, 2);
}

int resGetEntryRefer(int a)
{
	return resGetEntrySect(a, 4);
}

int resGetEntryTable(int a)
{
	return resGetEntrySect(a, 5);
}

int resGetEntryString(int a)
{
	return resGetEntrySect(a, 6);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetDatSect);

void **resGetDatLocal(a, b)
    int a, b;
{
    return resGetDatSect(a, 2, b);
}

void *resGetDatRefer(int a, int b)
{
	return resGetDatSect(a, 4, b);
}

void *resGetDatTable(int a, int b)
{
	return resGetDatSect(a, 5, b);
}

void *resGetDatString(int a, int b)
{
	return resGetDatSect(a, 6, b);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBF14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBF20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBF2C);

int resGetSizeSect(int arg0, int arg1, int arg2) {
    if (arg0 < 0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x3DF, "resGetSizeSect", &D_000FBD40);
    }
    if (arg1 < 0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x3E0, "resGetSizeSect", &D_000FBF14);
    }
    if (arg2 < 0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x3E1, "resGetSizeSect", &D_000FBF20);
    }
    if (arg2 >= resGetEntrySect(arg0, arg1)) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x3E2, "resGetSizeSect", &D_000FBF2C);
    }
    return M2C_FIELD(resGetDatSect(arg0, arg1, arg2), int *, 4);
}

void resGetSizeLocal(int arg0, int arg1) {
    resGetSizeSect(arg0, 2, arg1);
}

void resGetSizeTable(int arg0, int arg1) {
    resGetSizeSect(arg0, 5, arg1);
}

void resGetSizeString(int arg0, int arg1) {
    resGetSizeSect(arg0, 6, arg1);
}

int resGetPtrSect(int arg0, int arg1, int arg2) {
    if (arg0 < 0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x407, "resGetPtrSect", &D_000FBD40);
    }
    if (arg1 < 0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x408, "resGetPtrSect", &D_000FBF14);
    }
    if (arg2 < 0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x409, "resGetPtrSect", &D_000FBF20);
    }
    if (arg2 >= resGetEntrySect(arg0, arg1)) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x40A, "resGetPtrSect", &D_000FBF2C);
    }
    return *(int *)resGetDatSect(arg0, arg1, arg2);
}

int resGetPtrLocal(int a, int b)
{
	return resGetPtrSect(a, 2, b);
}

int resGetPtrTable(int a, int b)
{
	return resGetPtrSect(a, 5, b);
}

int resGetPtrString(int a, int b)
{
	return resGetPtrSect(a, 6, b);
}

int resGetExtSect(int arg0, int arg1, int arg2) {
    if (arg0 < 0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x42F, "resGetExtSect", &D_000FBD40);
    }
    if (arg1 < 0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x430, "resGetExtSect", &D_000FBF14);
    }
    if (arg2 < 0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x431, "resGetExtSect", &D_000FBF20);
    }
    if (arg2 >= resGetEntrySect(arg0, arg1)) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x432, "resGetExtSect", &D_000FBF2C);
    }
    return M2C_FIELD(resGetDatSect(arg0, arg1, arg2), int *, 0x10);
}

void resGetExtLocal(int arg0, int arg1) {
    resGetExtSect(arg0, 2, arg1);
}

void resGetExtTable(int arg0, int arg1) {
    resGetExtSect(arg0, 5, arg1);
}

void resGetExtString(int arg0, int arg1) {
    resGetExtSect(arg0, 6, arg1);
}

void *resArg(int *r, unsigned int i)
{
	if (r && i < (unsigned int)r[3])
		return ((void **)r[2])[i];
	return &D_000FBF80;
}

int resCmpExt(int *r, char *s)
{
	char *p = resArg(r, 1);
	if (!p)
		return -1;
	return strcmp(p, s);
}

int resGetTerm(void) {
    return pResTerm;
}

void resSetTerm(int arg0) {
    pResTerm = arg0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBF80);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resAsmWord);

void resReleaseWord(void) {
}

int resGetWordNum(void *arg0) {
    return *M2C_FIELD(arg0, int **, 0x10);
}

int resGetWordPtr(void *arg0, int arg1) {
    int *temp_s1;
    int *p;

    temp_s1 = M2C_FIELD(arg0, int **, 0x10);
    if (arg1 < 0) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x4C1, "resGetWordPtr", "Index >= 0");
    }
    if (arg1 >= *temp_s1) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x4C2, "resGetWordPtr", "Index < *pnWord");
    }
    p = temp_s1 + 1;
    return p[arg1];
}

void resInitInst();
char *resReadLocal();
char *resReadTable();
char *resReadString();
char *resAsmRes(char *src, char *dst)
{
	int inst = *(unsigned char *)(src + 0x18) & 0xF;
	int id = *(int *)src;
	int *d = (int *)dst;
	char *e = resGetInst(inst);
	*(char **)(src + 0x10) = dst;
	dst = (char *)(((int)dst + 0x2F) & ~15);
	d[2] = *(int *)(e + 8);
	d[0] = id;
	d[1] = 0;
	d[3] = 0;
	d[4] = 0;
	d[5] = 0;
	d[6] = 0;
	d[7] = 0;
	resInitInst(inst, id);
	return resReadString(d, resReadTable(d, resReadLocal(d, dst)));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReleaseRes);

int resInstGetEntrySect(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 8) + M2C_FIELD(arg0, int *, 4)), int *, 4);
}

char *resInstGetDatSect(char *hdr, int sect, int label)
{
	int n;
	char *r;
	if (sect < 0)
		consPrintf(&D_000FBA08, &D_000FB9F8, 0x52C, "resInstGetDatSect", &D_000FBF14);
	if (label < 0)
		consPrintf(&D_000FBA08, &D_000FB9F8, 0x52D, "resInstGetDatSect", &D_000FBF20);
	n = resInstGetEntrySect(hdr, sect);
	r = 0;
	if (n > 0) {
		if (!(label < n))
			consPrintf(&D_000FBA08, &D_000FB9F8, 0x530, "resInstGetDatSect", "Label < resInstGetEntrySect(Hdr, Sect)");
		r = *(char **)(sect * 8 + *(int *)(hdr + 4)) + label * 32;
	}
	return r;
}

int resGetDatPackModel(void) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(*resGetDatLocal(), void **, 4);
    if (M2C_FIELD(temp_s0, int *, 0x2C) != 1) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x543, "resGetDatPackModel", "pTbl[Sect_Table].Entry == 1");
    }
    if (M2C_FIELD(M2C_FIELD(temp_s0, void **, 0x28), int *, 4) != 1) {
        consPrintf(&D_000FBA08, &D_000FB9F8, 0x544, "resGetDatPackModel", "pTbl[Sect_Table].Dat[0].Size == 1");
    }
    return M2C_FIELD(temp_s0, int *, 0x10) + (*M2C_FIELD(M2C_FIELD(temp_s0, void **, 0x28), int **, 0) << 5);
}
