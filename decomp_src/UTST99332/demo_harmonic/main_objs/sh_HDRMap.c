/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define basic_parser basic_parser_base_hpp
#define basic_file_parser basic_file_parser_base_hpp
#include "../main.hpp"
#undef basic_parser
#undef basic_file_parser
#include "../../demo_duck/demo/parser.hpp"
#include "../../demo_duck/demo/sgl.hpp"

extern const float D_0016F5F4;      /* 1 */

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _Z41__static_initialization_and_destruction_0ii_D8964);

sh::HDRMap::HDRMap(const char *name, float exposure) : _exposure(exposure), _name(name)
{
    load();
}


float sh::HDRMap::convert01f(float v) const
{
    float t = (v - _min) / (_max - _min);
    if (t > D_0016F5F4)
        t = D_0016F5F4;
    if (t < 0)
        t = 0;
    return t;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap9convert0iEfj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap10convert255Ef);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN2sh6HDRMap4loadEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN2sh6HDRMap22save_vert_distributionEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN2sh6HDRMap4saveEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap6getUVfEffRfS1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap7getUVucEffRhS1_S1_);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap5getDfEN4math11vector_xyzwERfS3_S3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap6getDucEN4math11vector_xyzwERhS3_S3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZNK2sh6HDRMap4evalEffRfS1_S1_);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_D8964");
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN2sh6HDRMapD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN2sh6HDRMapD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZNK6common9t_array2dI10ABGR_FLOATE2nxEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZNK6common9t_array2dI10ABGR_FLOATE2nyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common9t_array2dI10ABGR_FLOATED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common9t_array2dI10ABGR_FLOATE6resizeEjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common7t_arrayI10ABGR_FLOATE4addrEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZNK6common7t_arrayI10ABGR_FLOATE5emptyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN4math4min_IjEET_S1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZNK6common7t_arrayI10ABGR_FLOATE4addrEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common7t_arrayI10ABGR_FLOATED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common7t_arrayI10ABGR_FLOATE6resizeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common7t_arrayI10ABGR_FLOATE7releaseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common7t_arrayI10ABGR_FLOATE8allocateEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN10FloatImageD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN10FloatImageD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common9t_array2dI10ABGR_FLOATED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common9t_array2dI10ABGR_FLOATED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common7t_arrayI10ABGR_FLOATED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common7t_arrayI10ABGR_FLOATED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common7t_arrayI10ABGR_FLOATE4swapERS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common9t_array2dI10ABGR_FLOATE7releaseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common7t_arrayI10ABGR_FLOATE4fillERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common9t_array2dI10ABGR_FLOATE4swapERS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common9t_array2dI10ABGR_FLOATE7resizexEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common9t_array2dI10ABGR_FLOATE7resizeyEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common9t_array2dI10ABGR_FLOATE4copyERKS2_iiiiii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common4SwapINS_7t_arrayI10ABGR_FLOATE7MembersEEEvRT_S6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common4SwapINS_9t_array2dI10ABGR_FLOATE3DimEEEvRT_S6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZN6common9t_array2dI10ABGR_FLOATE2atEii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_HDRMap", _ZNK6common9t_array2dI10ABGR_FLOATE2atEii);

