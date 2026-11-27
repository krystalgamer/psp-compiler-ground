/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

glutils::StippleMask::StippleMask()
{
    clear();
}


void glutils::StippleMask::clear()
{
    unsigned char *p = &_mask[0][0];
    for (unsigned int i = 0; i < ROWS; i++)
        for (unsigned int j = 0; j < ROW_BYTES; j++)
            *p++ = 0;
}

void glutils::StippleMask::setPixel(unsigned int x, unsigned int y, bool v)
{
    if (x < 32) {
        if (y < 32) {
            unsigned int byte = x / 8;
            unsigned int bit = x - byte * 8;
            unsigned char *p = (unsigned char *)this + (y * ROW_BYTES + byte);
            unsigned int s = 7 - bit;
            if (v)
                *p |= 1 << s;
            else
                *p &= ~(1 << s);
        }
    }
}

void *glutils::StippleMask::mask()
{
    return this;
}

void glutils::StippleMask::sparse(unsigned char sy, unsigned char sx)
{
    clear();
    for (unsigned int y = 0; y < ROWS; y += sy)
        for (unsigned int x = 0; x < 32; x += sx)
            setPixel(x, y, true);
}

void glutils::StippleMask::sparse(unsigned char s)
{
    clear();
    for (unsigned int y = 0; y < ROWS; y += s)
        for (unsigned int x = 0; x < 32; x += s)
            setPixel(x, y, true);
}

void glutils::StippleMask::checker(unsigned char a, unsigned char b)
{
    clear();
    if (a == 1 && b == 1) {
        unsigned char *p = &_mask[0][0];
        for (unsigned int y = 0; y < ROWS; y++)
            for (unsigned int j = 0; j < ROW_BYTES; j++)
                *p++ = (y & 1) ? 0xAA : 0x55;
    } else {
        if (a >= 32)
            a = 31;
        if (b >= 32)
            b = 31;
        for (unsigned int y = 0; y < 32; y++)
            for (unsigned int x = 0; x < 32; x++)
                setPixel(x, y, (x / a + y / b) & 1);
    }
}

void glutils::StippleMask::checker(unsigned char c)
{
    checker(c, c);
}

void glutils::StippleMask::diagonal(unsigned char step, bool dir)
{
    clear();
    int d = dir ? -1 : 1;
    int off = 0;
    for (int y = 0; y < 32; y++) {
        for (int x = 0; x < 32; x += step) {
            int px = x + off;
            while (px >= 32)
                px -= 32;
            while (px < 0)
                px += 32;
            setPixel(px, y, true);
        }
        off += d;
    }
}
