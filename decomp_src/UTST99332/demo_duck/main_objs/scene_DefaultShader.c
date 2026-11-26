/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* these template instances are still asm below */
namespace common {
extern template class handle<scene::Material>;
extern template class handle<scene::DefaultShader>;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _Z41__static_initialization_and_destruction_0ii_5F3B4);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN5scene13DefaultShaderC2ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN5scene13DefaultShaderC1ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN5scene13DefaultShaderD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN5scene13DefaultShaderD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN5scene13DefaultShaderD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN5scene13DefaultShader5enterEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN5scene13DefaultShader5leaveEv);

void scene::DefaultShader::attachMaterial(common::handle<Material> &m)
{
    _material = m;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN5scene13DefaultShader14detachMaterialEv);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZNK5scene4Node7isGroupEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZNK5scene4Node10isClonableEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZNK5scene13DefaultShader11getTypeNameEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZNK5scene13DefaultShader5cloneESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN6common6handleIN5scene8MaterialEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN6common6handleIN5scene13DefaultShaderEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN6common6handleIN5scene8MaterialEEaSERKS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN6common6handleIN5scene8MaterialEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN6common6handleIN5scene13DefaultShaderEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN6common6handleIN5scene4NodeEEC1INS1_13DefaultShaderEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN6common6handleIN5scene8MaterialEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_DefaultShader", _ZN6common6handleIN5scene13DefaultShaderEED0Ev);

