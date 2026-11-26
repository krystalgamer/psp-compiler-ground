/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Switch", _Z41__static_initialization_and_destruction_0ii_92064);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Switch", _ZN5scene6SwitchC2ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Switch", _ZN5scene6SwitchC1ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Switch", _ZN5scene6SwitchD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Switch", _ZN5scene6SwitchD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Switch", _ZN5scene6SwitchD0Ev);

void scene::Switch::select(int v)
{
    _f30 = v;
}

int scene::Switch::getSelected() const
{
    return _f30;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Switch", _ZN5scene6Switch7flattenERN4math14TransformStackE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Switch", _ZN5scene6Switch8getChildEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_92064");
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Switch", _ZNK5scene6Switch11getTypeNameEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Switch", _ZNK5scene6Switch5cloneESs);
