/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
/* the instances' own assert strings are literals (the unit's .rodata is carved); the shared " *** error " / " "
   belong to operator= (asm) */
#define SGL_PI_ASSERT(c, text, fn, line) \
    SGL_ASSERT(c, PrimitiveIndexNames<T>::err, DME_##text, "../lib/sgl/PrimitiveIndex.h", __PRETTY_FUNCTION__, line, \
               PrimitiveIndexNames<T>::sep)
#define DME_val_ge_0 "val >= 0"
#define DME_retval_size "_Retval.size() == num_vertices"
#define DME_tri_size "3 * ( _triangles.size() / 3 ) == _triangles.size()"
#define DME_count_n "count == _num_strips"
#define SGL_TEMPLATE_DEFS 1
#define DEMO_TEMPLATE_DEFS 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor, keyed to the .data variable draw_mesh_enabled
   (asm); cc1plus keys ours to the deferred-asm wrapper of the first function */
__asm__(".globl _GLOBAL__I_draw_mesh_enabled\n_GLOBAL__I_draw_mesh_enabled = _GLOBAL__I__ZN5scene19MeshDataInterleavedC2Ev__asm");
__asm__(".globl _GLOBAL__D_draw_mesh_enabled\n_GLOBAL__D_draw_mesh_enabled = _GLOBAL__D__ZN5scene19MeshDataInterleavedC2Ev__asm");

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/draw_mesh_enabled", _ZN5scene19MeshDataInterleavedC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/draw_mesh_enabled", _ZN5scene19MeshDataInterleavedC1Ev);


scene::MeshDataInterleaved::MeshDataInterleaved(const MeshDataInterleaved &o)
{
    *this = o;
}


INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/draw_mesh_enabled", _ZN5scene19MeshDataInterleavedaSERKS0_);

std::vector<sh::VectorRGB> &scene::MeshDataInterleaved::getRadianceTransfers()
{
    return _shared->_radiance;
}

const std::vector<sh::VectorRGB> &scene::MeshDataInterleaved::getRadianceTransfers() const
{
    return _shared->_radiance;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/draw_mesh_enabled", _ZN5scene19MeshDataInterleaved16convert_preserveERKNS_8MeshDataE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/draw_mesh_enabled", _ZN5scene19MeshDataInterleaved14convert_expandERKNS_8MeshDataE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/draw_mesh_enabled", _ZN5scene19MeshDataInterleaved7convertERKNS_8MeshDataE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/draw_mesh_enabled", _ZN5scene19MeshDataInterleaved4drawERKNS_17TraversalVarStackE);

void scene::DrawFuncIndex::draw(vertex_formats::T2F_C4UB_N3F_V3F *v, const sgl::PrimitiveIndex<short> &p)
{
    if (!p.tri().empty())
        sceGuDrawArray(3, 0x11FF, p.tri().size(), &p.tri()[0], v);
    for (int i = 0, k = 0; i != p.n; i++) {
        int len = p.strips()[k++];
        sceGuDrawArray(4, 0x11FF, len, &p.strips()[k], v);
        k += len;
    }
}

void scene::DrawFuncNonIndex::draw(vertex_formats::T2F_C4UB_N3F_V3F *v, const sgl::PrimitiveIndex<short> &p)
{
    if (!p.tri().empty())
        sceGuDrawArray(3, 0x1FF, p.tri().size(), 0, v);
    for (int i = 0, k = 0; i != p.n; i++) {
        int len = p.strips()[k++];
        sceGuDrawArray(4, 0x1FF, len, 0, v + p.strips()[k]);
        k += len;
    }
}

/* inline members / instances kept as asm: .gnu.linkonce.t (splat only sees `INCLUDE_ASM(`) */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/draw_mesh_enabled", _ZN5scene19MeshDataInterleaved10VertexDataD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/draw_mesh_enabled", _ZN5scene19MeshDataInterleaved10VertexDataD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/draw_mesh_enabled", _ZN5scene19MeshDataInterleaved10SharedDataD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/draw_mesh_enabled", _ZN5scene19MeshDataInterleaved10SharedDataD0Ev);

