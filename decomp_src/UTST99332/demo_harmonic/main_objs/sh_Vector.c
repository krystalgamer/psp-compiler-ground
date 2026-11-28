/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZNK2sh6Vector5printEPKc");
__asm__(".globl _GLOBAL__D__ZNK2sh6Vector5printEPKc");
#include <fstream>


void sh::Vector::print(const char *name) const
{
    std::cout << name;
    for (int i = 0; i != COEFFS; i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
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
    f << "coeff_size=" << (unsigned int)COEFFS << "\n";
    f << "red\n";
    for (int i = 0; i != COEFFS; i++)
        f << r.v[i] << " ";
    f << "\n";
    f << "green\n";
    for (int i = 0; i != COEFFS; i++)
        f << g.v[i] << " ";
    f << "\n";
    f << "blue\n";
    for (int i = 0; i != COEFFS; i++)
        f << b.v[i] << " ";
    f << "\n";
    f.close();
}

/* STAND-IN: float pointer view (first element folded into this+off, the rest through the row base register,
   as for the other array-based vector types) */
static inline void shv_zero(sh::Vector &v)
{
    float *p = &v[0];
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
}
#define SHV_ASSERT(c, t, l) SGL_ASSERT(c, " *** error ", t, "../lib/sh/Vector.cpp", __PRETTY_FUNCTION__, l, " ")
void sh::VectorRGB::load(const char *name)
{
    basic_file_parser parser(name, 2048, " \t\b\r\n[]:=");
    if (!parser.ready())
        return;
    parser.step();
    SHV_ASSERT(parser.is_equal("coeff_size"), "parser.is_equal(\"coeff_size\")", 92);
    parser.step();
    unsigned int n = parser.get<unsigned int>();
    shv_zero(r);
    shv_zero(g);
    shv_zero(b);
    parser.step();
    SHV_ASSERT(parser.is_equal("red"), "parser.is_equal(\"red\")", 102);
    for (unsigned int i = 0; i != n; i++) {
        parser.step();
        if (i < COEFFS)
            r[i] = parser.get<float>();
    }
    parser.step();
    SHV_ASSERT(parser.is_equal("green"), "parser.is_equal(\"green\")", 117);
    for (unsigned int i = 0; i != n; i++) {
        parser.step();
        if (i < COEFFS)
            g[i] = parser.get<float>();
    }
    parser.step();
    SHV_ASSERT(parser.is_equal("blue"), "parser.is_equal(\"blue\")", 130);
    for (unsigned int i = 0; i != n; i++) {
        parser.step();
        if (i < COEFFS)
            b[i] = parser.get<float>();
    }
}

void sh::VectorRGB::print(const char *) const {
}

/* inline in the class (weak copy in the object's tail; defined last: its strings follow the other functions') */
SGL_LINKONCE_BEGIN
inline float sh::Vector::eval(float theta, float phi, int maxL) const
{
    if ((unsigned int)maxL > BANDS - 1)
        maxL = BANDS - 1;
    float sum = 0;
    int i = 0;
    for (int l = 0; l <= maxL; l++)
        for (int m = -l; m <= l; m++, i++)
            sum += v[i] * SH_Eval(l, m, theta, phi);
    SGL_ASSERT(i == math::SH::N(maxL), " *** error ", "i == math::SH::N(_maxL)", "../lib/sh/Vector_1.h", __PRETTY_FUNCTION__, 189, " ");
    return sum;
}
SGL_LINKONCE_END
