/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZNK5scene9Transform11getTypeNameEv)
    SCENE_LINKONCE(_ZNK5scene9Transform5cloneESs)
);

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene9Transform11angle_rangeE");
__asm__(".globl _GLOBAL__D__ZN5scene9Transform11angle_rangeE");

extern const char D_0016D070[];
extern const char D_0016D1F8[];     /* "" */
extern const char D_0016D1FC[];     /* "non implemented yet" */
extern const char Transform_transform_name[]
    __asm__("_ZZN5scene9Transform9transformENS0_5SpaceERKN4math6matrixEE19__PRETTY_FUNCTION__");
extern const char D_0016D0DC[];     /* " *** warning " */
extern const char D_0016D0EC[];     /* "_Mat.isCoordSys( 1.e-3f )" */
extern const char Transform_setFromMatrix_name[]
    __asm__("_ZZN5scene9Transform13setFromMatrixEN4math6matrixEE19__PRETTY_FUNCTION__");
extern const char D_0016D108[];     /* "../lib/scene/Transform.cpp" */
extern const char D_0016D124[];     /* " " */
extern const char D_0016D180[];     /* "_RotationOrder == math::XYZ" */
extern const char D_0016D19C[];     /* " *** error " */
extern const char Transform_setEulerRotation_name[]
    __asm__("_ZZN5scene9Transform16setEulerRotationERKN4math10vector_xyzENS1_13RotationOrderEE19__PRETTY_FUNCTION__");

float scene::Transform::angle_range;
math::matrix scene::Transform::tmp_viewer_transform = math::matrix::Identity();
math::matrix scene::Transform::tmp_parent_transform = math::matrix::Identity();

scene::Transform::Transform(std::string name, bool b)
    : Group(name, b), _matrix(math::matrix::Identity()), _dirty(false), _translation(0, 0, 0), _scale(1, 1, 1), _euler(0, 0, 0)
{
    set_default_name();
    setIdentity();
}

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

/* calls setTranslation/setScale before their definitions: cc1plus's inlinable_function_p then caches
   DECL_UNINLINABLE for them, so setIdentity calls them too */
void scene::Transform::setFromMatrix(math::matrix _Mat)
{
    math::vector_xyz s(math::length(_Mat.r[0]), math::length(_Mat.r[1]), math::length(_Mat.r[2]));
    _Mat.r[0].x /= s.x; _Mat.r[0].y /= s.x; _Mat.r[0].z /= s.x; _Mat.r[0].w /= s.x;
    _Mat.r[1].x /= s.y; _Mat.r[1].y /= s.y; _Mat.r[1].z /= s.y; _Mat.r[1].w /= s.y;
    _Mat.r[2].x /= s.z; _Mat.r[2].y /= s.z; _Mat.r[2].z /= s.z; _Mat.r[2].w /= s.z;
    if (math::dot(math::cross(_Mat.r[0], _Mat.r[1]), _Mat.r[2]) < 0) {
        _Mat.r[2].x = -_Mat.r[2].x;
        _Mat.r[2].y = -_Mat.r[2].y;
        _Mat.r[2].z = -_Mat.r[2].z;
        _Mat.r[2].w = -_Mat.r[2].w;
        s.z = -s.z;
    }
    SCENE_WARN(_Mat.isCoordSys(1.e-3f), D_0016D0DC, D_0016D0EC, D_0016D108, Transform_setFromMatrix_name, 110, D_0016D124);
    setScale(s);
    set_rotation(_Mat);
    setTranslation(math::vector_xyz(_Mat.r[3].x, _Mat.r[3].y, _Mat.r[3].z));
}

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
    SCENE_ASSERT(o == 0, D_0016D19C, D_0016D180, D_0016D108, Transform_setEulerRotation_name, 153, D_0016D124);
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform12preTransformEN4math6matrixES2_S2_b);

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

void scene::Transform::rotateX(Space s, float a)
{
    transform(s, math::matrix::Rotation(a, 1.0f, 0, 0));
}

void scene::Transform::rotateY(Space s, float a)
{
    transform(s, math::matrix::Rotation(a, 0, 1.0f, 0));
}

void scene::Transform::rotateZ(Space s, float a)
{
    transform(s, math::matrix::Rotation(a, 0, 0, 1.0f));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZN5scene9Transform9transformENS0_5SpaceERKN4math6matrixE);

float scene::Transform::set_angle(float a)
{
    if (use_angle_range)
        return math::wrap(a, angle_range, 6.2831855f);
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

void scene::Transform::setRotation(math::vector_xyz v)
{
    _euler = math::vector_xyz(set_angle(v.x), set_angle(v.y), set_angle(v.z));
    _dirty = true;
    _identity = false;
}

math::vector_xyz scene::Transform::getTranslation() const
{
    return _translation;
}

math::vector_xyz scene::Transform::getScale() const
{
    return _scale;
}

void scene::Transform::setIdentity()
{
    setTranslation(math::vector_xyz(0, 0, 0));
    setRotation(math::vector_xyz(0, 0, 0));
    setScale(math::vector_xyz(1, 1, 1));
    _identity = true;
}

/* inline in the class (weak copies emitted with the vtable, in the object's tail) */
SGL_LINKONCE_BEGIN
inline const char *scene::Transform::getTypeName() const
{
    return D_0016D070;
}
SGL_LINKONCE_END

void scene::Transform::flatten(math::TransformStack &ts)
{
    math_TransformStack_push(ts);
    math_TransformStack_mult(ts, getMatrix());
    Group::flatten(ts);
    math_TransformStack_pop(ts);
}

/* inline in the class too (weak copies in the tail), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Transform", _ZNK5scene9Transform5cloneESs);
