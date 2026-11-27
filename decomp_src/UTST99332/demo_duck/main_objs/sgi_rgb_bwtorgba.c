/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the object's .gnu.linkonce.t sections in the original's order (ImageRec's inline destructor clones are asm) */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN6common7t_arrayIjEC1Ev)
    DEMO_LINKONCE(_ZN6common7t_arrayIjED1Ev)
    DEMO_LINKONCE(_ZN6common7t_arrayIiEC1Ev)
    DEMO_LINKONCE(_ZN6common7t_arrayIiED1Ev)
    DEMO_LINKONCE(_ZN6common7t_arrayIjE6resizeEj)
    DEMO_LINKONCE(_ZN6common7t_arrayIiE6resizeEj)
    DEMO_LINKONCE(_ZN6common7t_arrayIjE4addrEv)
    DEMO_LINKONCE(_ZN6common7t_arrayIiE4addrEv)
    DEMO_LINKONCE(_ZNK6common7t_arrayIjE4sizeEv)
    DEMO_LINKONCE(_ZNK6common7t_arrayIiE4sizeEv)
    DEMO_LINKONCE(_ZNK6common7t_arrayIhE4sizeEv)
    DEMO_LINKONCE(_ZNK6common7t_arrayIhE5emptyEv)
    DEMO_LINKONCE(_ZN6common7t_arrayIjE7releaseEv)
    DEMO_LINKONCE(_ZN6common7t_arrayIiE7releaseEv)
    DEMO_LINKONCE(_ZN6common7t_arrayIjE8allocateEj)
    DEMO_LINKONCE(_ZN6common7t_arrayIiE8allocateEj)
    DEMO_LINKONCE(_ZN7sgi_rgb8ImageRecD1Ev)
    DEMO_LINKONCE(_ZN7sgi_rgb8ImageRecD0Ev)
    DEMO_LINKONCE(_ZN6common7t_arrayIjED0Ev)
    DEMO_LINKONCE(_ZN6common7t_arrayIiED0Ev)
    DEMO_LINKONCE(_ZN6common7t_arrayIiE4swapERS1_)
    DEMO_LINKONCE(_ZN6common7t_arrayIiE4fillERKi)
    DEMO_LINKONCE(_ZN6common7t_arrayIjE4swapERS1_)
    DEMO_LINKONCE(_ZN6common7t_arrayIjE4fillERKj)
    DEMO_LINKONCE(_ZN6common4SwapINS_7t_arrayIiE7MembersEEEvRT_S5_)
    DEMO_LINKONCE(_ZN6common4SwapINS_7t_arrayIjE7MembersEEEvRT_S5_)
);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgi_rgb_bwtorgba", _Z41__static_initialization_and_destruction_0ii_1086CC);

void sgi_rgb::bwtorgba(unsigned char *b, unsigned char *l, int n)
{
    while (n--) {
        l[0] = *b;
        l[1] = *b;
        l[2] = *b;
        l[3] = 0xff;
        l += 4;
        b++;
    }
}

void sgi_rgb::latorgba(unsigned char *b, unsigned char *a, unsigned char *l, int n)
{
    while (n--) {
        l[0] = *b;
        l[1] = *b;
        l[2] = *b;
        l[3] = *a;
        l += 4;
        b++;
        a++;
    }
}

void sgi_rgb::rgbtorgba(unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *l, int n)
{
    while (n--) {
        l[0] = r[0];
        l[1] = g[0];
        l[2] = b[0];
        l[3] = 0xff;
        l += 4;
        r++;
        g++;
        b++;
    }
}

void sgi_rgb::rgbatorgba(unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *a, unsigned char *l, int n)
{
    while (n--) {
        l[0] = r[0];
        l[1] = g[0];
        l[2] = b[0];
        l[3] = a[0];
        l += 4;
        r++;
        g++;
        b++;
        a++;
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN7sgi_rgb8ImageRec4openEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN7sgi_rgb8ImageRec7get_rowEPhiij);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN7sgi_rgb4ReadEPKcPiS2_S2_);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_1086CC");
void _GLOBAL__I__ZN7sgi_rgb8bwtorgbaEPhS0_i(void);
void _GLOBAL__D__ZN7sgi_rgb8bwtorgbaEPhS0_i(void);
}

void _GLOBAL__I__ZN7sgi_rgb8bwtorgbaEPhS0_i(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN7sgi_rgb8bwtorgbaEPhS0_i(void)
{
    static_init(0, 0xFFFF);
}

template common::t_array<unsigned int>::t_array();

template common::t_array<unsigned int>::~t_array();

template common::t_array<int>::t_array();

template common::t_array<int>::~t_array();

template void common::t_array<unsigned int>::resize(unsigned int);

template void common::t_array<int>::resize(unsigned int);

template unsigned int *common::t_array<unsigned int>::addr();

template int *common::t_array<int>::addr();

template unsigned int common::t_array<unsigned int>::size() const;

template unsigned int common::t_array<int>::size() const;

template unsigned int common::t_array<unsigned char>::size() const;

template bool common::t_array<unsigned char>::empty() const;

template void common::t_array<unsigned int>::release();

template void common::t_array<int>::release();

template void common::t_array<unsigned int>::allocate(unsigned int);

template void common::t_array<int>::allocate(unsigned int);

CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN7sgi_rgb8ImageRecD1Ev, _ZN7sgi_rgb8ImageRecD1Ev)

CONT_INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN7sgi_rgb8ImageRecD0Ev, _ZN7sgi_rgb8ImageRecD0Ev)



template void common::t_array<int>::swap(common::t_array<int> &);

template void common::t_array<int>::fill(const int &);

template void common::t_array<unsigned int>::swap(common::t_array<unsigned int> &);

template void common::t_array<unsigned int>::fill(const unsigned int &);

template void common::Swap<common::t_array<int>::Members>(common::t_array<int>::Members &, common::t_array<int>::Members &);

template void common::Swap<common::t_array<unsigned int>::Members>(common::t_array<unsigned int>::Members &, common::t_array<unsigned int>::Members &);

