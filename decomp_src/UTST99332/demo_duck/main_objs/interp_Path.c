/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

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

/* BEGIN template bodies */
/* interp's assert (common/assert) */
#define INTERP_ASSERT(c, text, fn, line) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00163B08, text, D_00163AE0, fn, line, D_00163A54); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }
extern const char D_00163A54[];     /* " " */
extern const char D_00163AE0[];     /* "../lib/interp/KeyFrameSequenceBase.h" */
extern const char D_00163B08[];     /* " *** error " */
extern const char D_00163AC0[];     /* "! _keys.back().isClosingKey()" */
extern const char D_00163B60[];     /* "_keys.empty() || _keys.size() > 1" */
extern const char D_00163B84[];     /* "_keys.back().isClosingKey()" */
extern const char D_00163C94[];     /* "_Index >= 0 && _Index < (int) _keys.size()" */
extern const float D_00163A1C;      /* 0.2f: KeyFrameSequenceBase<float>() */
extern const float D_00163A20;      /* 1.0f: KeyFrameSequenceBase<quaternion>() */
extern const float D_00163A24;      /* 0.2f */
extern const char PF_setClose_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE8setCloseEbE19__PRETTY_FUNCTION___163A78");
extern const char PF_setCloseDt_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE10setCloseDtEfE19__PRETTY_FUNCTION___163B14");
extern const char PF_setClose_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE8setCloseEbE19__PRETTY_FUNCTION___163BA0");
extern const char PF_setCloseDt_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setCloseDtEfE19__PRETTY_FUNCTION___163BF4");
extern const char PF_setKeyValue_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE11setKeyValueEiS2_E19__PRETTY_FUNCTION__");
extern const char PF_setKeyValue_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE11setKeyValueEifE19__PRETTY_FUNCTION___163C48");

extern const char D_00164770[];     /* "_Index >= 0 && _Index < (int)_keys.size()" */
extern const char D_0016479C[];     /* "! ( ( ! _closed ) && retval )" */
extern const char PF_getKeyTime_f[] __asm__("_ZZNK6interp20KeyFrameSequenceBaseIfE10getKeyTimeEiE19__PRETTY_FUNCTION___164618");
extern const char PF_getKeyTime_q[] __asm__("_ZZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getKeyTimeEiE19__PRETTY_FUNCTION___164A04");
extern const char PF_isClosingKey_f[] __asm__("_ZZNK6interp20KeyFrameSequenceBaseIfE12isClosingKeyEiE19__PRETTY_FUNCTION___164720");
extern const char PF_isClosingKey_q[] __asm__("_ZZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE12isClosingKeyEiE19__PRETTY_FUNCTION___164ABC");
extern const char PF_setTangentType_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE14setTangentTypeEiNS_16keyframe_tangent4TypeEiE19__PRETTY_FUNCTION___1647BC");
extern const char PF_setTangentType_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14setTangentTypeEiNS_16keyframe_tangent4TypeEiE19__PRETTY_FUNCTION___164B18");
extern const char PF_getTangentType_f[] __asm__("_ZZNK6interp20KeyFrameSequenceBaseIfE14getTangentTypeEiNS_16keyframe_tangent4SideEE19__PRETTY_FUNCTION___16482C");
extern const char PF_getTangentType_q[] __asm__("_ZZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE14getTangentTypeEiNS_16keyframe_tangent4SideEE19__PRETTY_FUNCTION___164B94");
extern const char D_001649E0[];     /* "_Index >=0 && _Index < _keys.size()" */
extern const char D_0016494C[];     /* "" */
extern const char D_00164E84[];     /* "../lib/interp/KeyFrame.h" */
extern const char D_00164EA0[];     /* "bad tangent" */
extern const char PF_index_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfEixEjE19__PRETTY_FUNCTION___164978");
extern const char PF_index_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEixEjE19__PRETTY_FUNCTION___164D94");
extern const char PF_kf_getTangentType_f[] __asm__("_ZZNK6interp8KeyFrameIfE14getTangentTypeENS_16keyframe_tangent4SideEE19__PRETTY_FUNCTION___164E08");
extern const char PF_kf_getTangentType_q[] __asm__("_ZZNK6interp8KeyFrameIN4math10quaternionEE14getTangentTypeENS_16keyframe_tangent4SideEE19__PRETTY_FUNCTION___164EAC");
typedef interp::KeyFrame<float> KFf;
typedef interp::KeyFrame<math::quaternion> KFq;
typedef std::vector<KFf> VKf;
typedef std::vector<KFq> VKq;

