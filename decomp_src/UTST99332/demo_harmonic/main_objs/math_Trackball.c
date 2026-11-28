/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN4math9TrackballC2ERKNS_6matrixE\n_GLOBAL__I__ZN4math9TrackballC2ERKNS_6matrixE = _GLOBAL__I__ZN4math9TrackballC2ERKNS_6matrixE__asm");
__asm__(".globl _GLOBAL__D__ZN4math9TrackballC2ERKNS_6matrixE\n_GLOBAL__D__ZN4math9TrackballC2ERKNS_6matrixE = _GLOBAL__D__ZN4math9TrackballC2ERKNS_6matrixE__asm");

math::Trackball::Trackball(const matrix &m) : _transform(m), _f90(0)
{
    _transform[3][0] = 0;
    _transform[3][1] = 0;
    _transform[3][2] = 0;
}

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
