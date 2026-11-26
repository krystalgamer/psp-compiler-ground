#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoGetSlotTop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoGetSlotNum);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoSetDeviceRange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoGetDeviceRangeLo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoGetDeviceRangeHi);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", D_0010AEE4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxCategorySetVoiceRange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxCategoryGetVoiceRangeLo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxCategoryGetVoiceRangeHi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", FindVoNormal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", FindVoGroup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoAllocDevice);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoSetTakenCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoGetStatus);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoGetPlaySamples);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoGetPlayUnitSamples);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoGetDeviceID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoGetSlotID);
