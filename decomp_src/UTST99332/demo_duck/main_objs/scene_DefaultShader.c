/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZN6common6handleIN5scene8MaterialEE10invalidateEv)
    SCENE_LINKONCE(_ZN6common6handleIN5scene13DefaultShaderEE10invalidateEv)
    SCENE_LINKONCE(_ZN6common6handleIN5scene8MaterialEEaSERKS3_)
    SCENE_LINKONCE(_ZN6common6handleIN5scene8MaterialEED1Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene13DefaultShaderEED1Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_13DefaultShaderEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene8MaterialEED0Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene13DefaultShaderEED0Ev)
);

extern const char D_00169094[];     /* "DefaultShader" */

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _Z41__static_initialization_and_destruction_0ii_5F3B4);

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

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_5F3B4");
void _GLOBAL__I__ZN5scene13DefaultShaderC2ESsb(void);
void _GLOBAL__D__ZN5scene13DefaultShaderC2ESsb(void);
}

void _GLOBAL__I__ZN5scene13DefaultShaderC2ESsb(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene13DefaultShaderC2ESsb(void)
{
    static_init(0, 0xFFFF);
}

/* inline in the original (emitted with the vtable): out of line here, at their place */
bool scene::Node::isGroup() const
{
    return false;
}

bool scene::Node::isClonable() const
{
    return false;
}

const char *scene::DefaultShader::getTypeName() const
{
    return D_00169094;
}

common::handle<scene::Node> scene::DefaultShader::clone(std::string suffix) const
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
