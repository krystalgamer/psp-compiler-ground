/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" const char D_001722EC[], D_001722F0[], D_001722F4[], D_001722FC[], D_00172310[], D_00172314[];
extern const char Env_dtor_name[] __asm__("_ZZN2sh3EnvD1EvE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Env", _Z41__static_initialization_and_destruction_0ii_D9170);

sh::Env::Env(Args::Env args) : _args(args)
{
    switch (_args.type) {
    case 0:
        if (_args.name.empty())
            _args.name = D_001722F4;
        break;
    case 1:
        if (_args.name.empty())
            _args.name = D_001722FC;
        break;
    case 2:
        break;
    }
    if (!_args.dir.empty()) {
        std::string path(_args.dir);
        if (path.c_str()[path.length() - 1] != '/')
            path += D_001722F0;
        path += _args.name;
        _args.name = path;
    }
    std::string name(_args.name);
    std::string sh_name(_args.name);
    sh_name += D_001722EC;
    _cube.setBasename(_args.name.c_str());
    _cube_blur.setBasename(sh_name.c_str());
    _cube.setCubeSize(_args.cube_size);
}

sh::Env::~Env()
{
    common::Log() << Env_dtor_name << D_00172310 << _args.name.c_str() << D_00172314;
}

void sh::Env::draw(bool b)
{
    if (b)
        _cube.draw(false);
    else
        _cube_blur.draw(false);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Env", _ZN2sh3Env4loadEb);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_D9170");
void _GLOBAL__I__ZN2sh3EnvC2ENS_4Args3EnvE(void);
void _GLOBAL__D__ZN2sh3EnvC2ENS_4Args3EnvE(void);
}

void _GLOBAL__I__ZN2sh3EnvC2ENS_4Args3EnvE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN2sh3EnvC2ENS_4Args3EnvE(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Env", _ZNK2sh17FunctionEvaluator4evalEffRfS1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Env", _ZN2sh17FunctionEvaluatorD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Env", _ZN2sh17FunctionEvaluatorD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Env", _ZN2sh11CIEClearSkyD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Env", _ZN2sh11CIEClearSkyD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Env", _ZNK2sh11CIEClearSky4evalEffRfS1_S1_);

