/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* constants and strings stay in the module's .rodata (asm) */
extern const float D_00168A14, D_00168A18, D_00168A1C;     /* 1, 1e-5, -1 */
extern const float D_00168A20, D_00168A24, D_00168A28;     /* 1, 1e-5, -1 */
extern const float D_00168A3C, D_00168A40;                 /* pi, 2 pi */
extern const float D_00168A44;                             /* 1e-5 */
extern const char D_00168A74[];     /* " *** error " */
extern const char D_00168A80[];     /* "fabsf( _Value ) - 1.f < EPSILON5" */
extern const char D_00168AA4[];     /* "../lib/maths/math_misc.cpp" */
extern const char D_00168AC0[];     /* " " */
extern const char D_00168B0C[];     /* " *** warning " */
extern const char D_00168B1C[];     /* "_Value - EPSILON5 < _Start + _Period" */
extern const char D_00168B44[];     /* "_Start <= _Value + EPSILON5" */
extern const char D_00168B60[];     /* "!NaN" */
extern const char D_00168B68[];     /* "!NaN assert failed" */
extern const char PF_safe_acosf[] __asm__("_ZZN4math10safe_acosfEfE19__PRETTY_FUNCTION__");
extern const char PF_safe_asinf[] __asm__("_ZZN4math10safe_asinfEfE19__PRETTY_FUNCTION__");
extern const char PF_wrap[] __asm__("_ZZN4math4wrapEfffE19__PRETTY_FUNCTION__");
#define MM_ASSERT(c, s, pf, line, msg) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00168A74, s, D_00168AA4, pf, line, msg); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }
#define MM_WARN(c, s, pf, line) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00168B0C, s, D_00168AA4, pf, line, D_00168AC0); \
        common::common_internal::on_warning(); \
    }

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _Z41__static_initialization_and_destruction_0ii_53F1C);

float math::safe_acosf(float x)
{
    MM_ASSERT(fabsf(x) - D_00168A14 < D_00168A18, D_00168A80, PF_safe_acosf, 31, D_00168AC0);
    return acosf(x > D_00168A14 ? D_00168A14 : (x < D_00168A1C ? D_00168A1C : x));
}

float math::safe_asinf(float x)
{
    MM_ASSERT(fabsf(x) - D_00168A20 < D_00168A24, D_00168A80, PF_safe_asinf, 38, D_00168AC0);
    return asinf(x > D_00168A20 ? D_00168A20 : (x < D_00168A28 ? D_00168A28 : x));
}

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

/* pi, 2 pi: this function's float pool (carved .rodata) */
float math::angle::Relative(float a, float b)
{
    return wrap(b, a - 3.14159265358979323846f, 2 * 3.14159265358979323846f) - a;
}

float math::wrap(float _Value, float _Start, float _Period)
{
    MM_ASSERT(_Value == _Value, D_00168B60, PF_wrap, 155, D_00168B68);
    MM_ASSERT(_Start == _Start, D_00168B60, PF_wrap, 156, D_00168B68);
    MM_ASSERT(_Period == _Period, D_00168B60, PF_wrap, 157, D_00168B68);
    float q = (_Value - _Start) / _Period;
    int n = (int)q - (q < 0);
    float v = _Value - n * _Period;
    MM_WARN(_Start <= v + D_00168A44, D_00168B44, PF_wrap, 179);
    MM_WARN(v - D_00168A44 < _Start + _Period, D_00168B1C, PF_wrap, 180);
    if (v < _Start || v >= _Start + _Period)
        v = _Start;
    return v;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZN4math4areaENS_11vector_xyzwES0_S0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_safe_acosf", _ZN4math11compactnessENS_11vector_xyzwES0_S0_);

void math::vector_xyzw::print(std::string pre, std::string sep, std::string post) const
{
    std::cout << pre << x << sep << y << sep << z << sep << w << post;
}

void math::vector_xyz::print(std::string pre, std::string sep, std::string post) const
{
    std::cout << pre << x << sep << y << sep << z << post;
}

void math::vector_xy::print(std::string pre, std::string sep, std::string post) const
{
    std::cout << pre << x << sep << y << post;
}

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

