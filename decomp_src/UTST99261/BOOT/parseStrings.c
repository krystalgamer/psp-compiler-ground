/* cflags: -O1 */
#include "common.h"
#include "parse_rnd.h"
#include "parse_str.h"
#include "m2c_macros.h"
#define CI(c, C) (((c) >= 'a' && (c) <= 'z') ? ((c) == (C) + 0x20) : ((c) == (C)))
int HST_addAuthorizationDB();
extern int DOM_NODE_MAX_SIZE;
extern PChar DomMaxAlert[];
extern PChar ds_font[];
extern PChar ds_color[];
extern PChar ds_ff00[];
extern PChar ds_br[];
void *Util_HTMLDocument_getBody();
void *Document_createElement();
void *Document_createTextNode();
void *MEM_malloc();
void MEM_free();
int OS_clock_gettime();
int rnd_newMarquee();
int rnd_gdrawImageReset();
extern PTag htmlElementTable[];


unsigned int strlen(const char *);
int strncasecmp(const char *, const char *, unsigned int);
int strncmp(const char *, const char *, unsigned int);
char *strncpy(char *, const char *, unsigned int);
int checkEncode(unsigned char *s, int n);
void *memcpy(void *, const void *, unsigned int);
int parseStrEqual(char *a, PChar *b);
int parseDStrEqual(char *a, PDStr *s);
int utf8ToUcs2(unsigned short *d, const char *s, int n);
void *MEM_realloc(void *, void *p, unsigned int size);
int sjisToUcs2(u16 *dst, const u8 *src, int len);
int eucToUcs2(u16 *dst, const u8 *src, int len);
int asciiToUcs2(u16 *dst, const u8 *src, int len);
void *Node_appendChild(void *, void *);
void parseElementSetAttribute(int elem, PDStr *name, void *val);
void CharacterData_setData(void *, void *);
void parseFindValue(char *s, int *start, int *end, int *next) {
    int b;
    int st;
    int i;

    b = 0;
    st = 0;
    i = 0;
    for (;;) {
        if (s[i] == 0) {
            break;
        }
        switch (st) {
        case 0:
            if (s[i] == '=') {
                st = 1;
            }
            break;
        case 1:
            if (s[i] == '"') {
                st = 2;
                i++;
                b = i;
                continue;
            }
            if (s[i] != ' ') {
                st = 3;
                b = i;
            }
            break;
        case 2:
            if (s[i] == '"') {
                *start = b;
                *end = i;
                *next = i + 1;
                return;
            }
            break;
        case 3:
            if (s[i] == ' ' || s[i] == '"') {
                *start = b;
                *end = i;
                goto out;
            }
            break;
        }
        i++;
    }
    *start = 0;
    *end = 0;
out:
    *next = i;
}

