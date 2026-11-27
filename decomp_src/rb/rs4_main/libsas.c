#include "common.h"
#include "m2c_macros.h"
M2C_UNK sceSasInitWithGrain(M2C_UNK);               /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasCore);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasCoreWithMix);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasInitWithGrain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetKeyOn);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetKeyOff);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetPause);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetPauseMulti);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasGetPauseFlag);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetPitch);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetVoice);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetNoise);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetADSR);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetADSRmode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetSL);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetSimpleADSR);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasGetEndFlag);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasGetEnvelope);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetEffect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetEffectVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetEffectType);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasSetEffectParam);

#ifndef NULL
#define NULL ((void *)0)
#endif

void sceSasInit(void) {
    sceSasInitWithGrain(0x100);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/libsas", sceSasExit);
