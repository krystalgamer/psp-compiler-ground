/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"

void SDomiNode_Initialize(SDomiNode *n, const SDomiNodeVt *vt, int flags, int type,
                          SDomiDocument *doc, const SDomiStringH *name) {
    n->vt = vt;
    n->flags = flags;
    n->nodeType = type;
    n->trash.next = NULL;
    n->ownerDocument = doc;
    SDomiStringH_Init(&n->nodeName);
    SDomiStringH_Assign(&n->nodeName, name);
    n->x14 = NULL;
    n->x1C = NULL;
}

SDomiDocument *SDomiNode_GetContextDocument(SDomiNode *n) {
    SDomiDocument *doc = n->ownerDocument;

    if (doc == NULL) {
        doc = n->nodeType == 9 ? (SDomiDocument *)n : NULL;
    }
    return doc;
}

void SDomiNode_Trash(SDomiNode *n) {
    SDomiDocument *doc = n->ownerDocument;

    if (doc != NULL) {
        SDomiSLink_Insert(&doc->trash, &n->trash);
    }
}

void SDomiNode_Reuse(SDomiNode *n) {
    SDomiDocument *doc = n->ownerDocument;

    if (doc != NULL) {
        SDomiSLink_Remove(&doc->trash, &n->trash);
    }
}

int SDomiNode_OnSameDocument(SDomiNode *a, SDomiNode *b) {
    SDomiDocument *doc = SDomiNode_GetContextDocument(a);

    return (doc == SDomiNode_GetContextDocument(b)) & (doc != NULL);
}

int SDomiNode_replaceChild(SDomiNode *n, SDomiNode *newChild, SDomiNode *oldChild, SDomiNode **out) {
    SDomiNode *dummy;
    int r;

    *out = NULL;
    r = n->vt->insertBefore(n, newChild, oldChild, &dummy);
    if (r == 0) {
        r = n->vt->removeChild(n, oldChild, out);
    }
    return r;
}

int SDomiNode_normalize(SDomiNode *n) {
    SDomiString s;
    SDomiNode *removed;
    SDomiNode *child, *next;
    SDomiNamedNodeSet *attrs;
    unsigned int i;
    int r;

    for (child = n->vt->get_firstChild(n); child != NULL; child = child->vt->get_nextSibling(child)) {
        if (child->nodeType == 3) {
            for (;;) {
                next = child->vt->get_nextSibling(child);
                if (next == NULL || next->nodeType != 3) {
                    break;
                }
                s.len = ((SDomiCharacterData *)next)->data.len;
                s.str = ((SDomiCharacterData *)next)->data.buf;
                r = SDomiStrAcu_Insert(&((SDomiCharacterData *)child)->data, ((SDomiCharacterData *)child)->data.len, &s) ? 0 : -1;
                if (r != 0) {
                    return r;
                }
                SDomiCharacterData_set_data((SDomiCharacterData *)next, AcsExterngSnull());
                r = n->vt->removeChild(n, next, &removed);
                if (r != 0) {
                    return r;
                }
            }
            if (((SDomiCharacterData *)child)->data.len == 0) {
                next = child;
                child = child->vt->get_nextSibling(child);
                n->vt->removeChild(n, next, &removed);
            }
        } else {
            r = SDomiNode_normalize(child);
            if (r != 0) {
                return r;
            }
        }
    }
    attrs = n->vt->get_attributes(n);
    if (attrs != NULL) {
        for (i = 0; (child = attrs->vt->item(attrs, i)) != NULL; i++) {
            r = SDomiNode_normalize(child);
            if (r != 0) {
                return r;
            }
        }
    }
    return 0;
}
