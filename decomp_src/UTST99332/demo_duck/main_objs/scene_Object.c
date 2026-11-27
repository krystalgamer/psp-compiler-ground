/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const char D_0016CBD4[];

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Object", _Z41__static_initialization_and_destruction_0ii_915F8);

scene::Object::Object(std::string name, bool b) : Group(name, b)
{
    set_default_name();
}

scene::Object::~Object()
{
}

void scene::Object::flatten(math::TransformStack &ts)
{
    Group::flatten(ts);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_915F8");
void _GLOBAL__I__ZN5scene6ObjectC2ESsb(void);
void _GLOBAL__D__ZN5scene6ObjectC2ESsb(void);
}

void _GLOBAL__I__ZN5scene6ObjectC2ESsb(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene6ObjectC2ESsb(void)
{
    static_init(0, 0xFFFF);
}

const char *scene::Object::getTypeName() const
{
    return D_0016CBD4;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Object", _ZNK5scene6Object5cloneESs);

