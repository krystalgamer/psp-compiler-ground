/* cflags: -O1 */
#include "common.h"
#include "parse_str.h"
#include "m2c_macros.h"
PMb parseAttrName(PCtx *c);
PMb parseAttrValue(PCtx *c);
PDStr Attr_getValue(void *attr);
PTag parseTagNameCmp(PChar *name);
#define CF(c, o) M2C_FIELD(c, int *, o)
PDStr Attr_getName(void *attr);
extern char D_00137EB4[];
extern char D_00137EE4[];
PDStr Node_getNodeName(int node);
int DocumentSet(int, void *, M2C_UNK);              /* extern */
void *HST_searchSessionIDHistoryNode(int);          /* extern */
int Node_getJSObj(int);                             /* extern */
M2C_UNK Node_setJSObj(int, int);                    /* extern */
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK MEM_free(M2C_UNK, M2C_UNK *);               /* extern */
int MEM_realloc(M2C_UNK, int, int);                 /* extern */

M2C_UNK parseHST_deleteHistoryNode(M2C_UNK, M2C_UNK); /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

void parseReleaseResource(void) {
    parseDeleteMultiBuffer();
    parseHST_deleteHistoryNode(0, 0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseDocumentTEXT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseHTMLTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseCharEntity);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseCheckTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseElementName);

void parseElement(PCtx *c) {
    int empty;

    empty = 0;
    parseElementName(c);
    while (!((c->buf->cur[0] == '/' && c->buf->cur[1] == '>') || c->buf->cur[0] == '>' || (c->buf->count == c->buf->x04 - 1 && c->x1C[0] == c->x1C[1] - 1) || c->x44[2] == 2)) {
        parseAttribute(c);
    }
    if (c->buf->cur[0] == '/' && c->buf->cur[1] == '>') {
        empty = 1;
        if (parseNextChar(c) == 1) {
            return;
        }
    }
    parseTagTransact(1, c, 0, 0, 0, 0);
    if (empty) {
        parseTagTransact(4, c, 0, 0, 0, 0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseAttribute);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseAttrName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseAttrValue);

void parseComment(PCtx *c) {
    if (parseWellFormedCommentWC(c) != 1) {
        c->x44[2] = 2;
        return;
    }
    for (;;) {
        if (c->buf->cur[0] == '-' && c->buf->cur[1] == '-' && c->buf->cur[2] == '>') {
            break;
        }
        if (parseNextChar(c) == 1) {
            return;
        }
    }
    parseSkipChar(c, 2);
}

void parseInvalidComment(PCtx *c) {
    for (;;) {
        if (*c->buf->cur == '>') {
            break;
        }
        if (parseNextChar(c) == 1) {
            return;
        }
    }
    parseSkipChar(c, 1);
}

void parseMarkedSection(PCtx *c) {
    for (;;) {
        if (c->buf->cur[0] == ']' && c->buf->cur[1] == '>') {
            break;
        }
        if (parseNextChar(c) == 1) {
            return;
        }
    }
    parseSkipChar(c, 1);
}

void parseDocType(PCtx *c) {
    do {
        if (*c->buf->cur == '>') {
            return;
        }
    } while (parseNextChar(c) != 1);
}

void parseProcessingInstruction(PCtx *c) {
    for (;;) {
        if (*c->buf->cur == '>') {
            break;
        }
        if (parseNextChar(c) == 1) {
            return;
        }
    }
    parseSkipChar(c, 1);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseEndTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseContents);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseContentsNoParse);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", ps_prepareText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseTitle);

int parseWellFormedCommentWC(PCtx *c) {
    int found;
    PChar *cur;
    int i;
    int n;
    int idx;
    int last;

    found = 0;
    cur = c->buf->cur;
    i = 0;
    n = c->buf->x04 - c->buf->count - 3;
    last = c->x1C[1];
    idx = c->x1C[0];
    for (;;) {
            again:
        if (cur[i] == '-' && cur[i + 1] == '-' && cur[i + 2] == '>') {
            found = 1;
        }
        if (i == n || n < 0) {
            goto out;
        }
        i++;
        goto again;
    out:
        if (idx == last - 1) {
            break;
        }
        idx++;
        i = 0;
        n = ((PBuf **)c->x1C[3])[idx]->x04 - 8;
        cur = ((PBuf **)c->x1C[3])[idx]->cur;
    }
    return found;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseWellFormedScriptWC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseWellFormedScriptMB);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseWellFormedStyleWC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseWellFormedStyleMB);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseWellFormedTagWC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", backToTextareaTag);

