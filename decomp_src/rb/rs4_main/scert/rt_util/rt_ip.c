#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

unsigned int rt_ip_string2ip(const char *s)
{
    unsigned int ip = 0;
    unsigned int oct = 0;
    char c;

    if (s != NULL) {
        while ((c = *s++) != 0) {
            if (c == '.') {
                ip = (ip >> 8) + (oct << 24);
                oct = 0;
            } else if (c >= '0' && c <= '9')
            {
            oct *= 2;
            oct += oct * 4;
            oct += c - '0';
        }
        }
        ip = (ip >> 8) + (oct << 24);
    }
    return ip;
}

void rt_ip_ip2string(char *buf, unsigned int ip)
{
    unsigned int i;
    unsigned int b;

    if (buf == NULL) return;
    for (i = 0; i < 4; i++) {
        b = ip & 0xFF;
        if (i != 0) *buf++ = '.';
        ip >>= 8;
        if (b >= 100) {
            *buf++ = b / 100 + '0';
            b %= 100;
            goto tens;
        }
        if (b >= 10) {
        tens:
            *buf++ = b / 10 + '0';
            b %= 10;
        }
        *buf++ = b + '0';
    }
    *buf = 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_ip", rcsid_10E8EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_ip", rt_ip_header_rcsid);
