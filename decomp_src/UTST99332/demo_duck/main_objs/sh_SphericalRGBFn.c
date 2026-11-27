/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZNK2sh14SphericalRGBFn6eval_bEffRfS1_S1_if\n_GLOBAL__I__ZNK2sh14SphericalRGBFn6eval_bEffRfS1_S1_if = _GLOBAL__I__ZNK2sh14SphericalRGBFn6eval_bEffRfS1_S1_if__asm");
__asm__(".globl _GLOBAL__D__ZNK2sh14SphericalRGBFn6eval_bEffRfS1_S1_if\n_GLOBAL__D__ZNK2sh14SphericalRGBFn6eval_bEffRfS1_S1_if = _GLOBAL__D__ZNK2sh14SphericalRGBFn6eval_bEffRfS1_S1_if__asm");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphericalRGBFn", _ZNK2sh14SphericalRGBFn6eval_bEffRfS1_S1_if);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphericalRGBFn", _ZNK2sh14SphericalRGBFn21write_image_cube_faceER10FloatImageijif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphericalRGBFn", _ZNK2sh14SphericalRGBFn11saveCubeMapEPKcPPN8textures7TextureEjif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphericalRGBFn", _ZNK2sh14SphericalRGBFn14saveAngularMapEbPKcPN8textures7TextureEjif);
