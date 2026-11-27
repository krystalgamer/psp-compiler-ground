/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const float D_00173BBC;      /* 2^-30 */
extern const float D_00173BC0;      /* 0.5 */
extern const float D_00173BC4;

extern const char D_00173BDC[];     /* "sphere sampling constructed, n=" */
extern const char D_00173BFC[];     /* "\n" */
namespace std {
extern template vector<sh::SphereSampling::Sample>::iterator vector<sh::SphereSampling::Sample>::erase(iterator, iterator);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _Z41__static_initialization_and_destruction_0ii_EF3B4);

sh::SphereSampling::Sample::Sample()
{
}



void sh::SphereSampling::swap(SphereSampling &o)
{
    _samples.swap(o._samples);
}

sh::SphereSampling::SphereSampling(unsigned int n) : Icosahedron(2)
{
    _samples.clear();
    if (n) {
        create_samples(n);
        partition();
        precalc_sh_coeffs();
        Log_uint(common::Log() << D_00173BDC, n) << D_00173BFC;
    }
}



float sh::SphereSampling::canonical_random_var(unsigned int n)
{
    n = (n << 13) ^ n;
    unsigned int r = (n * (n * n * 15731 + 789221) + 1376312589) & 0x7FFFFFFF;
    return r * D_00173BBC * D_00173BC0;
}

sh::Vector sh::SphereSampling::project1() const
{
    Vector r;
    for (std::vector<Sample>::const_iterator it = _samples.begin(); it != _samples.end(); ++it)
        for (unsigned int i = 0; i < COEFFS; i++)
            r[i] += it->_value * it->sh[i];
    float k = D_00173BC4 / _samples.size();
    for (unsigned int i = 0; i < COEFFS; i++)
        r[i] *= k;
    return r;
}

sh::Vector sh::SphereSampling::project(float (*fn)(float, float))
{
    for (std::vector<Sample>::iterator it = _samples.begin(); it != _samples.end(); ++it)
        it->_value = fn(it->_theta, it->_phi);
    return project1();
}

sh::VectorRGB sh::SphereSampling::project()
{
    VectorRGB c;
    for (std::vector<Sample>::iterator it = _samples.begin(); it != _samples.end(); ++it)
        it->_value = it->_r;
    c.r = project1();
    for (std::vector<Sample>::iterator it = _samples.begin(); it != _samples.end(); ++it)
        it->_value = it->_g;
    c.g = project1();
    for (std::vector<Sample>::iterator it = _samples.begin(); it != _samples.end(); ++it)
        it->_value = it->_b;
    c.b = project1();
    return c;
}

sh::VectorRGB sh::SphereSampling::project(const SphericalRGBFn *f)
{
    for (std::vector<Sample>::iterator it = _samples.begin(); it != _samples.end(); ++it)
        f->eval(it->_theta, it->_phi, it->_r, it->_g, it->_b);
    return project();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZN2sh14SphereSampling14create_samplesEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZN2sh14SphereSampling17precalc_sh_coeffsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZN2sh14SphereSampling9partitionEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_EF3B4");
void _GLOBAL__I__ZN2sh14SphereSampling6SampleC2Ev(void);
void _GLOBAL__D__ZN2sh14SphereSampling6SampleC2Ev(void);
}

void _GLOBAL__I__ZN2sh14SphereSampling6SampleC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN2sh14SphereSampling6SampleC2Ev(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZNSt6vectorIN2sh14SphereSampling6SampleESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN2sh14SphereSampling6SampleESt6vectorIS4_SaIS4_EEEEPS4_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZNSt6vectorIN2sh14SphereSampling6SampleESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN2sh14SphereSampling6SampleESt6vectorIS4_SaIS4_EEEES4_EvT_SA_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZSt24__uninitialized_copy_auxIPN2sh14SphereSampling6SampleES3_ET0_T_S5_S4_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZSt26__uninitialized_fill_n_auxIPN2sh14SphereSampling6SampleEjS2_ET_S4_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN2sh14SphereSampling6SampleESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN2sh14SphereSampling6SampleESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN2sh14SphereSampling6SampleESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type);
