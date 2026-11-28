/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
#include "m2c_macros.h"
extern char lo_global[];
typedef struct COLCONTENT { int x0; int span; int x8; u8 align; int x10; int x14; int x18; } COLCONTENT;
int CharacterData_getData(DOMString *s, void *node);
char *DOMStringtoUTF8(DOMString *s);
int Node_getNodeType(void *node);
void *Node_getOwnerDocument(void *node);
int Node_getNodeName(DOMString *s, void *node);
int ucs2ToUtf8(char *dst, DOMChar *src, unsigned int len);
extern char tag_global[];
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
void initMapList(void *);                        /* extern */
extern void *ui_global;
int getDOMAttributeValue(int, M2C_UNK *);           /* extern */
extern unsigned char _DOMvalue;
int Element_hasAttribute(int, M2C_UNK *);           /* extern */
int actRestoreForm(int, void *);                    /* extern */
int getBodyBox(void *);                             /* extern */
int getDOMAttributeValue_PositiveNum(int, M2C_UNK *); /* extern */
extern unsigned char _DOMimmode;
extern unsigned char _DOMmaxlength;
extern unsigned char _DOMreadonly;
extern unsigned char _DOMchecked;
void MEM_free(M2C_UNK, int);                     /* extern */
int atoi(int);                                      /* extern */
extern unsigned char _DOMmultiple;
extern unsigned char _DOMsize;



void *Node_getAttributes(void *node);
int NamedNodeMap_getLength(void *map);
void *NamedNodeMap_item(void *map, int i);
void *memset(void *p, int c, unsigned int n);
char *getRawTextFromDomNode(void *n);
int strcmp(const char *, const char *);
SDomiNode *Node_getFirstChild(SDomiNode *n);
char *strcpy(char *, const char *);
SDomiNode *Node_getNextSibling(SDomiNode *n);
SDomiNode *Node_getParentNode(SDomiNode *n);
void DomStringToUtf8(DOMString *s, char *buf, int size) {
    unsigned int n = (size - 1) / 3;
    unsigned int len = s->len;
    if (n < len) {
        len = n;
    }
    buf[ucs2ToUtf8(buf, s->str, len)] = 0;
}

int checkAtributeByName(void *node, char *name) {
    DOMString s;
    char buf[0x100];
    void *map;
    void *a;
    int n, i;

    map = Node_getAttributes(node);
    if (map == NULL)
        return -1;
    n = NamedNodeMap_getLength(map);
    for (i = 0; i < n; i++) {
        a = NamedNodeMap_item(map, i);
        if (a == NULL)
            break;
        Node_getNodeName(&s, a);
        DomStringToUtf8(&s, buf, 0x100);
        if (strcmp(name, buf) == 0)
            return 0;
    }
    return -1;
}

char *getTagName(void *node) {
    DOMString s;
    if (Node_getNodeType(node) != 1) {
        return NULL;
    }
    Node_getNodeName(&s, node);
    DomStringToUtf8(&s, tag_global, 0x100);
    return tag_global;
}

char *getRawTextFromDomNode(void *node) {
    DOMString s;
    char *r;
    CharacterData_getData(&s, node);
    r = NULL;
    if (s.len != 0) {
        r = DOMStringtoUTF8(&s);
    }
    return r;
}

char *getRawTextFromDomTree(void *root) {
    int total = 0;
    char *res = NULL;
    void *n;
    void *c;
    char *t;
    char *nb;
    int len;

    n = Node_getFirstChild(root);
    while ((n != NULL) & (n != root)) {
        if (Node_getNodeType(n) == 3 && (t = getRawTextFromDomNode(n)) != NULL) {
            if (res == NULL) {
                len = strlen(t);
                res = t;
            } else {
                len = strlen(t);
                nb = MEM_malloc(0, total + len + 1);
                if (nb == NULL) {
                    return res;
                }
                strcpy(nb, res);
                strcpy(nb + total, t);
                MEM_free(0, res);
                MEM_free(0, t);
                res = nb;
            }
            total += len;
        }
        c = Node_getFirstChild(n);
        if (c == NULL) {
            c = Node_getNextSibling(n);
            if (c == NULL) {
                for (;;) {
                    n = Node_getParentNode(n);
                    if (n == root) {
                        break;
                    }
                    c = Node_getNextSibling(n);
                    if (c != NULL) {
                        break;
                    }
                }
                if (n == root) {
                    break;
                }
            }
        }
        n = c;
    }
    return res;
}

