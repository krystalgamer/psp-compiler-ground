/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene4Node19constructor_counterE");
__asm__(".globl _GLOBAL__D__ZN5scene4Node19constructor_counterE");

int scene::Node::constructor_counter;
std::string scene::Node::NULL_COLOR("red");
std::string scene::Node::DEFAULT_COLOR("black");

int Node_getParentCount(const scene::Node *) __asm__("_ZNK5scene4Node14getParentCountEv");
void Node_decrParentCount(scene::Node *) __asm__("_ZN5scene4Node15decrParentCountEv");
void Node_setName(scene::Node *, std::string) __asm__("_ZN5scene4Node7setNameESs");

void scene::Node::set_default_name() {
}

/* inline in the class (weak copies emitted with the vtable, in the object's tail) */
SGL_LINKONCE_BEGIN
inline const char *scene::Node::getTypeName() const
{
    return "Node";
}

inline common::handle<scene::Node> scene::Node::clone(std::string suffix) const
{
    std::string name = getBasename();
    name += suffix;
    common::handle<Node> h(new Node(name.c_str(), false));
    *h = *this;
    Node_setName(h.operator->(), name.c_str());
    h->_m._mapped = false;
    while (Node_getParentCount(h.operator->()))
        Node_decrParentCount(h.operator->());
    return h;
}
SGL_LINKONCE_END

scene::Node::Members::Members(std::string name, bool mapped)
    : _name(name), _mapped(mapped), _parent_count(0), _create_count(0), _magic(0), _f24(0)
{
}

scene::Node::Node(std::string name, bool mapped) : _m(name, mapped)
{
    bits = false;
    _m._create_count = constructor_counter++;
}

bool scene::Node::isMapped() const
{
    return _m._mapped;
}

const std::string &scene::Node::getName() const
{
    return _m._name;
}

std::string scene::Node::getBasename() const
{
    size_t pos = _m._name.find("::");
    if (pos == std::string::npos)
        return _m._name;
    std::string s = _m._name.substr(pos + 2);
    return s;
}

void scene::Node::setName(std::string name)
{
    _m._name = name;
}

scene::Node::~Node()
{
}

void scene::Node::flatten(math::TransformStack &) {
}

void scene::Node::incrParentCount()
{
    SCENE_ASSERT(_m._parent_count == 0, " *** error ", "_m._parent_count == 0", "../lib/scene/Node.cpp", __PRETTY_FUNCTION__, 115, " ");
    _m._parent_count++;
}

void scene::Node::decrParentCount()
{
    _m._parent_count--;
}

int scene::Node::getParentCount() const
{
    return _m._parent_count;
}

unsigned int scene::Node::getCreateCount() const
{
    return _m._create_count;
}

void scene::Node::setTmp(unsigned int t)
{
    _m._tmp = t;
}

unsigned int scene::Node::getTmp() const
{
    return _m._tmp;
}

void scene::Node::setMagic(unsigned int m)
{
    _m._magic = m;
}

unsigned int scene::Node::getMagic() const
{
    return _m._magic;
}

