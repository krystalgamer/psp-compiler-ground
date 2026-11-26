/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#include "../main.hpp"

/* the module's .ctors/.dtors (asm) refer to the static constructor/destructor,
   keyed to the first function (still asm: its wrapper's name + __asm) */
__asm__(".globl _GLOBAL__I__ZN4math14SphericalCoordC2Ev\n_GLOBAL__I__ZN4math14SphericalCoordC2Ev = _GLOBAL__I__ZN4math14SphericalCoordC2Ev__asm");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoordC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoordC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoordC2Eff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoordC1Eff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoord9setThetaDEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoord7setPhiDEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoord8setThetaEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoord6setPhiEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoord9incrThetaEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoord7incrPhiEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoord3setEff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoord5resetEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZNK4math14SphericalCoord15transformMatrixEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/math_SphericalCoord", _ZN4math14SphericalCoord14sync_directionEv);

