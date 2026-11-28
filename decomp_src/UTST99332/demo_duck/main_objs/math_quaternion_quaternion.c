/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_quaternion_quaternion", _Z41__static_initialization_and_destruction_0ii_5D6E0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_quaternion_quaternion", _ZN4math10quaternionC2ERKNS_6matrixE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_quaternion_quaternion", _ZN4math10quaternionC1ERKNS_6matrixE);

math::quaternion::quaternion(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_)
{
}

math::quaternion::quaternion(vector_xyzw v) : x(v.x), y(v.y), z(v.z), w(v.w)
{
}

math::quaternion::quaternion(vector_xyz v, float w_) : x(v.x), y(v.y), z(v.z), w(w_)
{
}

math::quaternion math::quaternion::operator+(const quaternion &q) const
{
    return quaternion(x + q.x, y + q.y, z + q.z, w + q.w);
}

math::quaternion math::quaternion::operator-(const quaternion &q) const
{
    return quaternion(x - q.x, y - q.y, z - q.z, w - q.w);
}

math::quaternion math::quaternion::operator*(const quaternion &q) const
{
    quaternion r;
    __asm__(
        ".set push\n"
        ".set noreorder\n"
        "lv.q C000, %1\n"
        "lv.q C100, %2\n"
        "vqmul.q C200, C000, C100\n"
        "sv.q C200, %0\n"
        ".set pop\n"
        : "=m"(r) : "m"(*this), "m"(q));
    return r;
}

math::quaternion math::quaternion::operator*(float s) const
{
    return quaternion(x * s, y * s, z * s, w * s);
}

math::quaternion math::quaternion::operator/(float s) const
{
    return quaternion(x / s, y / s, z / s, w / s);
}

bool math::quaternion::operator==(const quaternion &q) const
{
    return x == q.x && y == q.y && z == q.z && w == q.w;
}

bool math::quaternion::operator!=(const quaternion &q) const
{
    return x != q.x || y != q.y || z != q.z || w != q.w;
}

math::quaternion &math::quaternion::operator-=(const quaternion &q)
{
    *this = *this * q;
    return *this;
}

math::quaternion &math::quaternion::operator+=(const quaternion &q)
{
    *this = *this + q;
    return *this;
}

math::quaternion &math::quaternion::operator*=(const quaternion &q)
{
    *this = *this * q;
    return *this;
}

math::quaternion &math::quaternion::operator*=(float s)
{
    *this = *this * s;
    return *this;
}

math::quaternion &math::quaternion::operator/=(float s)
{
    *this = *this / s;
    return *this;
}

float math::quaternion::dot(const quaternion &q) const
{
    return x * q.x + y * q.y + z * q.z + w * q.w;
}

float math::quaternion::norm() const
{
    return x * x + y * y + z * z + w * w;
}

math::quaternion math::quaternion::FromEulerAngles(vector_xyz v, RotationOrder o)
{
    return FromEulerAngles(v.x, v.y, v.z, o);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_quaternion_quaternion", _ZN4math10quaternion15FromEulerAnglesEfffNS_13RotationOrderE);


extern const float D_00168DF4;  /* 0.5f */
math::quaternion math::quaternion::FromAxisAngle(vector_xyz axis, float angle)
{
    float h = angle * D_00168DF4;
    return quaternion(axis * sinf(h), cosf(h));
}

extern const float D_00168DF8;  /* 1.0f */
void math::quaternion::toAxisAngle(vector_xyz &axis, float &angle)
{
    vector_xyz v(x, y, z);
    float l = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    if (l > 0) {
        angle = 2 * safe_acosf(w);
        axis = vector_xyz(v.x / l, v.y / l, v.z / l);
    } else {
        angle = 0;
        axis = vector_xyz(D_00168DF8, 0, 0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_quaternion_quaternion", _ZNK4math10quaternion8toMatrixEv);

extern const float D_00168E08, D_00168E0C;  /* 1.0f, 0.001f */
math::quaternion math::quaternion::log() const
{
    quaternion r(0, 0, 0, 0);
    /* STAND-IN: float pointer views of r/*this order the loads and stores like the original (which
       probably indexed the components through an accessor) */
    float *d = &r.x;
    const float *s = &x;
    if (fabsf(s[3]) < D_00168E08) {
        float a = safe_acosf(s[3]);
        float sn = sinf(a);
        if (fabsf(sn) >= D_00168E0C) {
            float k = a / sn;
            d[0] = s[0] * k;
            d[1] = s[1] * k;
            d[2] = s[2] * k;
            return r;
        }
    }
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    return r;
}

math::quaternion math::quaternion::conj() const
{
    return quaternion(-x, -y, -z, w);
}

extern const float D_00168E10, D_00168E14;  /* 1.0f, eps */
math::quaternion math::quaternion::exp() const
{
    quaternion r(0, 0, 0, D_00168E10);
    /* STAND-IN: float pointer views of r/*this order the loads and stores like the original (which
       probably indexed the components through an accessor) */
    float *d = &r.x;
    const float *s = &x;
    vector_xyz v(s[0], s[1], s[2]);
    float a = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    float sn = sinf(a);
    d[3] = cosf(a);
    if (fabsf(sn) > D_00168E14) {
        float k = sn / a;
        d[0] = s[0] * k;
        d[1] = s[1] * k;
        d[2] = s[2] * k;
        return r;
    }
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    return r;
}

void math::quaternion::Shortest(quaternion &a, quaternion &b)
{
    if ((a - b).norm() > (b + a).norm())
        b = quaternion(-b.x, -b.y, -b.z, -b.w);
}

extern const float slerp_one __asm__("D_00168E18");
extern const float slerp_eps __asm__("D_00168E1C");
extern const float slerp_half_pi __asm__("D_00168E20");
math::quaternion math::quaternion::Slerp(quaternion a, quaternion b, float t)
{
    quaternion r(0, 0, 0, slerp_one);
    quaternion qb, qa;
    qa = a;
    qb = b;
    Shortest(qa, qb);
    float c = qa.dot(qb);
    float s0, s1;
    if (c + slerp_one > slerp_eps) {
        if (slerp_one - c > slerp_eps) {
            float om = safe_acosf(c);
            float so = sinf(om);
            s0 = sinf((slerp_one - t) * om) / so;
            s1 = sinf(t * om) / so;
        } else {
            s0 = slerp_one - t;
            s1 = t;
        }
        for (int i = 0; i < 4; i++)
            (&r.x)[i] = s0 * (&qa.x)[i] + s1 * (&qb.x)[i];
    } else {
        r.x = -qa.y;
        r.y = qa.x;
        r.z = -qa.w;
        r.w = qa.z;
        s0 = sinf((slerp_one - t) * slerp_half_pi);
        s1 = sinf(t * slerp_half_pi);
        for (int i = 0; i < 3; i++)
            (&r.x)[i] = s0 * (&qa.x)[i] + s1 * (&r.x)[i];
    }
    return r;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_5D6E0");
void _GLOBAL__I__ZN4math10quaternionC2ERKNS_6matrixE(void);
}

void _GLOBAL__I__ZN4math10quaternionC2ERKNS_6matrixE(void)
{
    static_init(1, 0xFFFF);
}

