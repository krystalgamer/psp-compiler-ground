/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern const SDomiNodeVt gDomiEntityVt;

void SDomiEntity_Initialize(SDomiEntity *n, SDomiDocument *doc, const SDomiStringH *name) {
    SDomiInternalNode_Initialize(&n->i.n, &gDomiEntityVt, 1, 6, doc, name);
    n->x2C = NULL;
    SDomiStringH_Init(&n->publicId);
    SDomiStringH_Init(&n->systemId);
    SDomiStringH_Init(&n->notationName);
}

int cmDomiEntityReference_cloneNode(SDomiNode *n, int deep, SDomiNode **out) {
    SDomiNode *clone;
    SDomiNode *doc;
    int r;

    *out = NULL;
    doc = (SDomiNode *)n->ownerDocument;
    r = doc->vt->createEntityReference(doc, &n->nodeName, &clone);
    if (r == 0) {
        if (!deep || SDomiInternalNode_CloneChildren(n, clone)) {
            *out = clone;
        } else {
            r = -1;
        }
    }
    return r;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiEntity", D_0013509C);
