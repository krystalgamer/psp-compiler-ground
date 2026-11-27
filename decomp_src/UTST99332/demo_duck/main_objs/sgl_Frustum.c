/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SGL_LINKONCE_Frustum 1
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Frustum", _Z41__static_initialization_and_destruction_0ii_A5C1C);

sgl::Frustum::Frustum()
{
}


INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Frustum", _ZN3sgl7FrustumC2Effffffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Frustum", _ZN3sgl7FrustumC1Effffffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Frustum", _ZN3sgl7FrustumC2Effffffffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Frustum", _ZN3sgl7FrustumC1Effffffffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Frustum", _ZN3sgl7Frustum6updateERKN4math6matrixES4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Frustum", _ZN3sgl7Frustum9intersectERNS_2BVE);

void sgl::Frustum::enable()
{
    _f8 = true;
}

void sgl::Frustum::disable()
{
    _f8 = false;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Frustum", _ZNK3sgl7Frustum5printEv);

float sgl::Frustum::getFov() const
{
    return _f24;
}

float sgl::Frustum::getZnear() const
{
    return _fC;
}

float sgl::Frustum::getZfar() const
{
    return _f10;
}

float sgl::Frustum::getZmin() const
{
    return _f14;
}

float sgl::Frustum::getZmax() const
{
    return _f18;
}

float sgl::Frustum::getWidth() const
{
    return _f1C;
}

float sgl::Frustum::getHeight() const
{
    return _f20;
}

float sgl::Frustum::getLeft() const
{
    return _f28;
}

float sgl::Frustum::getRight() const
{
    return _f2C;
}

float sgl::Frustum::getBottom() const
{
    return _f30;
}

float sgl::Frustum::getTop() const
{
    return _f34;
}

void sgl::Frustum::get(float &left, float &right, float &bottom, float &top, float &znear, float &zfar) const
{
    znear = _fC;
    zfar = _f10;
    left = _f28;
    right = _f2C;
    bottom = _f30;
    top = _f34;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Frustum", _ZN3sgl7Frustum6setFovEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Frustum", _ZN3sgl7Frustum10intersect1ERNS_2BVENS0_9PlaneEnumE);

void sgl::FindBestAlignedDiagonal(math::vector_xyzw n, Box::Vertex &a, Box::Vertex &b)
{
    int va = 0;
    int vb = 0;
    if (n.x > 0)
        vb = 4;
    else
        va = 4;
    if (n.y > 0)
        vb |= 2;
    else
        va |= 2;
    if (n.z > 0)
        vb |= 1;
    else
        va |= 1;
    a = Box::Vertex(va);
    b = Box::Vertex(vb);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_A5C1C");
void _GLOBAL__I__ZN3sgl7FrustumC2Ev(void);
void _GLOBAL__D__ZN3sgl7FrustumC2Ev(void);
}

void _GLOBAL__I__ZN3sgl7FrustumC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sgl7FrustumC2Ev(void)
{
    static_init(0, 0xFFFF);
}

/* the original's .gnu.linkonce.t order */
DEMO_LINKONCE_ORDER(DEMO_LINKONCE(_ZN3sgl7FrustumD0Ev)
                    DEMO_LINKONCE(_ZN3sgl7FrustumD1Ev));
