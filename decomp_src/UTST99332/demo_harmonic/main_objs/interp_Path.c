/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_INTERP
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN6interp4PathC2Ev\n_GLOBAL__I__ZN6interp4PathC2Ev = _GLOBAL__I__Z21interp_Path_instancesv");
__asm__(".globl _GLOBAL__D__ZN6interp4PathC2Ev\n_GLOBAL__D__ZN6interp4PathC2Ev = _GLOBAL__D__Z21interp_Path_instancesv");
/* the KeyFrameSequence<float>::evaluate copy (asm) addresses this object's BEZIER_BASIS by its own label */
__asm__(".globl _ZN4math12BEZIER_BASISE_18ADDC\n_ZN4math12BEZIER_BASISE_18ADDC = _ZN4math12BEZIER_BASISE");

/* A template instance kept as asm: explicitly instantiated wrapper (its own code goes to a
   discarded section), so the instance's .gnu.linkonce.t section is created in pending-template
   order like cc1plus's own instances; LEN = strlen(NAME) + 2 (the wrapper's mangled name). */
#if defined(M2CTX) || defined(PERMUTER)
#define INST_INCLUDE_ASM(FOLDER, NAME, LEN)
#define INST2_INCLUDE_ASM(FOLDER, NAME, NAME2, LEN)
#else
#define INST_INCLUDE_ASM(FOLDER, NAME, LEN) \
    template<int> void NAME##_i() __attribute__((section(".discard.asmi"))); \
    template<int> void NAME##_i() \
    { \
        __asm__(".end _Z" #LEN #NAME "_iILi0EEvv\n" \
                ".section .gnu.linkonce.t." #NAME ",\"ax\",@progbits\n" \
                "    .set noat\n" \
                "    .set noreorder\n" \
                "    .include \"" FOLDER "/" #NAME ".s\"\n" \
                "    .set reorder\n" \
                "    .set at\n" \
                ".section .discard.asmi\n" \
                ".ent _Z" #LEN #NAME "_iILi0EEvv\n"); \
    } \
    template void NAME##_i<0>();
/* ... and one split in two by the disassembler (NAME2 is its tail) */
#define INST2_INCLUDE_ASM(FOLDER, NAME, NAME2, LEN) \
    template<int> void NAME##_i() __attribute__((section(".discard.asmi"))); \
    template<int> void NAME##_i() \
    { \
        __asm__(".end _Z" #LEN #NAME "_iILi0EEvv\n" \
                ".section .gnu.linkonce.t." #NAME ",\"ax\",@progbits\n" \
                "    .set noat\n" \
                "    .set noreorder\n" \
                "    .include \"" FOLDER "/" #NAME ".s\"\n" \
                "    .include \"" FOLDER "/" #NAME2 ".s\"\n" \
                "    .set reorder\n" \
                "    .set at\n" \
                ".section .discard.asmi\n" \
                ".ent _Z" #LEN #NAME "_iILi0EEvv\n"); \
    } \
    template void NAME##_i<0>();
#endif

/* the object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfEC2Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEC2Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE11setKeyValueEif)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE11setKeyValueEiS2_)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EEaSERKS4_)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EEaSERKS6_)
    DEMO_LINKONCE(_ZSt13__destroy_auxIPN6interp8KeyFrameIfEEEvT_S4_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEEPS4_ET0_T_SD_SC_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEEPS6_ET0_T_SF_SE_12__false_type)
    DEMO_LINKONCE(_ZN6interp17KeyFrameSequenceAIfED1Ev)
    DEMO_LINKONCE(_ZN6interp17KeyFrameSequenceAIfED0Ev)
    DEMO_LINKONCE(_ZN6interp17KeyFrameSequenceAIfE2opEff)
    DEMO_LINKONCE(_ZN6interp17KeyFrameSequenceAIfE6op_invEff)
    DEMO_LINKONCE(_ZNK6interp17KeyFrameSequenceAIfE11op_identityEv)
);

/* interp's assert (common/assert) */
#define INTERP_ASSERT(c, text, fn, line) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00161068, text, D_00161040, fn, line, D_00160FB4); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }
extern const char D_00160FB4[];     /* " " */
extern const char D_00161040[];     /* "../lib/interp/KeyFrameSequenceBase.h" */
extern const char D_00161068[];     /* " *** error " */
extern const char D_001611F4[];     /* "_Index >= 0 && _Index < (int) _keys.size()" */
extern const char PF_setKeyValue_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE11setKeyValueEifE19__PRETTY_FUNCTION___1611A8");
extern const char PF_setKeyValue_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE11setKeyValueEiS2_E19__PRETTY_FUNCTION__");

namespace interp {
template<class T> struct kfs_data;
template<> struct kfs_data<float> {
    static const char *setKeyValue() { return PF_setKeyValue_f; }
};
template<> struct kfs_data<math::quaternion> {
    static const char *setKeyValue() { return PF_setKeyValue_q; }
};
}

/* the instances this object holds (CityApp's object holds the others) */
template<class T> void interp::KeyFrameSequenceBase<T>::setKeyValue(int _Index, T v)
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_001611F4, kfs_data<T>::setKeyValue(), 274);
    _keys[_Index].setValue(v);
    on_set_key_value(_Index);
}

