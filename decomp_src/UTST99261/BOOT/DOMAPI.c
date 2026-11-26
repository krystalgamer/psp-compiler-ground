/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
typedef struct SDomiDocManager SDomiDocManager;
extern int gDOMAPIUse;
extern SDomiDocManager gDomiDocManager;
extern int gDomiError;
void *MEM_malloc(int pool, unsigned int size);
void MEM_free(int pool, void *p);
int ucs2ToAscii(unsigned char *dst, const DOMChar *src, int len);
SDomiString DomiAPI_ConvertString(const DOMString *s);
void SDomiDocManager_Initialize(SDomiDocManager *m);
void SDomiDocManager_Finalize(SDomiDocManager *m);
void SDomiDocManager_EmptyTrash(SDomiDocManager *m);
int SDomiDocManager_AddDocument(SDomiDocManager *m, const SDomiString *id, SDomiDocument *doc);
SDomiDocument *SDomiDocManager_ReuseDocument(SDomiDocManager *m, const SDomiString *id);
void SDomiDocManager_TrashDocument(SDomiDocManager *m, const SDomiString *id);
void SDomiDocManager_DiscardDocument(SDomiDocManager *m, const SDomiString *id);
void SDomiDocManager_DeleteDocuments(SDomiDocManager *m, SDomiImplementation *impl);
SDomiDocManager *AcsExterngDomiDocManager(void);
void SDomiImplementation_Initialize(SDomiImplementation *impl, const SDomiImplementationVt *vt);
int SDomiDocument_createCharacterData(SDomiDocument *doc, int type, const SDomiString *s, SDomiNode **out);
SDomiImplementation *DOMAPI_NewDOMImplementation(void);
typedef void Node;
extern DOMString _DOMhtml, _DOMhead, _DOMtitle, _DOMbody, _DOMframeset, _DOMnull;
extern DOMString _DOMbutton, _DOMfieldset, _DOMinput, _DOMisindex, _DOMlabel, _DOMlegend, _DOMobject, _DOMselect, _DOMtextarea;
extern DOMString _DOMoption, _DOMmultiple, _DOM_select_one, _DOM_select_multiple;
Node *DOMImplementation_createDocument(SDomiImplementation *impl, const DOMString *ns, const DOMString *qname, Node *doctype);
Node *Document_createElement(Node *doc, const DOMString *tag);
Node *Document_getDocumentElement(Node *doc);
Node *Node_appendChild(Node *n, Node *child);
Node *Node_getFirstChild(Node *n);
Node *Node_getNextSibling(Node *n);
Node *Node_getParentNode(Node *n);
int Node_getNodeType(Node *n);
DOMString Element_getTagName(Node *n);
int Element_hasAttribute(Node *n, const DOMString *name);
DOMString CharacterData_getData(Node *n);
int DOMStringcasecmpFast(const DOMString *a, const DOMString *b);
Node *Util_Node_TraceNode(Node *n, Node *root);
void DOMAPI_DeleteDOMImplementation(SDomiImplementation *impl);

void DOMAPI_Initialize(void) {
    if (++gDOMAPIUse == 1) {
        SDomiDocManager_Initialize(&gDomiDocManager);
    }
    gDomiError = 0;
}

void DOMAPI_Finalize(void) {
    if (gDOMAPIUse != 0) {
        if (--gDOMAPIUse == 0) {
            SDomiDocManager_Finalize(&gDomiDocManager);
        }
    }
    gDomiError = 0;
}

int DOMAPI_AddDocument(const DOMString *id, SDomiDocument *doc) {
    SDomiString s = DomiAPI_ConvertString(id);

    return SDomiDocManager_AddDocument(&gDomiDocManager, &s, doc);
}

SDomiDocument *DOMAPI_ReuseDocument(const DOMString *id) {
    SDomiString s = DomiAPI_ConvertString(id);

    return SDomiDocManager_ReuseDocument(&gDomiDocManager, &s);
}

void DOMAPI_TrashDocument(const DOMString *id) {
    SDomiString s = DomiAPI_ConvertString(id);

    SDomiDocManager_TrashDocument(&gDomiDocManager, &s);
}

