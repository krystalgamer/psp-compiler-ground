/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* the header static of this object (its static initializer is asm) */
extern const math::matrix CUMULATIVE_BERNSTIEN_BASIS __asm__("_ZN6interp26CUMULATIVE_BERNSTIEN_BASISE_18EB2C");


INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_KeyFrameSequence", _Z41__static_initialization_and_destruction_0ii_4D7EC);

void interp::KeyFrameSequence<math::quaternion>::dump(const char *) const {
}

math::quaternion interp::KeyFrameSequence<math::quaternion>::calc_gradient(math::quaternion a, math::quaternion b, float t) const
{
    return (a.conj() * b).log() / t;
}

void interp::KeyFrameSequence<math::quaternion>::calc_tangent(int i)
{
    math::quaternion a(0, 0, 0, 1.0f), b(0, 0, 0, 1.0f), c(0, 0, 0, 1.0f);
    float s0, s1;
    if (calc_tangent_setup(i, a, b, c, s0, s1)) {
        KeyFrame<math::quaternion> &k = _keys[i];
        k._tangent[0] = c * s0;
        k._tangent[1] = c * s1;
        if (k.getTangentType((keyframe_tangent::Side)1) == 1)
            k._tangent[0] = b * s0;
        if (k.getTangentType((keyframe_tangent::Side)2) == 1)
            k._tangent[1] = a * s1;
    }
}

math::quaternion interp::KeyFrameSequence<math::quaternion>::evaluate(float t)
{
    math::quaternion q(0, 0, 0, 1.0f);
    float u;
    KeyFrame<math::quaternion> *k0 = 0, *k1 = 0;
    if (!evaluate_setup(t, u, q, k0, k1))
        return q;
    math::vector_xyzw b = math::vector_xyzw(u * (u * u), u * u, u, 1.0f) * CUMULATIVE_BERNSTIEN_BASIS;
    math::quaternion w1 = k0->_tangent[1] * (1.0f / 3);
    math::quaternion w3 = k1->_tangent[0] * (1.0f / 3);
    math::quaternion w2 = (w1.exp().conj() * k0->value().conj() * k1->value() * w3.exp().conj()).log();
    math::quaternion base = _relative ? _default : op_identity();
    return op(base, k0->value() * (w1 * b.x).exp() * (w2 * b.y).exp() * (w3 * b.z).exp());
}

math::quaternion interp::KeyFrameSequence<math::quaternion>::op(math::quaternion a, math::quaternion b)
{
    return a * b;
}

math::quaternion interp::KeyFrameSequence<math::quaternion>::op_inv(math::quaternion a, math::quaternion b)
{
    return b.conj() * a;
}

math::quaternion interp::KeyFrameSequence<math::quaternion>::op_identity() const
{
    return math::quaternion(0, 0, 0, 1.0f);
}

void interp::KeyFrameSequence<math::quaternion>::typed_fix()
{
    std::vector<KeyFrame<math::quaternion> >::iterator prev = _keys.begin();
    std::vector<KeyFrame<math::quaternion> >::iterator it = prev + 1;
    if (prev == _keys.end())
        return;
    for (; it != _keys.end(); ++prev, ++it) {
        math::quaternion a = prev->value();
        math::quaternion b = it->value();
        math::quaternion::Shortest(a, b);
        it->setValue(b);
    }
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_4D7EC");
void _GLOBAL__I__ZNK6interp16KeyFrameSequenceIN4math10quaternionEE4dumpEPKc(void);
void _GLOBAL__D__ZNK6interp16KeyFrameSequenceIN4math10quaternionEE4dumpEPKc(void);
}

void _GLOBAL__I__ZNK6interp16KeyFrameSequenceIN4math10quaternionEE4dumpEPKc(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZNK6interp16KeyFrameSequenceIN4math10quaternionEE4dumpEPKc(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_KeyFrameSequence", _ZN6interp16KeyFrameSequenceIN4math10quaternionEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_KeyFrameSequence", _ZN6interp16KeyFrameSequenceIN4math10quaternionEED0Ev);

