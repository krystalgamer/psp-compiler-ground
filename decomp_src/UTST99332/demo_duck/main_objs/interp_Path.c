/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define INTERP_LINKONCE_VKFS
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
/* the object's .gnu.linkonce.t sections in the original's order (also fixes where the library instances go) */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfEC2Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEC2Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE11setRelativeEb)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE8setCloseEb)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE10setCloseDtEf)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE11setRelativeEb)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE8setCloseEb)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setCloseDtEf)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE6insertEf)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE11setKeyValueEif)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEf)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE11setKeyValueEiS2_)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE6removeEj)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6removeEj)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE6finishEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6finishEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE17getKeyAbsRelValueEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17getKeyAbsRelValueEi)
    DEMO_LINKONCE(_ZN6interp16KeyFrameSequenceIfE8evaluateEf)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE30invalidate_cached_key_intervalEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE30invalidate_cached_key_intervalEv)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIfE12isClosingKeyEv)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIN4math10quaternionEE12isClosingKeyEv)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EEaSERKS4_)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EEaSERKS6_)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIfE8setValueEf)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIN4math10quaternionEE8setValueES2_)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIfE5valueEv)
    DEMO_LINKONCE(_ZSt13__destroy_auxIPN6interp8KeyFrameIfEEEvT_S4_12__false_type)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIfEC1Ev)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIN4math10quaternionEEC1Ev)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS4_S6_EESA_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEEPS4_ET0_T_SD_SC_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEEPS6_ET0_T_SF_SE_12__false_type)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS4_S6_EEjRKS4_)
    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEES4_EvT_SA_RKT0_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type)
    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEES6_EvT_SC_RKT0_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEESB_ET0_T_SD_SC_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN6interp8KeyFrameIfEES3_ET0_T_S5_S4_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN6interp8KeyFrameIfEEjS2_ET_S4_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN6interp8KeyFrameIN4math10quaternionEEES5_ET0_T_S7_S6_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN6interp8KeyFrameIN4math10quaternionEEEjS4_ET_S6_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEES7_ET0_T_SD_SC_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEEjS6_ET_SC_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZN6interp23VirtualKeyFrameSequenceD1Ev)
    DEMO_LINKONCE(_ZN6interp23VirtualKeyFrameSequenceD0Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED2Ev)
    DEMO_LINKONCE(_ZN6interp17KeyFrameSequenceAIfED1Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED1Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED0Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfED1Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfED0Ev)
    DEMO_LINKONCE(_ZN6interp17KeyFrameSequenceAIfED0Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE12makeRelativeEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE12makeAbsoluteEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE16push_closing_keyEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE16calc_all_tangentEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE18update_closing_keyEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeRelativeEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeAbsoluteEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16push_closing_keyEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16calc_all_tangentEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18update_closing_keyEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE6insertEff)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE16on_set_key_valueEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEfS2_)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16on_set_key_valueEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE21get_key_abs_rel_valueEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21get_key_abs_rel_valueEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE14evaluate_setupEfRfS2_RPNS_8KeyFrameIfEES6_)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIfE4timeEv)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIfEC1Effb)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIfE7setTimeEf)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIN4math10quaternionEE5valueEv)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIN4math10quaternionEE4timeEv)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIN4math10quaternionEEC1EfS2_b)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIN4math10quaternionEE7setTimeEf)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE21set_key_abs_rel_valueEif)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21set_key_abs_rel_valueEiS2_)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE4sizeEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE17find_key_intervalEf)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS4_S6_EERKS4_)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE5emptyEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE18sizeLessClosingKeyEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE5clearEv)
    DEMO_LINKONCE(_ZNK6interp16KeyFrameSequenceIfE4dumpEPKc)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE11getLastTimeEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE10getKeyTimeEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE10setKeyTimeEif)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE12isClosingKeyEi)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE10getCloseDtEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE8isClosedEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE7setLoopEb)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE6isLoopEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE10isRelativeEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE14setTangentTypeEiNS_16keyframe_tangent4TypeEi)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE14getTangentTypeEiNS_16keyframe_tangent4SideE)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE14wrap_key_indexEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE18calc_tangent_setupEiRfS2_S2_S2_S2_)
    DEMO_LINKONCE(_ZN6interp16KeyFrameSequenceIfE12calc_tangentEi)
    DEMO_LINKONCE(_ZNK6interp16KeyFrameSequenceIfE13calc_gradientEfff)
    DEMO_LINKONCE(_ZN6interp17KeyFrameSequenceAIfE2opEff)
    DEMO_LINKONCE(_ZN6interp17KeyFrameSequenceAIfE6op_invEff)
    DEMO_LINKONCE(_ZNK6interp17KeyFrameSequenceAIfE11op_identityEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE10setDefaultEf)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE10getDefaultEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE10getKeyListEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfEixEj)
    DEMO_LINKONCE(_ZN6interp16KeyFrameSequenceIfE9typed_fixEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE18makeConsistantWithEPKNS_23VirtualKeyFrameSequenceE)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE5emptyEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE4sizeEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE18sizeLessClosingKeyEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE5clearEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE11getLastTimeEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getKeyTimeEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setKeyTimeEif)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE12isClosingKeyEi)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getCloseDtEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE8isClosedEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE7setLoopEb)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE6isLoopEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10isRelativeEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14setTangentTypeEiNS_16keyframe_tangent4TypeEi)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE14getTangentTypeEiNS_16keyframe_tangent4SideE)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE14wrap_key_indexEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18calc_tangent_setupEiRS2_S4_S4_RfS5_)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17find_key_intervalEf)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14evaluate_setupEfRfRS2_RPNS_8KeyFrameIS2_EES9_)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setDefaultES2_)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getDefaultEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getKeyListEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEixEj)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18makeConsistantWithEPKNS_23VirtualKeyFrameSequenceE)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIfE14setTangentTypeENS_16keyframe_tangent4TypeEi)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIfE14getTangentTypeENS_16keyframe_tangent4SideE)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIN4math10quaternionEE14setTangentTypeENS_16keyframe_tangent4TypeEi)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIN4math10quaternionEE14getTangentTypeENS_16keyframe_tangent4SideE)
);

