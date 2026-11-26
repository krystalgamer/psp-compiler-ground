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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_HTMLDOMImplementation_createHTMLDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_Elament_getCharactorData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_HTMLDocument_getBody);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_HTMLFormElement_getLength);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_HTMLSelectElement_getLength);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_HTMLSelectElement_getType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_HTMLOptionElement_getIndex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_Node_TraceNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/DOMAPI", Util_getNodeByTagName);

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
