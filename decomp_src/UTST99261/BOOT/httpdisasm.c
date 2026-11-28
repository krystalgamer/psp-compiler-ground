/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
void *MEM_malloc(int heap, unsigned int size);
void *memcpy(void *d, const void *s, unsigned int n);
#define HD_UPPER(c) ((unsigned char)((c) - 'a') < 26 ? (c) & ~0x20 : (c))
typedef struct SDomiDocManager SDomiDocManager;
extern int gDomiError;
extern SDomiDocManager gDomiDocManager;
int SDomiDocManager_Free(SDomiDocManager *m);
void *AcsExterngDomiNodeSetEmpty(void);
int SDomiNode_replaceChild(SDomiNode *n, SDomiNode *newChild, SDomiNode *oldChild, SDomiNode **out);
int SDomiNode_normalize(SDomiNode *n);
int SDomiNodeSet_length(SDomiNodeSet *s, unsigned int *out);
int SDomiNodeSet_item(SDomiNodeSet *s, unsigned int i, SDomiNode **out);
int SDomiCharacterData_substringData(SDomiCharacterData *n, unsigned int off, unsigned int count, SDomiString *out);
int SDomiCharacterData_insertData(SDomiCharacterData *n, unsigned int off, const SDomiString *s);
int SDomiCharacterData_replaceData(SDomiCharacterData *n, unsigned int off, unsigned int count, const SDomiString *s);
int SDomiElement_getAttribute(SDomiElement *e, const SDomiString *name, const SDomiString **out);
int SDomiElement_setAttribute(SDomiElement *e, const SDomiString *name, const SDomiString *value);
int SDomiElement_removeAttribute(SDomiElement *e, const SDomiString *name);
int SDomiElement_getAttributeNode(SDomiElement *e, const SDomiString *name, SDomiAttr **out);
int SDomiElement_setAttributeNode(SDomiElement *e, SDomiAttr *a, SDomiAttr **out);
int SDomiElement_removeAttributeNode(SDomiElement *e, SDomiAttr *a, SDomiAttr **out);
int SDomiElement_hasAttribute(SDomiElement *e, const SDomiString *name, int *out);
int SDomiText_splitText(SDomiCharacterData *n, unsigned int off, SDomiNode **out);

#define DOMI_READONLY(n) (((SDomiNode *)(n))->flags & 1)

typedef struct SDomiDocumentType {
    SDomiTrunkNode t;
    void *x38;
    void *x3C;
    SDomiNamedNodeSet entities;       /* 0x40 */
    SDomiNamedNodeSet notations;      /* 0x4C */
    SDomiStringH publicId;            /* 0x58 */
    SDomiStringH systemId;            /* 0x5C */
    SDomiStringH internalSubset;      /* 0x60 */
} SDomiDocumentType;

typedef struct { char *start; char *end; } STRWORD;
#define ISEOL(c) ((c) == '\r' || (c) == '\n')
char *strlinecmp(const char *s, char *line) {
    while (*s && !ISEOL(*line)) {
        if (HD_UPPER(*s) != HD_UPPER(*line))
            return NULL;
        s++;
        line++;
    }
    return *s ? NULL : line;
}

int strlinevalue(const char *s)
{
    int v = 0;

    while ((unsigned char)(*s - '0') < 10) {
        v = v * 10 + *s - '0';
        s++;
    }
    return v;
}

STRWORD strlineword(char *p, char *skip, char *term) {
    STRWORD w;
    char q[2];
    int i;
    while (*p != '\r' && *p != '\n') {
        for (i = 0; skip[i]; i++)
            if (*p == skip[i]) break;
        if (skip[i] == 0) break;
        p++;
    }
    if (*p == '\r' || *p == '\n') {
        w.start = NULL;
        w.end = NULL;
        return w;
    }
    if (*p == '"' || *p == '\'') {
        q[0] = *p;
        q[1] = 0;
        term = q;
        p++;
    }
    w.start = p;
    while (*p != '\r' && *p != '\n') {
        for (i = 0; term[i]; i++)
            if (*p == term[i]) break;
        if (term[i] != 0) break;
        p++;
    }
    w.end = p;
    return w;
}

