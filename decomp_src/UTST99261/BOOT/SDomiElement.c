/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern SDomiString gSwildcard;
extern const SDomiNodeVt gDomiElementVt;
extern const SDomiNamedNodeSetVt gSDomiElementNamedNodeSetVt;
int UDomiString_CompareBinary(const DOMChar *a, unsigned int alen, const DOMChar *b, unsigned int blen);
int SDomiNode_OnSameDocument(SDomiNode *a, SDomiNode *b);
void SDomiNode_Reuse(SDomiNode *n);
void SDomiNode_Trash(SDomiNode *n);
void SDomiNamedNodeSet_Initialize(SDomiNamedNodeSet *s, const SDomiNamedNodeSetVt *vt, SDomiNode *owner);
SDomiNodeSet *SDomiNodeSetSet_Prepare(SDomiSLink *head, const SDomiString *name, SDomiNode *root, int (*build)(SDomiNodeSet *));
int SDomiInternalNode_BuildNodeSet(SDomiNode *n, SDomiNodeSet *set, int deep, int (*filter)(SDomiNodeSet *, SDomiNode *));
void cmDomiInternalNode_Finalize(SDomiInternalNode *n);
void cmDomiInternalNode_InheritObjInfo(SDomiNode *n, int flags);
void cmDomiInternalNode_FreeTrash(SDomiInternalNode *n);
void SDomiNodeArray_Finalize(SDomiPtrArray *a);
void SDomiNodeArray_InheritObjInfo(SDomiPtrArray *a, int flags);
void SDomiNodeArray_FreeTrash(SDomiPtrArray *a);
SDomiNode *SDomiNodeArray_Find(SDomiPtrArray *a, const SDomiString *name);
SDomiNode *SDomiNodeArray_Remove(SDomiPtrArray *a, const SDomiString *name, unsigned int *out);
int SDomiNodeArray_Put(SDomiPtrArray *a, SDomiNode *n, SDomiNode **old, unsigned int *out);
void SDomiElement_OwnAttr(SDomiElement *e, SDomiAttr *a);
void SDomiElement_ReleaseAttr(SDomiAttr *a);
int SDomiElement_CheckNewAttr(SDomiElement *e, SDomiAttr *a);
int SDomiElement_BuildTagElementList(SDomiNodeSet *set);
int SDomiElement_getAttributeNode(SDomiElement *e, const SDomiString *name, SDomiAttr **out);
int SDomiElement_setAttributeNode(SDomiElement *e, SDomiAttr *a, SDomiAttr **out);
int SDomiElement_removeAttributeNode(SDomiElement *e, SDomiAttr *a, SDomiAttr **out);

static int TagFilter(SDomiNodeSet *set, SDomiNode *n) {
    if (n->nodeType == 1 &&
        (UDomiString_CompareBinary(set->name.d->s.str, set->name.d->s.len, gSwildcard.str, gSwildcard.len) == 0 ||
         UDomiString_CompareBinary(set->name.d->s.str, set->name.d->s.len, n->nodeName.d->s.str, n->nodeName.d->s.len) == 0)) {
        return 2;
    }
    return 1;
}

static int PutAttribute(SDomiElement *e, int specified, SDomiAttr *a, SDomiAttr **out) {
    SDomiAttr *old;

    *out = NULL;
    if (!ELEMVT(e)->SetAttrNode(e, a, &old)) {
        return 0;
    }
    SDomiElement_OwnAttr(e, a);
    a->specified = specified;
    a->i.n.vt->InheritObjInfo(a, e->t.i.n.flags);
    if (old != NULL) {
        SDomiElement_ReleaseAttr(old);
        *out = old;
        return 1;
    }
    return 1;
}

