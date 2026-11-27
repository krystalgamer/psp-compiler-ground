/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3sys5timer4PushEv");
__asm__(".globl _GLOBAL__D__ZN3sys5timer4PushEv");

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZNSt11_Deque_baseIfSaIfEED2Ev)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIfSaIfEE17_M_initialize_mapEj)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIfSaIfEE16_M_destroy_nodesEPPfS3_)
    DEMO_LINKONCE(_ZNSt5dequeIfSaIfEE16_M_push_back_auxERKf)
    DEMO_LINKONCE(_ZNSt5dequeIfSaIfEE15_M_pop_back_auxEv)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIfSaIfEE15_M_create_nodesEPPfS3_)
    DEMO_LINKONCE(_ZNSt5dequeIfSaIfEE17_M_reallocate_mapEjb)
    DEMO_LINKONCE(_ZSt6__copyISt15_Deque_iteratorIfRKfPS1_ES0_IfRfPfEET0_T_S9_S8_St26random_access_iterator_tag)
);
#include <deque>
#include <stack>

namespace sys {
namespace timer {
static std::stack<float> time_stack;
float GetTime();
float Pop(const char *);
void Push();
}
}

void sys::timer::Push()
{
    time_stack.push(GetTime());
}

float sys::timer::Pop(const char *name)
{
    if (time_stack.empty())
        return -1;
    float t = time_stack.top();
    time_stack.pop();
    t = GetTime() - t;
    if (t > 60) {
        int m = (int)t / 60;
        std::cout << name << " " << m << "'" << (int)((t - m * 60) * 100) / 100 << "\"" << std::endl;
    } else
        std::cout << name << " " << t << std::endl;
    return t;
}

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

/* deque instances of this object that only its asm functions use: called from here (a discarded function) so that
   cc1plus emits them (their order is DEMO_LINKONCE_ORDER's) */
extern "C" void sys_timer_Push_instance_refs(std::deque<float> &d, std::deque<float> &e) __attribute__((section(".discard.asm")));
extern "C" void sys_timer_Push_instance_refs(std::deque<float> &d, std::deque<float> &e)
{
    std::deque<float> t(e);
    d.push_back(e.back());
    d.pop_back();
    d = e;
}
