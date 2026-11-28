/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN2sh6sh_rot3RmnE\n_GLOBAL__I__ZN2sh6sh_rot3RmnE = _GLOBAL__I__ZN2sh6sh_rot6setRmnEN4math6matrixE");
__asm__(".globl _GLOBAL__D__ZN2sh6sh_rot3RmnE\n_GLOBAL__D__ZN2sh6sh_rot3RmnE = _GLOBAL__D__ZN2sh6sh_rot6setRmnEN4math6matrixE");


void sh::sh_rot::setRmn(math::matrix m)
{
    static const int P[3] = { 1, 2, 0 };
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
            Rmn[j][i] = r[P[j]][P[i]];
}

float sh::sh_rot::R(int i, int j)
{
    SGL_ASSERT(i == -1 || i == 0 || i == 1, " *** error ", "i == -1 || i == 0 || i == 1", "../lib/sh/Rotation.cpp", __PRETTY_FUNCTION__, 70, " ");
    SGL_ASSERT(j == -1 || j == 0 || j == 1, " *** error ", "j == -1 || j == 0 || j == 1", "../lib/sh/Rotation.cpp", __PRETTY_FUNCTION__, 71, " ");
    return Rmn[i + 1][j + 1];
}

#define ROT_ABS(b) ((b) < 0 ? -(b) : (b))
float sh::sh_rot::P(int i, int l, int a, int b, RotMatrix &r)
{
    SGL_ASSERT(l >= 1, " *** error ", "l >= 1", "../lib/sh/Rotation.cpp", __PRETTY_FUNCTION__, 78, " ");
    SGL_ASSERT(ROT_ABS(b) <= l, " *** error ", "( b < 0 ? -b : b ) <= l", "../lib/sh/Rotation.cpp", __PRETTY_FUNCTION__, 79, " ");
    if (b == l)
        return r.at(l - 1, a, l - 1) * R(i, 1) - r.at(l - 1, a, -l + 1) * R(i, -1);
    if (b == -l)
        return r.at(l - 1, a, -l + 1) * R(i, 1) + r.at(l - 1, a, l - 1) * R(i, -1);
    SGL_ASSERT(ROT_ABS(b) < l, " *** error ", "( b < 0 ? -b : b ) < l", "../lib/sh/Rotation.cpp", __PRETTY_FUNCTION__, 91, " ");
    return R(i, 0) * r.at(l - 1, a, b);
}

float sh::sh_rot::U(int l, int m, int n, RotMatrix &r)
{
    return P(0, l, m, n, r);
}

float sh::sh_rot::V(int l, int m, int n, RotMatrix &r)
{
    float ret;
    if (m == 0) {
        float p0 = P(1, l, 1, n, r);
        float p1 = P(-1, l, -1, n, r);
        ret = p0 + p1;
    } else if (m > 0) {
        float d = m == 1 ? 1.0f : 0;
        float p0 = P(1, l, m - 1, n, r) * math::safe_sqrtf(d + 1.0f);
        float p1 = P(-1, l, -m + 1, n, r) * (1.0f - d);
        ret = p0 - p1;
    } else {
        float d = m == -1 ? 1.0f : 0;
        float p0 = P(1, l, m + 1, n, r) * (d + 1.0f);
        float p1 = P(-1, l, -m - 1, n, r) * math::safe_sqrtf(1.0f - d);
        ret = p0 + p1;
    }
    return ret;
}

float sh::sh_rot::W(int l, int m, int n, RotMatrix &r)
{
    if (m == 0) {
        SGL_ASSERT(false, " *** error ", "", "../lib/sh/Rotation.cpp", __PRETTY_FUNCTION__, 128, "not defined");
        return 0;
    }
    if (m > 0)
        return P(1, l, m + 1, n, r) + P(-1, l, -m - 1, n, r);
    return P(1, l, m - 1, n, r) - P(-1, l, -m + 1, n, r);
}

