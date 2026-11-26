/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_4", _Z41__static_initialization_and_destruction_0ii_81D3C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_4", _ZN5scene5Graph8traverseENS_13TraversalTypeERN3sgl7FrustumERKN4math6matrixES8_S8_f);

void scene::Node::traverse(TraversalVarStack &) {
}

void scene::DefaultShader::traverse(TraversalVarStack &) {
}

void scene::Material::traverse(TraversalVarStack &) {
}

void scene::Setup::traverse(TraversalVarStack &) {
}

void scene::Texture::traverse(TraversalVarStack &) {
}

void scene::Object::traverse(TraversalVarStack &tvs)
{
    if (frustumTest(*tvs._frustum))
        traverse_children(tvs);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_4", _ZN5scene5Shape8traverseERNS_17TraversalVarStackE);

void scene::Transform::traverse(TraversalVarStack &tvs)
{
    tvs.push();
    tvs.mult(getMatrix(), _identity, false);
    traverse_children(tvs);
    tvs.pop();
}

void scene::StaticTransform::traverse(TraversalVarStack &tvs)
{
    tvs.push();
    tvs.mult(getMatrix(), _identity, false);
    traverse_children(tvs);
    tvs.pop();
}

void scene::Mesh::traverse(TraversalVarStack &tvs)
{
    draw(tvs);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_4", _ZN5scene6Switch8traverseERNS_17TraversalVarStackE);

void scene::Group::traverse(TraversalVarStack &tvs)
{
    traverse_children(tvs);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_4", _ZN5scene5Group17traverse_childrenERNS_17TraversalVarStackE);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_81D3C");
void _GLOBAL__I__ZN5scene5Graph8traverseENS_13TraversalTypeERN3sgl7FrustumERKN4math6matrixES8_S8_f(void);
void _GLOBAL__D__ZN5scene5Graph8traverseENS_13TraversalTypeERN3sgl7FrustumERKN4math6matrixES8_S8_f(void);
}

void _GLOBAL__I__ZN5scene5Graph8traverseENS_13TraversalTypeERN3sgl7FrustumERKN4math6matrixES8_S8_f(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene5Graph8traverseENS_13TraversalTypeERN3sgl7FrustumERKN4math6matrixES8_S8_f(void)
{
    static_init(0, 0xFFFF);
}
