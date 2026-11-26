/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"

void SDomiPtrArray_Initialize(SDomiPtrArray *a, unsigned int grow) {
    a->grow = grow;
    a->alloc = 0;
    a->count = 0;
    a->items = NULL;
}

void SDomiPtrArray_Finalize(SDomiPtrArray *a) {
    SDomiPtrArray_Free(a);
}

void SDomiPtrArray_Free(SDomiPtrArray *a) {
    a->alloc = 0;
    a->count = 0;
    UDomiMemory_Free(a->items);
    a->items = NULL;
}

void *SDomiPtrArray_GetItem(SDomiPtrArray *a, unsigned int i) {
    return i < a->count ? a->items[i] : NULL;
}

void SDomiPtrArray_Replace(SDomiPtrArray *a, unsigned int i, void *p) {
    if (i < a->count) {
        a->items[i] = p;
    }
}

int SDomiPtrArray_Insert(SDomiPtrArray *a, unsigned int i, void *p) {
    unsigned int size;
    void **items;

    if (a->count < i) {
        i = a->count;
    }
    if (a->alloc <= a->count) {
        size = a->count + a->grow + 1;
        items = UDomiMemory_Allocate(size * sizeof(void *));
        if (items == NULL) {
            return 0;
        }
        UDomiMemory_Copy(items, a->items, i * sizeof(void *));
        items[i] = p;
        UDomiMemory_Copy(&items[i + 1], &a->items[i], (a->count - i) * sizeof(void *));
        a->alloc = size;
        a->count++;
        UDomiMemory_Free(a->items);
        a->items = items;
    } else {
        UDomiMemory_Move(&a->items[i + 1], &a->items[i], (a->count - i) * sizeof(void *));
        a->items[i] = p;
        a->count++;
    }
    return 1;
}

void SDomiPtrArray_Remove(SDomiPtrArray *a, unsigned int i) {
    if (i < a->count) {
        a->count--;
        UDomiMemory_Move(&a->items[i], &a->items[i + 1], (a->count - i) * sizeof(void *));
    }
}
