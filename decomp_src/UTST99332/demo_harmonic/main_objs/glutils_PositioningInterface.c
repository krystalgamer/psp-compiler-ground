/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_INTERP
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN7glutils20PositioningInterfaceC2Ev\n_GLOBAL__I__ZN7glutils20PositioningInterfaceC2Ev = _GLOBAL__I__ZN7glutils20PositioningInterfaceC2Ev__asm");
__asm__(".globl _GLOBAL__D__ZN7glutils20PositioningInterfaceC2Ev\n_GLOBAL__D__ZN7glutils20PositioningInterfaceC2Ev = _GLOBAL__D__ZN7glutils20PositioningInterfaceC2Ev__asm");

extern "C" const char D_001627D0[]; /* "\n" */
extern "C" const char D_001627E4[]; /* " " */

glutils::PositioningInterface::PositioningInterface()
    : _frame(math::vector_xyz(0, 0, 0), math::quaternion(0, 0, 0, 1))
{
}

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

/* the object's linkonce tail (thunks) in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZThn8_N7glutils20PositioningInterfaceD1Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils20PositioningInterfaceD0Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils20PositioningInterface3setEN4math5FrameE)
    DEMO_LINKONCE(_ZThn8_NK7glutils20PositioningInterface3getEv)
);

#undef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) INCLUDE_ASM_LINKONCE(FOLDER, NAME)

/* the object's weak tail (linkonce copies), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZThn8_N7glutils20PositioningInterfaceD1Ev);
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZThn8_N7glutils20PositioningInterfaceD0Ev);
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PositioningInterface", _ZThn8_N7glutils20PositioningInterface3setEN4math5FrameE);
