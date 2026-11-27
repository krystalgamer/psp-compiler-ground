/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_LINKONCE_RectanglePicking 1
#include "../main.hpp"

/* weak instances stay asm */
extern template class std::vector<unsigned int>;

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_RectanglePicking", _Z41__static_initialization_and_destruction_0ii_320FC);

glutils::RectanglePicking::RectanglePicking() : _f30(false), _f31(true)
{
}

void glutils::RectanglePicking::setStart(math::vector_xy v)
{
    _start = v;
}

void glutils::RectanglePicking::setCurrent(math::vector_xy v)
{
    _current = v;
}

math::vector_xy glutils::RectanglePicking::getStart() const
{
    return _start;
}

math::vector_xy glutils::RectanglePicking::getCurrent() const
{
    return _current;
}

void glutils::RectanglePicking::push_back(unsigned int name)
{
    _hits.push_back(name);
}

extern "C" const char D_00163CD8[], D_00163CE4[], D_00163CF0[], D_00163D14[];
extern const char RectanglePicking_activate_name[] __asm__("_ZZN7glutils16RectanglePicking8activateEvE19__PRETTY_FUNCTION__");

void glutils::RectanglePicking::activate()
{
    SGL_ASSERT(_f31, D_00163CD8, D_00163CE4, D_00163CF0, RectanglePicking_activate_name, 53, D_00163D14);
    _f30 = true;
}

void glutils::RectanglePicking::resize(unsigned int n)
{
    _hits.resize(n);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_320FC");
void _GLOBAL__I__ZN7glutils16RectanglePickingC2Ev(void);
void _GLOBAL__D__ZN7glutils16RectanglePickingC2Ev(void);
}

void _GLOBAL__I__ZN7glutils16RectanglePickingC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN7glutils16RectanglePickingC2Ev(void)
{
    static_init(0, 0xFFFF);
}
