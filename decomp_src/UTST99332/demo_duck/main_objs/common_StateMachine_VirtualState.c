/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN6common12StateMachine12VirtualState3popEv");
__asm__(".globl _GLOBAL__D__ZN6common12StateMachine12VirtualState3popEv");


void common::StateMachine::VirtualState::pop()
{
    if (_machine)
        _machine->_pop = true;
}

void common::StateMachine::VirtualState::pushChild(safe_ptr<VirtualState *> s)
{
    popChild();
    SGL_ASSERT(_child.invalid(), " *** error ", "_child.invalid()", "../lib/common/StateMachine.cpp", __PRETTY_FUNCTION__, 0x2C, " ");
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
        _next = 0;
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

void common::StateMachine::process()
{
    if (_top.invalid())
        return;
    safe_ptr<VirtualState *> s = _top;
    while (s->_child.valid())
        s = s->_child;
    s->update_internal();
    s->update();
    s = s->_machine;
    while (s.valid()) {
        s->update_internal();
        s->draw();
        s = s->_machine;
    }
}

void common::StateMachine::setTop(safe_ptr<VirtualState *> s)
{
    destroy_top();
    _top = s;
    if (s.valid())
        s->enter();
}
