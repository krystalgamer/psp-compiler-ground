/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene5Graph9save_vrmlESs");
__asm__(".globl _GLOBAL__D__ZN5scene5Graph9save_vrmlESs");

void scene::Graph::save_vrml(std::string) {
}
