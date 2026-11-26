/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
SDomiDocument *SDomiNode_GetContextDocument(SDomiNode *n);

static void PrepareArray(SDomiNodeSet *s) {
    SDomiDocument *doc;

    if (!s->valid) {
        if (s->root != NULL) {
            doc = SDomiNode_GetContextDocument(s->root);
            if (doc != NULL) {
                doc->changed = 1;
            }
        }
        if (s->build == NULL || s->build(s)) {
            s->valid = 1;
        } else {
            SDomiPtrArray_Free(&s->arr);
        }
    }
}

void SDomiNodeSet_Initialize(SDomiNodeSet *s, const SDomiStringH *name, SDomiNode *root, int (*build)(SDomiNodeSet *)) {
    s->link.next = NULL;
    SDomiStringH_Init(&s->name);
    s->root = root;
    s->build = build;
    SDomiStringH_Assign(&s->name, name);
    SDomiPtrArray_Initialize(&s->arr, 4);
    s->valid = 0;
}

void SDomiNodeSet_Finalize(SDomiNodeSet *s) {
    SDomiPtrArray_Finalize(&s->arr);
    SDomiStringH_Finalize(&s->name);
}

int SDomiNodeSet_length(SDomiNodeSet *s, unsigned int *out) {
    PrepareArray(s);
    *out = s->arr.count;
    return s->valid;
}

int SDomiNodeSet_item(SDomiNodeSet *s, unsigned int i, SDomiNode **out) {
    PrepareArray(s);
    *out = SDomiPtrArray_GetItem(&s->arr, i);
    return s->valid;
}

void SDomiNodeSet_Free(SDomiNodeSet *s) {
    SDomiPtrArray_Free(&s->arr);
    s->valid = 0;
}
