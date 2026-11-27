/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const char D_0016CA6C[];

/* the strings stay in the module's .rodata (asm) */
extern const char D_0016CAB4[];     /* " *** error " */
extern const char D_0016CAC0[];     /* "_m._parent_count == 0" */
extern const char D_0016CAD8[];     /* "../lib/scene/Node.cpp" */
extern const char D_0016CAF0[];     /* " " */
extern const char incrParentCount_name[] __asm__("_ZZN5scene4Node15incrParentCountEvE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Node_2", _Z41__static_initialization_and_destruction_0ii_90870);

void scene::Node::set_default_name() {
}

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Node_2", _ZNK5scene4Node11getBasenameEv);

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
    SCENE_ASSERT(_m._parent_count == 0, D_0016CAB4, D_0016CAC0, D_0016CAD8, incrParentCount_name, 115, D_0016CAF0);
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

int scene::Node::getCreateCount() const
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

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_90870");
void _GLOBAL__I__ZN5scene4Node19constructor_counterE(void);
void _GLOBAL__D__ZN5scene4Node19constructor_counterE(void);
}

void _GLOBAL__I__ZN5scene4Node19constructor_counterE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene4Node19constructor_counterE(void)
{
    static_init(0, 0xFFFF);
}

const char *scene::Node::getTypeName() const
{
    return D_0016CA6C;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Node_2", _ZNK5scene4Node5cloneESs);

