/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN2sh14SphereSampling6SampleC2Ev");
__asm__(".globl _GLOBAL__D__ZN2sh14SphereSampling6SampleC2Ev");



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
        Log_uint(common::Log() << "sphere sampling constructed, n=", n) << "\n";
    }
}

float sh::SphereSampling::canonical_random_var(unsigned int n)
{
    n = (n << 13) ^ n;
    unsigned int r = (n * (n * n * 15731 + 789221) + 1376312589) & 0x7FFFFFFF;
    return r * 9.31322574615e-10f * 0.5f;
}

sh::Vector sh::SphereSampling::project1() const
{
    Vector r;
    for (std::vector<Sample>::const_iterator it = _samples.begin(); it != _samples.end(); ++it)
        for (unsigned int i = 0; i < COEFFS; i++)
            r[i] += it->_value * it->sh[i];
    float k = 12.566371f / _samples.size();
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

void sh::SphereSampling::create_samples(int n)
{
    _samples.resize(n * n);
    float inv = 1.0f / n;
    unsigned int index = 0;
    unsigned int seed = 0;
    for (int a = 0; a != n; a++)
        for (int b = 0; b != n; b++) {
            float x = (a + canonical_random_var(seed++)) * inv;
            float y = (b + canonical_random_var(seed++)) * inv;
            float theta = 2.0f * acosf(sqrtf(1.0f - x));
            float phi = 6.28318530f * y;
            SGL_ASSERT(index < _samples.size(), " *** error ", "index < _samples.size()", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 183, " ");
            _samples[index++].set(theta, phi);
        }
}



void sh::SphereSampling::precalc_sh_coeffs()
{
    for (std::vector<Sample>::iterator it = _samples.begin(); it != _samples.end(); ++it) {
        int count = 0;
        for (int l = 0; l < BANDS; l++)
            for (int m = -l; m <= l; m++) {
                unsigned int i = l * (l + 1) + m;
                SGL_ASSERT(i < COEFFS, " *** error ", "i < sh::Vector::COEFF_SIZE", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 204, " ");
                it->sh[i] = math::SH::Eval(l, m, it->_theta, it->_phi);
                count++;
            }
        SGL_ASSERT(count == COEFFS, " *** error ", "count == sh::Vector::COEFF_SIZE", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 212, " ");
    }
}


/* STAND-IN: the colour is copied through an inline taking it by reference (y/z via a register base), maybe a Sample setter */
static inline void ss_col(float &r, float &g, float &b, const math::vector_xyzw &c) { r = c.x; g = c.y; b = c.z; }
void sh::SphereSampling::partition()
{
    for (std::vector<Sample>::iterator it = _samples.begin(); it != _samples.end(); ++it) {
        Bin *b = searchLeaf(it->point());
        SGL_ASSERT(b, " *** error ", "b", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 232, " ");
        ss_col(it->_r, it->_g, it->_b, b->_color);
    }
    std::vector<Bin *> bins;
    listBins(bins, getDepth());
    for (std::vector<Bin *>::iterator b = bins.begin(); b != bins.end(); ++b) {
        SGL_ASSERT((*b)->_depth == getDepth(), " *** error ", "(*b)->_depth == getDepth()", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 248, " ");
        SGL_ASSERT((*b)->_len == 0, " *** error ", "(*b)->_len == 0", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 249, " ");
        SGL_ASSERT((*b)->_indexes.size() == 0, " *** error ", "(*b)->_indexes.size() == 0", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 250, " ");
    }
    for (unsigned int i = 0; i != _samples.size(); i++) {
        Bin *b = searchLeaf(_samples[i].point());
        SGL_ASSERT(b, " *** error ", "b", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 260, " ");
        SGL_ASSERT(b->_depth == getDepth(), " *** error ", "b->_depth == getDepth()", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 261, " ");
        b->_indexes.push_back(i);
        b->_len++;
    }
    std::vector<unsigned int> reindexing;
    reindexing.resize(0);
    reindexing.reserve(_samples.size());
    unsigned int incr = 0;
    for (std::vector<Bin *>::iterator b = bins.begin(); b != bins.end(); ++b) {
        SGL_ASSERT((*b)->_len == (*b)->_indexes.size(), " *** error ", "(*b)->_len == (*b)->_indexes.size()", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 282, " ");
        SGL_ASSERT((*b)->_leaf, " *** error ", "(*b)->_leaf", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 283, " ");
        (*b)->_begin = incr;
        (*b)->_end = incr + (*b)->_len;
        for (std::vector<unsigned int>::iterator j = (*b)->_indexes.begin(); j != (*b)->_indexes.end(); ++j) {
            SGL_ASSERT(incr == reindexing.size(), " *** error ", "incr == reindexing.size()", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 293, " ");
            reindexing.push_back(*j);
            incr++;
        }
    }
    SGL_ASSERT(reindexing.size() == _samples.size(), " *** error ", "reindexing.size() == _samples.size()", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 301, " ");
    {
        std::vector<Sample> copy(_samples);
        for (unsigned int i = 0; i != _samples.size(); i++) {
            SGL_ASSERT(reindexing[i] >= 0 && reindexing[i] < _samples.size(), " *** error ", "reindexing[i] >= 0 && reindexing[i] < _samples.size()", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 323, " ");
            _samples[i] = copy[reindexing[i]];
        }
    }
    for (std::vector<Bin *>::iterator b = bins.begin(); b != bins.end(); ++b) {
        for (Bin *p = (*b)->_parent; p; p = p->_parent) {
            if (p->_len == 0) {
                p->_begin = (*b)->_begin;
                p->_end = (*b)->_end;
            } else {
                if ((*b)->_begin < p->_begin)
                    p->_begin = (*b)->_begin;
                if (p->_end < (*b)->_end)
                    p->_end = (*b)->_end;
            }
            p->_len += (*b)->_len;
        }
    }
    std::vector<Bin *> all;
    listAllBins(all);
    for (std::vector<Bin *>::iterator b = all.begin(); b != all.end(); ++b) {
        SGL_ASSERT((int)((*b)->_len) == (int)((*b)->_end - (*b)->_begin), " *** error ", "(int)( (*b)->_len ) == (int)( (*b)->_end - (*b)->_begin )", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 375, " ");
        for (unsigned int i = 0; i != (*b)->_len; i++)
            SGL_ASSERT((*b)->intersect(_samples[(*b)->_begin + i].point()), " *** error ", "(*b)->intersect( _samples[i].point() )", "../lib/sh/SphereSampling.cpp", __PRETTY_FUNCTION__, 385, " ");
    }
}


extern "C" void sh_SphereSampling_Sample_instances(std::vector<sh::SphereSampling::Sample> *v, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void sh_SphereSampling_Sample_instances(std::vector<sh::SphereSampling::Sample> *v, unsigned int n)
{
    std::vector<sh::SphereSampling::Sample> c(*v);
    v->resize(n);
}
