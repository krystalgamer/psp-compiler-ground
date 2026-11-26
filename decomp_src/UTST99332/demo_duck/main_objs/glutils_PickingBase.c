/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PickingBase", _ZN7glutils11PickingBaseC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PickingBase", _ZN7glutils11PickingBaseC1Ev);

const void *glutils::PickingBase::getHits() const
{
    return &_f4;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PickingBase", _ZNSt6vectorIjSaIjEE7reserveEj);