/* per-instance data of the template bodies below (the module's labels) */
namespace interp {
template<class T> struct kfs_data;
template<> struct kfs_data<float> {
    static const char *index() { return PF_index_f; }
    static const char *kf_getTangentType() { return PF_kf_getTangentType_f; }
    static const char *getKeyTime() { return PF_getKeyTime_f; }
    static const char *isClosingKey() { return PF_isClosingKey_f; }
    static const char *setTangentType() { return PF_setTangentType_f; }
    static const char *getTangentType() { return PF_getTangentType_f; }
    static float default_value() { return 0; }
    static float close_dt() { return D_00163A1C; }
    static const char *setClose() { return PF_setClose_f; }
    static const char *setCloseDt() { return PF_setCloseDt_f; }
    static const char *setKeyValue() { return PF_setKeyValue_f; }
};
template<> struct kfs_data<math::quaternion> {
    static const char *index() { return PF_index_q; }
    static const char *kf_getTangentType() { return PF_kf_getTangentType_q; }
    static const char *getKeyTime() { return PF_getKeyTime_q; }
    static const char *isClosingKey() { return PF_isClosingKey_q; }
    static const char *setTangentType() { return PF_setTangentType_q; }
    static const char *getTangentType() { return PF_getTangentType_q; }
    static math::quaternion default_value() { return math::quaternion(0, 0, 0, D_00163A20); }
    static float close_dt() { return D_00163A24; }
    static const char *setClose() { return PF_setClose_q; }
    static const char *setCloseDt() { return PF_setCloseDt_q; }
    static const char *setKeyValue() { return PF_setKeyValue_q; }
};
}

template<class T> interp::KeyFrame<T>::KeyFrame() : _time(0), _value(0)
{
    _type[0] = (keyframe_tangent::Type)0;
    _type[1] = (keyframe_tangent::Type)0;
    _closing = false;
    _tangent[0] = 0;
    _tangent[1] = 0;
}

template<class T> bool interp::KeyFrame<T>::isClosingKey() const
{
    return _closing;
}

template<class T> T interp::KeyFrame<T>::value() const
{
    return _value;
}

template<class T> void interp::KeyFrame<T>::setValue(T v)
{
    _value = v;
}

template<class T> void interp::KeyFrameSequenceBase<T>::setRelative(bool r)
{
    if (r)
        makeRelative();
    else
        makeAbsolute();
}

template<class T> void interp::KeyFrameSequenceBase<T>::setClose(bool c)
{
    if (_closed == c)
        return;
    _closed = c;
    if (!_keys.empty()) {
        if (!c) {
            if (_keys.back().isClosingKey())
                _keys.resize(_keys.size() - 1);
        } else {
            INTERP_ASSERT(!_keys.back().isClosingKey(), D_00163AC0, kfs_data<T>::setClose(), 705);
            push_closing_key();
        }
    }
    calc_all_tangent();
    invalidate_cached_key_interval();
}

template<class T> void interp::KeyFrameSequenceBase<T>::setCloseDt(float dt)
{
    _closeDt = dt;
    if (_closed) {
        INTERP_ASSERT(_keys.empty() || _keys.size() > 1, D_00163B60, kfs_data<T>::setCloseDt(), 670);
        if (!_keys.empty()) {
            INTERP_ASSERT(_keys.back().isClosingKey(), D_00163B84, kfs_data<T>::setCloseDt(), 674);
            update_closing_key();
            calc_all_tangent();
            invalidate_cached_key_interval();
        }
    }
}

