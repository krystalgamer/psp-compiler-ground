/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
/* Identity()'s 1.0f stays in the module's .rodata (asm) */
extern const float D_0015B668;
#define MATH_IDENTITY_ONE D_0015B668
#define DEMO_TEMPLATE_DEFS
#include "main.hpp"

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN6common6handleIN5scene4NodeEE10invalidateEv)
    DEMO_LINKONCE(_ZN6common6handleIN5scene5GroupEE10invalidateEv)
    DEMO_LINKONCE(_ZN6common6handleIN5scene6ObjectEE10invalidateEv)
    DEMO_LINKONCE(_ZN6common6handleIN5scene7TextureEE10invalidateEv)
    DEMO_LINKONCE(_ZN6common6handleIN5scene9TransformEE10invalidateEv)
    DEMO_LINKONCE(_ZNSt6vectorIN6common7CmdLine6OptionESaIS2_EE9push_backERKS2_)
    DEMO_LINKONCE(_ZN6common6handleIN7CityApp3CarEE10invalidateEv)
    DEMO_LINKONCE(_ZN5scene5Graph7newNodeINS_9TransformEEEN6common6handleIT_EESsb)
    DEMO_LINKONCE(_ZN6common6handleIN5scene9TransformEEaSERKS3_)
    DEMO_LINKONCE(_ZNKSt15basic_stringbufIcSt11char_traitsIcESaIcEE3strEv)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils20PositioningInterfaceEE10invalidateEv)
    DEMO_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_7TextureEEEN6common6handleIT_EERKSs)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils9TurnTableEE10invalidateEv)
    DEMO_LINKONCE(_ZNSt6vectorIN6common7CmdLine6OptionESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfED2Ev)
    DEMO_LINKONCE(_ZNSt6vectorIN6common6handleIN7CityApp3CarEEESaIS4_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS4_S6_EERKS4_)
    DEMO_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_9TransformEEEN6common6handleIT_EERKSs)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE17_M_stringbuf_initESt13_Ios_Openmode)
    DEMO_LINKONCE(_ZN6common6handleIN7CityApp3CarEEaSERKS3_)
    DEMO_LINKONCE(_ZNSsC1IPcEET_S1_RKSaIcE)
    DEMO_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ESt4lessIS0_ESaIS7_EE4findERS0_)
    DEMO_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ENS2_7LessStrESaIS7_EE4findERS0_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common7CmdLine6OptionESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common6handleIN7CityApp3CarEEESt6vectorIS6_SaIS6_EEEESB_ET0_T_SD_SC_12__false_type)
    DEMO_LINKONCE(_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag)
    DEMO_LINKONCE(_ZN6interp23VirtualKeyFrameSequenceD1Ev)
    DEMO_LINKONCE(_ZN6interp23VirtualKeyFrameSequenceD0Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED2Ev)
    DEMO_LINKONCE(_ZN6interp16VirtualQuickAnimD1Ev)
    DEMO_LINKONCE(_ZN6interp16VirtualQuickAnimD0Ev)
    DEMO_LINKONCE(_ZN6common15handle_internal10data_ownerD1Ev)
    DEMO_LINKONCE(_ZN6common15handle_internal10data_ownerD0Ev)
    DEMO_LINKONCE(_ZN6common15handle_internal10data_owner8set_dataEPNS0_4dataE)
    DEMO_LINKONCE(_ZN6common18shared_object_baseD1Ev)
    DEMO_LINKONCE(_ZN6common18shared_object_baseD0Ev)
    DEMO_LINKONCE(_ZN3psp11DisplayList6finishEb)
    DEMO_LINKONCE(_ZN7glutils17AnimableTrackballD0Ev)
    DEMO_LINKONCE(_ZN7glutils17AnimableTrackballD1Ev)
    DEMO_LINKONCE(_ZN7glutils17AnimableTrackball3setEN4math5FrameE)
    DEMO_LINKONCE(_ZNK7glutils17AnimableTrackball3getEv)
    DEMO_LINKONCE(_ZN6common6handleIN5scene4NodeEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene5GroupEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_5GroupEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZN6common6handleIN5scene6ObjectEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_6ObjectEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZN6common6handleIN5scene7TextureEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene9TransformEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_9TransformEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZN6common7CmdLine6OptionD1Ev)
    DEMO_LINKONCE(_ZN6common7CmdLine6OptionC1ESsjPKc)
    DEMO_LINKONCE(_ZN6common7CmdLine5TokenERSt6vectorISsSaISsEESs)
    DEMO_LINKONCE(_ZNK6common7CmdLine8find_argEPKc)
    DEMO_LINKONCE(_ZN6common7CmdLineC1ESsSsSsSsSs)
    DEMO_LINKONCE(_ZNK6common7CmdLine6inListEPKc)
    DEMO_LINKONCE(_ZN6common7CmdLine6defArgESsjPKc)
    DEMO_LINKONCE(_ZN2sh4Args3Env7getArgsERN6common7CmdLineE)
    DEMO_LINKONCE(_ZN6interp12SHLAnimationD0Ev)
    DEMO_LINKONCE(_ZN6interp12SHLAnimationD1Ev)
    DEMO_LINKONCE(_ZNK6interp12SHLAnimation3getEv)
    DEMO_LINKONCE(_ZN6interp12SHLAnimation3setEN2sh9VectorRGBE)
    DEMO_LINKONCE(_ZN7CityApp3CarD1Ev)
    DEMO_LINKONCE(_ZN7CityApp3CarD0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN7CityApp3CarEED1Ev)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED0Ev)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED1Ev)
    DEMO_LINKONCE(_ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev)
    DEMO_LINKONCE(_ZTv0_n12_NSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene5GroupEEC1INS1_4NodeEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils20PositioningInterfaceEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils9TurnTableEEC1INS1_20PositioningInterfaceEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils9TurnTableEED1Ev)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8evaluateEf)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE8evaluateEf)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEED1Ev)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene4NodeEED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene5GroupEED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene6ObjectEED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene7TextureEED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene9TransformEED0Ev)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEED1Ev)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN7CityApp3CarEED0Ev)
    DEMO_LINKONCE(_ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED0Ev)
    DEMO_LINKONCE(_ZTv0_n12_NSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils20PositioningInterfaceEED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene7TextureEEC1INS1_4NodeEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils9TurnTableEED0Ev)
    DEMO_LINKONCE(_ZNSt6vectorISsSaISsEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPSsS1_EERKSs)
    DEMO_LINKONCE(_ZSt4findIN9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEEEPKcET_SA_SA_RKT0_St26random_access_iterator_tag)
    DEMO_LINKONCE(_ZN6interp16KeyFrameSequenceIfED1Ev)
    DEMO_LINKONCE(_ZN6interp16KeyFrameSequenceIfED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene9TransformEEC1INS1_4NodeEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfED1Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfED0Ev)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE14_M_really_syncEjj)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_12__false_type)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE6setbufEPci)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE7seekoffElSt12_Ios_SeekdirSt13_Ios_Openmode)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE7seekposESt4fposI9mbstate_tESt13_Ios_Openmode)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE9underflowEv)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE9pbackfailEi)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE8overflowEi)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE18startRecordingPathEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE9addRecordEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE16deleteLastRecordEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE19finishRecordingPathEv)
    DEMO_LINKONCE(_ZNK6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE15isRecordingPathEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE8loadPathESs)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE8savePathESs)
    DEMO_LINKONCE(_ZNK6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE8pathSizeEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE18startRecordingPathEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE9addRecordEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE16deleteLastRecordEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE19finishRecordingPathEv)
    DEMO_LINKONCE(_ZNK6interp16HasPathInterfaceINS_4PathEN4math5FrameEE15isRecordingPathEv)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8loadPathESs)
    DEMO_LINKONCE(_ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8savePathESs)
    DEMO_LINKONCE(_ZNK6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8pathSizeEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE5emptyEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE4sizeEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE18sizeLessClosingKeyEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE5clearEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE6removeEj)
    DEMO_LINKONCE(_ZNK6interp16KeyFrameSequenceIfE4dumpEPKc)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE11getLastTimeEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE10getKeyTimeEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE10setKeyTimeEif)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE12isClosingKeyEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE10setCloseDtEf)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE10getCloseDtEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE8setCloseEb)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE8isClosedEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE7setLoopEb)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE6isLoopEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE11setRelativeEb)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE10isRelativeEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE6finishEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE14setTangentTypeEiNS_16keyframe_tangent4TypeEi)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE14getTangentTypeEiNS_16keyframe_tangent4SideE)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE14wrap_key_indexEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE30invalidate_cached_key_intervalEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE18calc_tangent_setupEiRfS2_S2_S2_S2_)
    DEMO_LINKONCE(_ZN6interp16KeyFrameSequenceIfE12calc_tangentEi)
    DEMO_LINKONCE(_ZNK6interp16KeyFrameSequenceIfE13calc_gradientEfff)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE16calc_all_tangentEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE17find_key_intervalEf)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE14evaluate_setupEfRfS2_RPNS_8KeyFrameIfEES6_)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE16push_closing_keyEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE18update_closing_keyEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE16on_set_key_valueEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE21get_key_abs_rel_valueEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE21set_key_abs_rel_valueEif)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE10setDefaultEf)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE10getDefaultEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE6insertEff)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE6insertEf)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIfE10getKeyListEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfEixEj)
    DEMO_LINKONCE(_ZN6interp16KeyFrameSequenceIfE8evaluateEf)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE12makeRelativeEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE12makeAbsoluteEv)
    DEMO_LINKONCE(_ZN6interp16KeyFrameSequenceIfE9typed_fixEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE18makeConsistantWithEPKNS_23VirtualKeyFrameSequenceE)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_)
    DEMO_LINKONCE(_ZN2sh4Args3Env10GetEnvTypeESs)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED1Ev)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED0Ev)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIfE12isClosingKeyEv)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIfEC1Ev)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIfE4timeEv)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIfE5valueEv)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIfE7setTimeEf)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIfE14setTangentTypeENS_16keyframe_tangent4TypeEi)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIfE14getTangentTypeENS_16keyframe_tangent4SideE)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIfE17getKeyAbsRelValueEi)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIfEC1Effb)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIfE8setValueEf)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN6interp8KeyFrameIfEES3_ET0_T_S5_S4_12__false_type)
    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEES4_EvT_SA_RKT0_)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN6interp8KeyFrameIfEEjS2_ET_S4_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE5emptyEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE4sizeEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE18sizeLessClosingKeyEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE5clearEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6removeEj)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE11getLastTimeEv)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getKeyTimeEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setKeyTimeEif)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE12isClosingKeyEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setCloseDtEf)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getCloseDtEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE8setCloseEb)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE8isClosedEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE7setLoopEb)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE6isLoopEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE11setRelativeEb)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10isRelativeEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6finishEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14setTangentTypeEiNS_16keyframe_tangent4TypeEi)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE14getTangentTypeEiNS_16keyframe_tangent4SideE)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE14wrap_key_indexEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE30invalidate_cached_key_intervalEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18calc_tangent_setupEiRS2_S4_S4_RfS5_)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16calc_all_tangentEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17find_key_intervalEf)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14evaluate_setupEfRfRS2_RPNS_8KeyFrameIS2_EES9_)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16push_closing_keyEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18update_closing_keyEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16on_set_key_valueEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21get_key_abs_rel_valueEi)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21set_key_abs_rel_valueEiS2_)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setDefaultES2_)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getDefaultEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEfS2_)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEf)
    DEMO_LINKONCE(_ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getKeyListEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEixEj)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeRelativeEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeAbsoluteEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18makeConsistantWithEPKNS_23VirtualKeyFrameSequenceE)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS4_S6_EEjRKS4_)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIN4math10quaternionEE12isClosingKeyEv)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS4_S6_EESA_)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIN4math10quaternionEEC1Ev)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIN4math10quaternionEE4timeEv)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIN4math10quaternionEE7setTimeEf)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIN4math10quaternionEE14setTangentTypeENS_16keyframe_tangent4TypeEi)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIN4math10quaternionEE14getTangentTypeENS_16keyframe_tangent4SideE)
    DEMO_LINKONCE(_ZNK6interp8KeyFrameIN4math10quaternionEE5valueEv)
    DEMO_LINKONCE(_ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17getKeyAbsRelValueEi)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIN4math10quaternionEEC1EfS2_b)
    DEMO_LINKONCE(_ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS4_S6_EERKS4_)
    DEMO_LINKONCE(_ZN6interp8KeyFrameIN4math10quaternionEE8setValueES2_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN6interp8KeyFrameIN4math10quaternionEEES5_ET0_T_S7_S6_12__false_type)
    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEES6_EvT_SC_RKT0_)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN6interp8KeyFrameIN4math10quaternionEEEjS4_ET_S6_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEES7_ET0_T_SD_SC_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEESB_ET0_T_SD_SC_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEEjS6_ET_SC_T0_RKT1_12__false_type)
);
#include "../demo_duck/gl.hpp"

