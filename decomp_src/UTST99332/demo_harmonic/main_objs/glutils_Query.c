/* lang: c++ */
/* cflags: -O3 -fno-exceptions -frandom-seed=Querya0dpPC28 */
/* srcname: ../lib/glutils/Query.cpp */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* The original object (../lib/glutils/Query.cpp) has no public symbol, so cc1plus named its static
   constructor/destructor after the file plus six random letters from the -frandom-seed hash
   (tree.c append_random_chars): _GLOBAL__I_.._lib_glutils_Query.cpp1nxKRa. The seed above gives
   the same letters (the per-object effect of the original's random seed); the srcname line makes cc1plus
   see the same input file name. The module's .ctors/.dtors refer to them by their split names: */
__asm__(".globl func_000320BC\nfunc_000320BC = _GLOBAL__I_.._lib_glutils_Query.cpp1nxKRa");
__asm__(".globl func_000320DC\nfunc_000320DC = _GLOBAL__D_.._lib_glutils_Query.cpp1nxKRa");