template<class T> int interp::KeyFrameSequenceBase<T>::insert(float t)
{
    T d = _default;
    _default = op_identity();
    int i = insert(t, evaluate(t));
    _default = d;
    return i;
}

template<class T> void interp::KeyFrameSequenceBase<T>::setKeyValue(int _Index, T v)
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_00163C94, kfs_data<T>::setKeyValue(), 274);
    _keys[_Index].setValue(v);
    on_set_key_value(_Index);
}

template<class T> void interp::KeyFrameSequenceBase<T>::finish()
{
    update_closing_key();
    typed_fix();
    calc_all_tangent();
    invalidate_cached_key_interval();
}

template<class T> T interp::KeyFrameSequenceBase<T>::getKeyAbsRelValue(int i)
{
    return get_key_abs_rel_value(i);
}

template<class T> void interp::KeyFrameSequenceBase<T>::invalidate_cached_key_interval()
{
    _cached = 1;
}

template<class T> float interp::KeyFrame<T>::time() const
{
    return _time;
}

template<class T> void interp::KeyFrame<T>::setTime(float t)
{
    _time = t;
}

template<class T> interp::KeyFrame<T>::KeyFrame(float t, T v, bool c) : _time(t), _value(v), _closing(c)
{
    _type[0] = (keyframe_tangent::Type)0;
    _type[1] = (keyframe_tangent::Type)0;
    _tangent[0] = 0;
    _tangent[1] = 0;
}

template<class T> int interp::KeyFrameSequenceBase<T>::size() const
{
    return _keys.size();
}

template<class T> bool interp::KeyFrameSequenceBase<T>::empty() const
{
    return _keys.empty();
}

template<class T> int interp::KeyFrameSequenceBase<T>::sizeLessClosingKey() const
{
    if (_keys.size() > 1 && _keys.back().isClosingKey())
        return _keys.size() - 1;
    return _keys.size();
}

template<class T> void interp::KeyFrameSequenceBase<T>::clear()
{
    _keys.clear();
}

template<class T> float interp::KeyFrameSequenceBase<T>::getLastTime() const
{
    if (empty())
        return 0;
    return _keys[size() - 1].time();
}

template<class T> float interp::KeyFrameSequenceBase<T>::getKeyTime(int _Index) const
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_00163C94, kfs_data<T>::getKeyTime(), 409);
    return _keys[_Index].time();
}

template<class T> bool interp::KeyFrameSequenceBase<T>::isClosingKey(int _Index) const
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_00164770, kfs_data<T>::isClosingKey(), 480);
    bool retval = _keys[_Index].isClosingKey();
    INTERP_ASSERT(!((!_closed) && retval), D_0016479C, kfs_data<T>::isClosingKey(), 484);
    return retval;
}

template<class T> float interp::KeyFrameSequenceBase<T>::getCloseDt() const
{
    return _closeDt;
}

template<class T> bool interp::KeyFrameSequenceBase<T>::isClosed() const
{
    return _closed;
}

template<class T> void interp::KeyFrameSequenceBase<T>::setLoop(bool l)
{
    _loop = l;
}

template<class T> bool interp::KeyFrameSequenceBase<T>::isLoop() const
{
    return _loop;
}

template<class T> bool interp::KeyFrameSequenceBase<T>::isRelative() const
{
    return _relative;
}

template<class T> void interp::KeyFrameSequenceBase<T>::setTangentType(int _Index, keyframe_tangent::Type t, int side)
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_00163C94, kfs_data<T>::setTangentType(), 1095);
    _keys[_Index].setTangentType(t, side);
}

