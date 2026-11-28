/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN5scene11VertexArrayC2Ev\n_GLOBAL__I__ZN5scene11VertexArrayC2Ev = _GLOBAL__I__ZN5scene11VertexArrayC2Ev__asm");
__asm__(".globl _GLOBAL__D__ZN5scene11VertexArrayC2Ev\n_GLOBAL__D__ZN5scene11VertexArrayC2Ev = _GLOBAL__D__ZN5scene11VertexArrayC2Ev__asm");

extern "C" const char D_0016D3DC[], D_0016D3E8[], D_0016D3EC[], D_0016D400[];
extern const char VertexArray_use_name[] __asm__("_ZZN5scene11VertexArray3useENS_4PassEE19__PRETTY_FUNCTION__");
SCENE_ALLOC_FIRST_USE
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZNSt6vectorIN14vertex_formats16T2F_C4UB_N3F_V3FESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_)
    SCENE_LINKONCE(_ZNSt6vectorIN14vertex_formats16T2F_C4UB_N3F_V3FESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_)
    SCENE_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN14vertex_formats16T2F_C4UB_N3F_V3FESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIPN14vertex_formats16T2F_C4UB_N3F_V3FES2_ET0_T_S4_S3_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN14vertex_formats16T2F_C4UB_N3F_V3FEjS1_ET_S3_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN14vertex_formats16T2F_C4UB_N3F_V3FESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN14vertex_formats16T2F_C4UB_N3F_V3FESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN14vertex_formats16T2F_C4UB_N3F_V3FESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type)
);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_VertexArray", _ZN5scene11VertexArrayC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_VertexArray", _ZN5scene11VertexArrayC1Ev);

void scene::VertexArray::extractFrom(const MeshData &md)
{
    std::vector<short> v;
    extractFrom(md, v);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_VertexArray", _ZN5scene11VertexArray11extractFromERKNS_8MeshDataESt6vectorIsSaIsEE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_VertexArray", _ZN5scene11VertexArray19calcRefmapTexcoordsERKNS_17TraversalVarStackE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_VertexArray", _ZN5scene11VertexArray13calcShlColorsERKN2sh9VectorRGBERKN3sgl20TransferVectorVectorE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_VertexArray", _ZN5scene11VertexArray19calcDefaultShlAlphaERKN3sgl20TransferVectorVectorE);

void scene::VertexArray::use(Pass p)
{
    _v_ptr = p == 0 ? &_v38 : &_v44;
    SGL_ASSERT(!_v_ptr->empty(), D_0016D3DC, D_0016D3EC, D_0016D400, VertexArray_use_name, 0x153, D_0016D3E8);
}

/* the vector's instances that the (asm) methods above use */
template std::vector<vertex_formats::T2F_C4UB_N3F_V3F>::iterator
std::vector<vertex_formats::T2F_C4UB_N3F_V3F>::erase(std::vector<vertex_formats::T2F_C4UB_N3F_V3F>::iterator,
                                                     std::vector<vertex_formats::T2F_C4UB_N3F_V3F>::iterator);
namespace std {
typedef vertex_formats::T2F_C4UB_N3F_V3F VA_T;
typedef vector<VA_T>::iterator VA_It;
template void fill<VA_It, VA_T>(VA_It, VA_It, const VA_T &);
template VA_T *__uninitialized_copy_aux<VA_T *, VA_T *>(VA_T *, VA_T *, VA_T *, __false_type);
template VA_T *__uninitialized_fill_n_aux<VA_T *, unsigned int, VA_T>(VA_T *, unsigned int, const VA_T &, __false_type);
template VA_T *__uninitialized_copy_aux<VA_It, VA_T *>(VA_It, VA_It, VA_T *, __false_type);
template VA_It __uninitialized_copy_aux<VA_It, VA_It>(VA_It, VA_It, VA_It, __false_type);
template VA_It __uninitialized_fill_n_aux<VA_It, unsigned int, VA_T>(VA_It, unsigned int, const VA_T &, __false_type);
}
template void std::vector<vertex_formats::T2F_C4UB_N3F_V3F>::_M_fill_insert(std::vector<vertex_formats::T2F_C4UB_N3F_V3F>::iterator,
                                                                                    unsigned int, const vertex_formats::T2F_C4UB_N3F_V3F &);
