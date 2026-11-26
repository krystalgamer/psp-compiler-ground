/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_5", _Z41__static_initialization_and_destruction_0ii_826CC);

void scene::Graph::save_vrml(std::string) {
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_826CC");
void _GLOBAL__I__ZN5scene5Graph9save_vrmlESs(void);
void _GLOBAL__D__ZN5scene5Graph9save_vrmlESs(void);
}

void _GLOBAL__I__ZN5scene5Graph9save_vrmlESs(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene5Graph9save_vrmlESs(void)
{
    static_init(0, 0xFFFF);
}

