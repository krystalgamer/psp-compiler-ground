/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"
#include "UTST99332/demo_duck/gl.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Material", _Z41__static_initialization_and_destruction_0ii_84BF0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Material", _ZN5scene8MaterialC2ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Material", _ZN5scene8MaterialC1ESsb);

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

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_84BF0");
void _GLOBAL__I__ZN5scene8MaterialC2ESsb(void);
void _GLOBAL__D__ZN5scene8MaterialC2ESsb(void);
}

void _GLOBAL__I__ZN5scene8MaterialC2ESsb(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene8MaterialC2ESsb(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Material", _ZNK5scene8Material11getTypeNameEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Material", _ZNK5scene8Material5cloneESs);

