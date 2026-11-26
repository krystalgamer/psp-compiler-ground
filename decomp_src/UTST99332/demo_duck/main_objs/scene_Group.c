/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* the strings stay in the module's .rodata (asm) */
extern const char D_0016B7D0[];     /* " " */
extern const char D_0016B7D4[];     /* " *** error " */
extern const char D_0016B7EC[];     /* "../lib/scene/Group.cpp" */
extern const char D_0016B8BC[];     /* "_children.empty()" */
extern const char clearChildren_name[] __asm__("_ZZN5scene5Group13clearChildrenEbE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Group", _Z41__static_initialization_and_destruction_0ii_85A08);

scene::Group::Group(std::string name, bool b) : Node(name, b)
{
    set_default_name();
}

scene::Group::~Group()
{
    clearChildren(true);
}

void scene::Group::addChild(common::handle<Node> n)
{
    if (hnull(n))
        return;
    n->incrParentCount();
    _children.push_back(n);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Group", _ZN5scene5Group8addChildEN6common6handleIS0_EENS2_INS_4NodeEEE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Group", _ZN5scene5Group8addChildEN6common6handleIS0_EES3_NS2_INS_4NodeEEE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Group", _ZN5scene5Group11removeChildEN6common6handleINS_4NodeEEE);

void scene::Group::clearChildren(bool decr)
{
    for (std::list<common::handle<Node> >::iterator it = _children.begin(); it != _children.end(); ++it) {
        if (hnull(*it))
            continue;
        if (decr)
            (*it)->decrParentCount();
    }
    _children.clear();
    SCENE_ASSERT(_children.empty(), D_0016B7D4, D_0016B8BC, D_0016B7EC, clearChildren_name, 104, D_0016B7D0);
}

void scene::Group::flatten(math::TransformStack &ts)
{
    for (std::list<common::handle<Node> >::iterator it = _children.begin(); it != _children.end(); ++it)
        (*it)->flatten(ts);
}

std::list<common::handle<scene::Node> > &scene::Group::children()
{
    return _children;
}

const std::list<common::handle<scene::Node> > &scene::Group::children() const
{
    return _children;
}

void scene::Group::traverse(TraversalType type, sgl::Frustum &frustum, const math::matrix &m0, const math::matrix &m1,
                            const math::matrix &m2, const sh::VectorRGB &light, float f)
{
    TraversalVarStack tvs(type, frustum, m0, m1, m2, light, f);
    traverse(tvs);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_85A08");
void _GLOBAL__I__ZN5scene5Group13_magic_numberE(void);
void _GLOBAL__D__ZN5scene5Group13_magic_numberE(void);
}

void _GLOBAL__I__ZN5scene5Group13_magic_numberE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene5Group13_magic_numberE(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Group", _ZNK5scene5Group11getTypeNameEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Group", _ZNK5scene5Group5cloneESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Group", _ZNK5scene5Group7isGroupEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Group", _ZNK5scene5Group10isClonableEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Group", _ZNSt4listIN6common6handleIN5scene4NodeEEESaIS4_EEaSERKS6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Group", _ZNSt4listIN6common6handleIN5scene4NodeEEESaIS4_EE5eraseESt14_List_iteratorIS4_RS4_PS4_E);

