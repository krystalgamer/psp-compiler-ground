/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
/* Identity()'s 1.0f stays in the module's .rodata (asm) */
extern const float D_0015E748;
#define MATH_IDENTITY_ONE D_0015E748
#include "main.hpp"
#include "gl.hpp"

/* handle<> instances this object has as asm */
namespace common {
extern template class handle<scene::Node>;
extern template class handle<scene::Group>;
extern template class handle<scene::Switch>;
extern template class handle<scene::Texture>;
extern template class handle<scene::Object>;
extern template class handle<glutils::PositioningInterface>;
}

extern const char D_0015DCF0[];     /* " " */
extern const char D_0015DD00[];     /* "main.cpp" */
extern const char D_0015DD0C[];     /* " *** error " */
extern const char D_0015DF18[];     /* "_obj_switch->children().size() == 2" */
extern const char TestApp_switch_object_fn[] __asm__("_ZZN7TestApp13switch_objectEvE19__PRETTY_FUNCTION__");
extern const float D_0015E750;


INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _Z41__static_initialization_and_destruction_0ii_2D3C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestApp4initEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestApp15local_water_shlEv);

void TestApp::draw_all()
{
    draw_sink_background();
    if (draw_water_enabled)
        _water.prepareRefraction();
    if (draw_objects_enabled)
        draw_objects(false);
    if (draw_water_enabled)
        _water.draw((WaterPatch::Pass)0);
}

void TestApp::draw_sink_background()
{
    math::matrix m = _trackball.getTransform();
    math::matrix cam = getCamera()->getTransformInverse();
    _sink_background->traverse((scene::TraversalType)0, frustum(), m, math::matrix::Identity(), cam, _graph._light,
                               _f1538);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestApp12draw_objectsEb);

void TestApp::draw_environment()
{
    glPushAttrib(0x2000);
    glDisable(GL_LIGHTING);
    glPushMatrix();
    math::matrix m = _trackball.getTransform();
    glMultMatrixf(&m.r[0].x);
    if (!_vertex_color_env)
        _env.draw(_f1638);
    else
        _vce.draw(D_0015E750);
    glPopMatrix();
    glPopAttrib();
}

void TestApp::print_help() {
}

void TestApp::control() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestApp9envChangeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestApp14control_objectEv);

void TestApp::switch_object()
{
    SGL_ASSERT(_obj_switch->children().size() == 2, D_0015DD0C, D_0015DF18, D_0015DD00, TestApp_switch_object_fn, 0x2B5,
               D_0015DCF0);
    _obj_switch->select(1 - _obj_switch->getSelected());
    _object = _obj_switch->getChild();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestApp12dealWithMenuEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestApp4drawEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _Z9run_ahiruv);

extern "C" int main(void)
{
    menuInit();
    run_ahiru();
    return 0;
}

