/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"
#include <fstream>

extern const char D_0017432C[];     /* " " */
extern const char D_00174330[];     /* "\n" */
extern const char D_00174334[];     /* "coeff_size=" */
extern const char D_00174340[];     /* "red\n" */
extern const char D_00174348[];     /* "green\n" */
extern const char D_00174350[];     /* "blue\n" */
extern const char D_00174398[];     /* " *** error " */
extern const char D_0017446C[];     /* "i == math::SH::N(_maxL)" */
extern const char D_00174484[];     /* "../lib/sh/Vector_1.h" */
extern const char eval_name[] __asm__("_ZZNK2sh6Vector4evalEffiE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Vector", _Z41__static_initialization_and_destruction_0ii_F50B4);

void sh::Vector::print(const char *name) const
{
    std::cout << name;
    for (int i = 0; i != COEFFS; i++)
        std::cout << v[i] << D_0017432C;
    std::cout << D_00174330;
    std::cout.flush();
}

void sh::VectorRGB::eval(float theta, float phi, float &red, float &green, float &blue) const
{
    red = r.eval(theta, phi, -1);
    green = g.eval(theta, phi, -1);
    blue = b.eval(theta, phi, -1);
}

void sh::VectorRGB::save(const char *name)
{
    std::fstream f(name, std::ios::out);
    if (!f.is_open())
        return;
    f << D_00174334 << (unsigned int)COEFFS << D_00174330;
    f << D_00174340;
    for (int i = 0; i != COEFFS; i++)
        f << r.v[i] << D_0017432C;
    f << D_00174330;
    f << D_00174348;
    for (int i = 0; i != COEFFS; i++)
        f << g.v[i] << D_0017432C;
    f << D_00174330;
    f << D_00174350;
    for (int i = 0; i != COEFFS; i++)
        f << b.v[i] << D_0017432C;
    f << D_00174330;
    f.close();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sh_Vector", _ZN2sh9VectorRGB4loadEPKc);

void sh::VectorRGB::print(const char *) const {
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_F50B4");
void _GLOBAL__I__ZNK2sh6Vector5printEPKc(void);
void _GLOBAL__D__ZNK2sh6Vector5printEPKc(void);
}

void _GLOBAL__I__ZNK2sh6Vector5printEPKc(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZNK2sh6Vector5printEPKc(void)
{
    static_init(0, 0xFFFF);
}

float sh::Vector::eval(float theta, float phi, int maxL) const
{
    if ((unsigned int)maxL > BANDS - 1)
        maxL = BANDS - 1;
    float sum = 0;
    int i = 0;
    for (int l = 0; l <= maxL; l++)
        for (int m = -l; m <= l; m++, i++)
            sum += v[i] * SH_Eval(l, m, theta, phi);
    SGL_ASSERT(i == math::SH::N(maxL), D_00174398, D_0017446C, D_00174484, eval_name, 189, D_0017432C);
    return sum;
}
