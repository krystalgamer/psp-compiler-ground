#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_list_buf_normalize(void);
int rt_memory_free(void **);
typedef struct {
    unsigned int count;
    unsigned int size;
    unsigned int blk;
    unsigned int n;
    char *buf;
    unsigned char *used;
} RtListPool;
typedef struct RtListNode {
    unsigned int len;
    struct RtListNode *next;
} RtListNode;
typedef struct {
    unsigned int max;
    unsigned int used;
    RtListPool *pool;
    RtListNode *head;
} RtList;
typedef struct {
    struct { void *ptr; unsigned int len; } e[8];
    unsigned int total;
    int count;
} RtListData;
int rt_memory_allocate(void **, unsigned int);

void *memset(void *, int, unsigned int);
void *memcpy(void *, const void *, unsigned long);
void *pool_alloc(RtListPool *, unsigned int);
void pool_free(RtListPool *, void *);
int rt_list_buf_remove(RtList *, RtListNode *);
void rt_list_buf_clear(RtList *);
int rt_list_buf_insert(RtList *, RtListNode *, RtListData *);

int rt_list_buf_create_pool(RtListPool *pool, unsigned int size, unsigned int blk)
{
    int ret = 2;
    unsigned int n, rem;
    int rc;

    if (pool == NULL)
        goto out;
    if ((size & 3) != 0)
        goto out;
    if ((blk & 3) != 0)
        goto out;
    if (blk >= size)
        goto out;
    memset(pool, 0, sizeof(*pool));
    rc = rt_memory_allocate((void **)&pool->buf, size);
    if (rc != 0) {
        ret = rc;
        goto out;
    }
    pool->size = size;
    pool->blk = blk;
    pool->count = 0;
    pool->n = size / blk;
    rem = size % blk;
    if (rem < pool->n)
        pool->n = pool->n - (pool->n - rem) / blk;
    pool->used = (unsigned char *)pool->buf + pool->n * pool->blk;
    memset(pool->used, 0, pool->n);
    ret = 0;
out:
    return ret;
}

int rt_list_buf_destroy_pool(RtListPool *pool)
{
    int ret = 2;

    if (pool != NULL) {
        rt_memory_free((void **)&pool->buf);
        memset(pool, 0, sizeof(*pool));
        ret = 0;
    }
    return ret;
}

int rt_list_buf_get_pool_used(RtListPool *pool, unsigned int *used)
{
    unsigned int i;
    unsigned int n = 0;
    int ret = 2;

    if (pool != NULL)
        if (used != NULL) {
            *used = 0;
            for (i = 0; i < pool->n; i++)
                if (pool->used[i] != 0)
                    n++;
            *used = n * pool->blk;
            ret = 0;
        }
    return ret;
}

int rt_list_buf_create(RtList *list, RtListPool *pool, unsigned int max)
{
    int ret = 2;

    if (list != NULL)
        if (pool != NULL)
            if (max >= 9) {
                memset(list, 0, sizeof(*list));
                list->max = max;
                list->pool = pool;
                pool->count++;
                ret = 0;
            }
    return ret;
}

void rt_list_buf_destroy(RtList *list)
{
    if (list != NULL)
        if (list->pool != NULL)
            if (list->max != 0) {
                rt_list_buf_clear(list);
                list->pool->count--;
                memset(list, 0, sizeof(*list));
            }
}

void rt_list_buf_clear(RtList *list)
{
    RtListNode *n;

    if (list != NULL)
        if (list->pool != NULL)
            if (list->max != 0)
                for (n = list->head; n != NULL; n = n->next)
                    rt_list_buf_remove(list, n);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_insert);

int rt_list_buf_set_new_head(RtList *list, RtListData *d)
{
    return rt_list_buf_insert(list, NULL, d);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_remove);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_append_data);

RtListNode *rt_list_buf_get_tail(RtList *list)
{
    RtListNode *n = NULL;
    RtListNode *p;

    if (list != NULL)
        if (list->pool != NULL)
            if (list->max != 0)
                if (list->head != NULL)
                    for (p = list->head; p != NULL; p = p != NULL ? p->next : NULL)
                        n = p;
    return n;
}

int rt_list_buf_normalize(void)
{
    return 0;
}

int rt_list_buf_resize_buffer(RtList *list, unsigned int max)
{
    int ret = 2;

    if (list != NULL)
        if (list->pool != NULL)
            if (list->max != 0)
                if (max >= 9) {
                    list->max = max;
                    ret = 0;
                }
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", pool_alloc);

void pool_free(RtListPool *p, void *ptr)
{
    unsigned int off, idx, n, i;

    if (p == NULL) return;
    if (ptr == NULL) return;
    off = (char *)ptr - p->buf;
    if (off % p->blk != 0) return;
    idx = off / p->blk;
    n = p->used[idx] & 0x7F;
    for (i = 0; i < n; i++)
        p->used[idx + i] = 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rcsid_10C164);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_header_rcsid);
