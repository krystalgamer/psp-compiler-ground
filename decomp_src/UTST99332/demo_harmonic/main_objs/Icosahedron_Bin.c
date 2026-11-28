/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN11Icosahedron3BinC2EN4math11vector_xyzwES2_S2_h\n_GLOBAL__I__ZN11Icosahedron3BinC2EN4math11vector_xyzwES2_S2_h = _GLOBAL__I__ZN11Icosahedron3BinC2EN4math11vector_xyzwES2_S2_h__asm");
__asm__(".globl _GLOBAL__D__ZN11Icosahedron3BinC2EN4math11vector_xyzwES2_S2_h\n_GLOBAL__D__ZN11Icosahedron3BinC2EN4math11vector_xyzwES2_S2_h = _GLOBAL__D__ZN11Icosahedron3BinC2EN4math11vector_xyzwES2_S2_h__asm");

#include "UTST99332/demo_duck/gl.hpp"
extern const float D_0016F86C;      /* 1.0f */
extern const char D_0016F904[];     /* " *** error " */
extern const char D_0016F934[];     /* "../lib/sh/Icosahedron.cpp" */
extern const char D_0016F950[];     /* " " */
extern const char D_0016FA4C[];     /* "_leaf" */
extern const char D_0016FCE8[];
extern const char listBins_name[] __asm__("_ZZN11Icosahedron8listBinsERSt6vectorIPNS_3BinESaIS2_EEhE19__PRETTY_FUNCTION__");
extern const char getLeafIndex_name[] __asm__("_ZZNK11Icosahedron3Bin12getLeafIndexEvE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/Icosahedron_Bin", _ZN11Icosahedron3BinC2EN4math11vector_xyzwES2_S2_h);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/Icosahedron_Bin", _ZN11Icosahedron3BinC1EN4math11vector_xyzwES2_S2_h);

