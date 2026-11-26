/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _Z41__static_initialization_and_destruction_0ii_51AA0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math10safe_acosfEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math10safe_asinfEf);

float math::safe_atan2f(float y, float x)
{
    return atan2f(y, x);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math10safe_sqrtfEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math9FastNoiseEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math5angle17BetweenTwoVectorsERKNS_9vector_xyES3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math5angle18BetweenTwoVectors2ERKNS_11vector_xyzwES3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math5angle17BetweenTwoVectorsENS_11vector_xyzwERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math5angle11SmartUpdateEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math5angle8RelativeEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math4wrapEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math4areaENS_11vector_xyzwES0_S0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math11compactnessENS_11vector_xyzwES0_S0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZNK4math11vector_xyzw5printESsSsSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZNK4math10vector_xyz5printESsSsSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZNK4math9vector_xy5printESsSsSs);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_51AA0");
void _GLOBAL__I__ZN4math10safe_acosfEf(void);
void _GLOBAL__D__ZN4math10safe_acosfEf(void);
}

void _GLOBAL__I__ZN4math10safe_acosfEf(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN4math10safe_acosfEf(void)
{
    static_init(0, 0xFFFF);
}

