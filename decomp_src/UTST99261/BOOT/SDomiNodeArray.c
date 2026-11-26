/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern unsigned char gDomiNodeSetEmpty;
int UDomiString_CompareBinary(const DOMChar *a, unsigned int alen, const DOMChar *b, unsigned int blen);
int SBinarySearch_Search(void *arr, unsigned int count, int (*cmp)(), const void *key, unsigned int *idx);
void SDomiNodeArray_DeleteAll(SDomiPtrArray *a);

static int NodeComparator(SDomiPtrArray *a, unsigned int i, const SDomiString *key) {
    SDomiStringData *d = ((SDomiNode *)a->items[i])->nodeName.d;

    return UDomiString_CompareBinary(d->s.str, d->s.len, key->str, key->len);
}

void SDomiNodeArray_Finalize(SDomiPtrArray *a) {
    SDomiNodeArray_DeleteAll(a);
    SDomiPtrArray_Finalize(a);
}

void SDomiNodeArray_DeleteAll(SDomiPtrArray *a) {
    unsigned int i;
    SDomiNode *n;

    for (i = a->count; i != 0; i = a->count) {
        i--;
        n = SDomiPtrArray_GetItem(a, i);
        SDomiPtrArray_Remove(a, i);
        n->vt->Finalize(n);
        UDomiMemory_Free(n);
    }
}

void SDomiNodeArray_InheritObjInfo(SDomiPtrArray *a, int flags) {
    unsigned int i;
    SDomiNode *n;

    for (i = 0; (n = SDomiPtrArray_GetItem(a, i)) != NULL; i++) {
        n->vt->InheritObjInfo(n, flags);
    }
}

void SDomiNodeArray_FreeTrash(SDomiPtrArray *a) {
    unsigned int i;
    SDomiNode *n;

    for (i = 0; (n = SDomiPtrArray_GetItem(a, i)) != NULL; i++) {
        n->vt->FreeTrash(n);
    }
}

SDomiNode *SDomiNodeArray_Find(SDomiPtrArray *a, const SDomiString *name) {
    unsigned int idx;

    if (SBinarySearch_Search(a, a->count, NodeComparator, name, &idx)) {
        return SDomiPtrArray_GetItem(a, idx);
    }
    return NULL;
}

SDomiNode *SDomiNodeArray_Remove(SDomiPtrArray *a, const SDomiString *name, unsigned int *out) {
    unsigned int idx;
    SDomiNode *n;

    if (!SBinarySearch_Search(a, a->count, NodeComparator, name, &idx)) {
        return NULL;
    }
    n = a->items[idx];
    SDomiPtrArray_Remove(a, idx);
    *out = idx;
    return n;
}

int SDomiNodeArray_Put(SDomiPtrArray *a, SDomiNode *n, SDomiNode **old, unsigned int *out) {
    unsigned int idx;

    *old = NULL;
    if (SBinarySearch_Search(a, a->count, NodeComparator, &n->nodeName.d->s, &idx)) {
        if (a->items[idx] != n) {
            *old = a->items[idx];
            a->items[idx] = n;
        }
        *out = idx;
        return 1;
    }
    *out = idx;
    return SDomiPtrArray_Insert(a, idx, n);
}

void *AcsExterngDomiNodeSetEmpty(void) {
    return &gDomiNodeSetEmpty;
}
