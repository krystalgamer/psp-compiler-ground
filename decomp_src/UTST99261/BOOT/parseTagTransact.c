/* cflags: -O1 */
#include "common.h"
#include "parse_tag.h"
#include "m2c_macros.h"
typedef struct { const DOMChar *p[2]; } PtrArr2;
typedef struct { const DOMChar *p[3]; } PtrArr3;
typedef struct { const DOMChar *p[4]; } PtrArr4;
extern const DOMChar D_00138BFC[];
extern const DOMChar D_00138C04[];
extern const DOMChar D_00138C08[];
extern const DOMChar D_00138C0C[];
extern const DOMChar D_00138C10[];
extern const DOMChar D_00138C48[];
extern const DOMChar D_00138C64[];
extern const DOMChar D_00138C68[];
extern const DOMChar D_00138C6C[];
extern const DOMChar D_00138C70[];
extern const DOMChar D_00138C90[];
extern const DOMChar D_00138CAC[];
extern const PtrArr2 D_00138C18;
extern const PtrArr2 D_00138C38;
extern const PtrArr2 D_00138C94;
extern const PtrArr2 D_00138CA4;
extern const PtrArr2 D_00138E00;
extern const PtrArr3 D_00138C58;
extern const PtrArr4 D_00138C28;
M2C_UNK parseSearchDtDdNode(void *);                /* extern */
M2C_UNK parseSearchListNode(void *);                /* extern */
M2C_UNK parseSearchOptionNode(void *);              /* extern */
M2C_UNK parseSearchPNode();                         /* extern */
M2C_UNK parseSearchRowGroupNode(void *);            /* extern */
M2C_UNK parseSearchTableNode(void *);               /* extern */
M2C_UNK parseSearchTdThNode(void *);                /* extern */
M2C_UNK parseSearchTrNode(void *);                  /* extern */


typedef struct { const DOMChar *p[5]; } PtrArr5;
typedef struct { const DOMChar *p[6]; } PtrArr6;
extern const PtrArr5 D_00138C78;
extern const PtrArr3 D_00138CC0;
extern const PtrArr6 D_00138CDC;
typedef struct { int x00; unsigned int len; DOMChar *data; } TDStr;
TDStr *parseMBtoDScopy(DOMChar *s, int n);
int Document_createElement(int doc, TDStr *name);
void MEM_free(void *pool, void *p);
void *Node_appendChild(int parent, int child);
void parseAlertMessage(void *c);
typedef struct { int size; unsigned int len; DOMChar *str; } TDOMString;
typedef struct { const DOMChar *name; int x04; signed char type; char x09; short id; } TTag;
typedef struct { char x00[0x34]; TTag tag; char x40[0x118 - 0x40]; int doc; int cur; char x120[0x164 - 0x120]; int alertCount; } TCtx;
int Element_getTagName(TDOMString *s, int node);
int parseDStrEqual(const DOMChar *a, TDOMString *b);
int parseTagCountMinus(TCtx *c, TTag t);
void *MEM_malloc(void *pool, unsigned int size);
void *MEM_realloc(void *pool, void *p, unsigned int size);
int Node_getParentNode(int node);
TTag parseDSTagNameCmp(TDOMString *name);
extern const TDOMString D_00138BF0;
int parseTagCountPlus(TCtx *c, TTag t);
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseTagTransact);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseTagCommon);

int parseSearchTdThNode(void *ctx) {
    TCtx *c = ctx;
    TDOMString name;
    TDOMString t;
    TTag *list;
    int node;
    int el;
    int n = 0;
    int cap = 16;
    int i;

    node = c->cur;
    Element_getTagName(&name, node);
    list = MEM_malloc(0, 0xC0);
    if (list == NULL) {
        goto out;
    }
    list[0] = parseDSTagNameCmp(&name);
    for (;;) {
        if (parseDStrEqual(D_00138BFC, &name) || parseDStrEqual(D_00138C04, &name) || parseDStrEqual(D_00138C08, &name) || parseDStrEqual(D_00138C0C, &name)) {
            break;
        }
        if (parseDStrEqual(D_00138C10, &name)) {
            break;
        }
        n++;
        if (n >= cap) {
            cap = cap * 3 / 2;
            list = MEM_realloc(0, list, cap * sizeof(TTag));
            if (list == NULL) {
                goto out;
            }
        }
        node = Node_getParentNode(node);
        if (node == 0) {
            break;
        }
        Element_getTagName(&name, node);
        list[n] = parseDSTagNameCmp(&name);
    }
    if (parseDStrEqual(D_00138C0C, &name) || parseDStrEqual(D_00138C04, &name)) {
        c->cur = Node_getParentNode(node);
        for (i = 0; i <= n; i++) {
            parseTagCountMinus(c, list[i]);
        }
    } else if (parseDStrEqual(D_00138C10, &name)) {
        t = D_00138BF0;
        el = Document_createElement(c->doc, (TDStr *)&t);
        c->alertCount++;
        if (el != 0) {
            Node_appendChild(c->cur, el);
            c->cur = el;
        }
        parseAlertMessage(c);
        c->tag = parseDSTagNameCmp(&t);
        parseTagCountPlus(c, c->tag);
        for (i = 0; i <= n - 1; i++) {
            parseTagCountMinus(c, list[i]);
        }
    }
    MEM_free(0, list);
out:
    ;
}