template<class T> interp::keyframe_tangent::Type interp::KeyFrameSequenceBase<T>::getTangentType(int _Index, keyframe_tangent::Side s) const
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_00163C94, kfs_data<T>::getTangentType(), 1104);
    return _keys[_Index].getTangentType(s);
}

template<class T> int interp::KeyFrameSequenceBase<T>::wrap_key_index(int i) const
{
    int n = _keys.size();
    if (n == 0)
        return -1;
    if (i < 0) {
        int k = -i - 1;
        return n - 1 - (k - n * (k / n));
    }
    if (i > n - 1)
        return i - n * (i / n);
    return i;
}

template<class T> void interp::KeyFrame<T>::setTangentType(keyframe_tangent::Type t, int side)
{
    if (side & 1)
        _type[0] = t;
    if (side & 2)
        _type[1] = t;
}

template<class T> interp::keyframe_tangent::Type interp::KeyFrame<T>::getTangentType(keyframe_tangent::Side s) const
{
    if (s == 1)
        return _type[0];
    else if (s == 2)
        return _type[1];
    common::common_internal::assert_display(D_00163B08, D_0016494C, D_00164E84, kfs_data<T>::kf_getTangentType(), 127, D_00164EA0);
        common::common_internal::on_error();
        common::common_internal::clash();
    return (keyframe_tangent::Type)0;
}

template<class T> void interp::KeyFrameSequenceBase<T>::calc_all_tangent()
{
    for (int i = 0; i < (int)_keys.size(); i++)
        calc_tangent(i);
}

template<class T> void interp::KeyFrameSequenceBase<T>::setDefault(T v)
{
    _default = v;
}

template<class T> T interp::KeyFrameSequenceBase<T>::getDefault() const
{
    return _default;
}

template<class T> const std::vector<interp::KeyFrame<T> > &interp::KeyFrameSequenceBase<T>::getKeyList() const
{
    return _keys;
}

template<class T> interp::KeyFrame<T> &interp::KeyFrameSequenceBase<T>::operator[](unsigned int _Index)
{
    INTERP_ASSERT(_Index < _keys.size(), D_001649E0, kfs_data<T>::index(), 655);
    return _keys[_Index];
}

/* still asm */
template<> interp::KeyFrame<math::quaternion>::KeyFrame();
template<> interp::KeyFrame<math::quaternion>::KeyFrame(float, math::quaternion, bool);
extern template VKf &VKf::operator=(const VKf &);
extern template VKq &VKq::operator=(const VKq &);
extern template VKf::iterator VKf::erase(VKf::iterator, VKf::iterator);
extern template VKq::iterator VKq::erase(VKq::iterator, VKq::iterator);
extern template KFf *std::__uninitialized_copy_aux<VKf::const_iterator, KFf *>(VKf::const_iterator, VKf::const_iterator, KFf *, __false_type);
extern template KFq *std::__uninitialized_copy_aux<VKq::const_iterator, KFq *>(VKq::const_iterator, VKq::const_iterator, KFq *, __false_type);
extern template void VKf::_M_fill_insert(VKf::iterator, VKf::size_type, const KFf &);
extern template void VKq::_M_fill_insert(VKq::iterator, VKq::size_type, const KFq &);
extern template void std::fill<VKf::iterator, KFf>(VKf::iterator, VKf::iterator, const KFf &);
extern template VKf::iterator std::__uninitialized_copy_aux<VKf::iterator, VKf::iterator>(VKf::iterator, VKf::iterator, VKf::iterator, __false_type);
extern template void std::fill<VKq::iterator, KFq>(VKq::iterator, VKq::iterator, const KFq &);
extern template VKq::iterator std::__uninitialized_copy_aux<VKq::iterator, VKq::iterator>(VKq::iterator, VKq::iterator, VKq::iterator, __false_type);
extern template KFf *std::__uninitialized_copy_aux<KFf *, KFf *>(KFf *, KFf *, KFf *, __false_type);
extern template KFf *std::__uninitialized_fill_n_aux<KFf *, unsigned int, KFf>(KFf *, unsigned int, const KFf &, __false_type);
extern template KFf *std::__uninitialized_copy_aux<VKf::iterator, KFf *>(VKf::iterator, VKf::iterator, KFf *, __false_type);
extern template VKf::iterator std::__uninitialized_fill_n_aux<VKf::iterator, unsigned int, KFf>(VKf::iterator, unsigned int, const KFf &, __false_type);
extern template KFq *std::__uninitialized_copy_aux<KFq *, KFq *>(KFq *, KFq *, KFq *, __false_type);
extern template KFq *std::__uninitialized_fill_n_aux<KFq *, unsigned int, KFq>(KFq *, unsigned int, const KFq &, __false_type);
extern template KFq *std::__uninitialized_copy_aux<VKq::iterator, KFq *>(VKq::iterator, VKq::iterator, KFq *, __false_type);
extern template VKq::iterator std::__uninitialized_fill_n_aux<VKq::iterator, unsigned int, KFq>(VKq::iterator, unsigned int, const KFq &, __false_type);
extern template void VKf::_M_insert_aux(VKf::iterator, const KFf &);
extern template void VKq::_M_insert_aux(VKq::iterator, const KFq &);
/* END template bodies */

