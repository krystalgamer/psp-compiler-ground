/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
/* Identity()'s 1.0f stays in the module's .rodata (asm) */
extern const float D_0015B668;
#define MATH_IDENTITY_ONE D_0015B668
#define DEMO_TEMPLATE_DEFS
#define SCENE_GRAPH_TEMPLATE_DEFS
#define INTERP_LINKONCE_VKFS
#define DEMO_LINKONCE_data_owner 1
#define DEMO_LINKONCE_shared_object_base 1
#define DEMO_LINKONCE_CityApp 1
#define DEMO_LINKONCE_CmdLine 1
#include "main.hpp"
#include <sstream>

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

/* Graph.h's asserts (getMappedNode<T>, newNode<T>) */
extern const char scene_graph_h_err[] __asm__("D_00159954");        /* " *** error " */
extern const char scene_graph_h_name_expr[] __asm__("D_0015A0D0");  /* "_Name != \"\"" */
extern const char scene_graph_h_file[] __asm__("D_0015A0DC");       /* "../lib/scene/Graph.h" */
extern const char scene_graph_h_sp[] __asm__("D_00159884");         /* " " */
extern const char scene_graph_h_empty[] __asm__("D_00159808");      /* "" */
extern const char scene_graph_h_us[] __asm__("D_0015A06C");         /* "_" */
extern const char gmn_Texture_name[] __asm__("_ZZN5scene5Graph13getMappedNodeINS_7TextureEEEN6common6handleIT_EERKSsE19__PRETTY_FUNCTION___15A070");
extern const char gmn_Transform_name[] __asm__("_ZZN5scene5Graph13getMappedNodeINS_9TransformEEEN6common6handleIT_EERKSsE19__PRETTY_FUNCTION___15A0F4");
namespace scene {
inline const char *scene_pf_getMappedNode(Texture *) { return gmn_Texture_name; }
inline const char *scene_pf_getMappedNode(Transform *) { return gmn_Transform_name; }
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

extern "C" const char D_00159808[]; /* "" */

SGL_LINKONCE_BEGIN
inline common::CmdLine::CmdLine(std::string a1, std::string a2, std::string a3, std::string a4, std::string a5)
{
    if (a1 == D_00159808)
        return;
    _args.push_back(a1);
    if (a2 == D_00159808)
        return;
    _args.push_back(a2);
    if (a3 == D_00159808)
        return;
    _args.push_back(a3);
    if (a4 == D_00159808)
        return;
    _args.push_back(a4);
    if (a5 == D_00159808)
        return;
    _args.push_back(a5);
}
SGL_LINKONCE_END

/* expanded before the instances below: the first inliner of the allocator (dead code: no string constant) */
template<int> void CityApp_alloc_first() __attribute__((section(".discard.alloc")));
template<int> void CityApp_alloc_first()
{
    int never = 0;
    if (never)
        std::__default_alloc_template<true, 0>::deallocate(std::__default_alloc_template<true, 0>::allocate(8), 8);
}
template void CityApp_alloc_first<0>();
/* expanded before defArg (which calls them) and before ~Option (which _M_insert_aux inlines) */
template void std::vector<common::CmdLine::Option>::push_back(const common::CmdLine::Option &);
template void std::vector<common::CmdLine::Option>::_M_insert_aux(std::vector<common::CmdLine::Option>::iterator,
                                                                  const common::CmdLine::Option &);

SGL_LINKONCE_BEGIN
inline void common::CmdLine::defArg(std::string names, unsigned int n, const char *help)
{
    std::vector<std::string> toks;
    Token(toks, names);
    for (std::vector<std::string>::iterator it = toks.begin(); it != toks.end(); ++it)
        _options.push_back(Option(*it, n, help));
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

extern "C" void sceKernelDcacheWritebackAll(void);
extern "C" int sceGuCheckList(void);
extern "C" const char D_00159954[]; /* " *** error " */
extern "C" const char D_00159968[]; /* "../lib/gl_psp/DisplayList.h" */
extern "C" const char D_00159884[]; /* " " */
extern "C" const char D_0015A1A8[]; /* "_wflag" */
extern "C" const char D_0015A1B0[]; /* "_size == 0" */
extern "C" const char D_0015A1BC[]; /* "_size < _capacity" */
extern const char DisplayList_finish_fn[] __asm__("_ZZN3psp11DisplayList6finishEbE19__PRETTY_FUNCTION___15A184");

SGL_LINKONCE_BEGIN
inline void psp::DisplayList::finish(bool writeback)
{
    SGL_ASSERT(_wflag, D_00159954, D_0015A1A8, D_00159968, DisplayList_finish_fn, 0xBD, D_00159884);
    SGL_ASSERT(_size == 0, D_00159954, D_0015A1B0, D_00159968, DisplayList_finish_fn, 0xBE, D_00159884);
    _size = sceGuCheckList();
    SGL_ASSERT(_size < _capacity, D_00159954, D_0015A1BC, D_00159968, DisplayList_finish_fn, 0xC2, D_00159884);
    if (writeback)
        sceKernelDcacheWritebackAll();
    sceGuFinish();
    _wflag = false;
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

/* inline (KeyFrameSequence.h; interp_KeyFrameSequence.o holds its copy) */
inline interp::KeyFrameSequence<math::quaternion>::~KeyFrameSequence()
{
}
/* interp:: template bodies (as in demo_duck's interp_Path) */
/* interp's assert (common/assert) */
#define INTERP_ASSERT(c, text, fn, line) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00159954, text, D_0015A23C, fn, line, D_00159884); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }
/* KeyFrameSequence.h's */
#define INTERP_ASSERT_KFS(c, text, fn, line) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00159954, text, D_0015AC10, fn, line, D_00159884); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }
/* ... with a message */
#define INTERP_ASSERT_MSG(c, text, fn, line, msg) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00159954, text, D_0015A23C, fn, line, msg); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }
extern const char D_00159884[];     /* " " */
extern const char D_0015A23C[];     /* "../lib/interp/KeyFrameSequenceBase.h" */
extern const char D_00159954[];     /* " *** error " */
extern const char D_0015A520[];     /* "! _keys.back().isClosingKey()" */
extern const char D_0015A4B4[];     /* "_keys.empty() || _keys.size() > 1" */
extern const char D_0015A220[];     /* "_keys.back().isClosingKey()" */
extern const char D_0015A2E8[];     /* "_Index >= 0 && _Index < (int) _keys.size()" */
extern const float D_00163A1C;      /* 0.2f: KeyFrameSequenceBase<float>() */
extern const float D_00163A20;      /* 1.0f: KeyFrameSequenceBase<quaternion>() */
extern const float D_00163A24;      /* 0.2f */
extern const char PF_setClose_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE8setCloseEbE19__PRETTY_FUNCTION___15A4D8");
extern const char PF_setCloseDt_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE10setCloseDtEfE19__PRETTY_FUNCTION___15A468");
extern const char PF_setClose_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE8setCloseEbE19__PRETTY_FUNCTION___15AF6C");
extern const char PF_setCloseDt_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setCloseDtEfE19__PRETTY_FUNCTION___15AF18");
extern const char PF_setKeyValue_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE11setKeyValueEiS2_E19__PRETTY_FUNCTION__");
extern const char PF_setKeyValue_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE11setKeyValueEifE19__PRETTY_FUNCTION___1611A8");

extern const char D_0015A41C[];     /* "_Index >= 0 && _Index < (int)_keys.size()" */
extern const char D_0015A448[];     /* "! ( ( ! _closed ) && retval )" */
extern const char PF_getKeyTime_f[] __asm__("_ZZNK6interp20KeyFrameSequenceBaseIfE10getKeyTimeEiE19__PRETTY_FUNCTION___15A298");
extern const char PF_getKeyTime_q[] __asm__("_ZZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE10getKeyTimeEiE19__PRETTY_FUNCTION___15AE04");
extern const char PF_isClosingKey_f[] __asm__("_ZZNK6interp20KeyFrameSequenceBaseIfE12isClosingKeyEiE19__PRETTY_FUNCTION___15A3CC");
extern const char PF_isClosingKey_q[] __asm__("_ZZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE12isClosingKeyEiE19__PRETTY_FUNCTION___15AEBC");
extern const char PF_setTangentType_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE14setTangentTypeEiNS_16keyframe_tangent4TypeEiE19__PRETTY_FUNCTION___15A540");
extern const char PF_setTangentType_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14setTangentTypeEiNS_16keyframe_tangent4TypeEiE19__PRETTY_FUNCTION___15AFC0");
extern const char PF_getTangentType_f[] __asm__("_ZZNK6interp20KeyFrameSequenceBaseIfE14getTangentTypeEiNS_16keyframe_tangent4SideEE19__PRETTY_FUNCTION___15A5B0");
extern const char PF_getTangentType_q[] __asm__("_ZZNK6interp20KeyFrameSequenceBaseIN4math10quaternionEE14getTangentTypeEiNS_16keyframe_tangent4SideEE19__PRETTY_FUNCTION___15B03C");
extern const char D_0015ABA0[];     /* "_Index >=0 && _Index < _keys.size()" */
extern const char D_00159808[];     /* "" */
extern const char D_0015AD84[];     /* "../lib/interp/KeyFrame.h" */
extern const char D_0015ADA0[];     /* "bad tangent" */
extern const char PF_index_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfEixEjE19__PRETTY_FUNCTION___15AB38");
extern const char PF_index_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEEixEjE19__PRETTY_FUNCTION___15B464");
extern const char PF_kf_getTangentType_f[] __asm__("_ZZNK6interp8KeyFrameIfE14getTangentTypeENS_16keyframe_tangent4SideEE19__PRETTY_FUNCTION___15AD08");
extern const char PF_kf_getTangentType_q[] __asm__("_ZZNK6interp8KeyFrameIN4math10quaternionEE14getTangentTypeENS_16keyframe_tangent4SideEE19__PRETTY_FUNCTION___15B580");
extern const char D_0015AC80[];     /* "! _relative" */
extern const char D_0015ACD4[];     /* "_relative" */
extern const char PF_makeRelative_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE12makeRelativeEvE19__PRETTY_FUNCTION___15AC38");
extern const char PF_makeAbsolute_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE12makeAbsoluteEvE19__PRETTY_FUNCTION___15AC8C");
extern const char PF_makeRelative_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeRelativeEvE19__PRETTY_FUNCTION___15B4D8");
extern const char PF_makeAbsolute_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE12makeAbsoluteEvE19__PRETTY_FUNCTION___15B52C");
extern const char PF_get_key_abs_rel_value_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE21get_key_abs_rel_valueEiE19__PRETTY_FUNCTION___15A9EC");
extern const char PF_get_key_abs_rel_value_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21get_key_abs_rel_valueEiE19__PRETTY_FUNCTION___15B344");
extern const char PF_update_closing_key_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE18update_closing_keyEvE19__PRETTY_FUNCTION___15A950");
extern const char PF_update_closing_key_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18update_closing_keyEvE19__PRETTY_FUNCTION___15B294");
extern const char PF_on_set_key_value_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE16on_set_key_valueEiE19__PRETTY_FUNCTION___15A99C");
extern const char PF_on_set_key_value_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16on_set_key_valueEiE19__PRETTY_FUNCTION___15B2EC");
extern const char PF_set_key_abs_rel_value_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE21set_key_abs_rel_valueEifE19__PRETTY_FUNCTION___15AA44");
extern const char PF_set_key_abs_rel_value_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE21set_key_abs_rel_valueEiS2_E19__PRETTY_FUNCTION___15B3A4");
extern const char D_0015A8DC[];     /* "keys.back() already a closing key" */
extern const char D_0015A900[];     /* "! _keys.empty()" */
extern const char D_0015A910[];     /* "trying to push a closing key in non closed animation" */
extern const char D_0015A948[];     /* "_closed" */
extern const float D_0015B6B4;      /* 1/3: KeyFrameSequence<float>::calc_tangent */
extern const char PF_push_closing_key_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE16push_closing_keyEvE19__PRETTY_FUNCTION___15A890");
extern const char PF_push_closing_key_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE16push_closing_keyEvE19__PRETTY_FUNCTION___15B23C");
extern const char D_0015A264[];     /* "_Index < _keys.size()" */
extern const char PF_remove_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE6removeEjE19__PRETTY_FUNCTION___15A1D4");
extern const char PF_remove_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6removeEjE19__PRETTY_FUNCTION___15ADAC");
extern const float D_0015B6CC;      /* 1.0f: makeConsistantWith<quaternion> */
extern const char D_0015AC0C[];     /* "k2" */
extern const char D_0015AC10[];     /* "../lib/interp/KeyFrameSequence.h" */
extern const char D_0015AC34[];     /* "k1" */
extern const char PF_kfs_evaluate_f[] __asm__("_ZZN6interp16KeyFrameSequenceIfE8evaluateEfE19__PRETTY_FUNCTION___15ABC4");
/* this object's copy of the header static */
extern const math::matrix BEZIER_BASIS_18E25C __asm__("_ZN4math12BEZIER_BASISE_189CA0");
extern const float D_0015B6B8;      /* 1.0f: evaluate_setup<float> */
extern const float D_0015B6C4;      /* 1.0f: evaluate_setup<quaternion> */
extern const char D_0015A870[];     /* "t >= 0.f && t <= 1.f" */
extern const char D_0015A888[];     /* "k > 0" */
extern const char PF_evaluate_setup_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE14evaluate_setupEfRfS2_RPNS_8KeyFrameIfEES6_E19__PRETTY_FUNCTION___15A7E8");
extern const char PF_evaluate_setup_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE14evaluate_setupEfRfRS2_RPNS_8KeyFrameIS2_EES9_E19__PRETTY_FUNCTION___15B1A8");
extern const char D_0015A748[];     /* "you probably forgot to reset _key_interval to 1 after an insert or remove, or setClose..." */
extern const char D_0015A7A4[];     /* "_key_interval > 0 && _key_interval < n" */
extern const char D_0015A7CC[];     /* "d > 0" */
extern const char D_0015A7D4[];     /* "_key_interval != 0" */
extern const char PF_find_key_interval_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE17find_key_intervalEfE19__PRETTY_FUNCTION___15A6F8");
extern const char PF_find_key_interval_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17find_key_intervalEfE19__PRETTY_FUNCTION___15B14C");
extern const char D_0015A364[];     /* "_keys.back().time() > _keys[n-2].time()" */
extern const char D_0015A38C[];     /* "_Time < _keys[_Index+1].time()" */
extern const char D_0015A3AC[];     /* "_keys[_Index-1].time() < _Time" */
extern const char PF_setKeyTime_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE10setKeyTimeEifE19__PRETTY_FUNCTION___15A314");
extern const char PF_setKeyTime_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE10setKeyTimeEifE19__PRETTY_FUNCTION___15AE60");
extern const float D_0015B6C0;      /* 1.0f: calc_tangent_setup<quaternion> */
extern const char D_0015A6A8[];     /* "count == 1 || count == 2" */
extern const char D_0015A6C4[];     /* "dt != 0.f" */
extern const char D_0015A6D0[];     /* "error in tangent setup" */
extern const char D_0015A6E8[];     /* "i >= 0 && i < n" */
extern const char PF_calc_tangent_setup_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE18calc_tangent_setupEiRfS2_S2_S2_S2_E19__PRETTY_FUNCTION___15A63C");
extern const char PF_calc_tangent_setup_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE18calc_tangent_setupEiRS2_S4_S4_RfS5_E19__PRETTY_FUNCTION___15B0D4");
extern const char D_0015AAF0[];     /* "_keys.size() > 0" */
extern const char D_0015AB04[];     /* "_keys.size() > 1" */
extern const char D_0015AB18[];     /* " same key time already exist!\n" */
extern const char PF_insert_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE6insertEffE19__PRETTY_FUNCTION___15AAA4");
extern const char PF_insert_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEfS2_E19__PRETTY_FUNCTION___15B40C");
extern const char FN_insert_f[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIfE6insertEffE12__FUNCTION___15AA9C");
extern const char FN_insert_q[] __asm__("_ZZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEfS2_E12__FUNCTION___15B404");
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
    static float evaluate_setup_one() { return D_0015B6B8; }
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
    static float cts_one() { return D_0015B6C0; }
    static void cts_zero(math::quaternion &x, float one) { x = math::quaternion(0, 0, 0, one); }
    static const char *calc_tangent_setup() { return PF_calc_tangent_setup_q; }
    static const char *setKeyTime() { return PF_setKeyTime_q; }
    static const char *find_key_interval() { return PF_find_key_interval_q; }
    static float evaluate_setup_one() { return D_0015B6C4; }
    static const char *evaluate_setup() { return PF_evaluate_setup_q; }
    static math::quaternion mcw_value() { return math::quaternion(0, 0, 0, D_0015B6CC); }
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

/* not inline (the original calls its D2 from the inline destructors of KeyFrameSequence<quaternion> and
   HasPathInterface<>) */
template<class T> interp::KeyFrameSequenceBase<T>::~KeyFrameSequenceBase()
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
            INTERP_ASSERT(!_keys.back().isClosingKey(), D_0015A520, kfs_data<T>::setClose(), 705);
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
        INTERP_ASSERT(_keys.empty() || _keys.size() > 1, D_0015A4B4, kfs_data<T>::setCloseDt(), 670);
        if (!_keys.empty()) {
            INTERP_ASSERT(_keys.back().isClosingKey(), D_0015A220, kfs_data<T>::setCloseDt(), 674);
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
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_0015A2E8, kfs_data<T>::setKeyValue(), 274);
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
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_0015A2E8, kfs_data<T>::getKeyTime(), 409);
    return _keys[_Index].time();
}

template<class T> bool interp::KeyFrameSequenceBase<T>::isClosingKey(int _Index) const
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_0015A41C, kfs_data<T>::isClosingKey(), 480);
    bool retval = _keys[_Index].isClosingKey();
    INTERP_ASSERT(!((!_closed) && retval), D_0015A448, kfs_data<T>::isClosingKey(), 484);
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
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_0015A2E8, kfs_data<T>::setTangentType(), 1095);
    _keys[_Index].setTangentType(t, side);
}

