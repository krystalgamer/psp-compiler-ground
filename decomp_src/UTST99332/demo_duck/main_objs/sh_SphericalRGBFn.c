/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphericalRGBFn", _Z41__static_initialization_and_destruction_0ii_F1214);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphericalRGBFn", _ZNK2sh14SphericalRGBFn6eval_bEffRfS1_S1_if);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphericalRGBFn", _ZNK2sh14SphericalRGBFn21write_image_cube_faceER10FloatImageijif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphericalRGBFn", _ZNK2sh14SphericalRGBFn11saveCubeMapEPKcPPN8textures7TextureEjif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphericalRGBFn", _ZNK2sh14SphericalRGBFn14saveAngularMapEbPKcPN8textures7TextureEjif);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_F1214");
void _GLOBAL__I__ZNK2sh14SphericalRGBFn6eval_bEffRfS1_S1_if(void);
void _GLOBAL__D__ZNK2sh14SphericalRGBFn6eval_bEffRfS1_S1_if(void);
}

void _GLOBAL__I__ZNK2sh14SphericalRGBFn6eval_bEffRfS1_S1_if(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZNK2sh14SphericalRGBFn6eval_bEffRfS1_S1_if(void)
{
    static_init(0, 0xFFFF);
}

