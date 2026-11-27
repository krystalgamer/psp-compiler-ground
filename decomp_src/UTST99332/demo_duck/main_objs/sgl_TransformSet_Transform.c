/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"


INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_TransformSet_Transform", _Z41__static_initialization_and_destruction_0ii_D2750);

sgl::TransformSet::Transform::Transform() {
}

sgl::TransformSet::Transform::Transform(math::matrix mm) : m(mm)
{
}


INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_TransformSet_Transform", _ZN3sgl12TransformSetC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_TransformSet_Transform", _ZN3sgl12TransformSetC1Ev);

void sgl::TransformSet::add(math::matrix m)
{
    _transforms.push_back(Transform(m));
}

void sgl::TransformSet::clear()
{
    _transforms.clear();
}

void sgl::TransformSet::set_crease(float c)
{
    _crease = c;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_D2750");
void _GLOBAL__I__ZN3sgl12TransformSet9TransformC2Ev(void);
}

void _GLOBAL__I__ZN3sgl12TransformSet9TransformC2Ev(void)
{
    static_init(1, 0xFFFF);
}

/* the original's .gnu.linkonce.t order */
DEMO_LINKONCE_ORDER(DEMO_LINKONCE(_ZNSt6vectorIN3sgl12TransformSet9TransformESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl12TransformSet9TransformESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl12TransformSet9TransformESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type));
