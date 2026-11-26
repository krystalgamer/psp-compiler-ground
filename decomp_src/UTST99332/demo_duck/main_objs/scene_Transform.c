/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _Z41__static_initialization_and_destruction_0ii_95D10);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9TransformC2ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9TransformC1ESsb);

scene::Transform::~Transform()
{
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform10flushCacheEv);

void scene::Transform::invalidate_cached_mat()
{
    _dirty = true;
    _identity = false;
}

const math::matrix &scene::Transform::getMatrix() const
{
    if (_dirty)
        const_cast<Transform *>(this)->flushCache();
    return _matrix;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform13setFromMatrixEN4math6matrixE);

math::quaternion scene::Transform::getRotation() const
{
    return math::quaternion::FromEulerAngles(_euler.x, _euler.y, _euler.z, (math::RotationOrder)0);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZNK5scene9Transform14getEulerAnglesEN4math13RotationOrderE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform16setEulerRotationERKN4math10vector_xyzENS1_13RotationOrderE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform11setRotationERKN4math10quaternionE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform12set_rotationERKN4math6matrixE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform12preTransformEN4math6matrixES2_S2_b);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform18SetViewerTransformERKN4math6matrixE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform18SetParentTransformERKN4math6matrixE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform9translateENS0_5SpaceEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform6rotateENS0_5SpaceEfffN4math13RotationOrderE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform7rotateXENS0_5SpaceEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform7rotateYENS0_5SpaceEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform7rotateZENS0_5SpaceEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform9transformENS0_5SpaceERKN4math6matrixE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform9set_angleEf);

void scene::Transform::setTranslation(math::vector_xyz v)
{
    _translation = v;
    _dirty = true;
    _identity = false;
}

void scene::Transform::setScale(math::vector_xyz v)
{
    _scale = v;
    _dirty = true;
    _identity = false;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform11setRotationEN4math10vector_xyzE);

math::vector_xyz scene::Transform::getTranslation() const
{
    return _translation;
}

math::vector_xyz scene::Transform::getScale() const
{
    return _scale;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform11setIdentityEv);

void scene::Transform::flatten(math::TransformStack &ts)
{
    math_TransformStack_push(ts);
    math_TransformStack_mult(ts, getMatrix());
    Group::flatten(ts);
    math_TransformStack_pop(ts);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_95D10");
void _GLOBAL__I__ZN5scene9Transform11angle_rangeE(void);
void _GLOBAL__D__ZN5scene9Transform11angle_rangeE(void);
}

void _GLOBAL__I__ZN5scene9Transform11angle_rangeE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene9Transform11angle_rangeE(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZNK5scene9Transform11getTypeNameEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZNK5scene9Transform5cloneESs);

