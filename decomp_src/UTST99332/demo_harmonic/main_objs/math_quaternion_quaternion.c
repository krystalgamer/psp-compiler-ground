/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_quaternion_quaternion", _Z41__static_initialization_and_destruction_0ii_5B264);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_quaternion_quaternion", _ZN4math10quaternionC2ERKNS_6matrixE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_quaternion_quaternion", _ZN4math10quaternionC1ERKNS_6matrixE);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_quaternion_quaternion", _ZNK4math10quaternionmlERKS0_);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_quaternion_quaternion", _ZN4math10quaternionmIERKS0_);

math::quaternion &math::quaternion::operator+=(const quaternion &q)
{
    *this = *this + q;
    return *this;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_quaternion_quaternion", _ZN4math10quaternionmLERKS0_);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_quaternion_quaternion", _ZN4math10quaternion15FromEulerAnglesEfffNS_13RotationOrderE);


extern const float D_00165ED4;  /* 0.5f */
math::quaternion math::quaternion::FromAxisAngle(vector_xyz axis, float angle)
{
    float h = angle * D_00165ED4;
    return quaternion(axis * sinf(h), cosf(h));
}

extern const float D_00165ED8;  /* 1.0f */
void math::quaternion::toAxisAngle(vector_xyz &axis, float &angle)
{
    vector_xyz v(x, y, z);
    float l = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    if (l > 0) {
        angle = 2 * safe_acosf(w);
        axis = vector_xyz(v.x / l, v.y / l, v.z / l);
    } else {
        angle = 0;
        axis = vector_xyz(D_00165ED8, 0, 0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_quaternion_quaternion", _ZNK4math10quaternion8toMatrixEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_quaternion_quaternion", _ZNK4math10quaternion3logEv);

math::quaternion math::quaternion::conj() const
{
    return quaternion(-x, -y, -z, w);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_quaternion_quaternion", _ZNK4math10quaternion3expEv);

void math::quaternion::Shortest(quaternion &a, quaternion &b)
{
    if ((a - b).norm() > (b + a).norm())
        b = quaternion(-b.x, -b.y, -b.z, -b.w);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_quaternion_quaternion", _ZN4math10quaternion5SlerpES0_S0_f);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_5B264");
void _GLOBAL__I__ZN4math10quaternionC2ERKNS_6matrixE(void);
}

void _GLOBAL__I__ZN4math10quaternionC2ERKNS_6matrixE(void)
{
    static_init(1, 0xFFFF);
}

