/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

namespace std {
extern template vector<sgl::TransformSet::Transform>::iterator
vector<sgl::TransformSet::Transform>::erase(iterator, iterator);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_TransformSet_Transform", _Z41__static_initialization_and_destruction_0ii_D036C);

sgl::TransformSet::Transform::Transform() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_TransformSet_Transform", _ZN3sgl12TransformSet9TransformC2EN4math6matrixE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_TransformSet_Transform", _ZN3sgl12TransformSet9TransformC1EN4math6matrixE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_TransformSet_Transform", _ZN3sgl12TransformSetC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_TransformSet_Transform", _ZN3sgl12TransformSetC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_TransformSet_Transform", _ZN3sgl12TransformSet3addEN4math6matrixE);

void sgl::TransformSet::clear()
{
    _transforms.clear();
}

void sgl::TransformSet::set_crease(float c)
{
    _crease = c;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_D036C");
void _GLOBAL__I__ZN3sgl12TransformSet9TransformC2Ev(void);
}

void _GLOBAL__I__ZN3sgl12TransformSet9TransformC2Ev(void)
{
    static_init(1, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_TransformSet_Transform", _ZNSt6vectorIN3sgl12TransformSet9TransformESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_TransformSet_Transform", _ZNSt6vectorIN3sgl12TransformSet9TransformESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_TransformSet_Transform", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl12TransformSet9TransformESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);

