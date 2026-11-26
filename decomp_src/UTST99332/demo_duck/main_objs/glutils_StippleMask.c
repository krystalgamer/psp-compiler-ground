/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

glutils::StippleMask::StippleMask()
{
    clear();
}


void glutils::StippleMask::clear()
{
    unsigned char *p = &_mask[0][0];
    for (unsigned int i = 0; i < ROWS; i++)
        for (unsigned int j = 0; j < ROW_BYTES; j++)
            *p++ = 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_StippleMask", _ZN7glutils11StippleMask8setPixelEjjb);

void *glutils::StippleMask::mask()
{
    return this;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_StippleMask", _ZN7glutils11StippleMask6sparseEhh);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_StippleMask", _ZN7glutils11StippleMask6sparseEh);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_StippleMask", _ZN7glutils11StippleMask7checkerEhh);

void glutils::StippleMask::checker(unsigned char c)
{
    checker(c, c);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_StippleMask", _ZN7glutils11StippleMask8diagonalEhb);
