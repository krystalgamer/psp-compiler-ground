#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
typedef struct { unsigned char *start; unsigned char *end; unsigned char *cur; int c; int err; } RtPackBuf;
void memcpy();

int rt_init_pack_buffer(RtPackBuf *b, unsigned char *buf, unsigned char *end)
{
    if (b == NULL) return 0;
    b->err = 0;
    b->start = buf;
    b->cur = buf;
    b->end = end;
    b->c = 0;
    if (buf == NULL) {
        b->err = 2;
        return 0;
    }
    if (end == NULL) {
        b->err = 2;
        return 0;
    }
    if (buf >= end) {
        b->err = 2;
        return 0;
    }
    return 1;
}

int rt_pack_anything(int mode, RtPackBuf *b, void *data, unsigned int len)
{
    if (mode == 1 && b->err != 0) return 0;
    if (b->end <= b->cur) {
        b->err = 2;
        return 0;
    }
    if (b->cur == NULL) {
        b->err = 2;
        return 0;
    }
    if (data == NULL) {
        b->err = 2;
        return 0;
    }
    if ((unsigned int)(b->end - b->cur) < len) {
        b->err = 8;
        return 0;
    }
    if (mode == 1)
        memcpy(b->cur, data, len);
    else if (mode == 2)
        memcpy(data, b->cur, len);
    b->cur += len;
    return 1;
}

int rt_pack_1byte(int mode, RtPackBuf *b, unsigned char *data)
{
    if (b->err != 0) return 0;
    if (b->end <= b->cur || b->cur == NULL) {
        b->err = 2;
        return 0;
    }
    if ((unsigned int)(b->end - b->cur) < 1) {
        b->err = 8;
        return 0;
    }
    if (mode == 1)
        *b->cur = *data;
    else if (mode == 2)
        *data = *b->cur;
    b->cur++;
    return 1;
}

int rt_pack_cu2byte(int mode, RtPackBuf *b, unsigned short *data)
{
    if (b->err != 0) return 0;
    if (b->end <= b->cur) {
        b->err = 2;
        return 0;
    }
    if (b->cur == NULL) {
        b->err = 2;
        return 0;
    }
    if ((unsigned int)(b->end - b->cur) < 4) {
        b->err = 8;
        return 0;
    }
    if (mode == 1) {
        if (*data >= 0x7FFF) {
            b->err = 2;
            return 0;
        }
        if (*data >= 0x80) {
            *b->cur = (*data >> 8) | 0x80;
            b->cur++;
        }
        *b->cur = *data;
    } else if (mode == 2) {
        *data = *b->cur;
        if (*data & 0x80) {
            *data = (*data << 8) & 0x7FFF;
            b->cur++;
            *data |= *b->cur;
        }
        if (*data >= 0x7FFF) {
            b->err = 2;
            return 0;
        }
    }
    b->cur++;
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_pack", rt_pack_cstring);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_pack", rcsid_10ED94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_pack", header_rcsid_10EDEC);
