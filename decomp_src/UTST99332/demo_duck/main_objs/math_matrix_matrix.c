/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
/* Identity()'s 1.0f stays in the module's .rodata (asm) */
extern const float D_00168BEC;
#define MATH_IDENTITY_ONE D_00168BEC
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN4math6matrixC2ERKNS_10quaternionE");
__asm__(".globl _GLOBAL__D__ZN4math6matrixC2ERKNS_10quaternionE");

/* float constants stay in the module's .rodata (asm) */
extern const float D_00168B98;      /* 1 */
extern const float D_00168B9C;      /* 1 */
extern const float D_00168BA0;      /* 1 */
extern const float D_00168BA4;      /* 1 */
extern const float D_00168BA8;      /* 1 */
extern const float D_00168BAC;      /* 1 */
extern const float D_00168BB8;      /* pi / 180 */
extern const float D_00168BBC;      /* 0.5 */
extern const float D_00168BC0;      /* 1 */
extern const float D_00168BC4;      /* -1 */
extern const float D_00168BC8;      /* -2 */
extern const float D_00168BCC;      /* -2 */
extern const float D_00168BD0;      /* -1 */
extern const float D_00168BFC;      /* 1 */
extern const float D_00168C00;      /* -1 */
extern const float D_00168C04;      /* -pi / 2 */
extern const float D_00168C08;      /* pi / 2 */
extern const float D_00168C0C, D_00168C10, D_00168C14, D_00168C18, D_00168C1C, D_00168C20, D_00168C24, D_00168C28;
extern const float D_00168C2C, D_00168C30, D_00168C34, D_00168C38, D_00168C3C, D_00168C40, D_00168C44, D_00168C48;
extern const float D_00168C4C, D_00168C50, D_00168C54, D_00168C58;
extern const char D_00168CB4[];     /* " *** error " */
extern const char D_00168CC0[];     /* "n != 0.f" */
extern const char D_00168CCC[];     /* "../lib/maths/matrix.cpp" */
extern const char D_00168CE4[];     /* "n should never be set to 0" */
extern const char PF_Perspective[] __asm__("_ZZN4math6matrix11PerspectiveEffffE19__PRETTY_FUNCTION__");

math::matrix::matrix(const quaternion &q)
{
    *this = q.toMatrix();
}

math::matrix math::matrix::Translation(float x, float y, float z)
{
    return matrix(vector_xyzw(D_00168B98, 0, 0, 0), vector_xyzw(0, D_00168B98, 0, 0), vector_xyzw(0, 0, D_00168B98, 0),
                  vector_xyzw(x, y, z, D_00168B98));
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
                  vector_xyzw(0, 0, 0, D_00168B9C));
}

math::matrix math::matrix::Scale(const vector_xyz &v)
{
    return Scale(v.x, v.y, v.z);
}

math::matrix math::matrix::Rotation(float a, float x, float y, float z)
{
    float s = sinf(a);
    float c = cosf(a);
    float t = D_00168BA0 - c;
    float sx = s * x;
    float sy = s * y;
    float sz = s * z;
    float tx = t * x;
    float ty = t * y;
    float tz = t * z;
    return matrix(vector_xyzw(tx * x + c, ty * x + sz, tz * x - sy, 0),
                  vector_xyzw(tx * y - sz, ty * y + c, tz * y + sx, 0),
                  vector_xyzw(tx * z + sy, ty * z - sx, tz * z + c, 0),
                  vector_xyzw(0, 0, 0, D_00168BA0));
}

math::matrix math::matrix::RotationX(float a)
{
    float s = sinf(a);
    float c = cosf(a);
    return matrix(vector_xyzw(D_00168BA4, 0, 0, 0), vector_xyzw(0, c, s, 0), vector_xyzw(0, -s, c, 0),
                  vector_xyzw(0, 0, 0, D_00168BA4));
}

math::matrix math::matrix::RotationY(float a)
{
    float s = sinf(a);
    float c = cosf(a);
    return matrix(vector_xyzw(c, 0, -s, 0), vector_xyzw(0, D_00168BA8, 0, 0), vector_xyzw(s, 0, c, 0),
                  vector_xyzw(0, 0, 0, D_00168BA8));
}

math::matrix math::matrix::RotationZ(float a)
{
    float s = sinf(a);
    float c = cosf(a);
    return matrix(vector_xyzw(c, s, 0, 0), vector_xyzw(-s, c, 0, 0), vector_xyzw(0, 0, D_00168BAC, 0),
                  vector_xyzw(0, 0, 0, D_00168BAC));
}

