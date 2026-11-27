/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"
#include "../../demo_duck/gl.hpp"

extern "C" void glVertex3fv(const GLfloat *);


INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _Z41__static_initialization_and_destruction_0ii_4FBD8);

math::basic_net::basic_net()
{
}

math::basic_net::basic_net(unsigned int nx, unsigned int ny) : common::t_array2d<vector_xyzw>(nx, ny)
{
    float dx = 1.0f / (nx - 1);
    float dy = 1.0f / (ny - 1);
    for (unsigned int i = 0; i < nx; i++)
        for (unsigned int j = 0; j < ny; j++)
            addr()[i + j * nx] = vector_xyzw(dx * i - 0.5f, dy * j - 0.5f, 0, 1.0f);
}

void math::basic_net::draw() const
{
    int nx = this->nx();
    int ny = this->ny();
    if (ny < 2 || nx < 2)
        return;
    const vector_xyzw *a = addr();
    const vector_xyzw *b = a + nx;
    for (int j = 0; j < ny - 1; j++) {
        glBegin(5);
        for (int i = 0; i < nx; i++) {
            glVertex3fv(&a->x);
            glVertex3fv(&b->x);
            a++;
            b++;
        }
        glEnd();
    }
}

void math::basic_net::draw_w() const
{
    int nx = this->nx();
    int ny = this->ny();
    const vector_xyzw *p = addr();
    for (int j = 0; j < ny; j++) {
        glBegin(3);
        const vector_xyzw *q = p;
        for (int i = 0; i < nx; i++) {
            glVertex3fv(&q->x);
            q++;
        }
        glEnd();
        p += nx;
    }
    p = addr();
    for (int i = 0; i < nx; i++) {
        glBegin(3);
        const vector_xyzw *q = p;
        for (int j = 0; j < ny; j++) {
            glVertex3fv(&q->x);
            q += nx;
        }
        glEnd();
        p++;
    }
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_4FBD8");
void _GLOBAL__I__ZN4math9basic_netC2Ev(void);
}

void _GLOBAL__I__ZN4math9basic_netC2Ev(void)
{
    static_init(1, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common9t_array2dIN4math11vector_xyzwEEC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common9t_array2dIN4math11vector_xyzwEEC2Ejj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common7t_arrayIN4math11vector_xyzwEE4addrEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZNK6common9t_array2dIN4math11vector_xyzwEE2nxEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZNK6common9t_array2dIN4math11vector_xyzwEE2nyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZNK6common7t_arrayIN4math11vector_xyzwEE4addrEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common7t_arrayIN4math11vector_xyzwEEC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common7t_arrayIN4math11vector_xyzwEEC2Ej);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common7t_arrayIN4math11vector_xyzwEE8allocateEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN4math9basic_netD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN4math9basic_netD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common9t_array2dIN4math11vector_xyzwEED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common9t_array2dIN4math11vector_xyzwEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common9t_array2dIN4math11vector_xyzwEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common7t_arrayIN4math11vector_xyzwEED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common7t_arrayIN4math11vector_xyzwEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common7t_arrayIN4math11vector_xyzwEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common7t_arrayIN4math11vector_xyzwEE7releaseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common7t_arrayIN4math11vector_xyzwEE4swapERS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common9t_array2dIN4math11vector_xyzwEE7releaseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common7t_arrayIN4math11vector_xyzwEE6resizeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common7t_arrayIN4math11vector_xyzwEE4fillERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common9t_array2dIN4math11vector_xyzwEE4swapERS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common9t_array2dIN4math11vector_xyzwEE6resizeEjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common9t_array2dIN4math11vector_xyzwEE7resizexEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common9t_array2dIN4math11vector_xyzwEE7resizeyEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common9t_array2dIN4math11vector_xyzwEE4copyERKS3_iiiiii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common4SwapINS_7t_arrayIN4math11vector_xyzwEE7MembersEEEvRT_S7_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common4SwapINS_9t_array2dIN4math11vector_xyzwEE3DimEEEvRT_S7_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN6common9t_array2dIN4math11vector_xyzwEE2atEii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZNK6common9t_array2dIN4math11vector_xyzwEE2atEii);

