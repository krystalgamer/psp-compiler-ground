/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern const SDomiNodeVt gDomiNotationVt;

void SDomiNotation_Initialize(SDomiNode *n, struct SDomiDocument *doc, const SDomiStringH *name) {
    SDomiNotation *no = (SDomiNotation *)n;

    SDomiNode_Initialize(n, &gDomiNotationVt, 1, 12, doc, name);
    no->x20 = NULL;
    SDomiStringH_Init(&no->publicId);
    SDomiStringH_Init(&no->systemId);
}

void cmDomiProcessingInstruction_Finalize(SDomiNode *n) {
    SDomiStringH_Finalize(&((SDomiProcessingInstruction *)n)->data);
    cmDomiNode_Finalize(n);
}

int cmDomiProcessingInstruction_get_nodeValue(SDomiNode *n, SDomiString *out) {
    *out = ((SDomiProcessingInstruction *)n)->data.d->s;
    return 0;
}

int cmDomiProcessingInstruction_set_nodeValue(SDomiNode *n, const SDomiString *s) {
    return SDomiStringH_Set(&((SDomiProcessingInstruction *)n)->data, s) ? 0 : -1;
}

int cmDomiProcessingInstruction_cloneNode(SDomiNode *n, int deep, SDomiNode **out) {
    SDomiNode *clone;
    struct SDomiDocument *doc;
    int r;

    *out = NULL;
    doc = n->ownerDocument;
    r = ((SDomiNode *)doc)->vt->createProcessingInstruction(doc, &n->nodeName, &((SDomiProcessingInstruction *)n)->data, &clone);
    if (r == 0) {
        *out = clone;
    }
    return r;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiNotation", D_0013517C);
