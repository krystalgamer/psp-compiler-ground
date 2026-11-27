/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor, keyed to Group::_magic_number
   (initialized .data, defined at the top of the original; it stays asm data here, so cc1plus keys them to the
   constructor) */
__asm__(".globl _GLOBAL__I__ZN5scene5Group13_magic_numberE\n_GLOBAL__I__ZN5scene5Group13_magic_numberE = _GLOBAL__I__ZN5scene5GroupC2ESsb");
__asm__(".globl _GLOBAL__D__ZN5scene5Group13_magic_numberE\n_GLOBAL__D__ZN5scene5Group13_magic_numberE = _GLOBAL__D__ZN5scene5GroupC2ESsb");
SCENE_ALLOC_FIRST_USE
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZNK5scene5Group11getTypeNameEv)
    SCENE_LINKONCE(_ZNK5scene5Group5cloneESs)
    SCENE_LINKONCE(_ZNK5scene5Group7isGroupEv)
    SCENE_LINKONCE(_ZNK5scene5Group10isClonableEv)
    SCENE_LINKONCE(_ZNSt4listIN6common6handleIN5scene4NodeEEESaIS4_EEaSERKS6_)
    SCENE_LINKONCE(_ZNSt4listIN6common6handleIN5scene4NodeEEESaIS4_EE5eraseESt14_List_iteratorIS4_RS4_PS4_E)
);

extern const char D_0016881C[];

/* the strings stay in the module's .rodata (asm) */
extern const char D_001688A8[];     /* " " */
extern const char D_001688AC[];     /* " *** error " */
extern const char D_001688C4[];     /* "../lib/scene/Group.cpp" */
extern const char D_00168994[];     /* "_children.empty()" */
extern const char clearChildren_name[] __asm__("_ZZN5scene5Group13clearChildrenEbE19__PRETTY_FUNCTION__");

/* inline in the class (weak copies emitted with the vtable, in the object's tail) */
SGL_LINKONCE_BEGIN
inline const char *scene::Group::getTypeName() const
{
    return D_0016881C;
}

inline bool scene::Group::isGroup() const
{
    return true;
}

inline bool scene::Group::isClonable() const
{
    return true;
}
SGL_LINKONCE_END

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Group", _ZN5scene5Group8addChildEN6common6handleIS0_EENS2_INS_4NodeEEE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Group", _ZN5scene5Group8addChildEN6common6handleIS0_EES3_NS2_INS_4NodeEEE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Group", _ZN5scene5Group11removeChildEN6common6handleINS_4NodeEEE);

void scene::Group::clearChildren(bool decr)
{
    for (std::list<common::handle<Node> >::iterator it = _children.begin(); it != _children.end(); ++it) {
        if (hnull(*it))
            continue;
        if (decr)
            (*it)->decrParentCount();
    }
    _children.clear();
    SCENE_ASSERT(_children.empty(), D_001688AC, D_00168994, D_001688C4, clearChildren_name, 104, D_001688A8);
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

/* used by clone() (asm) */
template std::list<common::handle<scene::Node> > &std::list<common::handle<scene::Node> >::operator=(const std::list<common::handle<scene::Node> > &);
template std::list<common::handle<scene::Node> >::iterator std::list<common::handle<scene::Node> >::erase(std::list<common::handle<scene::Node> >::iterator);

/* the object's weak tail (linkonce copies), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Group", _ZNK5scene5Group5cloneESs);
