/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern const SDomiNodeVt gDomiEntityReferenceVt;

void SDomiEntityReference_Initialize(SDomiTrunkNode *n, SDomiDocument *doc, const SDomiStringH *name) {
    SDomiTrunkNode_Initialize(n, &gDomiEntityReferenceVt, 1, 5, doc, name);
}

void cmDomiExternalNode_SetParentNode(SDomiExternalNode *n, SDomiNode *p) {
    n->parentNode = p;
}

void cmDomiExternalNode_SetPreviousSibling(SDomiExternalNode *n, SDomiNode *p) {
    n->previousSibling = p;
}

void cmDomiExternalNode_SetNextSibling(SDomiExternalNode *n, SDomiNode *p) {
    n->nextSibling = p;
}

SDomiNode *cmDomiExternalNode_get_parentNode(SDomiExternalNode *n) {
    return n->parentNode;
}

SDomiNode *cmDomiExternalNode_get_previousSibling(SDomiExternalNode *n) {
    return n->previousSibling;
}

SDomiNode *cmDomiExternalNode_get_nextSibling(SDomiExternalNode *n) {
    return n->nextSibling;
}
