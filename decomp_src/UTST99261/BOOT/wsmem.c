/* cflags: -O1 */
#include "common.h"

typedef struct MEMBLOCK { /* header 0x10 */
    unsigned int size;
    struct MEMBLOCK *prev;
    struct MEMBLOCK *next;
    int pad;
} MEMBLOCK;

typedef struct {
    int state;
    int thread;
    void (*handler)(void);
} MEMHANDLER;

typedef struct { /* size 0xEC */
    MEMBLOCK *used;
    MEMBLOCK *first;
    MEMBLOCK *freelist;
    char *end;
    unsigned int total;
    unsigned int inuse;
    unsigned int avail;
    unsigned int peak;
    int mutex;
    void *reserve;
    unsigned int reserveSize;
    MEMHANDLER handlers[16];
} MEMHEAP;

void *memset(void *p, int c, unsigned int n);
int OS_thread_mutex_create(void);
int OS_thread_mutex_init(int m, int attr);
int OS_thread_mutex_lock(int m);
int OS_thread_mutex_unlock(int m);
int OS_thread_self(void);
void *MEM_malloc(MEMHEAP *h, unsigned int size);
void *allocate(MEMHEAP *h, int flag, unsigned int size);
int deallocate(MEMHEAP *h, void *ptr);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/wsmem", deallocate);
