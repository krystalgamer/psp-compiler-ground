/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN5scene17TraversalVarStackC2ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf\n_GLOBAL__I__ZN5scene17TraversalVarStackC2ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf = _GLOBAL__I__ZN5scene17TraversalVarStackC2ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf__asm");
__asm__(".globl _GLOBAL__D__ZN5scene17TraversalVarStackC2ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf\n_GLOBAL__D__ZN5scene17TraversalVarStackC2ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf = _GLOBAL__D__ZN5scene17TraversalVarStackC2ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf__asm");
SCENE_ALLOC_FIRST_USE
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZNSt11_Deque_baseIN5scene17TraversalVarStack12StackElementESaIS2_EED2Ev)
    SCENE_LINKONCE(_ZNSt11_Deque_baseIbSaIbEED2Ev)
    SCENE_LINKONCE(_ZNSt11_Deque_baseIN5scene17TraversalVarStack12StackElementESaIS2_EE17_M_initialize_mapEj)
    SCENE_LINKONCE(_ZNSt11_Deque_baseIN5scene17TraversalVarStack12StackElementESaIS2_EE16_M_destroy_nodesEPPS2_S6_)
    SCENE_LINKONCE(_ZNSt11_Deque_baseIbSaIbEE17_M_initialize_mapEj)
    SCENE_LINKONCE(_ZNSt11_Deque_baseIbSaIbEE16_M_destroy_nodesEPPbS3_)
    SCENE_LINKONCE(_ZNSt5dequeIN5scene17TraversalVarStack12StackElementESaIS2_EE16_M_push_back_auxERKS2_)
    SCENE_LINKONCE(_ZNSt5dequeIN5scene17TraversalVarStack12StackElementESaIS2_EE15_M_pop_back_auxEv)
    SCENE_LINKONCE(_ZNSt11_Deque_baseIN5scene17TraversalVarStack12StackElementESaIS2_EE15_M_create_nodesEPPS2_S6_)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxISt15_Deque_iteratorIN5scene17TraversalVarStack12StackElementERKS3_PS4_ES0_IS3_RS3_PS3_EET0_T_SC_SB_12__false_type)
    SCENE_LINKONCE(_ZNSt11_Deque_baseIbSaIbEE15_M_create_nodesEPPbS3_)
    SCENE_LINKONCE(_ZNSt5dequeIN5scene17TraversalVarStack12StackElementESaIS2_EE17_M_reallocate_mapEjb)
    SCENE_LINKONCE(_ZSt6__copyISt15_Deque_iteratorIbRKbPS1_ES0_IbRbPbEET0_T_S9_S8_St26random_access_iterator_tag)
);

/* the strings stay in the module's .rodata (asm) */
extern const char D_0016D290[];     /* "! _stack.empty()" */
extern const char D_0016D2A4[];     /* "../lib/scene/TraversalVarStack.cpp" */
extern const char D_0016D2C8[];     /* " *** error " */
extern const char D_0016D2D4[];     /* " " */
extern const char internal_pop_name[] __asm__("_ZZN5scene17TraversalVarStack12internal_popEvE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZN5scene17TraversalVarStackC2ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZN5scene17TraversalVarStackC1ENS_13TraversalTypeERN3sgl7FrustumEN4math6matrixES6_S6_N2sh9VectorRGBEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZN5scene17TraversalVarStackD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZN5scene17TraversalVarStackD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_TraversalVarStack", _ZN5scene17TraversalVarStack13internal_pushEv);

void scene::TraversalVarStack::internal_pop()
{
    SCENE_ASSERT(! _stack.empty(), D_0016D2C8, D_0016D290, D_0016D2A4, internal_pop_name, 82, D_0016D2D4);
    _stack.pop();
    if (!_stack.empty()) {
        glLoadMatrixf((const float *)&_stack.top().m70);
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

/* instances used by the (asm) methods above.  Explicit instantiations of single members (an
   out-of-class member instantiated this way becomes inlinable into this unit's callers, e.g.
   _M_pop_back_aux into internal_pop, ~_Deque_base would inline _M_destroy_nodes) */
namespace std {
typedef scene::TraversalVarStack::StackElement TVS_SE;
template deque<TVS_SE>::deque(const deque<TVS_SE> &);
template deque<TVS_SE>::~deque();
template deque<bool>::deque(const deque<bool> &);
template deque<bool>::~deque();
template _Deque_iterator<bool, bool &, bool *> __copy(_Deque_iterator<bool, const bool &, const bool *>,
                                                      _Deque_iterator<bool, const bool &, const bool *>,
                                                      _Deque_iterator<bool, bool &, bool *>, random_access_iterator_tag);
template void deque<TVS_SE>::_M_reallocate_map(size_t, bool);
template void deque<TVS_SE>::_M_push_back_aux(const TVS_SE &);
}