/* handle<> instances this object has as asm */
namespace common {
}

/* the strings stay in the module's .rodata (asm) */
extern const char D_00159984[];     /* "load test env\n" */
extern const char D_00159994[];     /* "apply env change\n" */
extern const float D_0015B664;      /* 20 */

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _Z41__static_initialization_and_destruction_0ii_3E8);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityAppC2EN2sh4Args6CommonE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityAppC1EN2sh4Args6CommonE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityAppD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityAppD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityAppD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp7add_carEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp4initEv);

void CityApp::init_lights()
{
    common::Log() << D_00159984;
    _env.load();
    common::Log() << D_00159994;
    envChange();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp9envChangeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp11camera_idleEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp9auto_idleEv);

void CityApp::light_source_idle()
{
    _light_trackball.mode((math::Trackball::Mode)1);
    float dx = (psp::pad().down(3) - psp::pad().down(2)) * D_0015B664;
    float dy = (psp::pad().down(0) - psp::pad().down(1)) * D_0015B664;
    _light_trackball.track(dx, dy, false, true, getCamera()->getTransform());
}

float CityApp::get_anim_time() const
{
    return _anim_time;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK7CityApp19get_light_transformEv);

void CityApp::draw_scene_graph()
{
    glPushAttrib(0x2000);
    glDisable(GL_LIGHTING);
    math::matrix light = get_light_transform();
    math::matrix id = math::matrix::Identity();
    math::matrix cam = getCamera()->getTransformInverse();
    _graph.traverse((scene::TraversalType)0, frustum(), light, id, cam, _f1230);
    glPopAttrib();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp22real_demo_lightcontrolEv);

