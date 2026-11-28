/* cflags: -O1 */
#include "common.h"
#include "parse_str.h"
#include "m2c_macros.h"
extern const PDStr D_00137DF8;
extern const PDStr D_00137E04;
#define CF(c, o) M2C_FIELD(c, int *, o)
extern const PDocDesc D_00137DEC;

void DOMAPI_Initialize(void);
void *Util_DOMAPI_NewHTMLDOMImplementation(void);
int HST_setDomObject(void *arg0, int arg1);
void *HST_searchSessionIDHistoryNode(int sid);
void Node_setSid(void *, void *sid);
void parseJSDocumentSet(void *arg0);
void *Util_HTMLDocument_getBody(void *);
int DOMAPI_AddDocument(void *, void *);
void parseCheckEncodeType(PCtx *c, int *src);
int HST_setCharSet(void *arg0, int arg1);
void *MEM_malloc(void *, unsigned int size);
int parseConvertEncode(void *dst, void *src, int n, int enc);
int parseDataInputBuf(PCtx *c, PChar *data, int n);
void MEM_free(void *, void *p);
int parseDocumentTEXT(PCtx *c);
void *Document_createElement(void *, void *);
void *Node_appendChild(void *, void *);
void parseConvertUTF8toUCS2(char *src, int len, PChar **out, int *outLen);
void parseElementSetAttribute(int elem, PDStr *name, void *val);
void parseJSImgSet(PCtx *c);
void *memcpy(void *, const void *, unsigned int);
int parseWellFormedTag(PChar *buf, int n);
void *parseNewCtxt(void);
void parseCtxtDataCopy(PCtx *d, PCtx *s);
int parseDocument(PCtx *c);
void parseFreeCtxt(PCtx *c);
int parseCheckLastTag(void *ctx, unsigned char *s, int n, int enc);
int parseWellFormedScriptMB(unsigned char *s, int n);
void parseBackTag(PCtx *c);
void parseInsertDocWriteBuffer(PCtx *c);
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

int *parseBINARYStart(PCtx *c, int *src) {
    PDocDesc desc;
    PDStr tag;
    PDStr attr;
    PDStr val;
    PChar *str;
    int len;
    int el;
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
    tag = D_00137DF8;
    attr = D_00137E04;
    len = 0;
    el = Document_createElement(CF(c, 0x118), &tag);
    if (el != 0) {
        Node_appendChild(CF(c, 0x11C), el);
        CF(c, 0x11C) = el;
    }
    parseConvertUTF8toUCS2((char *)src[1], src[0], &str, &len);
    val.len = len;
    val.x00 = len;
    val.data = str;
    parseElementSetAttribute(CF(c, 0x11C), &attr, &val);
    parseJSImgSet(c);
    MEM_free(0, str);
    str = NULL;
    r = MEM_malloc(0, 0x14);
    r[1] = 0;
    r[2] = 0;
    r[3] = 0;
    r[4] = 0;
    r[0] = 0;
    return r;
}

