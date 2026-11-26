/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
#include "m2c_macros.h"
typedef struct COLCONTENT { int x0; int span; int x8; u8 align; int x10; int x14; int x18; } COLCONTENT;
void CharacterData_getData(DOMString *s, void *node);
char *DOMStringtoUTF8(DOMString *s);
int Node_getNodeType(void *node);
void *Node_getOwnerDocument(void *node);
void Node_getNodeName(DOMString *s, void *node);
int ucs2ToUtf8(char *dst, DOMChar *src, unsigned int len);
extern char tag_global[];
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK initMapList(void *);                        /* extern */
extern void *ui_global;
extern int D_00584CAC;
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
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
int atoi(int);                                      /* extern */
extern unsigned char _DOMmultiple;
extern unsigned char _DOMsize;



void DomStringToUtf8(DOMString *s, char *buf, int size) {
    unsigned int n = (size - 1) / 3;
    unsigned int len = s->len;
    if (n < len) {
        len = n;
    }
    buf[ucs2ToUtf8(buf, s->str, len)] = 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", checkAtributeByName);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", getRawTextFromDomTree);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", getTextFromDomTree);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initPreTextContent);

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
    M2C_FIELD(temp_v0, int *, 0) = (int) D_00584CAC;
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
