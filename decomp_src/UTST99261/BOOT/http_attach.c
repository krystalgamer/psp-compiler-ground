/* cflags: -O1 */
#include "common.h"
typedef struct DumyArg {
    void (*func)(void *);
    void *arg;
} DumyArg;

int dumyFunc_req(int a, DumyArg *p)
{
    p->func(p->arg);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/http_attach", http_attach);
