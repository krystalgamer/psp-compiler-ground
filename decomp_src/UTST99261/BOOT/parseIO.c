/* cflags: -O1 */
#include "common.h"
#include "parse_str.h"
#include "m2c_macros.h"
#define CF(c, o) M2C_FIELD(c, int *, o)
extern const PDocDesc D_00137DEC;

int *parseTEXTStart(PCtx *c, int *src) {
    PDocDesc desc;
    void *buf;
    int n;
    int *r;

    desc = D_00137DEC;
    c->x00[4] = src[9];
    DOMAPI_Initialize();
    CF(c, 0x114) = Util_DOMAPI_NewHTMLDOMImplementation();
    CF(c, 0x118) = Util_HTMLDOMImplementation_createHTMLDocument(CF(c, 0x114), 0);
    HST_setDomObject(HST_searchSessionIDHistoryNode(c->x00[4]), CF(c, 0x118));
    Node_setSid(CF(c, 0x118), c->x00[4]);
    parseJSDocumentSet(c);
    CF(c, 0x11C) = Util_HTMLDocument_getBody(CF(c, 0x118));
    DOMAPI_AddDocument(&desc, CF(c, 0x118));
    parseCheckEncodeType(c, src);
    HST_setCharSet(HST_searchSessionIDHistoryNode(c->x00[4]), c->x00[2]);
    buf = MEM_malloc(0, src[6] * 4);
    n = parseConvertEncode(buf, src[7], src[6], c->x00[2]);
    parseDataInputBuf(c, buf, n);
    MEM_free(0, buf);
    parseDocumentTEXT(c);
    r = MEM_malloc(0, 0x14);
    r[1] = 0;
    r[2] = 0;
    r[3] = 0;
    r[4] = 0;
    r[0] = 0;
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", parseBINARYStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", parseContentStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", parseContentContinue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", parseContentContinueJS);

int *parseJSDocumentEncode(int *enc, int *src) {
    void *buf;
    int n;
    int *d;

    buf = MEM_malloc(0, src[6] * 4);
    n = parseConvertEncode(buf, src[7], src[6], enc[2]);
    d = MEM_malloc(0, 0x14);
    d[3] = 0;
    d[4] = 0;
    d[0] = 1;
    d[2] = (int)buf;
    d[1] = n;
    return d;
}

int *parseContentEnd(PCtx *c) {
    int *r;
    void *buf;
    int n;

    r = MEM_malloc(0, 0x14);
    r[1] = 0;
    r[2] = 0;
    r[3] = 0;
    r[4] = 0;
    r[0] = 0;
    if (c == NULL) {
        return r;
    }
    if (CF(c, 0x30) == 0) {
        return r;
    }
    if (CF(c, 0x140) == 0xD) {
        MEM_free(0, CF(c, 0x2C));
        CF(c, 0x2C) = 0;
        CF(c, 0x30) = 0;
        return r;
    }
    buf = MEM_malloc(0, CF(c, 0x30) * 4);
    n = parseConvertEncode(buf, CF(c, 0x2C), CF(c, 0x30), c->x00[2]);
    parseDataInputBuf(c, buf, n);
    MEM_free(0, buf);
    MEM_free(0, CF(c, 0x2C));
    CF(c, 0x2C) = 0;
    CF(c, 0x30) = 0;
    c->x44[2] = 1;
    M2C_FIELD(c, unsigned char *, 0x12C) = 3;
    CF(c, 0x154) = 8;
    parseDocument(c);
    return r;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", D_00137DEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", D_00137DF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseIO", D_00137E04);