/* the object's template instances (.gnu.linkonce.t), explicitly instantiated in the original's order */
INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfEC2Ev, 41)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEC2Ev, 59)

template void interp::KeyFrameSequenceBase<float>::setRelative(bool);

template void interp::KeyFrameSequenceBase<float>::setClose(bool);

template void interp::KeyFrameSequenceBase<float>::setCloseDt(float);

template void interp::KeyFrameSequenceBase<math::quaternion>::setRelative(bool);

template void interp::KeyFrameSequenceBase<math::quaternion>::setClose(bool);

template void interp::KeyFrameSequenceBase<math::quaternion>::setCloseDt(float);

template int interp::KeyFrameSequenceBase<float>::insert(float);

template void interp::KeyFrameSequenceBase<float>::setKeyValue(int, float);

template int interp::KeyFrameSequenceBase<math::quaternion>::insert(float);

template void interp::KeyFrameSequenceBase<math::quaternion>::setKeyValue(int, math::quaternion);

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE6removeEj, 46)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6removeEj, 64)

template void interp::KeyFrameSequenceBase<float>::finish();

template void interp::KeyFrameSequenceBase<math::quaternion>::finish();

template float interp::KeyFrameSequenceBase<float>::getKeyAbsRelValue(int);

template math::quaternion interp::KeyFrameSequenceBase<math::quaternion>::getKeyAbsRelValue(int);

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp16KeyFrameSequenceIfE8evaluateEf, 44)

template void interp::KeyFrameSequenceBase<float>::invalidate_cached_key_interval();

template void interp::KeyFrameSequenceBase<math::quaternion>::invalidate_cached_key_interval();

template bool interp::KeyFrame<float>::isClosingKey() const;

template bool interp::KeyFrame<math::quaternion>::isClosingKey() const;

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EEaSERKS4_, 52)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EEaSERKS6_, 70)

template void interp::KeyFrame<float>::setValue(float);

template void interp::KeyFrame<math::quaternion>::setValue(math::quaternion);

template float interp::KeyFrame<float>::value() const;

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt13__destroy_auxIPN6interp8KeyFrameIfEEEvT_S4_12__false_type, 65)

template interp::KeyFrame<float>::KeyFrame();

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIN4math10quaternionEEC1Ev, 46)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_, 94)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS4_S6_EESA_, 112)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEEPS4_ET0_T_SD_SC_12__false_type, 140)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEEPS6_ET0_T_SF_SE_12__false_type, 158)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_, 107)

