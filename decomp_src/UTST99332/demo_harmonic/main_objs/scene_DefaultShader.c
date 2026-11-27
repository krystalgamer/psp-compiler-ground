/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene13DefaultShaderC2ESsb");
__asm__(".globl _GLOBAL__D__ZN5scene13DefaultShaderC2ESsb");
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZNK5scene4Node7isGroupEv)
    SCENE_LINKONCE(_ZNK5scene4Node10isClonableEv)
    SCENE_LINKONCE(_ZNK5scene13DefaultShader11getTypeNameEv)
    SCENE_LINKONCE(_ZNK5scene13DefaultShader5cloneESs)
    SCENE_LINKONCE(_ZN6common6handleIN5scene8MaterialEE10invalidateEv)
    SCENE_LINKONCE(_ZN6common6handleIN5scene13DefaultShaderEE10invalidateEv)
    SCENE_LINKONCE(_ZN6common6handleIN5scene8MaterialEEaSERKS3_)
    SCENE_LINKONCE(_ZN6common6handleIN5scene7TextureEEaSERKS3_)
    SCENE_LINKONCE(_ZN6common6handleIN5scene8MaterialEED1Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene13DefaultShaderEED1Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_13DefaultShaderEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene8MaterialEED0Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene13DefaultShaderEED0Ev)
);

/* inline in the class (weak copies emitted with the vtable, in the object's tail) */
SGL_LINKONCE_BEGIN
inline bool scene::Node::isGroup() const
{
    return false;
}

inline bool scene::Node::isClonable() const
{
    return false;
}

inline const char *scene::DefaultShader::getTypeName() const
{
    return "DefaultShader";
}

inline common::handle<scene::Node> scene::DefaultShader::clone(std::string suffix) const
{
    std::string name = getBasename();
    name += suffix;
    common::handle<DefaultShader> h(new DefaultShader(name.c_str(), false));
    *h = *this;
    h->setName(name.c_str());
    h->_m._mapped = false;
    while (h->getParentCount())
        h->decrParentCount();
    return h;
}
SGL_LINKONCE_END

scene::DefaultShader::DefaultShader(std::string name, bool b) : Setup(name, b)
{
    set_default_name();
}

scene::DefaultShader::~DefaultShader()
{
}

void scene::DefaultShader::enter()
{
    scene_glPushAttrib(GL_ENABLE_BIT);
    if (hvalid(_material)) _material->enter(); if (hvalid(_texture)) _texture->enter();
}

void scene::DefaultShader::leave()
{
    if (hvalid(_material))
        _material->leave();
    if (hvalid(_texture))
        _texture->leave();
    scene_glPopAttrib();
}

void scene::DefaultShader::attachMaterial(common::handle<Material> &m)
{
    _material = m;
}

void scene::DefaultShader::detachMaterial()
{
    _material = common::handle<Material>();
}

void scene::DefaultShader::attachTexture(common::handle<Texture> &t)
{
    _texture = t;
}

common::handle<scene::Material> &scene::DefaultShader::getMaterial()
{
    return _material;
}

const common::handle<scene::Material> &scene::DefaultShader::getMaterial() const
{
    return _material;
}

common::handle<scene::Texture> &scene::DefaultShader::getTexture()
{
    return _texture;
}

const common::handle<scene::Texture> &scene::DefaultShader::getTexture() const
{
    return _texture;
}

void scene::DefaultShader::flatten(math::TransformStack &) {
}

void scene::DefaultShader::save(std::ostream &) {
}

