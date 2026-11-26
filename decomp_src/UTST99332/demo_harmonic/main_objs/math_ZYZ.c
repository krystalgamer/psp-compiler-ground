/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#include "../main.hpp"

/* the module's .ctors/.dtors (asm) refer to the static constructor/destructor,
   keyed to the first function (still asm: its wrapper's name + __asm) */
__asm__(".globl _GLOBAL__I__ZNK4math3ZYZ15transformMatrixEv\n_GLOBAL__I__ZNK4math3ZYZ15transformMatrixEv = _GLOBAL__I__ZNK4math3ZYZ15transformMatrixEv__asm");

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/math_ZYZ", _ZNK4math3ZYZ15transformMatrixEv);