INST2_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS4_S6_EEjRKS4_, func_0002B4B4, 125)
#if 0 /* (for splat) */
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", func_0002B4B4);
#endif

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEESB_ET0_T_SD_SC_12__false_type, 156)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIPN6interp8KeyFrameIfEES3_ET0_T_S5_S4_12__false_type, 84)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt26__uninitialized_fill_n_auxIPN6interp8KeyFrameIfEEjS2_ET_S4_T0_RKT1_12__false_type, 89)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type, 138)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type, 143)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIPN6interp8KeyFrameIN4math10quaternionEEES5_ET0_T_S7_S6_12__false_type, 102)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt26__uninitialized_fill_n_auxIPN6interp8KeyFrameIN4math10quaternionEEEjS4_ET_S6_T0_RKT1_12__false_type, 107)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEES7_ET0_T_SD_SC_12__false_type, 156)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEEjS6_ET_SC_T0_RKT1_12__false_type, 161)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp23VirtualKeyFrameSequenceD1Ev, 41)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp23VirtualKeyFrameSequenceD0Ev, 41)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED2Ev, 59)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp17KeyFrameSequenceAIfED1Ev, 38)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED1Ev, 59)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED0Ev, 59)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfED1Ev, 41)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfED0Ev, 41)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp17KeyFrameSequenceAIfED0Ev, 38)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE12makeRelativeEv, 53)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE12makeAbsoluteEv, 53)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE16push_closing_keyEv, 57)

template void interp::KeyFrameSequenceBase<float>::calc_all_tangent();

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE18update_closing_keyEv, 59)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeRelativeEv, 71)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeAbsoluteEv, 71)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16push_closing_keyEv, 75)

template void interp::KeyFrameSequenceBase<math::quaternion>::calc_all_tangent();

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18update_closing_keyEv, 77)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE6insertEff, 47)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE16on_set_key_valueEi, 57)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEfS2_, 67)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16on_set_key_valueEi, 75)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE21get_key_abs_rel_valueEi, 62)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21get_key_abs_rel_valueEi, 80)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE14evaluate_setupEfRfS2_RPNS_8KeyFrameIfEES6_, 81)

template float interp::KeyFrame<float>::time() const;

template interp::KeyFrame<float>::KeyFrame(float, float, bool);

template void interp::KeyFrame<float>::setTime(float);

template math::quaternion interp::KeyFrame<math::quaternion>::value() const;

template float interp::KeyFrame<math::quaternion>::time() const;

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIN4math10quaternionEEC1EfS2_b, 50)

template void interp::KeyFrame<math::quaternion>::setTime(float);

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE21set_key_abs_rel_valueEif, 63)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21set_key_abs_rel_valueEiS2_, 83)

template int interp::KeyFrameSequenceBase<float>::size() const;

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE17find_key_intervalEf, 58)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_, 105)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS4_S6_EERKS4_, 123)

template bool interp::KeyFrameSequenceBase<float>::empty() const;

template int interp::KeyFrameSequenceBase<float>::sizeLessClosingKey() const;

template void interp::KeyFrameSequenceBase<float>::clear();

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp16KeyFrameSequenceIfE4dumpEPKc, 43)

template float interp::KeyFrameSequenceBase<float>::getLastTime() const;

template float interp::KeyFrameSequenceBase<float>::getKeyTime(int) const;

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE10setKeyTimeEif, 52)

template bool interp::KeyFrameSequenceBase<float>::isClosingKey(int) const;

template float interp::KeyFrameSequenceBase<float>::getCloseDt() const;

template bool interp::KeyFrameSequenceBase<float>::isClosed() const;

template void interp::KeyFrameSequenceBase<float>::setLoop(bool);

template bool interp::KeyFrameSequenceBase<float>::isLoop() const;

template bool interp::KeyFrameSequenceBase<float>::isRelative() const;

template void interp::KeyFrameSequenceBase<float>::setTangentType(int, interp::keyframe_tangent::Type, int);

template interp::keyframe_tangent::Type interp::KeyFrameSequenceBase<float>::getTangentType(int, interp::keyframe_tangent::Side) const;

