/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern const SDomiNodeVt gDomiAttrVt;
int SDomiElement_setAttributeNode(SDomiElement *e, SDomiAttr *a, SDomiAttr **old);

void SDomiAttr_Initialize(SDomiAttr *n, SDomiDocument *doc, const SDomiStringH *name) {
    SDomiInternalNode_Initialize(&n->i.n, &gDomiAttrVt, 0, 2, doc, name);
    SDomiStringH_Init(&n->value);
    n->specified = 0;
}

int SDomiAttr_set_value(SDomiAttr *a, const SDomiStringH *v) {
    SDomiAttr *old;
    SDomiStringH_Assign(&a->value, v);
    if (a->ownerElement != NULL) {
        return SDomiElement_setAttributeNode(a->ownerElement, a, &old);
    }
    return 0;
}
