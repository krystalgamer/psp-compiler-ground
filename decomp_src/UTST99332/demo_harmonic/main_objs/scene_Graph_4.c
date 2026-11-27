/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene5Graph8traverseENS_13TraversalTypeERN3sgl7FrustumERKN4math6matrixES8_S8_f");
__asm__(".globl _GLOBAL__D__ZN5scene5Graph8traverseENS_13TraversalTypeERN3sgl7FrustumERKN4math6matrixES8_S8_f");


void scene::Graph::traverse(TraversalType type, sgl::Frustum &frustum, const math::matrix &m0, const math::matrix &m1,
                            const math::matrix &m2, float f)
{
    SCENE_ASSERT(_finish_called, " *** error ", "_finish_called", "../lib/scene/Graph.traverse.cpp", __PRETTY_FUNCTION__, 58, " ");
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