static int NewAttribute(SDomiElement *e, const SDomiString *name, const SDomiString *value, int specified, SDomiAttr **out) {
    SDomiStringH h;
    SDomiAttr *a;
    SDomiAttr *old;
    SDomiNode *doc;
    int r;

    *out = NULL;
    SDomiStringH_Init(&h);
    if (!SDomiStringH_Set(&h, name)) {
        r = -1;
        goto end;
    }
    doc = (SDomiNode *)e->t.i.n.ownerDocument;
    r = doc->vt->createAttribute(doc, &h, &a);
    if (r != 0) {
        goto end;
    }
    if (!SDomiStringH_Set(&a->value, value)) {
        r = -1;
        goto end;
    }
    if (PutAttribute(e, specified, a, &old)) {
        *out = a;
    } else {
        r = -1;
    }
end:
    SDomiStringH_Finalize(&h);
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_CheckNewAttr);

int cmDomiElementNamedNodeSet_getNamedItem(SDomiNamedNodeSet *s, const SDomiString *name, SDomiAttr **out) {
    return SDomiElement_getAttributeNode((SDomiElement *)s->owner, name, out);
}

int cmDomiElementNamedNodeSet_setNamedItem(SDomiNamedNodeSet *s, SDomiAttr *a, SDomiAttr **out) {
    return SDomiElement_setAttributeNode((SDomiElement *)s->owner, a, out);
}

int cmDomiElementNamedNodeSet_removeNamedItem(SDomiNamedNodeSet *s, const SDomiString *name, SDomiAttr **out) {
    SDomiAttr *a;
    SDomiAttr *b;
    int r;

    *out = NULL;
    if (!ELEMVT(s->owner)->GetAttrNode(s->owner, name, &a)) {
        r = -1;
    } else if ((b = a) == NULL) {
        r = 0;
    } else {
        r = SDomiElement_removeAttributeNode((SDomiElement *)s->owner, b, out);
    }
    return r;
}

SDomiNode *cmDomiElementNamedNodeSet_item(SDomiNamedNodeSet *s, unsigned int i) {
    return SDomiPtrArray_GetItem(&((SDomiElement *)s->owner)->attrs, i);
}

unsigned int cmDomiElementNamedNodeSet_get_length(SDomiNamedNodeSet *s) {
    return ((SDomiElement *)s->owner)->attrs.count;
}

void cmDomiElement_Finalize(SDomiElement *e) {
    SDomiNodeArray_Finalize(&e->attrs);
    cmDomiInternalNode_Finalize(&e->t.i);
}

void cmDomiElement_InheritObjInfo(SDomiElement *e, int flags) {
    SDomiNodeArray_InheritObjInfo(&e->attrs, flags);
    e->attrSet.x8 |= flags;
    cmDomiInternalNode_InheritObjInfo(&e->t.i.n, flags);
}

void cmDomiElement_FreeTrash(SDomiElement *e) {
    SDomiNodeArray_FreeTrash(&e->attrs);
    cmDomiInternalNode_FreeTrash(&e->t.i);
}

