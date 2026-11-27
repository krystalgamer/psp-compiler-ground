#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxFree(int);                               /* extern */
extern unsigned char gWork_11FF60;
extern int D_0011FF64;
extern int D_0011FF68;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoInit);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void sgxVoTerm(void) {
    if (M2C_FIELD(&gWork_11FF60, int *, 0) == 0) {

    } else {
        sgxFree(M2C_FIELD(&gWork_11FF60, int *, 4));
        memset(&gWork_11FF60, 0, 0x88CU);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxVoGetSlotTop(void) {
    return D_0011FF64;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxVoGetSlotNum(void) {
    return D_0011FF68;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif

signed char sgxVoGetStatus(int arg0) {
    return M2C_FIELD(((arg0 * 0x30) + D_0011FF64), signed char *, 4);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoGetPlaySamples);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoGetPlayUnitSamples);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxVoGetDeviceID(int arg0) {
    return M2C_FIELD(((arg0 * 0x30) + D_0011FF64), int *, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxVoGetSlotID(int arg0) {
    return M2C_FIELD(((arg0 * 0x30) + D_0011FF64), int *, 0x1C);
}
