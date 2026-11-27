/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const float D_0016495C;      /* 1.0f: calc_tangent's identity quaternions */
extern const float D_00164968;      /* 1.0f: op_identity's w */

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_KeyFrameSequence", _Z41__static_initialization_and_destruction_0ii_4B370);

void interp::KeyFrameSequence<math::quaternion>::dump(const char *) const {
}

math::quaternion interp::KeyFrameSequence<math::quaternion>::calc_gradient(math::quaternion a, math::quaternion b, float t) const
{
    return (a.conj() * b).log() / t;
}

void interp::KeyFrameSequence<math::quaternion>::calc_tangent(int i)
{
    const float one = D_0016495C;
    math::quaternion a(0, 0, 0, one), b(0, 0, 0, one), c(0, 0, 0, one);
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_KeyFrameSequence", _ZN6interp16KeyFrameSequenceIN4math10quaternionEE8evaluateEf);

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
    return math::quaternion(0, 0, 0, D_00164968);
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
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_4B370");
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_KeyFrameSequence", _ZN6interp16KeyFrameSequenceIN4math10quaternionEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_KeyFrameSequence", _ZN6interp16KeyFrameSequenceIN4math10quaternionEED0Ev);

