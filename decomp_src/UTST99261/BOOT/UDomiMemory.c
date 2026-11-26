/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
void *MEM_malloc(int pool, unsigned int size);
void MEM_free(int pool, void *p);
int DomiMoreMemory(void);
void *memcpy(void *d, const void *s, unsigned int n);
void *memmove(void *d, const void *s, unsigned int n);

void *UDomiMemory_Allocate(unsigned int size) {
    void *p;

    do {
        p = MEM_malloc(0, size);
    } while (p == NULL && DomiMoreMemory());
    return p;
}

void UDomiMemory_Free(void *p) {
    if (p != NULL) {
        MEM_free(0, p);
    }
}

void UDomiMemory_Copy(void *d, const void *s, unsigned int n) {
    memcpy(d, s, n);
}

void UDomiMemory_Move(void *d, const void *s, unsigned int n) {
    memmove(d, s, n);
}
