/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_INTERP
#define DEMO_LINKONCE_TurnTable 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
/* (the constructor TurnTable() is still asm: its deferred-asm wrapper is the first public symbol cc1plus sees) */
__asm__(".globl _GLOBAL__I__ZN7glutils9TurnTableC2Ev\n_GLOBAL__I__ZN7glutils9TurnTableC2Ev = _GLOBAL__I__ZN7glutils9TurnTableC2Ev__asm");
__asm__(".globl _GLOBAL__D__ZN7glutils9TurnTableC2Ev\n_GLOBAL__D__ZN7glutils9TurnTableC2Ev = _GLOBAL__D__ZN7glutils9TurnTableC2Ev__asm");

/* the tail's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN7glutils9TurnTableD0Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils9TurnTableD0Ev)
    DEMO_LINKONCE(_ZN7glutils9TurnTableD1Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils9TurnTableD1Ev)
);

glutils::TurnTable::TurnTable() : _pivot(0, 0, 5, 1), _f1A0(false)
{
    set_transform(math::matrix::Identity());
    speed(Speed(0), 0.005f);
    speed(Speed(1), 0.01f);
    speed(Speed(2), 0.01f);
}

void glutils::TurnTable::speed(Speed s, float v)
{
    if (s < NUM_SPEEDS)
        _speed[s] = v;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_TurnTable", _ZN7glutils9TurnTable5resetEv);

void glutils::TurnTable::setIsYUp(bool v)
{
    _f1A0 = v;
}

bool glutils::TurnTable::isYUp() const
{
    return _f1A0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_TurnTable", _ZN7glutils9TurnTable8setPivotEN4math11vector_xyzwE);

void glutils::TurnTable::setPivot(float x, float y, float z)
{
    _pivot = math::vector_xyzw(x, y, z, 1.0f);
}

void glutils::TurnTable::setPivot(float y)
{
    _pivot = math::vector_xyzw(0, 0, y, 1.0f);
}

math::vector_xyzw glutils::TurnTable::getPivot() const
{
    return _pivot;
}

math::matrix glutils::TurnTable::getPivotFrame() const
{
    return _pivot_frame;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_TurnTable", _ZN7glutils9TurnTable5trackEbbbii);

void glutils::TurnTable::track()
{
    bool a = psp::pad().down(4);
    bool b = psp::pad().down(6);
    bool c = psp::pad().down(5);
    int dx = psp::pad().down(3) - psp::pad().down(2);
    int dy = psp::pad().down(0) - psp::pad().down(1);
    track(a, b, c, dx, dy);
}
