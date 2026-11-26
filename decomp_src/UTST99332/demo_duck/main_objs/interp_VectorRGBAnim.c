/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_VectorRGBAnim", _Z41__static_initialization_and_destruction_0ii_F5D78);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_VectorRGBAnim", _ZN6interp13VectorRGBAnimC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_VectorRGBAnim", _ZN6interp13VectorRGBAnimC1Ev);

bool interp::VectorRGBAnim::isRecording() const
{
    return _f1B4;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_VectorRGBAnim", _ZN6interp13VectorRGBAnim14startRecordingEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_VectorRGBAnim", _ZN6interp13VectorRGBAnim9addRecordEN2sh9VectorRGBE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_VectorRGBAnim", _ZN6interp13VectorRGBAnim16deleteLastRecordEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_VectorRGBAnim", _ZN6interp13VectorRGBAnim12insertRecordEN2sh9VectorRGBEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_VectorRGBAnim", _ZN6interp13VectorRGBAnim15finishRecordingEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_VectorRGBAnim", _ZN6interp13VectorRGBAnim8evaluateEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_VectorRGBAnim", _ZN6interp13VectorRGBAnim4loadESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_VectorRGBAnim", _ZN6interp13VectorRGBAnim4saveESs);

int interp::VectorRGBAnim::size() const
{
    return _f1B0;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_F5D78");
void _GLOBAL__I__ZN6interp13VectorRGBAnimC2Ev(void);
void _GLOBAL__D__ZN6interp13VectorRGBAnimC2Ev(void);
}

void _GLOBAL__I__ZN6interp13VectorRGBAnimC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN6interp13VectorRGBAnimC2Ev(void)
{
    static_init(0, 0xFFFF);
}

