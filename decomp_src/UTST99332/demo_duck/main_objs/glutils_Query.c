/* lang: c++ */
/* cflags: -O3 -fno-exceptions -frandom-seed=Querya0dpPC28 */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* The original object (../lib/glutils/Query.cpp) has no public symbol, so cc1plus named its static
   constructor/destructor after the file plus six random letters from the -frandom-seed hash
   (tree.c append_random_chars): _GLOBAL__I_.._lib_glutils_Query.cpp1nxKRa. The seed above gives
   the same letters (the per-object effect of the original's random seed); the prefix is our input
   name (<stdin>). The module's .ctors/.dtors refer to them by their split names: */
__asm__(".globl func_00034538\nfunc_00034538 = _GLOBAL__I__stdin_1nxKRa");
__asm__(".globl func_00034558\nfunc_00034558 = _GLOBAL__D__stdin_1nxKRa");
