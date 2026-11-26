/* NetFront-style DOM core (SDomi* / cmDomi* / UDomi*), recovered from the asm */
#ifndef DOM_DOMI_H
#define DOM_DOMI_H

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned short DOMChar;

typedef struct SDomiString {
    unsigned int len;
    DOMChar *str;
} SDomiString;

/* reference-counted string data, the characters follow it */
typedef struct SDomiStringData {
    int ref;
    SDomiString s;
} SDomiStringData;

typedef struct SDomiStringH {
    SDomiStringData *d;
} SDomiStringH;

/* growable character buffer */
typedef struct SDomiStrAcu {
    unsigned int grow;
    unsigned int alloc;
    unsigned int len;
    DOMChar *buf;
} SDomiStrAcu;

typedef struct SDomiSLink {
    struct SDomiSLink *next;
} SDomiSLink;

typedef struct SDomiPtrArray {
    unsigned int grow;
    unsigned int alloc;
    unsigned int count;
    void **items;
} SDomiPtrArray;

struct SDomiDocument;

/* lazily built node list */
typedef struct SDomiNodeSet {
    SDomiSLink link;                  /* 0x00 */
    SDomiStringH name;                /* 0x04 */
    struct SDomiNode *root;           /* 0x08 */
    int (*build)(struct SDomiNodeSet *); /* 0x0C */
    SDomiPtrArray arr;                /* 0x10 */
    unsigned char valid;              /* 0x20 */
} SDomiNodeSet;
struct SDomiNodeVt;

typedef struct SDomiNode {
    const struct SDomiNodeVt *vt;    /* 0x00 */
    unsigned char flags;              /* 0x04 */
    unsigned char nodeType;           /* 0x05 */
    SDomiSLink trash;                 /* 0x08 */
    struct SDomiDocument *ownerDocument; /* 0x0C */
    SDomiStringH nodeName;            /* 0x10 */
    void *x14;
    void *x18;
    void *x1C;
} SDomiNode;

/* leaf node with its own sibling links */
typedef struct SDomiExternalNode {
    SDomiNode n;
    SDomiNode *parentNode;            /* 0x20 */
    SDomiNode *previousSibling;       /* 0x24 */
    SDomiNode *nextSibling;           /* 0x28 */
} SDomiExternalNode;

typedef struct SDomiCharacterData {
    SDomiExternalNode e;
    SDomiStrAcu data;                 /* 0x2C */
} SDomiCharacterData;

typedef struct SDomiProcessingInstruction {
    SDomiExternalNode e;
    SDomiStringH data;                /* 0x2C */
} SDomiProcessingInstruction;

typedef struct SDomiInternalNode {
    SDomiNode n;
    SDomiNode *firstChild;            /* 0x20 */
    SDomiNode *lastChild;             /* 0x24 */
    SDomiSLink nodeSets;              /* 0x28 */
} SDomiInternalNode;

typedef struct SDomiTrunkNode {
    SDomiInternalNode i;
    SDomiNode *parentNode;            /* 0x2C */
    SDomiNode *previousSibling;       /* 0x30 */
    SDomiNode *nextSibling;           /* 0x34 */
} SDomiTrunkNode;

typedef struct SDomiImplementationVt {
    void (*Finalize)();               /* 0x00 */
    int (*hasFeature)();              /* 0x04 */
    int (*createDocumentType)();      /* 0x08 */
    int (*createDocument)();          /* 0x0C */
} SDomiImplementationVt;

typedef struct SDomiImplementation {
    const SDomiImplementationVt *vt;
    SDomiSLink trash;                 /* 0x04 */
} SDomiImplementation;

typedef struct SDomiDocument {
    SDomiInternalNode i;
    SDomiImplementation *implementation; /* 0x2C */             /* 0x2C */
    void *x30;
    int changed;                      /* 0x34 */
    SDomiSLink trash;                 /* 0x38 */
} SDomiDocument;

typedef struct SDomiEntity {
    SDomiInternalNode i;
    void *x2C;
    SDomiStringH publicId;            /* 0x30 */
    SDomiStringH systemId;            /* 0x34 */
    SDomiStringH notationName;        /* 0x38 */
} SDomiEntity;

typedef struct SDomiNotation {
    SDomiNode n;
    void *x20;
    SDomiStringH publicId;            /* 0x24 */
    SDomiStringH systemId;            /* 0x28 */
} SDomiNotation;

