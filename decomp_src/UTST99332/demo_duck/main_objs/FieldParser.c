/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* the strings stay in the module's .rodata (asm) */
extern const char D_0017570C[];     /* " \t\b\r\n[]:=" */
extern const char D_00175718[];     /* "\"" */
extern const char D_0017571C[];     /* "true" */
extern const char D_00175724[];     /* "yes" */
extern const char D_00175728[];     /* "1" */
extern const char D_00175760[];     /* "}" */
extern const char D_00175764[];     /* "bool" */
extern const char D_0017576C[];     /* "int" */
extern const char D_00175770[];     /* "float" */
extern const char D_00175778[];     /* "string" */
extern const char D_00175780[];     /* "size_t" */
extern const char D_00175788[];     /* "" */
extern const char D_0017578C[];     /* "../lib/system/FieldParser.cpp" */
extern const char D_001757AC[];     /* "unknown type" */
extern const char D_001757BC[];     /* " *** error " */
extern const char D_001757FC[];
extern const char PF_step_field[] __asm__("_ZZN11FieldParser10step_fieldERNS_5FieldEE19__PRETTY_FUNCTION__");
extern const char PF_skip[] __asm__("_ZZN11FieldParser4skipERKNS_5FieldEE19__PRETTY_FUNCTION__");
#define FP_FAIL(pf, line, msg) \
    { \
        common::common_internal::assert_display(D_001757BC, D_00175788, D_0017578C, pf, line, msg); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

FieldParser::FieldParser(std::string file) : basic_file_parser(file, 0x800, D_0017570C)
{
}

void FieldParser::step_string(std::string &s)
{
    step_until(D_00175718);
    step('"', '"');
    s = c_str();
}

void FieldParser::step_bool(bool &b)
{
    step();
    b = is_equal(D_0017571C) || is_equal(D_00175724) || is_equal(D_00175728);
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
    if (is_equal(D_00175760))
        return false;
    if (is_equal(D_00175764))
        f.type = BOOL;
    else if (is_equal(D_0017576C))
        f.type = INT;
    else if (is_equal(D_00175770))
        f.type = FLOAT;
    else if (is_equal(D_00175778))
        f.type = STRING;
    else if (is_equal(D_00175780))
        f.type = SIZE_T;
    else {
        watch_tp(24);
        FP_FAIL(PF_step_field, 86, D_001757AC);
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
        FP_FAIL(PF_skip, 109, D_001757FC);
}
