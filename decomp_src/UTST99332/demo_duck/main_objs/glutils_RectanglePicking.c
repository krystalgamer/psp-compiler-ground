/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* weak instances stay asm */
extern template class std::vector<unsigned int>;

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_RectanglePicking", _Z41__static_initialization_and_destruction_0ii_34578);

glutils::RectanglePicking::RectanglePicking() : _f30(false), _f31(true)
{
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_RectanglePicking", _ZN7glutils16RectanglePicking8setStartEN4math9vector_xyE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_RectanglePicking", _ZN7glutils16RectanglePicking10setCurrentEN4math9vector_xyE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_RectanglePicking", _ZNK7glutils16RectanglePicking8getStartEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_RectanglePicking", _ZNK7glutils16RectanglePicking10getCurrentEv);

void glutils::RectanglePicking::push_back(unsigned int name)
{
    _hits.push_back(name);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_RectanglePicking", _ZN7glutils16RectanglePicking8activateEv);

void glutils::RectanglePicking::resize(unsigned int n)
{
    _hits.resize(n);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_34578");
void _GLOBAL__I__ZN7glutils16RectanglePickingC2Ev(void);
void _GLOBAL__D__ZN7glutils16RectanglePickingC2Ev(void);
}

void _GLOBAL__I__ZN7glutils16RectanglePickingC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN7glutils16RectanglePickingC2Ev(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_RectanglePicking", _ZN7glutils16RectanglePickingD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_RectanglePicking", _ZN7glutils16RectanglePickingD0Ev);

