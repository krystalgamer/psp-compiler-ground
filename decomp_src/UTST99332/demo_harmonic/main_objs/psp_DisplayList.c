/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" const char D_0015E700[], D_0015E70C[], D_0015E710[], D_0015E730[], D_0015E750[], D_0015E784[];
extern const char resize_name[] __asm__("_ZZN3psp11DisplayList6resizeEjE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_DisplayList", _Z41__static_initialization_and_destruction_0ii_1AA00);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_1AA00");
/* _GLOBAL__I_/_D_ (local names) */
void func_0001AA7C(void);
void func_0001AA9C(void);
}

void func_0001AA7C(void)
{
    static_init(1, 0xFFFF);
}

void func_0001AA9C(void)
{
    static_init(0, 0xFFFF);
}

#define DL_ASSERT(c, text, line) SGL_ASSERT(c, D_0015E700, text, D_0015E730, resize_name, line, D_0015E70C)
void psp::DisplayList::resize(unsigned int n)
{
    DL_ASSERT(!_wflag, D_0015E784, 23);
    if (_capacity == n)
        return;
    if (_buf_mem) {
        delete[] _buf_mem;
        _buf_mem = 0;
    }
    _size = 0;
    _capacity = n;
    _buf = 0;
    if (n) {
        _buf_mem = new char[n + 64];
        _buf = _buf_mem;
        while ((unsigned int)_buf % 64 != 0)
            _buf++;
        DL_ASSERT((unsigned int)_buf - (unsigned int)_buf_mem < 64, D_0015E750, 46);
        DL_ASSERT((unsigned int)_buf % 64 == 0, D_0015E710, 47);
    }
}

void psp::DisplayList::set_name(const char *n)
{
    unsigned int len = strlen(n);
    unsigned int i;
    for (i = 0; i < 31 && i < len; i++)
        _name[i] = n[i];
    _name[i] = 0;
}
