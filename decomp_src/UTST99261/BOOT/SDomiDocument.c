/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
extern const SDomiNodeVt gDomiDocumentVt;
void *AcsExterngDomiNodeSetEmpty(void);
void SDomiElement_Initialize(SDomiElement *e, const SDomiNodeVt *vt, SDomiDocument *doc, const SDomiStringH *name);
int SDomiElement_BuildTagElementList(SDomiNodeSet *set);
void SDomiDocumentFragment_Initialize(SDomiNode *n, SDomiDocument *doc);
void SDomiCharacterData_Initialize(SDomiCharacterData *n, const SDomiNodeVt *vt, int type, SDomiDocument *doc, const SDomiStringH *name);
void SDomiProcessingInstruction_Initialize(SDomiNode *n, SDomiDocument *doc, const SDomiStringH *target);
void SDomiAttr_Initialize(SDomiAttr *a, SDomiDocument *doc, const SDomiStringH *name);
void SDomiEntityReference_Initialize(SDomiTrunkNode *n, SDomiDocument *doc, const SDomiStringH *name);
void SDomiEntity_Initialize(SDomiEntity *n, SDomiDocument *doc, const SDomiStringH *name);
void SDomiNotation_Initialize(SDomiNode *n, SDomiDocument *doc, const SDomiStringH *name);
void cmDomiInternalNode_Finalize(SDomiInternalNode *n);
void cmDomiInternalNode_FreeTrash(SDomiInternalNode *n);
SDomiNodeSet *SDomiNodeSetSet_Prepare(SDomiSLink *head, const SDomiString *name, SDomiNode *root, int (*build)(SDomiNodeSet *));
void SDomiDocument_EmptyTrash(SDomiDocument *doc);
int SDomiDocument_createCharacterData(SDomiDocument *doc, int type, const SDomiString *s, SDomiNode **out);
int cmDomiDocument_createEntityReference(SDomiDocument *doc, const SDomiStringH *name, SDomiNode **out);

void SDomiDocument_EmptyTrash(SDomiDocument *doc) {
    SDomiNodeSLink_DeleteAll(&doc->trash);
}

static int ImportDeep(SDomiDocument *doc, SDomiNode *dst, SDomiNode *src) {
    SDomiNode *c;
    SDomiNode *n;
    int r = 0;

    for (c = src->vt->get_firstChild(src); c != NULL; c = c->vt->get_nextSibling(c)) {
        r = doc->i.n.vt->importNode(doc, c, 1, &n);
        if (r != 0) {
            break;
        }
        r = dst->vt->insertBefore(dst, n, NULL, &n);
        if (r != 0) {
            break;
        }
    }
    return r;
}

void cmDomiDocument_Finalize(SDomiDocument *doc) {
    cmDomiInternalNode_Finalize(&doc->i);
    SDomiDocument_EmptyTrash(doc);
}

void cmDomiDocument_FreeTrash(SDomiDocument *doc) {
    cmDomiInternalNode_FreeTrash(&doc->i);
    SDomiDocument_EmptyTrash(doc);
    doc->changed = 0;
}

SDomiNode *cmDomiDocument_get_doctype(SDomiDocument *doc) {
    return NULL;
}

int cmDomiDocument_createElement(SDomiDocument *doc, const SDomiStringH *name, SDomiNode **out) {
    SDomiElement *e;

    *out = NULL;
    e = UDomiMemory_Allocate(sizeof(SDomiElement));
    if (e == NULL) {
        return -1;
    }
    SDomiElement_Initialize(e, NULL, doc, name);
    SDomiSLink_Insert(&doc->trash, &e->t.i.n.trash);
    *out = &e->t.i.n;
    return 0;
}

int cmDomiDocument_createDocumentFragment(SDomiDocument *doc, SDomiNode **out) {
    SDomiInternalNode *n;

    *out = NULL;
    n = UDomiMemory_Allocate(sizeof(SDomiInternalNode));
    if (n == NULL) {
        return -1;
    }
    SDomiDocumentFragment_Initialize(&n->n, doc);
    SDomiSLink_Insert(&doc->trash, &n->n.trash);
    *out = &n->n;
    return 0;
}

int cmDomiDocument_createTextNode(SDomiDocument *doc, const SDomiString *data, SDomiNode **out) {
    SDomiCharacterData *n;
    int r;

    *out = NULL;
    n = UDomiMemory_Allocate(sizeof(SDomiCharacterData));
    r = -1;
    if (n != NULL) {
        SDomiCharacterData_Initialize(n, NULL, 3, doc, AcsExterngSHnull());
        r = SDomiCharacterData_set_data(n, data);
        if (r == 0) {
            SDomiSLink_Insert(&doc->trash, &n->e.n.trash);
            *out = &n->e.n;
        } else {
            n->e.n.vt->Finalize(n);
            UDomiMemory_Free(n);
        }
    }
    return r;
}

int cmDomiDocument_createComment(SDomiDocument *doc, const SDomiString *data, SDomiNode **out) {
    SDomiCharacterData *n;
    int r;

    *out = NULL;
    n = UDomiMemory_Allocate(sizeof(SDomiCharacterData));
    r = -1;
    if (n != NULL) {
        SDomiCharacterData_Initialize(n, NULL, 8, doc, AcsExterngSHnull());
        r = SDomiCharacterData_set_data(n, data);
        if (r == 0) {
            SDomiSLink_Insert(&doc->trash, &n->e.n.trash);
            *out = &n->e.n;
        } else {
            n->e.n.vt->Finalize(n);
            UDomiMemory_Free(n);
        }
    }
    return r;
}