/* interp's assert (common/assert) */
#define INTERP_ASSERT(c, text, fn, line) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00163B08, text, D_00163AE0, fn, line, D_00163A54); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }
/* KeyFrameSequence.h's */
#define INTERP_ASSERT_KFS(c, text, fn, line) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00163B08, text, D_00163E20, fn, line, D_00163A54); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }
/* ... with a message */
#define INTERP_ASSERT_MSG(c, text, fn, line, msg) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00163B08, text, D_00163AE0, fn, line, msg); \
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
extern const char D_00163E90[];     /* "! _relative" */
extern const char D_00163EE4[];     /* "_relative" */
extern const char PF_makeRelative_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE12makeRelativeEvE19__PRETTY_FUNCTION___163E48");
extern const char PF_makeAbsolute_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE12makeAbsoluteEvE19__PRETTY_FUNCTION___163E9C");
extern const char PF_makeRelative_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeRelativeEvE19__PRETTY_FUNCTION___163FFC");
extern const char PF_makeAbsolute_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeAbsoluteEvE19__PRETTY_FUNCTION___164050");
extern const char PF_get_key_abs_rel_value_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE21get_key_abs_rel_valueEiE19__PRETTY_FUNCTION___1642F8");
extern const char PF_get_key_abs_rel_value_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21get_key_abs_rel_valueEiE19__PRETTY_FUNCTION___164350");
extern const char PF_update_closing_key_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE18update_closing_keyEvE19__PRETTY_FUNCTION___163FB0");
extern const char PF_update_closing_key_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18update_closing_keyEvE19__PRETTY_FUNCTION___1640FC");
extern const char PF_on_set_key_value_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE16on_set_key_valueEiE19__PRETTY_FUNCTION___1641F0");
extern const char PF_on_set_key_value_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16on_set_key_valueEiE19__PRETTY_FUNCTION___1642A0");
extern const char PF_set_key_abs_rel_value_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE21set_key_abs_rel_valueEifE19__PRETTY_FUNCTION___164458");
extern const char PF_set_key_abs_rel_value_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21set_key_abs_rel_valueEiS2_E19__PRETTY_FUNCTION___1644B0");
extern const char D_00163F3C[];     /* "keys.back() already a closing key" */
extern const char D_00163F60[];     /* "! _keys.empty()" */
extern const char D_00163F70[];     /* "trying to push a closing key in non closed animation" */
extern const char D_00163FA8[];     /* "_closed" */
extern const float D_00163A3C;      /* 1/3: KeyFrameSequence<float>::calc_tangent */
extern const char PF_push_closing_key_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE16push_closing_keyEvE19__PRETTY_FUNCTION___163EF0");
extern const char PF_push_closing_key_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16push_closing_keyEvE19__PRETTY_FUNCTION___1640A4");
extern const char D_00163D64[];     /* "_Index < _keys.size()" */
extern const char PF_remove_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE6removeEjE19__PRETTY_FUNCTION___163D18");
extern const char PF_remove_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6removeEjE19__PRETTY_FUNCTION___163D7C");
extern const float D_00163A48;      /* 1.0f: makeConsistantWith<quaternion> */
extern const char D_00163E1C[];     /* "k2" */
extern const char D_00163E20[];     /* "../lib/interp/KeyFrameSequence.h" */
extern const char D_00163E44[];     /* "k1" */
extern const char PF_kfs_evaluate_f[] __asm__("_ZZN6interp16KeyFrameSequenceIfE8evaluateEfE19__PRETTY_FUNCTION___163DD4");
/* this object's copy of the header static */
extern const math::matrix BEZIER_BASIS_18E25C __asm__("_ZN4math12BEZIER_BASISE_18E25C");
extern const float D_00163A34;      /* 1.0f: evaluate_setup<float> */
extern const float D_00163A44;      /* 1.0f: evaluate_setup<quaternion> */
extern const char D_00164438[];     /* "t >= 0.f && t <= 1.f" */
extern const char D_00164450[];     /* "k > 0" */
extern const char PF_evaluate_setup_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE14evaluate_setupEfRfS2_RPNS_8KeyFrameIfEES6_E19__PRETTY_FUNCTION___1643B0");
extern const char PF_evaluate_setup_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14evaluate_setupEfRfRS2_RPNS_8KeyFrameIS2_EES9_E19__PRETTY_FUNCTION___164D00");
extern const char D_00164560[];     /* "you probably forgot to reset _key_interval to 1 after an insert or remove, or setClose..." */
extern const char D_001645BC[];     /* "_key_interval > 0 && _key_interval < n" */
extern const char D_001645E4[];     /* "d > 0" */
extern const char D_001645EC[];     /* "_key_interval != 0" */
extern const char PF_find_key_interval_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE17find_key_intervalEfE19__PRETTY_FUNCTION___164510");
extern const char PF_find_key_interval_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17find_key_intervalEfE19__PRETTY_FUNCTION___164CA4");
extern const char D_001646B8[];     /* "_keys.back().time() > _keys[n-2].time()" */
extern const char D_001646E0[];     /* "_Time < _keys[_Index+1].time()" */
extern const char D_00164700[];     /* "_keys[_Index-1].time() < _Time" */
extern const char PF_setKeyTime_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE10setKeyTimeEifE19__PRETTY_FUNCTION___164668");
extern const char PF_setKeyTime_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setKeyTimeEifE19__PRETTY_FUNCTION___164A60");
extern const float D_00163A40;      /* 1.0f: calc_tangent_setup<quaternion> */
extern const char D_00164924[];     /* "count == 1 || count == 2" */
extern const char D_00164940[];     /* "dt != 0.f" */
extern const char D_00164950[];     /* "error in tangent setup" */
extern const char D_00164968[];     /* "i >= 0 && i < n" */
extern const char PF_calc_tangent_setup_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE18calc_tangent_setupEiRfS2_S2_S2_S2_E19__PRETTY_FUNCTION___1648B8");
extern const char PF_calc_tangent_setup_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18calc_tangent_setupEiRS2_S4_S4_RfS5_E19__PRETTY_FUNCTION___164C2C");
extern const char D_001641A8[];     /* "_keys.size() > 0" */
extern const char D_001641BC[];     /* "_keys.size() > 1" */
extern const char D_001641D0[];     /* " same key time already exist!\n" */
extern const char PF_insert_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE6insertEffE19__PRETTY_FUNCTION___16415C");
extern const char PF_insert_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEfS2_E19__PRETTY_FUNCTION___164248");
extern const char FN_insert_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE6insertEffE12__FUNCTION___164154");
extern const char FN_insert_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEfS2_E12__FUNCTION___164240");
typedef interp::KeyFrame<float> KFf;
typedef interp::KeyFrame<math::quaternion> KFq;
typedef std::vector<KFf> VKf;
typedef std::vector<KFq> VKq;

