/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const float D_0016E00C;      /* 1e-6f */
extern const float D_0016E010;      /* -11.0f */
extern const float D_0016E020;      /* 30.0f */
extern const float D_0016E024;      /* degrees -> radians */
extern const char D_0016E070[];     /* "../lib/sgl/LineSet.cpp" */
extern const char D_0016E108[];     /* " *** error " */
extern const char D_0016E114[];     /* "! ready()" */
extern const char D_0016E120[];     /* "forgot a call to LineSet::end()" */
extern const char D_0016E168[];     /* "ready()" */
extern const char D_0016E170[];     /* "forgot a call to LineSet::begin()" */
extern const char begin_name[] __asm__("_ZZN3sgl7LineSet5beginENS_8LineModeEE19__PRETTY_FUNCTION__");
extern const char color_name[] __asm__("_ZZN3sgl7LineSet5colorENS_5ColorEE19__PRETTY_FUNCTION__");
extern const char end_name[] __asm__("_ZZN3sgl7LineSet3endEvE19__PRETTY_FUNCTION__");
#define LS_ASSERT(c, text, fn, line, msg) SGL_ASSERT(c, D_0016E108, text, D_0016E070, fn, line, msg)

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _Z41__static_initialization_and_destruction_0ii_A9488);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZN3sgl7LineSet4Line6VertexC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZN3sgl7LineSet4Line6VertexC1Ev);

bool sgl::LineSet::Line::zero_length() const
{
    math::vector_xyzw d = a.p - b.p;
    return sqrtf(math::dot(d, d)) < D_0016E00C;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZN3sgl7LineSet21invert_normal_vectorsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZN3sgl7LineSet19calc_normal_vectorsEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZN3sgl7LineSetC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZN3sgl7LineSetC1Ev);

void sgl::LineSet::begin(LineMode m)
{
    LS_ASSERT(!ready(), D_0016E114, begin_name, 138, D_0016E120);
    _state = m;
}

void sgl::LineSet::color(Color c)
{
    LS_ASSERT(ready(), D_0016E168, color_name, 145, D_0016E170);
    _color = c;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZN3sgl7LineSet6vertexENS_8PositionE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZN3sgl7LineSet3endEv);

bool sgl::LineSet::ready() const
{
    return _state != 3;
}

void sgl::LineSet::set_negate_normals(bool v)
{
    _negate_normals = v;
}

void sgl::LineSet::set_crease(float v)
{
    _crease = v;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_A9488");
void _GLOBAL__I__ZN3sgl7LineSet4Line6VertexC2Ev(void);
void _GLOBAL__D__ZN3sgl7LineSet4Line6VertexC2Ev(void);
}

void _GLOBAL__I__ZN3sgl7LineSet4Line6VertexC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sgl7LineSet4Line6VertexC2Ev(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZNSt6vectorIN3sgl7LineSet4LineESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZNSt6vectorIN3sgl7LineSet4LineESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZNSt6vectorIN3sgl7LineSet4LineESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl7LineSet4LineESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl7LineSet4LineESt6vectorIS4_SaIS4_EEEES4_EvT_SA_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZSt24__uninitialized_copy_auxIPN3sgl7LineSet4LineES3_ET0_T_S5_S4_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZSt26__uninitialized_fill_n_auxIPN3sgl7LineSet4LineEjS2_ET_S4_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl7LineSet4LineESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl7LineSet4LineESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type);

