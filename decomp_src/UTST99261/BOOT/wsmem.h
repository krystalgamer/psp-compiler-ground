#ifndef WSMEM_H
#define WSMEM_H
/* browser memory pools (wsmem.c) */

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

int mem_init(void *mem, unsigned int size);
void *mem_alloc(MEMHEAP *h, int flag, unsigned int size);
int mem_free(MEMHEAP *h, void *ptr);
int deallocate(MEMHEAP *h, void *ptr);
int OS_thread_mutex_destroy(int m);
void *memcpy(void *d, const void *s, unsigned int n);

extern MEMHEAP *mem_defaultPool;

#endif
