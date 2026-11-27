/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN7glutils8Material5setupEv\n_GLOBAL__I__ZN7glutils8Material5setupEv = _GLOBAL__I__ZN7glutils8Material5setupEv__asm");
__asm__(".globl _GLOBAL__D__ZN7glutils8Material5setupEv\n_GLOBAL__D__ZN7glutils8Material5setupEv = _GLOBAL__D__ZN7glutils8Material5setupEv__asm");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_Material", _ZN7glutils8Material5setupEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_Material", _ZN7glutils8Material5printERSo);
