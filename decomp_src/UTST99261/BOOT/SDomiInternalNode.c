/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
int SDomiNode_OnSameDocument(SDomiNode *a, SDomiNode *b);
void SDomiNode_Reuse(SDomiNode *n);
void SDomiNode_Trash(SDomiNode *n);
void cmDomiNode_Changed(SDomiNode *n);
void SDomiNodeSetSet_DeleteAll(SDomiSLink *head);
void SDomiNodeSetSet_Free(SDomiSLink *head);
SDomiNodeSet *SDomiNodeSetSet_Prepare(SDomiSLink *head, const SDomiString *name, SDomiNode *root, int (*build)(SDomiNodeSet *));
int SDomiInternalNode_BuildNodeSet(SDomiNode *n, SDomiNodeSet *set, int deep, int (*filter)(SDomiNodeSet *, SDomiNode *));
int cmDomiInternalNode_insertBefore(SDomiInternalNode *n, SDomiNode *newChild, SDomiNode *refChild, SDomiNode **out);

static int CheckNewNode(SDomiNode *parent, SDomiNode *child) {
    SDomiNode *old;
    SDomiNode *p;

    if (!SDomiNode_OnSameDocument(parent, child)) {
        return 4;
    }
    old = child->vt->get_parentNode(child);
    child->vt->SetParentNode(child, parent);
    if (child->vt->get_parentNode(child) != parent) {
        child->vt->SetParentNode(child, old);
        return 3;
    }
    child->vt->SetParentNode(child, old);
    p = parent;
    for (;;) {
        if (p == NULL) {
            return 0;
        }
        if (p == child) {
            return 3;
        }
        p = p->vt->get_parentNode(p);
    }
}

static int ChildFilter(SDomiNodeSet *set, SDomiNode *n) {
    return 2;
}

static int DomiInternalNode_BuildChildNodeList(SDomiNodeSet *set) {
    return SDomiInternalNode_BuildNodeSet(set->root, set, 0, ChildFilter);
}

int SDomiInternalNode_BuildNodeSet(SDomiNode *n, SDomiNodeSet *set, int deep, int (*filter)(SDomiNodeSet *, SDomiNode *)) {
    SDomiNode *c;
    int f;

    for (c = n->vt->get_firstChild(n); c != NULL; c = c->vt->get_nextSibling(c)) {
f = filter(set, c);
        if (f == 1) {
            goto recurse;
        } else if (f == 0) {
        } else if (f == 2) {
            if (!SDomiPtrArray_Insert(&set->arr, set->arr.count, c)) {
                return 0;
            }
        recurse:
            if (deep && !SDomiInternalNode_BuildNodeSet(c, set, deep, filter)) {
                return 0;
            }
        }
    }
    return 1;
}

void cmDomiInternalNode_Finalize(SDomiInternalNode *n) {
    SDomiNode *c, *next;

    SDomiNodeSetSet_DeleteAll(&n->nodeSets);
    for (c = n->firstChild; c != NULL; c = next) {
        next = c->vt->get_nextSibling(c);
        c->vt->Finalize(c);
        UDomiMemory_Free(c);
    }
    cmDomiNode_Finalize(&n->n);
}

void cmDomiInternalNode_Changed(SDomiNode *n) {
    SDomiNodeSetSet_Free(&((SDomiInternalNode *)n)->nodeSets);
    cmDomiNode_Changed(n);
}

void cmDomiInternalNode_InheritObjInfo(SDomiNode *n, int flags) {
    SDomiNode *c;

    if (~n->flags & flags) {
        n->flags |= flags;
        for (c = n->vt->get_firstChild(n); c != NULL; c = c->vt->get_nextSibling(c)) {
            c->vt->InheritObjInfo(c, n->flags);
        }
    }
}

void cmDomiInternalNode_FreeTrash(SDomiInternalNode *n) {
    SDomiNode *c;

    SDomiNodeSetSet_DeleteAll(&n->nodeSets);
    for (c = n->n.vt->get_firstChild(n); c != NULL; c = c->vt->get_nextSibling(c)) {
        c->vt->FreeTrash(c);
    }
}