void parseFindName(char *s, char *name, int *start, int *val, int *end)
{
    int st;
    int len;
    int i;
    char c;

    st = 0;
    len = strlen(name);
    i = 0;
    for (;;) {
        if (strncasecmp(s + st, name, len) == 0)
            break;
        while (s[i] != 0 && s[i] != ' ' && s[i] != ';')
            i++;
        if (s[i] == 0) {
            *start = 0;
            *val = 0;
            *end = i;
            return;
        }
        i++;
        st = i;
    }
    i += len;
    for (;;) {
        c = s[i];
        if (c == 0) {
            *end = i;
            return;
        }
        if (c != ' ') {
            if (c != '=') {
                *start = 0;
                *val = 0;
            } else {
                *start = st;
                *val = i;
            }
            *end = i;
            return;
        }
        i++;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", procMetaTag);

void parseFindMetaTag(char *s, int *start, int *end, int *adv, int n) {
    int b;
    int st;
    int i;
    int r;

    b = 0;
    st = 0;
    i = 0;
    for (;;) {
        if (i >= n) {
            break;
        }
        switch (st) {
        case 0:
            if (s[i] == '<') {
                st = 1;
                b = i + 1;
            }
            break;
        case 1:
            if (s[i] == '>') {
                r = (n - b < 5) ? -1 : strncasecmp(s + b, "meta ", 5);
                st = 0;
                if (r == 0) {
                    *start = b + 5;
                    *end = i;
                    goto out;
                }
                b = 0;
            } else {
                r = (n - i < 3) ? -1 : strncmp(s + i, "!--", 3);
                if (r == 0 && s[i - 1] == '<') {
                    st = 2;
                }
            }
            break;
        case 2:
            if (s[i] == '-') {
                r = (n - i < 3) ? -1 : strncmp(s + i, "-->", 3);
                if (r == 0) {
                    st = 0;
                    i += 2;
                }
            }
            break;
        }
        i++;
    }
    *start = 0;
    *end = 0;
out:
    *adv = i;
}

int parseCheckMetaCharset(char *buf, int len) {
    int start;
    int end;
    int adv;
    int off;
    int n;
    char *tag;
    int r;
    int left;

    start = 0;
    end = 0;
    adv = 0;
    off = 0;
    left = len;
    for (;;) {
        if (left <= 0) {
            return -1;
        }
        adv = 0;
        parseFindMetaTag(buf + off, &start, &end, &adv, left);
        n = end - start;
        if (n != 0) {
            tag = MEM_malloc(0, n + 1);
            if (tag == NULL) {
                return -1;
            }
            strncpy(tag, buf + (off + start), n);
            tag[n] = 0;
            r = procMetaTag(tag);
            MEM_free(0, tag);
            if (r != -1) {
                return r;
            }
        }
        off += adv;
        left -= adv;
    }
}

void parseCheckEncodeType(PCtx *c, int *src) {
    int n;
    char *p;
    int i;
    int r;
    int m;

    switch (src[10]) {
    case 0:
        n = src[6];
        p = (char *)src[7];
        for (i = 0; i < n && p[i] != 0; i++) {
        }
        if (i == n - 1) {
            n = i;
        }
        m = parseCheckMetaCharset((char *)src[7], n);
        if (m != -1) {
            c->x00[2] = m;
        } else {
            r = checkEncode((char *)src[7], n);
            if (r == 4 || r == 0 || r == -1) {
                c->x00[2] = 2;
            } else {
                c->x00[2] = r;
            }
        }
        break;
    case 2:
        c->x00[2] = 3;
        break;
    case 3:
        c->x00[2] = 1;
        break;
    case 4:
        c->x00[2] = 5;
        break;
    case 5:
        c->x00[2] = 0;
        break;
    case 1:
    default:
        c->x00[2] = 2;
        break;
    }
}

char *parseSetExtractedAuthData(char *url, int len) {
    int found;
    int at;
    int i;
    int colon;
    int slash;
    int nl;
    int rest;
    char **auth;

    slash = 0;
    found = 0;
    colon = 0;
    for (at = 0; at < len; at++) {
        if (url[at] == '@') {
            found = 1;
            break;
        }
    }
    if (!found) {
        return url;
    }
    for (i = at - 1; i >= 0; i--) {
        if (url[i] == ':') {
            colon = i;
        }
        if (url[i] == '/') {
            slash = i;
            break;
        }
    }
    if (slash == 0) {
        return url;
    }
    if (colon + 1 == at || colon == 0) {
        return url;
    }
    auth = MEM_malloc(0, 12);
    rest = len - at;
    nl = rest + slash;
    auth[0] = MEM_malloc(0, nl + 1);
    memcpy(auth[0], url, slash + 1);
    memcpy(auth[0] + slash + 1, url + at + 1, --rest);
    auth[0][nl] = 0;
    if (colon == slash + 1) {
        auth[1] = NULL;
    } else if (colon + 1 == at || colon == 0) {
        len = at - slash;
        auth[1] = MEM_malloc(0, len);
        memcpy(auth[1], url + slash + 1, len - 1);
        auth[1][len - 1] = 0;
        auth[2] = NULL;
        goto add;
    } else {
        len = colon - slash;
        auth[1] = MEM_malloc(0, len);
        memcpy(auth[1], url + slash + 1, len - 1);
        auth[1][len - 1] = 0;
    }
    len = at - colon;
    auth[2] = MEM_malloc(0, len);
    memcpy(auth[2], url + colon + 1, len - 1);
    auth[2][len - 1] = 0;
add:
    HST_addAuthorizationDB(auth);
    return auth[0];
}

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
    c->tags.n[t.id]++;
    return 0;
}

int parseTagCountMinus(PCtx *c, PTag t) {
    if (c->tags.n[t.id] != 0) {
        c->tags.n[t.id]--;
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

int parseDStrEqual(char *a, PDStr *s) {
    int i;

    if (a == NULL || s == NULL || s->data == NULL) {
        return 0;
    }
    for (i = 0; i < s->len; i++) {
        if (((char)s->data[i] >= 'A' && (char)s->data[i] <= 'Z') ? a[i] != (char)s->data[i] + 0x20 : a[i] != (char)s->data[i]) {
            return 0;
        }
    }
    return 1;
}

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

int parseCheckLastTag(void *ctx, unsigned char *s, int n, int enc) {
    int st;
    int i;
    int last;

    last = 0;
    switch (enc) {
    case -1:
    case 0:
    case 3:
    case 5:
        for (i = 1; i <= n; i++) {
            if (*s == '>') {
                last = i;
            }
            s++;
        }
        break;
    case 2:
    case 4:
        for (i = 1; i <= n; i++) {
            if (*s == '>' && !((s[-1] >= 0x81 && s[-1] <= 0x9F) || (s[-1] >= 0xE0 && s[-1] <= 0xEF))) {
                last = i;
            }
            s++;
        }
        break;
    case 1:
        st = 0;
        for (i = 1; i <= n; i++) {
            if (st == 0) {
                if (*s == '>') {
                    last = i;
                } else if (*s == 0x1B) {
                    s++;
                    i++;
                    if (*s == '$') {
                        st = 1;
                    }
                }
                s++;
            } else if (st == 1) {
                if (*s == 0x1B) {
                    s++;
                    i++;
                    if (*s == '(') {
                        st = 0;
                    }
                }
                s++;
            }
        }
        break;
    }
    return last;
}

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

int parseWellFormedTag(PChar *buf, int n) {
    int type;
    int i;

    type = 0;
    for (i = 0; i < n; i++) {
        if (buf[i] == '<') {
            if (CI(buf[i + 1], 'S') && CI(buf[i + 2], 'C') && CI(buf[i + 3], 'R') && CI(buf[i + 4], 'I') && CI(buf[i + 5], 'P') && CI(buf[i + 6], 'T')) {
                type = 1;
                break;
            }
            if (CI(buf[i + 1], 'S') && CI(buf[i + 2], 'T') && CI(buf[i + 3], 'Y') && CI(buf[i + 4], 'L') && CI(buf[i + 5], 'E')) {
                type = 0x10;
                break;
            }
        }
    }
    switch (type) {
    case 0:
        type = 0;
        for (i = n - 1; i >= 0; i--) {
            if (buf[i] == '>') {
                type = 1;
            }
            if (buf[i] == '<') {
                if (((char)buf[i + 1] >= 'A' && (char)buf[i + 1] <= 'Z') || ((char)buf[i + 1] >= 'a' && (char)buf[i + 1] <= 'z') || (char)buf[i + 1] == '!' || (char)buf[i + 1] == '/' || (char)buf[i + 1] == '?') {
                    if (type == 1) {
                        return 1;
                    }
                    return 1;
                }
            }
        }
        break;
    case 1:
        type = 0;
        for (i = n - 1; i >= 0; i--) {
            if (buf[i] == '>') {
                type = 1;
            }
            if (type == 1 && buf[i] == '<') {
                if (CI(buf[i + 1], '/') && CI(buf[i + 2], 'S') && CI(buf[i + 3], 'C') && CI(buf[i + 4], 'R') && CI(buf[i + 5], 'I') && CI(buf[i + 6], 'P') && CI(buf[i + 7], 'T')) {
                    return 0x10;
                }
                return 0;
            }
        }
        break;
    case 0x10:
        type = 0;
        for (i = n - 1; i >= 0; i--) {
            if (buf[i] == '>') {
                type = 1;
            }
            if (type == 1 && buf[i] == '<') {
                if (CI(buf[i + 1], '/') && CI(buf[i + 2], 'S') && CI(buf[i + 3], 'T') && CI(buf[i + 4], 'Y') && CI(buf[i + 5], 'L') && CI(buf[i + 6], 'E')) {
                    return 0x100;
                }
                return 0;
            }
        }
        break;
    }
    return 0;
}

void parseAlertMessage(PCtx *c) {
    void *body;
    void *parent;
    void *el;
    void *text;

    c->alertCount++;
    if (DOM_NODE_MAX_SIZE != 0) {
        PDStr msg = {27, 27, DomMaxAlert};
        PDStr font = {4, 4, ds_font};
        PDStr color = {5, 5, ds_color};
        PDStr ff00 = {7, 7, ds_ff00};
        PDStr br = {2, 2, ds_br};

        parent = NULL;
        if (c->alertCount >= DOM_NODE_MAX_SIZE) {
            body = Util_HTMLDocument_getBody(c->doc);
            el = Document_createElement(c->doc, &br);
            if (el != NULL) {
                Node_appendChild(body, el);
                parent = el;
            }
            el = Document_createElement(c->doc, &br);
            if (el != NULL) {
                Node_appendChild(parent, el);
                parent = el;
            }
            el = Document_createElement(c->doc, &font);
            if (el != NULL) {
                parseElementSetAttribute(el, &color, &ff00);
                Node_appendChild(parent, el);
            }
            text = Document_createTextNode(c->doc, 0);
            CharacterData_setData(text, &msg);
            Node_appendChild(el, text);
            c->state = 15;
        }
    }
}

int rnd_addAnimBoxnode(RndBox *box, void *arg) {
    RndAnimNode *n;
    RndAnimGroup *g;
    RndAnimImage *img;
    RndTime t;
    RndTime ts;

    if (box->type == 0x13) {
        for (n = rnd_global.x14; n != NULL; n = n->next) {
            if (n->box == box) {
                return 0;
            }
        }
        n = MEM_malloc(0, 0x10);
        if (n == NULL) {
            return -100;
        }
        if (rnd_newMarquee(box, n) < 0) {
            MEM_free(0, n);
            return -100;
        }
        n->next = rnd_global.x14;
        n->box = box;
        n->arg = arg;
        rnd_global.x14 = n;
    } else if (box->type == 10) {
        for (g = rnd_global.x10; g != NULL; g = g->next) {
            for (n = g->list; n != NULL; n = n->next) {
                if (n->box == box) {
                    return 0;
                }
            }
        }
        img = *box->x20;
        for (g = rnd_global.x10; g != NULL; g = g->next) {
            if (g->image == img) {
                break;
            }
        }
        if (g == NULL) {
            g = MEM_malloc(0, 0xC);
            if (g == NULL) {
                return -100;
            }
            g->next = rnd_global.x10;
            g->image = img;
            g->list = NULL;
            rnd_global.x10 = g;
            OS_clock_gettime(0, &ts);
            t = ts;
            g->image->x1C = 0;
            rnd_gdrawImageReset(g->image, &t);
        }
        n = MEM_malloc(0, 0x10);
        if (n == NULL) {
            return -100;
        }
        n->next = g->list;
        n->box = box;
        n->arg = arg;
        g->list = n;
    } else if (box->type == 9) {
        for (n = rnd_global.x0C; n != NULL; n = n->next) {
            if (n->box == box) {
                return 0;
            }
        }
        n = MEM_malloc(0, 0x10);
        if (n == NULL) {
            return -100;
        }
        n->next = rnd_global.x0C;
        n->box = box;
        n->arg = arg;
        rnd_global.x0C = n;
    }
    return 0;
}

void rnd_removeAnimBoxnode(RndBox *box) {
    RndAnimNode *n;
    RndAnimNode *next;
    RndAnimNode *prev;
    RndAnimGroup *g;
    RndAnimGroup *gnext;
    RndAnimGroup *gprev;

    if (box->type == 9) {
        prev = NULL;
        for (n = rnd_global.x0C; n != NULL; n = next) {
            next = n->next;
            if (n->box == box) {
                MEM_free(0, n);
                if (prev != NULL) {
                    prev->next = next;
                } else {
                    rnd_global.x0C = next;
                }
            } else {
                prev = n;
            }
        }
    } else if (box->type == 10) {
        gprev = NULL;
        for (g = rnd_global.x10; g != NULL; g = gnext) {
            gnext = g->next;
            prev = NULL;
            for (n = g->list; n != NULL; n = next) {
                next = n->next;
                if (n->box == box) {
                    MEM_free(0, n);
                    if (prev != NULL) {
                        prev->next = next;
                    } else {
                        g->list = next;
                    }
                } else {
                    prev = n;
                }
            }
            if (g->list == NULL) {
                MEM_free(0, g);
                if (gprev != NULL) {
                    gprev->next = gnext;
                } else {
                    rnd_global.x10 = gnext;
                }
            } else {
                gprev = g;
            }
        }
    } else if (box->type == 0x13) {
        prev = NULL;
        for (n = rnd_global.x14; n != NULL; n = next) {
            next = n->next;
            if (n->box == box) {
                MEM_free(0, n->x0C);
                MEM_free(0, n);
                if (prev != NULL) {
                    prev->next = next;
                } else {
                    rnd_global.x14 = next;
                }
            } else {
                prev = n;
            }
        }
    }
}
