/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN2sh14SphereSampling6SampleC2Ev");
__asm__(".globl _GLOBAL__D__ZN2sh14SphereSampling6SampleC2Ev");

extern const float D_00173BBC;      /* 2^-30 */
extern const float D_00173BC0;      /* 0.5 */
extern const float D_00173BC4;

extern const char D_00173BDC[];     /* "sphere sampling constructed, n=" */
extern const char D_00173BFC[];     /* "\n" */

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

extern const char D_00173C30[], D_00173C34[], D_00173C58[], D_00173CA8[], D_00173CC4[];
/* create_samples (matches with literals: tmp/cxx/drafts/s31/ss/c_match.c) waits for the unit's full .rodata carve:
   its inlined canonical_random_var uses the function's own pool copies */
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZN2sh14SphereSampling14create_samplesEi);


extern const char precalc_name[] __asm__("_ZZN2sh14SphereSampling17precalc_sh_coeffsEvE19__PRETTY_FUNCTION__");
void sh::SphereSampling::precalc_sh_coeffs()
{
    for (std::vector<Sample>::iterator it = _samples.begin(); it != _samples.end(); ++it) {
        int count = 0;
        for (int l = 0; l < BANDS; l++)
            for (int m = -l; m <= l; m++) {
                unsigned int i = l * (l + 1) + m;
                SGL_ASSERT(i < COEFFS, D_00173C34, D_00173CA8, D_00173C58, precalc_name, 204, D_00173C30);
                it->sh[i] = math::SH::Eval(l, m, it->_theta, it->_phi);
                count++;
            }
        SGL_ASSERT(count == COEFFS, D_00173C34, D_00173CC4, D_00173C58, precalc_name, 212, D_00173C30);
    }
}


INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SphereSampling_Sample", _ZN2sh14SphereSampling9partitionEv);

extern "C" void sh_SphereSampling_Sample_instances(std::vector<sh::SphereSampling::Sample> *v, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void sh_SphereSampling_Sample_instances(std::vector<sh::SphereSampling::Sample> *v, unsigned int n)
{
    std::vector<sh::SphereSampling::Sample> c(*v);
    v->resize(n);
}