template int interp::KeyFrameSequenceBase<float>::wrap_key_index(int) const;

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE18calc_tangent_setupEiRfS2_S2_S2_S2_, 73)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp16KeyFrameSequenceIfE12calc_tangentEi, 49)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp16KeyFrameSequenceIfE13calc_gradientEfff, 53)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp17KeyFrameSequenceAIfE2opEff, 40)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp17KeyFrameSequenceAIfE6op_invEff, 44)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp17KeyFrameSequenceAIfE11op_identityEv, 50)

template void interp::KeyFrameSequenceBase<float>::setDefault(float);

template float interp::KeyFrameSequenceBase<float>::getDefault() const;

template const std::vector<interp::KeyFrame<float> > &interp::KeyFrameSequenceBase<float>::getKeyList() const;

template interp::KeyFrame<float> &interp::KeyFrameSequenceBase<float>::operator[](unsigned int);

template<class T> void interp::KeyFrameSequence<T>::typed_fix()
{
}
template void interp::KeyFrameSequence<float>::typed_fix();

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE18makeConsistantWithEPKNS_23VirtualKeyFrameSequenceE, 89)

template bool interp::KeyFrameSequenceBase<math::quaternion>::empty() const;

template int interp::KeyFrameSequenceBase<math::quaternion>::size() const;

template int interp::KeyFrameSequenceBase<math::quaternion>::sizeLessClosingKey() const;

template void interp::KeyFrameSequenceBase<math::quaternion>::clear();

template float interp::KeyFrameSequenceBase<math::quaternion>::getLastTime() const;

template float interp::KeyFrameSequenceBase<math::quaternion>::getKeyTime(int) const;

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setKeyTimeEif, 70)

template bool interp::KeyFrameSequenceBase<math::quaternion>::isClosingKey(int) const;

template float interp::KeyFrameSequenceBase<math::quaternion>::getCloseDt() const;

template bool interp::KeyFrameSequenceBase<math::quaternion>::isClosed() const;

template void interp::KeyFrameSequenceBase<math::quaternion>::setLoop(bool);

template bool interp::KeyFrameSequenceBase<math::quaternion>::isLoop() const;

template bool interp::KeyFrameSequenceBase<math::quaternion>::isRelative() const;

template void interp::KeyFrameSequenceBase<math::quaternion>::setTangentType(int, interp::keyframe_tangent::Type, int);

template interp::keyframe_tangent::Type interp::KeyFrameSequenceBase<math::quaternion>::getTangentType(int, interp::keyframe_tangent::Side) const;

template int interp::KeyFrameSequenceBase<math::quaternion>::wrap_key_index(int) const;

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18calc_tangent_setupEiRS2_S4_S4_RfS5_, 92)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17find_key_intervalEf, 76)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14evaluate_setupEfRfRS2_RPNS_8KeyFrameIS2_EES9_, 102)

template void interp::KeyFrameSequenceBase<math::quaternion>::setDefault(math::quaternion);

template math::quaternion interp::KeyFrameSequenceBase<math::quaternion>::getDefault() const;

template const std::vector<interp::KeyFrame<math::quaternion> > &interp::KeyFrameSequenceBase<math::quaternion>::getKeyList() const;

template interp::KeyFrame<math::quaternion> &interp::KeyFrameSequenceBase<math::quaternion>::operator[](unsigned int);

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18makeConsistantWithEPKNS_23VirtualKeyFrameSequenceE, 107)

template void interp::KeyFrame<float>::setTangentType(interp::keyframe_tangent::Type, int);

template interp::keyframe_tangent::Type interp::KeyFrame<float>::getTangentType(interp::keyframe_tangent::Side) const;

template void interp::KeyFrame<math::quaternion>::setTangentType(interp::keyframe_tangent::Type, int);

template interp::keyframe_tangent::Type interp::KeyFrame<math::quaternion>::getTangentType(interp::keyframe_tangent::Side) const;

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
