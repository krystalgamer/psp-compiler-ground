/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* the strings stay in the module's .rodata (asm) */
extern const char D_0015F2D4[];     /* "/" */
extern const char D_0015F2D8[];     /* " " */
extern const char D_0015F2DC[];     /* ":" */

common::Date::CopiableMembers::CopiableMembers()
    : year(2003), month(4), day(7), hour(0), minute(0), second(0)
{
}

bool common::Date::CopiableMembers::operator==(const CopiableMembers &o) const
{
    return year == o.year && month == o.month && day == o.day
        && hour == o.hour && minute == o.minute && second == o.second;
}

void common::Date::set_from_time_t(long *)
{
}

void common::Date::get_date()
{
}

void common::Date::get_file_date(const char *)
{
}

bool common::Date::operator==(const Date &o) const
{
    return m == o.m;
}

bool common::Date::operator!=(const Date &o) const
{
    return !(*this == o);
}

int common::Date::getYear() const
{
    return m.year;
}

int common::Date::getMonth() const
{
    return m.month;
}

int common::Date::getDay() const
{
    return m.day;
}

int common::Date::getHour() const
{
    return m.hour;
}

int common::Date::getMinute() const
{
    return m.minute;
}

int common::Date::getSecond() const
{
    return m.second;
}

common::Date::Date(const char *)
{
}

common::Date::Date()
{
}

void common::Date::output(std::ostream &os) const
{
    os << m.year << D_0015F2D4 << m.month << D_0015F2D4 << m.day << D_0015F2D8
       << m.hour << D_0015F2DC << m.minute << D_0015F2DC << m.second << std::endl;
}
