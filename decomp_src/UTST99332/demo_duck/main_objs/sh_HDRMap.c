/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SGL_LINKONCE_HDRMap 1
#define DEMO_TEMPLATE_DEFS 1
#include "../main.hpp"
namespace math {
template<class T> T min_(T, T);
}


INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _Z41__static_initialization_and_destruction_0ii_DAD48);

sh::HDRMap::HDRMap(const char *name, float exposure) : _exposure(exposure), _name(name)
{
    load();
}


float sh::HDRMap::convert01f(float v) const
{
    float t = (v - _min) / (_max - _min);
    if (t > 1)
        t = 1;
    if (t < 0)
        t = 0;
    return t;
}

unsigned int sh::HDRMap::convert0i(float v, unsigned int n) const
{
    unsigned int m = n - 1;
    unsigned int r = (unsigned int)(m * convert01f(v));
    if (r >= n)
        r = m;
    return r;
}

unsigned int sh::HDRMap::convert255(float v) const
{
    return (unsigned int)((1 - expf(-_exposure * v)) * 255);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZN2sh6HDRMap4loadEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZN2sh6HDRMap22save_vert_distributionEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZN2sh6HDRMap4saveEPKc);

void sh::HDRMap::getUVf(float u, float v, float &r, float &g, float &b) const
{
    if (_img.empty())
        return;
    unsigned int nx = _img.nx();
    unsigned int ny = _img.ny();
    unsigned int x = math::min_(nx - 1, (unsigned int)((u + 1) * 0.5f * nx));
    unsigned int y = math::min_(ny - 1, (unsigned int)((1 - v) * 0.5f * ny));
    const ABGR_FLOAT &c = _img.addr()[x + y * nx];
    /* the original calls getUVf (never inlined): its body counts >= 12 more statements (GCC 3.3 -O3 inline limit) */
    ((void)0); ((void)0); ((void)0); ((void)0); ((void)0); ((void)0); ((void)0); ((void)0); ((void)0); ((void)0); ((void)0); ((void)0);
    r = c.x;
    g = c.y;
    b = c.z;
}

void sh::HDRMap::getUVuc(float u, float v, unsigned char &r, unsigned char &g, unsigned char &b) const
{
    if (_img.empty())
        return;
    float fr, fg, fb;
    getUVf(u, v, fr, fg, fb);
    r = convert255(fr);
    g = convert255(fg);
    b = convert255(fb);
}

void sh::HDRMap::getThetaPhif(float theta, float phi, float &r, float &g, float &b) const
{
    math::SphericalCoord sc(theta, phi);
    getDf(sc._dir, r, g, b);
}

void sh::HDRMap::getThetaPhiuc(float theta, float phi, unsigned char &r, unsigned char &g, unsigned char &b) const
{
    math::SphericalCoord sc(theta, phi);
    getDuc(sc._dir, r, g, b);
}

void sh::HDRMap::getDf(math::vector_xyzw d, float &r, float &g, float &b) const
{
    float a = acosf(d.z) * 0.31830988618f;
    float l = sqrtf(d.x * d.x + d.y * d.y);
    float k = a / l;
    getUVf(d.x * k, d.y * k, r, g, b);
}

void sh::HDRMap::getDuc(math::vector_xyzw d, unsigned char &r, unsigned char &g, unsigned char &b) const
{
    float a = acosf(d.z) * 0.31830988618f;
    float l = sqrtf(d.x * d.x + d.y * d.y);
    float k = a / l;
    getUVuc(d.x * k, d.y * k, r, g, b);
}

void sh::HDRMap::eval(float theta, float phi, float &r, float &g, float &b) const
{
    if (_img.empty())
        return;
    unsigned char c[3];
    getThetaPhiuc(theta, phi, c[0], c[1], c[2]);
    r = c[0] * (1.0f / 255);
    g = c[1] * (1.0f / 255);
    b = c[2] * (1.0f / 255);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_DAD48");
void _GLOBAL__I__ZN2sh6HDRMapC2EPKcf(void);
void _GLOBAL__D__ZN2sh6HDRMapC2EPKcf(void);
}

