/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"

int SDomiText_splitText(SDomiCharacterData *n, unsigned int off, SDomiNode **out) {
    unsigned int len = n->data.len;
    SDomiNode *clone;
    SDomiNode *dummy;
    SDomiNode *parent;
    int r;

    *out = NULL;
    if (len < off) {
        return 1;
    }
    r = n->e.n.vt->cloneNode(n, 0, &clone);
    if (r == 0) {
        parent = n->e.n.vt->get_parentNode(n);
        if (parent != NULL) {
            r = parent->vt->insertBefore(parent, clone, n->e.n.vt->get_nextSibling(n), &dummy);
            if (r != 0) {
                return r;
            }
        }
        SDomiCharacterData_deleteData(n, off, len - off);
        SDomiCharacterData_deleteData((SDomiCharacterData *)clone, 0, off);
        *out = clone;
    }
    return r;
}

void cmDomiTrunkNode_Changed(SDomiTrunkNode *n) {
    SDomiNode *parent;
    SDomiDocument *doc;

    cmDomiInternalNode_Changed(&n->i.n);
    parent = n->parentNode;
    if (parent != NULL) {
        doc = n->i.n.ownerDocument;
        if (doc == NULL || doc->changed != 0) {
            parent->vt->Changed(parent);
        }
    }
}

void cmDomiTrunkNode_SetParentNode(SDomiTrunkNode *n, SDomiNode *p) {
    n->parentNode = p;
}

void cmDomiTrunkNode_SetPreviousSibling(SDomiTrunkNode *n, SDomiNode *p) {
    n->previousSibling = p;
}

void cmDomiTrunkNode_SetNextSibling(SDomiTrunkNode *n, SDomiNode *p) {
    n->nextSibling = p;
}

SDomiNode *cmDomiTrunkNode_get_parentNode(SDomiTrunkNode *n) {
    return n->parentNode;
}

SDomiNode *cmDomiTrunkNode_get_previousSibling(SDomiTrunkNode *n) {
    return n->previousSibling;
}

SDomiNode *cmDomiTrunkNode_get_nextSibling(SDomiTrunkNode *n) {
    return n->nextSibling;
}