/* per-instance data of the template bodies below (the module's labels) */
namespace interp {
template<class T> struct kfs_data;
template<> struct kfs_data<float> {
    static float ins_value() { return 0; }
    static const char *insert() { return PF_insert_f; }
    static const char *insert_fn() { return FN_insert_f; }
    static float cts_one() { return 0; }
    static void cts_zero(float &x, float) { x = 0; }
    static const char *calc_tangent_setup() { return PF_calc_tangent_setup_f; }
    static const char *setKeyTime() { return PF_setKeyTime_f; }
    static const char *find_key_interval() { return PF_find_key_interval_f; }
    static float evaluate_setup_one() { return D_00163A34; }
    static const char *evaluate_setup() { return PF_evaluate_setup_f; }
    static const char *kfs_evaluate() { return PF_kfs_evaluate_f; }
    static float mcw_value() { return 0; }
    static const char *remove() { return PF_remove_f; }
    static const char *push_closing_key() { return PF_push_closing_key_f; }
    static const char *update_closing_key() { return PF_update_closing_key_f; }
    static const char *on_set_key_value() { return PF_on_set_key_value_f; }
    static const char *set_key_abs_rel_value() { return PF_set_key_abs_rel_value_f; }
    static const char *makeRelative() { return PF_makeRelative_f; }
    static const char *makeAbsolute() { return PF_makeAbsolute_f; }
    static const char *get_key_abs_rel_value() { return PF_get_key_abs_rel_value_f; }
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
    static const char *insert() { return PF_insert_q; }
    static const char *insert_fn() { return FN_insert_q; }
    static float cts_one() { return D_00163A40; }
    static void cts_zero(math::quaternion &x, float one) { x = math::quaternion(0, 0, 0, one); }
    static const char *calc_tangent_setup() { return PF_calc_tangent_setup_q; }
    static const char *setKeyTime() { return PF_setKeyTime_q; }
    static const char *find_key_interval() { return PF_find_key_interval_q; }
    static float evaluate_setup_one() { return D_00163A44; }
    static const char *evaluate_setup() { return PF_evaluate_setup_q; }
    static math::quaternion mcw_value() { return math::quaternion(0, 0, 0, D_00163A48); }
    static const char *remove() { return PF_remove_q; }
    static const char *push_closing_key() { return PF_push_closing_key_q; }
    static const char *update_closing_key() { return PF_update_closing_key_q; }
    static const char *on_set_key_value() { return PF_on_set_key_value_q; }
    static const char *set_key_abs_rel_value() { return PF_set_key_abs_rel_value_q; }
    static const char *makeRelative() { return PF_makeRelative_q; }
    static const char *makeAbsolute() { return PF_makeAbsolute_q; }
    static const char *get_key_abs_rel_value() { return PF_get_key_abs_rel_value_q; }
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

template<class T> inline interp::KeyFrameSequenceBase<T>::~KeyFrameSequenceBase()
{
}

template<class T> inline interp::KeyFrameSequence<T>::~KeyFrameSequence()
{
}

template<class T> inline interp::KeyFrameSequenceA<T>::~KeyFrameSequenceA()
{
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
    _key_interval = 1;
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

template<class T> void interp::KeyFrameSequenceBase<T>::makeRelative()
{
    INTERP_ASSERT(!_relative, D_00163E90, kfs_data<T>::makeRelative(), 1144);
    for (typename std::vector<KeyFrame<T> >::iterator it = _keys.begin(); it < _keys.end(); it++)
        it->setValue(op_inv(it->value(), _default));
    finish();
    _relative = true;
}

template<class T> void interp::KeyFrameSequenceBase<T>::makeAbsolute()
{
    INTERP_ASSERT(_relative, D_00163EE4, kfs_data<T>::makeAbsolute(), 1163);
    for (typename std::vector<KeyFrame<T> >::iterator it = _keys.begin(); it < _keys.end(); it++)
        it->setValue(op(_default, it->value()));
    finish();
    _relative = false;
}

template<class T> T interp::KeyFrameSequenceBase<T>::get_key_abs_rel_value(int _Index)
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_00163C94, kfs_data<T>::get_key_abs_rel_value(), 1184);
    T base = _relative ? _default : op_identity();
    return op(base, _keys[_Index].value());
}

template<class T> T interp::KeyFrameSequence<T>::calc_gradient(T a, T b, float dt) const
{
    return (b - a) / dt;
}

template<class T> void interp::KeyFrameSequenceBase<T>::update_closing_key()
{
    if (!_closed)
        return;
    unsigned int n = _keys.size();
    if (n < 2)
        return;
    INTERP_ASSERT(_keys.back().isClosingKey(), D_00163B84, kfs_data<T>::update_closing_key(), 365);
    _keys.back().setTime(_keys[n - 2].time() + _closeDt);
    _keys.back().setValue(_keys[0].value());
}

template<class T> void interp::KeyFrameSequenceBase<T>::on_set_key_value(int i)
{
    if (_closed && (int)_keys.size() > 1) {
        INTERP_ASSERT(_keys.back().isClosingKey(), D_00163B84, kfs_data<T>::on_set_key_value(), 386);
        if (_keys[i].isClosingKey())
            _keys[0].setValue(_keys[i].value());
    }
}

template<class T> void interp::KeyFrameSequenceBase<T>::set_key_abs_rel_value(int _Index, T v)
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_00163C94, kfs_data<T>::set_key_abs_rel_value(), 1196);
    KeyFrame<T> &k = _keys[_Index];
    k.setValue(op_inv(v, _relative ? _default : op_identity()));
}

