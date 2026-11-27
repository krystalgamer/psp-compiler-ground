/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define SGL_LINKONCE_FunctionEvaluator 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN2sh3EnvC2ENS_4Args3EnvE");
__asm__(".globl _GLOBAL__D__ZN2sh3EnvC2ENS_4Args3EnvE");

extern "C" const char D_001722EC[], D_001722F0[], D_001722F4[], D_001722FC[], D_00172310[], D_00172314[];
extern const char Env_dtor_name[] __asm__("_ZZN2sh3EnvD1EvE19__PRETTY_FUNCTION__");

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

/* inline members: .gnu.linkonce.t, after FunctionEvaluator's and CIEClearSky's dtors (splat only sees `INCLUDE_ASM(`) */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Env", _ZNK2sh11CIEClearSky4evalEffRfS1_S1_);
