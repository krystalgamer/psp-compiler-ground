/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN10FloatImageC2Ev");
__asm__(".globl _GLOBAL__D__ZN10FloatImageC2Ev");

/* constants and strings stay in the module's .rodata (asm) */
extern const char D_001733A8[];     /* " " */
extern const char D_001733AC[];     /* " *** error " */
extern const char D_001733B8[];     /* "_Value.width() == width()" */
extern const char D_001733D4[];     /* "../lib/textures/FloatImage.cpp" */
extern const char D_001733F4[];     /* "_Value.height() == height()" */
extern const char PF_mul[] __asm__("_ZZN10FloatImagemlERKS_E19__PRETTY_FUNCTION__");
extern const char PF_add[] __asm__("_ZZN10FloatImageplERKS_E19__PRETTY_FUNCTION__");
extern const char PF_sub[] __asm__("_ZZN10FloatImagemiERKS_E19__PRETTY_FUNCTION__");
extern const char PF_div[] __asm__("_ZZN10FloatImagedvERKS_E19__PRETTY_FUNCTION__");
#define FI_ASSERT(c, s, pf, line) \
    if (!(c)) { \
        common::common_internal::assert_display(D_001733AC, s, D_001733D4, pf, line, D_001733A8); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

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
            dst->x = src[0] / 255.0f;
            dst->y = src[1] / 255.0f;
            dst->z = src[2] / 255.0f;
            dst->w = src[3] / 255.0f;
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
    FI_ASSERT(_Value.width() == width(), D_001733B8, PF_mul, 192);
    FI_ASSERT(_Value.height() == height(), D_001733F4, PF_mul, 193);
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
    FI_ASSERT(_Value.width() == width(), D_001733B8, PF_add, 208);
    FI_ASSERT(_Value.height() == height(), D_001733F4, PF_add, 209);
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
    FI_ASSERT(_Value.width() == width(), D_001733B8, PF_sub, 224);
    FI_ASSERT(_Value.height() == height(), D_001733F4, PF_sub, 225);
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
    FI_ASSERT(_Value.width() == width(), D_001733B8, PF_div, 240);
    FI_ASSERT(_Value.height() == height(), D_001733F4, PF_div, 241);
    FloatImage r(_Value.nx(), _Value.ny());
    ABGR_FLOAT *d = r.addr();
    const ABGR_FLOAT *q = _Value.addr();
    ABGR_FLOAT *p = addr();
    for (unsigned int i = 0; i != size(); i++, p++, q++, d++)
        *d = *p / *q;
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/FloatImage", _ZN10FloatImage4copyERN8textures7TextureE);

float FloatImage::gaussian1(float x, float sigma)
{
    float a = 1.0f / (2 * sigma * sigma);
    return expf(-(x * x) * a) * sqrtf(a * 0.31830987f);
}

float FloatImage::gaussian2(float x, float sigma)
{
    float a = 1.0f / (2 * sigma * sigma);
    return expf(-(x * x) * a) * a * 0.31830987f;
}

static inline math::vector_xyzw scaled(const math::vector_xyzw &v, float s)
{
    float x_ = v.x;
    float y_ = v.y;
    float z_ = v.z;
    float w_ = v.w;
    math::vector_xyzw r;
    r.y = y_ * s;
    r.z = z_ * s;
    r.w = w_ * s;
    r.x = x_ * s;
    return r;
}

void FloatImage::blur2d(int r, float sigma)
{
    if (r == 0)
        return;
    FloatImage tmp = *this;
    for (int y = 0; y != ny(); y++)
        for (int x = 0; x != nx(); x++) {
            ABGR_FLOAT &d = tmp.addr()[x + y * nx()];
            float sum = 0;
            d = ABGR_FLOAT(sum);
            for (int j = -r; j <= r; j++) {
                int yy = y + j;
                if (yy >= 0 && yy < ny())
                    for (int i = -r; i <= r; i++) {
                        int xx = x + i;
                        if (xx >= 0 && xx < nx()) {
                            float w = gaussian2(sqrtf(i * i + j * j), sigma);
                            sum += w;
                            d += scaled(addr()[xx + yy * nx()], w);
                        }
                    }
            }
            d *= 1.0f / sum;
        }
    *this = tmp;
}

void FloatImage::blur(int r, float sigma)
{
    if (r == 0)
        return;
    FloatImage tmp = *this;
    for (int y = 0; y != ny(); y++)
        for (int x = 0; x != nx(); x++) {
            ABGR_FLOAT &d = tmp.addr()[x + y * nx()];
            float sum = 0;
            d = ABGR_FLOAT(sum);
            for (int i = -r; i <= r; i++) {
                int xx = x + i;
                if (xx >= 0 && xx < nx()) {
                    float w = gaussian1(sqrtf(i * i), sigma);
                    sum += w;
                    d += scaled(addr()[xx + y * nx()], w);
                }
            }
            d *= 1.0f / sum;
        }
    FloatImage tmp2 = tmp;
    for (int x = 0; x != nx(); x++)
        for (int y = 0; y != ny(); y++) {
            ABGR_FLOAT &d = tmp2.addr()[x + y * nx()];
            float sum = 0;
            d = ABGR_FLOAT(sum);
            for (int j = -r; j <= r; j++) {
                int yy = y + j;
                if (yy >= 0 && yy < ny()) {
                    float w = gaussian1(sqrtf(j * j), sigma);
                    sum += w;
                    d += scaled(tmp2.addr()[x + yy * nx()], w);
                }
            }
            d *= 1.0f / sum;
        }
    tmp2 *= 1.9f;
    *this = tmp2;
}
