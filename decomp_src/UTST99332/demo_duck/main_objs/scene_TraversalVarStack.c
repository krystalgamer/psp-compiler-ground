/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* these template instances are still asm below */
namespace std {
extern template class _Deque_base<scene::TraversalVarStack::StackElement, allocator<scene::TraversalVarStack::StackElement> >;
extern template class deque<scene::TraversalVarStack::StackElement>;
}

/* the strings stay in the module's .rodata (asm) */
extern const char D_0016D290[];     /* "! _stack.empty()" */
extern const char D_0016D2A4[];     /* "../lib/scene/TraversalVarStack.cpp" */
extern const char D_0016D2C8[];     /* " *** error " */
extern const char D_0016D2D4[];     /* " " */
extern const char internal_pop_name[] __asm__("_ZZN5scene17TraversalVarStack12internal_popEvE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _Z41__static_initialization_and_destruction_0ii_9AB00);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZN5scene17TraversalVarStackC2ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZN5scene17TraversalVarStackC1ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZN5scene17TraversalVarStackD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZN5scene17TraversalVarStackD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZN5scene17TraversalVarStack13internal_pushEv);

void scene::TraversalVarStack::internal_pop()
{
    SCENE_ASSERT(! _stack.empty(), D_0016D2C8, D_0016D290, D_0016D2A4, internal_pop_name, 82, D_0016D2D4);
    _stack.pop_back();
    if (!_stack.empty()) {
        glLoadMatrixf((const float *)&_stack.back().m70);
        sceGumSetCurMatrix();
    }
}

void scene::TraversalVarStack::push()
{
    _depth++;
}

void scene::TraversalVarStack::pop()
{
    if (_depth == 0)
        internal_pop();
    else
        _depth--;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZN5scene17TraversalVarStack4multERKN4math6matrixEbb);

void scene::TraversalVarStack::enable(Enabled e, bool on)
{
    if (on)
        _enabled |= e;
    else
        _enabled &= ~e;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_9AB00");
void _GLOBAL__I__ZN5scene17TraversalVarStackC2ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf(void);
void _GLOBAL__D__ZN5scene17TraversalVarStackC2ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf(void);
}

void _GLOBAL__I__ZN5scene17TraversalVarStackC2ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene17TraversalVarStackC2ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZNSt11_Deque_baseIN5scene17TraversalVarStack12StackElementESaIS2_EED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZNSt11_Deque_baseIbSaIbEED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZNSt11_Deque_baseIN5scene17TraversalVarStack12StackElementESaIS2_EE17_M_initialize_mapEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZNSt11_Deque_baseIN5scene17TraversalVarStack12StackElementESaIS2_EE16_M_destroy_nodesEPPS2_S6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZNSt11_Deque_baseIbSaIbEE17_M_initialize_mapEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZNSt11_Deque_baseIbSaIbEE16_M_destroy_nodesEPPbS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZNSt5dequeIN5scene17TraversalVarStack12StackElementESaIS2_EE16_M_push_back_auxERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZNSt5dequeIN5scene17TraversalVarStack12StackElementESaIS2_EE15_M_pop_back_auxEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZNSt11_Deque_baseIN5scene17TraversalVarStack12StackElementESaIS2_EE15_M_create_nodesEPPS2_S6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZSt24__uninitialized_copy_auxISt15_Deque_iteratorIN5scene17TraversalVarStack12StackElementERKS3_PS4_ES0_IS3_RS3_PS3_EET0_T_SC_SB_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZNSt11_Deque_baseIbSaIbEE15_M_create_nodesEPPbS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZNSt5dequeIN5scene17TraversalVarStack12StackElementESaIS2_EE17_M_reallocate_mapEjb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZSt6__copyISt15_Deque_iteratorIbRKbPS1_ES0_IbRbPbEET0_T_S9_S8_St26random_access_iterator_tag);