SDomiNodeSet *cmDomiInternalNode_get_childNodes(SDomiInternalNode *n) {
    return SDomiNodeSetSet_Prepare(&n->nodeSets, AcsExterngSnull(), &n->n, DomiInternalNode_BuildChildNodeList);
}

SDomiNode *cmDomiInternalNode_get_firstChild(SDomiInternalNode *n) {
    return n->firstChild;
}

SDomiNode *cmDomiInternalNode_get_lastChild(SDomiInternalNode *n) {
    return n->lastChild;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiInternalNode", cmDomiInternalNode_insertBefore);

int cmDomiInternalNode_removeChild(SDomiInternalNode *n, SDomiNode *old, SDomiNode **out) {
    SDomiNode *prev, *next;

    *out = NULL;
    if (old->vt->get_parentNode(old) != &n->n) {
        return 8;
    }
    prev = old->vt->get_previousSibling(old);
    next = old->vt->get_nextSibling(old);
    if (prev != NULL) {
        prev->vt->SetNextSibling(prev, next);
    } else {
        n->firstChild = next;
    }
    if (next != NULL) {
        next->vt->SetPreviousSibling(next, prev);
    } else {
        n->lastChild = prev;
    }
    old->vt->SetPreviousSibling(old, NULL);
    old->vt->SetNextSibling(old, NULL);
    old->vt->SetParentNode(old, NULL);
    SDomiNode_Trash(old);
    *out = old;
    n->n.vt->Changed(n);
    return 0;
}

int cmDomiInternalNode_hasChildNodes(SDomiInternalNode *n) {
    return n->firstChild != NULL;
}

void SDomiInternalNode_Initialize(SDomiNode *n, const SDomiNodeVt *vt, int flags, int type,
                                  SDomiDocument *doc, const SDomiStringH *name) {
    SDomiNode_Initialize(n, vt, flags, type, doc, name);
    ((SDomiInternalNode *)n)->firstChild = NULL;
    ((SDomiInternalNode *)n)->lastChild = NULL;
    ((SDomiInternalNode *)n)->nodeSets.next = &((SDomiInternalNode *)n)->nodeSets;
}

int SDomiInternalNode_CloneChildren(SDomiNode *n, SDomiNode *clone) {
    SDomiNode *c;
    SDomiNode *cc;
    SDomiNode *dummy;

    for (c = n->vt->get_firstChild(n); c != NULL; c = c->vt->get_nextSibling(c)) {
        if (c->vt->cloneNode(c, 1, &cc) != 0) {
            return 0;
        }
        if (clone->vt->insertBefore(clone, cc, NULL, &dummy) != 0) {
            return 0;
        }
    }
    return 1;
}

int cmDomiNamedNodeSet_getNamedItem(SDomiNamedNodeSet *s, const SDomiString *name, SDomiNode **out) {
    *out = NULL;
    return 0;
}

int cmDomiNamedNodeSet_setNamedItem(SDomiNamedNodeSet *s, SDomiNode *arg, SDomiNode **out) {
    *out = NULL;
    return 7;
}

int cmDomiNamedNodeSet_removeNamedItem(SDomiNamedNodeSet *s, const SDomiString *name, SDomiNode **out) {
    *out = NULL;
    return 8;
}

SDomiNode *cmDomiNamedNodeSet_item(SDomiNamedNodeSet *s, unsigned int i) {
    return NULL;
}

unsigned int cmDomiNamedNodeSet_get_length(SDomiNamedNodeSet *s) {
    return 0;
}

int cmDomiNamedNodeSet_getNamedItemNS(SDomiNamedNodeSet *s, const SDomiString *ns, const SDomiString *local, SDomiNode **out) {
    *out = NULL;
    return 0;
}

int cmDomiNamedNodeSet_setNamedItemNS(SDomiNamedNodeSet *s, SDomiNode *arg, SDomiNode **out) {
    *out = NULL;
    return 7;
}

int cmDomiNamedNodeSet_removeNamedItemNS(SDomiNamedNodeSet *s, const SDomiString *ns, const SDomiString *local, SDomiNode **out) {
    *out = NULL;
    return 8;
}