extern "C" {
void static_init_2D3C(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_2D3C");
void _GLOBAL__I___psp_moduleinfo(void);
void _GLOBAL__D___psp_moduleinfo(void);
}

void _GLOBAL__I___psp_moduleinfo(void)
{
    static_init_2D3C(1, 0xFFFF);
}

void _GLOBAL__D___psp_moduleinfo(void)
{
    static_init_2D3C(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestAppD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestAppD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene4NodeEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt6vectorISsSaISsEE9push_backERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt6vectorIN6common7CmdLine6OptionESaIS2_EE9push_backERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene5GroupEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene6ObjectEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene7TextureEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene7TextureEEaSERKS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene6SwitchEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN5scene5Group6searchIS0_EEN6common6handleIT_EERKSsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene5GroupEEaSERKS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene5GroupEEaSINS1_4NodeEEERS3_RKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN5scene5Graph7newNodeINS_6SwitchEEEN6common6handleIT_EESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene6SwitchEEaSERKS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN5scene5Graph13getMappedNodeINS_7TextureEEEN6common6handleIT_EERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN7glutils20PositioningInterfaceEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt6vectorISsSaISsEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPSsS1_EERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt6vectorIN6common7CmdLine6OptionESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN5scene5Graph13getMappedNodeINS_6SwitchEEEN6common6handleIT_EERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNKSt15basic_stringbufIcSt11char_traitsIcESaIcEE3strEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE17_M_stringbuf_initESt13_Ios_Openmode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ESt4lessIS0_ESaIS7_EE4findERS0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ENS2_7LessStrESaIS7_EE4findERS0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common7CmdLine6OptionESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSsC1IPcEET_S1_RKSaIcE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", func_0000AB74);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common15handle_internal10data_ownerD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common15handle_internal10data_ownerD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common15handle_internal10data_owner8set_dataEPNS0_4dataE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene4NodeEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common7CmdLine6OptionD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common7CmdLine6OptionC1ESsjPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common7CmdLine5TokenERSt6vectorISsSaISsEESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNK6common7CmdLine8find_argEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNK6common7CmdLine6inListEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common7CmdLine6defArgESsjPKc);

extern "C" const char D_0015E0CC[];
extern "C" const char D_0015E110[];
extern "C" const char D_0015E1A8[];
extern "C" const char D_0015E1EC[];
extern "C" const char D_0015E20C[];
extern "C" const char D_0015E24C[];
extern "C" const char D_0015E28C[];
extern "C" const char D_0015E2BC[];
extern "C" const char D_0015E2F4[];
extern "C" const char D_0015E32C[];
extern "C" const char D_0015E35C[];
extern "C" const char D_0015E394[];
extern "C" const char D_0015E3AC[];
extern "C" const char D_0015E3C8[];
extern "C" const char D_0015E3E4[];
extern "C" const char D_0015E69C[];
extern "C" const char D_0015DCF4[];

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

void sh::Args::Env::getArgs(common::CmdLine &cl)
{
    std::string t;
    get_arg(cl, D_0015E0CC, t);
    type = GetEnvType(t.c_str());
    get_arg(cl, D_0015E110, name);
    get_arg(cl, D_0015E1A8, exposure);
    get_arg(cl, D_0015E1EC, _fC);
    get_arg(cl, D_0015E20C, _f14);
    get_arg(cl, D_0015E24C, _f10);
    get_arg(cl, D_0015E28C, _f18);
    get_arg(cl, D_0015E2BC, _f20);
    get_arg(cl, D_0015E2F4, _f1C);
    get_arg(cl, D_0015E32C, dir);
    _f28 = cl.inList(D_0015E35C);
    get_arg(cl, D_0015E394, cube_size);
    get_arg(cl, D_0015E3AC, _f30);
    get_arg(cl, D_0015E3C8, _f34);
    get_arg(cl, D_0015E3E4, _f38);
    if (dir == D_0015E69C)
        dir = D_0015DCF4;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN3psp11DisplayList6finishEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene5GroupEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene4NodeEEC1INS1_5GroupEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene6ObjectEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene7TextureEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene6SwitchEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene4NodeEEC1INS1_6SwitchEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestAppC1EN2sh4Args6CommonE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestApp4turnEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene5GroupEEC1INS1_4NodeEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN7glutils20PositioningInterfaceEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene4NodeEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene5GroupEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene6ObjectEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene7TextureEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene6SwitchEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZTv0_n12_NSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene7TextureEEC1INS1_4NodeEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN7glutils20PositioningInterfaceEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZSt4findIN9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEEEPKcET_SA_SA_RKT0_St26random_access_iterator_tag);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common6handleIN5scene6SwitchEEC1INS1_4NodeEEERKNS0_IT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZTv0_n12_NSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE14_M_really_syncEjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE6setbufEPci);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE7seekoffElSt12_Ios_SeekdirSt13_Ios_Openmode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE7seekposESt4fposI9mbstate_tESt13_Ios_Openmode);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE9underflowEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE9pbackfailEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE8overflowEi);

extern "C" const char D_0015E6F8[]; /* "DEBUG" */
extern "C" const char D_0015E700[]; /* "debug" */
extern "C" const char D_0015E708[]; /* "SKY" */
extern "C" const char D_0015E70C[]; /* "sky" */
extern "C" const char D_0015E710[]; /* "HDR" */
extern "C" const char D_0015E714[]; /* "hdr" */
extern "C" const char D_0015E718[]; /* "TEX" */
extern "C" const char D_0015E71C[]; /* "tex" */

sh::Args::Env::Type sh::Args::Env::GetEnvType(std::string s)
{
    if (s == D_0015E6F8 || s == D_0015E700)
        return (Type)0;
    if (s == D_0015E708 || s == D_0015E70C)
        return (Type)1;
    if (s == D_0015E710 || s == D_0015E714)
        return (Type)3;
    if (s == D_0015E718 || s == D_0015E71C)
        return (Type)2;
    return (Type)0;
}