template<class T> interp::keyframe_tangent::Type interp::KeyFrameSequenceBase<T>::getTangentType(int _Index, keyframe_tangent::Side s) const
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_0015A2E8, kfs_data<T>::getTangentType(), 1104);
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
    common::common_internal::assert_display(D_00159954, D_00159808, D_0015AD84, kfs_data<T>::kf_getTangentType(), 127, D_0015ADA0);
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
    INTERP_ASSERT(_Index < _keys.size(), D_0015ABA0, kfs_data<T>::index(), 655);
    return _keys[_Index];
}

template<class T> void interp::KeyFrameSequenceBase<T>::makeRelative()
{
    INTERP_ASSERT(!_relative, D_0015AC80, kfs_data<T>::makeRelative(), 1144);
    for (typename std::vector<KeyFrame<T> >::iterator it = _keys.begin(); it < _keys.end(); it++)
        it->setValue(op_inv(it->value(), _default));
    finish();
    _relative = true;
}

template<class T> void interp::KeyFrameSequenceBase<T>::makeAbsolute()
{
    INTERP_ASSERT(_relative, D_0015ACD4, kfs_data<T>::makeAbsolute(), 1163);
    for (typename std::vector<KeyFrame<T> >::iterator it = _keys.begin(); it < _keys.end(); it++)
        it->setValue(op(_default, it->value()));
    finish();
    _relative = false;
}

