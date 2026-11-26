/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _Z41__static_initialization_and_destruction_0ii_CE0FC);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _ZN3sgl10MeshParamsC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _ZN3sgl10MeshParamsC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _ZN3sgl10MeshParams5resetEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _ZN3sgl10MeshParams4set0Ef);

void sgl::MeshParams::set(ParamsBool p, bool b)
{
    _bools[p] = b;
}

bool sgl::MeshParams::get(ParamsBool p) const
{
    return _bools[p];
}

void sgl::MeshParams::set(ParamsInt p, int v)
{
    _ints[p] = v;
}

int sgl::MeshParams::get(ParamsInt p) const
{
    return _ints[p];
}

void sgl::MeshParams::set(ParamsFloat p, float v)
{
    _floats[p] = v;
}

float sgl::MeshParams::get(ParamsFloat p) const
{
    return _floats[p];
}

void sgl::MeshParams::set(ParamsFloat4 p, math::vector_xyzw v)
{
    _float4s[p] = v;
}

void sgl::MeshParams::set(ParamsFloat4 p, float x, float y, float z, float w)
{
    _float4s[p] = math::vector_xyzw(x, y, z, w);
}

math::vector_xyzw sgl::MeshParams::get(ParamsFloat4 p) const
{
    return _float4s[p];
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_CE0FC");
void _GLOBAL__I__ZN3sgl10MeshParamsC2Ev(void);
void _GLOBAL__D__ZN3sgl10MeshParamsC2Ev(void);
}

void _GLOBAL__I__ZN3sgl10MeshParamsC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sgl10MeshParamsC2Ev(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _ZNSt6vectorIfSaIfEE5eraseEN9__gnu_cxx17__normal_iteratorIPfS1_EES5_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _ZNSt6vectorIfSaIfEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPfS1_EEjRKf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEEfEvT_S7_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _ZSt6fill_nIPfjfET_S1_T0_RKT1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _ZSt6fill_nIN9__gnu_cxx17__normal_iteratorIPfSt6vectorIfSaIfEEEEjfET_S7_T0_RKT1_);
