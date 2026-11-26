/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* the strings stay in the module's .rodata (asm) */
extern const char D_00168628[];     /* " *** error " */
extern const char D_00168634[];     /* "_finish_called" */
extern const char D_00168644[];     /* "../lib/scene/Graph.traverse.cpp" */
extern const char D_00168664[];     /* " " */
extern const char Graph_traverse_name[] __asm__("_ZZN5scene5Graph8traverseENS_13TraversalTypeERN3sgl7FrustumERKN4math6matrixES8_S8_fE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_4", _Z41__static_initialization_and_destruction_0ii_81D3C);

void scene::Graph::traverse(TraversalType type, sgl::Frustum &frustum, const math::matrix &m0, const math::matrix &m1,
                            const math::matrix &m2, float f)
{
    SCENE_ASSERT(_finish_called, D_00168628, D_00168634, D_00168644, Graph_traverse_name, 58, D_00168664);
    _root->traverse(type, frustum, m0, m1, m2, _light, f);
}

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

void scene::Switch::traverse(TraversalVarStack &tvs)
{
    int sel = getSelected();
    if (sel < 0 || sel >= (int)children().size())
        return;
    const std::list<common::handle<Node> > &c = children();
    std::list<common::handle<Node> >::const_iterator it = c.begin();
    for (; sel != 0; sel--)
        ++it;
    common::handle<Node> child = *it;
    child->traverse(tvs);
}

void scene::Group::traverse(TraversalVarStack &tvs)
{
    traverse_children(tvs);
}

void scene::Group::traverse_children(TraversalVarStack &tvs)
{
    for (std::list<common::handle<Node> >::iterator it = _children.begin(); it != _children.end(); ++it) {
        if (hnull(*it))
            continue;
        (*it)->traverse(tvs);
    }
}

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
