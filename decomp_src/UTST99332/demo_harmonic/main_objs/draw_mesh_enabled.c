/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SGL_TEMPLATE_DEFS 1
#define DEMO_TEMPLATE_DEFS 1
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/draw_mesh_enabled", _Z41__static_initialization_and_destruction_0ii_8B5A8);

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

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_8B5A8");
void _GLOBAL__I_draw_mesh_enabled(void);
void _GLOBAL__D_draw_mesh_enabled(void);
}

void _GLOBAL__I_draw_mesh_enabled(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D_draw_mesh_enabled(void)
{
    static_init(0, 0xFFFF);
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
/* strings of the PrimitiveIndex<short>/<int> instances' asserts */
template<> const char sgl::PrimitiveIndexNames<short>::err[] __asm__("D_00169590");
template<> const char sgl::PrimitiveIndexNames<short>::sep[] __asm__("D_0016958C");
template<> const char sgl::PrimitiveIndexNames<short>::file[] __asm__("D_001698B4");
template<> const char sgl::PrimitiveIndexNames<short>::val_ge_0[] __asm__("D_001698A8");
template<> const char sgl::PrimitiveIndexNames<short>::retval_size[] __asm__("D_00169938");
template<> const char sgl::PrimitiveIndexNames<short>::assign[] __asm__("_ZZN3sgl14PrimitiveIndexIsEaSIiEERS1_RKNS0_IT_EEE19__PRETTY_FUNCTION__");
template<> const char sgl::PrimitiveIndexNames<short>::unfold[] __asm__("_ZZN3sgl14PrimitiveIndexIsE6unfoldERSt6vectorIsSaIsEEE19__PRETTY_FUNCTION__");
template<> const char sgl::PrimitiveIndexNames<int>::err[] __asm__("D_00169590");
template<> const char sgl::PrimitiveIndexNames<int>::sep[] __asm__("D_0016958C");
template<> const char sgl::PrimitiveIndexNames<int>::file[] __asm__("D_001698B4");
template<> const char sgl::PrimitiveIndexNames<int>::tri_size[] __asm__("D_00169994");
template<> const char sgl::PrimitiveIndexNames<int>::count_n[] __asm__("D_001699C8");
template<> const char sgl::PrimitiveIndexNames<int>::check[] __asm__("_ZZNK3sgl14PrimitiveIndexIiE5checkEvE19__PRETTY_FUNCTION___169958");

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
