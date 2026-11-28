/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN4math9factorialEi");
__asm__(".globl _GLOBAL__D__ZN4math9factorialEi");

int math::factorial(int n)
{
    if (n == 0)
        return 1;
    int r = 1;
    for (; n > 1; n--)
        r *= n;
    return r;
}

int math::double_factorial(int n)
{
    if (n == 0 || n == -1)
        return 1;
    int r = 1;
    for (; n > 1; n -= 2)
        r *= n;
    return r;
}

float math::SH::P(int l, int m, float x)
{
    SCENE_ASSERT(0 <= l, " *** error ", "0 <= l", "../lib/sh/SH.cpp", __PRETTY_FUNCTION__, 63, " ");
    SCENE_ASSERT(0 <= m && m <= l, " *** error ", "0 <= m && m <= l", "../lib/sh/SH.cpp", __PRETTY_FUNCTION__, 64, " ");
    if (m == 0 && l == 0)
        return 1.0f;
    float somx2 = sqrtf(1.0f - x * x);
    float p = 1.0f;
    for (int i = m; i != 0; i--)
        p *= somx2;
    float df = double_factorial(2 * m - 1);
    if (m & 1)
        df = -df;
    float pmm = df * p;
    if (l == m)
        return pmm;
    float pmmp1 = x * (2.0f * m + 1.0f) * pmm;
    if (m + 1 == l)
        return pmmp1;
    float a = pmm;
    int ll = m + 1;
    float b = pmmp1, c;
    do {
        int n = ll + 1;
        c = (x * (2.0f * n - 1.0f) * b - (n + m - 1.0f) * a) / (n - m);
        a = b;
        b = c;
        ll = n;
    } while (ll != l);
    return c;
}

float math::SH::K(int l, int m)
{
    int am = abs(m);
    return sqrtf((2.0f * l + 1.0f) * factorial(l - am) / (factorial(l + am) * 12.566371f));
}

float math::SH::Eval(int l, int m, float theta, float phi)
{
    SCENE_ASSERT(theta >= 0.f && theta <= 3.14159265f, " *** error ", "theta >= 0.f && theta <= math::PI", "../lib/sh/SH.cpp", __PRETTY_FUNCTION__, 136, " ");
    SCENE_ASSERT(phi >= 0.f && phi <= 6.2831853f, " *** error ", "phi >= 0.f && phi <= math::TWICEPI", "../lib/sh/SH.cpp", __PRETTY_FUNCTION__, 137, " ");
    SCENE_ASSERT(-l <= m && m <= l, " *** error ", "-l <= m && m <= l", "../lib/sh/SH.cpp", __PRETTY_FUNCTION__, 138, " ");
    if (m > 0)
        return sqrtf(2.0f) * K(l, m) * cosf(m * phi) * P(l, m, cosf(theta));
    else if (m < 0)
        return sqrtf(2.0f) * K(l, m) * sinf(-m * phi) * P(l, -m, cosf(theta));
    SCENE_ASSERT(m == 0, " *** error ", "m == 0", "../lib/sh/SH.cpp", __PRETTY_FUNCTION__, 150, " ");
    return K(l, 0) * P(l, 0, cosf(theta));
}

int math::SH::N(unsigned int l)
{
    return (l + 1) * (l + 1);
}
