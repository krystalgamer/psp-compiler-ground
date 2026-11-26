/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
extern const char scene_bvdata_err[] __asm__("D_001660E8");      /* " *** error " */
extern const char scene_bvdata_valid[] __asm__("D_001660F4");    /* "valid()" */
extern const char scene_bvdata_file[] __asm__("D_001660FC");     /* "../lib/scene/BVdata.h" */
extern const char scene_bvdata_sp[] __asm__("D_00166114");       /* " " */
extern const char scene_bvdata_get_name[] __asm__("_ZZN5scene6BVdata3getEvE19__PRETTY_FUNCTION___1660C8");
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_HasBVdata", _Z41__static_initialization_and_destruction_0ii_5CBE8);

bool scene::HasBVdata::frustumTest(sgl::Frustum &f)
{
    bool r = true;
    if (enabled && _bvdata._bv)
        r = sgl_Frustum_intersect(&f, _bvdata.get());
    return r;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_5CBE8");
void _GLOBAL__I__ZN5scene9HasBVdata7enabledE(void);
void _GLOBAL__D__ZN5scene9HasBVdata7enabledE(void);
}

void _GLOBAL__I__ZN5scene9HasBVdata7enabledE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene9HasBVdata7enabledE(void)
{
    static_init(0, 0xFFFF);
}