template<class T> void interp::KeyFrameSequenceBase<T>::push_closing_key()
{
    INTERP_ASSERT_MSG(_closed, D_00163FA8, kfs_data<T>::push_closing_key(), 345, D_00163F70);
    INTERP_ASSERT(!_keys.empty(), D_00163F60, kfs_data<T>::push_closing_key(), 347);
    INTERP_ASSERT_MSG(!_keys.back().isClosingKey(), D_00163AC0, kfs_data<T>::push_closing_key(), 349, D_00163F3C);
    _keys.push_back(KeyFrame<T>(_keys.back().time() + _closeDt, _keys[0].value(), true));
}

template<class T> void interp::KeyFrameSequence<T>::calc_tangent(int i)
{
    T a, b, c;
    float s0, s1;
    if (this->calc_tangent_setup(i, a, b, c, s0, s1)) {
        KeyFrame<T> &k = this->_keys[i];
        T v = k.value();
        const float third = D_00163A3C;
        k._tangent[0] = v - c * s0 * third;
        k._tangent[1] = k.value() + c * s1 * third;
        if (k.getTangentType((keyframe_tangent::Side)1) == 1)
            k._tangent[0] = k.value() - b * s0 * third;
        if (k.getTangentType((keyframe_tangent::Side)2) == 1)
            k._tangent[1] = k.value() + a * s1 * third;
    }
}