char *strlinedup(const char *s, int n)
{
    char *p = MEM_malloc(0, n + 1);

    if (p == NULL)
        return NULL;
    memcpy(p, s, n);
    p[n] = 0;
    return p;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/httpdisasm", httpHeaderParse);

int *AcsExterngDomiError(void) {
    return &gDomiError;
}

SDomiDocManager *AcsExterngDomiDocManager(void) {
    return &gDomiDocManager;
}

int DomiAPI_RoPar(SDomiNode *n) {
    SDomiNode *p = n->vt->get_parentNode(n);

    return p != NULL ? p->flags & 1 : 0;
}

SDomiString DomiAPI_ConvertString(const DOMString *s) {
    SDomiString r;

    if (s != NULL) {
        r.len = s->len;
        r.str = s->str;
    } else {
        r.len = 0;
    }
    return r;
}

int DOMImplementation_hasFeature(SDomiImplementation *impl, const DOMString *feature, const DOMString *version) {
    SDomiString f = DomiAPI_ConvertString(feature);
    SDomiString v = DomiAPI_ConvertString(version);

    gDomiError = 0;
    return impl->vt->hasFeature(impl, &f, &v);
}

SDomiNode *DOMImplementation_createDocumentType(SDomiImplementation *impl, const DOMString *qname, const DOMString *publicId, const DOMString *systemId) {
    SDomiString a = DomiAPI_ConvertString(qname);
    SDomiString b = DomiAPI_ConvertString(publicId);
    SDomiString c = DomiAPI_ConvertString(systemId);
    SDomiNode *out = NULL;

    gDomiError = impl->vt->createDocumentType(impl, &a, &b, &c, &out);
    return out;
}

SDomiDocument *DOMImplementation_createDocument(SDomiImplementation *impl, const DOMString *ns, const DOMString *qname, SDomiNode *doctype) {
    SDomiString a = DomiAPI_ConvertString(ns);
    SDomiString b = DomiAPI_ConvertString(qname);
    SDomiDocument *out = NULL;

    gDomiError = impl->vt->createDocument(impl, &a, &b, doctype, &out);
    return out;
}

DOMString Node_getNodeName(SDomiNode *n) {
    DOMString r;
    SDomiStringData *d;

    gDomiError = 0;
    d = n->nodeName.d;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

DOMString Node_getNodeValue(SDomiNode *n) {
    SDomiString s;
    DOMString r;

    gDomiError = n->vt->get_nodeValue(n, &s);
    r.size = s.len;
    r.len = s.len;
    r.str = s.str;
    return r;
}

void Node_setNodeValue(SDomiNode *n, const DOMString *value) {
    int err = 7;

    if (!DOMI_READONLY(n)) {
        SDomiString s = DomiAPI_ConvertString(value);
        err = n->vt->set_nodeValue(n, &s);
    }
    gDomiError = err;
}

int Node_getNodeType(SDomiNode *n) {
    gDomiError = 0;
    return n->nodeType;
}

SDomiNode *Node_getParentNode(SDomiNode *n) {
    SDomiNode *r = n->vt->get_parentNode(n);

    gDomiError = 0;
    return r;
}

void *Node_getChildNodes(SDomiNode *n) {
    void *s = (void *)n->vt->get_childNodes(n);

    if (s != NULL) {
        gDomiError = 0;
    } else {
        s = AcsExterngDomiNodeSetEmpty();
        gDomiError = -1;
    }
    return s;
}

SDomiNode *Node_getFirstChild(SDomiNode *n) {
    SDomiNode *r = n->vt->get_firstChild(n);

    gDomiError = 0;
    return r;
}

SDomiNode *Node_getLastChild(SDomiNode *n) {
    SDomiNode *r = n->vt->get_lastChild(n);

    gDomiError = 0;
    return r;
}

SDomiNode *Node_getPreviousSibling(SDomiNode *n) {
    SDomiNode *r = n->vt->get_previousSibling(n);

    gDomiError = 0;
    return r;
}

SDomiNode *Node_getNextSibling(SDomiNode *n) {
    SDomiNode *r = n->vt->get_nextSibling(n);

    gDomiError = 0;
    return r;
}

SDomiNamedNodeSet *Node_getAttributes(SDomiNode *n) {
    SDomiNamedNodeSet *r = n->vt->get_attributes(n);

    gDomiError = 0;
    return r;
}

SDomiDocument *Node_getOwnerDocument(SDomiNode *n) {
    SDomiDocument * r = n->ownerDocument;

    gDomiError = 0;
    return r;
}

SDomiNode *Node_insertBefore(SDomiNode *n, SDomiNode *newChild, SDomiNode *refChild) {
    SDomiNode *out;
    int err;

    if (DOMI_READONLY(n) || DomiAPI_RoPar(newChild)) {
        out = NULL;
        err = 7;
    } else {
        err = n->vt->insertBefore(n, newChild, refChild, &out);
    }
    gDomiError = err;
    return out;
}

SDomiNode *Node_replaceChild(SDomiNode *n, SDomiNode *newChild, SDomiNode *oldChild) {
    SDomiNode *out;
    int err;

    if (DOMI_READONLY(n) || DomiAPI_RoPar(newChild)) {
        out = NULL;
        err = 7;
    } else {
        err = SDomiNode_replaceChild(n, newChild, oldChild, &out);
    }
    gDomiError = err;
    return out;
}

SDomiNode *Node_removeChild(SDomiNode *n, SDomiNode *oldChild) {
    SDomiNode *out;
    int err;

    if (DOMI_READONLY(n)) {
        out = NULL;
        err = 7;
    } else {
        err = n->vt->removeChild(n, oldChild, &out);
    }
    gDomiError = err;
    return out;
}

SDomiNode *Node_appendChild(SDomiNode *n, SDomiNode *newChild) {
    SDomiNode *out;
    int err;

    if (DOMI_READONLY(n) || DomiAPI_RoPar(newChild)) {
        out = NULL;
        err = 7;
    } else {
        err = n->vt->insertBefore(n, newChild, NULL, &out);
    }
    gDomiError = err;
    return out;
}

int Node_hasChildNodes(SDomiNode *n) {
    gDomiError = 0;
    return n->vt->hasChildNodes(n);
}

SDomiNode *Node_cloneNode(SDomiNode *n, int deep) {
    SDomiNode *out;

    gDomiError = n->vt->cloneNode(n, deep, &out);
    return out;
}

void Node_normalize(SDomiNode *n) {
    gDomiError = SDomiNode_normalize(n);
}

int Node_isSupported(SDomiNode *n, const DOMString *feature, const DOMString *version) {
    SDomiString f = DomiAPI_ConvertString(feature);
    SDomiString v = DomiAPI_ConvertString(version);

    gDomiError = 0;
    return n->vt->isSupported(n, &f, &v);
}

int Node_hasAttributes(SDomiNode *n) {
    gDomiError = 0;
    return n->vt->hasAttributes(n);
}

void Node_setBox(SDomiNode *n, void *box) {
    gDomiError = 0;
    n->x14 = box;
}

void *Node_getBox(SDomiNode *n) {
    gDomiError = 0;
    return n->x14;
}

void Node_setSid(SDomiNode *n, void *sid) {
    gDomiError = 0;
    n->x18 = sid;
}

void *Node_getSid(SDomiNode *n) {
    gDomiError = 0;
    return n->x18;
}

void Node_setJSObj(SDomiNode *n, void *obj) {
    gDomiError = 0;
    n->x1C = obj;
}

void *Node_getJSObj(SDomiNode *n) {
    gDomiError = 0;
    return n->x1C;
}

SDomiNode *NodeList_item(SDomiNodeSet *s, unsigned int i) {
    SDomiNode *out;

    int err;

    if (SDomiNodeSet_item(s, i, &out)) {
        err = 0;
    } else {
        err = -1;
    }
    gDomiError = err;
    return out;
}

unsigned int NodeList_getLength(SDomiNodeSet *s) {
    unsigned int len;

    int err;

    if (SDomiNodeSet_length(s, &len)) {
        err = 0;
    } else {
        err = -1;
    }
    gDomiError = err;
    return len;
}

SDomiNode *NamedNodeMap_getNamedItem(SDomiNamedNodeSet *m, const DOMString *name) {
    SDomiString s = DomiAPI_ConvertString(name);
    SDomiNode *out;

    gDomiError = m->vt->getNamedItem(m, &s, &out);
    return out;
}

SDomiNode *NamedNodeMap_setNamedItem(SDomiNamedNodeSet *m, SDomiNode *arg) {
    SDomiNode *out;
    int err;

    if (m->x8 & 1) {
        out = NULL;
        err = 7;
    } else {
        err = m->vt->setNamedItem(m, arg, &out);
    }
    gDomiError = err;
    return out;
}

SDomiNode *NamedNodeMap_removeNamedItem(SDomiNamedNodeSet *m, const DOMString *name) {
    SDomiNode *out;
    int err;

    if (m->x8 & 1) {
        out = NULL;
        err = 7;
    } else {
        SDomiString s = DomiAPI_ConvertString(name);
        err = m->vt->removeNamedItem(m, &s, &out);
    }
    gDomiError = err;
    return out;
}

SDomiNode *NamedNodeMap_item(SDomiNamedNodeSet *m, unsigned int i) {
    SDomiNode *r = m->vt->item(m, i);

    gDomiError = 0;
    return r;
}

unsigned int NamedNodeMap_getLength(SDomiNamedNodeSet *m) {
    gDomiError = 0;
    return m->vt->get_length(m);
}

DOMString CharacterData_getData(SDomiCharacterData *n) {
    SDomiString s;
    DOMString r;

    s.len = n->data.len;
    s.str = n->data.buf;
    gDomiError = 0;
    r.size = s.len;
    r.len = s.len;
    r.str = s.str;
    return r;
}

void CharacterData_setData(SDomiCharacterData *n, const DOMString *data) {
    int err = 7;

    if (!DOMI_READONLY(n)) {
        SDomiString s = DomiAPI_ConvertString(data);
        err = SDomiCharacterData_set_data(n, &s);
    }
    gDomiError = err;
}

unsigned int CharacterData_getLength(SDomiCharacterData *n) {
    gDomiError = 0;
    return n->data.len;
}

DOMString CharacterData_substringData(SDomiCharacterData *n, unsigned int off, unsigned int count) {
    SDomiString s;
    DOMString r;

    gDomiError = SDomiCharacterData_substringData(n, off, count, &s);
    r.size = s.len;
    r.len = s.len;
    r.str = s.str;
    return r;
}

void CharacterData_appendData(SDomiCharacterData *n, const DOMString *data) {
    int err = 7;

    if (!DOMI_READONLY(n)) {
        SDomiString s = DomiAPI_ConvertString(data);
        err = SDomiStrAcu_Insert(&n->data, n->data.len, &s) ? 0 : -1;
    }
    gDomiError = err;
}

void CharacterData_insertData(SDomiCharacterData *n, unsigned int off, const DOMString *data) {
    int err = 7;

    if (!DOMI_READONLY(n)) {
        SDomiString s = DomiAPI_ConvertString(data);
        err = SDomiCharacterData_insertData(n, off, &s);
    }
    gDomiError = err;
}

void CharacterData_deleteData(SDomiCharacterData *n, unsigned int off, unsigned int count) {
    int err = 7;

    if (!DOMI_READONLY(n)) {
        err = SDomiCharacterData_deleteData(n, off, count);
    }
    gDomiError = err;
}

void CharacterData_replaceData(SDomiCharacterData *n, unsigned int off, unsigned int count, const DOMString *data) {
    int err = 7;

    if (!DOMI_READONLY(n)) {
        SDomiString s = DomiAPI_ConvertString(data);
        err = SDomiCharacterData_replaceData(n, off, count, &s);
    }
    gDomiError = err;
}

DOMString Attr_getName(SDomiAttr *a) {
    DOMString r;
    SDomiStringData *d = a->i.n.nodeName.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

int Attr_getSpecified(SDomiAttr *a) {
    gDomiError = 0;
    return a->ownerElement == NULL || a->specified;
}

DOMString Attr_getValue(SDomiAttr *a) {
    DOMString r;
    SDomiStringData *d = a->value.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

void Attr_setValue(SDomiAttr *a, const DOMString *value) {
    int err = 7;

    if (!DOMI_READONLY(a)) {
        SDomiString s = DomiAPI_ConvertString(value);
        err = a->i.n.vt->set_nodeValue(a, &s);
    }
    gDomiError = err;
}

SDomiElement *Attr_getOwnerElement(SDomiAttr *a) {
    SDomiElement * r = a->ownerElement;

    gDomiError = 0;
    return r;
}

DOMString Element_getTagName(SDomiElement *e) {
    DOMString r;
    SDomiStringData *d = e->t.i.n.nodeName.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

DOMString Element_getAttribute(SDomiElement *e, const DOMString *name) {
    SDomiString s = DomiAPI_ConvertString(name);
    const SDomiString *v;
    DOMString r;

    gDomiError = SDomiElement_getAttribute(e, &s, &v);
    r.len = v->len;
    r.size = r.len;
    r.str = v->str;
    return r;
}

void Element_setAttribute(SDomiElement *e, const DOMString *name, const DOMString *value) {
    int err;

    if (DOMI_READONLY(e)) {
        err = 7;
    } else {
        SDomiString n = DomiAPI_ConvertString(name);
        SDomiString v = DomiAPI_ConvertString(value);
        err = SDomiElement_setAttribute(e, &n, &v);
    }
    gDomiError = err;
}

void Element_removeAttribute(SDomiElement *e, const DOMString *name) {
    int err = 7;

    if (!DOMI_READONLY(e)) {
        SDomiString s = DomiAPI_ConvertString(name);
        err = SDomiElement_removeAttribute(e, &s);
    }
    gDomiError = err;
}

SDomiAttr *Element_getAttributeNode(SDomiElement *e, const DOMString *name) {
    SDomiString s = DomiAPI_ConvertString(name);
    SDomiAttr *out;

    gDomiError = SDomiElement_getAttributeNode(e, &s, &out);
    return out;
}

SDomiAttr *Element_setAttributeNode(SDomiElement *e, SDomiAttr *a) {
    SDomiAttr *out;
    int err;

    if (DOMI_READONLY(e)) {
        out = NULL;
        err = 7;
    } else {
        err = SDomiElement_setAttributeNode(e, a, &out);
    }
    gDomiError = err;
    return out;
}

SDomiAttr *Element_removeAttributeNode(SDomiElement *e, SDomiAttr *a) {
    SDomiAttr *out;
    int err;

    if (DOMI_READONLY(e)) {
        out = NULL;
        err = 7;
    } else {
        err = SDomiElement_removeAttributeNode(e, a, &out);
    }
    gDomiError = err;
    return out;
}

void *Element_getElementsByTagName(SDomiElement *e, const DOMString *name) {
    SDomiString s = DomiAPI_ConvertString(name);
    void *set = ELEMVT(e)->getElementsByTagName(e, &s);

    if (set != NULL) {
        gDomiError = 0;
    } else {
        set = AcsExterngDomiNodeSetEmpty();
        gDomiError = -1;
    }
    return set;
}

int Element_hasAttribute(SDomiElement *e, const DOMString *name) {
    SDomiString s = DomiAPI_ConvertString(name);
    int r;

    gDomiError = SDomiElement_hasAttribute(e, &s, &r);
    return r;
}

SDomiNode *Text_splitText(SDomiCharacterData *t, unsigned int off) {
    SDomiNode *out;
    int err;

    if (DOMI_READONLY(t)) {
        out = NULL;
        err = 7;
    } else {
        err = SDomiText_splitText(t, off, &out);
    }
    gDomiError = err;
    return out;
}

DOMString DocumentType_getName(SDomiDocumentType *dt) {
    DOMString r;
    SDomiStringData *d = dt->t.i.n.nodeName.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

SDomiNamedNodeSet *DocumentType_getEntities(SDomiDocumentType *dt) {
    SDomiNamedNodeSet * r = &dt->entities;

    gDomiError = 0;
    return r;
}

SDomiNamedNodeSet *DocumentType_getNotations(SDomiDocumentType *dt) {
    SDomiNamedNodeSet * r = &dt->notations;

    gDomiError = 0;
    return r;
}

DOMString DocumentType_getPublicId(SDomiDocumentType *dt) {
    DOMString r;
    SDomiStringData *d = dt->publicId.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

DOMString DocumentType_getSystemId(SDomiDocumentType *dt) {
    DOMString r;
    SDomiStringData *d = dt->systemId.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

DOMString DocumentType_getInternalSubset(SDomiDocumentType *dt) {
    DOMString r;
    SDomiStringData *d = dt->internalSubset.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

DOMString Notation_getPublicId(SDomiNotation *n) {
    DOMString r;
    SDomiStringData *d = n->publicId.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

DOMString Notation_getSystemId(SDomiNotation *n) {
    DOMString r;
    SDomiStringData *d = n->systemId.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

DOMString Entity_getPublicId(SDomiEntity *n) {
    DOMString r;
    SDomiStringData *d = n->publicId.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

DOMString Entity_getSystemId(SDomiEntity *n) {
    DOMString r;
    SDomiStringData *d = n->systemId.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

DOMString Entity_getNotationName(SDomiEntity *n) {
    DOMString r;
    SDomiStringData *d = n->notationName.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

DOMString ProcessingInstruction_getTarget(SDomiProcessingInstruction *n) {
    DOMString r;
    SDomiStringData *d = n->e.n.nodeName.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

DOMString ProcessingInstruction_getData(SDomiProcessingInstruction *n) {
    DOMString r;
    SDomiStringData *d = n->data.d;

    gDomiError = 0;
    r.len = d->s.len;
    r.size = r.len;
    r.str = d->s.str;
    return r;
}

void ProcessingInstruction_setData(SDomiProcessingInstruction *n, const DOMString *data) {
    int err = 7;

    if (!DOMI_READONLY(n)) {
        SDomiString s = DomiAPI_ConvertString(data);
        err = n->e.n.vt->set_nodeValue(n, &s);
    }
    gDomiError = err;
}

SDomiNode *Document_getDoctype(SDomiDocument *doc) {
    SDomiNode *r = (SDomiNode *)doc->i.n.vt->get_doctype(doc);

    gDomiError = 0;
    return r;
}

SDomiImplementation *Document_getImplementation(SDomiDocument *doc) {
    SDomiImplementation * r = doc->implementation;

    gDomiError = 0;
    return r;
}

SDomiNode *Document_getDocumentElement(SDomiDocument *doc) {
    SDomiNode * r = doc->documentElement;

    gDomiError = 0;
    return r;
}

SDomiNode *Document_createElement(SDomiDocument *doc, const DOMString *tag) {
    SDomiString s = DomiAPI_ConvertString(tag);
    SDomiStringH h;
    SDomiNode *out;
    int err;

    SDomiStringH_Init(&h);
    if (SDomiStringH_Set(&h, &s)) {
        err = doc->i.n.vt->createElement(doc, &h, &out);
    } else {
        out = NULL;
        err = -1;
    }
    SDomiStringH_Finalize(&h);
    gDomiError = err;
    return out;
}

SDomiNode *Document_createDocumentFragment(SDomiDocument *doc) {
    SDomiNode *out;

    gDomiError = doc->i.n.vt->createDocumentFragment(doc, &out);
    return out;
}

SDomiNode *Document_createTextNode(SDomiDocument *doc, const DOMString *data) {
    SDomiString s = DomiAPI_ConvertString(data);
    SDomiNode *out;

    gDomiError = doc->i.n.vt->createTextNode(doc, &s, &out);
    return out;
}

SDomiNode *Document_createComment(SDomiDocument *doc, const DOMString *data) {
    SDomiString s = DomiAPI_ConvertString(data);
    SDomiNode *out;

    gDomiError = doc->i.n.vt->createComment(doc, &s, &out);
    return out;
}

SDomiNode *Document_createCDATASection(SDomiDocument *doc, const DOMString *data) {
    SDomiString s = DomiAPI_ConvertString(data);
    SDomiNode *out;

    gDomiError = doc->i.n.vt->createCDATASection(doc, &s, &out);
    return out;
}

SDomiNode *Document_createProcessingInstruction(SDomiDocument *doc, const DOMString *target, const DOMString *data) {
    SDomiString t = DomiAPI_ConvertString(target);
    SDomiString d = DomiAPI_ConvertString(data);
    SDomiStringH ht;
    SDomiStringH hd;
    SDomiNode *out;
    int err;

    SDomiStringH_Init(&ht);
    SDomiStringH_Init(&hd);
    if (SDomiStringH_Set(&ht, &t) && SDomiStringH_Set(&hd, &d)) {
        err = doc->i.n.vt->createProcessingInstruction(doc, &ht, &hd, &out);
    } else {
        out = NULL;
        err = -1;
    }
    SDomiStringH_Finalize(&hd);
    SDomiStringH_Finalize(&ht);
    gDomiError = err;
    return out;
}

SDomiNode *Document_createAttribute(SDomiDocument *doc, const DOMString *name) {
    SDomiString s = DomiAPI_ConvertString(name);
    SDomiStringH h;
    SDomiNode *out;
    int err;

    SDomiStringH_Init(&h);
    if (SDomiStringH_Set(&h, &s)) {
        err = doc->i.n.vt->createAttribute(doc, &h, &out);
    } else {
        out = NULL;
        err = -1;
    }
    SDomiStringH_Finalize(&h);
    gDomiError = err;
    return out;
}

SDomiNode *Document_createEntityReference(SDomiDocument *doc, const DOMString *name) {
    SDomiString s = DomiAPI_ConvertString(name);
    SDomiStringH h;
    SDomiNode *out;
    int err;

    SDomiStringH_Init(&h);
    if (SDomiStringH_Set(&h, &s)) {
        err = doc->i.n.vt->createEntityReference(doc, &h, &out);
    } else {
        out = NULL;
        err = -1;
    }
    SDomiStringH_Finalize(&h);
    gDomiError = err;
    return out;
}

void *Document_getElementsByTagName(SDomiDocument *doc, const DOMString *name) {
    SDomiString s = DomiAPI_ConvertString(name);
    void *set = (void *)doc->i.n.vt->getElementsByTagName(doc, &s);

    if (set != NULL) {
        gDomiError = 0;
    } else {
        set = AcsExterngDomiNodeSetEmpty();
        gDomiError = -1;
    }
    return set;
}

SDomiNode *Document_importNode(SDomiDocument *doc, SDomiNode *node, int deep) {
    SDomiNode *out;

    gDomiError = doc->i.n.vt->importNode(doc, node, deep, &out);
    return out;
}

SDomiNode *Document_getElementById(SDomiDocument *doc, const DOMString *id) {
    SDomiString s = DomiAPI_ConvertString(id);
    SDomiNode *r = (SDomiNode *)doc->i.n.vt->getElementById(doc, &s);

    gDomiError = 0;
    return r;
}

int DomiMoreMemory(void) {
    return SDomiDocManager_Free(&gDomiDocManager);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/httpdisasm", D_00134D90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/httpdisasm", D_00134D94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/httpdisasm", gDomiCharacterDataVt);
