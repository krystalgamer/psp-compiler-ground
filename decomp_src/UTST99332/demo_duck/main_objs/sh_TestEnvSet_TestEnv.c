/* lang: c++ */
/* cflags: -O3 -fno-exceptions -fno-merge-constants */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_TEMPLATE_DEFS
#define SGL_LINKONCE_TestEnv 1
#include <iostream>
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN2sh10TestEnvSet7TestEnvC2ENS0_7EnvEnumENS_4Args3EnvE");
__asm__(".globl _GLOBAL__D__ZN2sh10TestEnvSet7TestEnvC2ENS0_7EnvEnumENS_4Args3EnvE");

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN6common5setAtISt6vectorINS_6handleIN2sh10TestEnvSet7TestEnvEEESaIS6_EEPS5_EEvjRT_T0_)
    DEMO_LINKONCE(_ZN6common6handleIN2sh10TestEnvSet7TestEnvEE10invalidateEv)
    DEMO_LINKONCE(_ZN6common6handleIN2sh10TestEnvSet7TestEnvEEaSERKS4_)
    DEMO_LINKONCE(_ZNSt6vectorIN6common6handleIN2sh10TestEnvSet7TestEnvEEESaIS5_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS5_S7_EESB_)
    DEMO_LINKONCE(_ZNSt6vectorIN6common6handleIN2sh10TestEnvSet7TestEnvEEESaIS5_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS5_S7_EEjRKS5_)
    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN6common6handleIN2sh10TestEnvSet7TestEnvEEESt6vectorIS7_SaIS7_EEEES7_EvT_SD_RKT0_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN6common6handleIN2sh10TestEnvSet7TestEnvEEES6_ET0_T_S8_S7_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN6common6handleIN2sh10TestEnvSet7TestEnvEEEjS5_ET_S7_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common6handleIN2sh10TestEnvSet7TestEnvEEESt6vectorIS7_SaIS7_EEEES8_ET0_T_SE_SD_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common6handleIN2sh10TestEnvSet7TestEnvEEESt6vectorIS7_SaIS7_EEEESC_ET0_T_SE_SD_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN6common6handleIN2sh10TestEnvSet7TestEnvEEESt6vectorIS7_SaIS7_EEEEjS7_ET_SD_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZN2sh10TestEnvSet7TestEnvD1Ev)
    DEMO_LINKONCE(_ZN2sh10TestEnvSet7TestEnvD0Ev)
    DEMO_LINKONCE(_ZN6common6handleIN2sh10TestEnvSet7TestEnvEED1Ev)
    DEMO_LINKONCE(_ZN6common6handleIN2sh10TestEnvSet7TestEnvEED0Ev)
);

namespace {
extern "C" const char D_00174178[], D_00174190[], D_001741A8[], D_001741C0[], D_001741CC[], D_001741D4[], D_001741DC[];
extern "C" const char D_00174200[], D_0017420C[], D_00174228[], D_00174244[], D_00174248[], D_00174270[];
}
extern const char load_name[] __asm__("_ZZN2sh10TestEnvSet4loadEvE19__PRETTY_FUNCTION__");
extern const char draw_name[] __asm__("_ZZN2sh10TestEnvSet4drawEbE19__PRETTY_FUNCTION__");

#define TES_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_00174200, text, D_00174228, fn, line, D_00174244)

/* setAt<> stays asm (near-miss: register allocation); the vector members it calls are this object's */
typedef std::vector<common::handle<sh::TestEnvSet::TestEnv> > TestEnvHandles;
namespace common {
extern template void setAt(unsigned int, TestEnvHandles &, sh::TestEnvSet::TestEnv *);
}
sh::TestEnvSet::TestEnv::TestEnv(EnvEnum type, Args::Env args) : _env(args), _type(type), _loaded(false)
{
}

/* after the first public function: the static constructor is keyed to TestEnv() */
extern "C" void TestEnvHandles_resize(TestEnvHandles &v, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void TestEnvHandles_resize(TestEnvHandles &v, unsigned int n) { v.resize(n); }

void sh::TestEnvSet::TestEnv::load()
{
    _env.load(!_loaded);
    _loaded = true;
}

sh::TestEnvSet::TestEnvSet(Args::Env args, EnvEnum e) : _current_light(e)
{
    _lights.resize(MAX_ENV);
    args.type = (Args::Env::Type)3;
    args.name = D_00174178;
    args.exposure = 350;
    common::setAt(2, _lights, new TestEnv((EnvEnum)2, args));
    args.type = (Args::Env::Type)3;
    args.name = D_00174190;
    args.exposure = 0.9f;
    common::setAt(3, _lights, new TestEnv((EnvEnum)3, args));
    args.type = (Args::Env::Type)3;
    args.name = D_001741A8;
    args.exposure = 0.6f;
    common::setAt(4, _lights, new TestEnv((EnvEnum)4, args));
    args.type = (Args::Env::Type)2;
    args.name = D_001741C0;
    args.exposure = -1;
    common::setAt(5, _lights, new TestEnv((EnvEnum)5, args));
    args.type = (Args::Env::Type)0;
    args.name = D_001741CC;
    args.exposure = 0;
    common::setAt(6, _lights, new TestEnv((EnvEnum)6, args));
    args.type = (Args::Env::Type)1;
    args.name = D_001741D4;
    args.exposure = 2.5f;
    common::setAt(1, _lights, new TestEnv((EnvEnum)1, args));
    args.type = (Args::Env::Type)1;
    args.name = D_001741DC;
    args.exposure = 100;
    common::setAt(0, _lights, new TestEnv((EnvEnum)0, args));
}

void sh::TestEnvSet::load()
{
    TES_ASSERT(_current_light < MAX_ENV, D_0017420C, load_name, 88);
    TES_ASSERT(_current_light < (int)_lights.size(), D_00174248, load_name, 89);
    TES_ASSERT(0 <= _current_light, D_00174270, load_name, 90);
    _lights[_current_light]->load();
}

void sh::TestEnvSet::next()
{
    _current_light = _current_light + 1 < MAX_ENV ? _current_light + 1 : 0;
    load();
}

void sh::TestEnvSet::draw(bool b)
{
    TES_ASSERT(_current_light < MAX_ENV, D_0017420C, draw_name, 109);
    _lights[_current_light]->_env.draw(!b);
}

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_TestEnvSet_TestEnv", _ZN6common5setAtISt6vectorINS_6handleIN2sh10TestEnvSet7TestEnvEEESaIS6_EEPS5_EEvjRT_T0_);
