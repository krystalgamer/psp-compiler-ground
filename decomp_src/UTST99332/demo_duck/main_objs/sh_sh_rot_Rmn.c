/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN2sh6sh_rot3RmnE\n_GLOBAL__I__ZN2sh6sh_rot3RmnE = _GLOBAL__I__ZN2sh6sh_rot6setRmnEN4math6matrixE");
__asm__(".globl _GLOBAL__D__ZN2sh6sh_rot3RmnE\n_GLOBAL__D__ZN2sh6sh_rot3RmnE = _GLOBAL__D__ZN2sh6sh_rot6setRmnEN4math6matrixE");

extern const char D_00173888[];     /* " *** error " */
extern const char D_00173894[];     /* "../lib/sh/Rotation.cpp" */
extern const char D_001738AC[];     /* " " */
extern const char D_001738B0[];     /* "i == -1 || i == 0 || i == 1" */
extern const char D_001738CC[];     /* "j == -1 || j == 0 || j == 1" */
extern const char D_0017398C[];     /* "not defined" */
extern const char D_00173998[];     /* "" */
extern const char W_name[] __asm__("_ZZN2sh6sh_rot1WEiiiRNS_9RotMatrixEE19__PRETTY_FUNCTION__");
extern const char R_name[] __asm__("_ZZN2sh6sh_rot1REiiE19__PRETTY_FUNCTION__");
extern int setRmn_P[3] __asm__("_ZZN2sh6sh_rot6setRmnEN4math6matrixEE1P");

void sh::sh_rot::setRmn(math::matrix m)
{
    float r[3][3];
    r[0][0] = m.r[0].x;
    r[0][1] = m.r[1].x;
    r[0][2] = m.r[2].x;
    r[1][0] = m.r[0].y;
    r[1][1] = m.r[1].y;
    r[1][2] = m.r[2].y;
    r[2][0] = m.r[0].z;
    r[2][1] = m.r[1].z;
    r[2][2] = m.r[2].z;
    for (int i = 0; i != 3; i++)
        for (int j = 0; j != 3; j++)
            Rmn[j][i] = r[setRmn_P[j]][setRmn_P[i]];
}

float sh::sh_rot::R(int i, int j)
{
    SGL_ASSERT(i == -1 || i == 0 || i == 1, D_00173888, D_001738B0, D_00173894, R_name, 70, D_001738AC);
    SGL_ASSERT(j == -1 || j == 0 || j == 1, D_00173888, D_001738CC, D_00173894, R_name, 71, D_001738AC);
    return Rmn[i + 1][j + 1];
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_sh_rot_Rmn", _ZN2sh6sh_rot1PEiiiiRNS_9RotMatrixE);

float sh::sh_rot::U(int l, int m, int n, RotMatrix &r)
{
    return P(0, l, m, n, r);
}

extern const float D_00173838;
float sh::sh_rot::V(int l, int m, int n, RotMatrix &r)
{
    if (m == 0)
        return P(1, l, 1, n, r) + P(-1, l, -1, n, r);
    if (m > 0) {
        float d = m == 1 ? D_00173838 : 0;
        return P(1, l, m - 1, n, r) * math::safe_sqrtf(d + D_00173838) - P(-1, l, -m + 1, n, r) * (D_00173838 - d);
    }
    float d = m == -1 ? D_00173838 : 0;
    return P(1, l, m + 1, n, r) * (d + D_00173838) + P(-1, l, -m - 1, n, r) * math::safe_sqrtf(D_00173838 - d);
}

float sh::sh_rot::W(int l, int m, int n, RotMatrix &r)
{
    if (m == 0) {
        SGL_ASSERT(false, D_00173888, D_00173998, D_00173894, W_name, 128, D_0017398C);
        return 0;
    }
    if (m > 0)
        return P(1, l, m + 1, n, r) + P(-1, l, -m - 1, n, r);
    return P(1, l, m - 1, n, r) - P(-1, l, -m + 1, n, r);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_sh_rot_Rmn", _ZN2sh6sh_rot3uvwERfS1_S1_iii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_sh_rot_Rmn", _ZN2sh6sh_rot1MEiiiRNS_9RotMatrixE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_sh_rot_Rmn", _ZN2sh9RotMatrix8TwoBandsEN4math6matrixE);

sh::RotMatrix::RotMatrix()
{
}

sh::RotMatrix::RotMatrix(math::matrix m)
{
    m.r[3].x = 0;
    m.r[3].y = 0;
    m.r[3].z = 0;
    *this = TwoBands(m);
}

float sh::RotMatrix::at(int l, int a, int b) const
{
    int o = l * (l + 1);
    return m[o + a][o + b];
}

sh::RotMatrix &sh::RotMatrix::operator=(const Matrix &o)
{
    Matrix::operator=(o);
    return *this;
}

sh::Vector sh::RotMatrix::operator*(const Vector &v) const
{
    Vector r;
    for (int l = 0; l < BANDS; l++) {
        for (int a = -l; a <= l; a++) {
            int i = l * (l + 1) + a;
            r[i] = 0;
            for (int b = -l; b <= l; b++)
                r[i] += v[l * (l + 1) + b] * at(l, a, b);
        }
    }
    return r;
}

sh::VectorRGB sh::RotMatrix::operator*(const VectorRGB &v) const
{
    return VectorRGB(*this * v.r, *this * v.g, *this * v.b);
}
