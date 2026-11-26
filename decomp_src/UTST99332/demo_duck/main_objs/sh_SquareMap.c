/* lang: c++ */
/* cflags: -O3 -fno-exceptions -fmerge-constants */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN2sh9SquareMapC2EPKcf");
__asm__(".globl _GLOBAL__D__ZN2sh9SquareMapC2EPKcf");
/* other objects' asm has %lo(D_001740C8) for %lo(std::endl) (0x1340C8, mispaired by splat);
   the label pointed into this object's .rodata */
__asm__(".globl D_001740C8\nD_001740C8 = 0x001740C8");

sh::SquareMap::SquareMap(const char *name, float exposure) : _exposure(exposure)
{
    Log_float(common::Log() << "SquareMap " << name << "'s exposure=", exposure) << "\n";
    load(name);
}

void sh::SquareMap::eval(float theta, float phi, float &r, float &g, float &b) const
{
    static const float INV255 = 1.0f / 255.0f;
    if (!_tex.valid())
        return;
    theta = math_wrap(theta, 0, M_PI);
    phi = math_wrap(phi, 0, 2 * M_PI);
    float u = phi / (float)(2 * M_PI);
    float v = theta / (float)M_PI;
    int x = math_min_i(_tex.width() - 1, (int)(_tex.width() * u));
    int y = math_min_i(_tex.height() - 1, (int)(_tex.height() * (1 - v)));
    const unsigned int *data = (const unsigned int *)_tex.image.addr();
    unsigned int c = data[x + y * _tex.width()];
    r = (int)(c & 0xFF) * INV255;
    g = (int)((c >> 8) & 0xFF) * INV255;
    b = (int)((c >> 16) & 0xFF) * INV255;
}

void sh::SquareMap::load(const char *name)
{
    if (name && *name) {
        _tex.load(name);
        if (_tex.valid())
            _tex.convert32();
    }
}

/* weak instances: after _GLOBAL__I/D */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_WEAK

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SquareMap", _ZN2sh9SquareMapD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_SquareMap", _ZN2sh9SquareMapD0Ev);
