/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_eigenVectors", _Z41__static_initialization_and_destruction_0ii_52538);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_eigenVectors", _ZNK4math6matrix12eigenVectorsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_eigenVectors", _ZN5eigen5tred2EPA4_diPdS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_eigenVectors", _ZN5eigen4tqliEPdS0_iPA4_d);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_52538");
void _GLOBAL__I__ZNK4math6matrix12eigenVectorsEv(void);
}

void _GLOBAL__I__ZNK4math6matrix12eigenVectorsEv(void)
{
    static_init(1, 0xFFFF);
}

/* the object's instance (eigen::tred2/tqli, still asm, use it) */
namespace math {
template<class T> T sqr(T x)
{
    return x * x;
}
}
template double math::sqr<double>(double);