typedef int (*SDomiFn)();

typedef struct SDomiNodeVt {
    void (*Finalize)();               /* 0x00 */
    void (*Changed)();                /* 0x04 */
    void (*SetParentNode)();          /* 0x08 */
    void (*SetPreviousSibling)();     /* 0x0C */
    void (*SetNextSibling)();         /* 0x10 */
    void (*InheritObjInfo)();         /* 0x14 */
    void (*FreeTrash)();              /* 0x18 */
    int (*get_nodeValue)();           /* 0x1C */
    int (*set_nodeValue)();           /* 0x20 */
    SDomiNode *(*get_parentNode)();   /* 0x24 */
    int (*get_childNodes)();          /* 0x28 */
    SDomiNode *(*get_firstChild)();   /* 0x2C */
    SDomiNode *(*get_lastChild)();    /* 0x30 */
    SDomiNode *(*get_previousSibling)(); /* 0x34 */
    SDomiNode *(*get_nextSibling)();  /* 0x38 */
    void *(*get_attributes)();        /* 0x3C */
    int (*insertBefore)();            /* 0x40 */
    int (*removeChild)();             /* 0x44 */
    int (*hasChildNodes)();           /* 0x48 */
    int (*cloneNode)();               /* 0x4C */
    int (*isSupported)();             /* 0x50 */
    int (*get_namespaceURI)();        /* 0x54 */
    int (*get_prefix)();              /* 0x58 */
    int (*set_prefix)();              /* 0x5C */
    int (*get_localName)();           /* 0x60 */
    int (*hasAttributes)();           /* 0x64 */
    /* SDomiDocument */
    int (*get_doctype)();             /* 0x68 */
    int (*createElement)();           /* 0x6C */
    int (*createDocumentFragment)();  /* 0x70 */
    int (*createTextNode)();          /* 0x74 */
    int (*createComment)();           /* 0x78 */
    int (*createCDATASection)();      /* 0x7C */
    int (*createProcessingInstruction)(); /* 0x80 */
    int (*createAttribute)();         /* 0x84 */
    int (*createEntityReference)();   /* 0x88 */
    int (*getElementsByTagName)();    /* 0x8C */
    int (*importNode)();              /* 0x90 */
    int (*createElementNS)();         /* 0x94 */
    int (*createAttributeNS)();       /* 0x98 */
    int (*getElementsByTagNameNS)();  /* 0x9C */
    int (*getElementById)();          /* 0xA0 */
} SDomiNodeVt;

/* named node set (attributes) vtable */
typedef struct SDomiNamedNodeSetVt {
    int (*getNamedItem)();            /* 0x00 */
    int (*setNamedItem)();            /* 0x04 */
    int (*removeNamedItem)();         /* 0x08 */
    SDomiNode *(*item)();             /* 0x0C */
    unsigned int (*get_length)();     /* 0x10 */
    int (*getNamedItemNS)();          /* 0x14 */
    int (*setNamedItemNS)();          /* 0x18 */
    int (*removeNamedItemNS)();       /* 0x1C */
} SDomiNamedNodeSetVt;

typedef struct SDomiNamedNodeSet {
    const SDomiNamedNodeSetVt *vt;
    SDomiNode *owner;
    unsigned char x8;
} SDomiNamedNodeSet;

typedef struct SDomiElement {
    SDomiTrunkNode t;
    SDomiPtrArray attrs;              /* 0x38 */
    SDomiNamedNodeSet attrSet;        /* 0x48 */
} SDomiElement;

typedef struct SDomiAttr {
    SDomiInternalNode i;
    SDomiElement *ownerElement;       /* 0x2C */
    SDomiStringH value;               /* 0x30 */
    unsigned char specified;          /* 0x34 */
} SDomiAttr;

typedef struct SDomiElementVt {
    void *node[26];                   /* SDomiNodeVt up to hasAttributes */
    int (*GetAttrNode)();             /* 0x68 */
    int (*GetDefault)();              /* 0x6C */
    int (*SetAttrNode)();             /* 0x70 */
    int (*RemoveAttrNode)();          /* 0x74 */
    void *(*getElementsByTagName)();  /* 0x78 */
} SDomiElementVt;

#define ELEMVT(e) ((const SDomiElementVt *)((SDomiNode *)(e))->vt)

/* string of the DOM API layer (DOMAPI.c) */
typedef struct DOMString {
    int size;
    int len;
    DOMChar *str;
} DOMString;