void DOMAPI_DiscardDocument(const DOMString *id) {
    SDomiString s = DomiAPI_ConvertString(id);

    SDomiDocManager_DiscardDocument(&gDomiDocManager, &s);
}

void DOMAPI_EmptyTrash(void) {
    SDomiDocManager_EmptyTrash(&gDomiDocManager);
}

SDomiImplementation *DOMAPI_NewDOMImplementation(void) {
    SDomiImplementation *impl = UDomiMemory_Allocate(sizeof(SDomiImplementation));

    if (impl != NULL) {
        SDomiImplementation_Initialize(impl, NULL);
    }
    return impl;
}

void DOMAPI_DeleteDOMImplementation(SDomiImplementation *impl) {
    SDomiDocManager_DeleteDocuments(AcsExterngDomiDocManager(), impl);
    impl->vt->Finalize(impl);
    UDomiMemory_Free(impl);
}

int DOMAPI_Error(void) {
    return gDomiError;
}

SDomiImplementation *Util_DOMAPI_NewHTMLDOMImplementation(void) {
    return DOMAPI_NewDOMImplementation();
}

void Util_DOMAPI_DeleteHTMLDOMImplementation(SDomiImplementation *impl) {
    DOMAPI_DeleteDOMImplementation(impl);
}

Node *Util_HTMLDOMImplementation_createHTMLDocument(SDomiImplementation *impl) {
    Node *doc, *html, *head, *body;

    doc = DOMImplementation_createDocument(impl, NULL, NULL, NULL);
    html = Document_createElement(doc, &_DOMhtml);
    head = Document_createElement(doc, &_DOMhead);
    if (html == NULL || head == NULL) {
        return NULL;
    }
    Node_appendChild(html, head);
    Node_appendChild(head, Document_createElement(doc, &_DOMtitle));
    body = Document_createElement(doc, &_DOMbody);
    if (body == NULL) {
        return NULL;
    }
    Node_appendChild(html, body);
    Node_appendChild(doc, html);
    return doc;
}

DOMString Util_Elament_getCharactorData(Node *e) {
    Node *n;

    for (n = Node_getFirstChild(e); n != NULL; n = Node_getNextSibling(n)) {
        if (Node_getNodeType(n) == 3) {
            break;
        }
    }
    if (n == NULL) {
        return _DOMnull;
    }
    return CharacterData_getData(n);
}

Node *Util_HTMLDocument_getBody(Node *doc) {
    Node *root, *n;
    DOMString tag;

    root = Document_getDocumentElement(doc);
    if (root == NULL) {
        root = Node_getFirstChild(doc);
    }
    for (n = Node_getFirstChild(root); n != NULL; n = Node_getNextSibling(n)) {
        if (Node_getNodeType(n) == 1) {
            tag = Element_getTagName(n);
            if (DOMStringcasecmpFast(&tag, &_DOMbody) == 0 || DOMStringcasecmpFast(&tag, &_DOMframeset) == 0) {
                return n;
            }
        }
    }
    return NULL;
}

int Util_HTMLFormElement_getLength(Node *form) {
    Node *n;
    DOMString tag;
    int count;

    count = 0;
    n = form;
    while ((n = Util_Node_TraceNode(n, form)) != NULL) {
        if (Node_getNodeType(n) != 1) {
            continue;
        }
        tag = Element_getTagName(n);
        if (DOMStringcasecmpFast(&tag, &_DOMbutton) == 0 || DOMStringcasecmpFast(&tag, &_DOMfieldset) == 0 ||
            DOMStringcasecmpFast(&tag, &_DOMinput) == 0 || DOMStringcasecmpFast(&tag, &_DOMisindex) == 0 ||
            DOMStringcasecmpFast(&tag, &_DOMlabel) == 0 || DOMStringcasecmpFast(&tag, &_DOMlegend) == 0 ||
            DOMStringcasecmpFast(&tag, &_DOMobject) == 0 || DOMStringcasecmpFast(&tag, &_DOMselect) == 0 ||
            DOMStringcasecmpFast(&tag, &_DOMtextarea) == 0) {
            count++;
        }
    }
    return count;
}