char *getTextFromDomTree(void *root) {
    char *raw;
    char *buf;
    char *p;
    int len;
    int i;
    int j;
    int sp = 0;
    char c;

    raw = getRawTextFromDomTree(root);
    if (raw == NULL) {
        return NULL;
    }
    len = strlen(raw);
    buf = MEM_malloc(0, len + 1);
    if (buf == NULL) {
        MEM_free(0, raw);
        return NULL;
    }
    p = raw;
    while (((*p == ' ') | (*p == '\t')) || *p == '\r' || *p == '\n') {
        p++;
        len--;
    }
    j = 0;
    for (i = 0; i < len; i++) {
        c = p[i];
        if (((c == ' ') | (c == '\t')) || ((c == '\r') | (c == '\n'))) {
            if (sp == 0) {
                buf[j++] = ' ';
                sp = 1;
            }
        } else {
            buf[j++] = c;
            sp = 0;
        }
    }
    if (j > 0 && buf[j - 1] == ' ') {
        buf[j - 1] = 0;
    } else {
        buf[j] = 0;
    }
    MEM_free(0, raw);
    return buf;
}

void *getDOMDocument(void *node) {
    if (Node_getNodeType(node) == 9) {
        return node;
    }
    return Node_getOwnerDocument(node);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void initBodyContent(void *arg0) {
    void *temp_v0;

    M2C_FIELD(arg0, short *, 0x38) = 1;
    temp_v0 = MEM_malloc(0, 0xBC);
    memset(temp_v0, 0, 0xBCU);
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = (int) M2C_FIELD(ui_global, int *, 0x88);
    M2C_FIELD(temp_v0, int *, 0xC) = (int) M2C_FIELD(ui_global, int *, 0x8C);
    M2C_FIELD(temp_v0, int *, 0x10) = (int) M2C_FIELD(ui_global, int *, 0x88);
    M2C_FIELD(temp_v0, int *, 0x14) = (int) M2C_FIELD(ui_global, int *, 0x8C);
    M2C_FIELD(temp_v0, int *, 0x18) = 0;
    M2C_FIELD(temp_v0, int *, 0x1C) = 0;
    M2C_FIELD(temp_v0, int *, 0x34) = 0;
    M2C_FIELD(temp_v0, int *, 0x40) = 1;
    initMapList(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void initFramesetContent(void *arg0) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0xB8);
    memset(temp_v0, 0, 0xB8U);
    M2C_FIELD(arg0, short *, 0x38) = 2;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initFrameBorderContent(void *arg0) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 8);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(arg0, short *, 0x38) = 3;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initNoneContent(void *arg0) {
    M2C_FIELD(arg0, short *, 0x38) = 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initTextContent);

void initPreTextContent(void *box, void *node) {
    DOMString s;
    int *t;
    char *buf;
    int size;
    int n;
    int len;
    DOMChar *str;

    t = MEM_malloc(0, 0x14);
    t[0] = 0;
    t[1] = 0;
    t[2] = 0;
    t[3] = 0;
    t[4] = 0;
    M2C_FIELD(box, int **, 0x20) = t;
    M2C_FIELD(box, short *, 0x38) = 9;
    CharacterData_getData(&s, node);
    len = s.len;
    str = s.str;
    size = len * 3 + 1;
    buf = MEM_malloc(0, size);
    memset(buf, 0, size);
    n = ucs2ToUtf8(buf, str, len);
    buf[n] = 0;
    t[0] = (int)buf;
    t[3] = n;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initImageContent(void *arg0) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x2C);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0) = 0;
        M2C_FIELD(temp_v0, int *, 4) = 0;
        M2C_FIELD(temp_v0, int *, 8) = 0;
        M2C_FIELD(temp_v0, int *, 0xC) = 0;
        M2C_FIELD(temp_v0, int *, 0x10) = 0;
        M2C_FIELD(temp_v0, int *, 0x14) = 0;
        M2C_FIELD(temp_v0, int *, 0x18) = 0;
        M2C_FIELD(temp_v0, int *, 0x1C) = 0;
        M2C_FIELD(temp_v0, int *, 0x20) = 0;
        M2C_FIELD(temp_v0, int *, 0x24) = 0;
        M2C_FIELD(temp_v0, int *, 0x28) = 0;
    }
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(arg0, short *, 0x38) = 0xA;
    M2C_FIELD(temp_v0, int *, 0) = (int) (*(int *)(lo_global + 0x14));
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void initTableContent(void *arg0) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x48);
    memset(temp_v0, 0, 0x48U);
    M2C_FIELD(temp_v0, short *, 0x16) = -1;
    M2C_FIELD(temp_v0, short *, 0x18) = 1;
    M2C_FIELD(temp_v0, int *, 8) = 2;
    M2C_FIELD(temp_v0, int *, 4) = 1;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 4;
    M2C_FIELD(arg0, unsigned short *, 0x40) = (unsigned short) (M2C_FIELD(arg0, unsigned short *, 0x40) | 1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initTrContent(void *arg0) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 8);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 5;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initTdContent(void *arg0) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x20);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD(temp_v0, int *, 0x10) = 0;
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
    M2C_FIELD(temp_v0, int *, 0x18) = 0;
    M2C_FIELD(temp_v0, int *, 0x1C) = 0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 6;
    M2C_FIELD(arg0, unsigned short *, 0x40) = (unsigned short) (M2C_FIELD(arg0, unsigned short *, 0x40) | 1);
}

