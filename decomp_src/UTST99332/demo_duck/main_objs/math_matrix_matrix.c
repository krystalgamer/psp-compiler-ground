/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _Z41__static_initialization_and_destruction_0ii_55168);

math::matrix::matrix(const quaternion &q)
{
    *this = q.toMatrix();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix11TranslationEfff);

math::matrix math::matrix::Translation(const vector_xyz &v)
{
    return Translation(v.x, v.y, v.z);
}

math::matrix math::matrix::Translation(const vector_xyzw &v)
{
    return Translation(v.x, v.y, v.z);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix5ScaleEfff);

math::matrix math::matrix::Scale(const vector_xyz &v)
{
    return Scale(v.x, v.y, v.z);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix8RotationEffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix9RotationXEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix9RotationYEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix9RotationZEf);

math::matrix math::matrix::Rotation(float a, const vector_xyzw &v)
{
    return Rotation(a, v.x, v.y, v.z);
}

math::matrix math::matrix::Rotation(float a, const vector_xyz &v)
{
    return Rotation(a, v.x, v.y, v.z);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix11PointNormalENS_11vector_xyzwES1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix11PerspectiveEffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix7FrustumEffffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix12ShadowMatrixENS_11vector_xyzwES1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix9trackballEffbbffRNS_11vector_xyzwE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix12determinant3Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix8inverse3Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix9inverseONEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix7inverseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix9transposeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix13EulerRotationEfffNS_13RotationOrderE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZN4math6matrix13EulerRotationENS_10vector_xyzENS_13RotationOrderE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix11eulerAnglesENS_13RotationOrderE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix14eulerAnglesXYZEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix14eulerAnglesXZYEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix14eulerAnglesYXZEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix14eulerAnglesYZXEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix14eulerAnglesZXYEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix14eulerAnglesZYXEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix10isCoordSysEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix13fixedCoordSysEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_matrix", _ZNK4math6matrix5printESsSs);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_55168");
void _GLOBAL__I__ZN4math6matrixC2ERKNS_10quaternionE(void);
void _GLOBAL__D__ZN4math6matrixC2ERKNS_10quaternionE(void);
}

void _GLOBAL__I__ZN4math6matrixC2ERKNS_10quaternionE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN4math6matrixC2ERKNS_10quaternionE(void)
{
    static_init(0, 0xFFFF);
}