math::matrix math::matrix::Rotation(float a, const vector_xyzw &v)
{
    return Rotation(a, v.x, v.y, v.z);
}

math::matrix math::matrix::Rotation(float a, const vector_xyz &v)
{
    return Rotation(a, v.x, v.y, v.z);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix11PointNormalENS_11vector_xyzwES1_);

math::matrix math::matrix::Perspective(float fovy, float aspect, float n, float f)
{
    float c = D_00168BC0 / tanf(fovy * D_00168BB8 * D_00168BBC);
    if (!(n != 0)) {
        common::common_internal::assert_display(D_00168CB4, D_00168CC0, D_00168CCC, PF_Perspective, 168, D_00168CE4);
        common::common_internal::on_error();
        common::common_internal::clash();
    }
    return matrix(vector_xyzw(c / aspect, 0, 0, 0), vector_xyzw(0, c, 0, 0),
                  vector_xyzw(0, 0, -(f + n) / (f - n), D_00168BC4), vector_xyzw(0, 0, f * D_00168BC8 * n / (f - n), 0));
}

math::matrix math::matrix::Frustum(float l, float r, float b, float t, float n, float f)
{
    return matrix(vector_xyzw(2 * n / (r - l), 0, (r + l) / (r - l), 0), vector_xyzw(0, 2 * n / (t - b), (t + b) / (t - b), 0),
                  vector_xyzw(0, 0, -(f + n) / (f - n), f * D_00168BCC * n / (f - n)), vector_xyzw(0, 0, D_00168BD0, 0));
}

extern const float D_00168BD4;
extern const char D_00168D5C[], D_00168D60[];
extern const char PF_ShadowMatrix[] __asm__("_ZZN4math6matrix12ShadowMatrixENS_11vector_xyzwES1_E19__PRETTY_FUNCTION__");
math::matrix math::matrix::ShadowMatrix(vector_xyzw plane, vector_xyzw light)
{
    if (!(light.w == D_00168BD4)) {
        common::common_internal::assert_display(D_00168CB4, D_00168D60, D_00168CCC, PF_ShadowMatrix, 225, D_00168D5C);
        common::common_internal::on_error();
        common::common_internal::clash();
    }
    float d = dot(plane, light);
    return matrix(vector_xyzw(d, 0, 0, 0) - light * plane.x, vector_xyzw(0, d, 0, 0) - light * plane.y,
                  vector_xyzw(0, 0, d, 0) - light * plane.z, vector_xyzw(0, 0, 0, d) - light * plane.w);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix9trackballEffbbffRNS_11vector_xyzwE);

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
    det = D_00168BEC / det;
    return matrix(vector_xyzw(((*this)[1][1] * (*this)[2][2] - (*this)[2][1] * (*this)[1][2]) * det, -((*this)[0][1] * (*this)[2][2] - (*this)[2][1] * (*this)[0][2]) * det,
                              ((*this)[0][1] * (*this)[1][2] - (*this)[1][1] * (*this)[0][2]) * det, 0),
                  vector_xyzw(-((*this)[1][0] * (*this)[2][2] - (*this)[2][0] * (*this)[1][2]) * det, ((*this)[0][0] * (*this)[2][2] - (*this)[2][0] * (*this)[0][2]) * det,
                              -((*this)[0][0] * (*this)[1][2] - (*this)[1][0] * (*this)[0][2]) * det, 0),
                  vector_xyzw(((*this)[1][0] * (*this)[2][1] - (*this)[2][0] * (*this)[1][1]) * det, -((*this)[0][0] * (*this)[2][1] - (*this)[2][0] * (*this)[0][1]) * det,
                              ((*this)[0][0] * (*this)[1][1] - (*this)[1][0] * (*this)[0][1]) * det, 0),
                  vector_xyzw(0, 0, 0, D_00168BEC));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix9inverseONEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix7inverseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix9transposeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix13EulerRotationEfffNS_13RotationOrderE);

math::matrix math::matrix::EulerRotation(vector_xyz v, RotationOrder o)
{
    return EulerRotation(v.x, v.y, v.z, o);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix11eulerAnglesENS_13RotationOrderE);

