/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

namespace common {
extern template class handle<glutils::PositioningInterface>;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _Z41__static_initialization_and_destruction_0ii_13E64);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9CallbacksC2Ej);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9CallbacksC1Ej);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9CallbacksD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9CallbacksD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9CallbacksD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9Callbacks8init_pspEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9Callbacks12reset_cameraEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9Callbacks4initEv);

void app3d::Callbacks::setCameraFilename(const char *name)
{
    _camera_filename = name;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9Callbacks10loadCameraEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9Callbacks11resetCameraEv);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9Callbacks4idleEv);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5app3d9Callbacks10setFrustumERKN3sgl7FrustumE);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_13E64");
void _GLOBAL__I__ZN5app3d9CallbacksC2Ej(void);
void _GLOBAL__D__ZN5app3d9CallbacksC2Ej(void);
}

void _GLOBAL__I__ZN5app3d9CallbacksC2Ej(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5app3d9CallbacksC2Ej(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN5input9ButtonSetIN3psp4PadBEE3setEjb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/app3d_Callbacks", _ZN6common6handleIN7glutils20PositioningInterfaceEEaSERKS3_);
