/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"


extern const float D_00163A10;      /* 1.0f: deleteLastRecord's identity rotation */
extern const float D_00163A14;      /* 1.0f: finishRecording's closing dt */

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _Z41__static_initialization_and_destruction_0ii_27A88);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp4Path14startRecordingEv);

void interp::Path::addRecord(math::Frame f)
{
    if (!_recording)
        return;
    _x.setKeyValue(_x.insert(_count), f.pos.x);
    _y.setKeyValue(_y.insert(_count), f.pos.y);
    _z.setKeyValue(_z.insert(_count), f.pos.z);
    _rot.setKeyValue(_rot.insert(_count), f.rot);
    _count++;
}

std::pair<bool, math::Frame> interp::Path::deleteLastRecord()
{
    if (_count == 0)
        return std::make_pair(false, math::Frame(math::vector_xyz(0, 0, 0), math::quaternion(0, 0, 0, D_00163A10)));
    _x.remove(_count - 1);
    _y.remove(_count - 1);
    _z.remove(_count - 1);
    _rot.remove(_count - 1);
    _count--;
    if (_count == 0)
        return std::make_pair(false, math::Frame(math::vector_xyz(0, 0, 0), math::quaternion(0, 0, 0, D_00163A10)));
    return std::make_pair(true, evaluate(_count - 1));
}

void interp::Path::finishRecording()
{
    if (!_recording)
        return;
    _recording = false;
    _x.setClose(true);
    _y.setClose(true);
    _z.setClose(true);
    _rot.setClose(true);
    const float dt = D_00163A14;
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp4Path4loadESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp4Path4saveESs);

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
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_27A88");
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfEC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE11setRelativeEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE8setCloseEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE10setCloseDtEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE11setRelativeEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE8setCloseEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setCloseDtEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE6insertEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE11setKeyValueEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE11setKeyValueEiS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE6removeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6removeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE6finishEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6finishEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE17getKeyAbsRelValueEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17getKeyAbsRelValueEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp16KeyFrameSequenceIfE8evaluateEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE30invalidate_cached_key_intervalEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE30invalidate_cached_key_intervalEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp8KeyFrameIfE12isClosingKeyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp8KeyFrameIN4math10quaternionEE12isClosingKeyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EEaSERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EEaSERKS6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIfE8setValueEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIN4math10quaternionEE8setValueES2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp8KeyFrameIfE5valueEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt13__destroy_auxIPN6interp8KeyFrameIfEEEvT_S4_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIfEC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIN4math10quaternionEEC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS4_S6_EESA_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEEPS4_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEEPS6_ET0_T_SF_SE_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS4_S6_EEjRKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", func_0002B4B4);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEESB_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIPN6interp8KeyFrameIfEES3_ET0_T_S5_S4_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt26__uninitialized_fill_n_auxIPN6interp8KeyFrameIfEEjS2_ET_S4_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIPN6interp8KeyFrameIN4math10quaternionEEES5_ET0_T_S7_S6_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt26__uninitialized_fill_n_auxIPN6interp8KeyFrameIN4math10quaternionEEEjS4_ET_S6_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEES7_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEEjS6_ET_SC_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp23VirtualKeyFrameSequenceD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp23VirtualKeyFrameSequenceD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp17KeyFrameSequenceAIfED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp17KeyFrameSequenceAIfED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE12makeRelativeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE12makeAbsoluteEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE16push_closing_keyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE16calc_all_tangentEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE18update_closing_keyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeRelativeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeAbsoluteEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16push_closing_keyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16calc_all_tangentEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18update_closing_keyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE6insertEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE16on_set_key_valueEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEfS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16on_set_key_valueEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE21get_key_abs_rel_valueEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21get_key_abs_rel_valueEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE14evaluate_setupEfRfS2_RPNS_8KeyFrameIfEES6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp8KeyFrameIfE4timeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIfEC1Effb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIfE7setTimeEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp8KeyFrameIN4math10quaternionEE5valueEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp8KeyFrameIN4math10quaternionEE4timeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIN4math10quaternionEEC1EfS2_b);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIN4math10quaternionEE7setTimeEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE21set_key_abs_rel_valueEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21set_key_abs_rel_valueEiS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE4sizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE17find_key_intervalEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS4_S6_EERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE5emptyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE18sizeLessClosingKeyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE5clearEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp16KeyFrameSequenceIfE4dumpEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE11getLastTimeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE10getKeyTimeEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE10setKeyTimeEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE12isClosingKeyEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE10getCloseDtEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE8isClosedEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE7setLoopEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE6isLoopEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE10isRelativeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE14setTangentTypeEiNS_16keyframe_tangent4TypeEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE14getTangentTypeEiNS_16keyframe_tangent4SideE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE14wrap_key_indexEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE18calc_tangent_setupEiRfS2_S2_S2_S2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp16KeyFrameSequenceIfE12calc_tangentEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp16KeyFrameSequenceIfE13calc_gradientEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp17KeyFrameSequenceAIfE2opEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp17KeyFrameSequenceAIfE6op_invEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp17KeyFrameSequenceAIfE11op_identityEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE10setDefaultEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE10getDefaultEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIfE10getKeyListEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfEixEj);

template<> void interp::KeyFrameSequence<float>::typed_fix() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE18makeConsistantWithEPKNS_23VirtualKeyFrameSequenceE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE5emptyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE4sizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE18sizeLessClosingKeyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE5clearEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE11getLastTimeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getKeyTimeEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setKeyTimeEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE12isClosingKeyEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getCloseDtEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE8isClosedEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE7setLoopEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE6isLoopEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10isRelativeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14setTangentTypeEiNS_16keyframe_tangent4TypeEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE14getTangentTypeEiNS_16keyframe_tangent4SideE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE14wrap_key_indexEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18calc_tangent_setupEiRS2_S4_S4_RfS5_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17find_key_intervalEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14evaluate_setupEfRfRS2_RPNS_8KeyFrameIS2_EES9_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setDefaultES2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getDefaultEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getKeyListEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEixEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18makeConsistantWithEPKNS_23VirtualKeyFrameSequenceE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIfE14setTangentTypeENS_16keyframe_tangent4TypeEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp8KeyFrameIfE14getTangentTypeENS_16keyframe_tangent4SideE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIN4math10quaternionEE14setTangentTypeENS_16keyframe_tangent4TypeEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp8KeyFrameIN4math10quaternionEE14getTangentTypeENS_16keyframe_tangent4SideE);

