/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SGL_LINKONCE_PerVertexData 1
#include "../main.hpp"

#include "UTST99332/demo_duck/gl.hpp"
extern const float D_0016FDB4;      /* 1.0f */
extern const char D_0016FE28[];     /* "num sphere samples=" */
extern const char D_0017006C[];     /* "DRAW_SH" */
extern const char D_00170074[];     /* "FULL_HEMISPHERE_VTX" */
extern const char D_00170088[];     /* "DRAW_METRICS" */
extern const char D_00170098[];     /* "UNKNOWN" */
extern const char D_001700A0[];     /* "DRAW_NORMAL" */

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _Z41__static_initialization_and_destruction_0ii_E08F0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRTC2ENS_4Args4ToolE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRTC1ENS_4Args4ToolE);

void sh::PRT::import_model() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT18init_mesh_verticesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT17init_shadow_planeEv);

void sh::PRT::process()
{
    _processed = true;
    std::cout << D_0016FE28 << _sampling._samples.size() << std::endl;
    if (!_vdata._v.empty())
        process(_vdata);
    save_if_doesnt_exit();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT7processERNS0_10VertexDataE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT19save_if_doesnt_exitEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT19diffuse_shadow_passERNS0_10VertexDataE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT20interreflection_passERNS0_10VertexDataEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT11sum_bouncesERNS0_10VertexDataE);

const char *sh::PRT::DrawFlagName(DrawFlag f)
{
    switch (f) {
    case DRAW_NORMAL:
        return D_001700A0;
    case DRAW_SH:
        return D_0017006C;
    case FULL_HEMISPHERE_VTX:
        return D_00170074;
    case DRAW_METRICS:
        return D_00170088;
    }
    return D_00170098;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT12draw_samplesEiRKNS_9VectorRGBE);

void sh::PRT::draw(int flags, DrawFlag f, const math::matrix &m, int k)
{
    if (f == DRAW_NORMAL)
        _rt.getMesh()->draw(flags);
    else {
        draw_with_sh(f, m, k);
        _rt.getMesh()->draw(flags & 0xA);
    }
    if (flags & 8) {
        draw_averaged_normals();
        draw_triangles_normals();
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT12draw_with_shENS0_8DrawFlagERKN4math6matrixEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT10check_meshEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT21saveVertexSHAsCubeMapEPKcjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT18make_adj_tri_listsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT21draw_averaged_normalsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT22draw_triangles_normalsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT20calc_average_normalsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT4saveEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT4loadEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_E08F0");
void _GLOBAL__I__ZN2sh3PRTC2ENS_4Args4ToolE(void);
void _GLOBAL__D__ZN2sh3PRTC2ENS_4Args4ToolE(void);
}

void _GLOBAL__I__ZN2sh3PRTC2ENS_4Args4ToolE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN2sh3PRTC2ENS_4Args4ToolE(void)
{
    static_init(0, 0xFFFF);
}

/* the original's .gnu.linkonce.t order */
DEMO_LINKONCE_ORDER(DEMO_LINKONCE(_ZNSt6vectorIN2sh3PRT13PerVertexDataESaIS2_EE6resizeEjRKS2_)
                    DEMO_LINKONCE(_ZN10BoolVectorILj320EE2jkERjS1_j)
                    DEMO_LINKONCE(_ZNSt6vectorIN2sh6VertexESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_)
                    DEMO_LINKONCE(_ZNSt6vectorIN2sh3PRT13PerVertexDataESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_)
                    DEMO_LINKONCE(_ZNSt6vectorIN2sh6VertexESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_)
                    DEMO_LINKONCE(_ZNSt6vectorIN2sh3PRT13PerVertexDataESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_)
                    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN2sh6VertexESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_)
                    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN2sh3PRT13PerVertexDataESt6vectorIS4_SaIS4_EEEES4_EvT_SA_RKT0_)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN2sh6VertexES2_ET0_T_S4_S3_12__false_type)
                    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN2sh6VertexEjS1_ET_S3_T0_RKT1_12__false_type)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN2sh6VertexESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN2sh6VertexESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type)
                    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN2sh6VertexESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN2sh3PRT13PerVertexDataES3_ET0_T_S5_S4_12__false_type)
                    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN2sh3PRT13PerVertexDataEjS2_ET_S4_T0_RKT1_12__false_type)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN2sh3PRT13PerVertexDataESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN2sh3PRT13PerVertexDataESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type)
                    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN2sh3PRT13PerVertexDataESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type)
                    DEMO_LINKONCE(_ZN2sh3PRT13PerVertexDataC1Ev));
extern const char D_0016FFC4[];     /* " " */
extern const char D_0016FFC8[];     /* " *** error " */
extern const char D_00170420[];
extern const char D_0017042C[];
extern const char D_00170430[];
extern const char D_00170434[];
extern const char BoolVector_jk_name[] __asm__("_ZZN10BoolVectorILj320EE2jkERjS1_jE19__PRETTY_FUNCTION__");
template<unsigned int N> class BoolVector {
public:
    void jk(unsigned int &j, unsigned int &k, unsigned int i);
};


extern "C" void sh_PRT_resize(void) __asm__("_ZNSt6vectorIN2sh3PRT13PerVertexDataESaIS2_EE6resizeEjRKS2_");
extern "C" void sh_PRT_instances(std::vector<sh::PRT::PerVertexData> *pv, BoolVector<320> *b, std::vector<sh::Vertex> *vv, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void sh_PRT_instances(std::vector<sh::PRT::PerVertexData> *pv, BoolVector<320> *b, std::vector<sh::Vertex> *vv, unsigned int n)
{
    /* the asm calls resize(n, x) (inlined here): referenced by its assembler name too */
    pv->resize(n);
    sh_PRT_resize();
    b->jk(n, n, n);
    vv->resize(n);
}

template<unsigned int N> void BoolVector<N>::jk(unsigned int &j, unsigned int &k, unsigned int i)
{
    if (!(i < N)) {
        std::cout << D_00170420 << i << D_0017042C << N << std::endl;
        SGL_ASSERT(false, D_0016FFC8, D_00170430, D_00170434, BoolVector_jk_name, 37, D_0016FFC4);
    }
    j = i / 32;
    k = i - j * 32;
}
