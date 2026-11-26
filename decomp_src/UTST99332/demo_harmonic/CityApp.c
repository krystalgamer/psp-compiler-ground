/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "main.hpp"

/* the strings stay in the module's .rodata (asm) */
extern const char D_00159984[];     /* "load test env\n" */
extern const char D_00159994[];     /* "apply env change\n" */

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp17light_source_idleEv);

float CityApp::get_anim_time() const
{
    return _anim_time;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK7CityApp19get_light_transformEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp16draw_scene_graphEv);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN7CityApp20cycle_depth_settingsEv);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene4NodeEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene5GroupEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene6ObjectEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene7TextureEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene9TransformEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6common7CmdLine6OptionESaIS2_EE9push_backERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN7CityApp3CarEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN5scene5Graph7newNodeINS_9TransformEEEN6common6handleIT_EESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene9TransformEEaSERKS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNKSt15basic_stringbufIcSt11char_traitsIcESaIcEE3strEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN7glutils20PositioningInterfaceEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN5scene5Graph13getMappedNodeINS_7TextureEEEN6common6handleIT_EERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN7glutils9TurnTableEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6common7CmdLine6OptionESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6common6handleIN7CityApp3CarEEESaIS4_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS4_S6_EERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN5scene5Graph13getMappedNodeINS_9TransformEEEN6common6handleIT_EERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE17_M_stringbuf_initESt13_Ios_Openmode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN7CityApp3CarEEaSERKS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSsC1IPcEET_S1_RKSaIcE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", func_00008404);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ENS2_7LessStrESaIS7_EE4findERS0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common7CmdLine6OptionESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common6handleIN7CityApp3CarEEESt6vectorIS6_SaIS6_EEEESB_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", func_000087B4);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene4NodeEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene5GroupEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene4NodeEEC1INS1_5GroupEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene6ObjectEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene4NodeEEC1INS1_6ObjectEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene7TextureEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene9TransformEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene4NodeEEC1INS1_9TransformEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common7CmdLine6OptionD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common7CmdLine6OptionC1ESsjPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common7CmdLine5TokenERSt6vectorISsSaISsEESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6common7CmdLine8find_argEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common7CmdLineC1ESsSsSsSsSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNK6common7CmdLine6inListEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common7CmdLine6defArgESsjPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN2sh4Args3Env7getArgsERN6common7CmdLineE);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene5GroupEEC1INS1_4NodeEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN7glutils20PositioningInterfaceEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN7glutils9TurnTableEEC1INS1_20PositioningInterfaceEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN7glutils9TurnTableEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEE8evaluateEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEE8evaluateEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_4PathEN4math5FrameEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene4NodeEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene5GroupEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene6ObjectEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene7TextureEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene9TransformEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16HasPathInterfaceINS_13VectorRGBAnimEN2sh9VectorRGBEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN7CityApp3CarEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZTv0_n12_NSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN7glutils20PositioningInterfaceEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene7TextureEEC1INS1_4NodeEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN7glutils9TurnTableEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorISsSaISsEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPSsS1_EERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt4findIN9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEEEPKcET_SA_SA_RKT0_St26random_access_iterator_tag);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16KeyFrameSequenceIfED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp16KeyFrameSequenceIfED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6common6handleIN5scene9TransformEEC1INS1_4NodeEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE14_M_really_syncEjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_12__false_type);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", func_0000CD14);

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

template<> void interp::KeyFrameSequence<float>::typed_fix()
{
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN6interp20KeyFrameSequenceBaseIfE18makeConsistantWithEPKNS_23VirtualKeyFrameSequenceE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZNSt6vectorIN6interp8KeyFrameIfEESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", _ZN2sh4Args3Env10GetEnvTypeESs);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/CityApp", func_00012EB8);

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

