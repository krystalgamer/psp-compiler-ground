/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* constants and strings stay in the module's .rodata (asm) */
extern const float D_00176268;      /* 255 */
extern const float D_0017626C;      /* 1 */
extern const float D_00176270;      /* 255 */
extern const float D_00176278;      /* 1 */
extern const float D_0017627C;      /* 1 / pi */
extern const float D_00176280;      /* 1 */
extern const float D_00176284;      /* 1 / pi */
extern const char D_001762D0[];     /* " " */
extern const char D_001762D4[];     /* " *** error " */
extern const char D_001762E0[];     /* "_Value.width() == width()" */
extern const char D_001762FC[];     /* "../lib/textures/FloatImage.cpp" */
extern const char D_0017631C[];     /* "_Value.height() == height()" */
extern const char PF_mul[] __asm__("_ZZN10FloatImagemlERKS_E19__PRETTY_FUNCTION__");
extern const char PF_add[] __asm__("_ZZN10FloatImageplERKS_E19__PRETTY_FUNCTION__");
extern const char PF_sub[] __asm__("_ZZN10FloatImagemiERKS_E19__PRETTY_FUNCTION__");
extern const char PF_div[] __asm__("_ZZN10FloatImagedvERKS_E19__PRETTY_FUNCTION__");
#define FI_ASSERT(c, s, pf, line) \
    if (!(c)) { \
        common::common_internal::assert_display(D_001762D4, s, D_001762FC, pf, line, D_001762D0); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/FloatImage", _Z41__static_initialization_and_destruction_0ii_FED6C);

FloatImage::FloatImage()
{
}

FloatImage::FloatImage(unsigned int nx, unsigned int ny) : common::t_array2d<ABGR_FLOAT>(nx, ny)
{
}

FloatImage::FloatImage(const FloatImage &o)
{
    *this = o;
}

FloatImage &FloatImage::operator=(const FloatImage &o)
{
    common::t_array2d<ABGR_FLOAT>::operator=(o);
    return *this;
}

FloatImage::FloatImage(const textures::Texture &t)
{
    *this = t;
}

FloatImage &FloatImage::operator=(const textures::Texture &t)
{
    resize(t.width(), t.height());
    const unsigned char *src = const_cast<textures::Texture &>(t).image.addr();
    ABGR_FLOAT *dst = addr();
    for (int y = 0; y != t.height(); y++)
        for (int x = 0; x != t.width(); x++) {
            dst->x = src[0] / D_00176268;
            dst->y = src[1] / D_00176268;
            dst->z = src[2] / D_00176268;
            dst->w = src[3] / D_00176268;
            src += 4;
            dst++;
        }
    return *this;
}

void FloatImage::operator*=(float s)
{
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++)
        *p *= s;
}

void FloatImage::operator+=(float s)
{
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++)
        *p += ABGR_FLOAT(s);
}

void FloatImage::operator-=(float s)
{
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++)
        *p -= ABGR_FLOAT(s);
}

void FloatImage::operator/=(float s)
{
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++)
        *p /= s;
}

void FloatImage::operator*=(math::vector_xyzw v)
{
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++)
        *p *= v;
}

void FloatImage::operator+=(math::vector_xyzw v)
{
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++)
        *p += v;
}

void FloatImage::operator-=(math::vector_xyzw v)
{
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++)
        *p -= v;
}

void FloatImage::operator/=(math::vector_xyzw v)
{
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++)
        *p /= v;
}

FloatImage FloatImage::operator*(math::vector_xyzw v)
{
    FloatImage r(nx(), ny());
    ABGR_FLOAT *d = r.addr();
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++, d++)
        *d = *p * v;
    return r;
}

FloatImage FloatImage::operator+(math::vector_xyzw v)
{
    FloatImage r(nx(), ny());
    ABGR_FLOAT *d = r.addr();
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++, d++)
        *d = *p + v;
    return r;
}

