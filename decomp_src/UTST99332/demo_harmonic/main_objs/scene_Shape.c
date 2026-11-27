/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
/* BVdata::create's strings in this object */
extern const char scene_bvdata_warn[] __asm__("D_00169E10");         /* " *** warning " */
extern const char scene_bvdata_notvalid[] __asm__("D_00169E20");     /* "! valid()" */
extern const char scene_bvdata_file[] __asm__("D_00169E2C");         /* "../lib/scene/BVdata.h" */
extern const char scene_bvdata_created[] __asm__("D_00169E44");      /* "bounding box already created" */
extern const char scene_bvdata_create_name[] __asm__("_ZZN5scene6BVdata6createEN3sgl2BV4TypeEE19__PRETTY_FUNCTION___169DE4");
#include "../main.hpp"

extern const char D_00169DDC[];

/* these template instances are still asm below */
namespace common {
extern template class handle<scene::Setup>;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Shape", _Z41__static_initialization_and_destruction_0ii_9035C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Shape", _ZN5scene5ShapeC2ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Shape", _ZN5scene5ShapeC1ESsb);

scene::Shape::~Shape()
{
}

const common::handle<scene::Setup> &scene::Shape::getSetup(Pass p) const
{
    return _setup[p];
}

void scene::Shape::attachSetup(common::handle<Setup> s, Pass p)
{
    _setup[p] = s;
}

void scene::Shape::detachSetup(Pass p)
{
    _setup[p] = common::handle<Setup>();
}

void scene::Shape::attachMaterial(common::handle<Material> &m, Pass p)
{
    common::handle<DefaultShader> ds = _setup[p];
    if (hnull(ds))
        return;
    ds->attachMaterial(m);
}

void scene::Shape::detachMaterial(Pass p)
{
    common::handle<DefaultShader> ds = _setup[p];
    if (hnull(ds))
        return;
    ds->detachMaterial();
}

void scene::Shape::attachTexture(common::handle<Texture> &t, Pass p)
{
    common::handle<DefaultShader> ds = _setup[p];
    if (hnull(ds))
        return;
    ds->attachTexture(t);
}

/* Shape::enter's function-local statics (light directions, in the module's .data) */
extern ScePspFVector3 shape_enter_vec __asm__("_ZZN5scene5Shape5enterENS_4PassEE3vec");
extern ScePspFVector3 shape_enter_vec2 __asm__("_ZZN5scene5Shape5enterENS_4PassEE4vec2");

void scene::Shape::enter(Pass p)
{
    if (hget(_setup[p]))
        _setup[p]->enter();
    if (p == 1) {
        sceGuEnable(11);
        sceGuEnable(12);
        sceGuLight(0, 0, 2, &shape_enter_vec);
        sceGuLight(1, 0, 2, &shape_enter_vec2);
        sceGuTexMapMode(2, 0, 1);
        sceGuEnable(9);
        sceGuBlendFunc(0, 10, 10, 0x40404040, 0xFFFFFFFF);
        sceGuEnable(4);
    }
}

void scene::Shape::leave(Pass p)
{
    if (hget(_setup[p]))
        _setup[p]->leave();
    if (p == 1) {
        sceGuDisable(11);
        sceGuDisable(12);
        sceGuTexMapMode(0, 0, 0);
        sceGuDisable(4);
    }
}

void scene::Shape::flatten(math::TransformStack &ts)
{
    Group::flatten(ts);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_9035C");
void _GLOBAL__I__ZN5scene5ShapeC2ESsb(void);
void _GLOBAL__D__ZN5scene5ShapeC2ESsb(void);
}

void _GLOBAL__I__ZN5scene5ShapeC2ESsb(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene5ShapeC2ESsb(void)
{
    static_init(0, 0xFFFF);
}

const char *scene::Shape::getTypeName() const
{
    return D_00169DDC;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Shape", _ZNK5scene5Shape5cloneESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Shape", _ZN6common6handleIN5scene5SetupEEaSERKS3_);

