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
extern const char D_0016583C[];     /* "can't have cubic bsplines with less than 4 control points" */
extern const char D_00165878[];     /* "../lib/maths/bspline.cpp" */
extern const char D_00165894[];     /* " *** error " */
extern const char D_001658A0[];     /* "_Num >= 4" */
extern const char curve_setCtrl_name[] __asm__("_ZZN4math7bspline5curve7setCtrlEPNS_11vector_xyzwEiE19__PRETTY_FUNCTION__");
#define BS_ASSERT(c, s, name, line, msg) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00165894, s, D_00165878, name, line, msg); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

math::bspline::curve::curve() : _Num(0), _Ctrl(0)
{
}

void math::bspline::curve::setCtrl(vector_xyzw *ctrl, int n)
{
    BS_ASSERT(n >= 4, D_001658A0, curve_setCtrl_name, 33, D_0016583C);
    _Ctrl = ctrl;
    _Num = n;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline5curve9localEvalERNS_11vector_xyzwEf);

common::t_array2d<math::vector_xyzw> *math::bspline::surface::net()
{
    return _f0;
}

void *math::bspline::surface::ctrlnet()
{
    return &_f4;
}

void math::bspline::surface::setType(int type)
{
    int nx = _f4.nx();
    int ny = _f4.ny();
    vector_xyzw *p = _f4.addr();
    for (int j = 0; j < ny; j++)
        for (int i = 0; i < nx; i++, p++)
            *p = vector_xyzw(i - nx * 0.5f, j - ny * 0.5f, 0, 1.0f);
    p = _f4.addr();
    for (int j = 0; j < ny; j++)
        for (int i = 0; i < nx; i++, p++) {
            p->z = 0;
            switch (type) {
            case 2:
                break;
            case 3:
                p->z = 2 * sinf(i * 3.14159265f / (nx - 1)) * sinf(j * 3.14159265f / (ny - 1));
                break;
            case 4:
                p->z = sinf(i * 3.0f * 3.14159265f / (nx - 1)) * sinf(j * 3.0f * 3.14159265f / (ny - 1)) + 1;
                break;
            }
            if (i >= 3 && i <= nx - 4 && j >= 3 && j <= ny - 4) {
                switch (type) {
                case 1:
                    p->z = -5;
                    break;
                case 2:
                    p->z = 5 * sinf(i * 3.14159265f / (nx - 1)) * sinf(j * 3.14159265f / (ny - 1));
                    break;
                }
            }
        }
}

extern const char D_00165894[], D_001658DC[], D_00165878[], D_001658E8[], D_0016592C[], D_00165938[];
extern const char surface_name[] __asm__("_ZZN4math7bspline7surfaceC1EiiiE19__PRETTY_FUNCTION__");
math::bspline::surface::surface(int ctrlx, int ctrly, int type) : _f0(0), _f4(ctrlx, ctrly)
{
    SGL_ASSERT(ctrlx >= 4, D_00165894, D_001658DC, D_00165878, surface_name, 145, D_001658E8);
    SGL_ASSERT(ctrly >= 4, D_00165894, D_0016592C, D_00165878, surface_name, 146, D_00165938);
    setType(type);
}

void math::bspline::surface::setNet(common::t_array2d<vector_xyzw> *net)
{
    _f0 = net;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline7surface10globalEvalEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline7surface9localEvalERNS_11vector_xyzwEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_bspline_curve_curve", _ZN4math7bspline7surface9localEvalERNS_11vector_xyzwES3_S3_S3_ff);

/* the object's own instance (math_bspline_surface's ctor uses it; basic_net holds the rest of t_array2d<vector_xyzw>) */
template common::t_array2d<math::vector_xyzw>::t_array2d(unsigned int, unsigned int);
