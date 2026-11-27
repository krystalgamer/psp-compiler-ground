/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN11vector_font7ConsoleC2Ejj");
__asm__(".globl _GLOBAL__D__ZN11vector_font7ConsoleC2Ejj");
#include "../gl.hpp"

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZNSt6vectorIN11vector_font7Console4LineESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_)
    DEMO_LINKONCE(_ZNSt6vectorIN11vector_font7Console4LineESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_)
    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN11vector_font7Console4LineESt6vectorIS4_SaIS4_EEEES4_EvT_SA_RKT0_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN11vector_font7Console4LineES3_ET0_T_S5_S4_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN11vector_font7Console4LineEjS2_ET_S4_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN11vector_font7Console4LineESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN11vector_font7Console4LineESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN11vector_font7Console4LineESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type)
);

vector_font::Console::Console(unsigned int w, unsigned int h)
    : vx(0.5f), vy(0.5f), sx(1), sy(1), r(1), g(1), b(1), enabled(true)
{
    resize(w, h);
    sx = 1.0f / _num_columns;
    sy = 1.0f / _num_lines;
}

void vector_font::Console::resize(unsigned int w, unsigned int h)
{
    _num_columns = w;
    _num_lines = h;
    _lines.resize(h);
    for (std::vector<Line>::iterator l = _lines.begin(); l != _lines.end(); ++l) {
        l->_text.resize(w);
        l->_pos = 0;
    }
    clear();
}

void vector_font::Console::enable(bool e)
{
    enabled = e;
}

void vector_font::Console::clear()
{
    if (!enabled)
        return;
    _cur = _lines.begin();
    for (std::vector<Line>::iterator l = _cur; l != _lines.end(); ++l) {
        for (std::string::iterator c = l->_text.begin(); c != l->_text.end(); ++c) {
            *c = '@';
            l->_pos = 0;
        }
    }
}

vector_font::Console &vector_font::Console::operator<<(float f)
{
    if (enabled) {
        char buf[64];
        libc_fix::FtoA(f, buf);
        *this << buf;
    }
    return *this;
}

vector_font::Console &vector_font::Console::operator<<(int i)
{
    if (enabled) {
        char buf[64];
        libc_fix::ItoA(buf, sizeof(buf), i);
        *this << buf;
    }
    return *this;
}

vector_font::Console &vector_font::Console::operator<<(unsigned int i)
{
    if (enabled) {
        char buf[64];
        libc_fix::ItoA(buf, sizeof(buf), i);
        *this << buf;
    }
    return *this;
}

vector_font::Console &vector_font::Console::operator<<(const char *s)
{
    if (enabled) {
        for (; *s; s++)
            put(*s);
    }
    return *this;
}

vector_font::Console &vector_font::Console::operator<<(const std::string s)
{
    if (enabled) {
        for (std::string::const_iterator c = s.begin(); c != s.end(); ++c)
            put(*c);
    }
    return *this;
}

vector_font::Console &vector_font::Console::operator<<(char c)
{
    if (enabled)
        put(c);
    return *this;
}

void vector_font::Console::put(char c)
{
    if (_num_columns && _num_lines) {
        if (c == '\n' || _cur->full()) {
            ++_cur;
            if (_cur == _lines.end())
                _cur = _lines.begin();
            _cur->_pos = 0;
        }
        if (c != '\n')
            _cur->put(c);
    }
}

extern "C" {
void glGetIntegerv(unsigned int, int *);
void glViewport(int, int, int, int);
void glMatrixMode(unsigned int);
void glLoadIdentity(void);
void gluOrtho2D(double, double, double, double);
}
namespace vector_font {
void DrawText_(std::string, float, float, float, float, float, unsigned int);
}
void vector_font::Console::draw() const
{
    if (!enabled)
        return;
    int vp[4];
    glGetIntegerv(0xBA2, vp);
    glViewport(vp[0], vp[1] + (int)(vp[3] * (1 - vy)), (int)(vp[2] * vx), (int)(vp[3] * vy));
    glMatrixMode(0x1701);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 1, 0, 1);
    glMatrixMode(0x1700);
    glPushMatrix();
    glLoadIdentity();
    glPushMatrix();
    glDisable(GL_LIGHTING);
    math::vector_xyz p(-sx * 0.5f, 1 - sy * 0.5f, 0);
    glColor3f(r, g, b);
    for (std::vector<Line>::const_iterator l = _lines.begin(); l != _lines.end(); ++l) {
        SGL_ASSERT(l->_text.size() == _num_columns, " *** error ", "l->_text.size() == _num_columns", "../lib/glutils/Console.cpp", __PRETTY_FUNCTION__, 0xF3, " ");
        if (l->_pos)
            DrawText_(l->_text, p.x, p.y, p.z, sx, sy, l->_pos);
        p.y -= sy;
    }
    glPopMatrix();
    glPopMatrix();
    glMatrixMode(0x1701);
    glPopMatrix();
    glMatrixMode(0x1700);
    glViewport(vp[0], vp[1], vp[2], vp[3]);
}

void vector_font::Console::setViewport(float x, float y)
{
    vx = x;
    vy = y;
}

void vector_font::Console::setColor(float r_, float g_, float b_)
{
    r = r_;
    g = g_;
    b = b_;
}
