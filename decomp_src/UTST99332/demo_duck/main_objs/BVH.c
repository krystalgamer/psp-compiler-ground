/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/BVH", _Z41__static_initialization_and_destruction_0ii_A49E0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/BVH", _ZN3BVHC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/BVH", _ZN3BVHC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/BVH", _ZNK3BVH4Node4drawEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/BVH", _ZNK3BVH4drawEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/BVH", _ZN3BVH8setChildENS_4Node9ChildEnumEPS0_S2_);

void BVH::print()
{
    print(&_root);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/BVH", _ZN3BVH5printEPNS_4NodeE);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_A49E0");
void _GLOBAL__I__ZN3BVHC2Ev(void);
void _GLOBAL__D__ZN3BVHC2Ev(void);
}

void _GLOBAL__I__ZN3BVHC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3BVHC2Ev(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/BVH", _ZN3BVH4NodeD1Ev);
