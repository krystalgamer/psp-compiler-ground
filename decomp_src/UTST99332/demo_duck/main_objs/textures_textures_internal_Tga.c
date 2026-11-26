/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_textures_internal_Tga", _Z41__static_initialization_and_destruction_0ii_107670);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN8textures17textures_internal3Tga4loadEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN8textures17textures_internal3Tga10load_errorENS1_5ErrorEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN8textures7SaveTgaEPKciiPKhi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN8textures12SaveGlBufferEPKci);

void textures::TgaSnapshot(const char *name)
{
    SaveGlBuffer(name, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN8textures20TgaAutoNamedSnapshotEPKc);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_107670");
void _GLOBAL__I__ZN8textures17textures_internal3Tga4loadEPKc(void);
void _GLOBAL__D__ZN8textures17textures_internal3Tga4loadEPKc(void);
}

void _GLOBAL__I__ZN8textures17textures_internal3Tga4loadEPKc(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN8textures17textures_internal3Tga4loadEPKc(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN8textures17textures_internal3TgaD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN8textures17textures_internal3TgaD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN10byte_array4readIhEEvjRT_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN10byte_array5writeIhEEvjT_);

