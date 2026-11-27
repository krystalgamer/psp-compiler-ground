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


extern "C" void sh_SphereSampling_Sample_instances(std::vector<sh::SphereSampling::Sample> *v, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void sh_SphereSampling_Sample_instances(std::vector<sh::SphereSampling::Sample> *v, unsigned int n)
{
    std::vector<sh::SphereSampling::Sample> c(*v);
    v->resize(n);
}
