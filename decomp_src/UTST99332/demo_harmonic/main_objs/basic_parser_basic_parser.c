/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the strings stay in the module's .rodata (asm) */
extern const char D_00172BF4[];     /* " *** error " */
extern const char D_00172C00[];     /* "! _tmp_str.empty()" */
extern const char D_00172C14[];     /* "../lib/system/basic_parser.cpp" */
extern const char D_00172C34[];     /* " " */
extern const char D_00172C38[];     /* "" */
extern const char D_00172C70[];     /* "is_equal( _Str )" */
extern const char D_00172CBC[];     /* "_expect_eof" */
extern const char D_00172D04[];     /* "_tmp_str.bytesize() >= len + 1" */
extern const char D_00172D24[];     /* "len != 0" */
extern const char D_00172D30[];     /* "_parsed_text.c_str()[_Last] == '\\0'" */
extern const char D_00172D54[];     /* "_Last >= _First" */
extern const char D_00172D90[];     /* "! _bookmarks.empty()" */
extern const char D_00172DA8[];     /* "bookmarks stack underflow" */
extern const char D_00172DEC[];     /* "! _tmp_str_invalid" */
extern const char PF_ctor[] __asm__("_ZZN12basic_parserC1EPKcjS1_E19__PRETTY_FUNCTION__");
extern const char PF_step_assert[] __asm__("_ZZN12basic_parser11step_assertEPKcE19__PRETTY_FUNCTION__");
extern const char PF_read[] __asm__("_ZZN12basic_parser4readEjPKcE19__PRETTY_FUNCTION__");
extern const char PF_fill_c_str[] __asm__("_ZZN12basic_parser10fill_c_strEjjE19__PRETTY_FUNCTION__");
extern const char PF_pop_bookmark[] __asm__("_ZZN12basic_parser12pop_bookmarkEvE19__PRETTY_FUNCTION__");
extern const char PF_c_str_const[] __asm__("_ZZNK12basic_parser5c_strEvE19__PRETTY_FUNCTION__");
extern const char PF_c_str[] __asm__("_ZZN12basic_parser5c_strEvE19__PRETTY_FUNCTION__");
#define BP_ASSERT(c, s, pf, line, msg) \
    if (!(c)) { \
        common::common_internal::assert_display(D_00172BF4, s, D_00172C14, pf, line, msg); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/basic_parser_basic_parser", _Z41__static_initialization_and_destruction_0ii_F7670);

basic_parser::basic_parser(const char *text, unsigned int size, const char *seps)
    : _tmp_str(size), _tmp_str_invalid(true)
{
    copy_text(text);
    separators(seps);
    BP_ASSERT(!_tmp_str.empty(), D_00172C00, PF_ctor, 33, D_00172C34);
}

basic_parser::~basic_parser()
{
}

void basic_parser::copy_text(const char *text)
{
    if (!text)
        text = D_00172C38;
    _parsed_text = text;
    reset();
}

void basic_parser::swap(std::string &s)
{
    _parsed_text.swap(s);
    reset();
}

void basic_parser::reset()
{
    _expect_eof = true;
    _pos = _parsed_text.empty() ? std::string::npos : 0;
    if (!_tmp_str.empty())
        clear_c_str();
    while (!_bookmarks.empty())
        _bookmarks.pop();
}

void basic_parser::separators(const char *seps)
{
    _separators = seps;
}

void basic_parser::expect_eof(bool b)
{
    _expect_eof = b;
}

void basic_parser::step_while(const char *chars)
{
    clear_c_str();
    _pos = _parsed_text.find_first_not_of(chars, _pos);
}

void basic_parser::step_until(const char *chars)
{
    clear_c_str();
    _pos = _parsed_text.find_first_of(chars, _pos);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/basic_parser_basic_parser", _ZN12basic_parser4stepEcc);

bool basic_parser::step(const char *seps)
{
    _pos = read(_pos, seps);
    return _pos != (unsigned int)-1;
}

bool basic_parser::step()
{
    return step(_separators.c_str());
}

bool basic_parser::step_assert(const char *s)
{
    bool ret = step(_separators.c_str());
    if (!is_equal(s))
        watch_tp(24);
    BP_ASSERT(is_equal(s), D_00172C70, PF_step_assert, 178, s);
    return ret;
}

size_t basic_parser::read(unsigned int pos, const char *seps)
{
    const size_t npos = (size_t)-1;
    size_t first;
    clear_c_str();
    if (pos == _parsed_text.size() || pos == npos)
        first = npos;
    else
        first = _parsed_text.find_first_not_of(seps, pos);
    if (first == npos) {
        BP_ASSERT(_expect_eof, D_00172CBC, PF_read, 196, D_00172C34);
        _tmp_str_invalid = false;
        return npos;
    }
    return fill_c_str(first, _parsed_text.find_first_of(seps, first));
}

size_t basic_parser::fill_c_str(unsigned int first, unsigned int last)
{
    BP_ASSERT(last >= first, D_00172D54, PF_fill_c_str, 213, D_00172C34);
    if (last == (unsigned int)-1) {
        last = _parsed_text.size();
        BP_ASSERT(_parsed_text.c_str()[last] == '\0', D_00172D30, PF_fill_c_str, 219, D_00172C34);
    }
    size_t len = last - first;
    BP_ASSERT(len != 0, D_00172D24, PF_fill_c_str, 224, D_00172C34);
    BP_ASSERT(_tmp_str.bytesize() >= len + 1, D_00172D04, PF_fill_c_str, 226, D_00172C34);
    strncpy(_tmp_str.addr(), &_parsed_text[first], len);
    _tmp_str.addr()[len] = 0;
    _tmp_str_invalid = false;
    return last;
}

bool basic_parser::is_equal(const char *s) const
{
    return strcmp(c_str(), s) == 0;
}

bool basic_parser::next_is_equal(const char *s)
{
    push_bookmark();
    step();
    bool ret = is_equal(s);
    pop_bookmark();
    return ret;
}

bool basic_parser::next_is_equal(const char *s, int n)
{
    push_bookmark();
    for (; n > 0; n--)
        step();
    bool ret = is_equal(s);
    pop_bookmark();
    return ret;
}

void basic_parser::push_bookmark()
{
    _bookmarks.push(_pos);
}

void basic_parser::pop_bookmark()
{
    BP_ASSERT(!_bookmarks.empty(), D_00172D90, PF_pop_bookmark, 291, D_00172DA8);
    _pos = _bookmarks.top();
    _bookmarks.pop();
    clear_c_str();
}

void basic_parser::clear_c_str()
{
    _tmp_str_invalid = true;
    *_tmp_str.addr() = 0;
}

const char *basic_parser::c_str() const
{
    BP_ASSERT(!_tmp_str_invalid, D_00172DEC, PF_c_str_const, 318, D_00172C34);
    return _tmp_str.addr();
}

char *basic_parser::c_str()
{
    BP_ASSERT(!_tmp_str_invalid, D_00172DEC, PF_c_str, 325, D_00172C34);
    return _tmp_str.addr();
}

void basic_parser::watch_tp(unsigned int) {
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_F7670");
void _GLOBAL__I__ZN12basic_parserC2EPKcjS1_(void);
void _GLOBAL__D__ZN12basic_parserC2EPKcjS1_(void);
}

void _GLOBAL__I__ZN12basic_parserC2EPKcjS1_(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN12basic_parserC2EPKcjS1_(void)
{
    static_init(0, 0xFFFF);
}

