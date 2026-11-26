#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", CbCallFunc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxCbCallMode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxCbRegist);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxFormSampleToByte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxFormByteToSample);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxGetFormUnitByte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxGetFormUnitSample);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxSetStrPcmBufSample);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxGetStrPcmBufSample);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", sgxPatchInit);

void sgxPatchTerm(void) {
}

void sgxPatchFlush(void) {
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxsys", D_00109F90);
