/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK parseSearchDtDdNode(void *);                /* extern */
M2C_UNK parseSearchListNode(void *);                /* extern */
M2C_UNK parseSearchOptionNode(void *);              /* extern */
M2C_UNK parseSearchPNode();                         /* extern */
M2C_UNK parseSearchRowGroupNode(void *);            /* extern */
M2C_UNK parseSearchTableNode(void *);               /* extern */
M2C_UNK parseSearchTdThNode(void *);                /* extern */
M2C_UNK parseSearchTrNode(void *);                  /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseTagTransact);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseTagCommon);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseSearchTdThNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseSearchTrNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseSearchTableNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseSearchRowGroupNode);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseSearchListNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseSearchDtDdNode);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138C9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CA0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CC0);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseSearchOptionNode);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138CDC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseSearchPNode);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagTD);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagTH);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagTR);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagTABLE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagTBODY);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagOL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagUL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagDIR);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagMENU);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagDL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagSELECT);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", D_00138E00);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndTagFORM);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseEndCloseTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseTagTransact", parseDefTagElmName);