Icosahedron::Bin::~Bin()
{
    delete _children[0];
    delete _children[1];
    delete _children[2];
    delete _children[3];
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/Icosahedron_Bin", _ZN11Icosahedron3Bin11setChildrenEPS0_S1_S1_S1_);

void Icosahedron::Bin::setBinIndex(unsigned int v)
{
    _f90 = v;
}

int Icosahedron::Bin::getBinIndex() const
{
    return _f90;
}

void Icosahedron::Bin::setLeafIndex(unsigned int v)
{
    _f94 = v;
}

int Icosahedron::Bin::getLeafIndex() const
{
    SGL_ASSERT(_leaf, D_0016F904, D_0016FA4C, D_0016F934, getLeafIndex_name, 113, D_0016F950);
    return _f94;
}

math::vector_xyzw Icosahedron::on_sphere(math::vector_xyzw v)
{
    math::vector_xyz t(v.x, v.y, v.z);
    float l = sqrtf(t.x * t.x + t.y * t.y + t.z * t.z);
    v.x /= l;
    v.y /= l;
    v.z /= l;
    return v;
}

/* STAND-IN: tri_subdiv (still asm) owns the static local color_count; it is defined here so that cc1plus
   emits it while expanding this position, between in_negative_half_space's guard (emitted at parse time) and o */
extern "C" void Icosahedron_tri_subdiv_statics(int v) __attribute__((section(".discard.asm")));
extern "C" void Icosahedron_tri_subdiv_statics(int v)
{
    static int color_count __asm__("_ZZN11Icosahedron10tri_subdivEN4math11vector_xyzwES1_S1_hhE11color_count");
    color_count = v;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/Icosahedron_Bin", _ZN11Icosahedron10tri_subdivEN4math11vector_xyzwES1_S1_hh);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/Icosahedron_Bin", _ZN11Icosahedron8draw_binERNS_3BinEh);

void Icosahedron::draw()
{
    draw(getDepth());
}

void Icosahedron::draw(unsigned char d)
{
    glColor3f(D_0016F86C, 0, D_0016F86C);
    for (std::vector<Bin *>::iterator it = _bins.begin(); it != _bins.end(); ++it)
        draw_bin(**it, d);
}

unsigned char Icosahedron::getDepth() const
{
    return _f0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/Icosahedron_Bin", _ZN11IcosahedronC2Eh);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/Icosahedron_Bin", _ZN11IcosahedronC1Eh);

Icosahedron::~Icosahedron()
{
    for (std::vector<Bin *>::iterator it = _bins.begin(); it != _bins.end(); ++it)
        delete *it;
}

extern const float D_0016F898;
extern const float D_0016F89C;
bool Icosahedron::Bin::intersect(math::vector_xyzw v) const
{
    math::vector_xyzw p(v.x * D_0016F898, v.y * D_0016F898, v.z * D_0016F898, D_0016F89C);
    if (math::dot(_face, p - _v[0]) < 0)
        return false;
    if (math::dot(_edge[0], p - _v[0]) > 0)
        return false;
    if (math::dot(_edge[1], p - _v[1]) > 0)
        return false;
    if (math::dot(_edge[2], p - _v[2]) > 0)
        return false;
    return true;
}


extern const float D_0016F8A0;
bool Icosahedron::Bin::in_negative_half_space(math::vector_xyzw v) const
{
    static const math::vector_xyzw o(0, 0, 0, D_0016F8A0);
    return math::dot(v, _v[0] - o) < 0 && math::dot(v, _v[1] - o) < 0 && math::dot(v, _v[2] - o) < 0;
}

Icosahedron::Bin *Icosahedron::Bin::searchLeaf(math::vector_xyzw v)
{
    bool out = !intersect(v);
    if (out)
        return 0;
    if (_leaf)
        return this;
    Bin *b = _children[0]->searchLeaf(v);
    if (b)
        return b;
    b = _children[1]->searchLeaf(v);
    if (b)
        return b;
    b = _children[2]->searchLeaf(v);
    if (b)
        return b;
    return _children[3]->searchLeaf(v);
}


Icosahedron::Bin *Icosahedron::searchLeaf(math::vector_xyzw v)
{
    for (std::vector<Bin *>::iterator it = _bins.begin(); it != _bins.end(); ++it) {
        Bin *b = (*it)->searchLeaf(v);
        if (b)
            return b;
    }
    return 0;
}

void Icosahedron::listBinsRec(std::vector<Bin *> &out, Bin *b, unsigned char depth)
{
    if (b->_depth == depth) {
        out.push_back(b);
        return;
    }
    if (b->_leaf)
        return;
    listBinsRec(out, b->_children[0], depth);
    listBinsRec(out, b->_children[1], depth);
    listBinsRec(out, b->_children[2], depth);
    listBinsRec(out, b->_children[3], depth);
}

void Icosahedron::listBins(std::vector<Bin *> &out, unsigned char depth)
{
    out.resize(0);
    for (std::vector<Bin *>::iterator it = _bins.begin(); it != _bins.end(); ++it)
        listBinsRec(out, *it, depth);
    SGL_ASSERT(out.size() == (unsigned int)(20 << (2 * depth)), D_0016F904, D_0016FCE8, D_0016F934, listBins_name, 501, D_0016F950);
}

void Icosahedron::listAllBinsRec(std::vector<Bin *> &out, Bin *b)
{
    out.push_back(b);
    if (b->_leaf)
        return;
    listAllBinsRec(out, b->_children[0]);
    listAllBinsRec(out, b->_children[1]);
    listAllBinsRec(out, b->_children[2]);
    listAllBinsRec(out, b->_children[3]);
}

void Icosahedron::listAllBins(std::vector<Bin *> &out)
{
    out.resize(0);
    for (std::vector<Bin *>::iterator it = _bins.begin(); it != _bins.end(); ++it)
        listAllBinsRec(out, *it);
}

void Icosahedron::listPosHalfSpaceLeafBinsRec(std::vector<Bin *> &out, Bin *b, const math::vector_xyzw &n)
{
    if (b->in_negative_half_space(n))
        return;
    if (b->_leaf) {
        out.push_back(b);
        return;
    }
    listPosHalfSpaceLeafBinsRec(out, b->_children[0], n);
    listPosHalfSpaceLeafBinsRec(out, b->_children[1], n);
    listPosHalfSpaceLeafBinsRec(out, b->_children[2], n);
    listPosHalfSpaceLeafBinsRec(out, b->_children[3], n);
}

void Icosahedron::listPosHalfSpaceLeafBins(std::vector<Bin *> &out, const math::vector_xyzw &n)
{
    out.resize(0);
    for (std::vector<Bin *>::iterator it = _bins.begin(); it != _bins.end(); ++it)
        listPosHalfSpaceLeafBinsRec(out, *it, n);
}

/* the original's .gnu.linkonce.t order */
DEMO_LINKONCE_ORDER(DEMO_LINKONCE(_ZNSt6vectorIPN11Icosahedron3BinESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_)
                    DEMO_LINKONCE(_ZNSt6vectorIN11icosahedron4FaceESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_)
                    DEMO_LINKONCE(_ZNSt6vectorIPN11Icosahedron3BinESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_)
                    DEMO_LINKONCE(_ZNSt6vectorIN11icosahedron4FaceESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN11icosahedron4FaceESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type)
                    DEMO_LINKONCE(_ZNSt6vectorIPN11Icosahedron3BinESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_)
                    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN11icosahedron4FaceESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_)
                    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPPN11Icosahedron3BinESt6vectorIS4_SaIS4_EEEES4_EvT_SA_RKT0_)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN11icosahedron4FaceES2_ET0_T_S4_S3_12__false_type)
                    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN11icosahedron4FaceEjS1_ET_S3_T0_RKT1_12__false_type)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN11icosahedron4FaceESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type)
                    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN11icosahedron4FaceESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type)
                    DEMO_LINKONCE(_ZSt6fill_nIPPN11Icosahedron3BinEjS2_ET_S4_T0_RKT1_)
                    DEMO_LINKONCE(_ZSt6fill_nIN9__gnu_cxx17__normal_iteratorIPPN11Icosahedron3BinESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_));

extern "C" void Icosahedron_Bin_instances(std::vector<icosahedron::Face> *v, const icosahedron::Face *f, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void Icosahedron_Bin_instances(std::vector<icosahedron::Face> *v, const icosahedron::Face *f, unsigned int n)
{
    v->push_back(*f);
    v->insert(v->end(), n, *f);
}
