/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene4Node6calcbvERN4math14TransformStackERN3sgl2BVE");
__asm__(".globl _GLOBAL__D__ZN5scene4Node6calcbvERN4math14TransformStackERN3sgl2BVE");

bool scene::Node::calcbv(math::TransformStack &, sgl::BV &)
{
    return true;
}

bool scene::DefaultShader::calcbv(math::TransformStack &, sgl::BV &)
{
    return true;
}

bool scene::Material::calcbv(math::TransformStack &, sgl::BV &)
{
    return true;
}

bool scene::Setup::calcbv(math::TransformStack &, sgl::BV &)
{
    return true;
}

bool scene::Texture::calcbv(math::TransformStack &, sgl::BV &)
{
    return true;
}

void scene::Graph::calcbv()
{
    common::handle<Group> g = _root;
    g->calcbv();
}

void scene::Group::calcbv()
{
    math::TransformStack ts;
    sgl::BV bv;
    calcbv(ts, bv);
}

bool scene::Group::calcbv(math::TransformStack &ts, sgl::BV &bv)
{
    traverse_children(ts, bv);
    return true;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Node", _ZN5scene5Group17traverse_childrenERN4math14TransformStackERN3sgl2BVE);

bool scene::Object::calcbv(math::TransformStack &ts, sgl::BV &bv)
{
    traverse_children(ts, bv);
    return true;
}

bool scene::Shape::calcbv(math::TransformStack &ts, sgl::BV &bv)
{
    traverse_children(ts, bv);
    return true;
}

bool scene::Transform::calcbv(math::TransformStack &ts, sgl::BV &bv)
{
    math_TransformStack_push(ts);
    if (!_identity)
        math_TransformStack_mult(ts, getMatrix());
    traverse_children(ts, bv);
    math_TransformStack_pop(ts);
    return true;
}

bool scene::StaticTransform::calcbv(math::TransformStack &ts, sgl::BV &bv)
{
    math_TransformStack_push(ts);
    if (!_identity)
        math_TransformStack_mult(ts, getMatrix());
    traverse_children(ts, bv);
    math_TransformStack_pop(ts);
    return true;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Node", _ZN5scene4Mesh6calcbvERN4math14TransformStackERN3sgl2BVE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Node", _ZN5scene6Switch6calcbvERN4math14TransformStackERN3sgl2BVE);
