/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN4math7bspline5curveC2Ev");

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

extern const char D_001687B4[], D_001687FC[], D_00168798[], D_00168808[], D_0016884C[], D_00168858[];
extern const char surface_name[] __asm__("_ZZN4math7bspline7surfaceC1EiiiE19__PRETTY_FUNCTION__");
math::bspline::surface::surface(int ctrlx, int ctrly, int type) : _f0(0), _f4(ctrlx, ctrly)
{
    SGL_ASSERT(ctrlx >= 4, D_001687B4, D_001687FC, D_00168798, surface_name, 145, D_00168808);
    SGL_ASSERT(ctrly >= 4, D_001687B4, D_0016884C, D_00168798, surface_name, 146, D_00168858);
    setType(type);
}

void math::bspline::surface::setNet(common::t_array2d<vector_xyzw> *net)
{
    _f0 = net;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline7surface10globalEvalEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline7surface9localEvalERNS_11vector_xyzwEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline7surface9localEvalERNS_11vector_xyzwES3_S3_S3_ff);

/* the object's own instance (math_bspline_surface's ctor uses it; basic_net holds the rest of t_array2d<vector_xyzw>) */
template common::t_array2d<math::vector_xyzw>::t_array2d(unsigned int, unsigned int);
