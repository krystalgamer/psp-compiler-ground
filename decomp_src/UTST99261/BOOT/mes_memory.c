/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"

M2C_UNK bcopy();                                    /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_memory_copy(void) {
    bcopy();
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);
void mes_memory_zero(void *arg0, unsigned int arg1) {
    memset(arg0, 0, arg1);
}