void initColContent(void *box, void *a1, int align) {
    COLCONTENT *c = MEM_malloc(0, sizeof(COLCONTENT));
    memset(c, 0, sizeof(COLCONTENT));
    c->align = align;
    c->span = 1;
    M2C_FIELD(box, void **, 0x20) = c;
    M2C_FIELD(box, s16 *, 0x38) = 7;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void initHlineContent(void *arg0) {
    M2C_FIELD(arg0, short *, 0x38) = 0xB;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initButtonContent(void *arg0, int arg1) {
    int temp_v0_2;
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0xC);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 0x10;
    temp_v0_2 = getDOMAttributeValue(arg1, &_DOMvalue);
    if (temp_v0_2 != 0) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), int *, 8) = temp_v0_2;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initBlockButtonContent(void *arg0) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x14);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD(temp_v0, int *, 0x10) = 0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 0x11;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initTextFieldContent(void *arg0, int arg1, int arg2) {
    int temp_v0_2;
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x24);
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD(temp_v0, int *, 0x10) = 0;
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
    M2C_FIELD(temp_v0, int *, 0x18) = 0;
    M2C_FIELD(temp_v0, int *, 0x1C) = 0;
    M2C_FIELD(temp_v0, int *, 0x20) = 0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 0xD;
    M2C_FIELD(temp_v0, int *, 0) = 0;
    if ((actRestoreForm(getBodyBox(arg0), arg0) == 0) && (arg2 != 0)) {
        M2C_FIELD(temp_v0, int *, 0x14) = getDOMAttributeValue(arg1, &_DOMvalue);
    }
    if (Element_hasAttribute(arg1, &_DOMreadonly) != 0) {
        M2C_FIELD(temp_v0, int *, 0x1C) = 1;
    }
    temp_v0_2 = getDOMAttributeValue_PositiveNum(arg1, &_DOMmaxlength);
    M2C_FIELD(temp_v0, int *, 0xC) = temp_v0_2;
    if (temp_v0_2 < 0) {
        M2C_FIELD(temp_v0, int *, 0xC) = -1;
    }
    M2C_FIELD(temp_v0, int *, 0x20) = getDOMAttributeValue_PositiveNum(arg1, &_DOMimmode);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initPasswordContent(void *arg0, int arg1) {
    int temp_v0_2;
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x24);
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD(temp_v0, int *, 0x10) = 0;
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
    M2C_FIELD(temp_v0, int *, 0x18) = 0;
    M2C_FIELD(temp_v0, int *, 0x1C) = 0;
    M2C_FIELD(temp_v0, int *, 0x20) = 0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 0xD;
    M2C_FIELD(temp_v0, int *, 0) = 2;
    M2C_FIELD(temp_v0, int *, 0x14) = getDOMAttributeValue(arg1, &_DOMvalue);
    if (Element_hasAttribute(arg1, &_DOMreadonly) != 0) {
        M2C_FIELD(temp_v0, int *, 0x1C) = 1;
    }
    temp_v0_2 = getDOMAttributeValue_PositiveNum(arg1, &_DOMmaxlength);
    M2C_FIELD(temp_v0, int *, 0xC) = temp_v0_2;
    if (temp_v0_2 < 0) {
        M2C_FIELD(temp_v0, int *, 0xC) = -1;
    }
    M2C_FIELD(temp_v0, int *, 0x20) = getDOMAttributeValue_PositiveNum(arg1, &_DOMimmode);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initTextAreaContent(void *arg0, int arg1) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x24);
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD(temp_v0, int *, 0x10) = 0;
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
    M2C_FIELD(temp_v0, int *, 0x18) = 0;
    M2C_FIELD(temp_v0, int *, 0x1C) = 0;
    M2C_FIELD(temp_v0, int *, 0x20) = 0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 0xD;
    M2C_FIELD(temp_v0, int *, 0) = 1;
    actRestoreForm(getBodyBox(arg0), arg0);
    if (Element_hasAttribute(arg1, &_DOMreadonly) != 0) {
        M2C_FIELD(temp_v0, int *, 0x1C) = 1;
    }
    M2C_FIELD(temp_v0, int *, 0xC) = -1;
    M2C_FIELD(temp_v0, int *, 0x20) = getDOMAttributeValue_PositiveNum(arg1, &_DOMimmode);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initCheckContent(void *arg0, int arg1) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0xC);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 0xE;
    if ((actRestoreForm(getBodyBox(arg0), arg0) == 0) && (Element_hasAttribute(arg1, &_DOMchecked) != 0)) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), int *, 8) = 1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initRadioContent(void *arg0, int arg1) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0xC);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 0xF;
    if ((actRestoreForm(getBodyBox(arg0), arg0) == 0) && (Element_hasAttribute(arg1, &_DOMchecked) != 0)) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), int *, 8) = 1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initSelectContent(void *arg0, int arg1) {
    int temp_v0_2;
    int temp_v0_3;
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x10);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    if (Element_hasAttribute(arg1, &_DOMmultiple) != 0) {
        M2C_FIELD(temp_v0, int *, 0) = 1;
    }
    M2C_FIELD(temp_v0, int *, 4) = 1;
    temp_v0_2 = getDOMAttributeValue(arg1, &_DOMsize);
    if (temp_v0_2 != 0) {
        temp_v0_3 = atoi(temp_v0_2);
        M2C_FIELD(temp_v0, int *, 4) = temp_v0_3;
        if (temp_v0_3 <= 0) {
            M2C_FIELD(temp_v0, int *, 4) = 1;
        }
        MEM_free(0, temp_v0_2);
    }
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 0x12;
    actRestoreForm(getBodyBox(arg0), arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initMarqueeContent(void *arg0) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0xC);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 0x13;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initListContent(void *arg0) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x14);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD(temp_v0, int *, 0x10) = 0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 8;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initLiContent(void *arg0) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x10);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    M2C_FIELD(arg0, short *, 0x38) = 0x15;
}
