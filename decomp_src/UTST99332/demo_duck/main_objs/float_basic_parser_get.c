/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZNK12basic_parser3getIfEET_v");
__asm__(".globl _GLOBAL__D__ZNK12basic_parser3getIfEET_v");

/* the strings stay in the module's .rodata (asm) */

template<> float basic_parser::get<float>() const
{
    return libc_fix::AtoF(c_str());
}

template<> double basic_parser::get<double>() const
{
    return libc_fix::AtoF(c_str());
}

template<> int basic_parser::get<int>() const
{
    return libc_fix::AtoI(c_str());
}

template<> unsigned int basic_parser::get<unsigned int>() const
{
    return libc_fix::AtoI(c_str());
}

template<> long basic_parser::get<long>() const
{
    return libc_fix::AtoI(c_str());
}

template<> const std::string basic_parser::get<const std::string>() const
{
    return c_str();
}

template<> char *basic_parser::get<char *>() const
{
    common::common_internal::assert_display(" *** error ", "", "../lib/system/basic_parser_spe.cpp", __PRETTY_FUNCTION__, 69, "use c_str() instead");
    common::common_internal::on_error();
    common::common_internal::clash();
    return 0;
}

template<> const char *basic_parser::get<const char *>() const
{
    common::common_internal::assert_display(" *** error ", "", "../lib/system/basic_parser_spe.cpp", __PRETTY_FUNCTION__, 77, "use c_str() instead");
    common::common_internal::on_error();
    common::common_internal::clash();
    return 0;
}
