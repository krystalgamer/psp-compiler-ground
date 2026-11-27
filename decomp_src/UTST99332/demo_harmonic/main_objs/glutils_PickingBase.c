/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"


glutils::PickingBase::PickingBase()
{
    _hits.reserve(80);
    _hits.resize(0);
}

const std::vector<unsigned int> &glutils::PickingBase::getHits() const
{
    return _hits;
}
