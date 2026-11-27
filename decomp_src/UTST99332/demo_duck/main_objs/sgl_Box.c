/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

#include "UTST99332/demo_duck/gl.hpp"
extern const float D_0016DB94;      /* 1.0f */
extern const float D_0016DB9C;      /* 1.0f */
extern const float D_0016DBA0;      /* 1.0f */
extern const char D_0016DBCC[];     /* "_Value.w() == 1.f" */
extern const char D_0016DBE0[];     /* "../lib/sgl/Box.cpp" */
extern const char D_0016DBF4[];     /* " " */
extern const char D_0016DBF8[];     /* " *** error " */
extern const char first_name[] __asm__("_ZZN3sgl3Box5firstEN4math11vector_xyzwEE19__PRETTY_FUNCTION__");
#define BOX_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016DBF8, text, D_0016DBE0, fn, line, D_0016DBF4)

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Box", _Z41__static_initialization_and_destruction_0ii_A5028);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Box", _ZN3sgl3BoxC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Box", _ZN3sgl3BoxC1Ev);

sgl::Box::Box(math::vector_xyzw a, math::vector_xyzw b)
{
    first(a);
    add(b);
    finish();
}


void sgl::Box::first(math::vector_xyzw p)
{
    BOX_ASSERT(p.w == D_0016DB94, D_0016DBCC, first_name, 46);
    _c[0] = p;
    _c[7] = p;
    finish();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Box", _ZN3sgl3Box3addEN4math11vector_xyzwE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Box", _ZN3sgl3Box6finishEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Box", _ZNK3sgl3Box6volumeEv);

void sgl::Box::draw(int c) const
{
    if (c == 0)
        glColor3f(D_0016DBA0, 0, 0);
    else if (c == 1)
        glColor3f(0, D_0016DBA0, 0);
    else
        glColor3f(0, 0, D_0016DBA0);
    draw();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Box", _ZNK3sgl3Box4drawEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_A5028");
void _GLOBAL__I__ZN3sgl3BoxC2Ev(void);
void _GLOBAL__D__ZN3sgl3BoxC2Ev(void);
}

void _GLOBAL__I__ZN3sgl3BoxC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sgl3BoxC2Ev(void)
{
    static_init(0, 0xFFFF);
}

