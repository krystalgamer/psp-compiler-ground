/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" const char D_00160FD4[], D_00160FE0[], D_00160FF4[], D_00161014[];
extern const char VirtualState_pushChild_fn[] __asm__("_ZZN6common12StateMachine12VirtualState9pushChildENS_8safe_ptrIPS1_EEE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_StateMachine_VirtualState", _Z41__static_initialization_and_destruction_0ii_13AC0);

void common::StateMachine::VirtualState::pop()
{
    if (_machine)
        _machine->_pop = true;
}

void common::StateMachine::VirtualState::pushChild(safe_ptr<VirtualState *> s)
{
    popChild();
    SGL_ASSERT(_child.invalid(), D_00160FD4, D_00160FE0, D_00160FF4, VirtualState_pushChild_fn, 0x2C, D_00161014);
    _child = s;
    s->_machine = this;
    _child->enter();
}

void common::StateMachine::VirtualState::popChild()
{
    if (_child.valid()) {
        _child->popChild();
        _child->exit();
        _child.destroy();
    }
}

void common::StateMachine::VirtualState::change(safe_ptr<VirtualState *> s)
{
    _machine->_next = s;
}

void common::StateMachine::VirtualState::update_internal()
{
    if (_pop) {
        popChild();
        _pop = false;
    }
    if (_next.valid()) {
        pushChild(_next);
        _next.p = 0;
    }
}

const char *common::StateMachine::VirtualState::getName()
{
    return _name.c_str();
}

common::StateMachine::VirtualState::VirtualState(const char *name)
    : _child(0), _next(0), _machine(0), _pop(false), _name(name)
{
}

common::StateMachine::VirtualState::~VirtualState()
{
    popChild();
}

common::StateMachine::StateMachine(safe_ptr<VirtualState *> s) : _top(0)
{
    setTop(s);
}

void common::StateMachine::destroy_top()
{
    if (_top.valid()) {
        _top->popChild();
        _top->exit();
        _top.destroy();
    }
}

common::StateMachine::~StateMachine()
{
    destroy_top();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_StateMachine_VirtualState", _ZN6common12StateMachine7processEv);

void common::StateMachine::setTop(safe_ptr<VirtualState *> s)
{
    destroy_top();
    _top = s;
    if (s.valid())
        s->enter();
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_13AC0");
void _GLOBAL__I__ZN6common12StateMachine12VirtualState3popEv(void);
void _GLOBAL__D__ZN6common12StateMachine12VirtualState3popEv(void);
}

void _GLOBAL__I__ZN6common12StateMachine12VirtualState3popEv(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN6common12StateMachine12VirtualState3popEv(void)
{
    static_init(0, 0xFFFF);
}

