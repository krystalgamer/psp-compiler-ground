/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const float D_00167888;      /* 1.0f: op_identity's w */

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_KeyFrameSequence", _Z41__static_initialization_and_destruction_0ii_4D7EC);

void interp::KeyFrameSequence<math::quaternion>::dump(const char *) const {
}

math::quaternion interp::KeyFrameSequence<math::quaternion>::calc_gradient(math::quaternion a, math::quaternion b, float t) const
{
    return (a.conj() * b).log() / t;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_KeyFrameSequence", _ZN6interp16KeyFrameSequenceIN4math10quaternionEE12calc_tangentEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_KeyFrameSequence", _ZN6interp16KeyFrameSequenceIN4math10quaternionEE8evaluateEf);

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
    return math::quaternion(0, 0, 0, D_00167888);
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