extern SDomiStringData gSDnull;

SDomiStringData *AcsExterngSDnull(void);
const SDomiString *AcsExterngSnull(void);

/* a string handle starts as a reference to the shared empty string */
#define SDomiStringH_Init(h) (AcsExterngSDnull()->ref++, (h)->d = AcsExterngSDnull())

void *UDomiMemory_Allocate(unsigned int size);
void UDomiMemory_Free(void *p);
void UDomiMemory_Copy(void *d, const void *s, unsigned int n);
void UDomiMemory_Move(void *d, const void *s, unsigned int n);
DOMChar *UDomiString_Allocate(unsigned int len);
void UDomiString_Free(DOMChar *s);
void UDomiString_Copy(DOMChar *d, const DOMChar *s, unsigned int len);
void UDomiString_Move(DOMChar *d, const DOMChar *s, unsigned int len);

int SDomiStringData_Free(SDomiStringData *d);
void SDomiStringH_Finalize(SDomiStringH *h);
int SDomiStringH_Set(SDomiStringH *h, const SDomiString *s);
void SDomiStringH_Assign(SDomiStringH *h, const SDomiStringH *src);

void SDomiStrAcu_Initialize(SDomiStrAcu *a, unsigned int grow);
void SDomiStrAcu_Finalize(SDomiStrAcu *a);
void SDomiStrAcu_Reset(SDomiStrAcu *a);
int SDomiStrAcu_Truncate(SDomiStrAcu *a);
int SDomiStrAcu_Allocate(SDomiStrAcu *a, unsigned int n);
int SDomiStrAcu_Insert(SDomiStrAcu *a, unsigned int pos, const SDomiString *s);
void SDomiStrAcu_Delete(SDomiStrAcu *a, unsigned int pos, unsigned int n);

SDomiSLink *SDomiSLink_first(SDomiSLink *head);
SDomiSLink *SDomiSLink_next(SDomiSLink *head, SDomiSLink *cur);
void SDomiSLink_Insert(SDomiSLink *head, SDomiSLink *l);
void SDomiSLink_Remove(SDomiSLink *head, SDomiSLink *l);
SDomiSLink *SDomiSLink_RemoveFirst(SDomiSLink *head);
SDomiSLink *SDomiSLink_RemoveLast(SDomiSLink *head);
SDomiNode *RecoverNodePtr(SDomiSLink *l);
SDomiNode *SDomiNodeSLink_RemoveFirst(SDomiSLink *head);
void SDomiNodeSLink_DeleteAll(SDomiSLink *head);

void SDomiPtrArray_Initialize(SDomiPtrArray *a, unsigned int grow);
void SDomiPtrArray_Finalize(SDomiPtrArray *a);
void SDomiPtrArray_Free(SDomiPtrArray *a);
void *SDomiPtrArray_GetItem(SDomiPtrArray *a, unsigned int i);
void SDomiPtrArray_Replace(SDomiPtrArray *a, unsigned int i, void *p);
int SDomiPtrArray_Insert(SDomiPtrArray *a, unsigned int i, void *p);
void SDomiPtrArray_Remove(SDomiPtrArray *a, unsigned int i);

void SDomiNode_Initialize(SDomiNode *n, const SDomiNodeVt *vt, int flags, int type,
                          struct SDomiDocument *doc, const SDomiStringH *name);
void SDomiExternalNode_Initialize(SDomiNode *n, const SDomiNodeVt *vt, int flags, int type,
                                  struct SDomiDocument *doc, const SDomiStringH *name);
void SDomiInternalNode_Initialize(SDomiNode *n, const SDomiNodeVt *vt, int flags, int type,
                                  struct SDomiDocument *doc, const SDomiStringH *name);
void SDomiTrunkNode_Initialize(SDomiTrunkNode *n, const SDomiNodeVt *vt, int flags, int type,
                               struct SDomiDocument *doc, const SDomiStringH *name);
int SDomiInternalNode_CloneChildren(SDomiNode *n, SDomiNode *clone);
SDomiStringH *AcsExterngSHnull(void);
void cmDomiNode_Finalize(SDomiNode *n);
void cmDomiInternalNode_Changed(SDomiNode *n);

int SDomiCharacterData_set_data(SDomiCharacterData *n, const SDomiString *s);
int SDomiCharacterData_deleteData(SDomiCharacterData *n, unsigned int off, unsigned int count);

#endif
