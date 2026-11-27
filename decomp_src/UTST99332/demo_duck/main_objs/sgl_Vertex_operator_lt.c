/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* Vertex::operator< and lib/sgl/VarlenListsList: an object without static constructors after
   sgl_Mesh_4's template instances */
extern const char D_0016F0C0[];     /* " *** error " */
extern const char D_0016F160[];     /* " " */
extern const char D_0016F2C0[];     /* "../lib/sgl/VarlenListsList.h" */
extern const char D_0016F33C[];     /* "_List < _n" */
extern const char D_00170990[];     /* "_lists.size() == 0" */
extern const char D_001709A4[];     /* "_data.size() == 0" */
extern const char D_00170A40[];
extern const char VLL_reset_name[] __asm__("_ZZN3sgl15VarlenListsList5resetEvE19__PRETTY_FUNCTION___17096C");
extern const char VLL_clear_name[] __asm__("_ZZN3sgl15VarlenListsList5clearEjE19__PRETTY_FUNCTION___1709DC");
extern const char VLL_freeze_name[] __asm__("_ZZN3sgl15VarlenListsList6freezeEvE19__PRETTY_FUNCTION___1709B8");
extern const char VLL_add_name[] __asm__("_ZZN3sgl15VarlenListsList3addEjiE19__PRETTY_FUNCTION___170A0C");
#define VLL_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016F0C0, text, D_0016F2C0, fn, line, D_0016F160)
inline void sgl::VarlenListsList::clear(unsigned int _List)
{
    VLL_ASSERT(_List < _n, D_0016F33C, VLL_clear_name, 85);
    _lists[_List]._cur = 0;
}

bool sgl::Vertex::operator<(const Vertex &o) const
{
    if (_attr[POS] < o._attr[POS])
        return true;
    if (o._attr[POS] < _attr[POS])
        return false;
    if (_attr[NOR] < o._attr[NOR])
        return true;
    if (o._attr[NOR] < _attr[NOR])
        return false;
    if (_attr[COL] < o._attr[COL])
        return true;
    if (o._attr[COL] < _attr[COL])
        return false;
    if (_attr[TEX] < o._attr[TEX])
        return true;
    if (o._attr[TEX] < _attr[TEX])
        return false;
    return false;
}

void sgl::VarlenListsList::reset()
{
    _n = 0;
    _lists.clear();
    _data.clear();
    VLL_ASSERT(_lists.size() == 0, D_00170990, VLL_reset_name, 97);
    VLL_ASSERT(_data.size() == 0, D_001709A4, VLL_reset_name, 98);
}

void sgl::VarlenListsList::freeze()
{
    if (_n == 0)
        return;
    _lists[0]._head = 0;
    unsigned int total = _lists[0]._size;
    for (unsigned int i = 1; i != _n; i++) {
        _lists[i]._head = _lists[i - 1]._head + _lists[i - 1]._size;
        total += _lists[i]._size;
    }
    for (unsigned int i = 0; i != _n; i++)
        clear(i);
    if (total == 0) {
        _data.clear();
        VLL_ASSERT(_data.size() == 0, D_001709A4, VLL_freeze_name, 135);
    } else
        _data.resize(total);
}

void sgl::VarlenListsList::add(unsigned int _List, int v)
{
    VLL_ASSERT(_List < _n, D_0016F33C, VLL_add_name, 147);
    List &l = _lists[_List];
    VLL_ASSERT(l._head + l._cur >= 0 && l._head + l._cur < l._head + l._size, D_00170A40, VLL_add_name, 153);
    _data[l._head + l._cur] = v;
    l._cur++;
}