int *parseContentStart(PCtx *c, int *src) {
    PDocDesc desc;
    int *r;
    int n;
    unsigned char *tmp;
    unsigned char *p;
    unsigned char *q;
    int i;
    int len;
    void *buf;

    desc = D_00137DEC;
    r = MEM_malloc(0, 0x14);
    r[1] = 0;
    r[2] = 0;
    r[3] = 0;
    r[4] = 0;
    r[0] = 0;
    c->x00[4] = src[9];
    c->x00[5] = src[13];
    DOMAPI_Initialize();
    CF(c, 0x114) = Util_DOMAPI_NewHTMLDOMImplementation();
    CF(c, 0x118) = Util_HTMLDOMImplementation_createHTMLDocument(CF(c, 0x114), 0);
    HST_setDomObject(HST_searchSessionIDHistoryNode(c->x00[4]), CF(c, 0x118));
    Node_setSid(CF(c, 0x118), c->x00[4]);
    parseJSDocumentSet(c);
    CF(c, 0x11C) = Util_HTMLDocument_getBody(CF(c, 0x118));
    DOMAPI_AddDocument(&desc, CF(c, 0x118));
    if (src[6] == 0)
        return r;
    parseCheckEncodeType(c, src);
    HST_setCharSet(HST_searchSessionIDHistoryNode(c->x00[4]), c->x00[2]);
    n = parseCheckLastTag(c, (unsigned char *)src[7], src[6], c->x00[2]);
    if (n == 0) {
        CF(c, 0x30) = src[6];
        if (CF(c, 0x30) > 0) {
            CF(c, 0x2C) = MEM_malloc(0, CF(c, 0x30));
            memcpy(CF(c, 0x2C), (void *)src[7], CF(c, 0x30));
        } else
            CF(c, 0x2C) = 0;
        return r;
    }
    tmp = MEM_malloc(0, n);
    p = (unsigned char *)src[7];
    q = tmp;
    for (i = 0; i < n; i++) {
        if (*p != 0)
            *q++ = *p;
        p++;
    }
    len = i;
    CF(c, 0x30) = src[6] - n;
    if (CF(c, 0x30) > 0) {
        CF(c, 0x2C) = MEM_malloc(0, CF(c, 0x30));
        memcpy(CF(c, 0x2C), (char *)src[7] + n, CF(c, 0x30));
    }
    buf = MEM_malloc(0, len * 2 + 2);
    parseDataInputBuf(c, buf, parseConvertEncode(buf, tmp, len, c->x00[2]));
    MEM_free(0, tmp);
    MEM_free(0, buf);
    parseDocument(c);
    if (M2C_FIELD(c, signed char *, 0x12C) == 4) {
        if (CF(c, 0x140) == 0xD)
            r[0] = 0;
        else {
            r[2] = ((int *)CF(c, 0x130))[2];
            r[1] = ((int *)CF(c, 0x130))[1];
            r[0] = 1;
            if (CF(c, 0x130) != 0) {
                MEM_free(0, CF(c, 0x130));
                CF(c, 0x130) = 0;
            }
        }
    }
    if (M2C_FIELD(c, signed char *, 0x12C) == 11)
        r[0] = 2;
    if (CF(c, 0x154) == 0xC)
        r[0] = 3;
    return r;
}

int *parseContentContinue(PCtx *c, int *src) {
    int *r;
    unsigned char *buf;
    int len;
    int n;
    unsigned char *tmp;
    unsigned char *p;
    unsigned char *q;
    int i;
    int cnt;
    void *out;

    r = MEM_malloc(0, 0x14);
    r[1] = 0;
    r[2] = 0;
    r[3] = 0;
    r[4] = 0;
    r[0] = 0;
    if (src[6] != 0) {
        buf = MEM_malloc(0, src[6] + CF(c, 0x30));
        len = src[6] + CF(c, 0x30);
        if (CF(c, 0x2C) != 0) {
            memcpy(buf, (void *)CF(c, 0x2C), CF(c, 0x30));
            MEM_free(0, CF(c, 0x2C));
            CF(c, 0x2C) = 0;
        }
        memcpy(buf + CF(c, 0x30), (void *)src[7], src[6]);
        if (CF(c, 0x140) == 0xD) {
            if (parseWellFormedScriptMB(buf, len) == 2) {
                parseBackTag(c);
                CF(c, 0x140) = 10;
            } else {
                CF(c, 0x2C) = (int)buf;
                CF(c, 0x30) = len;
                return r;
            }
        }
        n = parseCheckLastTag(c, buf, len, c->x00[2]);
        if (n == 0) {
            CF(c, 0x30) = len;
            if (len > 0) {
                CF(c, 0x2C) = (int)buf;
                return r;
            }
            CF(c, 0x2C) = 0;
            MEM_free(0, buf);
            return r;
        }
        tmp = MEM_malloc(0, n);
        p = buf;
        q = tmp;
        for (i = 0; i < n; i++) {
            if (*p != 0)
                *q++ = *p;
            p++;
        }
        cnt = i;
        CF(c, 0x30) = len - n;
        if (CF(c, 0x30) > 0) {
            CF(c, 0x2C) = MEM_malloc(0, CF(c, 0x30));
            memcpy(CF(c, 0x2C), buf + n, CF(c, 0x30));
        }
        out = MEM_malloc(0, cnt * 4);
        parseDataInputBuf(c, out, parseConvertEncode(out, tmp, cnt, c->x00[2]));
        MEM_free(0, tmp);
        MEM_free(0, out);
        MEM_free(0, buf);
    }
    if (c == NULL)
        return r;
    c->x44[2] = 1;
    M2C_FIELD(c, signed char *, 0x12C) = 3;
    CF(c, 0x154) = 8;
    if (CF(c, 0x144) != 0 && CF(c, 0x148) != 0)
        parseInsertDocWriteBuffer(c);
    parseDocument(c);
    if (M2C_FIELD(c, signed char *, 0x12C) == 4) {
        if (CF(c, 0x140) == 0xD)
            r[0] = 0;
        else {
            r[2] = ((int *)CF(c, 0x130))[2];
            r[1] = ((int *)CF(c, 0x130))[1];
            r[0] = 1;
            if (CF(c, 0x130) != 0) {
                MEM_free(0, CF(c, 0x130));
                CF(c, 0x130) = 0;
            }
        }
    }
    if (M2C_FIELD(c, signed char *, 0x12C) == 11)
        r[0] = 2;
    if (CF(c, 0x154) == 0xC)
        r[0] = 3;
    return r;
}

