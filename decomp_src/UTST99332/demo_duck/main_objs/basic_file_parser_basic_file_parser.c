/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/basic_file_parser_basic_file_parser", _Z41__static_initialization_and_destruction_0ii_F962C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/basic_file_parser_basic_file_parser", _ZN17basic_file_parserC2ESsjPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/basic_file_parser_basic_file_parser", _ZN17basic_file_parserC1ESsjPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/basic_file_parser_basic_file_parser", _ZN17basic_file_parserD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/basic_file_parser_basic_file_parser", _ZN17basic_file_parserD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/basic_file_parser_basic_file_parser", _ZN17basic_file_parserD0Ev);

bool basic_file_parser::ready() const
{
    return _f50;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/basic_file_parser_basic_file_parser", _ZN17basic_file_parser10preprocessEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_F962C");
void _GLOBAL__I__ZN17basic_file_parserC2ESsjPKc(void);
void _GLOBAL__D__ZN17basic_file_parserC2ESsjPKc(void);
}

void _GLOBAL__I__ZN17basic_file_parserC2ESsjPKc(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN17basic_file_parserC2ESsjPKc(void)
{
    static_init(0, 0xFFFF);
}

