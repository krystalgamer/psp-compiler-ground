/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
/* Identity()'s 1.0f stays in the module's .rodata (asm) */
extern const float D_0015E748;
#define MATH_IDENTITY_ONE D_0015E748
#define DEMO_TEMPLATE_DEFS
#define DEMO_LINKONCE_data_owner 1
#include "main.hpp"

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN7TestAppD0Ev)
    DEMO_LINKONCE(_ZN7TestAppD1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene4NodeEE10invalidateEv)
    DEMO_LINKONCE(_ZNSt6vectorISsSaISsEE9push_backERKSs)
    DEMO_LINKONCE(_ZNSt6vectorIN6common7CmdLine6OptionESaIS2_EE9push_backERKS2_)
    DEMO_LINKONCE(_ZN6common6handleIN5scene5GroupEE10invalidateEv)
    DEMO_LINKONCE(_ZN6common6handleIN5scene6ObjectEE10invalidateEv)
    DEMO_LINKONCE(_ZN6common6handleIN5scene7TextureEE10invalidateEv)
    DEMO_LINKONCE(_ZN6common6handleIN5scene7TextureEEaSERKS3_)
    DEMO_LINKONCE(_ZN6common6handleIN5scene6SwitchEE10invalidateEv)
    DEMO_LINKONCE(_ZN5scene5Group6searchIS0_EEN6common6handleIT_EERKSsb)
    DEMO_LINKONCE(_ZN6common6handleIN5scene5GroupEEaSERKS3_)
    DEMO_LINKONCE(_ZN6common6handleIN5scene5GroupEEaSINS1_4NodeEEERS3_RKNS0_IT_EE)
    DEMO_LINKONCE(_ZN5scene5Graph7newNodeINS_6SwitchEEEN6common6handleIT_EESsb)
    DEMO_LINKONCE(_ZN6common6handleIN5scene6SwitchEEaSERKS3_)
    DEMO_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_7TextureEEEN6common6handleIT_EERKSs)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils20PositioningInterfaceEE10invalidateEv)
    DEMO_LINKONCE(_ZNSt6vectorISsSaISsEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPSsS1_EERKSs)
    DEMO_LINKONCE(_ZNSt6vectorIN6common7CmdLine6OptionESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_)
    DEMO_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_6SwitchEEEN6common6handleIT_EERKSs)
    DEMO_LINKONCE(_ZNKSt15basic_stringbufIcSt11char_traitsIcESaIcEE3strEv)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE17_M_stringbuf_initESt13_Ios_Openmode)
    DEMO_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ESt4lessIS0_ESaIS7_EE4findERS0_)
    DEMO_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ENS2_7LessStrESaIS7_EE4findERS0_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common7CmdLine6OptionESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type)
    DEMO_LINKONCE(_ZNSsC1IPcEET_S1_RKSaIcE)
    DEMO_LINKONCE(_ZNSs12_S_constructIPcEES0_T_S1_RKSaIcESt20forward_iterator_tag)
    DEMO_LINKONCE(_ZN6common15handle_internal10data_ownerD1Ev)
    DEMO_LINKONCE(_ZN6common15handle_internal10data_ownerD0Ev)
    DEMO_LINKONCE(_ZN6common15handle_internal10data_owner8set_dataEPNS0_4dataE)
    DEMO_LINKONCE(_ZN6common6handleIN5scene4NodeEED1Ev)
    DEMO_LINKONCE(_ZN6common7CmdLine6OptionD1Ev)
    DEMO_LINKONCE(_ZN6common7CmdLine6OptionC1ESsjPKc)
    DEMO_LINKONCE(_ZN6common7CmdLine5TokenERSt6vectorISsSaISsEESs)
    DEMO_LINKONCE(_ZNK6common7CmdLine8find_argEPKc)
    DEMO_LINKONCE(_ZNK6common7CmdLine6inListEPKc)
    DEMO_LINKONCE(_ZN6common7CmdLine6defArgESsjPKc)
    DEMO_LINKONCE(_ZN2sh4Args3Env7getArgsERN6common7CmdLineE)
    DEMO_LINKONCE(_ZN3psp11DisplayList6finishEb)
    DEMO_LINKONCE(_ZN6common6handleIN5scene5GroupEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_5GroupEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZN6common6handleIN5scene6ObjectEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene7TextureEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene6SwitchEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_6SwitchEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZN7TestAppC1EN2sh4Args6CommonE)
    DEMO_LINKONCE(_ZN7TestApp4turnEf)
    DEMO_LINKONCE(_ZN6common6handleIN5scene5GroupEEC1INS1_4NodeEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils20PositioningInterfaceEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene4NodeEED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene5GroupEED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene6ObjectEED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene7TextureEED0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene6SwitchEED0Ev)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED0Ev)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEED1Ev)
    DEMO_LINKONCE(_ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev)
    DEMO_LINKONCE(_ZTv0_n12_NSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN5scene7TextureEEC1INS1_4NodeEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZN6common6handleIN7glutils20PositioningInterfaceEED0Ev)
    DEMO_LINKONCE(_ZSt4findIN9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEEEPKcET_SA_SA_RKT0_St26random_access_iterator_tag)
    DEMO_LINKONCE(_ZN6common6handleIN5scene6SwitchEEC1INS1_4NodeEEERKNS0_IT_EE)
    DEMO_LINKONCE(_ZNSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED0Ev)
    DEMO_LINKONCE(_ZTv0_n12_NSt19basic_ostringstreamIcSt11char_traitsIcESaIcEED0Ev)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE14_M_really_syncEjj)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE6setbufEPci)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE7seekoffElSt12_Ios_SeekdirSt13_Ios_Openmode)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE7seekposESt4fposI9mbstate_tESt13_Ios_Openmode)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE9underflowEv)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE9pbackfailEi)
    DEMO_LINKONCE(_ZNSt15basic_stringbufIcSt11char_traitsIcESaIcEE8overflowEi)
    DEMO_LINKONCE(_ZN2sh4Args3Env10GetEnvTypeESs)
);
#include "gl.hpp"
#include <sstream>

