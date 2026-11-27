/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"


#include "UTST99332/demo_duck/gl.hpp"
extern const float D_0016F86C;      /* 1.0f */
extern const char D_0016F904[];     /* " *** error " */
extern const char D_0016F934[];     /* "../lib/sh/Icosahedron.cpp" */
extern const char D_0016F950[];     /* " " */
extern const char D_0016FA4C[];     /* "_leaf" */
extern const char D_0016FCE8[];
extern const char listBins_name[] __asm__("_ZZN11Icosahedron8listBinsERSt6vectorIPNS_3BinESaIS2_EEhE19__PRETTY_FUNCTION__");
extern const char getLeafIndex_name[] __asm__("_ZZNK11Icosahedron3Bin12getLeafIndexEvE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/Icosahedron_Bin", _Z41__static_initialization_and_destruction_0ii_DA398);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/Icosahedron_Bin", _ZN11Icosahedron9on_sphereEN4math11vector_xyzwE);

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

bool Icosahedron::getDepth() const
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


INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/Icosahedron_Bin", _ZNK11Icosahedron3Bin9intersectEN4math11vector_xyzwE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/Icosahedron_Bin", _ZNK11Icosahedron3Bin22in_negative_half_spaceEN4math11vector_xyzwE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/Icosahedron_Bin", _ZN11Icosahedron3Bin10searchLeafEN4math11vector_xyzwE);

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

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_DA398");
void _GLOBAL__I__ZN11Icosahedron3BinC2EN4math11vector_xyzwES2_S2_h(void);
void _GLOBAL__D__ZN11Icosahedron3BinC2EN4math11vector_xyzwES2_S2_h(void);
}

void _GLOBAL__I__ZN11Icosahedron3BinC2EN4math11vector_xyzwES2_S2_h(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN11Icosahedron3BinC2EN4math11vector_xyzwES2_S2_h(void)
{
    static_init(0, 0xFFFF);
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
