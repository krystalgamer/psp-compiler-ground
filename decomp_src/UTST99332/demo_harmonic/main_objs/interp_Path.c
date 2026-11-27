/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const float D_00160F74;      /* 1.0f: finishRecording's closing dt */

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _Z41__static_initialization_and_destruction_0ii_2D160);

interp::Path::Path() : _count(0), _recording(false)
{
    _x.setRelative(false);
    _x.setClose(false);
    _x.setCloseDt(0);
    _y.setRelative(false);
    _y.setClose(false);
    _y.setCloseDt(0);
    _z.setRelative(false);
    _z.setClose(false);
    _z.setCloseDt(0);
    _rot.setRelative(false);
    _rot.setClose(false);
    _rot.setCloseDt(0);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp4Path14startRecordingEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp4Path9addRecordEN4math5FrameE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp4Path16deleteLastRecordEv);

void interp::Path::finishRecording()
{
    if (!_recording)
        return;
    _recording = false;
    _x.setClose(true);
    _y.setClose(true);
    _z.setClose(true);
    _rot.setClose(true);
    const float dt = D_00160F74;
    _x.setCloseDt(dt);
    _y.setCloseDt(dt);
    _z.setCloseDt(dt);
    _rot.setCloseDt(dt);
    _x.finish();
    _y.finish();
    _z.finish();
    _rot.finish();
}

bool interp::Path::isRecording() const
{
    return _recording;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp4Path4loadESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp4Path4saveESs);

math::Frame interp::Path::evaluate(float t)
{
    float s = t * _count;
    return math::Frame(math::vector_xyz(_x.evaluate(s), _y.evaluate(s), _z.evaluate(s)), _rot.evaluate(s));
}

int interp::Path::size() const
{
    return _count;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_2D160");
void _GLOBAL__I__ZN6interp4PathC2Ev(void);
void _GLOBAL__D__ZN6interp4PathC2Ev(void);
}

void _GLOBAL__I__ZN6interp4PathC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN6interp4PathC2Ev(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfEC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE11setKeyValueEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE11setKeyValueEiS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EEaSERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EEaSERKS6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZSt13__destroy_auxIPN6interp8KeyFrameIfEEEvT_S4_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEEPS4_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEEPS6_ET0_T_SF_SE_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp17KeyFrameSequenceAIfED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp17KeyFrameSequenceAIfED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp17KeyFrameSequenceAIfE2opEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp17KeyFrameSequenceAIfE6op_invEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZNK6interp17KeyFrameSequenceAIfE11op_identityEv);
