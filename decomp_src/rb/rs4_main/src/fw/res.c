/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"

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
extern int pCurrent;


M2C_UNK resReadInst(int);                           /* extern */
M2C_UNK thrChange(void *);                          /* extern */

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

#ifndef NULL
#define NULL ((void *)0)
#endif

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

#ifndef NULL
#define NULL ((void *)0)
#endif

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

extern unsigned char InstBuf;

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

#ifndef NULL
#define NULL ((void *)0)
#endif

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

#ifndef NULL
#define NULL ((void *)0)
#endif
void resGetSizeLocal(int arg0, int arg1) {
    resGetSizeSect(arg0, 2, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void resGetSizeTable(int arg0, int arg1) {
    resGetSizeSect(arg0, 5, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void resGetSizeString(int arg0, int arg1) {
    resGetSizeSect(arg0, 6, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

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

#ifndef NULL
#define NULL ((void *)0)
#endif

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

#ifndef NULL
#define NULL ((void *)0)
#endif
void resGetExtLocal(int arg0, int arg1) {
    resGetExtSect(arg0, 2, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void resGetExtTable(int arg0, int arg1) {
    resGetExtSect(arg0, 5, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void resGetExtString(int arg0, int arg1) {
    resGetExtSect(arg0, 6, arg1);
}

extern unsigned char D_000FBF80;
void *resArg(int *r, unsigned int i)
{
	if (r && i < (unsigned int)r[3])
		return ((void **)r[2])[i];
	return &D_000FBF80;
}

int strcmp(const char *, const char *);
int resCmpExt(int *r, char *s)
{
	char *p = resArg(r, 1);
	if (!p)
		return -1;
	return strcmp(p, s);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int resGetTerm(void) {
    return pResTerm;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void resSetTerm(int arg0) {
    pResTerm = arg0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBF80);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resAsmWord);

void resReleaseWord(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resAsmRes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReleaseRes);

#ifndef NULL
#define NULL ((void *)0)
#endif
int resInstGetEntrySect(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 8) + M2C_FIELD(arg0, int *, 4)), int *, 4);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resInstGetDatSect);

#ifndef NULL
#define NULL ((void *)0)
#endif

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FC050);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FC058);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FC068);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FC070);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FC08C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FC098);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FC0A8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskTerm);

#ifndef NULL
#define NULL ((void *)0)
#endif

int taskSwitchCntx(int arg0) {
    int temp_v0;

    temp_v0 = pCurrent;
    pCurrent = arg0;
    return temp_v0;
}

int taskRest(void)
{
	int r = 0;
	if (pCurrent)
		r = (*(int **)pCurrent)[7];
	return r;
}

int taskHead(void)
{
	int r = 0;
	if (pCurrent)
		r = **(int **)pCurrent;
	return r;
}

int taskHeadAlive(void)
{
	if (pCurrent)
		return rsvHeadAlive(*(int *)pCurrent);
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void taskProc(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 8)();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskMake);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FC0C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FC0C8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskKill);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskKillReflexive);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskKillChild);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskDefaultMsg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskAllFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskSendProc);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FC1C0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskSendTag);

int taskSendParent(int *t, int a, int b, int c)
{
	return taskSendTag(t, 0xA, t[4], -1, a, b, c);
}

int taskSendElder(int *t, int a, int b, int c)
{
	return taskSendTag(t, 0xB, t[5], 0x14, a, b, c);
}

int taskSendYoung(int *t, int a, int b, int c)
{
	return taskSendTag(t, 0xC, t[6], 0x18, a, b, c);
}

int taskSendChild(int *t, int a, int b, int c)
{
	return taskSendTag(t, 0xD, t[7], 0x14, a, b, c);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskSendReflexive);
