/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#include "../main.hpp"

/* the module's .ctors refer to the static constructor */
__asm__(".globl _GLOBAL__I__ZN3sgl12TransformSet9TransformC2Ev");

sgl::TransformSet::Transform::Transform() {
}

sgl::TransformSet::Transform::Transform(math::matrix mm) : m(mm)
{
}

sgl::TransformSet::TransformSet() : _closed(false)
{
    float a = 30;
    _crease = a * 0.0174532924f;
}

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

/* the original's .gnu.linkonce.t order */
DEMO_LINKONCE_ORDER(DEMO_LINKONCE(_ZNSt6vectorIN3sgl12TransformSet9TransformESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl12TransformSet9TransformESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl12TransformSet9TransformESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type));
