/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN3sgl3BoxC2Ev\n_GLOBAL__I__ZN3sgl3BoxC2Ev = _GLOBAL__I__ZN3sgl3BoxC2Ev__asm");
__asm__(".globl _GLOBAL__D__ZN3sgl3BoxC2Ev\n_GLOBAL__D__ZN3sgl3BoxC2Ev = _GLOBAL__D__ZN3sgl3BoxC2Ev__asm");

#include "UTST99332/demo_duck/gl.hpp"
extern const float D_0016DB9C;      /* 1.0f */
extern const float D_0016DBA0;      /* 1.0f */
extern const char D_0016DBCC[];     /* "_Value.w() == 1.f" */
extern const char D_0016DBE0[];     /* "../lib/sgl/Box.cpp" */
extern const char D_0016DBF4[];     /* " " */
extern const char D_0016DBF8[];     /* " *** error " */
extern const char first_name[] __asm__("_ZZN3sgl3Box5firstEN4math11vector_xyzwEE19__PRETTY_FUNCTION__");
#define BOX_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016DBF8, text, D_0016DBE0, fn, line, D_0016DBF4)

sgl::Box::Box()
{
    first(math::vector_xyzw::Origin());
}

sgl::Box::Box(math::vector_xyzw a, math::vector_xyzw b)
{
    first(a);
    add(b);
    finish();
}

void sgl::Box::first(math::vector_xyzw p)
{
    BOX_ASSERT(p.w == 1.0f, D_0016DBCC, first_name, 46);
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

void sgl::Box::draw() const
{
    glPushAttrib(0x2000);
    glDisable(0xB50);
    glDisable(0xDE1);
    glBegin(3);
    glVertex3fv(&_c[0].x);
    glVertex3fv(&_c[1].x);
    glVertex3fv(&_c[3].x);
    glVertex3fv(&_c[7].x);
    glVertex3fv(&_c[5].x);
    glVertex3fv(&_c[1].x);
    glVertex3fv(&_c[5].x);
    glVertex3fv(&_c[4].x);
    glVertex3fv(&_c[6].x);
    glVertex3fv(&_c[7].x);
    glVertex3fv(&_c[6].x);
    glVertex3fv(&_c[2].x);
    glVertex3fv(&_c[3].x);
    glVertex3fv(&_c[2].x);
    glVertex3fv(&_c[0].x);
    glVertex3fv(&_c[4].x);
    glVertex3fv(&_c[0].x);
    glEnd();
    glPopAttrib();
}
