/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3BVHC2Ev");
__asm__(".globl _GLOBAL__D__ZN3BVHC2Ev");

BVH::BVH() : _depth(0)
{
}


void BVH::Node::draw() const
{
    _bv.draw();
    if (_child[0])
        _child[0]->draw();
    if (_child[1])
        _child[1]->draw();
}

void BVH::draw() const
{
    _root.draw();
}

void BVH::setChild(Node::ChildEnum c, Node *parent, Node *child)
{
    if (parent->_child[c]) {
        delete parent->_child[c];
        parent->_child[c] = 0;
    }
    parent->_child[c] = child;
    parent->_leaf = parent->_child[0] == 0 && parent->_child[1] == 0;
    child->_depth = parent->_depth + 1;
    if (_depth < child->_depth)
        _depth = child->_depth;
}

void BVH::print()
{
    print(&_root);
}

void BVH::print(Node *n)
{
    if (n->_leaf)
        return;
    Node *c0 = n->_child[0];
    if (c0)
        print(c0);
    Node *c1 = n->_child[1];
    if (c1)
        print(c1);
}

/* BVH::Node's inline destructor (weak copy in the tail) */
SGL_LINKONCE_BEGIN
inline BVH::Node::~Node()
{
    for (int i = 0; i != 2; i++) {
        if (_child[i])
            delete _child[i];
        _child[i] = 0;
    }
}
SGL_LINKONCE_END
