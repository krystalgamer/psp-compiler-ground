/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
/* Identity()'s 1.0f stays in the module's .rodata (asm) */
extern const float D_00165CCC;
#define MATH_IDENTITY_ONE D_00165CCC
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN4math6matrixC2ERKNS_10quaternionE");
__asm__(".globl _GLOBAL__D__ZN4math6matrixC2ERKNS_10quaternionE");

/* float constants stay in the module's .rodata (asm) */
extern const float D_00165C78;      /* 1 */
extern const float D_00165C7C;      /* 1 */
extern const float D_00165C80;      /* 1 */
extern const float D_00165C84;      /* 1 */
extern const float D_00165C88;      /* 1 */
extern const float D_00165C8C;      /* 1 */
extern const float D_00165C98;      /* pi / 180 */
extern const float D_00165C9C;      /* 0.5 */
extern const float D_00165CA0;      /* 1 */
extern const float D_00165CA4;      /* -1 */
extern const float D_00165CA8;      /* -2 */
extern const float D_00165CAC;      /* -2 */
extern const float D_00165CB0;      /* -1 */
extern const float D_00165CDC;      /* 1 */
extern const float D_00165CE0;      /* -1 */
extern const float D_00165CE4;      /* -pi / 2 */
extern const float D_00165CE8;      /* pi / 2 */
extern const float D_00165CEC, D_00165CF0, D_00165CF4, D_00165CF8, D_00165CFC, D_00165D00, D_00165D04, D_00165D08;
extern const float D_00165D0C, D_00165D10, D_00165D14, D_00165D18, D_00165D1C, D_00165D20, D_00165D24, D_00165D28;
extern const float D_00165D2C, D_00165D30, D_00165D34, D_00165D38;
extern const char D_00165D94[];     /* " *** error " */
extern const char D_00165DA0[];     /* "n != 0.f" */
extern const char D_00165DAC[];     /* "../lib/maths/matrix.cpp" */
extern const char D_00165DC4[];     /* "n should never be set to 0" */
extern const char PF_Perspective[] __asm__("_ZZN4math6matrix11PerspectiveEffffE19__PRETTY_FUNCTION__");

math::matrix::matrix(const quaternion &q)
{
    *this = q.toMatrix();
}

math::matrix math::matrix::Translation(float x, float y, float z)
{
    return matrix(vector_xyzw(D_00165C78, 0, 0, 0), vector_xyzw(0, D_00165C78, 0, 0), vector_xyzw(0, 0, D_00165C78, 0),
                  vector_xyzw(x, y, z, D_00165C78));
}

math::matrix math::matrix::Translation(const vector_xyz &v)
{
    return Translation(v.x, v.y, v.z);
}

math::matrix math::matrix::Translation(const vector_xyzw &v)
{
    return Translation(v.x, v.y, v.z);
}

math::matrix math::matrix::Scale(float x, float y, float z)
{
    return matrix(vector_xyzw(x, 0, 0, 0), vector_xyzw(0, y, 0, 0), vector_xyzw(0, 0, z, 0),
                  vector_xyzw(0, 0, 0, D_00165C7C));
}

math::matrix math::matrix::Scale(const vector_xyz &v)
{
    return Scale(v.x, v.y, v.z);
}

math::matrix math::matrix::Rotation(float a, float x, float y, float z)
{
    float s = sinf(a);
    float c = cosf(a);
    float t = D_00165C80 - c;
    float sx = s * x;
    float sy = s * y;
    float sz = s * z;
    float tx = t * x;
    float ty = t * y;
    float tz = t * z;
    return matrix(vector_xyzw(tx * x + c, ty * x + sz, tz * x - sy, 0),
                  vector_xyzw(tx * y - sz, ty * y + c, tz * y + sx, 0),
                  vector_xyzw(tx * z + sy, ty * z - sx, tz * z + c, 0),
                  vector_xyzw(0, 0, 0, D_00165C80));
}

math::matrix math::matrix::RotationX(float a)
{
    float s = sinf(a);
    float c = cosf(a);
    return matrix(vector_xyzw(D_00165C84, 0, 0, 0), vector_xyzw(0, c, s, 0), vector_xyzw(0, -s, c, 0),
                  vector_xyzw(0, 0, 0, D_00165C84));
}

math::matrix math::matrix::RotationY(float a)
{
    float s = sinf(a);
    float c = cosf(a);
    return matrix(vector_xyzw(c, 0, -s, 0), vector_xyzw(0, D_00165C88, 0, 0), vector_xyzw(s, 0, c, 0),
                  vector_xyzw(0, 0, 0, D_00165C88));
}

math::matrix math::matrix::RotationZ(float a)
{
    float s = sinf(a);
    float c = cosf(a);
    return matrix(vector_xyzw(c, s, 0, 0), vector_xyzw(-s, c, 0, 0), vector_xyzw(0, 0, D_00165C8C, 0),
                  vector_xyzw(0, 0, 0, D_00165C8C));
}

