/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
/* the constants stay in the module's .rodata (asm) */
extern const float D_00163D90;      /* 1.0f: reset()'s matrix::Identity() */
#define MATH_IDENTITY_ONE D_00163D90
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_Trackball", _Z41__static_initialization_and_destruction_0ii_32AA0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_Trackball", _ZN4math9TrackballC2ERKNS_6matrixE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_Trackball", _ZN4math9TrackballC1ERKNS_6matrixE);

void math::Trackball::mode(math::Trackball::Mode v)
{
    _f90 = v;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_Trackball", _ZN4math9Trackball5trackERNS_6matrixEffbb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_Trackball", _ZN4math9Trackball5trackEffbb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_Trackball", _ZN4math9Trackball5trackEffbbNS_6matrixE);

void math::Trackball::reset()
{
    *this = Trackball(matrix::Identity());
}

const math::matrix &math::Trackball::getTransform() const
{
    return _transform;
}

const math::matrix &math::Trackball::getDeltaRot() const
{
    return _deltaRot;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_32AA0");
void _GLOBAL__I__ZN4math9TrackballC2ERKNS_6matrixE(void);
void _GLOBAL__D__ZN4math9TrackballC2ERKNS_6matrixE(void);
}

void _GLOBAL__I__ZN4math9TrackballC2ERKNS_6matrixE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN4math9TrackballC2ERKNS_6matrixE(void)
{
    static_init(0, 0xFFFF);
}

