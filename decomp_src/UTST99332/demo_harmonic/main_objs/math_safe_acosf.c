/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN4math10safe_acosfEf");
__asm__(".globl _GLOBAL__D__ZN4math10safe_acosfEf");

/* constants and strings stay in the module's .rodata (asm) */
extern const char D_00165B54[];     /* " *** error " */
extern const char D_00165B60[];     /* "fabsf( _Value ) - 1.f < EPSILON5" */
extern const char D_00165B84[];     /* "../lib/maths/math_misc.cpp" */
extern const char D_00165BA0[];     /* " " */
extern const char D_00165BEC[];     /* " *** warning " */
extern const char D_00165BFC[];     /* "_Value - EPSILON5 < _Start + _Period" */
extern const char D_00165C24[];     /* "_Start <= _Value + EPSILON5" */
extern const char D_00165C40[];     /* "!NaN" */
extern const char D_00165C48[];     /* "!NaN assert failed" */
extern const char PF_safe_acosf[] __asm__("_ZZN4math10safe_acosfEfE19__PRETTY_FUNCTION__");
extern const char PF_safe_asinf[] __asm__("_ZZN4math10safe_asinfEfE19__PRETTY_FUNCTION__");
extern const char PF_wrap[] __asm__("_ZZN4math4wrapEfffE19__PRETTY_FUNCTION__");
#define MM_ASSERT(c, s, pf, line, msg) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00165B54, s, D_00165B84, pf, line, msg); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }
#define MM_WARN(c, s, pf, line) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00165BEC, s, D_00165B84, pf, line, D_00165BA0); \
        common::common_internal::on_warning(); \
    }

float math::safe_acosf(float x)
{
    MM_ASSERT(fabsf(x) - 1.0f < 1e-5f, D_00165B60, PF_safe_acosf, 31, D_00165BA0);
    return acosf(x > 1.0f ? 1.0f : (x < -1.0f ? -1.0f : x));
}

float math::safe_asinf(float x)
{
    MM_ASSERT(fabsf(x) - 1.0f < 1e-5f, D_00165B60, PF_safe_asinf, 38, D_00165BA0);
    return asinf(x > 1.0f ? 1.0f : (x < -1.0f ? -1.0f : x));
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


float math::FastNoise(unsigned int n)
{
    n = (n << 13) ^ n;
    return 1.0f - ((n * (n * n * 15731 + 789221) + 1376312589) & 0x7FFFFFFF) * 9.31322574615478515625e-10f;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math5angle17BetweenTwoVectorsERKNS_9vector_xyES3_);

float math::angle::BetweenTwoVectors2(const vector_xyzw &a, const vector_xyzw &b)
{
    return BetweenTwoVectors(vector_xy(a.x, a.y), vector_xy(b.x, b.y));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math5angle17BetweenTwoVectorsENS_11vector_xyzwERKS1_);

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
    MM_ASSERT(_Value == _Value, D_00165C40, PF_wrap, 155, D_00165C48);
    MM_ASSERT(_Start == _Start, D_00165C40, PF_wrap, 156, D_00165C48);
    MM_ASSERT(_Period == _Period, D_00165C40, PF_wrap, 157, D_00165C48);
    float q = (_Value - _Start) / _Period;
    int n = (int)q - (q < 0);
    float v = _Value - n * _Period;
    MM_WARN(_Start <= v + 1e-5f, D_00165C24, PF_wrap, 179);
    MM_WARN(v - 1e-5f < _Start + _Period, D_00165BFC, PF_wrap, 180);
    if (v < _Start || v >= _Start + _Period)
        v = _Start;
    return v;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math4areaENS_11vector_xyzwES0_S0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_safe_acosf", _ZN4math11compactnessENS_11vector_xyzwES0_S0_);

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

/* the asm functions refer to the header statics by their module names */
__asm__("_ZN4math12BEZIER_BASISE_18B9B0 = _ZN4math12BEZIER_BASISE\n"
        "_ZN4math13HERMITE_BASISE_18B970 = _ZN4math13HERMITE_BASISE\n");
/* split artifact: other objects' asm names a %lo of matrix::Identity()'s IDENTITY after this address */
__asm__(".globl D_0018B9E0\nD_0018B9E0 = _ZN4math12BEZIER_BASISE + 0x30");
