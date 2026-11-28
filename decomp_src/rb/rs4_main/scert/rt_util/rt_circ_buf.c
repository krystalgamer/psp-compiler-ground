#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_memory_allocate_init_zero(void **, unsigned int);
int rt_memory_free(void **);
typedef struct {
    unsigned int head;
    unsigned int tail;
    unsigned int size;
    unsigned int used;
    unsigned char *buf;
    int flags;
} RtCircBuf;

int rt_circ_buf_get_used(RtCircBuf *, unsigned int *);
int rt_circ_buf_normalize(RtCircBuf *, unsigned char *);
int rt_circ_buf_get_avail(RtCircBuf *, unsigned int *);
int rt_circ_buf_get_used_nowrap(RtCircBuf *, unsigned int *);
int rt_circ_buf_get_avail_nowrap(RtCircBuf *, unsigned int *);
int rt_circ_buf_normalize_with_buf(RtCircBuf *, unsigned char *, int);
void *memcpy(void *, const void *, unsigned long);

int rt_circ_buf_create(RtCircBuf *cb, unsigned int size, int flags)
{
    int ret = 2;

    if (cb == NULL)
        goto out;
    if (size == 0)
        goto out;
        cb->head = 0;
        cb->tail = 0;
        cb->size = 0;
        cb->used = 0;
        cb->buf = NULL;
        cb->flags = 0;
        if (rt_memory_allocate_init_zero((void **)&cb->buf, size) != 0)
            ret = 100;
        else if (cb->buf == NULL)
            ret = 100;
        else {
            cb->size = size;
            cb->head = 0;
            cb->tail = 0;
            cb->used = 0;
            cb->flags = flags;
            ret = 0;
        }
out:
    return ret;
}

int rt_circ_buf_destroy(RtCircBuf *cb)
{
    int ret = 2;

    if (cb != NULL) {
        if (cb->buf != NULL)
            rt_memory_free((void **)&cb->buf);
        cb->head = 0;
        cb->tail = 0;
        cb->size = 0;
        cb->used = 0;
        ret = 0;
    }
    return ret;
}

int rt_circ_buf_clear(RtCircBuf *cb)
{
    int ret = 2;

    if (cb != NULL) {
        cb->head = 0;
        cb->tail = 0;
        cb->used = 0;
        ret = 0;
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_circ_buf", rt_circ_buf_free);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_circ_buf", rt_circ_buf_use);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_circ_buf", rt_circ_buf_store);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_circ_buf", rt_circ_buf_copy);

int rt_circ_buf_normalize(RtCircBuf *cb, unsigned char *buf)
{
    if (cb == NULL)
        return 2;
    if (buf != NULL && cb->flags == 0)
        return 201;
    return rt_circ_buf_normalize_with_buf(cb, buf, cb->flags);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_circ_buf", rt_circ_buf_normalize_with_buf);

int rt_circ_buf_get_used(RtCircBuf *cb, unsigned int *out)
{
    int ret = 2;

    if (cb != NULL) {
        if (out != NULL) {
            *out = cb->used;
            ret = 0;
        }
    }
    return ret;
}

int rt_circ_buf_get_used_nowrap(RtCircBuf *cb, unsigned int *out)
{
    int ret = 2;

    if (cb != NULL) {
        if (out != NULL) {
            if (cb->used != 0) {
                if (cb->head < cb->tail)
                    *out = cb->tail - cb->head;
                else
                    *out = cb->size - cb->head;
            } else
                *out = 0;
            ret = 0;
        }
    }
    return ret;
}

int rt_circ_buf_get_avail(RtCircBuf *cb, unsigned int *out)
{
    int ret = 2;

    if (cb != NULL) {
        if (out != NULL) {
            *out = cb->size - cb->used;
            ret = 0;
        }
    }
    return ret;
}

int rt_circ_buf_get_avail_nowrap(RtCircBuf *cb, unsigned int *out)
{
    int ret = 2;

    if (cb != NULL) {
        if (out != NULL) {
            if (cb->used == cb->size)
                *out = 0;
            else if (cb->tail >= cb->head)
                *out = cb->size - cb->tail;
            else
                *out = cb->head - cb->tail;
            ret = 0;
        }
    }
    return ret;
}

int rt_circ_buf_get_start_used_ptr(RtCircBuf *cb, unsigned char **out)
{
    unsigned int used = 0;
    int ret = 2;

    if (cb == NULL)
        goto out;
    if (out == NULL)
        goto out;
    ret = rt_circ_buf_get_used(cb, &used);
    if (ret != 0)
        goto out;
    ret = 200;
    if (used == 0)
        goto out;
    *out = cb->buf + cb->head;
    ret = 0;
out:
    return ret;
}

int rt_circ_buf_get_start_avail_ptr(RtCircBuf *cb, unsigned char **out)
{
    unsigned int avail = 0;
    int ret = 2;

    if (cb == NULL)
        goto out;
    if (out == NULL)
        goto out;
    ret = rt_circ_buf_get_avail(cb, &avail);
    if (ret != 0)
        goto out;
    ret = 200;
    if (avail == 0)
        goto out;
    *out = cb->buf + cb->tail;
    ret = 0;
out:
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_circ_buf", rt_circ_buf_is_wrapped);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_circ_buf", rcsid_10E674);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_circ_buf", header_rcsid_10E6D0);
