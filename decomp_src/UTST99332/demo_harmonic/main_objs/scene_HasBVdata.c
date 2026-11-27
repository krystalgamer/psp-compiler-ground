/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SCENE_BVDATA_LITERALS
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene9HasBVdata7enabledE");
__asm__(".globl _GLOBAL__D__ZN5scene9HasBVdata7enabledE");

bool scene::HasBVdata::enabled;

bool scene::HasBVdata::frustumTest(sgl::Frustum &f)
{
    bool r = true;
    if (enabled && _bvdata._bv)
        r = sgl_Frustum_intersect(&f, _bvdata.get());
    return r;
}
