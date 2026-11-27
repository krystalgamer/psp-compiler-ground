/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SGL_LINKONCE_HDRMap 1
#define DEMO_TEMPLATE_DEFS 1
#include "../main.hpp"

extern const float D_0017251C;      /* 1 */

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _Z41__static_initialization_and_destruction_0ii_DAD48);

sh::HDRMap::HDRMap(const char *name, float exposure) : _exposure(exposure), _name(name)
{
    load();
}


float sh::HDRMap::convert01f(float v) const
{
    float t = (v - _min) / (_max - _min);
    if (t > D_0017251C)
        t = D_0017251C;
    if (t < 0)
        t = 0;
    return t;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap9convert0iEfj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap10convert255Ef);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZN2sh6HDRMap4loadEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZN2sh6HDRMap22save_vert_distributionEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZN2sh6HDRMap4saveEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap6getUVfEffRfS1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap7getUVucEffRhS1_S1_);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap5getDfEN4math11vector_xyzwERfS3_S3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap6getDucEN4math11vector_xyzwERhS3_S3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap4evalEffRfS1_S1_);

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
namespace math {
template<class T> T min_(T, T);
}
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
