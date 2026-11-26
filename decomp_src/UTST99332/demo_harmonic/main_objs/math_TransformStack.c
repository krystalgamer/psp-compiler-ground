/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* the strings stay in the module's .rodata (asm) */
extern const char D_0016ED24[];     /* " " */
extern const char D_0016ED28[];     /* " *** error " */
extern const char D_0016ED34[];     /* "_stack.empty()" */
extern const char D_0016ED44[];     /* "../lib/sgl/TransformStack.cpp" */
extern const char D_0016ED88[];     /* "! _stack.empty()" */
extern const char TransformStack_dtor_name[] __asm__("_ZZN4math14TransformStackD1EvE19__PRETTY_FUNCTION__");
extern const char TransformStack_pop_name[] __asm__("_ZZN4math14TransformStack3popEvE19__PRETTY_FUNCTION__");
extern const char TransformStack_ctop_name[] __asm__("_ZZNK4math14TransformStack3topEvE19__PRETTY_FUNCTION__");
extern const char TransformStack_top_name[] __asm__("_ZZN4math14TransformStack3topEvE19__PRETTY_FUNCTION__");
#define TS_ASSERT(c, s, name, line) \
    if (!(c)) { \
        common::common_internal::assert_display(D_0016ED28, s, D_0016ED44, name, line, D_0016ED24); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _Z41__static_initialization_and_destruction_0ii_D0C0C);

math::TransformStack::TransformStack()
{
    _dirty = true;
    push();
}

math::TransformStack::~TransformStack()
{
    pop();
    TS_ASSERT(_stack.empty(), D_0016ED34, TransformStack_dtor_name, 31);
}


INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack4pushEv);

void math::TransformStack::pop()
{
    TS_ASSERT(! _stack.empty(), D_0016ED88, TransformStack_pop_name, 41);
    _stack.pop();
    _dirty = true;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack4multERKNS_6matrixE);

void math::TransformStack::load(const matrix &m)
{
    top() = m;
    _dirty = true;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack8identityEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack6rotateEffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack7rotateXEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack7rotateYEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack7rotateZEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack5scaleEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack5scaleEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack9translateEfff);

const math::matrix &math::TransformStack::top() const
{
    TS_ASSERT(! _stack.empty(), D_0016ED88, TransformStack_ctop_name, 120);
    return _stack.top();
}

math::matrix &math::TransformStack::top()
{
    TS_ASSERT(! _stack.empty(), D_0016ED88, TransformStack_top_name, 127);
    return _stack.top();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZNK4math14TransformStack7top_invEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack7top_invEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_D0C0C");
void _GLOBAL__I__ZN4math14TransformStackC2Ev(void);
}

void _GLOBAL__I__ZN4math14TransformStackC2Ev(void)
{
    static_init(1, 0xFFFF);
}