template<class T> T interp::KeyFrameSequenceBase<T>::get_key_abs_rel_value(int _Index)
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_0015A2E8, kfs_data<T>::get_key_abs_rel_value(), 1184);
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
    INTERP_ASSERT(_keys.back().isClosingKey(), D_0015A220, kfs_data<T>::update_closing_key(), 365);
    _keys.back().setTime(_keys[n - 2].time() + _closeDt);
    _keys.back().setValue(_keys[0].value());
}

template<class T> void interp::KeyFrameSequenceBase<T>::on_set_key_value(int i)
{
    if (_closed && (int)_keys.size() > 1) {
        INTERP_ASSERT(_keys.back().isClosingKey(), D_0015A220, kfs_data<T>::on_set_key_value(), 386);
        if (_keys[i].isClosingKey())
            _keys[0].setValue(_keys[i].value());
    }
}

template<class T> void interp::KeyFrameSequenceBase<T>::set_key_abs_rel_value(int _Index, T v)
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_0015A2E8, kfs_data<T>::set_key_abs_rel_value(), 1196);
    KeyFrame<T> &k = _keys[_Index];
    k.setValue(op_inv(v, _relative ? _default : op_identity()));
}

template<class T> void interp::KeyFrameSequenceBase<T>::push_closing_key()
{
    INTERP_ASSERT_MSG(_closed, D_0015A948, kfs_data<T>::push_closing_key(), 345, D_0015A910);
    INTERP_ASSERT(!_keys.empty(), D_0015A900, kfs_data<T>::push_closing_key(), 347);
    INTERP_ASSERT_MSG(!_keys.back().isClosingKey(), D_0015A520, kfs_data<T>::push_closing_key(), 349, D_0015A8DC);
    _keys.push_back(KeyFrame<T>(_keys.back().time() + _closeDt, _keys[0].value(), true));
}