math::matrix math::matrix::Rotation(float a, const vector_xyzw &v)
{
    return Rotation(a, v.x, v.y, v.z);
}

math::matrix math::matrix::Rotation(float a, const vector_xyz &v)
{
    return Rotation(a, v.x, v.y, v.z);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix11PointNormalENS_11vector_xyzwES1_);

math::matrix math::matrix::Perspective(float fovy, float aspect, float n, float f)
{
    float c = D_00165CA0 / tanf(fovy * D_00165C98 * D_00165C9C);
    if (!(n != 0)) {
        common::common_internal::assert_display(D_00165D94, D_00165DA0, D_00165DAC, PF_Perspective, 168, D_00165DC4);
        common::common_internal::on_error();
        common::common_internal::clash();
    }
    return matrix(vector_xyzw(c / aspect, 0, 0, 0), vector_xyzw(0, c, 0, 0),
                  vector_xyzw(0, 0, -(f + n) / (f - n), D_00165CA4), vector_xyzw(0, 0, f * D_00165CA8 * n / (f - n), 0));
}

math::matrix math::matrix::Frustum(float l, float r, float b, float t, float n, float f)
{
    return matrix(vector_xyzw(2 * n / (r - l), 0, (r + l) / (r - l), 0), vector_xyzw(0, 2 * n / (t - b), (t + b) / (t - b), 0),
                  vector_xyzw(0, 0, -(f + n) / (f - n), f * D_00165CAC * n / (f - n)), vector_xyzw(0, 0, D_00165CB0, 0));
}

extern const float D_00165CB4;
extern const char D_00165E3C[], D_00165E40[];
extern const char PF_ShadowMatrix[] __asm__("_ZZN4math6matrix12ShadowMatrixENS_11vector_xyzwES1_E19__PRETTY_FUNCTION__");
math::matrix math::matrix::ShadowMatrix(vector_xyzw plane, vector_xyzw light)
{
    if (!(light.w == D_00165CB4)) {
        common::common_internal::assert_display(D_00165D94, D_00165E40, D_00165DAC, PF_ShadowMatrix, 225, D_00165E3C);
        common::common_internal::on_error();
        common::common_internal::clash();
    }
    float d = dot(plane, light);
    return matrix(vector_xyzw(d, 0, 0, 0) - light * plane.x, vector_xyzw(0, d, 0, 0) - light * plane.y,
                  vector_xyzw(0, 0, d, 0) - light * plane.z, vector_xyzw(0, 0, 0, d) - light * plane.w);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix9trackballEffbbffRNS_11vector_xyzwE);

float math::matrix::determinant3() const
{
    return (*this)[0][0] * (*this)[1][1] * (*this)[2][2] + (*this)[1][0] * (*this)[2][1] * (*this)[0][2] + (*this)[2][0] * (*this)[0][1] * (*this)[1][2]
         - (*this)[2][0] * (*this)[1][1] * (*this)[0][2] - (*this)[1][0] * (*this)[0][1] * (*this)[2][2] - (*this)[0][0] * (*this)[2][1] * (*this)[1][2];
}

math::matrix math::matrix::inverse3() const
{
    float zero = 0;
    float det = determinant3();
    if (det == zero)
        return Identity();
    det = D_00165CCC / det;
    return matrix(vector_xyzw(((*this)[1][1] * (*this)[2][2] - (*this)[2][1] * (*this)[1][2]) * det, -((*this)[0][1] * (*this)[2][2] - (*this)[2][1] * (*this)[0][2]) * det,
                              ((*this)[0][1] * (*this)[1][2] - (*this)[1][1] * (*this)[0][2]) * det, 0),
                  vector_xyzw(-((*this)[1][0] * (*this)[2][2] - (*this)[2][0] * (*this)[1][2]) * det, ((*this)[0][0] * (*this)[2][2] - (*this)[2][0] * (*this)[0][2]) * det,
                              -((*this)[0][0] * (*this)[1][2] - (*this)[1][0] * (*this)[0][2]) * det, 0),
                  vector_xyzw(((*this)[1][0] * (*this)[2][1] - (*this)[2][0] * (*this)[1][1]) * det, -((*this)[0][0] * (*this)[2][1] - (*this)[2][0] * (*this)[0][1]) * det,
                              ((*this)[0][0] * (*this)[1][1] - (*this)[1][0] * (*this)[0][1]) * det, 0),
                  vector_xyzw(0, 0, 0, D_00165CCC));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix9inverseONEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix7inverseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix9transposeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix13EulerRotationEfffNS_13RotationOrderE);

math::matrix math::matrix::EulerRotation(vector_xyz v, RotationOrder o)
{
    return EulerRotation(v.x, v.y, v.z, o);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix11eulerAnglesENS_13RotationOrderE);

