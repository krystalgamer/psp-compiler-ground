/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#define SCENE_BVDATA_LITERALS
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

bool scene::Group::traverse_children(math::TransformStack &ts, sgl::BV &bv)
{
    sgl::BV b;
    bool any = false;
    b.start();
    for (std::list<common::handle<Node> >::iterator it = _children.begin(); it != _children.end(); ++it) {
        if (hnull(*it))
            continue;
        if ((*it)->calcbv(ts, bv)) {
            b.add(bv);
            any = true;
        }
    }
    b.finish();
    bv = b;
    if (_bvdata.valid() && any)
        *_bvdata._bv = b;
    return any;
}

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

bool scene::Mesh::calcbv(math::TransformStack &, sgl::BV &bv)
{
    bv = _bvdata.get();
    const float *h = bv._h;
    /* STAND-IN: the original emits BVdata::get's __PRETTY_FUNCTION__ before this function's; a
       function's own one is declared at the top of its body (finish_fname_decls), so this block-scope
       static with its label (declared after the inlined get) reproduces the .rodata order */
    static const char name[] __asm__("_ZZN5scene4Mesh6calcbvERN4math14TransformStackERN3sgl2BVEE19__PRETTY_FUNCTION__") =
        "virtual bool scene::Mesh::calcbv(math::TransformStack&, sgl::BV&)";
    SCENE_WARN(h[0] != 0.f, " *** warning ", "_BV.getHalfSize().x() != 0.f", "../lib/scene/Graph_calcbv.cpp",
               name, 168, getName().c_str());
    SCENE_WARN(h[1] != 0.f, " *** warning ", "_BV.getHalfSize().y() != 0.f", "../lib/scene/Graph_calcbv.cpp",
               name, 169, getName().c_str());
    SCENE_WARN(h[2] != 0.f, " *** warning ", "_BV.getHalfSize().z() != 0.f", "../lib/scene/Graph_calcbv.cpp",
               name, 170, getName().c_str());
    return true;
}

bool scene::Switch::calcbv(math::TransformStack &ts, sgl::BV &bv)
{
    int sel = getSelected();
    if (sel < 0 || sel >= (int)children().size())
        return false;
    const std::list<common::handle<Node> > &c = children();
    std::list<common::handle<Node> >::const_iterator it = c.begin();
    for (; sel != 0; sel--)
        ++it;
    common::handle<Node> child = *it;
    return child->calcbv(ts, bv);
}