int parseSearchTrNode(void *ctx) {
    PtrArr2 tags = D_00138C18;
    const DOMChar *stop[1];

    stop[0] = D_00138C08;
    return parseTagCommon(ctx, stop, 1, tags.p, 2);
}

int parseSearchTableNode(void *ctx) {
    PtrArr4 tags = D_00138C28;
    const DOMChar *stop[1];

    stop[0] = D_00138C10;
    return parseTagCommon(ctx, stop, 1, tags.p, 4);
}

int parseSearchRowGroupNode(void *ctx) {
    PtrArr2 tags = D_00138C38;
    PtrArr3 stop = D_00138C58;


    return parseTagCommon(ctx, stop.p, 3, tags.p, 2);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138BF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138BFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C04);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C0C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C28);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C58);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C68);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C78);

int parseSearchListNode(void *ctx) {
    PtrArr5 tags = D_00138C78;
    const DOMChar *stop[1];

    stop[0] = (const DOMChar *)"li";
    return parseTagCommon(ctx, stop, 1, tags.p, 5);
}

int parseSearchDtDdNode(void *ctx) {
    PtrArr2 tags = D_00138C94;
    PtrArr2 stop = D_00138CA4;


    return parseTagCommon(ctx, stop.p, 2, tags.p, 2);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CA0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CC0);

int parseSearchOptionNode(void *ctx) {
    PtrArr3 tags = D_00138CC0;
    const DOMChar *stop[1];

    stop[0] = (const DOMChar *)"option";
    return parseTagCommon(ctx, stop, 1, tags.p, 3);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CDC);

