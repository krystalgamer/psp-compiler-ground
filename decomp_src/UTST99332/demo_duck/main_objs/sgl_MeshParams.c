/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const float D_00171184;      /* 0.8f */

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _Z41__static_initialization_and_destruction_0ii_CE0FC);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _ZN3sgl10MeshParamsC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _ZN3sgl10MeshParamsC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshParams", _ZN3sgl10MeshParams5resetEv);

void sgl::MeshParams::set0(float v)
{
    set(ParamsBool(1), true);
    set(ParamsBool(2), true);
    set(ParamsBool(3), true);
    set(ParamsBool(4), true);
    set(ParamsBool(5), true);
    set(ParamsBool(6), true);
    set(ParamsBool(7), true);
    set(ParamsBool(8), false);
    set(ParamsBool(9), true);
    set(ParamsFloat(0), v);
    set(ParamsFloat4(0), math::vector_xyzw(D_00171184, D_00171184, D_00171184, 0));
    set(ParamsBool(18), false);
}

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

/* std::vector<float> instances used by the asm above (MeshParams(), reset()): referenced from a
   discarded function */
extern "C" void sgl_MeshParams_instances(std::vector<float> *v, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void sgl_MeshParams_instances(std::vector<float> *v, unsigned int n)
{
    v->resize(n);
}

