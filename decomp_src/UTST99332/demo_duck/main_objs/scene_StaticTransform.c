/* lang: c++ */
/* cflags: -O3 -fno-exceptions -fno-merge-constants */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SCENE_BVDATA_LITERALS
#define SCENE_BVDATA_CREATE
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZNK5scene15StaticTransform11getTypeNameEv)
    SCENE_LINKONCE(_ZNK5scene15StaticTransform5cloneESs)
);

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene15StaticTransformC2ESsb");
__asm__(".globl _GLOBAL__D__ZN5scene15StaticTransformC2ESsb");

scene::StaticTransform::StaticTransform(std::string name, bool b) : Group(name, b)
{
    set_default_name();
    setIdentity();
}

scene::StaticTransform::~StaticTransform()
{
}

void scene::StaticTransform::setMatrix(math::matrix m)
{
    _matrix = m;
    _identity = false;
}

math::matrix scene::StaticTransform::getMatrix() const
{
    return _matrix;
}

void scene::StaticTransform::setIdentity()
{
    _matrix = math::matrix::Identity();
    _identity = true;
}

/* (after setIdentity: its float pool precedes the type name) */
/* inline in the class (weak copies emitted with the vtable, in the object's tail) */
SGL_LINKONCE_BEGIN
inline const char *scene::StaticTransform::getTypeName() const
{
    return "StaticTransform";
}
/* clone() (asm) inlines StaticTransform::operator= -> BVdata::operator= -> create(): create's __PRETTY_FUNCTION__
   stays in .rodata (its warning is dead code); this linkonce copy (discarded by the link) emits it there */
inline void StaticTransform_refs(scene::StaticTransform &a, const scene::StaticTransform &b)
{
    a = b;
}
SGL_LINKONCE_END

void scene::StaticTransform::flatten(math::TransformStack &ts)
{
    math_TransformStack_push(ts);
    math_TransformStack_mult(ts, getMatrix());
    Group::flatten(ts);
    math_TransformStack_pop(ts);
}

/* inline in the class too (weak copies in the tail), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_StaticTransform", _ZNK5scene15StaticTransform5cloneESs);