SDomiNamedNodeSet *cmDomiElement_get_attributes(SDomiElement *e) {
    return &e->attrSet;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", cmDomiElement_cloneNode);

int cmDomiElement_GetAttrNode(SDomiElement *e, const SDomiString *name, SDomiNode **out) {
    *out = SDomiNodeArray_Find(&e->attrs, name);
    return 1;
}

int cmDomiElement_GetDefault(SDomiElement *e, const SDomiString *name, const SDomiString **out) {
    *out = AcsExterngSnull();
    return 1;
}

int cmDomiElement_SetAttrNode(SDomiElement *e, SDomiNode *a, SDomiNode **old) {
    unsigned int idx;

    return SDomiNodeArray_Put(&e->attrs, a, old, &idx);
}

int cmDomiElement_RemoveAttrNode(SDomiElement *e, const SDomiString *name, SDomiNode **out) {
    unsigned int idx;

    *out = SDomiNodeArray_Remove(&e->attrs, name, &idx);
    return 1;
}

SDomiNodeSet *cmDomiElement_getElementsByTagName(SDomiElement *e, const SDomiString *name) {
    return SDomiNodeSetSet_Prepare(&e->t.i.nodeSets, name, &e->t.i.n, SDomiElement_BuildTagElementList);
}

int SDomiElement_BuildTagElementList(SDomiNodeSet *set) {
    return SDomiInternalNode_BuildNodeSet(set->root, set, 1, TagFilter);
}

void SDomiElement_Initialize(SDomiElement *e, const SDomiNodeVt *vt, SDomiDocument *doc, const SDomiStringH *name) {
    if (vt == NULL) {
        vt = &gDomiElementVt;
    }
    SDomiTrunkNode_Initialize(&e->t, vt, 0, 1, doc, name);
    SDomiPtrArray_Initialize(&e->attrs, 1);
    SDomiNamedNodeSet_Initialize(&e->attrSet, &gSDomiElementNamedNodeSetVt, &e->t.i.n);
}

void SDomiElement_OwnAttr(SDomiElement *e, SDomiAttr *a) {
    SDomiNode_Reuse(&a->i.n);
    a->ownerElement = e;
}

void SDomiElement_ReleaseAttr(SDomiAttr *a) {
    a->ownerElement = NULL;
    SDomiNode_Trash(&a->i.n);
}

int SDomiElement_getAttribute(SDomiElement *e, const SDomiString *name, const SDomiString **out) {
    SDomiAttr *a;
    int r = -1;

    *out = AcsExterngSnull();
    if (ELEMVT(e)->GetAttrNode(e, name, &a)) {
        if (a != NULL) {
            *out = &a->value.d->s;
            r = 0;
        } else if (ELEMVT(e)->GetDefault(e, name, out)) {
            r = 0;
        }
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_setAttribute);

int SDomiElement_removeAttribute(SDomiElement *e, const SDomiString *name) {
    SDomiAttr *a;

    return cmDomiElementNamedNodeSet_removeNamedItem(&e->attrSet, name, &a);
}

int SDomiElement_getAttributeNode(SDomiElement *e, const SDomiString *name, SDomiAttr **out) {
    SDomiAttr *a;
    const SDomiString *def;
    int r = -1;

    *out = NULL;
    if (ELEMVT(e)->GetAttrNode(e, name, &a)) {
        if (a != NULL) {
            *out = a;
            r = 0;
        } else if (ELEMVT(e)->GetDefault(e, name, &def)) {
            r = 0;
            if (def->len != 0) {
                r = NewAttribute(e, name, def, 0, &a);
                if (r == 0) {
                    *out = a;
                }
            }
        }
    }
    return r;
}

int SDomiElement_setAttributeNode(SDomiElement *e, SDomiAttr *a, SDomiAttr **out) {
    int r;

    *out = NULL;
    r = SDomiElement_CheckNewAttr(e, a);
    if (r == 0 && !PutAttribute(e, 1, a, out)) {
        r = -1;
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", SDomiElement_removeAttributeNode);

int SDomiElement_hasAttribute(SDomiElement *e, const SDomiString *name, int *out) {
    SDomiAttr *a;
    const SDomiString *def;
    int r = -1;

    *out = 0;
    if (ELEMVT(e)->GetAttrNode(e, name, &a)) {
        if (a != NULL) {
            *out = (a->ownerElement == NULL || a->specified) ? 1 : 0;
            r = 0;
        } else if (ELEMVT(e)->GetDefault(e, name, &def)) {
            *out = def->len != 0;
            r = 0;
        }
    }
    return r;
}

void cmDomiEntity_Finalize(SDomiEntity *n) {
    SDomiStringH_Finalize(&n->notationName);
    SDomiStringH_Finalize(&n->systemId);
    SDomiStringH_Finalize(&n->publicId);
    cmDomiInternalNode_Finalize(&n->i);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", gDomiElementVt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", gSDomiElementNamedNodeSetVt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", gCAwildcard);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", gSwildcard);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", gDomiEntityVt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiElement", gDomiEntityReferenceVt);
