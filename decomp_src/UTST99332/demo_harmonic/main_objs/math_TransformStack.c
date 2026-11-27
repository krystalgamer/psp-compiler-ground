/* lang: c++ */
/* cflags: -O3 -fno-exceptions -fmerge-constants */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN4math14TransformStackC2Ev");

#define TS_ASSERT(c, s, name, line) \
    if (!(c)) { \
        common::common_internal::assert_display(" *** error ", s, "../lib/sgl/TransformStack.cpp", name, line, " "); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

math::TransformStack::TransformStack()
{
    _dirty = true;
    push();
}

math::TransformStack::~TransformStack()
{
    pop();
    TS_ASSERT(_stack.empty(), "_stack.empty()", __PRETTY_FUNCTION__, 31);
}

void math::TransformStack::push()
{
    _stack.push(_stack.empty() ? matrix::Identity() : top());
}

void math::TransformStack::pop()
{
    TS_ASSERT(! _stack.empty(), "! _stack.empty()", __PRETTY_FUNCTION__, 41);
    _stack.pop();
    _dirty = true;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack4multERKNS_6matrixE);

void math::TransformStack::load(const matrix &m)
{
    top() = m;
    _dirty = true;
}

void math::TransformStack::identity()
{
    top() = matrix::Identity();
    _dirty = true;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack6rotateEffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack7rotateXEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack7rotateYEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack7rotateZEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack5scaleEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack5scaleEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_TransformStack", _ZN4math14TransformStack9translateEfff);

const math::matrix &math::TransformStack::top() const
{
    TS_ASSERT(! _stack.empty(), "! _stack.empty()", __PRETTY_FUNCTION__, 120);
    return _stack.top();
}

math::matrix &math::TransformStack::top()
{
    TS_ASSERT(! _stack.empty(), "! _stack.empty()", __PRETTY_FUNCTION__, 127);
    return _stack.top();
}

const math::matrix &math::TransformStack::top_inv() const
{
    TS_ASSERT(! _stack.empty(), "! _stack.empty()", __PRETTY_FUNCTION__, 134);
    if (_dirty) {
        _inv = _stack.top().inverse();
        _dirty = false;
    }
    return _inv;
}

math::matrix &math::TransformStack::top_inv()
{
    TS_ASSERT(! _stack.empty(), "! _stack.empty()", __PRETTY_FUNCTION__, 147);
    if (_dirty) {
        _inv = _stack.top().inverse();
        _dirty = false;
    }
    return _inv;
}