void sh::sh_rot::uvw(float &u, float &v, float &w, int l, int m, int n)
{
    SGL_ASSERT(abs(n) <= l, " *** error ", "abs(n) <= l", "../lib/sh/Rotation.cpp", __PRETTY_FUNCTION__, 144, " ");
    int am = abs(m);
    float b = (l + am - 1.0f) * (l + am);
    float d = m == 0 ? 1.0f : 0;
    bool e = abs(n) == l;
    float den = e ? 2.0f * l * (2.0f * l - 1.0f) : (l + n) * (l - n);
    u = math::safe_sqrtf((l + m) * (l - m) / den);
    v = (1.0f - 2 * d) * 0.5f * math::safe_sqrtf((1.0f + d) * b / den);
    w = (1.0f - d) * -0.5f * math::safe_sqrtf((e ? b : (l - am - 1.0f) * (l - am)) / den);
}

float sh::sh_rot::M(int l, int m, int n, RotMatrix &r)
{
    SGL_ASSERT(l >= 0, " *** error ", "l >= 0", "../lib/sh/Rotation.cpp", __PRETTY_FUNCTION__, 163, " ");
    SGL_ASSERT(abs(m) <= l, " *** error ", "abs(m) <= l", "../lib/sh/Rotation.cpp", __PRETTY_FUNCTION__, 164, " ");
    SGL_ASSERT(abs(n) <= l, " *** error ", "abs(n) <= l", "../lib/sh/Rotation.cpp", __PRETTY_FUNCTION__, 165, " ");
    float u, v, w;
    uvw(u, v, w, l, m, n);
    return u * U(l, m, n, r) + v * V(l, m, n, r) + w * V(l, m, n, r);
}

extern "C" float atan2f(float, float);
sh::RotMatrix sh::RotMatrix::TwoBands(math::matrix m)
{
    /* STAND-IN: an always-true check whose __PRETTY_FUNCTION__ survives in .rodata (its strings do not) */
    SGL_ASSERT(true, " *** error ", "", "../lib/sh/Rotation.cpp", __PRETTY_FUNCTION__, 0, " ");
    math::matrix t = m.transpose();
    float r[3][3];
    r[0][0] = t.r[0].x;
    r[0][1] = t.r[1].x;
    r[0][2] = t.r[2].x;
    r[1][0] = t.r[0].y;
    r[1][1] = t.r[1].y;
    r[1][2] = t.r[2].y;
    r[2][0] = t.r[0].z;
    r[2][1] = t.r[1].z;
    r[2][2] = t.r[2].z;
    float cb = r[2][2];
    float ca = 1.0f;
    float sb = math::safe_sqrtf(ca - cb * cb);
    float sa, sg, cg;
    if (fabsf(sb) > 0.001f) {
        float isb = ca / sb;
        cg = r[2][0] * isb;
        sg = r[2][1] * isb;
        ca = -r[0][2] * isb;
        sa = r[1][2] * isb;
    } else {
        cg = r[1][1];
        sa = 0;
        sg = -r[1][0];
    }
    RotMatrix R;
    sb = -sb;
    R.m[0][0] = 1.0f;
    R.m[0][1] = 0;
    R.m[0][2] = 0;
    R.m[0][3] = 0;
    R.m[1][0] = 0;
    R.m[1][1] = cg * ca - sg * sa * cb;
    R.m[1][2] = sg * sb;
    R.m[1][3] = cg * sa + sg * ca * cb;
    R.m[2][0] = 0;
    R.m[2][1] = sa * sb;
    R.m[2][2] = cb;
    R.m[2][3] = -ca * sb;
    R.m[3][0] = 0;
    R.m[3][1] = -cg * sa * cb - sg * ca;
    R.m[3][2] = cg * sb;
    R.m[3][3] = cg * ca * cb - sg * sa;
    R._f40 = atan2f(sg, cg);
    R._f44 = atan2f(sb, cb);
    R._f48 = atan2f(sa, ca);
    return R;
}

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
