/* cflags: -O1 */
#include "common.h"
#include "parse_str.h"
#include "m2c_macros.h"
extern PTag htmlElementTable[];


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseFindValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseFindName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", procMetaTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseFindMetaTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseCheckMetaCharset);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseCheckEncodeType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseSetExtractedAuthData);

PTag parseTagNameCmp(PChar *name) {
    PTag t;
    int i;

    t.x00 = 0;
    t.x04 = 0;
    *(int *)&t.x08 = 0;
    t.id = -1;
    for (i = 0; i < 0x5F; i++) {
        if (parseStrEqual((char *)htmlElementTable[i].x00, name)) {
            return htmlElementTable[i];
        }
    }
    return t;
}

PTag parseDSTagNameCmp(PDStr *name) {
    PTag t;
    int i;

    t.x00 = 0;
    t.x04 = 0;
    *(int *)&t.x08 = 0;
    t.id = -1;
    for (i = 0; i < 0x5F; i++) {
        if (parseDStrEqual((char *)htmlElementTable[i].x00, name)) {
            return htmlElementTable[i];
        }
    }
    return t;
}

int parseTagCountPlus(PCtx *c, PTag t) {
    c->tagCount[t.id]++;
    return 0;
}

int parseTagCountMinus(PCtx *c, PTag t) {
    if (c->tagCount[t.id] != 0) {
        c->tagCount[t.id]--;
        return 0;
    }
    return 1;
}

int parseNextChar(PCtx *c) {
    if (c->buf->count == c->buf->x04 - 1) {
        if (c->x1C[0] >= c->x1C[1] - 1 || c->x44[2] == 2) {
            return 1;
        }
        c->x1C[0]++;
        c->buf = ((PBuf **)c->x1C[3])[c->x1C[0]];
        c->buf->count = 0;
    } else {
        c->buf->cur++;
        c->buf->count++;
    }
    c->pos++;
    return 0;
}

int parseSkipChar(PCtx *c, int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (parseNextChar(c) == 1) {
            return 0;
        }
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int parseNextInput(void) {
    return 0;
}

PChar *parseStrnCpy(PChar *s, int n) {
    PChar *p;

    if (s == NULL || n < 0) {
        return NULL;
    }
    p = MEM_malloc(0, n * 2 + 2);
    memcpy(p, s, n * 2);
    p[n] = 0;
    return p;
}

int parseStrcmp(PChar *a, PChar *b) {
    int d;

    if (a == b) {
        return 0;
    }
    if (a == NULL) {
        return -1;
    }
    if (b == NULL) {
        return 1;
    }
    do {
        d = *a++ - *b;
        if (d != 0) {
            return d;
        }
    } while (*b++ != 0);
    return 0;
}

int parseStrEqual(char *a, PChar *b) {
    if ((void *)a == (void *)b) {
        return 1;
    }
    if (a == NULL) {
        return 0;
    }
    if (b == NULL) {
        return 0;
    }
    do {
        if ((PChar)*a++ != *b) {
            return 0;
        }
    } while (*b++ != 0);
    return 1;
}

int parseStrEqualNoCase(char *a, PChar *b) {
    int ca;
    int cb;

    if ((void *)a == (void *)b) {
        return 1;
    }
    if (a == NULL) {
        return 0;
    }
    if (b == NULL) {
        return 0;
    }
    do {
        if (*a >= 'A' && *a <= 'Z') {
            ca = (PChar)*a + 0x20;
        } else {
            ca = (PChar)*a;
        }
        if (ca != ((*b >= 'A' && *b <= 'Z') ? *b + 0x20 : *b)) {
            return 0;
        }
        a++;
    } while (*b++ != 0);
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseDStrEqual);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseDStrnEqual);

void parseDStrTrace(PDStr *s) {
    int i;

    if (s == NULL || s->data == NULL) {
        return;
    }
    for (i = 0; i < s->len; i++) {
    }
}

PDStr *parseMBtoDScopy(PChar *s, int n) {
    PDStr *d;

    if (s == NULL) {
        return NULL;
    }
    d = MEM_malloc(0, sizeof(PDStr));
    if (d == NULL) {
        return NULL;
    }
    if (n > 0) {
        d->data = MEM_malloc(0, n * 2);
        if (d->data == NULL) {
            MEM_free(0, d);
            return NULL;
        }
        memcpy(d->data, s, n * 2);
        d->len = n;
    } else {
        d->data = NULL;
        d->len = n;
    }
    d->x00 = n;
    return d;
}

PChar *parseDStoMBcopy(PDStr *s) {
    PChar *p;

    if (s->data == NULL) {
        return NULL;
    }
    p = MEM_malloc(0, s->len * 2 + 2);
    if (p == NULL) {
        return NULL;
    }
    memcpy(p, s->data, s->len * 2);
    p[s->len] = 0;
    return p;
}

void parseConvertUTF8toUCS2(char *src, int len, PChar **out, int *outLen) {
    PChar *buf;
    int n;

    if (src == NULL || len < 1) {
        return;
    }
    buf = MEM_malloc(0, (len * 2 + len) * 2 + 2);
    n = utf8ToUcs2(buf, src, len);
    buf = MEM_realloc(0, buf, n * 2 + 2);
    buf[n] = 0;
    *out = buf;
    *outLen = n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseCheckLastTag);

int parseConvertEncode(void *dst, void *src, int n, int enc) {
    int r;

    r = 0;
    switch (enc) {
    case 1:
        r = jisToUcs2(dst, src, n);
        break;
    case 2:
        r = sjisToUcs2(dst, src, n);
        break;
    case 3:
        r = eucToUcs2(dst, src, n);
        break;
    case 5:
        r = utf8ToUcs2(dst, src, n);
        break;
    case -1:
    case 0:
    case 4:
        r = asciiToUcs2(dst, src, n);
        break;
    }
    return r;
}

void parseBackTag(PCtx *c) {
    for (;;) {
        if (*c->buf->cur == '<') {
            break;
        }
        c->buf->cur--;
        c->buf->count--;
        c->pos--;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseWellFormedTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseAlertMessage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", rnd_addAnimBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", rnd_removeAnimBoxnode);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", D_00138FEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", D_00138FF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", D_00139004);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", D_00139010);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", D_0013901C);
