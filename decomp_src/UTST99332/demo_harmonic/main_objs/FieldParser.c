/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* the strings stay in the module's .rodata (asm) */
extern const char D_001727E4[];     /* " \t\b\r\n[]:=" */
extern const char D_001727F0[];     /* "\"" */
extern const char D_001727F4[];     /* "true" */
extern const char D_001727FC[];     /* "yes" */
extern const char D_00172800[];     /* "1" */
extern const char D_00172838[];     /* "}" */
extern const char D_0017283C[];     /* "bool" */
extern const char D_00172844[];     /* "int" */
extern const char D_00172848[];     /* "float" */
extern const char D_00172850[];     /* "string" */
extern const char D_00172858[];     /* "size_t" */
extern const char D_00172860[];     /* "" */
extern const char D_00172864[];     /* "../lib/system/FieldParser.cpp" */
extern const char D_00172884[];     /* "unknown type" */
extern const char D_00172894[];     /* " *** error " */
extern const char D_001728D4[];
extern const char PF_step_field[] __asm__("_ZZN11FieldParser10step_fieldERNS_5FieldEE19__PRETTY_FUNCTION__");
extern const char PF_skip[] __asm__("_ZZN11FieldParser4skipERKNS_5FieldEE19__PRETTY_FUNCTION__");
#define FP_FAIL(pf, line, msg) \
    { \
        common::common_internal::assert_display(D_00172894, D_00172860, D_00172864, pf, line, msg); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

FieldParser::FieldParser(std::string file) : basic_file_parser(file, 0x800, D_001727E4)
{
}

void FieldParser::step_string(std::string &s)
{
    step_until(D_001727F0);
    step('"', '"');
    s = c_str();
}

void FieldParser::step_bool(bool &b)
{
    step();
    b = is_equal(D_001727F4) || is_equal(D_001727FC) || is_equal(D_00172800);
}

void FieldParser::step_int(int &i)
{
    step();
    i = get<int>();
}

void FieldParser::step_size_t(unsigned int &n)
{
    step();
    n = get<unsigned int>();
}

bool FieldParser::step_field(Field &f)
{
    f.type = NONE;
    f.count = 0;
    if (!step())
        return false;
    if (is_equal(D_00172838))
        return false;
    if (is_equal(D_0017283C))
        f.type = BOOL;
    else if (is_equal(D_00172844))
        f.type = INT;
    else if (is_equal(D_00172848))
        f.type = FLOAT;
    else if (is_equal(D_00172850))
        f.type = STRING;
    else if (is_equal(D_00172858))
        f.type = SIZE_T;
    else {
        watch_tp(24);
        FP_FAIL(PF_step_field, 86, D_00172884);
    }
    step();
    f.count = get<unsigned int>();
    step();
    return true;
}

void FieldParser::skip(const Field &f)
{
    if (f.type != STRING) {
        for (unsigned int i = 0; i != f.count; i++)
            step();
    } else
        FP_FAIL(PF_skip, 109, D_001728D4);
}