template<class T> inline interp::KeyFrameSequenceBase<T>::~KeyFrameSequenceBase()
{
}

template<class T> inline interp::KeyFrameSequence<T>::~KeyFrameSequence()
{
}

template<class T> inline interp::KeyFrameSequenceA<T>::~KeyFrameSequenceA()
{
}

template<class T> T interp::KeyFrameSequenceA<T>::op(T a, T b)
{
    return a + b;
}

template<class T> T interp::KeyFrameSequenceA<T>::op_inv(T a, T b)
{
    return a - b;
}

template<class T> T interp::KeyFrameSequenceA<T>::op_identity() const
{
    return 0;
}

typedef std::vector<interp::KeyFrame<float> > VKf;
typedef std::vector<interp::KeyFrame<math::quaternion> > VKq;
/* uses the instances this object holds from a function in a discarded section (implicit instantiations, as in the original) */
void interp_Path_instances() __attribute__((section(".discard.instances")));
void interp_Path_instances()
{
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setKeyValue(*(int *)0, *(float *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setKeyValue(*(int *)0, *(math::quaternion *)0);
    *(VKf *)0 = *(const VKf *)0;
    *(VKq *)0 = *(const VKq *)0;
    ((interp::KeyFrameSequenceA<float> *)0)->interp::KeyFrameSequenceA<float>::op(*(float *)0, *(float *)0);
    ((interp::KeyFrameSequenceA<float> *)0)->interp::KeyFrameSequenceA<float>::op_inv(*(float *)0, *(float *)0);
    ((const interp::KeyFrameSequenceA<float> *)0)->interp::KeyFrameSequenceA<float>::op_identity();
}

/* the object's template instances (.gnu.linkonce.t), explicitly instantiated in the original's order */
INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfEC2Ev, 41)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEC2Ev, 59)

 
 
INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/interp_Path", _ZSt13__destroy_auxIPN6interp8KeyFrameIfEEEvT_S4_12__false_type, 65)

 
 

extern const float D_00160F70;      /* 1.0f: deleteLastRecord's identity rotation */
extern const float D_00160F74;      /* 1.0f: finishRecording's closing dt */

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
        return std::make_pair(false, math::Frame(math::vector_xyz(0, 0, 0), math::quaternion(0, 0, 0, D_00160F70)));
    _x.remove(_count - 1);
    _y.remove(_count - 1);
    _z.remove(_count - 1);
    _rot.remove(_count - 1);
    _count--;
    if (_count == 0)
        return std::make_pair(false, math::Frame(math::vector_xyz(0, 0, 0), math::quaternion(0, 0, 0, D_00160F70)));
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