int Util_HTMLSelectElement_getLength(Node *sel) {
    Node *n;
    DOMString tag;
    int count;

    count = 0;
    n = sel;
    while ((n = Util_Node_TraceNode(n, sel)) != NULL) {
        if (Node_getNodeType(n) == 1) {
            tag = Element_getTagName(n);
            count += DOMStringcasecmpFast(&tag, &_DOMoption) == 0;
        }
    }
    return count;
}

DOMString Util_HTMLSelectElement_getType(Node *sel) {
    if (Element_hasAttribute(sel, &_DOMmultiple)) {
        return _DOM_select_multiple;
    }
    return _DOM_select_one;
}

int Util_HTMLOptionElement_getIndex(Node *opt) {
    Node *n, *sel;
    DOMString tag;
    int count = 0;

    for (n = opt; (n = Node_getParentNode(n)) != NULL; ) {
        if (Node_getNodeType(n) == 1) {
            tag = Element_getTagName(n);
            if (DOMStringcasecmpFast(&tag, &_DOMselect) == 0) {
                sel = n;
                break;
            }
        }
    }
    if (n == NULL) {
        return 0;
    }
    while ((n = Util_Node_TraceNode(n, sel)) != NULL) {
        if (n == opt) {
            return count;
        }
        if (Node_getNodeType(n) == 1) {
            tag = Element_getTagName(n);
            count += DOMStringcasecmpFast(&tag, &_DOMoption) == 0;
        }
    }
    return 0;
}

Node *Util_Node_TraceNode(Node *n, Node *root) {
    Node *next;

    if ((next = Node_getFirstChild(n)) != NULL) {
        return next;
    }
    if ((next = Node_getNextSibling(n)) != NULL) {
        return next;
    }
    for (;;) {
        n = Node_getParentNode(n);
        if (n == NULL || n == root) {
            return NULL;
        }
        if ((next = Node_getNextSibling(n)) != NULL) {
            return next;
        }
    }
}

Node *Util_getNodeByTagName(Node *node, const DOMString *name) {
    DOMString tag;
    Node *n;

    for (n = node; n != NULL; n = Node_getParentNode(n)) {
        if (Node_getNodeType(n) == 1) {
            tag = Element_getTagName(n);
            if (DOMStringcasecmpFast(name, &tag) == 0) {
                return n;
            }
        }
    }
    return NULL;
}

void DOMStringfree(DOMString *s) {
    if (s->str != NULL) {
        MEM_free(0, s->str);
        s->str = NULL;
        s->len = 0;
        s->size = 0;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", UTF8toDOMString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", ASCIItoDOMString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoJIS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoSJIS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoEUC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringtoUTF8);

unsigned char *DOMStringtoASCII(const DOMString *s) {
    unsigned char *p = MEM_malloc(0, s->len * 2 + 1);

    if (p == NULL) {
        return NULL;
    }
    p[ucs2ToAscii(p, s->str, s->len)] = 0;
    return p;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringEncode);

int DOMStringlen(const DOMString *s) {
    return s->len;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringcat);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringcasecmp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringcasecmpFast);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringcasecmpChar);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", DOMStringcasecmpCharFast);

void cmDomiCharacterData_Finalize(SDomiCharacterData *n) {
    SDomiStrAcu_Finalize(&n->data);
    cmDomiNode_Finalize(&n->e.n);
}

int cmDomiCharacterData_get_nodeValue(SDomiCharacterData *n, SDomiString *out) {
    out->len = n->data.len;
    out->str = n->data.buf;
    return 0;
}

int cmDomiCharacterData_set_nodeValue(SDomiCharacterData *n, const SDomiString *s) {
    return SDomiCharacterData_set_data(n, s);
}

int cmDomiCharacterData_cloneNode(SDomiCharacterData *n, int deep, SDomiNode **out) {
    SDomiNode *clone;
    int r;

    *out = NULL;
    r = SDomiDocument_createCharacterData(n->e.n.ownerDocument, n->e.n.nodeType, (SDomiString *)&n->data.len, &clone);
    if (r == 0) {
        *out = clone;
    }
    return r;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", D_00134DB4);
