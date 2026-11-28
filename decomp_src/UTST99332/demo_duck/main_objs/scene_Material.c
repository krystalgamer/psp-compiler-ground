/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN5scene8MaterialC2ESsb\n_GLOBAL__I__ZN5scene8MaterialC2ESsb = _GLOBAL__I__ZN5scene8MaterialC2ESsb__asm");
__asm__(".globl _GLOBAL__D__ZN5scene8MaterialC2ESsb\n_GLOBAL__D__ZN5scene8MaterialC2ESsb = _GLOBAL__D__ZN5scene8MaterialC2ESsb__asm");

extern const char D_0016B99C[];
#include "../gl.hpp"

scene::Material::Material(std::string name, bool b) : Setup(name, b)
{
    set_default_name();
}

/* inline in the class (weak copies emitted with the vtable, in the object's tail) */
SGL_LINKONCE_BEGIN
inline const char *scene::Material::getTypeName() const
{
    return D_0016B99C;
}

inline common::handle<scene::Node> scene::Material::clone(std::string suffix) const
{
    std::string name = getBasename();
    name += suffix;
    common::handle<Material> h(new Material(name.c_str(), false));
    *h = *this;
    h->setName(name.c_str());
    h->_m._mapped = false;
    while (h->getParentCount())
        h->decrParentCount();
    return h;
}
SGL_LINKONCE_END

scene::Material::~Material()
{
}

glutils::Material &scene::Material::getMaterial()
{
    return _material;
}

const glutils::Material &scene::Material::getMaterial() const
{
    return _material;
}

void scene::Material::enter()
{
    _material.setup();
    glEnable(GL_COLOR_MATERIAL);
}

void scene::Material::leave()
{
    glDisable(GL_COLOR_MATERIAL);
}

void scene::Material::flatten(math::TransformStack &) {
}