int cmDomiDocument_createCDATASection(SDomiDocument *doc, const SDomiString *data, SDomiNode **out) {
    SDomiCharacterData *n;
    int r;

    *out = NULL;
    n = UDomiMemory_Allocate(sizeof(SDomiCharacterData));
    r = -1;
    if (n != NULL) {
        SDomiCharacterData_Initialize(n, NULL, 4, doc, AcsExterngSHnull());
        r = SDomiCharacterData_set_data(n, data);
        if (r == 0) {
            SDomiSLink_Insert(&doc->trash, &n->e.n.trash);
            *out = &n->e.n;
        } else {
            n->e.n.vt->Finalize(n);
            UDomiMemory_Free(n);
        }
    }
    return r;
}

int cmDomiDocument_createProcessingInstruction(SDomiDocument *doc, const SDomiStringH *target, const SDomiStringH *data, SDomiNode **out) {
    SDomiProcessingInstruction *n;
    int r;

    *out = NULL;
    n = UDomiMemory_Allocate(sizeof(SDomiProcessingInstruction));
    if (n != NULL) {
        SDomiProcessingInstruction_Initialize(&n->e.n, doc, target);
        SDomiStringH_Assign(&n->data, data);
        r = 0;
        SDomiSLink_Insert(&doc->trash, &n->e.n.trash);
        *out = &n->e.n;
    } else
        r = -1;
    return r;
}

int cmDomiDocument_createAttribute(SDomiDocument *doc, const SDomiStringH *name, SDomiNode **out) {
    SDomiAttr *a;

    *out = NULL;
    a = UDomiMemory_Allocate(sizeof(SDomiAttr));
    if (a != NULL) {
        SDomiAttr_Initialize(a, doc, name);
        SDomiSLink_Insert(&doc->trash, &a->i.n.trash);
        *out = &a->i.n;
        return 0;
    }
    return -1;
}

int cmDomiDocument_createEntityReference(SDomiDocument *doc, const SDomiStringH *name, SDomiNode **out) {
    SDomiTrunkNode *n;

    *out = NULL;
    n = UDomiMemory_Allocate(sizeof(SDomiTrunkNode));
    if (n != NULL) {
        SDomiEntityReference_Initialize(n, doc, name);
        SDomiSLink_Insert(&doc->trash, &n->i.n.trash);
        *out = &n->i.n;
        return 0;
    }
    return -1;
}

SDomiNodeSet *cmDomiDocument_getElementsByTagName(SDomiDocument *doc, const SDomiString *name) {
    return SDomiNodeSetSet_Prepare(&doc->i.nodeSets, name, &doc->i.n, SDomiElement_BuildTagElementList);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", gDomiDocumentVt);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", cmDomiDocument_importNode);

int cmDomiDocument_createElementNS(SDomiDocument *doc, const SDomiString *ns, const SDomiString *qname, SDomiNode **out) {
    *out = NULL;
    return 9;
}

int cmDomiDocument_createAttributeNS(SDomiDocument *doc, const SDomiString *ns, const SDomiString *qname, SDomiNode **out) {
    *out = NULL;
    return 9;
}

void *cmDomiDocument_getElementsByTagNameNS(SDomiDocument *doc, const SDomiString *ns, const SDomiString *local) {
    return AcsExterngDomiNodeSetEmpty();
}

SDomiNode *cmDomiDocument_getElementById(SDomiDocument *doc, const SDomiString *id) {
    return NULL;
}

void SDomiDocument_Initialize(SDomiDocument *doc, const SDomiNodeVt *vt, SDomiImplementation *impl, const SDomiStringH *name) {
    if (vt == NULL) {
        vt = &gDomiDocumentVt;
    }
    SDomiInternalNode_Initialize(&doc->i.n, vt, 0, 9, NULL, name);
    doc->implementation = impl;
    doc->documentElement = NULL;
    doc->changed = 0;
    doc->trash.next = &doc->trash;
}

int SDomiDocument_createCharacterData(SDomiDocument *doc, int type, const SDomiString *s, SDomiNode **out) {
    switch (type) {
    case 3:
        return doc->i.n.vt->createTextNode(doc, s, out);
    case 4:
        return doc->i.n.vt->createCDATASection(doc, s, out);
    case 8:
        return doc->i.n.vt->createComment(doc, s, out);
    }
    return 9;
}

int cmDomiDocumentFragment_cloneNode(SDomiNode *n, int deep, SDomiNode **out) {
    SDomiNode *clone;
    SDomiNode *doc;
    int r;

    *out = NULL;
    doc = (SDomiNode *)n->ownerDocument;
    r = doc->vt->createDocumentFragment(doc, &clone);
    if (r == 0) {
        if (!deep || SDomiInternalNode_CloneChildren(n, clone)) {
            *out = clone;
        } else {
            r = -1;
        }
    }
    return r;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/SDomiDocument", gDomiDocumentFragmentVt);
