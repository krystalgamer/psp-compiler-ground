/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3sgl4HeapC2Ev");
__asm__(".globl _GLOBAL__D__ZN3sgl4HeapC2Ev");

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

#define HEAP_ASSERT(c, text, fn, line) SGL_ASSERT(c, " *** error ", text, "../lib/sgl/Heap.cpp", fn, line, " ")

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
    _e[i].id = i;
    _e[i].data = data;
    _e[i].value = value;
    _index[i] = i;
}

void sgl::Heap::change_value(unsigned int i, float value)
{
    int j = _index[i];
    HEAP_ASSERT(j >= 0 && j < _n, "j >=0 && j < _n", __PRETTY_FUNCTION__, 81);
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
    HEAP_ASSERT(i >= 0 && i < _n, "i >= 0 && i < _n", __PRETTY_FUNCTION__, 165);
    swap(i, _n - 1);
    _n--;
    update(i);
}

void sgl::Heap::pop()
{
    HEAP_ASSERT(_n > 0, "_n > 0", __PRETTY_FUNCTION__, 178);
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

int sgl::Heap::check_heapify()
{
    int miss = 0;
    SGL_ASSERT(_heap, " *** error ", "_is_heap", "../lib/sgl/Heap.cpp", __PRETTY_FUNCTION__, 224, "make sure you didn't call sort() (that destroys the heap properties)");
    for (int i = 0; i < _n / 2; i++) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (r < _n && value(i) < value(r)) {
            miss++;
            printf("\ni=%i right=%i %g / %i %i %g", i, _e[i].id, _e[i].value, r, _e[r].id, _e[r].value);
        }
        if (l < _n && value(i) < value(l)) {
            miss++;
            printf("\ni=%i left=%i %g / %i %i %g", i, _e[i].id, _e[i].value, l, _e[l].id, _e[l].value);
        }
    }
    HEAP_ASSERT(miss == 0, "miss == 0", __PRETTY_FUNCTION__, 258);
    return miss;
}

void sgl::Heap::dump() {
}

void sgl::Heap::check_sort()
{
    for (int i = 1; i < _n; i++)
        HEAP_ASSERT(value(i) >= value(i - 1), "value( i ) >= value( i - 1 )", __PRETTY_FUNCTION__, 285);
}

void sgl::Heap::Test()
{
    for (int t = 0; t != 200; t++) {
        int n = math::min_(rand(), 4000);
        std::cout << n << std::endl;
        Heap h;
        h.resize(n);
        for (int i = 0; i < n; i++)
            h.set_element(i, i, rand());
        h.heapify();
        h.check_heapify();
        for (int k = 0; h._n; ) {
            int j = (int)((math::FastNoise(k++) + 1.0f) * 0.5f * h._n);
            if (j < 0)
                j = 0;
            if (j >= h._n)
                j = h._n - 1;
            h.remove(j);
            h.check_heapify();
        }
    }
    std::cout << "HEAP CHECK STILL ALIVE!\n";
    exit(0);
}

namespace math {
template<class T> T min_(T a, T b)
{
    return a < b ? a : b;
}
}
