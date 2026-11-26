/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
int SDomiAttr_set_value(SDomiAttr *a, const SDomiStringH *v);
void cmDomiInternalNode_Finalize(SDomiNode *n);

int SBinarySearch_Search(void *base, unsigned int n, int (*cmp)(void *, unsigned int, void *), void *key, unsigned int *out) {
    unsigned int lo = 0;
    unsigned int hi = n;
    unsigned int mid;
    int r;

    while (lo < hi) {
        mid = (lo + hi) >> 1;
        r = cmp(base, mid, key);
        if (r == 0) {
            *out = mid;
            return 1;
        }
        if (r < 0) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    *out = lo;
    return 0;
}

void cmDomiAttr_Finalize(SDomiNode *n) {
    SDomiStringH_Finalize(&((SDomiAttr *)n)->value);
    cmDomiInternalNode_Finalize(n);
}

int cmDomiAttr_get_nodeValue(SDomiNode *n, SDomiString *out) {
    *out = ((SDomiAttr *)n)->value.d->s;
    return 0;
}

int cmDomiAttr_set_nodeValue(SDomiNode *n, const SDomiString *s) {
    SDomiAttr *a = (SDomiAttr *)n;
    if (SDomiStringH_Set(&a->value, s)) {
        return SDomiAttr_set_value(a, &a->value);
    }
    return -1;
}

int cmDomiAttr_cloneNode(SDomiNode *n, int deep, SDomiNode **out) {
    SDomiNode *clone;
    SDomiNode *doc;
    int r;

    *out = NULL;
    doc = (SDomiNode *)n->ownerDocument;
    r = doc->vt->createAttribute(doc, &n->nodeName, &clone);
    if (r == 0) {
        SDomiStringH_Assign(&((SDomiAttr *)clone)->value, &((SDomiAttr *)n)->value);
        if (!deep || SDomiInternalNode_CloneChildren(n, clone)) {
            *out = clone;
        } else {
            r = -1;
        }
    }
    return r;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SBinarySearch", D_0013CAB4);
