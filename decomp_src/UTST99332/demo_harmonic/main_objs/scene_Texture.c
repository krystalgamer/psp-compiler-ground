/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

#include "../../demo_duck/gl.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene7Texture12debug_outputE");
__asm__(".globl _GLOBAL__D__ZN5scene7Texture12debug_outputE");

bool scene::Texture::debug_output;

/* getTypeName/clone are inline (weak copies in the object's tail, emitted for the vtable) */
SGL_LINKONCE_BEGIN
inline const char *scene::Texture::getTypeName() const
{
    return "Texture";
}

inline common::handle<scene::Node> scene::Texture::clone(std::string suffix) const
{
    std::string name = getBasename();
    name += suffix;
    common::handle<Texture> h(new Texture(name.c_str(), false));
    *h = *this;
    h->setName(name.c_str());
    h->_m._mapped = false;
    while (h->getParentCount())
        h->decrParentCount();
    return h;
}
SGL_LINKONCE_END

scene::Texture::Texture(std::string name, bool b)
    : Setup(name, b), _texid(0), _override_alpha(false), _alpha(128)
{
    set_default_name();
    invalidate();
}

void scene::Texture::setPath(std::string path)
{
    _path = path;
}

const std::string &scene::Texture::getPath() const
{
    return _path;
}

scene::Texture::~Texture()
{
    invalidate();
    if (_texid) {
        gl_DeleteTextures(1, &_texid);
        _texid = 0;
    }
}

void scene::Texture::invalidate()
{
    _invalid = true;
    _loaded = false;
}

void scene::Texture::load()
{
    if (_loaded)
        return;
    _loaded = true;
    if (_override_alpha) {
        textures::Texture::OverrideAlpha(-2);
        textures::Texture::OverrideAlpha(_alpha);
    } else
        textures::Texture::OverrideAlpha(-1);
    common::Log() << _path.c_str() << "\n";
    _invalid = textures_Texture_load(_tex.t, _path.c_str()) < 0;
    textures::Texture::OverrideAlpha(-1);
    if (_invalid) {
        common::Log() << "load failed\n";
        return;
    }
    common::Log() << "load ok! \n";
    if (!_tex.t.is32())
        common::Log() << _path.c_str() << "'s format is " << textures::FormatName(_tex.t.format()) << "\n";
    if (!_texid)
        gl_GenTextures(1, &_texid);
    _tex.t.setFiltering((textures::Filtering)0);
    _tex.t.setTextureFunc(_hint == "pass1" ? (textures::TextureFunction)0 : (textures::TextureFunction)0);
    textures_Texture_resizePow2(_tex.t, false, false, true);
    _tex.t.setWrapS((textures::Wrapping)1);
    _tex.t.setWrapT((textures::Wrapping)1);
    textures_Texture_initGl(_tex.t, _texid);
}

void scene::Texture::enter()
{
    if (!_loaded)
        load();
    if (_invalid)
        glDisable(GL_TEXTURE_2D);
    else {
        textures_Texture_setupGl(_tex.t, _texid, false);
        if (_hint == "add_alpha")
            sceGuTexFunc(4, 1);
    }
}

void scene::Texture::leave()
{
    glDisable(GL_TEXTURE_2D);
}

void scene::Texture::setHint(std::string hint)
{
    _hint = hint;
}

void scene::Texture::setOverrideAlpha(bool b, unsigned char a)
{
    _alpha = a;
    _override_alpha = b;
}

void scene::Texture::flatten(math::TransformStack &) {
}
