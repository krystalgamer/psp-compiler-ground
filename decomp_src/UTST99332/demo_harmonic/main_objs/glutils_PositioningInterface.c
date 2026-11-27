/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" const char D_001627D0[]; /* "\n" */
extern "C" const char D_001627E4[]; /* " " */

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _Z41__static_initialization_and_destruction_0ii_306E8);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterfaceC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterfaceC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterfaceD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterfaceD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterfaceD0Ev);

const math::matrix &glutils::PositioningInterface::get_transform() const
{
    return _transform;
}

const math::matrix &glutils::PositioningInterface::get_inverse_transform() const
{
    return _inverse;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterface13set_transformEN4math6matrixE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterface21set_inverse_transformEN4math6matrixE);

void glutils::PositioningInterface::set_callback() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterface4saveESs);

void glutils::PositioningInterface::print(std::ostream &os)
{
    const math::vector_xyz &p = _frame.pos;
    const math::quaternion &q = _frame.rot;
    os << p.x << D_001627E4;
    os << p.y << D_001627E4;
    os << p.z << D_001627E4;
    os << q.x << D_001627E4;
    os << q.y << D_001627E4;
    os << q.z << D_001627E4;
    os << q.w << D_001627E4;
    os.flush();
    os << D_001627D0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterface4loadESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterface3setEN4math5FrameE);

math::Frame glutils::PositioningInterface::get() const
{
    return _frame;
}

const math::matrix &glutils::PositioningInterface::getTransformInverse() const
{
    return _inverse;
}

const math::matrix &glutils::PositioningInterface::getTransform() const
{
    return _transform;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_306E8");
void _GLOBAL__I__ZN7glutils20PositioningInterfaceC2Ev(void);
void _GLOBAL__D__ZN7glutils20PositioningInterfaceC2Ev(void);
}

void _GLOBAL__I__ZN7glutils20PositioningInterfaceC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN7glutils20PositioningInterfaceC2Ev(void)
{
    static_init(0, 0xFFFF);
}

/* the object's linkonce tail (thunks) in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZThn8_N7glutils20PositioningInterfaceD1Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils20PositioningInterfaceD0Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils20PositioningInterface3setEN4math5FrameE)
    DEMO_LINKONCE(_ZThn8_NK7glutils20PositioningInterface3getEv)
);

#undef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) INCLUDE_ASM_LINKONCE(FOLDER, NAME)

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZThn8_N7glutils20PositioningInterfaceD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZThn8_N7glutils20PositioningInterfaceD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZThn8_N7glutils20PositioningInterface3setEN4math5FrameE);
