/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_LINKONCE_RectanglePicking 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN7glutils16RectanglePickingC2Ev");
__asm__(".globl _GLOBAL__D__ZN7glutils16RectanglePickingC2Ev");

/* weak instances stay asm */
extern template class std::vector<unsigned int>;

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


void glutils::RectanglePicking::activate()
{
    SGL_ASSERT(_f31, " *** error ", "_visible", "../lib/glutils/RectanglePicking.cpp", __PRETTY_FUNCTION__, 53, " ");
    _f30 = true;
}

void glutils::RectanglePicking::resize(unsigned int n)
{
    _hits.resize(n);
}
