/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"

extern int CurrentInst;
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK resReadRefer(int, int, int);                /* extern */
extern unsigned char D_000FB9F8;
extern unsigned char D_000FBA08;
void *resGetDatSect(int, int, int);                 /* extern */
int resGetEntrySect(int, int);                      /* extern */
extern unsigned char D_000FBD40;
extern unsigned char D_000FBF14;
extern unsigned char D_000FBF20;
extern unsigned char D_000FBF2C;
void **resGetDatLocal();                            /* extern */

extern int pResTerm;
extern int pCurrent;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", _resReadInst);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetEntrySect);

int resGetEntryLocal(int a)
{
	return resGetEntrySect(a, 2);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetEntryRefer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetEntryTable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetEntryString);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetDatSect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetDatLocal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetDatRefer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetDatTable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetDatString);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetPtrSect);

int resGetPtrLocal(int a, int b)
{
	return resGetPtrSect(a, 2, b);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetPtrTable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetPtrString);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resArg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resCmpExt);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetWordPtr);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskRest);

int taskHead(void)
{
	int r = 0;
	if (pCurrent)
		r = **(int **)pCurrent;
	return r;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskHeadAlive);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskSendParent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskSendElder);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskSendYoung);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskSendChild);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskSendReflexive);
