/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3sys5timer12GetDeltaTimeEv");
__asm__(".globl _GLOBAL__D__ZN3sys5timer12GetDeltaTimeEv");

extern "C" long long sceKernelGetSystemTimeWide(void);

namespace sys {
namespace timer {

struct Timer {
    float dt;
    double now;
    double prev;
    double start;
    bool abs;

    Timer(bool a)
    {
        dt = 0;
        abs = a;
        prev = now = start = time();
    }
    static double time() { return (unsigned long long)sceKernelGetSystemTimeWide() / 1000000.0; }
    float update()
    {
        now = time();
        dt = abs ? now - start : now - prev;
        prev = now;
        return dt;
    }
};

float GetDeltaTime();
float GetTime();
}
}

float sys::timer::GetDeltaTime()
{
    static Timer rel_timer(false);
    return rel_timer.update();
}

float sys::timer::GetTime()
{
    static Timer abs_timer(true);
    return abs_timer.update();
}
