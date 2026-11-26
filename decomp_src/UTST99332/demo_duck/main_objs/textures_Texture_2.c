/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture_2", _Z41__static_initialization_and_destruction_0ii_106860);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture_2", _ZN8textures7Texture6initGlEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture_2", _ZN8textures7Texture14setGlFilteringEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture_2", _ZN8textures7Texture10setGlWrapSEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture_2", _ZN8textures7Texture10setGlWrapTEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture_2", _ZN8textures7Texture16setGlTextureFuncEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture_2", _ZN8textures7Texture7setupGlEib);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture_2", _ZN8textures7Texture6drawGLEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_106860");
void _GLOBAL__I__ZN8textures7Texture6initGlEi(void);
void _GLOBAL__D__ZN8textures7Texture6initGlEi(void);
}

void _GLOBAL__I__ZN8textures7Texture6initGlEi(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN8textures7Texture6initGlEi(void)
{
    static_init(0, 0xFFFF);
}