int *parseContentContinueJS(PCtx *c, int *src) {
    int *r;
    int len;
    char *buf;
    char *nb;
    int half;
    int mode;
    PCtx *sub;

    r = MEM_malloc(0, 0x14);
    r[1] = 0;
    r[2] = 0;
    r[3] = 0;
    r[4] = 0;
    r[0] = 0;
    if (src[6] == 0 && src[14] == 0) {
        return r;
    }
    len = src[6];
    buf = NULL;
    if (len > 0) {
        buf = MEM_malloc(0, len);
        memcpy(buf, (void *)src[7], len);
    }
    if (CF(c, 0x148) != 0) {
        nb = MEM_malloc(0, len + CF(c, 0x148));
        memcpy(nb, (void *)CF(c, 0x144), CF(c, 0x148));
        if (len > 0) {
            memcpy(nb + CF(c, 0x148), buf, len);
        }
        if (buf != NULL) {
            MEM_free(0, buf);
        }
        buf = nb;
        len += CF(c, 0x148);
        MEM_free(0, CF(c, 0x144));
        CF(c, 0x144) = 0;
        CF(c, 0x148) = 0;
    }
    half = len / 2;
    if (parseWellFormedTag(buf, half) > 0 && (mode = src[14]) == 1) {
        CF(c, 0x140) = 10;
        c->x44[2] = mode;
        M2C_FIELD(c, signed char *, 0x12C) = 3;
        CF(c, 0x154) = 8;
        sub = parseNewCtxt();
        parseCtxtDataCopy(sub, c);
        parseDataInputBuf(sub, buf, half);
        parseDocument(sub);
        parseCtxtDataCopy(c, sub);
        parseFreeCtxt(sub);
        if (M2C_FIELD(c, signed char *, 0x12C) == 4) {
            r[2] = ((int *)CF(c, 0x130))[2];
            r[1] = ((int *)CF(c, 0x130))[1];
            r[0] = mode;
            if (CF(c, 0x130) != 0) {
                MEM_free(0, CF(c, 0x130));
                CF(c, 0x130) = 0;
            }
        }
        if (M2C_FIELD(c, signed char *, 0x12C) == 11) {
            r[0] = 2;
        }
        if (CF(c, 0x140) == 0xD) {
            r[0] = 0;
        }
        if (CF(c, 0x154) == 0xC) {
            r[0] = 3;
        }
        MEM_free(0, buf);
        return r;
    }
    CF(c, 0x144) = (int)buf;
    CF(c, 0x148) = len;
    return r;
}

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