template<class T> void interp::KeyFrameSequenceBase<T>::remove(unsigned int _Index)
{
    INTERP_ASSERT(_Index < _keys.size(), D_00163D64, kfs_data<T>::remove(), 617);
    if (_keys[_Index].isClosingKey())
        return;
    for (unsigned int i = _Index + 1; i < _keys.size(); i++)
        _keys[i - 1] = _keys[i];
    _keys.resize(_keys.size() - 1);
    if (_closed && _keys.size() == 1) {
        INTERP_ASSERT(_keys.back().isClosingKey(), D_00163B84, kfs_data<T>::remove(), 636);
        _keys.resize(0);
    }
    update_closing_key();
    calc_all_tangent();
    invalidate_cached_key_interval();
}

template<class T> void interp::KeyFrameSequenceBase<T>::makeConsistantWith(const VirtualKeyFrameSequence *s)
{
    _closed = s->isClosed();
    _closeDt = s->getCloseDt();
    invalidate_cached_key_interval();
    _loop = s->isLoop();
    _relative = s->isRelative();
    _keys.clear();
    int n = s->size();
    for (int i = 0; i != n; i++) {
        _keys.push_back(KeyFrame<T>(s->getKeyTime(i), kfs_data<T>::mcw_value(), i == n - 1 && _closed));
        _keys.back().setTangentType(s->getTangentType(i, (keyframe_tangent::Side)1), 1);
        _keys.back().setTangentType(s->getTangentType(i, (keyframe_tangent::Side)2), 2);
    }
}

template<class T> bool interp::KeyFrameSequenceBase<T>::evaluate_setup(float t, float &u, T &v, KeyFrame<T> *&k1, KeyFrame<T> *&k2)
{
    if (_keys.size() < 2) {
        if (_keys.empty())
            v = _default;
        else if (_keys.size() == 1)
            v = getKeyAbsRelValue(0);
        return false;
    }
    u = t;
    float t0 = _keys.front().time();
    float t1 = _keys.back().time();
    if (!_loop) {
        if (u < t0)
            u = t0;
        else if (t1 < u)
            u = t1;
    } else if (u < t0 || t1 < u)
        u = math::wrap(u, t0, t1 - t0);
    if (u == t0) {
        v = getKeyAbsRelValue(0);
        return false;
    }
    if (u == t1) {
        v = getKeyAbsRelValue(size() - 1);
        return false;
    }
    int k = find_key_interval(u);
    k2 = &_keys[k];
    if (u == k2->time()) {
        v = getKeyAbsRelValue(k);
        return false;
    }
    INTERP_ASSERT(k > 0, D_00164450, kfs_data<T>::evaluate_setup(), 1071);
    k1 = &_keys[k - 1];
    if (u == k1->time()) {
        v = getKeyAbsRelValue(k - 1);
        return false;
    }
    float dt = k2->time() - k1->time();
    u = (u - k1->time()) / dt;
    INTERP_ASSERT(u >= 0.f && u <= kfs_data<T>::evaluate_setup_one(), D_00164438, kfs_data<T>::evaluate_setup(), 1086);
    return true;
}