void _GLOBAL__I__ZN2sh6HDRMapC2EPKcf(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN2sh6HDRMapC2EPKcf(void)
{
    static_init(0, 0xFFFF);
}

/* the original's .gnu.linkonce.t order */
DEMO_LINKONCE_ORDER(DEMO_LINKONCE(_ZN2sh6HDRMapD1Ev)
                    DEMO_LINKONCE(_ZN2sh6HDRMapD0Ev)
                    DEMO_LINKONCE(_ZNK6common9t_array2dI10ABGR_FLOATE2nxEv)
                    DEMO_LINKONCE(_ZNK6common9t_array2dI10ABGR_FLOATE2nyEv)
                    DEMO_LINKONCE(_ZN6common9t_array2dI10ABGR_FLOATED2Ev)
                    DEMO_LINKONCE(_ZN6common9t_array2dI10ABGR_FLOATE6resizeEjj)
                    DEMO_LINKONCE(_ZN6common7t_arrayI10ABGR_FLOATE4addrEv)
                    DEMO_LINKONCE(_ZNK6common7t_arrayI10ABGR_FLOATE5emptyEv)
                    DEMO_LINKONCE(_ZN4math4min_IjEET_S1_S1_)
                    DEMO_LINKONCE(_ZNK6common7t_arrayI10ABGR_FLOATE4addrEv)
                    DEMO_LINKONCE(_ZN6common7t_arrayI10ABGR_FLOATED2Ev)
                    DEMO_LINKONCE(_ZN6common7t_arrayI10ABGR_FLOATE6resizeEj)
                    DEMO_LINKONCE(_ZN6common7t_arrayI10ABGR_FLOATE7releaseEv)
                    DEMO_LINKONCE(_ZN6common7t_arrayI10ABGR_FLOATE8allocateEj)
                    DEMO_LINKONCE(_ZN10FloatImageD0Ev)
                    DEMO_LINKONCE(_ZN10FloatImageD1Ev)
                    DEMO_LINKONCE(_ZN6common9t_array2dI10ABGR_FLOATED1Ev)
                    DEMO_LINKONCE(_ZN6common9t_array2dI10ABGR_FLOATED0Ev)
                    DEMO_LINKONCE(_ZN6common7t_arrayI10ABGR_FLOATED1Ev)
                    DEMO_LINKONCE(_ZN6common7t_arrayI10ABGR_FLOATED0Ev)
                    DEMO_LINKONCE(_ZN6common7t_arrayI10ABGR_FLOATE4swapERS2_)
                    DEMO_LINKONCE(_ZN6common9t_array2dI10ABGR_FLOATE7releaseEv)
                    DEMO_LINKONCE(_ZN6common7t_arrayI10ABGR_FLOATE4fillERKS1_)
                    DEMO_LINKONCE(_ZN6common9t_array2dI10ABGR_FLOATE4swapERS2_)
                    DEMO_LINKONCE(_ZN6common9t_array2dI10ABGR_FLOATE7resizexEj)
                    DEMO_LINKONCE(_ZN6common9t_array2dI10ABGR_FLOATE7resizeyEj)
                    DEMO_LINKONCE(_ZN6common9t_array2dI10ABGR_FLOATE4copyERKS2_iiiiii)
                    DEMO_LINKONCE(_ZN6common4SwapINS_7t_arrayI10ABGR_FLOATE7MembersEEEvRT_S6_)
                    DEMO_LINKONCE(_ZN6common4SwapINS_9t_array2dI10ABGR_FLOATE3DimEEEvRT_S6_)
                    DEMO_LINKONCE(_ZN6common9t_array2dI10ABGR_FLOATE2atEii)
                    DEMO_LINKONCE(_ZNK6common9t_array2dI10ABGR_FLOATE2atEii));
/* t_array<ABGR_FLOAT>'s D0 (called by its vtable in the original) */
extern "C" void t_array_ABGR_FLOAT_D0(void *) __asm__("_ZN6common7t_arrayI10ABGR_FLOATED0Ev");
extern "C" void t_array2d_ABGR_FLOAT_D0(void *) __asm__("_ZN6common9t_array2dI10ABGR_FLOATED0Ev");

extern "C" void sh_HDRMap_instances(FloatImage *img, const ABGR_FLOAT *c, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void sh_HDRMap_instances(FloatImage *img, const ABGR_FLOAT *c, unsigned int n)
{
    typedef common::t_array<ABGR_FLOAT> A;
    typedef common::t_array2d<ABGR_FLOAT> A2;
    const FloatImage *ci = img;
    img->nx();
    img->ny();
    img->A2::resize(n, n);
    img->addr();
    img->empty();
    math::min_(n, n);
    ci->addr();
    img->A::resize(n);
    img->A::release();
    img->allocate(n);
    img->A2::~A2();
    t_array2d_ABGR_FLOAT_D0(img);
    img->A::~A();
    t_array_ABGR_FLOAT_D0(img);
    img->A::swap(*img);
    img->A2::release();
    img->A::fill(*c);
    img->A2::swap(*img);
    img->A2::resizex(n);
    img->A2::resizey(n);
    img->A2::copy(*img, n, n, n, n, n, n);
    img->at(n, n);
    ci->at(n, n);
}

namespace math {
template<class T> T min_(T a, T b)
{
    return a < b ? a : b;
}
}