template<class T> void interp::KeyFrameSequence<T>::calc_tangent(int i)
{
    T a, b, c;
    float s0, s1;
    if (this->calc_tangent_setup(i, a, b, c, s0, s1)) {
        KeyFrame<T> &k = this->_keys[i];
        T v = k.value();
        const float third = D_0015B6B4;
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
    INTERP_ASSERT(_Index < _keys.size(), D_0015A264, kfs_data<T>::remove(), 617);
    if (_keys[_Index].isClosingKey())
        return;
    for (unsigned int i = _Index + 1; i < _keys.size(); i++)
        _keys[i - 1] = _keys[i];
    _keys.resize(_keys.size() - 1);
    if (_closed && _keys.size() == 1) {
        INTERP_ASSERT(_keys.back().isClosingKey(), D_0015A220, kfs_data<T>::remove(), 636);
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
    INTERP_ASSERT(k > 0, D_0015A888, kfs_data<T>::evaluate_setup(), 1071);
    k1 = &_keys[k - 1];
    if (u == k1->time()) {
        v = getKeyAbsRelValue(k - 1);
        return false;
    }
    float dt = k2->time() - k1->time();
    u = (u - k1->time()) / dt;
    INTERP_ASSERT(u >= 0.f && u <= kfs_data<T>::evaluate_setup_one(), D_0015A870, kfs_data<T>::evaluate_setup(), 1086);
    return true;
}

template<class T> void interp::KeyFrameSequenceBase<T>::setKeyTime(int _Index, float _Time)
{
    INTERP_ASSERT(_Index >= 0 && _Index < (int)_keys.size(), D_0015A2E8, kfs_data<T>::setKeyTime(), 422);
    if (_Index > 0)
        INTERP_ASSERT(_keys[_Index - 1].time() < _Time, D_0015A3AC, kfs_data<T>::setKeyTime(), 426);
    int n = _keys.size();
    if (_Index < n - 1 && !(_closed && _Index == n - 2))
        INTERP_ASSERT(_Time < _keys[_Index + 1].time(), D_0015A38C, kfs_data<T>::setKeyTime(), 435);
    _keys[_Index].setTime(_Time);
    if (_closed && n >= 2) {
        INTERP_ASSERT(_keys.back().isClosingKey(), D_0015A220, kfs_data<T>::setKeyTime(), 445);
        if (_Index == n - 1) {
            INTERP_ASSERT(_keys.back().time() > _keys[n - 2].time(), D_0015A364, kfs_data<T>::setKeyTime(), 463);
            _closeDt = _keys.back().time() - _keys[n - 2].time();
        }
    }
    calc_all_tangent();
    invalidate_cached_key_interval();
}

template<class T> bool interp::KeyFrameSequenceBase<T>::calc_tangent_setup(int i, T &a, T &b, T &c, float &s0, float &s1)
{
    int n = _keys.size();
    INTERP_ASSERT(i >= 0 && i < n, D_0015A6E8, kfs_data<T>::calc_tangent_setup(), 911);
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
        common::common_internal::assert_display(D_00159954, D_00159808, D_0015A23C, kfs_data<T>::calc_tangent_setup(), 946, D_0015A6D0);
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
    INTERP_ASSERT(count == 1 || count == 2, D_0015A6A8, kfs_data<T>::calc_tangent_setup(), 976);
    float dt = s0 + s1;
    INTERP_ASSERT(dt != 0.f, D_0015A6C4, kfs_data<T>::calc_tangent_setup(), 980);
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
            common::Log() << kfs_data<T>::insert_fn() << D_0015AB18;
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
        INTERP_ASSERT(_keys.size() > 0, D_0015AAF0, kfs_data<T>::insert(), 598);
        return _keys.size() - 1;
    }
    INTERP_ASSERT(_keys.size() > 1, D_0015AB04, kfs_data<T>::insert(), 607);
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


/* still asm */
template<> int interp::KeyFrameSequenceBase<math::quaternion>::insert(float, math::quaternion);
template<> interp::KeyFrame<math::quaternion>::KeyFrame();
template<> interp::KeyFrame<math::quaternion>::KeyFrame(float, math::quaternion, bool);
/* the disassembler put KeyFrame<quaternion>()'s start into this instance's .s: both stay asm */
extern template void VKq::_M_fill_insert(VKq::iterator, VKq::size_type, const KFq &);
/* the disassembler put these into dump<float>'s / _M_fill_insert<quaternion>'s .s (asm) */
extern template float interp::KeyFrameSequenceBase<float>::getLastTime() const;
extern template float interp::KeyFrameSequenceBase<float>::getKeyTime(int) const;
extern template void interp::KeyFrameSequenceBase<float>::setKeyTime(int, float);
extern template bool interp::KeyFrame<math::quaternion>::isClosingKey() const;
extern template VKq::iterator VKq::erase(VKq::iterator, VKq::iterator);
/* instances of later objects (interp_Path) */
extern template void interp::KeyFrameSequenceBase<float>::setKeyValue(int, float);
extern template void interp::KeyFrameSequenceBase<math::quaternion>::setKeyValue(int, math::quaternion);
extern template VKf &VKf::operator=(const VKf &);
extern template VKq &VKq::operator=(const VKq &);

/* interp instances this object holds: used from a discarded function (implicit instantiations) */
void CityApp_interp_instances() __attribute__((section(".discard.instances")));
void CityApp_interp_instances()
{
    typedef interp::HasPathInterface<interp::Path, math::Frame> HPf;
    typedef interp::HasPathInterface<interp::VectorRGBAnim, sh::VectorRGB> HPv;
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
    ((HPv *)0)->HPv::startRecordingPath();
    ((HPv *)0)->HPv::addRecord();
    ((HPv *)0)->HPv::deleteLastRecord();
    ((HPv *)0)->HPv::finishRecordingPath();
    ((const HPv *)0)->HPv::isRecordingPath();
    ((HPv *)0)->HPv::loadPath(*(std::string *)0);
    ((HPv *)0)->HPv::savePath(*(std::string *)0);
    ((HPv *)0)->HPv::evaluate(0);
    ((const HPv *)0)->HPv::pathSize();
    ((HPv *)0)->HPv::~HasPathInterface();
    /* called by the asm _M_fill_insert<quaternion> */
    std::__uninitialized_copy_aux((KFq *)0, (KFq *)0, (KFq *)0, __false_type());
    std::fill(VKq::iterator(), VKq::iterator(), *(const KFq *)0);
    std::__uninitialized_fill_n_aux((KFq *)0, 0u, *(const KFq *)0, __false_type());
    std::__uninitialized_copy_aux(VKq::iterator(), VKq::iterator(), (KFq *)0, __false_type());
    std::__uninitialized_fill_n_aux(VKq::iterator(), 0u, *(const KFq *)0, __false_type());
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setRelative(*(bool *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setClose(*(bool *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setCloseDt(*(float *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setRelative(*(bool *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setClose(*(bool *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setCloseDt(*(float *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::insert(*(float *)0);
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
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::evaluate_setup(*(float *)0, *(float *)0, *(float *)0, *(interp::KeyFrame<float> * *)0, *(interp::KeyFrame<float> * *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::evaluate_setup(*(float *)0, *(float *)0, *(math::quaternion *)0, *(interp::KeyFrame<math::quaternion> * *)0, *(interp::KeyFrame<math::quaternion> * *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::setKeyTime(*(int *)0, *(float *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::setKeyTime(*(int *)0, *(float *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::calc_tangent_setup(*(int *)0, *(float *)0, *(float *)0, *(float *)0, *(float *)0, *(float *)0);
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::calc_tangent_setup(*(int *)0, *(math::quaternion *)0, *(math::quaternion *)0, *(math::quaternion *)0, *(float *)0, *(float *)0);
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::insert(*(float *)0, *(float *)0);
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
    ((interp::KeyFrameSequenceBase<float> *)0)->interp::KeyFrameSequenceBase<float>::~KeyFrameSequenceBase();
    ((interp::KeyFrameSequenceBase<math::quaternion> *)0)->interp::KeyFrameSequenceBase<math::quaternion>::~KeyFrameSequenceBase();
}

/* asm (near-miss: cc1plus's frame is 16 bytes smaller) */
typedef std::vector<common::CmdLine::Option>::iterator OptionIt;
extern template OptionIt std::__uninitialized_copy_aux<OptionIt, OptionIt>(OptionIt, OptionIt, OptionIt, __false_type);
/* asm (near-miss: one branch delay slot filled differently near the end) */
extern template common::handle<scene::Transform> scene::Graph::newNode<scene::Transform>(std::string, bool);
/* asm: the start of Graph's map<const string, handle<Node> >::find is in the basic_string<char *> constructor's .s */
extern template scene::Graph::NodeMap::_Rep_type::iterator scene::Graph::NodeMap::_Rep_type::find(const std::string &);
/* asm: the basic_string<char *> range constructor's .s also holds _S_construct<char *> */
extern template std::string::basic_string(char *, char *, const std::allocator<char> &);
extern template char *std::string::_S_construct(char *, char *, const std::allocator<char> &, std::forward_iterator_tag);

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
    common::handle<scene::Object> j;
    ((scene::Graph::NodeMultiMap *)0)->find(*(const std::string *)0);
    /* called by the asm vector<handle<Car> >::_M_insert_aux (near-miss: two registers swapped) */
    typedef std::vector<common::handle<CityApp::Car> >::iterator CarIt;
    std::__uninitialized_copy_aux(CarIt(), CarIt(), CarIt(), __false_type());
    ((scene::Graph *)0)->getMappedNode<scene::Texture>(*(const std::string *)0);
    ((scene::Graph *)0)->getMappedNode<scene::Transform>(*(const std::string *)0);
    std::ostringstream os;
    os.str();
    /* the first function that inlines streambuf::_M_out_cur_move is the only one (cc1plus 3.3): the original
       stringbuf members call it */
    os.rdbuf()->sputc(0);
    common::handle<CityApp::Car> k;
}

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6common6handleIN7CityApp3CarEEESaIS4_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS4_S6_EERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSsC1IPcEET_S1_RKSaIcE);
CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", func_00008404, _ZNSsC1IPcEET_S1_RKSaIcE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common7CmdLine6OptionESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag);
CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", func_000087B4, _ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7glutils17AnimableTrackball3setEN4math5FrameE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK7glutils17AnimableTrackball3getEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common7CmdLine5TokenERSt6vectorISsSaISsEESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp3CarD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp3CarD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6interp16KeyFrameSequenceIfE4dumpEPKc);
CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", func_0000CD14, _ZNK6interp16KeyFrameSequenceIfE4dumpEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE17find_key_intervalEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16KeyFrameSequenceIfE8evaluateEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE17find_key_intervalEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIN4math10quaternionEE6insertEfS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS4_S6_EEjRKS4_);
CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", func_00012EB8, _ZNSt6vectorIN6interp8KeyFrameIN4math10quaternionEEESaIS4_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS4_S6_EEjRKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp8KeyFrameIN4math10quaternionEEC1EfS2_b);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN5scene5Graph7newNodeINS_9TransformEEEN6common6handleIT_EESsb);
