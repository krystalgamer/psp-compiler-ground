/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _Z41__static_initialization_and_destruction_0ii_FC798);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZN3sys5timer4PushEv);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZNSt11_Deque_baseIfSaIfEED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZNSt11_Deque_baseIfSaIfEE17_M_initialize_mapEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZNSt11_Deque_baseIfSaIfEE16_M_destroy_nodesEPPfS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZNSt5dequeIfSaIfEE16_M_push_back_auxERKf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZNSt5dequeIfSaIfEE15_M_pop_back_auxEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZNSt11_Deque_baseIfSaIfEE15_M_create_nodesEPPfS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZNSt5dequeIfSaIfEE17_M_reallocate_mapEjb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sys_timer_Push", _ZSt6__copyISt15_Deque_iteratorIfRKfPS1_ES0_IfRfPfEET0_T_S9_S8_St26random_access_iterator_tag);
