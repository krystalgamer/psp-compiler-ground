/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#include "../main.hpp"

__asm__(".globl _GLOBAL__I__ZN3sgl10MeshParamsC2Ev");
__asm__(".globl _GLOBAL__D__ZN3sgl10MeshParamsC2Ev");

sgl::MeshParams::MeshParams()
{
    _bools.resize(21);
    _floats.resize(6);
    _float4s.resize(1);
    _ints.resize(4);
    reset();
}


void sgl::MeshParams::reset()
{
    set((ParamsBool)0, false);
    set((ParamsBool)1, false);
    set((ParamsBool)2, false);
    set((ParamsBool)3, false);
    set((ParamsBool)4, false);
    set((ParamsBool)5, false);
    set((ParamsBool)6, false);
    set((ParamsBool)7, false);
    set((ParamsBool)8, false);
    set((ParamsBool)9, false);
    set((ParamsBool)13, false);
    set((ParamsBool)14, false);
    set((ParamsBool)12, false);
    set((ParamsBool)10, false);
    set((ParamsBool)11, false);
    set((ParamsBool)15, false);
    set((ParamsBool)16, false);
    set((ParamsBool)17, true);
    set((ParamsBool)18, false);
    set((ParamsBool)19, false);
    set((ParamsBool)20, true);
    set((ParamsFloat)0, 60.0f);
    set((ParamsFloat)1, 1e-5f);
    set((ParamsFloat)2, 1e-6f);
    set((ParamsFloat)3, 1e-6f);
    set((ParamsFloat)4, 1e-6f);
    set((ParamsFloat)5, 1e-6f);
    set((ParamsInt)0, 0);
    set((ParamsInt)1, 3);
    set((ParamsInt)2, -1);
    set((ParamsInt)3, -1);
    set((ParamsFloat4)0, math::vector_xyzw(0.8f, 0.8f, 0.8f, 0));
}

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
    set(ParamsFloat4(0), math::vector_xyzw(0.8f, 0.8f, 0.8f, 0));
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

/* std::vector<float> instances used by the asm above (MeshParams(), reset()): referenced from a
   discarded function */
extern "C" void sgl_MeshParams_instances(std::vector<float> *v, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void sgl_MeshParams_instances(std::vector<float> *v, unsigned int n)
{
    v->resize(n);
}
