/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_LINKONCE_TurnTable 1
#include "../main.hpp"

/* the tail's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN7glutils9TurnTableD0Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils9TurnTableD0Ev)
    DEMO_LINKONCE(_ZN7glutils9TurnTableD1Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils9TurnTableD1Ev)
);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TurnTable", _Z41__static_initialization_and_destruction_0ii_35074);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TurnTable", _ZN7glutils9TurnTableC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TurnTable", _ZN7glutils9TurnTableC1Ev);

void glutils::TurnTable::speed(Speed s, float v)
{
    if (s < NUM_SPEEDS)
        _speed[s] = v;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TurnTable", _ZN7glutils9TurnTable5resetEv);

void glutils::TurnTable::setIsYUp(bool v)
{
    _f1A0 = v;
}

bool glutils::TurnTable::isYUp() const
{
    return _f1A0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TurnTable", _ZN7glutils9TurnTable8setPivotEN4math11vector_xyzwE);

extern "C" const float D_00163F10;

void glutils::TurnTable::setPivot(float x, float y, float z)
{
    _pivot = math::vector_xyzw(x, y, z, D_00163F10);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TurnTable", _ZN7glutils9TurnTable8setPivotEf);

math::vector_xyzw glutils::TurnTable::getPivot() const
{
    return _pivot;
}

math::matrix glutils::TurnTable::getPivotFrame() const
{
    return _pivot_frame;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TurnTable", _ZN7glutils9TurnTable5trackEbbbii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TurnTable", _ZN7glutils9TurnTable5trackEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_35074");
void _GLOBAL__I__ZN7glutils9TurnTableC2Ev(void);
void _GLOBAL__D__ZN7glutils9TurnTableC2Ev(void);
}

void _GLOBAL__I__ZN7glutils9TurnTableC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN7glutils9TurnTableC2Ev(void)
{
    static_init(0, 0xFFFF);
}
