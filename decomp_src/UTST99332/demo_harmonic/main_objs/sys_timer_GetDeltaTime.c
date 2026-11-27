/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" long long sceKernelGetSystemTimeWide(void);

namespace sys {
namespace timer {

struct Timer {
    float dt;
    double now;
    double prev;
    double start;
    bool abs;

    static double time() { return (unsigned long long)sceKernelGetSystemTimeWide() / 1000000.0; }
    void init(bool a)
    {
        dt = 0;
        abs = a;
        prev = now = start = time();
    }
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

extern sys::timer::Timer rel_timer __asm__("_ZZN3sys5timer12GetDeltaTimeEvE9rel_timer");
extern char rel_guard __asm__("_ZGVZN3sys5timer12GetDeltaTimeEvE9rel_timer");
extern sys::timer::Timer abs_timer __asm__("_ZZN3sys5timer7GetTimeEvE9abs_timer");
extern char abs_guard __asm__("_ZGVZN3sys5timer7GetTimeEvE9abs_timer");

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sys_timer_GetDeltaTime", _Z41__static_initialization_and_destruction_0ii_FB124);

float sys::timer::GetDeltaTime()
{
    if (!rel_guard) {
        rel_timer.init(false);
        rel_guard = 1;
    }
    return rel_timer.update();
}

float sys::timer::GetTime()
{
    if (!abs_guard) {
        abs_timer.init(true);
        abs_guard = 1;
    }
    return abs_timer.update();
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_FB124");
void _GLOBAL__I__ZN3sys5timer12GetDeltaTimeEv(void);
void _GLOBAL__D__ZN3sys5timer12GetDeltaTimeEv(void);
}

void _GLOBAL__I__ZN3sys5timer12GetDeltaTimeEv(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sys5timer12GetDeltaTimeEv(void)
{
    static_init(0, 0xFFFF);
}

