/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_3", _Z41__static_initialization_and_destruction_0ii_B478C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_3", _ZN3sgl4Mesh4saveEPKcSsbf);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_B478C");
void _GLOBAL__I__ZN3sgl4Mesh4saveEPKcSsbf(void);
void _GLOBAL__D__ZN3sgl4Mesh4saveEPKcSsbf(void);
}

void _GLOBAL__I__ZN3sgl4Mesh4saveEPKcSsbf(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sgl4Mesh4saveEPKcSsbf(void)
{
    static_init(0, 0xFFFF);
}

