/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_2", _Z41__static_initialization_and_destruction_0ii_B2ABC);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_2", _ZNK3sgl4Mesh4drawEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_2", _ZNK3sgl4Mesh11draw_vertexEjjjjjjfb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_2", _ZNK3sgl4Mesh14draw_trianglesEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_2", _ZNK3sgl4Mesh15draw_primitivesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_2", _ZN3sgl17StencilShadowData6updateEN4math11vector_xyzwERKNS1_6matrixEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_2", _ZN3sgl17StencilShadowData4drawEj);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_B2ABC");
void _GLOBAL__I__ZNK3sgl4Mesh4drawEj(void);
void _GLOBAL__D__ZNK3sgl4Mesh4drawEj(void);
}

void _GLOBAL__I__ZNK3sgl4Mesh4drawEj(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZNK3sgl4Mesh4drawEj(void)
{
    static_init(0, 0xFFFF);
}