void CityApp::depthblur_idle()
{
    if (psp::pad().press(6))
        DepthBlurNextMode();
    if (psp::pad().press(5))
        DepthBlurToggleSpread();
    if (psp::pad().press(7))
        DepthBlurCycleDebugMode();
    if (psp::pad().down(0))
        DepthBlurIncrFocus();
    if (psp::pad().down(1))
        DepthBlurDecrFocus();
    if (psp::pad().down(3))
        DepthBlurIncrRange();
    if (psp::pad().down(2))
        DepthBlurDecrRange();
    DepthBlurPrint();
}

void CityApp::all_modes_idle()
{
    psp::pad();
}

void CityApp::set_control(ControledObject c)
{
    _control = c;
}

void CityApp::zrange_idle()
{
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _Z9znearfuncf);

/* cycle_depth_settings()'s statics stay in the module's data */
extern int cycle_depth_settings_current __asm__("_ZZN7CityApp20cycle_depth_settingsEvE15current_setting");
extern CityApp::DepthSetting cycle_depth_settings_SETTINGS[] __asm__("_ZZN7CityApp20cycle_depth_settingsEvE8SETTINGS");
extern char cycle_depth_settings_SETTINGS_guard __asm__("_ZGVZN7CityApp20cycle_depth_settingsEvE8SETTINGS");