math::vector_xyz math::matrix::eulerAnglesXYZ() const
{
    vector_xyz v;
    if (r[2].x < D_00165CDC) {
        float x, y;
        if (r[2].x > D_00165CE0) {
            x = safe_atan2f(-r[2].y, r[2].z);
            y = safe_asinf(r[2].x);
            v.z = safe_atan2f(-r[1].x, r[0].x);
        } else {
            x = -safe_atan2f(r[0].y, r[1].y);
            y = D_00165CE4;
            v.z = 0;
        }
        v.x = x;
        v.y = y;
    } else {
        v.x = safe_atan2f(r[0].y, r[1].y);
        v.y = D_00165CE8;
        v.z = 0;
    }
    return v;
}

math::vector_xyz math::matrix::eulerAnglesXZY() const
{
    vector_xyz v;
    float x, z;
    if (r[1].x < D_00165CEC) {
        if (r[1].x > D_00165CF0) {
            x = safe_atan2f(r[1].z, r[1].y);
            z = safe_asinf(-r[1].x);
            v.y = safe_atan2f(r[2].x, r[0].x);
            v.x = x;
            v.z = z;
        } else {
            x = safe_atan2f(r[0].z, r[2].z);
            z = D_00165CF4;
            v.x = x;
            v.z = z;
            v.y = 0;
        }
    } else {
        x = safe_atan2f(-r[0].z, r[2].z);
        z = D_00165CF8;
        v.x = x;
        v.z = z;
        v.y = 0;
    }
    return v;
}

math::vector_xyz math::matrix::eulerAnglesYXZ() const
{
    vector_xyz v;
    float y, x;
    if (r[2].y < D_00165CFC) {
        if (r[2].y > D_00165D00) {
            y = safe_atan2f(r[2].x, r[2].z);
            x = safe_asinf(-r[2].y);
            v.z = safe_atan2f(r[0].y, r[1].y);
            v.x = x;
            v.y = y;
        } else {
            y = safe_atan2f(r[1].x, r[0].x);
            x = D_00165D04;
            v.y = y;
            v.x = x;
            v.z = 0;
        }
    } else {
        y = safe_atan2f(-r[1].x, r[0].x);
        x = D_00165D08;
        v.y = y;
        v.x = x;
        v.z = 0;
    }
    return v;
}

math::vector_xyz math::matrix::eulerAnglesYZX() const
{
    vector_xyz v;
    if (r[0].y < D_00165D0C) {
        float y, z;
        if (r[0].y > D_00165D10) {
            y = safe_atan2f(-r[0].z, r[0].x);
            z = safe_asinf(r[0].y);
            v.x = safe_atan2f(-r[2].y, r[1].y);
        } else {
            y = -safe_atan2f(r[1].z, r[2].z);
            z = D_00165D14;
            v.x = 0;
        }
        v.y = y;
        v.z = z;
    } else {
        v.y = safe_atan2f(r[1].z, r[2].z);
        v.z = D_00165D18;
        v.x = 0;
    }
    return v;
}

math::vector_xyz math::matrix::eulerAnglesZXY() const
{
    vector_xyz v;
    if (r[1].z < D_00165D1C) {
        float z, x;
        if (r[1].z > D_00165D20) {
            z = safe_atan2f(-r[1].x, r[1].y);
            x = safe_asinf(r[1].z);
            v.y = safe_atan2f(-r[0].z, r[2].z);
        } else {
            z = -safe_atan2f(r[2].x, r[0].x);
            x = D_00165D24;
            v.y = 0;
        }
        v.x = x;
        v.z = z;
    } else {
        v.z = safe_atan2f(r[2].x, r[0].x);
        v.x = D_00165D28;
        v.y = 0;
    }
    return v;
}

math::vector_xyz math::matrix::eulerAnglesZYX() const
{
    vector_xyz v;
    float z, y;
    if (r[0].z < D_00165D2C) {
        if (r[0].z > D_00165D30) {
            z = safe_atan2f(r[0].y, r[0].x);
            y = safe_asinf(-r[0].z);
            v.x = safe_atan2f(r[1].z, r[2].z);
        } else {
            z = -safe_atan2f(r[1].x, r[2].x);
            y = D_00165D34;
            v.x = 0;
        }
        v.y = y;
        v.z = z;
    } else {
        z = safe_atan2f(-r[1].x, -r[2].x);
        y = D_00165D38;
        v.z = z;
        v.y = y;
        v.x = 0;
    }
    return v;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix10isCoordSysEf);

extern const float D_00165D40;
static inline math::vector_xyzw fcs_normalize(const math::vector_xyzw &v)
{
    float l = math::length(v);
    return v * (l == 0 ? 0 : D_00165D40 / l);
}
math::matrix math::matrix::fixedCoordSys() const
{
    matrix m;
    m.r[0] = fcs_normalize(r[0]);
    vector_xyzw &z = m.r[2];
    z = fcs_normalize(cross(m.r[0], r[1]));
    vector_xyzw &y = m.r[1];
    y = cross(m.r[2], m.r[0]);
    vector_xyzw &w = m.r[3];
    w = r[3];
    return m;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix5printESsSs);
