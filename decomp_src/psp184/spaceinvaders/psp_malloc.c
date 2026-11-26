/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "m2c_macros.h"
extern int malloc_max;
extern int malloc_max_size;
extern int print_malloc_max_size;


#ifndef NULL
#define NULL ((void *)0)
#endif

void psp_malloc_init(void) {
    malloc_max = 0;
    malloc_max_size = 0;
    print_malloc_max_size = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memalign(unsigned int align, unsigned int size);
void psp_malloc(unsigned int arg0) {
    memalign(0x40U, arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memalign(unsigned int align, unsigned int size);
void psp_malloc16(unsigned int arg0) {
    memalign(0x10U, arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void free(void *p);
void psp_free(void *arg0) {
    if (arg0 != NULL) {
        free(arg0);
    }
}
