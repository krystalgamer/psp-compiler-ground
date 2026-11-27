/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define basic_parser basic_parser_base_hpp
#define basic_file_parser basic_file_parser_base_hpp
#include "../main.hpp"
#undef basic_parser
#undef basic_file_parser
#include "../../demo_duck/demo/parser.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _Z41__static_initialization_and_destruction_0ii_1062E8);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN7sgi_rgb8ImageRec4openEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN7sgi_rgb8ImageRec7get_rowEPhiij);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN7sgi_rgb4ReadEPKcPiS2_S2_);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_1062E8");
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIjEC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIjED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIiEC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIiED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIjE6resizeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIiE6resizeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIjE4addrEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIiE4addrEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZNK6common7t_arrayIjE4sizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZNK6common7t_arrayIiE4sizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZNK6common7t_arrayIhE4sizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZNK6common7t_arrayIhE5emptyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIjE7releaseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIiE7releaseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIjE8allocateEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIiE8allocateEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN7sgi_rgb8ImageRecD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN7sgi_rgb8ImageRecD0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIjED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIiED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIiE4swapERS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIiE4fillERKi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIjE4swapERS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common7t_arrayIjE4fillERKj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common4SwapINS_7t_arrayIiE7MembersEEEvRT_S5_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgi_rgb_bwtorgba", _ZN6common4SwapINS_7t_arrayIjE7MembersEEEvRT_S5_);