void CityApp::cycle_depth_settings()
{
#define current_setting cycle_depth_settings_current
#define SETTINGS cycle_depth_settings_SETTINGS
    if (!cycle_depth_settings_SETTINGS_guard) {
        cycle_depth_settings_SETTINGS_guard = 1;
        SETTINGS[0].focus = 0;
        SETTINGS[0].range = 15;
    }
    if (current_setting == -1) {
        current_setting = 0;
    } else {
        current_setting++;
        if (current_setting >= 1)
            current_setting = 0;
    }
    DepthBlurSetRange(SETTINGS[current_setting].range);
    DepthBlurSetFocus(SETTINGS[current_setting].focus);
#undef current_setting
#undef SETTINGS
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp4drawEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _Z8run_cityv);

extern "C" int main(void)
{
    menuInit();
    run_city();
    return 0;
}

extern "C" {
void static_init_3E8(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_3E8");
void _GLOBAL__I___psp_moduleinfo(void);
void _GLOBAL__D___psp_moduleinfo(void);
}

void _GLOBAL__I___psp_moduleinfo(void)
{
    static_init_3E8(1, 0xFFFF);
}

void _GLOBAL__D___psp_moduleinfo(void)
{
    static_init_3E8(0, 0xFFFF);
}

extern template common::CmdLine::const_iterator std::find<common::CmdLine::const_iterator, const char *>(common::CmdLine::const_iterator, common::CmdLine::const_iterator, const char *const &, std::random_access_iterator_tag);

SGL_LINKONCE_BEGIN
inline common::CmdLine::const_iterator common::CmdLine::find_arg(const char *opts) const
{
    std::vector<std::string> toks;
    Token(toks, opts);
    for (std::vector<std::string>::iterator it = toks.begin(); it != toks.end(); ++it) {
        const_iterator f = std::find(_args.begin(), _args.end(), it->c_str());
        if (f != _args.end())
            return f + 1;
    }
    return _args.end();
}
SGL_LINKONCE_END

SGL_LINKONCE_BEGIN
inline bool common::CmdLine::inList(const char *list) const
{
    std::vector<std::string> toks;
    Token(toks, list);
    for (std::vector<std::string>::iterator it = toks.begin(); it != toks.end(); ++it)
        if (std::find(_args.begin(), _args.end(), it->c_str()) != _args.end())
            return true;
    return false;
}
SGL_LINKONCE_END

extern "C" const char D_00159BF8[];
extern "C" const char D_00159C3C[];
extern "C" const char D_00159CD4[];
extern "C" const char D_00159D18[];
extern "C" const char D_00159D38[];
extern "C" const char D_00159D78[];
extern "C" const char D_00159DB8[];
extern "C" const char D_00159DE8[];
extern "C" const char D_00159E20[];
extern "C" const char D_00159E58[];
extern "C" const char D_00159E88[];
extern "C" const char D_00159BE8[];
extern "C" const char D_00159ED0[];
extern "C" const char D_00159EEC[];
extern "C" const char D_00159F08[];
extern "C" const char D_0015A1D0[];
extern "C" const char D_00159808[];

static inline void get_arg(common::CmdLine &cl, const char *opt, std::string &s)
{
    common::CmdLine::const_iterator it = cl.find_arg(opt);
    if (it != cl.end())
        s = *it;
}

static inline void get_arg(common::CmdLine &cl, const char *opt, float &f)
{
    common::CmdLine::const_iterator it = cl.find_arg(opt);
    if (it != cl.end())
        f = libc_fix::AtoF(it->c_str());
}

static inline void get_arg(common::CmdLine &cl, const char *opt, int &i)
{
    common::CmdLine::const_iterator it = cl.find_arg(opt);
    if (it != cl.end())
        i = libc_fix::AtoI(it->c_str());
}

SGL_LINKONCE_BEGIN
inline void sh::Args::Env::getArgs(common::CmdLine &cl)
{
    std::string t;
    get_arg(cl, D_00159BF8, t);
    type = GetEnvType(t.c_str());
    get_arg(cl, D_00159C3C, name);
    get_arg(cl, D_00159CD4, exposure);
    get_arg(cl, D_00159D18, _fC);
    get_arg(cl, D_00159D38, _f14);
    get_arg(cl, D_00159D78, _f10);
    get_arg(cl, D_00159DB8, _f18);
    get_arg(cl, D_00159DE8, _f20);
    get_arg(cl, D_00159E20, _f1C);
    get_arg(cl, D_00159E58, dir);
    _f28 = cl.inList(D_00159E88);
    get_arg(cl, D_00159BE8, cube_size);
    get_arg(cl, D_00159ED0, _f30);
    get_arg(cl, D_00159EEC, _f34);
    get_arg(cl, D_00159F08, _f38);
    if (dir == D_0015A1D0)
        dir = D_00159808;
}
SGL_LINKONCE_END

SGL_LINKONCE_BEGIN
template<> inline void interp::KeyFrameSequence<float>::typed_fix()
{
}
SGL_LINKONCE_END

extern "C" const char D_0015ACE0[]; /* "DEBUG" */
extern "C" const char D_0015ACE8[]; /* "debug" */
extern "C" const char D_0015ACF0[]; /* "SKY" */
extern "C" const char D_0015ACF4[]; /* "sky" */
extern "C" const char D_0015ACF8[]; /* "HDR" */
extern "C" const char D_0015ACFC[]; /* "hdr" */
extern "C" const char D_0015AD00[]; /* "TEX" */
extern "C" const char D_0015AD04[]; /* "tex" */

SGL_LINKONCE_BEGIN
inline sh::Args::Env::Type sh::Args::Env::GetEnvType(std::string s)
{
    if (s == D_0015ACE0 || s == D_0015ACE8)
        return (Type)0;
    if (s == D_0015ACF0 || s == D_0015ACF4)
        return (Type)1;
    if (s == D_0015ACF8 || s == D_0015ACFC)
        return (Type)3;
    if (s == D_0015AD00 || s == D_0015AD04)
        return (Type)2;
    return (Type)0;
}
SGL_LINKONCE_END

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

/* Graph's map<const string, handle<Node> >::find stays asm: splat put its start at the end of the basic_string<char *>
   constructor's .s (func_00008404 is the rest) */

/* template instances of this object that only its asm functions use: called from here (a discarded function) so
   that cc1plus emits them (their order is DEMO_LINKONCE_ORDER's) */
extern "C" void CityApp_instance_refs(common::handle<scene::Node> &n, common::handle<scene::Group> &g,
                                      common::handle<scene::Object> &o, common::handle<scene::Texture> &t,
                                      common::handle<scene::Transform> &tr, common::handle<CityApp::Car> &c,
                                      common::handle<glutils::TurnTable> &tt,
                                      common::handle<glutils::PositioningInterface> &pi,
                                      std::vector<common::handle<CityApp::Car> > &cars, std::vector<std::string> &v)
    __attribute__((section(".discard.asm")));
extern "C" void CityApp_instance_refs(common::handle<scene::Node> &n, common::handle<scene::Group> &g,
                                      common::handle<scene::Object> &o, common::handle<scene::Texture> &t,
                                      common::handle<scene::Transform> &tr, common::handle<CityApp::Car> &c,
                                      common::handle<glutils::TurnTable> &tt,
                                      common::handle<glutils::PositioningInterface> &pi,
                                      std::vector<common::handle<CityApp::Car> > &cars, std::vector<std::string> &v)
{
    n.invalidate();
    g.invalidate();
    o.invalidate();
    t.invalidate();
    tr.invalidate();
    c.invalidate();
    tt.invalidate();
    tr = tr;
    c = c;
    v.push_back(std::string());
    common::handle<scene::Node> a(g), b(o), d(tr);
    common::handle<scene::Group> e(n);
    common::handle<glutils::TurnTable> f(pi);
    common::handle<scene::Texture> h(n);
    common::handle<scene::Transform> i(n);
}

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6common7CmdLine6OptionESaIS2_EE9push_backERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN5scene5Graph7newNodeINS_9TransformEEEN6common6handleIT_EESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNKSt15basic_stringbufIcSt11char_traitsIcESaIcEE3strEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN5scene5Graph13getMappedNodeINS_7TextureEEEN6common6handleIT_EERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6common7CmdLine6OptionESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6common6handleIN7CityApp3CarEEESaIS4_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS4_S6_EERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN5scene5Graph13getMappedNodeINS_9TransformEEEN6common6handleIT_EERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE17_M_stringbuf_initESt13_Ios_Openmode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSsC1IPcEET_S1_RKSaIcE);
CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", func_00008404, _ZNSsC1IPcEET_S1_RKSaIcE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ENS2_7LessStrESaIS7_EE4findERS0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common7CmdLine6OptionESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common6handleIN7CityApp3CarEEESt6vectorIS6_SaIS6_EEEESB_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag);
CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", func_000087B4, _ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp23VirtualKeyFrameSequenceD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp23VirtualKeyFrameSequenceD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16VirtualQuickAnimD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16VirtualQuickAnimD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common15handle_internal10data_ownerD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common15handle_internal10data_ownerD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common15handle_internal10data_owner8set_dataEPNS0_4dataE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common18shared_object_baseD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common18shared_object_baseD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN3psp11DisplayList6finishEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7glutils17AnimableTrackballD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7glutils17AnimableTrackballD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7glutils17AnimableTrackball3setEN4math5FrameE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK7glutils17AnimableTrackball3getEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene6ObjectEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common7CmdLine6OptionD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common7CmdLine6OptionC1ESsjPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common7CmdLine5TokenERSt6vectorISsSaISsEESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common7CmdLineC1ESsSsSsSsSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common7CmdLine6defArgESsjPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp12SHLAnimationD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp12SHLAnimationD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp12SHLAnimation3getEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp12SHLAnimation3setEN2sh9VectorRGBE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp3CarD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp3CarD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN7CityApp3CarEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZTv0_n12_NSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8evaluateEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE8evaluateEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene6ObjectEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN7CityApp3CarEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZTv0_n12_NSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt4findIN9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEEEPKcET_SA_SA_RKT0_St26random_access_iterator_tag);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16KeyFrameSequenceIfED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16KeyFrameSequenceIfED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE14_M_really_syncEjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE6setbufEPci);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE7seekoffElSt12_Ios_SeekdirSt13_Ios_Openmode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE7seekposESt4fposI9mbstate_tESt13_Ios_Openmode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE9underflowEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE9pbackfailEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE8overflowEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE18startRecordingPathEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE9addRecordEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE16deleteLastRecordEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE19finishRecordingPathEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE15isRecordingPathEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE8loadPathESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE8savePathESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE8pathSizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE18startRecordingPathEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE9addRecordEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE16deleteLastRecordEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE19finishRecordingPathEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp16HasPathInterfaceINS_4PathEN4math5FrameEE15isRecordingPathEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8loadPathESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8savePathESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8pathSizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIfE5emptyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIfE4sizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIfE18sizeLessClosingKeyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE5clearEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE6removeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp16KeyFrameSequenceIfE4dumpEPKc);
CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", func_0000CD14, _ZNK6interp16KeyFrameSequenceIfE4dumpEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIfE12isClosingKeyEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE10setCloseDtEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIfE10getCloseDtEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE8setCloseEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIfE8isClosedEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE7setLoopEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIfE6isLoopEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE11setRelativeEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIfE10isRelativeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE6finishEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE14setTangentTypeEiNS_16keyframe_tangent4TypeEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIfE14getTangentTypeEiNS_16keyframe_tangent4SideE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIfE14wrap_key_indexEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE30invalidate_cached_key_intervalEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE18calc_tangent_setupEiRfS2_S2_S2_S2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16KeyFrameSequenceIfE12calc_tangentEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp16KeyFrameSequenceIfE13calc_gradientEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE16calc_all_tangentEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE17find_key_intervalEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE14evaluate_setupEfRfS2_RPNS_8KeyFrameIfEES6_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE16push_closing_keyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE18update_closing_keyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE16on_set_key_valueEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE21get_key_abs_rel_valueEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE21set_key_abs_rel_valueEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE10setDefaultEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIfE10getDefaultEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE6insertEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE6insertEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIfE10getKeyListEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfEixEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16KeyFrameSequenceIfE8evaluateEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE12makeRelativeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE12makeAbsoluteEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE18makeConsistantWithEPKNS_23VirtualKeyFrameSequenceE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp8KeyFrameIfE12isClosingKeyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp8KeyFrameIfEC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp8KeyFrameIfE4timeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp8KeyFrameIfE5valueEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp8KeyFrameIfE7setTimeEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp8KeyFrameIfE14setTangentTypeENS_16keyframe_tangent4TypeEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp8KeyFrameIfE14getTangentTypeENS_16keyframe_tangent4SideE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE17getKeyAbsRelValueEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp8KeyFrameIfEC1Effb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp8KeyFrameIfE8setValueEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt24__uninitialized_copy_auxIPN6interp8KeyFrameIfEES3_ET0_T_S5_S4_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEES4_EvT_SA_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt26__uninitialized_fill_n_auxIPN6interp8KeyFrameIfEEjS2_ET_S4_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIfEESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE5emptyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE4sizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE18sizeLessClosingKeyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE5clearEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6removeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE11getLastTimeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getKeyTimeEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setKeyTimeEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE12isClosingKeyEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setCloseDtEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getCloseDtEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE8setCloseEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE8isClosedEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE7setLoopEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE6isLoopEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE11setRelativeEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10isRelativeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6finishEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14setTangentTypeEiNS_16keyframe_tangent4TypeEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE14getTangentTypeEiNS_16keyframe_tangent4SideE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE14wrap_key_indexEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE30invalidate_cached_key_intervalEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18calc_tangent_setupEiRS2_S4_S4_RfS5_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16calc_all_tangentEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17find_key_intervalEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14evaluate_setupEfRfRS2_RPNS_8KeyFrameIS2_EES9_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16push_closing_keyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18update_closing_keyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16on_set_key_valueEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21get_key_abs_rel_valueEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21set_key_abs_rel_valueEiS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setDefaultES2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getDefaultEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEfS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getKeyListEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEixEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeRelativeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeAbsoluteEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18makeConsistantWithEPKNS_23VirtualKeyFrameSequenceE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS4_S6_EEjRKS4_);
CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", func_00012EB8, _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS4_S6_EEjRKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp8KeyFrameIN4math10quaternionEE4timeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp8KeyFrameIN4math10quaternionEE7setTimeEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp8KeyFrameIN4math10quaternionEE14setTangentTypeENS_16keyframe_tangent4TypeEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp8KeyFrameIN4math10quaternionEE14getTangentTypeENS_16keyframe_tangent4SideE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp8KeyFrameIN4math10quaternionEE5valueEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17getKeyAbsRelValueEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp8KeyFrameIN4math10quaternionEEC1EfS2_b);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS4_S6_EERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp8KeyFrameIN4math10quaternionEE8setValueES2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt24__uninitialized_copy_auxIPN6interp8KeyFrameIN4math10quaternionEEES5_ET0_T_S7_S6_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEES6_EvT_SC_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt26__uninitialized_fill_n_auxIPN6interp8KeyFrameIN4math10quaternionEEEjS4_ET_S6_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEES7_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEESB_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN6interp8KeyFrameIN4math10quaternionEEESt6vectorIS6_SaIS6_EEEEjS6_ET_SC_T0_RKT1_12__false_type);
