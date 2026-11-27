/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/wsmem.h"

void *allocate(MEMHEAP *h, int flag, unsigned int size);

void MEM_agent(MEMHEAP *pool, int flag);

int MEM_init(MEMHEAP *pool, void *mem, unsigned int size) {
    if (pool == NULL) {
        mem_defaultPool = mem;
    }
    if (mem_init(mem, size) < 0) {
        if (pool == NULL) {
            mem_defaultPool = NULL;
        }
        return -1;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void MEM_destroy(MEMHEAP *pool) {
    MEMHEAP *h;
    int m;

    h = pool;
    if (pool == NULL) {
        h = mem_defaultPool;
    }
    if (h != NULL) {
        m = h->mutex;
        h->mutex = 0;
        OS_thread_mutex_destroy(m);
        if (h->reserve != NULL) {
            deallocate(h, h->reserve);
            h->reserve = NULL;
            h->reserveSize = 0;
        }
        MEM_agent(h, 1);
    }
    if (pool == NULL) {
        mem_defaultPool = NULL;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

MEMHEAP *MEM_attach(MEMHEAP *pool) {
    if (pool == NULL) {
        pool = mem_defaultPool;
    }
    return pool;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *MEM_malloc(MEMHEAP *pool, unsigned int size) {
    if (pool == NULL) {
        pool = mem_defaultPool;
    }
    return mem_alloc(pool, 1, size);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *MEM_calloc(MEMHEAP *pool, unsigned int size) {
    void *p;

    if (pool == NULL) {
        pool = mem_defaultPool;
    }
    p = mem_alloc(pool, 1, size);
    if (p != NULL) {
        memset(p, 0, size);
    }
    return p;
}

void *MEM_realloc(MEMHEAP *pool, void *p, unsigned int size) {
    void *n;
    MEMHEAP *h;

    h = pool ? pool : mem_defaultPool;
    if (p == NULL) {
        return mem_alloc(h, 1, size);
    }
    if (size == 0) {
        mem_free(h, p);
        return NULL;
    }
    n = mem_alloc(h, 1, size);
    if (n == NULL) {
        return NULL;
    }
    memcpy(n, p, size);
    mem_free(h, p);
    return n;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void MEM_free(MEMHEAP *pool, void *p) {
    if (pool == NULL) {
        pool = mem_defaultPool;
    }
    mem_free(pool, p);
}

void *MEM_addHaltCallback(MEMHEAP *h_, void (*handler)(void)) {
    void *old;
    int self;
    int i;
    MEMHEAP *h;

    h = h_;
    if (h == NULL) {
        h = mem_defaultPool;
    }
    old = NULL;
    self = OS_thread_self();
    OS_thread_mutex_lock(h->mutex);
    for (i = 0; i < 16; i++) {
        if (h->handlers[i].state != 0 && h->handlers[i].thread == self) {
            old = h->handlers[i].handler;
            h->handlers[i].handler = handler;
            break;
        }
    }
    if (i >= 16) {
        for (i = 0; i < 16; i++) {
            if (h->handlers[i].state == 0) {
                h->handlers[i].state = 1;
                h->handlers[i].thread = self;
                h->handlers[i].handler = handler;
                break;
            }
        }
    }
    OS_thread_mutex_unlock(h->mutex);
    return old;
}

void MEM_agent(MEMHEAP *pool, int flag) {
    MEMBLOCK *b;
    unsigned int max;
    unsigned int min;

    if (pool == NULL) {
        pool = mem_defaultPool;
    }
    if (pool->mutex != 0) {
        OS_thread_mutex_lock(pool->mutex);
    }
    min = 0xFFFFFFFF;
    max = 0;
    for (b = pool->freelist; b != NULL; b = b->next) {
        if (max < b->size) {
            max = b->size;
        }
        if (b->size < min && b->size != 0) {
            min = b->size;
        }
    }
    if (pool->mutex != 0) {
        OS_thread_mutex_unlock(pool->mutex);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int MEM_checkViolation(void) {
    return 0;
}

int mem_init(void *mem, unsigned int size) {
    MEMHEAP *h;
    char *p;
    unsigned int pad;

    if (size <= 0x10C) {
        return -1;
    }
    h = mem;
    memset(h, 0, sizeof(MEMHEAP));
    p = (char *)h + sizeof(MEMHEAP);
    size -= sizeof(MEMHEAP);
    if (((unsigned int)p & 7) != 0) {
        pad = 8 - ((unsigned int)p & 7);
        p += pad;
        size -= pad;
    }
    h->used = NULL;
    h->first = (MEMBLOCK *)p;
    h->first->next = NULL;
    h->first->prev = h->first + 1;
    h->first->size = 0;
    size -= sizeof(MEMBLOCK);
    (h->first + 1)->next = h->first;
    (h->first + 1)->prev = NULL;
    (h->first + 1)->size = size;
    h->freelist = h->first + 1;
    h->end = (char *)(h->first + 1) + size;
    h->avail = size;
    h->mutex = OS_thread_mutex_create();
    if (OS_thread_mutex_init(h->mutex, 0) != 0) {
        return -1;
    }
    h->reserve = MEM_malloc(h, 0x2000);
    h->reserveSize = h->reserve != NULL ? 0x2000 : 0;
    return 0;
}

void *mem_alloc(MEMHEAP *h, int flag, unsigned int size) {
    void *p;
    int self;
    unsigned int n;
    int i;

    if (size == 0) {
        return NULL;
    }
    OS_thread_mutex_lock(h->mutex);
    p = allocate(h, flag, size);
    if (p == NULL) {
        self = OS_thread_self();
        if (h->reserve != NULL) {
            n = h->reserveSize * 2 / 3;
            deallocate(h, h->reserve);
            h->reserve = NULL;
            h->reserveSize = 0;
            if (n != 0) {
                h->reserve = allocate(h, flag, n);
                if (h->reserve != NULL) {
                    h->reserveSize = n;
                }
            }
        }
        for (i = 0; i < 16; i++) {
            if (h->handlers[i].thread == self && h->handlers[i].state != 2) {
                if (h->handlers[i].handler == NULL) {
                    break;
                }
                h->handlers[i].state = 2;
                OS_thread_mutex_unlock(h->mutex);
                h->handlers[i].handler();
                return NULL;
            }
        }
    }
    OS_thread_mutex_unlock(h->mutex);
    return p;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsmem", allocate);

int mem_free(MEMHEAP *h, void *ptr) {
    int ret;

    OS_thread_mutex_lock(h->mutex);
    ret = deallocate(h, ptr);
    OS_thread_mutex_unlock(h->mutex);
    return ret;
}

int deallocate(MEMHEAP *h, void *p)
{
    MEMBLOCK *b;
    MEMBLOCK *prev;
    MEMBLOCK *next;
    MEMBLOCK *f;
    MEMBLOCK *n;

    if (p == NULL)
        return -1;
    if ((void *)h >= p)
        return -1;
    if ((char *)p >= h->end)
        return -1;
    b = (MEMBLOCK *)p - 1;
    if (b < h->first)
        return -1;
    if ((char *)b >= h->end)
        return -1;
    prev = b->prev;
    next = b->next;
    if (b->size == 0)
        return -1;
    if (prev != NULL) {
        if (prev < h->first)
            return -1;
        if ((char *)prev >= h->end)
            return -1;
    }
    if (next != NULL && !(next >= h->first && (char *)next < h->end))
        return -1;
    h->total = h->total - b->size + 0x10;
    h->inuse -= b->size;
    h->avail += b->size;
    if (prev != NULL)
        prev->next = next;
    if (next != NULL)
        next->prev = prev;
    else
        h->used = prev;
    f = h->freelist;
    while (b < f)
        f = f->next;
    if ((char *)f + f->size == (char *)b) {
        f->size += b->size;
        b = f;
    } else {
        b->next = f;
        b->prev = f->prev;
        f->prev = b;
        if (b->prev != NULL)
            b->prev->next = b;
    }
    n = (MEMBLOCK *)((char *)b + b->size);
    if (n == b->prev) {
        b->size += n->size;
        b->prev = n->prev;
        if (b->prev != NULL)
            b->prev->next = b;
    }
    if (b->prev == NULL)
        h->freelist = b;
    return 0;
}
