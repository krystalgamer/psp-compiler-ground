#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_msg_set_byte(signed char *arg0, signed char arg1);

int rt_msg_set_byte(signed char *arg0, signed char arg1) {
    int var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        *arg0 = arg1;
        var_v0 = 0;
    }
    return var_v0;
}

int rt_msg_get_byte(unsigned char *buf, char *out)
{
    int ret = 2;

    if (buf != NULL) {
        if (out != NULL) {
        *out = *buf;
        ret = 0;
        }
    }
    return ret;
}

int rt_msg_set_ubyte(unsigned char *buf, unsigned char v)
{
    int ret = 2;

    if (buf != NULL) {
        *buf = v;
        ret = 0;
    }
    return ret;
}

int rt_msg_get_ubyte(unsigned char *buf, unsigned char *out)
{
    int ret = 2;

    if (buf != NULL) {
        if (out != NULL) {
        *out = *buf;
        ret = 0;
        }
    }
    return ret;
}

int rt_msg_set_2byte(unsigned char *buf, short v)
{
    int ret = 2;

    if (buf != NULL) {
        buf[0] = v;
        buf[1] = v >> 8;
        ret = 0;
    }
    return ret;
}

int rt_msg_get_2byte(unsigned char *buf, short *out)
{
    int ret = 2;

    if (buf != NULL) {
        if (out != NULL) {
        *out = buf[0];
        *out |= buf[1] << 8;
        ret = 0;
        }
    }
    return ret;
}

int rt_msg_set_u2byte(unsigned char *buf, unsigned short v)
{
    int ret = 2;

    if (buf != NULL) {
        buf[0] = v;
        buf[1] = v >> 8;
        ret = 0;
    }
    return ret;
}

int rt_msg_get_u2byte(unsigned char *buf, unsigned short *out)
{
    int ret = 2;

    if (buf != NULL) {
        if (out != NULL) {
        *out = buf[0];
        *out |= buf[1] << 8;
        ret = 0;
        }
    }
    return ret;
}

int rt_msg_set_4byte(unsigned char *buf, int v)
{
    int ret = 2;

    if (buf != NULL) {
        *buf++ = v;
        *buf++ = v >> 8;
        *buf++ = v >> 16;
        *buf = v >> 24;
        ret = 0;
    }
    return ret;
}

int rt_msg_get_4byte(unsigned char *buf, int *out)
{
    int ret = 2;

    if (buf != NULL) {
        if (out != NULL) {
        *out = *buf++;
        *out |= *buf++ << 8;
        *out |= *buf++ << 16;
        *out |= *buf << 24;
        ret = 0;
        }
    }
    return ret;
}

int rt_msg_set_u4byte(unsigned char *buf, unsigned int v)
{
    int ret = 2;

    if (buf != NULL) {
        *buf++ = v;
        *buf++ = v >> 8;
        *buf++ = v >> 16;
        *buf = v >> 24;
        ret = 0;
    }
    return ret;
}

int rt_msg_get_u4byte(unsigned char *buf, unsigned int *out)
{
    int ret = 2;

    if (buf != NULL) {
        if (out != NULL) {
        *out = *buf++;
        *out |= *buf++ << 8;
        *out |= *buf++ << 16;
        *out |= *buf << 24;
        ret = 0;
        }
    }
    return ret;
}

int rt_msg_set_2byte_be(unsigned char *buf, short v)
{
    int ret = 2;

    if (buf != NULL) {
        buf[0] = v >> 8;
        buf[1] = v;
        ret = 0;
    }
    return ret;
}

int rt_msg_get_2byte_be(unsigned char *buf, short *out)
{
    int ret = 2;

    if (buf != NULL) {
        if (out != NULL) {
        *out = buf[0] << 8;
        *out |= buf[1];
        ret = 0;
        }
    }
    return ret;
}

int rt_msg_set_u2byte_be(unsigned char *buf, unsigned short v)
{
    int ret = 2;

    if (buf != NULL) {
        buf[0] = v >> 8;
        buf[1] = v;
        ret = 0;
    }
    return ret;
}

int rt_msg_get_u2byte_be(unsigned char *buf, unsigned short *out)
{
    int ret = 2;

    if (buf != NULL) {
        if (out != NULL) {
        *out = buf[0] << 8;
        *out |= buf[1];
        ret = 0;
        }
    }
    return ret;
}

int rt_msg_set_4byte_be(unsigned char *buf, int v)
{
    int ret = 2;

    if (buf != NULL) {
        *buf++ = v >> 24;
        *buf++ = v >> 16;
        *buf++ = v >> 8;
        *buf = v;
        ret = 0;
    }
    return ret;
}

int rt_msg_get_4byte_be(unsigned char *buf, int *out)
{
    int ret = 2;

    if (buf != NULL) {
        if (out != NULL) {
        *out = *buf++ << 24;
        *out |= *buf++ << 16;
        *out |= *buf++ << 8;
        *out |= *buf;
        ret = 0;
        }
    }
    return ret;
}

int rt_msg_set_u4byte_be(unsigned char *buf, unsigned int v)
{
    int ret = 2;

    if (buf != NULL) {
        *buf++ = v >> 24;
        *buf++ = v >> 16;
        *buf++ = v >> 8;
        *buf = v;
        ret = 0;
    }
    return ret;
}

int rt_msg_get_u4byte_be(unsigned char *buf, unsigned int *out)
{
    int ret = 2;

    if (buf != NULL) {
        if (out != NULL) {
        *out = *buf++ << 24;
        *out |= *buf++ << 16;
        *out |= *buf++ << 8;
        *out |= *buf;
        ret = 0;
        }
    }
    return ret;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rcsid_10EA4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", header_rcsid_10EAA8);
