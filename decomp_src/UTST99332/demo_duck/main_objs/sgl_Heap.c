/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3sgl4HeapC2Ev");
__asm__(".globl _GLOBAL__D__ZN3sgl4HeapC2Ev");

extern const char D_0016DE4C[];     /* " *** error " */
extern const char D_0016DE58[];     /* "j >=0 && j < _n" */
extern const char D_0016DE68[];     /* "../lib/sgl/Heap.cpp" */
extern const char D_0016DE7C[];     /* " " */
extern const char D_0016DE9C[];     /* "i >= 0 && i < _n" */
extern const char D_0016DEC8[];     /* "_n > 0" */
extern const char D_0016DFAC[];     /* "value( i ) >= value( i - 1 )" */
extern const char check_sort_name[] __asm__("_ZZN3sgl4Heap10check_sortEvE19__PRETTY_FUNCTION__");
extern const char change_value_name[] __asm__("_ZZN3sgl4Heap12change_valueEjfE19__PRETTY_FUNCTION__");
extern const char remove_name[] __asm__("_ZZN3sgl4Heap6removeEiE19__PRETTY_FUNCTION__");
extern const char pop_name[] __asm__("_ZZN3sgl4Heap3popEvE19__PRETTY_FUNCTION__");
namespace common {
template<class T> void Swap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}
}
namespace math {
template<class T> T min_(T a, T b);
}

#define HEAP_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016DE4C, text, D_0016DE68, fn, line, D_0016DE7C)

sgl::Heap::Heap() : _index(0), _e(0), _n(0), _heap(false)
{
}

sgl::Heap::~Heap()
{
    clear();
}

void sgl::Heap::clear()
{
    if (_e) {
        delete[] _e;
        _e = 0;
    }
    if (_index) {
        delete[] _index;
        _index = 0;
    }
    _n = 0;
    _heap = false;
}

void sgl::Heap::resize(int n)
{
    clear();
    if (n) {
        _n = n;
        _e = new Element[n];
        _index = new int[_n];
    }
}

void sgl::Heap::set_element(unsigned int i, int data, float value)
{
    _e[i].data = data;
    _e[i].id = i;
    _e[i].value = value;
    _index[i] = i;
}

void sgl::Heap::change_value(unsigned int i, float value)
{
    int j = _index[i];
    HEAP_ASSERT(j >= 0 && j < _n, D_0016DE58, change_value_name, 81);
    _e[j].value = value;
    update(j);
}

void sgl::Heap::swap(int i, int j)
{
    _index[_e[i].id] = j;
    _index[_e[j].id] = i;
    common::Swap(_e[i], _e[j]);
}

void sgl::Heap::downheap(int i, int n)
{
    for (;;) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l >= n)
            return;
        if (r >= n || !(value(r) > value(l)))
            r = l;
        if (!(value(i) < value(r)))
            return;
        swap(i, r);
        i = r;
    }
}

void sgl::Heap::upheap(int i)
{
    for (int p; i > 0; i = p) {
        p = (i - 1) / 2;
        if (value(p) > value(i))
            break;
        else {
            swap(i, p);
        }
    }
}

float sgl::Heap::value(int i) const
{
    return _e[i].value;
}

void sgl::Heap::update(int i)
{
    if (value((i - 1) / 2) < value(i))
        upheap(i);
    else
        downheap(i, _n);
}

void sgl::Heap::remove(int i)
{
    HEAP_ASSERT(i >= 0 && i < _n, D_0016DE9C, remove_name, 165);
    swap(i, _n - 1);
    _n--;
    update(i);
}

void sgl::Heap::pop()
{
    HEAP_ASSERT(_n > 0, D_0016DEC8, pop_name, 178);
    swap(0, _n - 1);
    _n--;
    downheap(0, _n);
}

void sgl::Heap::heapify()
{
    for (int i = _n / 2 - 1; i >= 0; i--)
        downheap(i, _n);
    _heap = true;
}

void sgl::Heap::sort()
{
    for (int i = _n - 1; i > 0; i--) {
        swap(i, 0);
        downheap(0, i);
    }
    _heap = false;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Heap", _ZN3sgl4Heap13check_heapifyEv);

void sgl::Heap::dump() {
}

void sgl::Heap::check_sort()
{
    for (int i = 1; i < _n; i++)
        HEAP_ASSERT(value(i) >= value(i - 1), D_0016DFAC, check_sort_name, 285);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Heap", _ZN3sgl4Heap4TestEv);

/* Test() (asm) calls math::min_<int>: referenced here (from a discarded function, before the template's
   definition: no inlining) it is instantiated after Swap<Heap::Element>, like Sony's */
extern "C" void sgl_Heap_instances(void) __attribute__((section(".discard.asm")));
extern "C" void sgl_Heap_instances(void)
{
    math::min_(0, 0);
}

namespace math {
template<class T> T min_(T a, T b)
{
    return a < b ? a : b;
}
}
