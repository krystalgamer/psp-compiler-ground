/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _Z41__static_initialization_and_destruction_0ii_53F1C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZN4math10safe_acosfEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZN4math10safe_asinfEf);

float math::safe_atan2f(float y, float x)
{
    return atan2f(y, x);
}

float math::safe_sqrtf(float x)
{
    if (x < 0)
        return 0;
    return sqrtf(x);
}

extern const float D_00168A2C;  /* 1 / 2^30 */
extern const float D_00168A30;  /* 1.0f */

float math::FastNoise(unsigned int n)
{
    n = (n << 13) ^ n;
    return D_00168A30 - ((n * (n * n * 15731 + 789221) + 1376312589) & 0x7FFFFFFF) * D_00168A2C;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZN4math5angle17BetweenTwoVectorsERKNS_9vector_xyES3_);

float math::angle::BetweenTwoVectors2(const vector_xyzw &a, const vector_xyzw &b)
{
    return BetweenTwoVectors(vector_xy(a.x, a.y), vector_xy(b.x, b.y));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZN4math5angle17BetweenTwoVectorsENS_11vector_xyzwERKS1_);

float math::angle::SmartUpdate(float a, float b)
{
    return a + Relative(a, b);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZN4math5angle8RelativeEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZN4math4wrapEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZN4math4areaENS_11vector_xyzwES0_S0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZN4math11compactnessENS_11vector_xyzwES0_S0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZNK4math11vector_xyzw5printESsSsSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZNK4math10vector_xyz5printESsSsSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZNK4math9vector_xy5printESsSsSs);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_53F1C");
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

