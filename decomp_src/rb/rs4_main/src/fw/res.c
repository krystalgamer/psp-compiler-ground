#include "common.h"
#include "m2c_macros.h"
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetCurrentInst);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", _resReadRefer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReadRefer);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBDD8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBDF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBE10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBE40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", D_000FBE58);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resReleaseRefer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetEntrySect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetEntryLocal);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetSizeSect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetSizeLocal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetSizeTable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetSizeString);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetPtrSect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetPtrLocal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetPtrTable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetPtrString);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetExtSect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetExtLocal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetExtTable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetExtString);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resArg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resCmpExt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetTerm);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetWordNum);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", resGetDatPackModel);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/res", taskHead);

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
