/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SCENE_BVDATA_LITERALS
#define SCENE_BVDATA_CREATE
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZNK5scene6Switch11getTypeNameEv)
    SCENE_LINKONCE(_ZNK5scene6Switch5cloneESs)
);

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene6SwitchC2ESsb");
__asm__(".globl _GLOBAL__D__ZN5scene6SwitchC2ESsb");

/* inline in the class (weak copies emitted with the vtable, in the object's tail) */
SGL_LINKONCE_BEGIN
inline const char *scene::Switch::getTypeName() const
{
    return "Switch";
}
/* clone() (asm) inlines Switch::operator= -> BVdata::operator= -> create(): create's __PRETTY_FUNCTION__
   stays in .rodata (its warning is dead code); this linkonce copy (discarded by the link) emits it there */
inline void Switch_refs(scene::Switch &a, const scene::Switch &b)
{
    a = b;
}
SGL_LINKONCE_END

scene::Switch::Switch(std::string name, bool b) : Group(name, b), _selected(-1)
{
    set_default_name();
}

scene::Switch::~Switch()
{
}

void scene::Switch::select(int v)
{
    _selected = v;
}

int scene::Switch::getSelected() const
{
    return _selected;
}

void scene::Switch::flatten(math::TransformStack &ts)
{
    Group::flatten(ts);
}

common::handle<scene::Node> scene::Switch::getChild()
{
    if (_selected < 0 || _selected >= (int)children().size())
        return common::handle<Node>();
    const std::list<common::handle<Node> > &c = children();
    std::list<common::handle<Node> >::const_iterator it = c.begin();
    for (int i = 0; i < _selected; i++)
        ++it;
    return *it;
}

/* inline in the class too (weak copies in the tail), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Switch", _ZNK5scene6Switch5cloneESs);
