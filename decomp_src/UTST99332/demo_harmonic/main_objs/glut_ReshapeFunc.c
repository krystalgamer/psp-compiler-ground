/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

namespace glut {
void ReshapeFunc(int, int);
void DisplayFunc();
void IdleFunc();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glut_ReshapeFunc", _Z41__static_initialization_and_destruction_0ii_135B4);

void glut::ReshapeFunc(int w, int h)
{
    if (app_ptr)
        app_ptr->reshape(w, h);
}

void glut::DisplayFunc()
{
    if (app_ptr)
        app_ptr->display();
}

void glut::IdleFunc()
{
    if (app_ptr) {
        if (app_ptr->exitRequested())
            exit(0);
        app_ptr->idle();
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glut_ReshapeFunc", _ZN3psp3padEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glut_ReshapeFunc", _ZN3psp10MainThreadEjPv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glut_ReshapeFunc", _ZN3psp15StartMainThreadEv);

int app::width()
{
    return glut::screen_width;
}

int app::height()
{
    return glut::screen_height;
}

float app::ratio()
{
    return (float)glut::screen_width / (float)glut::screen_height;
}

void app::set_initial_res(int, int) {
}

app::Callbacks::Callbacks() : exit_requested(false)
{
}

app::Callbacks::~Callbacks()
{
}

void app::Callbacks::run()
{
    glut::app_ptr = this;
    if (!init_glut) {
        init_glut = true;
        psp::StartMainThread();
    }
}

void app::Callbacks::init() {
}

void app::Callbacks::idle() {
}

void app::Callbacks::reshape(int, int) {
}

void app::Callbacks::display() {
}

bool app::Callbacks::exitRequested() const
{
    return exit_requested;
}

void app::Callbacks::exit()
{
    exit_requested = true;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glut_ReshapeFunc", _ZN3app11CheckMemoryEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_135B4");
void _GLOBAL__I__ZN4glut11ReshapeFuncEii(void);
void _GLOBAL__D__ZN4glut11ReshapeFuncEii(void);
}

void _GLOBAL__I__ZN4glut11ReshapeFuncEii(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN4glut11ReshapeFuncEii(void)
{
    static_init(0, 0xFFFF);
}
