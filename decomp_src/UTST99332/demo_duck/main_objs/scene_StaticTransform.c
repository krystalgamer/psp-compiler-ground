/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_StaticTransform", _Z41__static_initialization_and_destruction_0ii_938DC);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_StaticTransform", _ZN5scene15StaticTransform11setIdentityEv);

void scene::StaticTransform::flatten(math::TransformStack &ts)
{
    math_TransformStack_push(ts);
    math_TransformStack_mult(ts, getMatrix());
    Group::flatten(ts);
    math_TransformStack_pop(ts);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_938DC");
void _GLOBAL__I__ZN5scene15StaticTransformC2ESsb(void);
void _GLOBAL__D__ZN5scene15StaticTransformC2ESsb(void);
}

void _GLOBAL__I__ZN5scene15StaticTransformC2ESsb(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene15StaticTransformC2ESsb(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_StaticTransform", _ZNK5scene15StaticTransform11getTypeNameEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_StaticTransform", _ZNK5scene15StaticTransform5cloneESs);

