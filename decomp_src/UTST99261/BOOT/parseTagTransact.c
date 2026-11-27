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
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseTagTransact);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseTagCommon);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseSearchTdThNode);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagDefault);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndCloseTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseDefTagElmName);
