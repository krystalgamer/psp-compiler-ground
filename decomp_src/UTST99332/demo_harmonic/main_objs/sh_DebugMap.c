/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define SGL_LINKONCE_DebugMap 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZNK2sh8DebugMap4evalEffRfS1_S1_");
__asm__(".globl _GLOBAL__D__ZNK2sh8DebugMap4evalEffRfS1_S1_");

void sh::DebugMap::eval(float theta, float phi, float &r, float &g, float &b) const
{
    static const sgl::Color n[6] = {
        sgl::Color(1, 0, 0, 0), sgl::Color(-1, 0, 0, 0),
        sgl::Color(0, 1, 0, 0), sgl::Color(0, -1, 0, 0),
        sgl::Color(0, 0, 1, 0), sgl::Color(0, 0, -1, 0),
    };
    static const sgl::Color P[6] = {
        sgl::Color(1, 0, 0, 1), sgl::Color(-1, 0, 0, 1),
        sgl::Color(0, 1, 0, 1), sgl::Color(0, -1, 0, 1),
        sgl::Color(0, 0, 1, 1), sgl::Color(0, 0, -1, 1),
    };
    math::SphericalCoord sc(theta, phi);
    float tmin = 1000;
    for (unsigned int i = 0; i < 6; i++) {
        const float *p = P[i].c, *q = n[i].c;
        float t = (p[0] * q[0] + p[1] * q[1] + p[2] * q[2] + p[3] * q[3]) / (p[0] * sc._dir.x + p[1] * sc._dir.y + p[2] * sc._dir.z + p[3] * sc._dir.w);
        if (0 < t && t < tmin) {
            tmin = t;
            const sgl::Color &c = _colors[i];
            r = c.c[0];
            g = c.c[1];
            b = c.c[2];
        }
    }
}

/* inline members: .gnu.linkonce.t, after DebugMap's (splat only sees `INCLUDE_ASM(`) */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_DebugMap", _ZN2sh14SphericalRGBFnD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_DebugMap", _ZN2sh14SphericalRGBFnD0Ev);
