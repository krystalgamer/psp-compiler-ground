/* lang: c++ */
/* cflags: -O2 -frename-registers */
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _Z41__static_initialization_and_destruction_0ii_DC98);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _ZN4glut11ReshapeFuncEii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _ZN4glut11DisplayFuncEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _ZN4glut8IdleFuncEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _ZN3psp3padEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _ZN3psp10MainThreadEjPv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _ZN3psp15StartMainThreadEv);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _ZN3app9Callbacks3runEv);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _ZN3app11CheckMemoryEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _GLOBAL__I__ZN4glut11ReshapeFuncEii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _GLOBAL__D__ZN4glut11ReshapeFuncEii);
