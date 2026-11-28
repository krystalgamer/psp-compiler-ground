/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_INTERP
#define DEMO_TEMPLATE_DEFS
#define DEMO_LINKONCE_shared_object_base 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN5app3d9CallbacksC2Ej\n_GLOBAL__I__ZN5app3d9CallbacksC2Ej = _GLOBAL__I__ZN5app3d9CallbacksC2Ej__asm");
__asm__(".globl _GLOBAL__D__ZN5app3d9CallbacksC2Ej\n_GLOBAL__D__ZN5app3d9CallbacksC2Ej = _GLOBAL__D__ZN5app3d9CallbacksC2Ej__asm");

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN5input9ButtonSetIN3psp4PadBEE3setEjb)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils9TurnTableEE10invalidateEv)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils20PositioningInterfaceEEaSERKS3_)
    DEMO_LINKONCE(_ZN6common18shared_object_baseD1Ev)
    DEMO_LINKONCE(_ZN6common18shared_object_baseD0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils9TurnTableEEC1INS1_20PositioningInterfaceEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils9TurnTableEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils9TurnTableEED0Ev)
);

namespace common {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9CallbacksC2Ej);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9CallbacksC1Ej);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9CallbacksD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9CallbacksD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9CallbacksD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9Callbacks8init_pspEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9Callbacks12reset_cameraEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9Callbacks4initEv);

void app3d::Callbacks::setCameraFilename(const char *name)
{
    _camera_filename = name;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9Callbacks10loadCameraEv);

void app3d::Callbacks::resetCamera()
{
    getCamera()->set(_initial_frame);
}

common::handle<glutils::PositioningInterface> app3d::Callbacks::getCamera()
{
    return _camera;
}

const common::handle<glutils::PositioningInterface> &app3d::Callbacks::getCamera() const
{
    return _camera;
}

void app3d::Callbacks::replaceCamera(common::handle<glutils::PositioningInterface> c)
{
    _camera = c;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9Callbacks4idleEv);

void app3d::Callbacks::draw() {
}

void app3d::Callbacks::before_vsync() {
}

void app3d::Callbacks::toggleGrid()
{
    grid = !grid;
}

void app3d::Callbacks::displayGrid(bool b)
{
    grid = b;
}

void app3d::Callbacks::setSceneScale(float s)
{
    scene_scale = s;
    reset_camera();
}

void app3d::Callbacks::togglePivot()
{
    pivot = !pivot;
}

void app3d::Callbacks::setFrustum(const sgl::Frustum &f)
{
    frustum() = f;
}

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

/* instances of this object that only its asm functions use: called from here (a discarded function) so that
   cc1plus emits them (their order is DEMO_LINKONCE_ORDER's) */
extern "C" void app3d_Callbacks_instance_refs(common::handle<glutils::TurnTable> &t, common::handle<glutils::PositioningInterface> &p)
    __attribute__((section(".discard.asm")));
extern "C" void app3d_Callbacks_instance_refs(common::handle<glutils::TurnTable> &t, common::handle<glutils::PositioningInterface> &p)
{
    t.invalidate();
    common::handle<glutils::TurnTable> a(p);
}

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

extern "C" const char D_0015F0E0[], D_0015F110[], D_0015F1D4[], D_0015F1EC[];
extern const char ButtonSet_set_name[] __asm__("_ZZN5input9ButtonSetIN3psp4PadBEE3setEjbE19__PRETTY_FUNCTION__");
template<class T> void input::ButtonSet<T>::set(unsigned int _Index, bool v)
{
    SGL_ASSERT(_Index < N, D_0015F0E0, D_0015F1EC, D_0015F1D4, ButtonSet_set_name, 0x4A, D_0015F110);
    Button &bt = b[_Index];
    bt.down = v;
}
/* the (asm) callers' instance: emitted through a discarded user */
extern "C" void app3d_Callbacks_ButtonSet_refs(input::ButtonSet<psp::PadB> &s) __attribute__((section(".discard.asm")));
extern "C" void app3d_Callbacks_ButtonSet_refs(input::ButtonSet<psp::PadB> &s)
{
    s.set(0, false);
}
