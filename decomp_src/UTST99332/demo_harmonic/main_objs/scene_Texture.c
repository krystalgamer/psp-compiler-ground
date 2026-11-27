/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const char D_0016A05C[];
extern const char D_0016A064[];     /* "\n" */
extern const char D_0016A068[];     /* "load failed\n" */
extern const char D_0016A078[];     /* "load ok! \n" */
extern const char D_0016A084[];     /* "pass1" */
extern const char D_0016A08C[];     /* "'s format is " */
extern const char D_0016A09C[];     /* "add_alpha" */
#include "../../demo_duck/gl.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Texture", _Z41__static_initialization_and_destruction_0ii_92A4C);

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
    common::Log() << _path.c_str() << D_0016A064;
    _invalid = textures_Texture_load(_tex.t, _path.c_str()) < 0;
    textures::Texture::OverrideAlpha(-1);
    if (_invalid) {
        common::Log() << D_0016A068;
        return;
    }
    common::Log() << D_0016A078;
    if (!_tex.t.is32())
        common::Log() << _path.c_str() << D_0016A08C << textures::FormatName(_tex.t.format()) << D_0016A064;
    if (!_texid)
        gl_GenTextures(1, &_texid);
    _tex.t.setFiltering((textures::Filtering)0);
    _tex.t.setTextureFunc(_hint == D_0016A084 ? (textures::TextureFunction)0 : (textures::TextureFunction)0);
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
        if (_hint == D_0016A09C)
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

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_92A4C");
void _GLOBAL__I__ZN5scene7Texture12debug_outputE(void);
void _GLOBAL__D__ZN5scene7Texture12debug_outputE(void);
}

void _GLOBAL__I__ZN5scene7Texture12debug_outputE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene7Texture12debug_outputE(void)
{
    static_init(0, 0xFFFF);
}

const char *scene::Texture::getTypeName() const
{
    return D_0016A05C;
}

common::handle<scene::Node> scene::Texture::clone(std::string suffix) const
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

