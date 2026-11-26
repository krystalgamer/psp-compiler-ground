/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN2sh6MatrixC2Ev");
__asm__(".globl _GLOBAL__D__ZN2sh6MatrixC2Ev");





sh::Matrix::Matrix() {
}

const sh::Matrix &sh::Matrix::Identity()
{
    static Matrix retval;
    static bool init = false;
    if (!init) {
        init = true;
        for (unsigned int i = 0; i < COEFFS; i++)
            for (unsigned int j = 0; j < COEFFS; j++)
                retval.m[j][i] = (j == i) ? 1.0f : 0.0f;
    }
    return retval;
}

sh::Vector sh::Matrix::operator*(const Vector &v) const
{
    Vector r;
    for (unsigned int i = 0; i < COEFFS; i++) {
        r.v[i] = 0;
        for (unsigned int j = 0; j < COEFFS; j++)
            r.v[i] += v.v[j] * m[i][j];
    }
    return r;
}

sh::Matrix sh::Matrix::transpose() const
{
    Matrix r;
    for (unsigned int i = 0; i < COEFFS; i++)
        for (unsigned int j = 0; j < COEFFS; j++)
            r.m[j][i] = m[i][j];
    return r;
}

bool sh::Matrix::equal(Matrix o, float eps) const
{
    for (unsigned int i = 0; i < COEFFS; i++)
        for (unsigned int j = 0; j < COEFFS; j++)
            if (fabsf(o.m[j][i] - m[j][i]) > eps)
                return false;
    return true;
}

void sh::Matrix::print(bool symbolic) const
{
    std::cout << std::endl;
    for (unsigned int i = 0; i < COEFFS; i++) {
        for (unsigned int j = 0; j < COEFFS; j++) {
            float f = m[i][j];
            if (!symbolic)
                std::cout << f << "\t";
            else if (f == 1)
                std::cout << " 1";
            else if (f == -1)
                std::cout << "-1";
            else if (f == 0)
                std::cout << " 0";
            else if (f == -666)
                std::cout << " .";
            else
                std::cout << " x";
            std::cout << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
