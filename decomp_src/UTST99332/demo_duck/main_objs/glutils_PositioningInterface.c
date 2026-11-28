/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_INTERP
#define DEMO_TEMPLATE_DEFS
#define DEMO_LINKONCE_VirtualQuickAnim 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN7glutils20PositioningInterfaceC2Ev\n_GLOBAL__I__ZN7glutils20PositioningInterfaceC2Ev = _GLOBAL__I__ZN7glutils20PositioningInterfaceC2Ev__asm");
__asm__(".globl _GLOBAL__D__ZN7glutils20PositioningInterfaceC2Ev\n_GLOBAL__D__ZN7glutils20PositioningInterfaceC2Ev = _GLOBAL__D__ZN7glutils20PositioningInterfaceC2Ev__asm");

extern "C" const char D_00165540[]; /* "\n" */
extern "C" const char D_00165554[]; /* " " */

glutils::PositioningInterface::PositioningInterface()
    : _frame(math::vector_xyz(0, 0, 0), math::quaternion(0, 0, 0, 1))
{
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterfaceD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterfaceD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterfaceD0Ev);

const math::matrix &glutils::PositioningInterface::get_transform() const
{
    return _transform;
}

const math::matrix &glutils::PositioningInterface::get_inverse_transform() const
{
    return _inverse;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterface13set_transformEN4math6matrixE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterface21set_inverse_transformEN4math6matrixE);

void glutils::PositioningInterface::set_callback() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterface4saveESs);

void glutils::PositioningInterface::print(std::ostream &os)
{
    const math::vector_xyz &p = _frame.pos;
    const math::quaternion &q = _frame.rot;
    os << p.x << D_00165554;
    os << p.y << D_00165554;
    os << p.z << D_00165554;
    os << q.x << D_00165554;
    os << q.y << D_00165554;
    os << q.z << D_00165554;
    os << q.w << D_00165554;
    os.flush();
    os << D_00165540;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterface4loadESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PositioningInterface", _ZN7glutils20PositioningInterface3setEN4math5FrameE);

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

/* the object's linkonce tail (thunks, interp instances) in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZThn8_N7glutils20PositioningInterfaceD1Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils20PositioningInterfaceD0Ev)
    DEMO_LINKONCE(_ZThn8_N7glutils20PositioningInterface3setEN4math5FrameE)
    DEMO_LINKONCE(_ZThn8_NK7glutils20PositioningInterface3getEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfED2Ev)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE18startRecordingPathEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE9addRecordEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE16deleteLastRecordEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE19finishRecordingPathEv)
    DEMO_LINKONCE(_ZNK6interp16HasPathInterfaceINS_4PathEN4math5FrameEE15isRecordingPathEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8loadPathESs)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8savePathESs)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8evaluateEf)
    DEMO_LINKONCE(_ZNK6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8pathSizeEv)
    DEMO_LINKONCE(_ZN6interp16VirtualQuickAnimD1Ev)
    DEMO_LINKONCE(_ZN6interp16VirtualQuickAnimD0Ev)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEED1Ev)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEED0Ev)
    DEMO_LINKONCE(_ZN6interp16KeyFrameSequenceIfED1Ev)
    DEMO_LINKONCE(_ZN6interp16KeyFrameSequenceIfED0Ev)
);

#undef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) INCLUDE_ASM_LINKONCE(FOLDER, NAME)

/* not inline: the inline destructors call its D2 (instances of this object) */
template<class T> interp::KeyFrameSequenceBase<T>::~KeyFrameSequenceBase()
{
}

template<class T> inline interp::KeyFrameSequence<T>::~KeyFrameSequence()
{
}

template<class T> inline interp::KeyFrameSequenceA<T>::~KeyFrameSequenceA()
{
}

inline interp::KeyFrameSequence<math::quaternion>::~KeyFrameSequence()
{
}

/* interp instances this object holds: used from a discarded function (implicit instantiations) */
void glutils_PositioningInterface_instances() __attribute__((section(".discard.instances")));
void glutils_PositioningInterface_instances()
{
    typedef interp::HasPathInterface<interp::Path, math::Frame> HPf;
    ((HPf *)0)->HPf::startRecordingPath();
    ((HPf *)0)->HPf::addRecord();
    ((HPf *)0)->HPf::deleteLastRecord();
    ((HPf *)0)->HPf::finishRecordingPath();
    ((const HPf *)0)->HPf::isRecordingPath();
    ((HPf *)0)->HPf::loadPath(*(std::string *)0);
    ((HPf *)0)->HPf::savePath(*(std::string *)0);
    ((HPf *)0)->HPf::evaluate(0);
    ((const HPf *)0)->HPf::pathSize();
    ((HPf *)0)->HPf::~HasPathInterface();
    ((interp::KeyFrameSequence<float> *)0)->interp::KeyFrameSequence<float>::~KeyFrameSequence();
}

/* the object's weak tail (linkonce copies), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PositioningInterface", _ZThn8_N7glutils20PositioningInterfaceD1Ev);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PositioningInterface", _ZThn8_N7glutils20PositioningInterfaceD0Ev);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_PositioningInterface", _ZThn8_N7glutils20PositioningInterface3setEN4math5FrameE);
