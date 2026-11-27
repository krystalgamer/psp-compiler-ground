/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const char D_0016A148[];
extern const char D_0016A1E0[];     /* "../lib/scene/Transform.cpp" */
extern const char D_0016A1FC[];     /* " " */
extern const char D_0016A258[];     /* "_RotationOrder == math::XYZ" */
extern const char D_0016A274[];     /* " *** error " */
extern const char Transform_setEulerRotation_name[]
    __asm__("_ZZN5scene9Transform16setEulerRotationERKN4math10vector_xyzENS1_13RotationOrderEE19__PRETTY_FUNCTION__");
extern const float D_0016A12C, D_0016A130, D_0016A134;     /* 1.0f */
extern const float D_0016A13C;      /* 2 pi */
extern const float D_0016A144;      /* 1.0f */

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _Z41__static_initialization_and_destruction_0ii_938EC);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _ZN5scene9TransformC2ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _ZN5scene9TransformC1ESsb);

scene::Transform::~Transform()
{
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform10flushCacheEv);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform13setFromMatrixEN4math6matrixE);

math::quaternion scene::Transform::getRotation() const
{
    return math::quaternion::FromEulerAngles(_euler.x, _euler.y, _euler.z, (math::RotationOrder)0);
}

math::vector_xyz scene::Transform::getEulerAngles(math::RotationOrder o) const
{
    if (o == 0)
        return _euler;
    return math_matrix_eulerAngles(getMatrix(), o);
}

void scene::Transform::setEulerRotation(const math::vector_xyz &v, math::RotationOrder o)
{
    SCENE_ASSERT(o == 0, D_0016A274, D_0016A258, D_0016A1E0, Transform_setEulerRotation_name, 153, D_0016A1FC);
    setRotation(v);
}

void scene::Transform::setRotation(const math::quaternion &q)
{
    set_rotation(q.toMatrix());
}

void scene::Transform::set_rotation(const math::matrix &m)
{
    const math::vector_xyz &e = math_matrix_eulerAnglesXYZ(m);
    setRotation(e);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform12preTransformEN4math6matrixES2_S2_b);

void scene::Transform::SetViewerTransform(const math::matrix &m)
{
    tmp_viewer_transform = m;
}

void scene::Transform::SetParentTransform(const math::matrix &m)
{
    tmp_parent_transform = m;
}

void scene::Transform::translate(Space s, float x, float y, float z)
{
    transform(s, math::matrix::Translation(x, y, z));
}

void scene::Transform::rotate(Space s, float a, float b, float c, math::RotationOrder o)
{
    transform(s, math_matrix_EulerRotation(a, b, c, o));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform7rotateXENS0_5SpaceEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform7rotateYENS0_5SpaceEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform7rotateZENS0_5SpaceEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform9transformENS0_5SpaceERKN4math6matrixE);

float scene::Transform::set_angle(float a)
{
    if (use_angle_range)
        return math::wrap(a, angle_range, D_0016A13C);
    return a;
}

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform11setRotationEN4math10vector_xyzE);

math::vector_xyz scene::Transform::getTranslation() const
{
    return _translation;
}

math::vector_xyz scene::Transform::getScale() const
{
    return _scale;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform11setIdentityEv);

void scene::Transform::flatten(math::TransformStack &ts)
{
    math_TransformStack_push(ts);
    math_TransformStack_mult(ts, getMatrix());
    Group::flatten(ts);
    math_TransformStack_pop(ts);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_938EC");
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

const char *scene::Transform::getTypeName() const
{
    return D_0016A148;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Transform", _ZNK5scene9Transform5cloneESs);