int parseSearchPNode(ctx)
void *ctx;
{
    PtrArr6 tags = D_00138CDC;
    const DOMChar *stop[1];

    stop[0] = (const DOMChar *)"p";
    return parseTagCommon(ctx, stop, 1, tags.p, 6);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void parseOmissibleTag(void *arg0) {
    short temp_v0;

    if ((M2C_FIELD(arg0, signed char *, 0x3C) == 1) && (M2C_FIELD(arg0, short *, 0x3E) != 0x4E)) {
        parseSearchPNode();
    }
    temp_v0 = M2C_FIELD(arg0, short *, 0x3E);
    switch (temp_v0) {
    case 0x50:
    case 0x53:
        parseSearchTdThNode(arg0);
        return;
    case 0x34:
        parseSearchListNode(arg0);
        return;
    case 0x15:
    case 0x1B:
        parseSearchDtDdNode(arg0);
        return;
    case 0x3D:
    case 0x3E:
        parseSearchOptionNode(arg0);
        return;
    case 0x56:
        parseSearchTrNode(arg0);
        return;
    case 0x4E:
        parseSearchTableNode(arg0);
        return;
    case 0x4F:
    case 0x52:
    case 0x54:
        parseSearchRowGroupNode(arg0);
        /* fallthrough */
        /* fallthrough */
    default:
        return;
    }
}

void parseEndTagDefault(TCtx *c) {
    TDOMString name;
    const DOMChar *tn;
    TTag *tags;
    int node;
    int n = 0;
    int cap = 16;
    int i;

    tn = c->tag.name;
    node = c->cur;
    Element_getTagName(&name, node);
    tags = MEM_malloc(0, 0xC0);
    if (tags == NULL) {
        return;
    }
    tags[0] = parseDSTagNameCmp(&name);
    for (;;) {
        if (parseDStrEqual(D_00138BFC, &name) || parseDStrEqual(D_00138C10, &name) || parseDStrEqual(D_00138C0C, &name)) {
            break;
        }
        if (parseDStrEqual(tn, &name)) {
            break;
        }
        n++;
        if (n >= cap) {
            cap = cap * 3 / 2;
            tags = MEM_realloc(0, tags, cap * sizeof(TTag));
            if (tags == NULL) {
                return;
            }
        }
        node = Node_getParentNode(node);
        if (node == 0) {
            break;
        }
        Element_getTagName(&name, node);
        tags[n] = parseDSTagNameCmp(&name);
    }
    if (parseDStrEqual(tn, &name)) {
        c->cur = Node_getParentNode(node);
        for (i = 0; i < n; i++) {
            parseTagCountMinus(c, tags[i]);
        }
    }
    MEM_free(0, tags);
}

int parseEndTagTD(void *ctx) {
    PtrArr2 tags = D_00138E00;
    const DOMChar *stop[1];

    stop[0] = D_00138C0C;
    return parseTagCommon(ctx, stop, 1, tags.p, 2);
}

int parseEndTagTH(void *ctx) {
    PtrArr2 tags = D_00138C38;
    const DOMChar *stop[1];

    stop[0] = D_00138C04;
    return parseTagCommon(ctx, stop, 1, tags.p, 2);
}

int parseEndTagTR(void *ctx) {
    PtrArr2 tags = D_00138C38;
    const DOMChar *stop[1];

    stop[0] = D_00138C08;
    return parseTagCommon(ctx, stop, 1, tags.p, 2);
}

int parseEndTagTABLE(void *ctx) {
    const DOMChar *stop[1];
    const DOMChar *tags[1];

    tags[0] = D_00138BFC;
    stop[0] = D_00138C10;
    return parseTagCommon(ctx, stop, 1, tags, 1);
}

int parseEndTagTBODY(void *ctx) {
    PtrArr2 tags = D_00138C38;
    const DOMChar *stop[1];

    stop[0] = D_00138C48;
    return parseTagCommon(ctx, stop, 1, tags.p, 2);
}

int parseEndTagOL(void *ctx) {
    const DOMChar *stop[1];
    const DOMChar *tags[1];

    tags[0] = D_00138BFC;
    stop[0] = D_00138C68;
    return parseTagCommon(ctx, stop, 1, tags, 1);
}

int parseEndTagUL(void *ctx) {
    const DOMChar *stop[1];
    const DOMChar *tags[1];

    tags[0] = D_00138BFC;
    stop[0] = D_00138C64;
    return parseTagCommon(ctx, stop, 1, tags, 1);
}

int parseEndTagDIR(void *ctx) {
    const DOMChar *stop[1];
    const DOMChar *tags[1];

    tags[0] = D_00138BFC;
    stop[0] = D_00138C6C;
    return parseTagCommon(ctx, stop, 1, tags, 1);
}

int parseEndTagMENU(void *ctx) {
    const DOMChar *stop[1];
    const DOMChar *tags[1];

    tags[0] = D_00138BFC;
    stop[0] = D_00138C70;
    return parseTagCommon(ctx, stop, 1, tags, 1);
}

int parseEndTagDL(void *ctx) {
    const DOMChar *stop[1];
    const DOMChar *tags[1];

    tags[0] = D_00138BFC;
    stop[0] = D_00138C90;
    return parseTagCommon(ctx, stop, 1, tags, 1);
}

int parseEndTagSELECT(void *ctx) {
    const DOMChar *stop[1];
    const DOMChar *tags[1];

    tags[0] = D_00138BFC;
    stop[0] = D_00138CAC;
    return parseTagCommon(ctx, stop, 1, tags, 1);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138E00);

int parseEndTagFORM(void *ctx) {
    PtrArr2 tags = D_00138C38;
    const DOMChar *stop[1];

    stop[0] = (const DOMChar *)"form";
    return parseTagCommon(ctx, stop, 1, tags.p, 2);
}

void parseEndCloseTag(TCtx *c) {
    TDOMString name;

    Element_getTagName(&name, c->cur);
    if (parseDStrEqual(D_00138BFC, &name)) {
        return;
    }
    if (c->tag.type == 1 && c->tag.id != 0x4E) {
        parseSearchPNode(c, c->tag);
    }
    if (parseTagCountMinus(c, c->tag) == 1) {
        return;
    }
    switch (c->tag.id) {
    case 0x50:
        parseEndTagTD(c);
        break;
    case 0x53:
        parseEndTagTH(c);
        break;
    case 0x56:
        parseEndTagTR(c);
        break;
    case 0x4F:
        parseEndTagTBODY(c);
        break;
    case 0x4E:
        parseEndTagTABLE(c);
        break;
    case 0x3C:
        parseEndTagOL(c);
        break;
    case 0x59:
        parseEndTagUL(c);
        break;
    case 0x18:
        parseEndTagDIR(c);
        break;
    case 0x37:
        parseEndTagMENU(c);
        break;
    case 0x1A:
        parseEndTagDL(c);
        break;
    case 0x46:
        parseEndTagSELECT(c);
        break;
    case 0x1F:
        parseEndTagFORM(c);
        break;
    default:
        parseEndTagDefault(c);
        break;
    }
}

void parseDefTagElmName(void *c, DOMChar *str, int len) {
    TDStr *d;
    int el;
    unsigned int i;

    d = parseMBtoDScopy(str, len);
    if (d != NULL && d->len != 0) {
        for (i = 0; i < d->len; i++) {
            d->data[i] = ((DOMChar)(d->data[i] - 'a') < 26) ? d->data[i] - 0x20 : d->data[i];
        }
    }
    el = Document_createElement(M2C_FIELD(c, int *, 0x118), d);
    if (d != NULL) {
        MEM_free(0, d->data);
        d->data = NULL;
        MEM_free(0, d);
    }
    if (el != 0) {
        Node_appendChild(M2C_FIELD(c, int *, 0x11C), el);
        M2C_FIELD(c, int *, 0x11C) = el;
    }
    parseAlertMessage(c);
}