/* the original's .gnu.linkonce.t order */
DEMO_LINKONCE_ORDER(DEMO_LINKONCE(_ZN3sgl14PrimitiveIndexIsEC1Ev)
                    DEMO_LINKONCE(_ZN6common6handleIN5scene19MeshDataInterleaved10SharedDataEEaSERKS4_)
                    DEMO_LINKONCE(_ZN6common6handleIN5scene19MeshDataInterleaved10VertexDataEEaSERKS4_)
                    DEMO_LINKONCE(_ZNSt6vectorIN14vertex_formats16T2F_C4UB_N3F_V3FESaIS1_EEaSERKS3_)
                    DEMO_LINKONCE(_ZN3sgl14PrimitiveIndexIsEaSIiEERS1_RKNS0_IT_EE)
                    DEMO_LINKONCE(_ZN3sgl14PrimitiveIndexIsE6unfoldERSt6vectorIsSaIsEE)
                    DEMO_LINKONCE(_ZNK3sgl14PrimitiveIndexIiE5checkEv)
                    DEMO_LINKONCE(_ZNK3sgl14PrimitiveIndexIsE3triEv)
                    DEMO_LINKONCE(_ZNK3sgl14PrimitiveIndexIsE6stripsEv)
                    DEMO_LINKONCE(_ZN3sgl14PrimitiveIndexIsE5clearEv)
                    DEMO_LINKONCE(_ZNK3sgl14PrimitiveIndexIiE6stripsEv)
                    DEMO_LINKONCE(_ZNK3sgl14PrimitiveIndexIiE3triEv)
                    DEMO_LINKONCE(_ZNK3sgl14PrimitiveIndexIsE13countVerticesEv)
                    DEMO_LINKONCE(_ZNSt6vectorIsSaIsEE7reserveEj)
                    DEMO_LINKONCE(_ZN3sgl14PrimitiveIndexIsE3triEv)
                    DEMO_LINKONCE(_ZN3sgl14PrimitiveIndexIsE6stripsEv)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN14vertex_formats16T2F_C4UB_N3F_V3FESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_12__false_type)
                    DEMO_LINKONCE(_ZNK3sgl14PrimitiveIndexIsE21countVerticesInStripsEv)
                    DEMO_LINKONCE(_ZNSt6vectorIsSaIsEE5eraseEN9__gnu_cxx17__normal_iteratorIPsS1_EES5_)
                    DEMO_LINKONCE(_ZNSt6vectorIsSaIsEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPsS1_EERKs)
                    DEMO_LINKONCE(_ZNSt6vectorIsSaIsEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPsS1_EEjRKs)
                    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPsSt6vectorIsSaIsEEEEsEvT_S7_RKT0_)
                    DEMO_LINKONCE(_ZSt6fill_nIPsjsET_S1_T0_RKT1_)
                    DEMO_LINKONCE(_ZSt6fill_nIN9__gnu_cxx17__normal_iteratorIPsSt6vectorIsSaIsEEEEjsET_S7_T0_RKT1_)
                    DEMO_LINKONCE(_ZN5scene19MeshDataInterleaved10VertexDataD1Ev)
                    DEMO_LINKONCE(_ZN5scene19MeshDataInterleaved10VertexDataD0Ev)
                    DEMO_LINKONCE(_ZN5scene19MeshDataInterleaved10SharedDataD1Ev)
                    DEMO_LINKONCE(_ZN5scene19MeshDataInterleaved10SharedDataD0Ev));
/* the shared strings of the PrimitiveIndex<short>/<int> instances' asserts (operator= owns them) */
template<> const char sgl::PrimitiveIndexNames<short>::err[] __asm__("D_00169590");
template<> const char sgl::PrimitiveIndexNames<short>::sep[] __asm__("D_0016958C");
template<> const char sgl::PrimitiveIndexNames<int>::err[] __asm__("D_00169590");
template<> const char sgl::PrimitiveIndexNames<int>::sep[] __asm__("D_0016958C");

extern "C" void draw_mesh_enabled_instances(sgl::PrimitiveIndex<short> *s, sgl::PrimitiveIndex<int> *i, std::vector<short> *v, common::handle<scene::MeshDataInterleaved::SharedData> *hs, common::handle<scene::MeshDataInterleaved::VertexData> *hv, std::vector<vertex_formats::T2F_C4UB_N3F_V3F> *va, short n) __attribute__((section(".discard.asm")));
extern "C" void draw_mesh_enabled_instances(sgl::PrimitiveIndex<short> *s, sgl::PrimitiveIndex<int> *i, std::vector<short> *v, common::handle<scene::MeshDataInterleaved::SharedData> *hs, common::handle<scene::MeshDataInterleaved::VertexData> *hv, std::vector<vertex_formats::T2F_C4UB_N3F_V3F> *va, short n)
{
    sgl::PrimitiveIndex<short> p;
    const sgl::PrimitiveIndex<short> *cs = s;
    const sgl::PrimitiveIndex<int> *ci = i;
    *hs = *hs;
    *hv = *hv;
    *va = *va;
    *s = *i;
    s->unfold(*v);
    ci->check();
    cs->tri();
    cs->strips();
    s->clear();
    ci->strips();
    ci->tri();
    s->countVertices();
    v->resize(n);
    v->push_back(n);
}