/* handle<> instances this object has as asm */
namespace common {
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

SGL_LINKONCE_BEGIN
inline void sh::Args::Env::getArgs(common::CmdLine &cl)
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
SGL_LINKONCE_END

extern "C" const char D_0015E6F8[]; /* "DEBUG" */
extern "C" const char D_0015E700[]; /* "debug" */
extern "C" const char D_0015E708[]; /* "SKY" */
extern "C" const char D_0015E70C[]; /* "sky" */
extern "C" const char D_0015E710[]; /* "HDR" */
extern "C" const char D_0015E714[]; /* "hdr" */
extern "C" const char D_0015E718[]; /* "TEX" */
extern "C" const char D_0015E71C[]; /* "tex" */

SGL_LINKONCE_BEGIN
inline sh::Args::Env::Type sh::Args::Env::GetEnvType(std::string s)
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
SGL_LINKONCE_END

/* asm: the basic_string<char *> range constructor's .s also holds _S_construct<char *> */
extern template std::string::basic_string(char *, char *, const std::allocator<char> &);
extern template char *std::string::_S_construct(char *, char *, const std::allocator<char> &, std::forward_iterator_tag);

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

/* template instances of this object that only its asm functions use: called from here (a discarded function) so
   that cc1plus emits them (their order is DEMO_LINKONCE_ORDER's) */
extern "C" void main_instance_refs(common::handle<scene::Node> &n, common::handle<scene::Group> &g,
                                   common::handle<scene::Switch> &sw, common::handle<scene::Texture> &t,
                                   common::handle<scene::Object> &o, std::vector<std::string> &v)
    __attribute__((section(".discard.asm")));
extern "C" void main_instance_refs(common::handle<scene::Node> &n, common::handle<scene::Group> &g,
                                   common::handle<scene::Switch> &sw, common::handle<scene::Texture> &t,
                                   common::handle<scene::Object> &o, std::vector<std::string> &v)
{
    o.invalidate();
    t.invalidate();
    t = t;
    sw.invalidate();
    g = g;
    sw = sw;
    v.push_back(std::string());
    common::handle<scene::Node> a(g), b(sw);
    common::handle<scene::Group> c(n);
    common::handle<scene::Texture> d(n);
    common::handle<scene::Switch> e(n);
    common::handle<scene::Object> f;
    std::ostringstream os;
    os.str();
    /* the first function that inlines streambuf::_M_out_cur_move is the only one (cc1plus 3.3): the original
       stringbuf members call it */
    os.rdbuf()->sputc(0);
}

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestAppD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestAppD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt6vectorISsSaISsEE9push_backERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt6vectorIN6common7CmdLine6OptionESaIS2_EE9push_backERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN5scene5Group6searchIS0_EEN6common6handleIT_EERKSsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN5scene5Graph7newNodeINS_6SwitchEEEN6common6handleIT_EESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN5scene5Graph13getMappedNodeINS_7TextureEEEN6common6handleIT_EERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt6vectorIN6common7CmdLine6OptionESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN5scene5Graph13getMappedNodeINS_6SwitchEEEN6common6handleIT_EERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ESt4lessIS0_ESaIS7_EE4findERS0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ENS2_7LessStrESaIS7_EE4findERS0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common7CmdLine6OptionESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZNSsC1IPcEET_S1_RKSaIcE);
CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", func_0000AB74, _ZNSsC1IPcEET_S1_RKSaIcE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common7CmdLine6OptionD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common7CmdLine6OptionC1ESsjPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common7CmdLine5TokenERSt6vectorISsSaISsEESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN6common7CmdLine6defArgESsjPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN3psp11DisplayList6finishEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestAppC1EN2sh4Args6CommonE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZN7TestApp4turnEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main", _ZSt4findIN9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEEEPKcET_SA_SA_RKT0_St26random_access_iterator_tag);
