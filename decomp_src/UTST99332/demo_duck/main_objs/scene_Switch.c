/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Switch", _Z41__static_initialization_and_destruction_0ii_94488);

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

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_94488");
void _GLOBAL__I__ZN5scene6SwitchC2ESsb(void);
void _GLOBAL__D__ZN5scene6SwitchC2ESsb(void);
}

void _GLOBAL__I__ZN5scene6SwitchC2ESsb(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene6SwitchC2ESsb(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Switch", _ZNK5scene6Switch11getTypeNameEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Switch", _ZNK5scene6Switch5cloneESs);

