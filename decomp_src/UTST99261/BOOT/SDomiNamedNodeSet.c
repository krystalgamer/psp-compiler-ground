/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
void *AcsExterngDomiNodeSetEmpty(void);
SDomiDocument *SDomiNode_GetContextDocument(SDomiNode *n);

void SDomiNamedNodeSet_Initialize(SDomiNamedNodeSet *s, const SDomiNamedNodeSetVt *vt, SDomiNode *owner) {
    s->vt = vt;
    s->owner = owner;
    s->x8 = 0;
}

void cmDomiNode_Finalize(SDomiNode *n) {
    SDomiStringH_Finalize(&n->nodeName);
}

void cmDomiNode_Changed(SDomiNode *n) {
}

void cmDomiNode_SetParentNode(SDomiNode *n, SDomiNode *p) {
}

void cmDomiNode_SetPreviousSibling(SDomiNode *n, SDomiNode *p) {
}

void cmDomiNode_SetNextSibling(SDomiNode *n, SDomiNode *p) {
}

void cmDomiNode_InheritObjInfo(SDomiNode *n, int flags) {
    n->flags |= flags;
}

void cmDomiNode_FreeTrash(SDomiNode *n) {
}

int cmDomiNode_get_nodeValue(SDomiNode *n, SDomiString *out) {
    out->len = 0;
    return 0;
}

int cmDomiNode_set_nodeValue(SDomiNode *n, const SDomiString *s) {
    return 7;
}

SDomiNode *cmDomiNode_get_parentNode(SDomiNode *n) {
    return NULL;
}

void *cmDomiNode_get_childNodes(SDomiNode *n) {
    return AcsExterngDomiNodeSetEmpty();
}

SDomiNode *cmDomiNode_get_firstChild(SDomiNode *n) {
    return NULL;
}

SDomiNode *cmDomiNode_get_lastChild(SDomiNode *n) {
    return NULL;
}

SDomiNode *cmDomiNode_get_previousSibling(SDomiNode *n) {
    return NULL;
}

SDomiNode *cmDomiNode_get_nextSibling(SDomiNode *n) {
    return NULL;
}

void *cmDomiNode_get_attributes(SDomiNode *n) {
    return NULL;
}

int cmDomiNode_insertBefore(SDomiNode *n, SDomiNode *newChild, SDomiNode *refChild, SDomiNode **out) {
    return 3;
}

int cmDomiNode_removeChild(SDomiNode *n, SDomiNode *oldChild, SDomiNode **out) {
    return 8;
}

int cmDomiNode_hasChildNodes(SDomiNode *n) {
    return 0;
}

int cmDomiNode_cloneNode(SDomiNode *n, int deep, SDomiNode **out) {
    *out = NULL;
    return 9;
}

int cmDomiNode_isSupported(SDomiNode *n, const SDomiString *feature, const SDomiString *version) {
    SDomiDocument *doc = SDomiNode_GetContextDocument(n);
    SDomiImplementation *impl;

    if (doc == NULL) {
        return 0;
    }
    impl = doc->implementation;
    return impl->vt->hasFeature(impl, feature, version);
}

const SDomiString *cmDomiNode_get_namespaceURI(SDomiNode *n) {
    return AcsExterngSnull();
}

const SDomiString *cmDomiNode_get_prefix(SDomiNode *n) {
    return AcsExterngSnull();
}

int cmDomiNode_set_prefix(SDomiNode *n, const SDomiString *s) {
    return 14;
}

const SDomiString *cmDomiNode_get_localName(SDomiNode *n) {
    return AcsExterngSnull();
}

int cmDomiNode_hasAttributes(SDomiNode *n) {
    return 0;
}
