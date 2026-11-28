/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
/* BVdata::create's strings in this object */
extern const char scene_bvdata_warn[] __asm__("D_0016CD38");         /* " *** warning " */
extern const char scene_bvdata_notvalid[] __asm__("D_0016CD48");     /* "! valid()" */
extern const char scene_bvdata_file[] __asm__("D_0016CD54");         /* "../lib/scene/BVdata.h" */
extern const char scene_bvdata_created[] __asm__("D_0016CD6C");      /* "bounding box already created" */
extern const char scene_bvdata_create_name[] __asm__("_ZZN5scene6BVdata6createEN3sgl2BV4TypeEE19__PRETTY_FUNCTION___16CD0C");
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN5scene5ShapeC2ESsb\n_GLOBAL__I__ZN5scene5ShapeC2ESsb = _GLOBAL__I__ZN5scene5ShapeC2ESsb__asm");
__asm__(".globl _GLOBAL__D__ZN5scene5ShapeC2ESsb\n_GLOBAL__D__ZN5scene5ShapeC2ESsb = _GLOBAL__D__ZN5scene5ShapeC2ESsb__asm");
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZNK5scene5Shape11getTypeNameEv)
    SCENE_LINKONCE(_ZNK5scene5Shape5cloneESs)
    SCENE_LINKONCE(_ZN6common6handleIN5scene5SetupEEaSERKS3_)
);

extern const char D_0016CD04[];

scene::Shape::Shape(std::string name, bool b) : Group(name, b)
{
    set_default_name();
    _bvdata.create((sgl::BV::Type)0);
}

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

/* inline in the class (weak copies emitted with the vtable, in the object's tail) */
SGL_LINKONCE_BEGIN
inline const char *scene::Shape::getTypeName() const
{
    return D_0016CD04;
}
SGL_LINKONCE_END

/* inline in the class too (weak copies in the tail), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Shape", _ZNK5scene5Shape5cloneESs);
