/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
int sgxSndGetStatus(int);                           /* extern */
extern int D_0011FBFC;


#ifndef NULL
#define NULL ((void *)0)
#endif

void CbCallFunc(int arg0, M2C_UNK (*arg1)(int, int), int arg2, int arg3) {
    if (arg0 != 0) {

    } else if (sgxSndGetStatus(arg2) & 1) {
        arg1(arg2, arg3);
    }
}

extern int gWork_11FBE0[];

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxCbCallMode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxCbRegist);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxFormSampleToByte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxFormByteToSample);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxGetFormUnitByte);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sgxGetFormUnitSample(unsigned int arg0) {
    switch (arg0) {
    default:
    case 0:
    case 1:
    case 2:
    case 4:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
        return 1;
    case 3:
        return 0x1C;
    case 5:
        return 6;
    }
}

int sgxSetStrPcmBufSample(int n)
{
    int old = gWork_11FBE0[7];
    gWork_11FBE0[7] = n;
    return old;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetStrPcmBufSample(void) {
    return D_0011FBFC;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sgxPatchInit(void) {
    return 1;
}

void sgxPatchTerm(void) {
}

void sgxPatchFlush(void) {
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", D_00109F90);
