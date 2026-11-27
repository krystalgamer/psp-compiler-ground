/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN12basic_parserC2EPKcjS1_");
__asm__(".globl _GLOBAL__D__ZN12basic_parserC2EPKcjS1_");

#define BP_ASSERT(c, s, pf, line, msg) \
    if (!(c)) { \
        common::common_internal::assert_display(" *** error ", s, "../lib/system/basic_parser.cpp", pf, line, msg); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

basic_parser::basic_parser(const char *text, unsigned int size, const char *seps)
    : _tmp_str(size), _tmp_str_invalid(true)
{
    copy_text(text);
    separators(seps);
    BP_ASSERT(!_tmp_str.empty(), "! _tmp_str.empty()", __PRETTY_FUNCTION__, 33, " ");
}

basic_parser::~basic_parser()
{
}

void basic_parser::copy_text(const char *text)
{
    if (!text)
        text = "";
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

bool basic_parser::step(char open, char close)
{
    char o[2] = { open, 0 };
    char c[2] = { close, 0 };
    step_until(o);
    if (_pos == (unsigned int)-1)
        return false;
    unsigned int first = ++_pos;
    step_until(c);
    unsigned int last = _pos;
    fill_c_str(first, last);
    if (_pos != (unsigned int)-1)
        _pos++;
    return true;
}

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
    BP_ASSERT(is_equal(s), "is_equal( _Str )", __PRETTY_FUNCTION__, 178, s);
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
        BP_ASSERT(_expect_eof, "_expect_eof", __PRETTY_FUNCTION__, 196, " ");
        _tmp_str_invalid = false;
        return npos;
    }
    return fill_c_str(first, _parsed_text.find_first_of(seps, first));
}

size_t basic_parser::fill_c_str(unsigned int first, unsigned int last)
{
    BP_ASSERT(last >= first, "_Last >= _First", __PRETTY_FUNCTION__, 213, " ");
    if (last == (unsigned int)-1) {
        last = _parsed_text.size();
        BP_ASSERT(_parsed_text.c_str()[last] == '\0', "_parsed_text.c_str()[_Last] == '\\0'", __PRETTY_FUNCTION__, 219, " ");
    }
    size_t len = last - first;
    BP_ASSERT(len != 0, "len != 0", __PRETTY_FUNCTION__, 224, " ");
    BP_ASSERT(_tmp_str.bytesize() >= len + 1, "_tmp_str.bytesize() >= len + 1", __PRETTY_FUNCTION__, 226, " ");
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
    BP_ASSERT(!_bookmarks.empty(), "! _bookmarks.empty()", __PRETTY_FUNCTION__, 291, "bookmarks stack underflow");
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
    BP_ASSERT(!_tmp_str_invalid, "! _tmp_str_invalid", __PRETTY_FUNCTION__, 318, " ");
    return _tmp_str.addr();
}

char *basic_parser::c_str()
{
    BP_ASSERT(!_tmp_str_invalid, "! _tmp_str_invalid", __PRETTY_FUNCTION__, 325, " ");
    return _tmp_str.addr();
}

void basic_parser::watch_tp(unsigned int) {
}
