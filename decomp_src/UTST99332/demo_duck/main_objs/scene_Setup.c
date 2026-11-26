/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Setup", _Z41__static_initialization_and_destruction_0ii_91EDC);

scene::Setup::Setup(std::string name, bool b) : Node(name, b)
{
    set_default_name();
}

scene::Setup::~Setup()
{
}

void scene::Setup::flatten(math::TransformStack &) {
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_91EDC");
void _GLOBAL__I__ZN5scene5SetupC2ESsb(void);
void _GLOBAL__D__ZN5scene5SetupC2ESsb(void);
}

void _GLOBAL__I__ZN5scene5SetupC2ESsb(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene5SetupC2ESsb(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Setup", _ZNK5scene5Setup11getTypeNameEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Setup", _ZNK5scene5Setup5cloneESs);

void scene::Setup::enter() {
}

void scene::Setup::leave() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Setup", _ZN6common6handleIN5scene4NodeEEC1INS1_5SetupEEERKNS0_IT_EE);

