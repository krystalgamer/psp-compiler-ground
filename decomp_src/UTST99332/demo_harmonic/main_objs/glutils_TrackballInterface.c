/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_INTERP
#define DEMO_LINKONCE_TrackballInterface 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN7glutils18TrackballInterfaceC2Ev\n_GLOBAL__I__ZN7glutils18TrackballInterfaceC2Ev = _GLOBAL__I__ZN7glutils18TrackballInterfaceC2Ev__asm");
__asm__(".globl _GLOBAL__D__ZN7glutils18TrackballInterfaceC2Ev\n_GLOBAL__D__ZN7glutils18TrackballInterfaceC2Ev = _GLOBAL__D__ZN7glutils18TrackballInterfaceC2Ev__asm");

/* the tail's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN7glutils18TrackballInterfaceD0Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils18TrackballInterfaceD0Ev)
    DEMO_LINKONCE(_ZN7glutils18TrackballInterfaceD1Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils18TrackballInterfaceD1Ev)
);

glutils::TrackballInterface::TrackballInterface()
    : _trackball(math::matrix::Identity()), _center(0, 0, 0), _p234(0, 0, 0, 1)
{
}

void glutils::TrackballInterface::track() {
}

void glutils::TrackballInterface::reset()
{
    *this = TrackballInterface();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_TrackballInterface", _ZN7glutils18TrackballInterface12set_callbackEv);
