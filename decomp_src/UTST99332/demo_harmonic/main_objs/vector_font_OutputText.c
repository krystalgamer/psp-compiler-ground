/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN11vector_font10OutputText8_currentE");

#include "UTST99332/demo_harmonic/gl.hpp"

namespace vector_font {
class OutputText {
public:
    struct Pos {
        Pos() : x(0), y(0), z(0) {}
        float x, y, z;
    };
    struct Point {
        Point() : x(0), y(0), z(0) {}
        float x, y, z;
    };
    static void Put(std::string);
    static void Outline(std::string);
    static void Brackets(std::string);
    static void put(std::string, bool, Point &, Point &);
    static void LineStart();
    static void Margin(float, float);
    static void NextChar();
    static void End();
    static void PrevLine();
    static void NextLine();
    static Pos _current;
    static float _margin_x;
    static float _margin_y;
};
}

vector_font::OutputText::Pos vector_font::OutputText::_current;
float vector_font::OutputText::_margin_x;
float vector_font::OutputText::_margin_y;

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/vector_font_OutputText", _ZN11vector_font9DrawText_ESsfffffj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/vector_font_OutputText", _ZN11vector_font11DrawIntegerEifffffb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/vector_font_OutputText", _ZN11vector_font10OutputText5BeginEfffff);

void vector_font::OutputText::End()
{
    glPopMatrix();
    glPopMatrix();
}

void vector_font::OutputText::PrevLine()
{
    _current.x = 0;
    _current.y += 1.0f;
}

void vector_font::OutputText::NextLine()
{
    LineStart();
    _current.y -= 1.0f;
}

void vector_font::OutputText::LineStart()
{
    _current.x = 0;
}

void vector_font::OutputText::NextChar()
{
    _current.x += 1.0f;
}

void vector_font::OutputText::Put(std::string s)
{
    Point a, b;
    put(s, true, a, b);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/vector_font_OutputText", _ZN11vector_font10OutputText3putESsbRNS0_5PointES2_);

void vector_font::OutputText::Margin(float x, float y)
{
    _margin_x = x;
    _margin_y = y;
}

extern "C" {
void glBegin(unsigned int);
void glEnd(void);
void glVertex3f(float, float, float);
}
void vector_font::OutputText::Outline(std::string s)
{
    Point a, b;
    put(s, false, a, b);
    a.x -= _margin_x;
    a.y -= _margin_y;
    b.x += _margin_x;
    b.y += _margin_y;
    glPushMatrix();
    glBegin(2);
    glVertex3f(a.x, a.y, b.z);
    glVertex3f(a.x, b.y, b.z);
    glVertex3f(b.x, b.y, b.z);
    glVertex3f(b.x, a.y, b.z);
    glEnd();
    glPopMatrix();
}

void vector_font::OutputText::Brackets(std::string s)
{
    Point a, b;
    put(s, false, a, b);
    a.x -= _margin_x;
    b.x += _margin_x;
    a.y -= _margin_y;
    b.y += _margin_y;
    float dx = (b.x - a.x) * 0.2f;
    float dy = (b.y - a.y) * 0.2f;
    glPushMatrix();
    glBegin(3);
    glVertex3f(a.x, a.y + dy, b.z);
    glVertex3f(a.x, a.y, b.z);
    glVertex3f(a.x + dx, a.y, b.z);
    glEnd();
    glBegin(3);
    glVertex3f(a.x, b.y - dy, b.z);
    glVertex3f(a.x, b.y, b.z);
    glVertex3f(a.x + dx, b.y, b.z);
    glEnd();
    glBegin(3);
    glVertex3f(b.x, b.y - dy, b.z);
    glVertex3f(b.x, b.y, b.z);
    glVertex3f(b.x - dx, b.y, b.z);
    glEnd();
    glBegin(3);
    glVertex3f(b.x, a.y + dy, b.z);
    glVertex3f(b.x, a.y, b.z);
    glVertex3f(b.x - dx, a.y, b.z);
    glEnd();
    glPopMatrix();
}
