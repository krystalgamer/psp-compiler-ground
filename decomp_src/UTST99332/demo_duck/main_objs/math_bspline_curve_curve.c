/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* the strings stay in the module's .rodata (asm) */
extern const char D_0016875C[];     /* "can't have cubic bsplines with less than 4 control points" */
extern const char D_00168798[];     /* "../lib/maths/bspline.cpp" */
extern const char D_001687B4[];     /* " *** error " */
extern const char D_001687C0[];     /* "_Num >= 4" */
extern const char curve_setCtrl_name[] __asm__("_ZZN4math7bspline5curve7setCtrlEPNS_11vector_xyzwEiE19__PRETTY_FUNCTION__");
#define BS_ASSERT(c, s, name, line, msg) \
    if (!(c)) { \
        common::common_internal::assert_display(D_001687B4, s, D_00168798, name, line, msg); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_bspline_curve_curve", _Z41__static_initialization_and_destruction_0ii_50C2C);

math::bspline::curve::curve() : _Num(0), _Ctrl(0)
{
}

void math::bspline::curve::setCtrl(vector_xyzw *ctrl, int n)
{
    BS_ASSERT(n >= 4, D_001687C0, curve_setCtrl_name, 33, D_0016875C);
    _Ctrl = ctrl;
    _Num = n;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline5curve9localEvalERNS_11vector_xyzwEf);

common::t_array2d<math::vector_xyzw> *math::bspline::surface::net()
{
    return _f0;
}

void *math::bspline::surface::ctrlnet()
{
    return &_f4;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline7surface7setTypeEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline7surfaceC2Eiii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline7surfaceC1Eiii);

void math::bspline::surface::setNet(common::t_array2d<vector_xyzw> *net)
{
    _f0 = net;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline7surface10globalEvalEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline7surface9localEvalERNS_11vector_xyzwEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline7surface9localEvalERNS_11vector_xyzwES3_S3_S3_ff);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_50C2C");
void _GLOBAL__I__ZN4math7bspline5curveC2Ev(void);
}

void _GLOBAL__I__ZN4math7bspline5curveC2Ev(void)
{
    static_init(1, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_bspline_curve_curve", _ZN6common9t_array2dIN4math11vector_xyzwEEC1Ejj);