math::vector_xyz math::matrix::eulerAnglesXYZ() const
{
    vector_xyz v;
    if (r[2].x < D_00168BFC) {
        float x, y;
        if (r[2].x > D_00168C00) {
            x = safe_atan2f(-r[2].y, r[2].z);
            y = safe_asinf(r[2].x);
            v.z = safe_atan2f(-r[1].x, r[0].x);
        } else {
            x = -safe_atan2f(r[0].y, r[1].y);
            y = D_00168C04;
            v.z = 0;
        }
        v.x = x;
        v.y = y;
    } else {
        v.x = safe_atan2f(r[0].y, r[1].y);
        v.y = D_00168C08;
        v.z = 0;
    }
    return v;
}

math::vector_xyz math::matrix::eulerAnglesXZY() const
{
    vector_xyz v;
    float x, z;
    if (r[1].x < D_00168C0C) {
        if (r[1].x > D_00168C10) {
            x = safe_atan2f(r[1].z, r[1].y);
            z = safe_asinf(-r[1].x);
            v.y = safe_atan2f(r[2].x, r[0].x);
            v.x = x;
            v.z = z;
        } else {
            x = safe_atan2f(r[0].z, r[2].z);
            z = D_00168C14;
            v.x = x;
            v.z = z;
            v.y = 0;
        }
    } else {
        x = safe_atan2f(-r[0].z, r[2].z);
        z = D_00168C18;
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
    if (r[2].y < D_00168C1C) {
        if (r[2].y > D_00168C20) {
            y = safe_atan2f(r[2].x, r[2].z);
            x = safe_asinf(-r[2].y);
            v.z = safe_atan2f(r[0].y, r[1].y);
            v.x = x;
            v.y = y;
        } else {
            y = safe_atan2f(r[1].x, r[0].x);
            x = D_00168C24;
            v.y = y;
            v.x = x;
            v.z = 0;
        }
    } else {
        y = safe_atan2f(-r[1].x, r[0].x);
        x = D_00168C28;
        v.y = y;
        v.x = x;
        v.z = 0;
    }
    return v;
}

math::vector_xyz math::matrix::eulerAnglesYZX() const
{
    vector_xyz v;
    if (r[0].y < D_00168C2C) {
        float y, z;
        if (r[0].y > D_00168C30) {
            y = safe_atan2f(-r[0].z, r[0].x);
            z = safe_asinf(r[0].y);
            v.x = safe_atan2f(-r[2].y, r[1].y);
        } else {
            y = -safe_atan2f(r[1].z, r[2].z);
            z = D_00168C34;
            v.x = 0;
        }
        v.y = y;
        v.z = z;
    } else {
        v.y = safe_atan2f(r[1].z, r[2].z);
        v.z = D_00168C38;
        v.x = 0;
    }
    return v;
}

math::vector_xyz math::matrix::eulerAnglesZXY() const
{
    vector_xyz v;
    if (r[1].z < D_00168C3C) {
        float z, x;
        if (r[1].z > D_00168C40) {
            z = safe_atan2f(-r[1].x, r[1].y);
            x = safe_asinf(r[1].z);
            v.y = safe_atan2f(-r[0].z, r[2].z);
        } else {
            z = -safe_atan2f(r[2].x, r[0].x);
            x = D_00168C44;
            v.y = 0;
        }
        v.x = x;
        v.z = z;
    } else {
        v.z = safe_atan2f(r[2].x, r[0].x);
        v.x = D_00168C48;
        v.y = 0;
    }
    return v;
}

math::vector_xyz math::matrix::eulerAnglesZYX() const
{
    vector_xyz v;
    float z, y;
    if (r[0].z < D_00168C4C) {
        if (r[0].z > D_00168C50) {
            z = safe_atan2f(r[0].y, r[0].x);
            y = safe_asinf(-r[0].z);
            v.x = safe_atan2f(r[1].z, r[2].z);
        } else {
            z = -safe_atan2f(r[1].x, r[2].x);
            y = D_00168C54;
            v.x = 0;
        }
        v.y = y;
        v.z = z;
    } else {
        z = safe_atan2f(-r[1].x, -r[2].x);
        y = D_00168C58;
        v.z = z;
        v.y = y;
        v.x = 0;
    }
    return v;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix10isCoordSysEf);

extern const float D_00168C60;
static inline math::vector_xyzw fcs_normalize(const math::vector_xyzw &v)
{
    float l = math::length(v);
    return v * (l == 0 ? 0 : D_00168C60 / l);
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix5printESsSs);
