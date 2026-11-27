/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* weak instances stay asm */
extern template class std::vector<unsigned int>;

glutils::PickingBase::PickingBase()
{
    _hits.reserve(80);
    _hits.resize(0);
}

const std::vector<unsigned int> &glutils::PickingBase::getHits() const
{
    return _hits;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_PickingBase", _ZNSt6vectorIjSaIjEE7reserveEj);

