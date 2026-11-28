/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
#include "nflayout.h"

BOX *createBox(void *node, int type);
void linkBox(BOX *b, BOX *parent, BOX *prev);
void initTextContent(BOX *b, void *node, int f);
void initBoxProperty(BOX *b);
void initTextBoxSize(BOX *b);
char *strcpy(char *d, const char *s);
typedef struct { int size; unsigned int len; unsigned short *str; } PTDStr;
int CharacterData_getData(PTDStr *s, void *node);
void *Node_getFirstChild(void *node);
int ucs2ToUtf8(char *d, unsigned short *s, int n);
BOX *html_BR(void *node, BOX *parent, BOX *prev);
void freeBox(BOX *b, int f);
BOX *normal_text(void *node, BOX *parent, BOX *prev) {
    BOX *src;
    BOX *b;

    src = parent;
    if (parent->display != 1) {
        for (src = prev; src != NULL; src = src->prev) {
            if (src->content == 9 && src->html != 0x66)
                break;
        }
    }
    b = createBox(node, src == NULL);
    if (b == NULL)
        return NULL;
    linkBox(b, parent, prev);
    b->display = 1;
    b->html = 0x65;
    initTextContent(b, node, 0);
    if (src != NULL) {
        b->style = src->style;
    } else {
        initBoxProperty(b);
        b->style->unk30 = 0;
        M2C_FIELD(b->style, s16 *, 0x32) = 0;
        b->style->unk34 = 0;
        M2C_FIELD(b->style, s16 *, 0x36) = 0;
    }
    M2C_FIELD(b->geom, u8 *, 0x10) = M2C_FIELD(b->style, u8 *, 0x68);
    initTextBoxSize(b);
    return b;
}

unsigned char *normalizeText(unsigned char *s) {
    unsigned char *p;
    unsigned char *d;
    unsigned char *buf;
    int tabs = 0;

    for (p = s; *p != 0; p++) {
        if (*p == '\t') {
            tabs++;
        }
    }
    buf = MEM_malloc(0, (p - s) + tabs * 7 + 1);
    if (buf == NULL) {
        return s;
    }

    for (p = s, d = buf; *p != 0; p++) {
        if (*p == '\t') {
            strcpy((char *)d, "        ");
            d += 8;
        } else if (*p >= 0x20) {
            *d++ = *p;
        }
    }
    *d = 0;
    MEM_free(0, s);
    return buf;
}

BOX *pre_text(void *node, BOX *parent, BOX *prev) {
    PTDStr data;
    BOX *first;
    BOX *box = NULL;
    BOX *src;
    BOX *last;
    BOX *next;
    unsigned short *p;
    unsigned short *start;
    int n;
    char *buf;

    CharacterData_getData(&data, node);
    if (parent->html == 0x48 && Node_getFirstChild(M2C_FIELD(parent, void **, 0x28)) == node) {
        if (*data.str == '\r') {
            data.str++;
            data.len--;
        }
        if (*data.str == '\n') {
            data.str++;
            data.len--;
        }
    }
    start = data.str;
    p = start;
    last = prev;
    n = 0;
    first = NULL;
    src = parent;
    if (parent->display != 1) {
        for (src = prev; src != NULL; src = src->prev) {
            if (src->content == 9 && src->html != 0x66)
                break;
        }
    }
    while ((unsigned int)(p - data.str) < data.len) {
        if ((*p == '\r') | (*p == '\n')) {
            if (n > 0) {
                buf = MEM_malloc(0, n * 3 + 1);
                if (buf == NULL) {
                    goto fail;
                }
                buf[ucs2ToUtf8(buf, start, n)] = 0;
                box = createBox(node, src == NULL);
                if (box == NULL) {
                    goto freebuf;
                }
                if (first == NULL) {
                    first = box;
                }
                linkBox(box, parent, last);
                box->display = 1;
                box->html = 0x65;
                initTextContent(box, node, (int)normalizeText((unsigned char *)buf));
                if (src != NULL) {
                    box->style = src->style;
                } else {
                    initBoxProperty(box);
                    box->style->unk30 = 0;
                    M2C_FIELD(box->style, s16 *, 0x32) = 0;
                    box->style->unk34 = 0;
                    M2C_FIELD(box->style, s16 *, 0x36) = 0;
                    src = box;
                }
                M2C_FIELD(box->geom, u8 *, 0x10) = M2C_FIELD(box->style, u8 *, 0x68);
                initTextBoxSize(box);
                last = box;
            }
            last = html_BR(node, parent, last);
            if (last == NULL) {
                goto fail;
            }
            if (first == NULL) {
                first = last;
            }
            n = 0;
            if (*p == '\r') {
                if (p[1] == '\n') {
                    p += 2;
                } else {
                    p += 1;
                }
            } else {
                p += 1;
            }
            start = p;
        } else {
            n++;
            p++;
        }
    }
    if (n > 0) {
        buf = MEM_malloc(0, n * 3 + 1);
        if (buf == NULL) {
            goto fail;
        }
        buf[ucs2ToUtf8(buf, start, n)] = 0;
        box = createBox(node, src == NULL);
        if (box == NULL) {
            goto freebuf;
        }
        linkBox(box, parent, last);
        box->display = 1;
        box->html = 0x65;
        initTextContent(box, node, (int)normalizeText((unsigned char *)buf));
        if (src != NULL) {
            box->style = src->style;
        } else {
            initBoxProperty(box);
            box->style->unk30 = 0;
            M2C_FIELD(box->style, s16 *, 0x32) = 0;
            box->style->unk34 = 0;
            M2C_FIELD(box->style, s16 *, 0x36) = 0;
        }
        M2C_FIELD(box->geom, u8 *, 0x10) = M2C_FIELD(box->style, u8 *, 0x68);
        initTextBoxSize(box);
    }
    return box;
freebuf:
    MEM_free(0, buf);
fail:
    if (first == NULL) {
        return NULL;
    }
    for (box = first; box != NULL; box = next) {
        next = box->next;
        freeBox(box, 0);
    }
    if (first->prev == NULL) {
        parent->child = NULL;
    } else {
        first->prev->next = NULL;
    }
    return NULL;
}

BOX *getSpecialBehaviorParent(BOX *box) {
    s16 h;
    while (box != NULL) {
        h = box->html;
        if (h == 0x45 || h == 0x4D || h == 0x58) {
            return box;
        }
        box = box->parent;
    }
    return NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_notag", html_NOTAG);
