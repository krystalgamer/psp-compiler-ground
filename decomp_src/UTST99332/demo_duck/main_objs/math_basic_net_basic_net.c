/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN4math9basic_netC2Ev");
#include "../../demo_duck/gl.hpp"

/* the object's .gnu.linkonce.t sections in the original's order (basic_net's inline destructor clones are asm) */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN6common9t_array2dIN4math11vector_xyzwEEC2Ev)
    DEMO_LINKONCE(_ZN6common9t_array2dIN4math11vector_xyzwEEC2Ejj)
    DEMO_LINKONCE(_ZN6common7t_arrayIN4math11vector_xyzwEE4addrEv)
    DEMO_LINKONCE(_ZNK6common9t_array2dIN4math11vector_xyzwEE2nxEv)
    DEMO_LINKONCE(_ZNK6common9t_array2dIN4math11vector_xyzwEE2nyEv)
    DEMO_LINKONCE(_ZNK6common7t_arrayIN4math11vector_xyzwEE4addrEv)
    DEMO_LINKONCE(_ZN6common7t_arrayIN4math11vector_xyzwEEC2Ev)
    DEMO_LINKONCE(_ZN6common7t_arrayIN4math11vector_xyzwEEC2Ej)
    DEMO_LINKONCE(_ZN6common7t_arrayIN4math11vector_xyzwEE8allocateEj)
    DEMO_LINKONCE(_ZN4math9basic_netD1Ev)
    DEMO_LINKONCE(_ZN4math9basic_netD0Ev)
    DEMO_LINKONCE(_ZN6common9t_array2dIN4math11vector_xyzwEED2Ev)
    DEMO_LINKONCE(_ZN6common9t_array2dIN4math11vector_xyzwEED1Ev)
    DEMO_LINKONCE(_ZN6common9t_array2dIN4math11vector_xyzwEED0Ev)
    DEMO_LINKONCE(_ZN6common7t_arrayIN4math11vector_xyzwEED2Ev)
    DEMO_LINKONCE(_ZN6common7t_arrayIN4math11vector_xyzwEED1Ev)
    DEMO_LINKONCE(_ZN6common7t_arrayIN4math11vector_xyzwEED0Ev)
    DEMO_LINKONCE(_ZN6common7t_arrayIN4math11vector_xyzwEE7releaseEv)
    DEMO_LINKONCE(_ZN6common7t_arrayIN4math11vector_xyzwEE4swapERS3_)
    DEMO_LINKONCE(_ZN6common9t_array2dIN4math11vector_xyzwEE7releaseEv)
    DEMO_LINKONCE(_ZN6common7t_arrayIN4math11vector_xyzwEE6resizeEj)
    DEMO_LINKONCE(_ZN6common7t_arrayIN4math11vector_xyzwEE4fillERKS2_)
    DEMO_LINKONCE(_ZN6common9t_array2dIN4math11vector_xyzwEE4swapERS3_)
    DEMO_LINKONCE(_ZN6common9t_array2dIN4math11vector_xyzwEE6resizeEjj)
    DEMO_LINKONCE(_ZN6common9t_array2dIN4math11vector_xyzwEE7resizexEj)
    DEMO_LINKONCE(_ZN6common9t_array2dIN4math11vector_xyzwEE7resizeyEj)
    DEMO_LINKONCE(_ZN6common9t_array2dIN4math11vector_xyzwEE4copyERKS3_iiiiii)
    DEMO_LINKONCE(_ZN6common4SwapINS_7t_arrayIN4math11vector_xyzwEE7MembersEEEvRT_S7_)
    DEMO_LINKONCE(_ZN6common4SwapINS_9t_array2dIN4math11vector_xyzwEE3DimEEEvRT_S7_)
    DEMO_LINKONCE(_ZN6common9t_array2dIN4math11vector_xyzwEE2atEii)
    DEMO_LINKONCE(_ZNK6common9t_array2dIN4math11vector_xyzwEE2atEii)
);

extern "C" void glVertex3fv(const GLfloat *);

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

CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN4math9basic_netD1Ev, _ZN4math9basic_netD1Ev)

CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_basic_net_basic_net", _ZN4math9basic_netD0Ev, _ZN4math9basic_netD0Ev)

/* used only by basic_net's destructor clones (asm) */
template common::t_array2d<math::vector_xyzw>::~t_array2d();
