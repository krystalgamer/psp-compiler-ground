/* cflags: -O1 */
#include "common.h"
#include "parse_str.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseFindValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseFindName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", procMetaTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseFindMetaTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseCheckMetaCharset);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseCheckEncodeType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseSetExtractedAuthData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseTagNameCmp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseDSTagNameCmp);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseNextChar);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseStrEqualNoCase);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseMBtoDScopy);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseConvertUTF8toUCS2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseCheckLastTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseConvertEncode);

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
