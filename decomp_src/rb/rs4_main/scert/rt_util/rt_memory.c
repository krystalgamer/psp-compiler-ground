#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_memory_align_free(void **);
int rt_memory_allocate_init_zero(void **, unsigned int);
int rt_memory_free(void **);
int rt_memory_get_aligned_address(unsigned int *, unsigned int, int);
int rt_memory_register_another_callback(int);
int rt_memory_register_callbacks(int, int);
typedef struct { void *base; void *aligned; } RtAlignedMem;
void *malloc(unsigned int);
void *realloc(void *, unsigned int);
void free(void *);

int rt_memory_align_alloc(RtAlignedMem *, unsigned int, unsigned short);
void *memset(void *s, int c, unsigned int n);

int rt_memory_allocate();
extern void *gpfFreeCallback;
extern void *gpfMallocCallback;
extern void *gpfReallocCallback;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_memory", rt_memory_allocate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_memory", rt_memory_reallocate);

int rt_memory_allocate_init_zero(void **arg0, unsigned int arg1) {
    int temp_v0;
    int var_v1;
    void *temp_v0_2;

    var_v1 = 0x64;
    if (arg0 != NULL) {
        *arg0 = NULL;
        temp_v0 = rt_memory_allocate();
        var_v1 = temp_v0;
        if (temp_v0 == 0) {
            temp_v0_2 = *arg0;
            var_v1 = 0x64;
            if (temp_v0_2 != NULL) {
                memset(temp_v0_2, 0, arg1);
                var_v1 = 0;
            }
        }
    }
    return var_v1;
}

int rt_memory_free(void **p)
{
    if (*p != NULL) {
        if (gpfFreeCallback == NULL)
            free(*p);
        else
            ((void (*)(void *))gpfFreeCallback)(*p);
        *p = NULL;
    }
    return 0;
}

int rt_memory_align_alloc(RtAlignedMem *m, unsigned int size, unsigned short align)
{
    int ret = 100;

    if (((m == NULL) | (size == 0)) == 0) {
        m->base = NULL;
        m->aligned = NULL;
        if (align >= 2) {
            size = size + align - 1;
            size += align - size % align;
        }
        ret = rt_memory_allocate(&m->base, size);
        if (ret == 0)
            ret = rt_memory_get_aligned_address((unsigned int *)&m->aligned, (unsigned int)m->base, align);
    }
    return ret;
}

int rt_memory_align_alloc_init_zero(RtAlignedMem *m, unsigned int size, unsigned short al)
{
    int r;
    if (m == NULL || size == 0) return 100;
    ((int *)m)[0] = 0;
    ((int *)m)[1] = 0;
    r = rt_memory_align_alloc(m, size, al);
    if (r != 0) return r;
    if (((void **)m)[1] == NULL) return 100;
    memset(((void **)m)[1], 0, size);
    return 0;
}

int rt_memory_align_free(void **p)
{
    int r;
    if (p == NULL) return 100;
    if (p[0] != NULL) {
        r = rt_memory_free(p);
        if (r != 0) return r;
        p[0] = NULL;
    }
    p[1] = NULL;
    return 0;
}

int rt_memory_register_callbacks(int arg0, int arg1) {
    gpfMallocCallback = arg0;
    gpfFreeCallback = arg1;
    return 0;
}

int rt_memory_register_another_callback(int arg0) {
    gpfReallocCallback = arg0;
    return 0;
}

int rt_memory_get_aligned_address(unsigned int *arg0, unsigned int arg1, int arg2) {
    int var_a3;
    unsigned int temp_hi;
    unsigned int temp_v1;

    temp_v1 = arg2 & 0xFFFF;
    var_a3 = 0x64;
    if (((arg0 == NULL) | (arg1 == 0)) == 0) {
        *arg0 = arg1;
        var_a3 = 0;
        if (temp_v1 >= 2U) {
            temp_hi = arg1 % temp_v1;
            if (temp_hi != 0) {
                *arg0 = arg1 + (temp_v1 - temp_hi);
            }
        }
    }
    return var_a3;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_memory", rcsid_10E994);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_memory", header_rcsid_10E9F0);
