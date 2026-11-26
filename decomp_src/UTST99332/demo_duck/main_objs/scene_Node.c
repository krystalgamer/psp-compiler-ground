/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Node", _Z41__static_initialization_and_destruction_0ii_84E7C);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Node", _ZN5scene5Graph6calcbvEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Node", _ZN5scene5Group6calcbvEv);

bool scene::Group::calcbv(math::TransformStack &ts, sgl::BV &bv)
{
    traverse_children(ts, bv);
    return true;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Node", _ZN5scene5Group17traverse_childrenERN4math14TransformStackERN3sgl2BVE);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Node", _ZN5scene9Transform6calcbvERN4math14TransformStackERN3sgl2BVE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Node", _ZN5scene15StaticTransform6calcbvERN4math14TransformStackERN3sgl2BVE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Node", _ZN5scene4Mesh6calcbvERN4math14TransformStackERN3sgl2BVE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Node", _ZN5scene6Switch6calcbvERN4math14TransformStackERN3sgl2BVE);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_84E7C");
void _GLOBAL__I__ZN5scene4Node6calcbvERN4math14TransformStackERN3sgl2BVE(void);
void _GLOBAL__D__ZN5scene4Node6calcbvERN4math14TransformStackERN3sgl2BVE(void);
}

void _GLOBAL__I__ZN5scene4Node6calcbvERN4math14TransformStackERN3sgl2BVE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene4Node6calcbvERN4math14TransformStackERN3sgl2BVE(void)
{
    static_init(0, 0xFFFF);
}
