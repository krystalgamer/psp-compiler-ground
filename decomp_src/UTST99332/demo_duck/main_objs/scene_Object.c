/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SCENE_BVDATA_LITERALS
#define SCENE_BVDATA_CREATE
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZNK5scene6Object11getTypeNameEv)
    SCENE_LINKONCE(_ZNK5scene6Object5cloneESs)
);

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene6ObjectC2ESsb");
__asm__(".globl _GLOBAL__D__ZN5scene6ObjectC2ESsb");

/* inline in the class (weak copies emitted with the vtable, in the object's tail) */
SGL_LINKONCE_BEGIN
inline const char *scene::Object::getTypeName() const
{
    return "Object";
}
/* clone() (asm) inlines Object::operator= -> BVdata::operator= -> create(): create's __PRETTY_FUNCTION__
   stays in .rodata (its warning is dead code); this linkonce copy (discarded by the link) emits it there */
inline void Object_refs(scene::Object &a, const scene::Object &b)
{
    a = b;
}
SGL_LINKONCE_END

scene::Object::Object(std::string name, bool b) : Group(name, b)
{
    set_default_name();
}

scene::Object::~Object()
{
}

void scene::Object::flatten(math::TransformStack &ts)
{
    Group::flatten(ts);
}

/* inline in the class too (weak copies in the tail), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Object", _ZNK5scene6Object5cloneESs);