FloatImage FloatImage::operator-(math::vector_xyzw v)
{
    FloatImage r(nx(), ny());
    ABGR_FLOAT *d = r.addr();
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++, d++)
        *d = *p - v;
    return r;
}

FloatImage FloatImage::operator/(math::vector_xyzw v)
{
    FloatImage r(nx(), ny());
    ABGR_FLOAT *d = r.addr();
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++, d++)
        *d = *p / v;
    return r;
}

FloatImage FloatImage::operator*(const FloatImage &_Value)
{
    FI_ASSERT(_Value.width() == width(), D_001762E0, PF_mul, 192);
    FI_ASSERT(_Value.height() == height(), D_0017631C, PF_mul, 193);
    FloatImage r(_Value.nx(), _Value.ny());
    ABGR_FLOAT *d = r.addr();
    const ABGR_FLOAT *q = _Value.addr();
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++, q++, d++)
        *d = *p * *q;
    return r;
}

FloatImage FloatImage::operator+(const FloatImage &_Value)
{
    FI_ASSERT(_Value.width() == width(), D_001762E0, PF_add, 208);
    FI_ASSERT(_Value.height() == height(), D_0017631C, PF_add, 209);
    FloatImage r(_Value.nx(), _Value.ny());
    ABGR_FLOAT *d = r.addr();
    const ABGR_FLOAT *q = _Value.addr();
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++, q++, d++)
        *d = *p + *q;
    return r;
}

FloatImage FloatImage::operator-(const FloatImage &_Value)
{
    FI_ASSERT(_Value.width() == width(), D_001762E0, PF_sub, 224);
    FI_ASSERT(_Value.height() == height(), D_0017631C, PF_sub, 225);
    FloatImage r(_Value.nx(), _Value.ny());
    ABGR_FLOAT *d = r.addr();
    const ABGR_FLOAT *q = _Value.addr();
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++, q++, d++)
        *d = *p - *q;
    return r;
}

FloatImage FloatImage::operator/(const FloatImage &_Value)
{
    FI_ASSERT(_Value.width() == width(), D_001762E0, PF_div, 240);
    FI_ASSERT(_Value.height() == height(), D_0017631C, PF_div, 241);
    FloatImage r(_Value.nx(), _Value.ny());
    ABGR_FLOAT *d = r.addr();
    const ABGR_FLOAT *q = _Value.addr();
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++, q++, d++)
        *d = *p / *q;
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/FloatImage", _ZN10FloatImage4copyERN8textures7TextureE);

float FloatImage::gaussian1(float x, float sigma)
{
    float a = D_00176278 / (2 * sigma * sigma);
    return expf(-(x * x) * a) * sqrtf(a * D_0017627C);
}

float FloatImage::gaussian2(float x, float sigma)
{
    float a = D_00176280 / (2 * sigma * sigma);
    return expf(-(x * x) * a) * a * D_00176284;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/FloatImage", _ZN10FloatImage6blur2dEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/FloatImage", _ZN10FloatImage4blurEif);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_FED6C");
void _GLOBAL__I__ZN10FloatImageC2Ev(void);
void _GLOBAL__D__ZN10FloatImageC2Ev(void);
}

void _GLOBAL__I__ZN10FloatImageC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN10FloatImageC2Ev(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/FloatImage", _ZN6common9t_array2dI10ABGR_FLOATEC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/FloatImage", _ZN6common9t_array2dI10ABGR_FLOATEC2Ejj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/FloatImage", _ZN6common9t_array2dI10ABGR_FLOATEaSERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/FloatImage", _ZNK6common7t_arrayI10ABGR_FLOATE4sizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/FloatImage", _ZN6common7t_arrayI10ABGR_FLOATEC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/FloatImage", _ZN6common7t_arrayI10ABGR_FLOATEC2Ej);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/FloatImage", _ZN6common7t_arrayI10ABGR_FLOATEaSERKS2_);
