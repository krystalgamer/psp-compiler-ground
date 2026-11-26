/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"
#include "../gl.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Texture", _Z41__static_initialization_and_destruction_0ii_94E70);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Texture", _ZN5scene7TextureC2ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Texture", _ZN5scene7TextureC1ESsb);

void scene::Texture::setPath(std::string path)
{
    _path = path;
}

const std::string &scene::Texture::getPath() const
{
    return _path;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Texture", _ZN5scene7TextureD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Texture", _ZN5scene7TextureD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Texture", _ZN5scene7TextureD0Ev);

void scene::Texture::invalidate()
{
    _invalid = true;
    _loaded = false;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Texture", _ZN5scene7Texture4loadEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Texture", _ZN5scene7Texture5enterEv);

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
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_94E70");
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Texture", _ZNK5scene7Texture11getTypeNameEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Texture", _ZNK5scene7Texture5cloneESs);

