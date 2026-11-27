/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_LINKONCE_TrackballInterface 1
#include "../main.hpp"

/* the tail's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN7glutils18TrackballInterfaceD0Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils18TrackballInterfaceD0Ev)
    DEMO_LINKONCE(_ZN7glutils18TrackballInterfaceD1Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils18TrackballInterfaceD1Ev)
);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TrackballInterface", _Z41__static_initialization_and_destruction_0ii_34478);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TrackballInterface", _ZN7glutils18TrackballInterfaceC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TrackballInterface", _ZN7glutils18TrackballInterfaceC1Ev);

void glutils::TrackballInterface::track() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TrackballInterface", _ZN7glutils18TrackballInterface5resetEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TrackballInterface", _ZN7glutils18TrackballInterface12set_callbackEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_34478");
void _GLOBAL__I__ZN7glutils18TrackballInterfaceC2Ev(void);
void _GLOBAL__D__ZN7glutils18TrackballInterfaceC2Ev(void);
}

void _GLOBAL__I__ZN7glutils18TrackballInterfaceC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN7glutils18TrackballInterfaceC2Ev(void)
{
    static_init(0, 0xFFFF);
}