template<class T> void interp::KeyFrameSequenceBase<T>::setKeyTime(int _Index, float _Time)
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_00163C94, kfs_data<T>::setKeyTime(), 422);
    if (_Index > 0)
        INTERP_ASSERT(_keys[_Index - 1].time() < _Time, D_00164700, kfs_data<T>::setKeyTime(), 426);
    int n = _keys.size();
    if (_Index < n - 1 && !(_closed && _Index == n - 2))
        INTERP_ASSERT(_Time < _keys[_Index + 1].time(), D_001646E0, kfs_data<T>::setKeyTime(), 435);
    _keys[_Index].setTime(_Time);
    if (_closed && n >= 2) {
        INTERP_ASSERT(_keys.back().isClosingKey(), D_00163B84, kfs_data<T>::setKeyTime(), 445);
        if (_Index == n - 1) {
            INTERP_ASSERT(_keys.back().time() > _keys[n - 2].time(), D_001646B8, kfs_data<T>::setKeyTime(), 463);
            _closeDt = _keys.back().time() - _keys[n - 2].time();
        }
    }
    calc_all_tangent();
    invalidate_cached_key_interval();
}

template<class T> bool interp::KeyFrameSequenceBase<T>::calc_tangent_setup(int i, T &a, T &b, T &c, float &s0, float &s1)
{
    int n = _keys.size();
    INTERP_ASSERT(i >= 0 && i < n, D_00164968, kfs_data<T>::calc_tangent_setup(), 911);
    if (n < 2)
        return false;
    KeyFrame<T> *k0 = 0, *k1 = 0, *k2 = 0, *k3 = 0;
    if (i > 0 && i < n - 1) {
        k0 = &_keys[i - 1];
        k1 = &_keys[i];
        k2 = &_keys[i];
        k3 = &_keys[i + 1];
    } else if (i == 0) {
        k0 = &_keys[_closed ? n - 2 : 0];
        k1 = &_keys[_closed ? n - 1 : 0];
        k2 = &_keys[0];
        k3 = &_keys[1];
    } else if (i == n - 1) {
        k0 = &_keys[n - 2];
        k1 = &_keys[i];
        k2 = &_keys[_closed ? 0 : i];
        k3 = &_keys[_closed ? 1 : i];
    } else {
        common::common_internal::assert_display(D_00163B08, D_0016494C, D_00163AE0, kfs_data<T>::calc_tangent_setup(), 946, D_00164950);
        common::common_internal::on_error();
        common::common_internal::clash();
    }
    s0 = k1->time() - k0->time();
    s1 = k3->time() - k2->time();
    int count = 0;
    const float one = kfs_data<T>::cts_one();
    kfs_data<T>::cts_zero(b, one);
    if (s0 != 0) {
        b = calc_gradient(k0->value(), k1->value(), s0);
        count++;
    }
    kfs_data<T>::cts_zero(a, one);
    if (s1 != 0) {
        a = calc_gradient(k2->value(), k3->value(), s1);
        count++;
    }
    INTERP_ASSERT(count == 1 || count == 2, D_00164924, kfs_data<T>::calc_tangent_setup(), 976);
    float dt = s0 + s1;
    INTERP_ASSERT(dt != 0.f, D_00164940, kfs_data<T>::calc_tangent_setup(), 980);
    float w0 = s0 / dt;
    float w1 = s1 / dt;
    c = b * w0 + a * w1;
    return true;
}

