/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

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

namespace sys {
namespace timer {
extern std::deque<float> time_stack;
float GetTime();
void Push();
}
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _Z41__static_initialization_and_destruction_0ii_FC798);

void sys::timer::Push()
{
    time_stack.push_back(GetTime());
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZN3sys5timer3PopEPKc);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_FC798");
void _GLOBAL__I__ZN3sys5timer4PushEv(void);
void _GLOBAL__D__ZN3sys5timer4PushEv(void);
}

void _GLOBAL__I__ZN3sys5timer4PushEv(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sys5timer4PushEv(void)
{
    static_init(0, 0xFFFF);
}

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZNSt11_Deque_baseIfSaIfEED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZNSt11_Deque_baseIfSaIfEE17_M_initialize_mapEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZNSt11_Deque_baseIfSaIfEE16_M_destroy_nodesEPPfS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZNSt5dequeIfSaIfEE15_M_pop_back_auxEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZNSt11_Deque_baseIfSaIfEE15_M_create_nodesEPPfS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZSt6__copyISt15_Deque_iteratorIfRKfPS1_ES0_IfRfPfEET0_T_S9_S8_St26random_access_iterator_tag);