void parseTextarea(PCtx *c, PChar *str, int len) {
    PDStr *d;
    int el;
    unsigned int i;

    if (parseWellFormedTagWC(c, str, len) == 0) {
        c->x44[2] = 2;
        parseTagCountMinus(c, *(PTag *)((char *)c + 0x34));
        backToTextareaTag(c);
        return;
    }
    d = parseMBtoDScopy(str, len);
    if (d != NULL && d->len != 0) {
        for (i = 0; i < d->len; i++) {
            d->data[i] = (d->data[i] >= 'a' && d->data[i] <= 'z') ? d->data[i] - 0x20 : d->data[i];
        }
    }
    el = Document_createElement(CF(c, 0x118), d);
    MEM_free(0, d->data);
    d->data = NULL;
    MEM_free(0, d);
    if (el != 0) {
        Node_appendChild(CF(c, 0x11C), el);
        CF(c, 0x11C) = el;
    }
    parseAlertMessage(c);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseScript);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137E3C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137E48);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseScriptAttribute);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", checkFileStrage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseScriptExternal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseNoScript);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137E60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137E64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137E70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137E80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137E8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137E94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137E9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137EA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137EB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137EBC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137EC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137ED0);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseLink);

void parseExtStyleSheet(int sid, void *text) {
    void *node;
    void *ss;
    void *r;

    node = HST_searchSessionIDHistoryNode(sid);
    ss = HST_getStyleSheet(node);
        if (ss == NULL) {
        HST_setStyleSheet(node, CSS2_Parse(2, text, 0, 0, 0, 0, 0, 0));
    } else {
        HST_setStyleSheet(node, CSS2_Parse(2, text, 0, ss, 0, 0, 0, 0));
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", backToStyleTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseStyle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseStyleAttribute);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137EE4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137EF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137EF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137F04);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseBase);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseForm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseFrame);

int parseJSEventHandler(PDStr *s) {
    if ((unsigned)s->len >= 2 && (s->data[0] == 'O' || s->data[0] == 'o') && (s->data[1] == 'N' || s->data[1] == 'n')) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseJSCreateEventArray);

int parseJSDestroyEventArray(void **ev) {
    while (ev[0] != NULL) {
        MEM_free(0, ev[0]);
        MEM_free(0, ev[1]);
        ev += 2;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void parseJSDocumentSet(void *arg0) {
    int temp_v0_2;
    int temp_v0_3;
    int var_a0;
    int var_s3;
    void *temp_v0;

    var_s3 = 0;
    temp_v0 = HST_searchSessionIDHistoryNode(M2C_FIELD(arg0, int *, 0x10));
    temp_v0_2 = HST_getParentHistoryNode(temp_v0);
    if (temp_v0_2 != 0) {
        var_a0 = 0;
        if (HST_getDomObject((void *) temp_v0_2) != 0) {
            var_s3 = Node_getJSObj(HST_getDomObject((void *) temp_v0_2));
            goto block_3;
        }
    } else {
block_3:
        var_a0 = var_s3;
    }
    temp_v0_3 = DocumentSet(var_a0, temp_v0, 0);
    M2C_FIELD(arg0, int *, 0x158) = temp_v0_3;
    Node_setJSObj(M2C_FIELD(arg0, int *, 0x118), temp_v0_3);
}

void parseJSAnchorSet(PCtx *c) {
    void *ev[32];
    int obj;

    parseJSCreateEventArray(Node_getAttributes(M2C_FIELD(c, int *, 0x11C)), ev);
    obj = ASet(M2C_FIELD(c, int *, 0x158), M2C_FIELD(c, int *, 0x11C), ev);
    parseJSDestroyEventArray(ev);
    Node_setJSObj(M2C_FIELD(c, int *, 0x11C), obj);
}

void parseJSBodySet(PCtx *c) {
    void *ev[32];
    PDStr name;
    int node;

    name = Node_getNodeName(M2C_FIELD(c, int *, 0x11C));
        if (parseDStrEqual("frameset", &name)) {
        node = Node_getAttributes(M2C_FIELD(c, int *, 0x11C));
    } else {
        node = Node_getAttributes(Util_HTMLDocument_getBody(M2C_FIELD(c, int *, 0x118)));
    }
    parseJSCreateEventArray(node, ev);
    EventHandlerSet(M2C_FIELD(c, int *, 0x158), ev);
    parseJSDestroyEventArray(ev);
}

void parseJSButtonSet(PCtx *c) {
    PDStr an;
    void *ev[32];
    int obj;
    int type;
    int map;
    int n;
    int i;
    void *attr;

    obj = 0;
    type = 0;
    if (CF(c, 0x15C) == 0) {
        return;
    }
    map = Node_getAttributes(CF(c, 0x11C));
    parseJSCreateEventArray(map, ev);
    n = NamedNodeMap_getLength(map);
    for (i = 0; i < n; i++) {
        attr = NamedNodeMap_item(map, i);
        an = Attr_getName(attr);
        if (parseDStrEqual(D_00137EB4, &an) == 1) {
            an = Attr_getValue(attr);
            type = parseJSInputTypeCmp(&an);
            break;
        }
    }
    switch (type) {
    case 1:
        obj = ButtonSet(CF(c, 0x15C), CF(c, 0x11C), ev);
        break;
    case 5:
        obj = ResetSet(CF(c, 0x15C), CF(c, 0x11C), ev);
        break;
    default:
        obj = SubmitSet(CF(c, 0x15C), CF(c, 0x11C), ev);
        break;
    }
    parseJSDestroyEventArray(ev);
    Node_setJSObj(CF(c, 0x11C), obj);
}

void parseJSFormSet(PCtx *c) {
    void *ev[32];
    int obj;

    parseJSCreateEventArray(Node_getAttributes(M2C_FIELD(c, int *, 0x11C)), ev);
    obj = FormSet(M2C_FIELD(c, int *, 0x158), M2C_FIELD(c, int *, 0x11C), ev);
    parseJSDestroyEventArray(ev);
    M2C_FIELD(c, int *, 0x15C) = obj;
    Node_setJSObj(M2C_FIELD(c, int *, 0x11C), obj);
}

void parseJSImgSet(PCtx *c) {
    void *ev[32];
    int obj;

    parseJSCreateEventArray(Node_getAttributes(M2C_FIELD(c, int *, 0x11C)), ev);
    obj = ImageSet(M2C_FIELD(c, int *, 0x158), M2C_FIELD(c, int *, 0x11C), ev);
    parseJSDestroyEventArray(ev);
    Node_setJSObj(M2C_FIELD(c, int *, 0x11C), obj);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseJSInputTypeCmp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseJSInputSet);

void parseJSSelectSet(PCtx *c) {
    void *ev[32];
    int obj;

    if (M2C_FIELD(c, int *, 0x15C) == 0) {
        return;
    }
    parseJSCreateEventArray(Node_getAttributes(M2C_FIELD(c, int *, 0x11C)), ev);
    obj = SelectSet(M2C_FIELD(c, int *, 0x15C), M2C_FIELD(c, int *, 0x11C), ev);
    parseJSDestroyEventArray(ev);
    M2C_FIELD(c, int *, 0x160) = obj;
    Node_setJSObj(M2C_FIELD(c, int *, 0x11C), obj);
}

void parseJSOptionSet(PCtx *c) {
    void *ev[32];
    int obj;

    if (M2C_FIELD(c, int *, 0x160) == 0) {
        return;
    }
    parseJSCreateEventArray(Node_getAttributes(M2C_FIELD(c, int *, 0x11C)), ev);
    obj = OptionSet(M2C_FIELD(c, int *, 0x160), M2C_FIELD(c, int *, 0x11C), ev);
    parseJSDestroyEventArray(ev);
    Node_setJSObj(M2C_FIELD(c, int *, 0x11C), obj);
}

void parseJSTextareaSet(PCtx *c) {
    void *ev[32];
    int obj;

    if (M2C_FIELD(c, int *, 0x15C) == 0) {
        return;
    }
    parseJSCreateEventArray(Node_getAttributes(M2C_FIELD(c, int *, 0x11C)), ev);
    obj = TextAreaSet(M2C_FIELD(c, int *, 0x15C), M2C_FIELD(c, int *, 0x11C), ev);
    parseJSDestroyEventArray(ev);
    Node_setJSObj(M2C_FIELD(c, int *, 0x11C), obj);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseInvalidTag);

int parseIsSetAttribute(int node, PDStr *name) {
    int map;
    int n;
    int i;
    void *attr;
    PDStr an;

    if (node == 0 || name == NULL) {
        return 0;
    }
    i = 0;
    map = Node_getAttributes(node);
    n = NamedNodeMap_getLength(map);
    for (; i < n; i++) {
        attr = NamedNodeMap_item(map, i);
        an = Attr_getName(attr);
        if (an.len == name->len && UCS_strncasecmp(an.data, name->data, an.len) == 0 && Attr_getSpecified(attr) != 0) {
            return 0;
        }
    }
    return 1;
}

void parseElementSetAttribute(int elem, PDStr *name, void *val) {
    unsigned int i;

    if (elem == 0 || name == NULL) {
        return;
    }
    if (parseIsSetAttribute(elem, name) == 0) {
        return;
    }
    if (name != NULL && name->len != 0) {
        for (i = 0; i < name->len; i++) {
            name->data[i] = (name->data[i] >= 'a' && name->data[i] <= 'z') ? name->data[i] - 0x20 : name->data[i];
        }
    }
    Element_setAttribute(elem, name, val);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void *parseNewCtxt(void) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x170);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 2;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD(temp_v0, int *, 0x10) = 0;
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
    M2C_FIELD(temp_v0, int *, 0x18) = 0;
    M2C_FIELD(temp_v0, int *, 0x1C) = 0;
    M2C_FIELD(temp_v0, int *, 0x20) = 0;
    M2C_FIELD(temp_v0, int *, 0x24) = 5;
    M2C_FIELD(temp_v0, void **, 0x28) = MEM_malloc(0, 0x14);
    M2C_FIELD(temp_v0, int *, 0x2C) = 0;
    M2C_FIELD(temp_v0, int *, 0x30) = 0;
    M2C_FIELD(temp_v0, int *, 0x34) = 0;
    M2C_FIELD(temp_v0, signed char *, 0x38) = 0;
    M2C_FIELD(temp_v0, signed char *, 0x39) = 0;
    M2C_FIELD(temp_v0, signed char *, 0x3A) = 0;
    M2C_FIELD(temp_v0, signed char *, 0x3B) = 0;
    M2C_FIELD(temp_v0, signed char *, 0x3C) = 0;
    M2C_FIELD(temp_v0, signed char *, 0x3D) = 0;
    M2C_FIELD(temp_v0, short *, 0x3E) = -1;
    M2C_FIELD(temp_v0, int *, 0x40) = 0;
    M2C_FIELD(temp_v0, int *, 0x44) = 0;
    M2C_FIELD(temp_v0, int *, 0x48) = 0;
    M2C_FIELD(temp_v0, int *, 0x4C) = 1;
    M2C_FIELD(temp_v0, int *, 0x50) = 0;
    memset(temp_v0 + 0x54, 0, 0xBEU);
    M2C_FIELD(temp_v0, int *, 0x120) = 0;
    M2C_FIELD(temp_v0, int *, 0x124) = 0;
    M2C_FIELD(temp_v0, signed char *, 0x128) = 0x61;
    M2C_FIELD(temp_v0, signed char *, 0x12C) = 3;
    M2C_FIELD(temp_v0, int *, 0x130) = 0;
    M2C_FIELD(temp_v0, int *, 0x134) = 2;
    M2C_FIELD(temp_v0, signed char *, 0x138) = 0x30;
    M2C_FIELD(temp_v0, int *, 0x13C) = 0;
    M2C_FIELD(temp_v0, int *, 0x140) = 0xA;
    M2C_FIELD(temp_v0, int *, 0x144) = 0;
    M2C_FIELD(temp_v0, int *, 0x148) = 0;
    M2C_FIELD(temp_v0, int *, 0x150) = 8;
    M2C_FIELD(temp_v0, int *, 0x154) = 8;
    M2C_FIELD(temp_v0, int *, 0x158) = 0;
    M2C_FIELD(temp_v0, int *, 0x15C) = 0;
    M2C_FIELD(temp_v0, int *, 0x160) = 0;
    M2C_FIELD(temp_v0, int *, 0x164) = 0;
    M2C_FIELD(temp_v0, int *, 0x168) = 1;
    M2C_FIELD(temp_v0, signed char *, 0x16C) = 0;
    return temp_v0;
}

void parseFreeCtxt(PCtx *c) {
    int i;

    if (c == NULL) {
        return;
    }
    for (i = 0; i < c->x1C[1]; i++) {
        MEM_free(0, M2C_FIELD(((PBuf **)c->x1C[3])[i], void **, 0x10));
        MEM_free(0, ((PBuf **)c->x1C[3])[i]);
    }
    if (c->x1C[3] != 0) {
        MEM_free(0, c->x1C[3]);
    }
    if (c->x00[1] != 0) {
        MEM_free(0, c->x00[1]);
    }
    if (c->x1C[4] != 0) {
        MEM_free(0, c->x1C[4]);
    }
    if (M2C_FIELD(c, int *, 0x144) != 0) {
        MEM_free(0, M2C_FIELD(c, int *, 0x144));
    }
    MEM_free(0, c);
}

void parseInitCtxt(PCtx *c) {
    c->x00[0] = 0;
    c->x00[1] = 0;
    c->x00[2] = 2;
    c->x00[3] = 0;
    c->buf = NULL;
    c->x1C[1] = 0;
    c->buf->cur = NULL;
    c->buf->x04 = 0;
    c->buf->x08 = 0;
    c->buf->count = 0;
    c->pos = 0;
    c->x44[0] = 0;
    c->x44[1] = 0;
    c->x44[2] = 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parser", parseDataInputBuf);

#ifndef NULL
#define NULL ((void *)0)
#endif

void *parseNewMultiCtxt(void) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0xC);
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 5;
    M2C_FIELD(temp_v0, void **, 0) = MEM_malloc(0, 0x14);
    return temp_v0;
}

int parseRegistBuffer(int sid, void *ctx, PCtxList *l) {
    if (l->n >= l->cap) {
        l->cap += 5;
        l->items = (void **)MEM_realloc(0, (int)l->items, l->cap * 4);
    }
    l->items[l->n] = ctx;
    M2C_FIELD(l->items[l->n], int *, 0x10) = sid;
    l->n++;
    return 0;
}

void *parseSearchSessionID(int sid, void ***list) {
    void *found;
    int i;

    found = NULL;
    for (i = 0; i < ((int *)list)[1]; i++) {
        if (sid == M2C_FIELD((*list)[i], int *, 0x10)) {
            found = (*list)[i];
        }
    }
    return found;
}

int parseDeleteMultiBuffer(PCtxList *l) {
    int i;

    if (l == NULL) {
        return 0;
    }
    for (i = 0; i < l->n; i++) {
        parseFreeCtxt(l->items[i]);
        l->items[i] = NULL;
    }
    MEM_free(0, l->items);
    l->items = NULL;
    l->n = 0;
    MEM_free(0, l);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *parseCreateBuffer(void) {
    void *temp_s0;

    temp_s0 = MEM_malloc(0, 0xC);
    M2C_FIELD(temp_s0, void **, 0) = MEM_malloc(0, 0x800);
    M2C_FIELD(temp_s0, int *, 4) = 0x400;
    M2C_FIELD(temp_s0, int *, 8) = 0;
    return temp_s0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void parseDeleteBuffer(M2C_UNK *arg0) {
    M2C_UNK *temp_a1;

    if (arg0 != NULL) {
        temp_a1 = *arg0;
        if (temp_a1 != NULL) {
            MEM_free(0, temp_a1);
        }
        MEM_free(0, arg0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void parseGrowBuffer(void *arg0) {
    int temp_a2;

    temp_a2 = M2C_FIELD(arg0, int *, 4) + 0x400;
    M2C_FIELD(arg0, int *, 4) = temp_a2;
    M2C_FIELD(arg0, int *, 0) = MEM_realloc(0, M2C_FIELD(arg0, int *, 0), temp_a2 * 2);
}

void parseSetBuffer(PStrBuf *b, PChar ch) {
    if (b->len >= b->cap) {
        parseGrowBuffer(b);
    }
    b->data[b->len] = ch;
    b->len++;
}

void parseAdjustBuffer(PStrBuf *b) {
    b->data = (PChar *)MEM_realloc(0, (int)b->data, b->len * 2 + 2);
    b->data[b->len] = 0;
}

void parseCtxtDataCopy(PCtx *d, PCtx *s) {
    CF(d, 0x0) = CF(s, 0x0);
    CF(d, 0x4) = CF(s, 0x4);
    CF(d, 0x8) = CF(s, 0x8);
    CF(d, 0xC) = CF(s, 0xC);
    CF(d, 0x10) = CF(s, 0x10);
    CF(d, 0x34) = CF(s, 0x34);
    CF(d, 0x38) = CF(s, 0x38);
    CF(d, 0x3C) = CF(s, 0x3C);
    CF(d, 0x48) = CF(s, 0x48);
    CF(d, 0x50) = CF(s, 0x50);
    d->tags = s->tags;
    CF(d, 0x114) = CF(s, 0x114);
    CF(d, 0x118) = CF(s, 0x118);
    CF(d, 0x11C) = CF(s, 0x11C);
    CF(d, 0x124) = CF(s, 0x124);
    CF(d, 0x120) = CF(s, 0x120);
    CF(d, 0x4C) = CF(s, 0x4C);
    M2C_FIELD(d, unsigned char *, 0x12C) = M2C_FIELD(s, unsigned char *, 0x12C);
    CF(d, 0x140) = CF(s, 0x140);
    CF(d, 0x130) = CF(s, 0x130);
    CF(d, 0x150) = CF(s, 0x150);
    CF(d, 0x154) = CF(s, 0x154);
    CF(d, 0x158) = CF(s, 0x158);
    CF(d, 0x15C) = CF(s, 0x15C);
    CF(d, 0x160) = CF(s, 0x160);
}

void parseInsertDocWriteBuffer(PCtx *c) {
    int total;
    int ins;
    int pos;
    int newlen;
    PChar *nb;

    total = c->buf->x04;
    ins = CF(c, 0x148) / 2;
    pos = c->buf->count;
    newlen = total + ins;
    nb = MEM_malloc(0, newlen * 2);
    memcpy(nb, c->buf->base, pos * 2);
    memcpy(nb + pos, (void *)CF(c, 0x144), ins * 2);
    memcpy(nb + pos + ins, c->buf->cur, (total - pos) * 2);
    MEM_free(0, c->buf->base);
    c->buf->cur = NULL;
    c->buf->base = NULL;
    MEM_free(0, CF(c, 0x144));
    CF(c, 0x144) = 0;
    CF(c, 0x148) = 0;
    c->buf->cur = nb;
    c->buf->cur += pos;
    c->buf->base = nb;
    c->buf->x04 = newlen;
    c->x44[0] += ins;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137FA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137FAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137FB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137FBC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137FC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137FCC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137FD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137FD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137FE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137FEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137FF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00137FF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138000);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138008);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013800C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138014);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013801C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138024);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013802C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138034);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138038);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138044);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138048);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013804C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138050);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138054);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138058);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013805C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138060);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138064);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138070);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138078);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138080);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138088);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138094);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138098);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013809C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001380FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138104);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138108);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138110);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138118);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138124);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138130);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138138);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013813C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138148);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138150);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138154);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013815C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138160);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138164);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138168);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138170);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138178);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138180);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138188);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138190);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138198);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001381FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138200);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138208);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138210);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138218);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138220);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138228);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138230);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138238);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138240);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138248);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138250);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138258);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138260);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138268);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138270);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138274);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013827C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138284);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138288);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138290);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138298);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001382F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138300);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138304);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013830C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138314);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013831C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138324);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013832C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138334);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013833C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138344);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013834C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138350);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138354);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013835C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138360);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138364);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013836C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138374);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013837C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138380);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138388);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138390);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138398);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001383FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138404);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138408);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013840C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138410);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138418);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138420);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138428);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138430);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138438);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138440);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138448);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138450);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138454);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013845C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138464);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013846C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138470);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138478);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138480);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138488);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138490);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138498);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013849C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001384A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001384AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001384B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001384BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001384C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001384C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001384D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001384D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001384E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001384E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001384F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001384F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138500);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138508);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138510);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138518);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013851C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138520);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138528);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138530);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138538);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138540);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138548);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138550);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138558);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138560);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138568);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138570);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138574);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138578);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138580);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138588);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138590);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138598);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001385FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138604);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013860C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138614);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013861C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138624);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013862C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138630);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138638);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138640);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138644);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138648);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138650);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138658);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013865C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138664);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013866C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138674);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013867C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138684);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138688);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138690);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138698);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001386F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138700);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138708);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013870C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138714);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013871C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138724);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013872C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138734);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013873C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138744);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013874C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138754);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013875C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138760);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138764);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138768);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138770);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138778);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138780);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138788);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138790);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138794);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013879C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001387F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138800);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138808);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138810);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138818);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138820);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138824);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013882C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138834);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138838);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138840);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138848);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013884C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138854);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013885C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138864);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013886C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138874);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138878);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138880);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138888);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138894);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013889C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001388A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001388AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001388B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001388BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001388C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001388CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001388D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001388DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001388E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001388E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001388F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_001388F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138900);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138908);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013890C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138914);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138918);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138920);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_00138928);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parser", D_0013892C);