template<class T> int interp::KeyFrameSequenceBase<T>::insert(float t, T v)
{
    int idx = -1;
    for (unsigned int i = 0; i < _keys.size(); i++) {
        if (_keys[i].isClosingKey())
            break;
        if (t == _keys[i].time()) {
            common::Log() << kfs_data<T>::insert_fn() << D_001641D0;
            return i;
        }
        if (t < _keys[i].time()) {
            idx = i;
            break;
        }
    }
    if (!_keys.empty() && _keys.back().isClosingKey())
        _keys.back() = KeyFrame<T>(t, kfs_data<T>::ins_value(), false);
    else
        _keys.push_back(KeyFrame<T>(t, kfs_data<T>::ins_value(), false));
    int n = _keys.size();
    set_key_abs_rel_value(n - 1, v);
    if (idx != -1) {
        for (int j = n - 2; j >= idx; j--) {
            KeyFrame<T> tmp = _keys[j];
            _keys[j] = _keys[j + 1];
            _keys[j + 1] = tmp;
        }
    }
    if (_closed)
        push_closing_key();
    calc_all_tangent();
    invalidate_cached_key_interval();
    if (idx != -1)
        return idx;
    if (!_closed) {
        INTERP_ASSERT(_keys.size() > 0, D_001641A8, kfs_data<T>::insert(), 598);
        return _keys.size() - 1;
    }
    INTERP_ASSERT(_keys.size() > 1, D_001641BC, kfs_data<T>::insert(), 607);
    return _keys.size() - 2;
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


/* Uses every instance this object holds, from a non-template function in a discarded section: the instances are then
   implicit instantiations, as in the original (an explicit instantiation would change how cc1plus inlines the library
   code they instantiate, e.g. __default_alloc_template<true,0>::allocate) */
void interp_Path_instances() __attribute__((section(".discard.instances")));
void interp_Path_instances()
{
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setRelative(*(bool *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setClose(*(bool *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setCloseDt(*(float *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setRelative(*(bool *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setClose(*(bool *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setCloseDt(*(float *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::insert(*(float *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setKeyValue(*(int *)0, *(float *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::insert(*(float *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::finish();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::finish();
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::getKeyAbsRelValue(*(int *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::getKeyAbsRelValue(*(int *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::invalidate_cached_key_interval();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::invalidate_cached_key_interval();
    ((const interp::KeyFrame<float> *)0)->interp::KeyFrame<float>::isClosingKey();
    ((const interp::KeyFrame<math::quaternion> *)0)->interp::KeyFrame<math::quaternion>::isClosingKey();
    ((interp::KeyFrame<float> *)0)->interp::KeyFrame<float>::setValue(*(float *)0);
    ((interp::KeyFrame<math::quaternion> *)0)->interp::KeyFrame<math::quaternion>::setValue(*(math::quaternion *)0);
    ((const interp::KeyFrame<float> *)0)->interp::KeyFrame<float>::value();
    new ((void *)0) interp::KeyFrame<float>();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setKeyValue(*(int *)0, *(math::quaternion *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::evaluate_setup(*(float *)0, *(float *)0, *(float *)0, *(interp::KeyFrame<float> * *)0, *(interp::KeyFrame<float> * *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::evaluate_setup(*(float *)0, *(float *)0, *(math::quaternion *)0, *(interp::KeyFrame<math::quaternion> * *)0, *(interp::KeyFrame<math::quaternion> * *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setKeyTime(*(int *)0, *(float *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setKeyTime(*(int *)0, *(float *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::calc_tangent_setup(*(int *)0, *(float *)0, *(float *)0, *(float *)0, *(float *)0, *(float *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::calc_tangent_setup(*(int *)0, *(math::quaternion *)0, *(math::quaternion *)0, *(math::quaternion *)0, *(float *)0, *(float *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::insert(*(float *)0, *(float *)0);
    ((interp::KeyFrameSequenceA<float> *)0)->interp::KeyFrameSequenceA<float>::op(*(float *)0, *(float *)0);
    ((interp::KeyFrameSequenceA<float> *)0)->interp::KeyFrameSequenceA<float>::op_inv(*(float *)0, *(float *)0);
    ((const interp::KeyFrameSequenceA<float> *)0)->interp::KeyFrameSequenceA<float>::op_identity();
    ((const interp::KeyFrame<float> *)0)->interp::KeyFrame<float>::time();
    new ((void *)0) interp::KeyFrame<float>(*(float *)0, *(float *)0, *(bool *)0);
    ((interp::KeyFrame<float> *)0)->interp::KeyFrame<float>::setTime(*(float *)0);
    ((const interp::KeyFrame<math::quaternion> *)0)->interp::KeyFrame<math::quaternion>::value();
    ((const interp::KeyFrame<math::quaternion> *)0)->interp::KeyFrame<math::quaternion>::time();
    ((interp::KeyFrame<math::quaternion> *)0)->interp::KeyFrame<math::quaternion>::setTime(*(float *)0);
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::size();
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::empty();
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::sizeLessClosingKey();
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::clear();
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::getLastTime();
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::getKeyTime(*(int *)0);
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::isClosingKey(*(int *)0);
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::getCloseDt();
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::isClosed();
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setLoop(*(bool *)0);
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::isLoop();
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::isRelative();
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setTangentType(*(int *)0, *(interp::keyframe_tangent::Type *)0, *(int *)0);
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::getTangentType(*(int *)0, *(interp::keyframe_tangent::Side *)0);
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::wrap_key_index(*(int *)0);
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::size();
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::empty();
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::sizeLessClosingKey();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::clear();
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::getLastTime();
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::getKeyTime(*(int *)0);
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::isClosingKey(*(int *)0);
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::getCloseDt();
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::isClosed();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setLoop(*(bool *)0);
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::isLoop();
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::isRelative();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setTangentType(*(int *)0, *(interp::keyframe_tangent::Type *)0, *(int *)0);
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::getTangentType(*(int *)0, *(interp::keyframe_tangent::Side *)0);
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::wrap_key_index(*(int *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::calc_all_tangent();
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setDefault(*(float *)0);
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::getDefault();
    ((const interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::getKeyList();
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::operator[](*(unsigned int *)0);
    ((interp::KeyFrame<float> *)0)->interp::KeyFrame<float>::setTangentType(*(interp::keyframe_tangent::Type *)0, *(int *)0);
    ((const interp::KeyFrame<float> *)0)->interp::KeyFrame<float>::getTangentType(*(interp::keyframe_tangent::Side *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::calc_all_tangent();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setDefault(*(math::quaternion *)0);
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::getDefault();
    ((const interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::getKeyList();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::operator[](*(unsigned int *)0);
    ((interp::KeyFrame<math::quaternion> *)0)->interp::KeyFrame<math::quaternion>::setTangentType(*(interp::keyframe_tangent::Type *)0, *(int *)0);
    ((const interp::KeyFrame<math::quaternion> *)0)->interp::KeyFrame<math::quaternion>::getTangentType(*(interp::keyframe_tangent::Side *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::makeRelative();
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::makeAbsolute();
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::get_key_abs_rel_value(*(int *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::makeRelative();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::makeAbsolute();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::get_key_abs_rel_value(*(int *)0);
    ((const interp::KeyFrameSequence<float> *)0)->interp::KeyFrameSequence<float>::calc_gradient(*(float *)0, *(float *)0, *(float *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::update_closing_key();
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::on_set_key_value(*(int *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::set_key_abs_rel_value(*(int *)0, *(float *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::update_closing_key();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::on_set_key_value(*(int *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::set_key_abs_rel_value(*(int *)0, *(math::quaternion *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::push_closing_key();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::push_closing_key();
    ((interp::KeyFrameSequence<float> *)0)->interp::KeyFrameSequence<float>::calc_tangent(*(int *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::remove(*(unsigned int *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::remove(*(unsigned int *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::makeConsistantWith((const interp::VirtualKeyFrameSequence *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::makeConsistantWith((const interp::VirtualKeyFrameSequence *)0);
    *(VKf *)0 = *(const VKf *)0;
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::~KeyFrameSequenceBase();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::~KeyFrameSequenceBase();
    *(VKq *)0 = *(const VKq *)0;
}

/* still asm */
template<> int interp::KeyFrameSequenceBase<math::quaternion>::insert(float, math::quaternion);
template<> interp::KeyFrame<math::quaternion>::KeyFrame();
template<> interp::KeyFrame<math::quaternion>::KeyFrame(float, math::quaternion, bool);
/* END template bodies */

/* the object's template instances (.gnu.linkonce.t), explicitly instantiated in the original's order */
INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfEC2Ev, 41)

INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEC2Ev, 59)

































INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp16KeyFrameSequenceIfE8evaluateEf, 44)



















INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZSt13__destroy_auxIPN6interp8KeyFrameIfEEEvT_S4_12__false_type, 65)



INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIN4math10quaternionEEC1Ev, 46)












#if 0 /* (for splat) */
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", func_0002B4B4);
#endif























INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED2Ev, 59)





































INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEfS2_, 67)



















INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp8KeyFrameIN4math10quaternionEEC1EfS2_b, 50)









INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIfE17find_key_intervalEf, 58)











INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZNK6interp16KeyFrameSequenceIfE4dumpEPKc, 43)













































template<class T> void interp::KeyFrameSequence<T>::typed_fix()
{
}
template void interp::KeyFrameSequence<float>::typed_fix();





































INST_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/interp_Path", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17find_key_intervalEf, 76)





















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
