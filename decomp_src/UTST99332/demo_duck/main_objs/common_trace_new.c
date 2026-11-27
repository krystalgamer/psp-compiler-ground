/* lang: c++ */
/* cflags: -O3 -fno-exceptions -frandom-seed=trace_newhr198J17 */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* The original object (../lib/common/trace_new.cpp) has no public symbol, so cc1plus named its static
   constructor/destructor after the file plus six random letters from the -frandom-seed hash
   (tree.c append_random_chars): _GLOBAL__I_.._lib_common_trace_new.cpppfMlvd. The seed above gives
   the same letters (the per-object effect of the original's random seed); the prefix is our input
   name (<stdin>). The module's .ctors/.dtors refer to them by their split names: */
__asm__(".globl func_000153A4\nfunc_000153A4 = _GLOBAL__I__stdin_pfMlvd");
__asm__(".globl func_000153C4\nfunc_000153C4 = _GLOBAL__D__stdin_pfMlvd");
