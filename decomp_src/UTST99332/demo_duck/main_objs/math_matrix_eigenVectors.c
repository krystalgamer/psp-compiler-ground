/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZNK4math6matrix12eigenVectorsEv\n_GLOBAL__I__ZNK4math6matrix12eigenVectorsEv = _GLOBAL__I__ZNK4math6matrix12eigenVectorsEv__asm");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_eigenVectors", _ZNK4math6matrix12eigenVectorsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_eigenVectors", _ZN5eigen5tred2EPA4_diPdS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_matrix_eigenVectors", _ZN5eigen4tqliEPdS0_iPA4_d);

/* the object's instance (eigen::tred2/tqli, still asm, use it) */
namespace math {
template<class T> T sqr(T x)
{
    return x * x;
}
}
template double math::sqr<double>(double);
