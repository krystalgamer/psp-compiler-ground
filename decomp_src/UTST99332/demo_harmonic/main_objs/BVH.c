/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
/* (BVH() is still asm: its deferred-asm wrapper is the first public symbol cc1plus sees) */
__asm__(".globl _GLOBAL__I__ZN3BVHC2Ev\n_GLOBAL__I__ZN3BVHC2Ev = _GLOBAL__I__ZN3BVHC2Ev__asm");
__asm__(".globl _GLOBAL__D__ZN3BVHC2Ev\n_GLOBAL__D__ZN3BVHC2Ev = _GLOBAL__D__ZN3BVHC2Ev__asm");

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/BVH", _ZN3BVHC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/BVH", _ZN3BVHC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/BVH", _ZNK3BVH4Node4drawEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/BVH", _ZNK3BVH4drawEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/BVH", _ZN3BVH8setChildENS_4Node9ChildEnumEPS0_S2_);

void BVH::print()
{
    print(&_root);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/BVH", _ZN3BVH5printEPNS_4NodeE);

/* BVH::Node's inline destructor (weak copy in the tail), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/BVH", _ZN3BVH4NodeD1Ev);
