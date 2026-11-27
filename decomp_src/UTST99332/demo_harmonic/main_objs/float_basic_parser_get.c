/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
/* base.hpp still has its own stand-ins for these classes: keep them out of the way */
#define basic_parser basic_parser_base_hpp
#define basic_file_parser basic_file_parser_base_hpp
#include "../main.hpp"
#undef basic_parser
#undef basic_file_parser
#include "../../demo_duck/demo/parser.hpp"

/* the strings stay in the module's .rodata (asm) */
extern const char D_00172EA8[];     /* "../lib/system/basic_parser_spe.cpp" */
extern const char D_00172ECC[];     /* " *** error " */
extern const char D_00172ED8[];     /* "use c_str() instead" */
extern const char D_00172EEC[];     /* "" */
extern const char PF_get_pc[] __asm__("_ZZNK12basic_parser3getIPcEET_vE19__PRETTY_FUNCTION__");
extern const char PF_get_pkc[] __asm__("_ZZNK12basic_parser3getIPKcEET_vE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/float_basic_parser_get", _Z41__static_initialization_and_destruction_0ii_F9070);

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
    common::common_internal::assert_display(D_00172ECC, D_00172EEC, D_00172EA8, PF_get_pc, 69, D_00172ED8);
    common::common_internal::on_error();
    common::common_internal::clash();
    return 0;
}

template<> const char *basic_parser::get<const char *>() const
{
    common::common_internal::assert_display(D_00172ECC, D_00172EEC, D_00172EA8, PF_get_pkc, 77, D_00172ED8);
    common::common_internal::on_error();
    common::common_internal::clash();
    return 0;
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_F9070");
void _GLOBAL__I__ZNK12basic_parser3getIfEET_v(void);
void _GLOBAL__D__ZNK12basic_parser3getIfEET_v(void);
}

void _GLOBAL__I__ZNK12basic_parser3getIfEET_v(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZNK12basic_parser3getIfEET_v(void)
{
    static_init(0, 0xFFFF);
}
