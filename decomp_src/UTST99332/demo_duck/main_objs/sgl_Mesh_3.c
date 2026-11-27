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
__asm__(".globl _GLOBAL__I__ZN3sgl4Mesh4saveEPKcSsbf\n_GLOBAL__I__ZN3sgl4Mesh4saveEPKcSsbf = _GLOBAL__I__ZN3sgl4Mesh4saveEPKcSsbf__asm");
__asm__(".globl _GLOBAL__D__ZN3sgl4Mesh4saveEPKcSsbf\n_GLOBAL__D__ZN3sgl4Mesh4saveEPKcSsbf = _GLOBAL__D__ZN3sgl4Mesh4saveEPKcSsbf__asm");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_3", _ZN3sgl4Mesh4saveEPKcSsbf);
