/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#define SGL_LINKONCE_PerVertexData 1
#include <iostream>
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN2sh3PRTC2ENS_4Args4ToolE\n_GLOBAL__I__ZN2sh3PRTC2ENS_4Args4ToolE = _GLOBAL__I__ZN2sh3PRTC2ENS_4Args4ToolE__asm");
__asm__(".globl _GLOBAL__D__ZN2sh3PRTC2ENS_4Args4ToolE\n_GLOBAL__D__ZN2sh3PRTC2ENS_4Args4ToolE = _GLOBAL__D__ZN2sh3PRTC2ENS_4Args4ToolE__asm");

#include "UTST99332/demo_duck/gl.hpp"
#include <fstream>
extern const char D_0016FFC4[];     /* " " */
extern const char D_0016FFC8[];     /* " *** error " */
extern const char D_0016FF2C[];     /* ".prt" */
static inline std::string prt_filename(const std::string &name)
{
    std::string s(name);
    s += D_0016FF2C;
    return s;
}
extern const float D_0016FDB4;      /* 1.0f */
extern const char D_0016FE28[];     /* "num sphere samples=" */
extern const char D_0017006C[];     /* "DRAW_SH" */
extern const char D_00170074[];     /* "FULL_HEMISPHERE_VTX" */
extern const char D_00170088[];     /* "DRAW_METRICS" */
extern const char D_00170098[];     /* "UNKNOWN" */
extern const char D_001700A0[];     /* "DRAW_NORMAL" */

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

extern const char D_0016FF34[];
void sh::PRT::save_if_doesnt_exit()
{
    std::fstream f;
    f.open(prt_filename(_name).c_str(), std::ios::in);
    if (!f.is_open()) {
        common::Log() << D_0016FF34;
        save();
    } else
        f.close();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT19diffuse_shadow_passERNS0_10VertexDataE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT20interreflection_passERNS0_10VertexDataEi);

static inline void zero(sh::Vector &v)
{
    v.v[0] = 0;
    v.v[1] = 0;
    v.v[2] = 0;
    v.v[3] = 0;
}
void sh::PRT::sum_bounces(VertexData &vd)
{
    int i = 0;
    for (std::vector<PerVertexData>::iterator it = vd._pvd.begin(); it != vd._pvd.end(); ++it, ++i) {
        VectorRGB &c = vd._v[i]._sh;
        zero(c.r);
        zero(c.g);
        zero(c.b);
        for (int k = 0; k != 3; k++)
            vd._v[i]._sh += it->_sh[k];
    }
}

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

void sh::PRT::draw_samples(int, const VectorRGB &)
{
    glColor3f(1, 0, 0);
}

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

extern const char D_0016FFB0[];     /* "../lib/sh/PRT.cpp" */
extern const char D_0017017C[];
extern const char D_001701AC[];
extern const char D_001701CC[];
extern const float D_0016FDC0;      /* 1.0f */
extern const char saveVertexSHAsCubeMap_name[] __asm__("_ZZN2sh3PRT21saveVertexSHAsCubeMapEPKcjjE19__PRETTY_FUNCTION__");
void sh::PRT::saveVertexSHAsCubeMap(const char *name, unsigned int _Index, unsigned int size)
{
    SGL_ASSERT(_Index > 0 && _Index < _vdata._v.size(), D_0016FFC8, D_0017017C, D_0016FFB0, saveVertexSHAsCubeMap_name, 1244, D_0016FFC4);
    std::cout << D_001701AC << _Index << D_001701CC;
    FunctionEvaluator f(_vdata._pvd[_Index]._sh[0]);
    f.saveCubeMap(name, 0, size, 0, 1.0f);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT18make_adj_tri_listsEv);

static inline sgl::Position to_position(const math::vector_xyzw &v)
{
    return sgl::Position(v.x, v.y, v.z, 1);
}
void sh::PRT::draw_averaged_normals()
{
    int i = 0;
    glPushAttrib(GL_ENABLE_BIT);
    glDisable(GL_LIGHTING);
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    for (std::vector<PerVertexData>::iterator it = _vdata._pvd.begin(); it != _vdata._pvd.end(); ++it, ++i) {
        sgl::Position p = _rt.getMesh()->getVertexPosition(i);
        sgl::Position q = to_position(p + *(const math::vector_xyzw *)&it->_f90 * 0.2f);
        glVertex3fv(&p.x);
        glVertex3fv(&q.x);
    }
    glEnd();
    glPopAttrib();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT22draw_triangles_normalsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_PRT", _ZN2sh3PRT20calc_average_normalsEv);

extern const char D_001702DC[];
void sh::PRT::save()
{
    if (!_processed) {
        common::Log() << D_001702DC;
        return;
    }
    _vdata.save(prt_filename(_name));
}

extern const char D_0017032C[];
extern const char D_00170378[];
void sh::PRT::load()
{
    if (_processed) {
        common::Log() << D_0017032C;
        return;
    }
    VerticesVector d;
    if (!d.load(prt_filename(_name)))
        return;
    if (d._v.size() != _rt.getMesh()->getVertices().size()) {
        common::Log() << D_00170378;
        return;
    }
    for (unsigned int i = 0; i != d._v.size(); i++)
        _vdata._v[i]._sh = d._v[i]._sh;
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

/* the asm functions refer to the header statics by their module names */
__asm__("_ZN3sgl3REDE_18E02C = _ZN3sgl3REDE\n"
        "_ZN3sgl4BLUEE_18E04C = _ZN3sgl4BLUEE\n"
        "_ZN3sgl4CYANE_18E09C = _ZN3sgl4CYANE\n"
        "_ZN3sgl5BLACKE_18E05C = _ZN3sgl5BLACKE\n"
        "_ZN3sgl5GREENE_18E03C = _ZN3sgl5GREENE\n"
        "_ZN3sgl5WHITEE_18E06C = _ZN3sgl5WHITEE\n"
        "_ZN3sgl6YELLOWE_18E07C = _ZN3sgl6YELLOWE\n"
        "_ZN3sgl7MAGENTAE_18E08C = _ZN3sgl7MAGENTAE\n"
        "_ZN4math12BEZIER_BASISE_18DFEC = _ZN4math12BEZIER_BASISE\n"
        "_ZN4math13HERMITE_BASISE_18DFAC = _ZN4math13HERMITE_BASISE\n");
