#include "common.h"
#include "m2c_macros.h"
extern unsigned char D_00109C00;
extern unsigned char D_00109C50;
M2C_UNK sgxFlush();                                 /* extern */
M2C_UNK sgxTickProc(float);                           /* extern */
extern int gSgxMallocFunc;
extern int gSgxFreeFunc;
extern int gSgxPrintFunc;
extern int gSgxDebugFlags;
extern int D_0011FBE4;
extern int D_0011FBE8;
extern int D_0011FBF0;
extern int D_0011FC00;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxPrintfPref);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxPrintf);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgx", D_00109CA8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxMalloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxNextToken);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxNextLine);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxGetLineCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxConfReadStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxConfReadInt);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sgxStrCpyN(unsigned char *arg0, unsigned char *arg1, int arg2) {
    int temp_a2;
    int var_a3;
    unsigned char *var_a0;
    unsigned char *var_a1;
    unsigned char var_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v0 = *var_a1;
    var_a3 = 0;
    if (var_v0 != 0) {
        temp_a2 = arg2 - 1;
        if (temp_a2 > 0) {
loop_2:
            *var_a0 = var_v0;
            var_a1 += 1;
            var_a3 += 1;
            var_v0 = *var_a1;
            var_a0 += 1;
            if (var_v0 != 0) {
                if (var_a3 < temp_a2) {
                    goto loop_2;
                }
            }
        }
    }
    *var_a0 = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int strlen(const char *s);

void sgxStrCatN(signed char *arg0, int arg1, int arg2) {
    unsigned int temp_v0;

    temp_v0 = strlen(arg0);
    sgxStrCpyN(&arg0[temp_v0], arg1, arg2 - temp_v0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxIsStrMatch);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxIsStrMatchWC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxIsStrIncWC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxListArrayInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxListEnumID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxAttrSetValueSafe);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxAttrSetUpdateSafe);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxAttrCopyUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxAttrCopyEnable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxAttrMergeEnable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxStackMemOpen);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sgxStackMemClose(void *arg0) {
    return M2C_FIELD(arg0, int *, 4) + M2C_FIELD(arg0, int *, 8);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxStackMemAlloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxStackMemAllocStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxStackMemAlign);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgx", D_00109CE0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxFlush);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxTickProc);

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
void sgxProc(float fparg0) {
    sgxFlush();
    sgxTickProc(fparg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSetMallocFunc(int arg0) {
    int temp_v0;

    temp_v0 = gSgxMallocFunc;
    gSgxMallocFunc = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSetFreeFunc(int arg0) {
    int temp_v0;

    temp_v0 = gSgxFreeFunc;
    gSgxFreeFunc = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSetPrintFunc(int arg0) {
    int temp_v0;

    temp_v0 = gSgxPrintFunc;
    gSgxPrintFunc = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSetDebugFlags(int arg0) {
    int temp_v0;

    temp_v0 = gSgxDebugFlags;
    gSgxDebugFlags = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetDebugFlags(void) {
    return gSgxDebugFlags;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxSetMainThreadID);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetMainThreadID(void) {
    return D_0011FBE4;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxSetSyncMode);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetSyncMode(void) {
    return D_0011FBE8;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxSetOutputMode);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetOutputMode(void) {
    return D_0011FBF0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxIsOutputSurround(void) {
    return D_0011FC00;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxCent128ToPitch);
