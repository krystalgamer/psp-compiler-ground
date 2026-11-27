/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN2sh14VerticesVector4loadESs\n_GLOBAL__I__ZN2sh14VerticesVector4loadESs = _GLOBAL__I__ZN2sh14VerticesVector4loadESs__asm");
__asm__(".globl _GLOBAL__D__ZN2sh14VerticesVector4loadESs\n_GLOBAL__D__ZN2sh14VerticesVector4loadESs = _GLOBAL__D__ZN2sh14VerticesVector4loadESs__asm");

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_VerticesVector", _ZN2sh14VerticesVector4loadESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sh_VerticesVector", _ZN2sh14VerticesVector4saveESs);
