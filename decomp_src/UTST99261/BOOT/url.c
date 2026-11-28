/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"

typedef struct QUEUE {
    struct QUEUE *next;
    struct QUEUE *prev;
} QUEUE;

extern const char _ctype_[];
extern char D_00132354[];   /* "file:" */

typedef struct {
    QUEUE q;
    int len;            /* 0x8 */
    u8 flag;            /* 0xC */
} MBLOCK;

typedef struct {
    int unk0;
    int size;           /* 0x4 */
    QUEUE q;            /* 0x8 */
    MBLOCK *first;      /* 0x10 */
    MBLOCK *cur;        /* 0x14 */
    int off;            /* 0x18 */
} MFILE;

typedef struct {
    char *scheme;
    char *host;
    int port;
    char *path;         /* 0xC */
    char *query;        /* 0x10 */
    char *frag;         /* 0x14 */
} URL;

typedef struct {
    u8 *start;
    int unk4;
    u8 *end;            /* 0x8 */
} GIFBS;

typedef struct {
    void *next;
    s16 left;
    s16 top;
    u16 width;          /* 0x8 */
    u16 height;
    u8 unkC[0x1C];
    u8 *buf;            /* 0x28 */
} GIFFRAME;

typedef struct {
    GIFBS *bs;
    u16 width;          /* 0x4 */
    u16 height;
    u8 unk8[0x10];
    int unk18;
    int unk1C;
    u8 unk20[0x12];
    s8 interlace;       /* 0x32 */
    int *rows;          /* 0x34 */
    int unk38;
    int offset;         /* 0x3C */
    int x;              /* 0x40 */
    int line;           /* 0x44 */
    int step;           /* 0x48 */
    int unk4C;
    int unk50;
    GIFFRAME *unk54;
    int unk58;
    u8 unk5C[0xC13C];
    int lines;          /* 0xC198 */
} GIFCTX;

typedef struct {
    s16 width;
    s16 height;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
} IMGDATA;

char *strrchr(const char *s, int c);
int strncasecmp(const char *a, const char *b, unsigned int n);
int UTL_guessMIMETypeFromName(char *name);
QUEUE *UTL_dequeue(QUEUE *q);
void MEM_free(void *pool, void *p);
void *MEM_malloc(void *pool, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
unsigned int strlen(const char *s);
char *pathMake(char *path);
int GIFParser(GIFCTX *ctx, int flag);
int UTL_mfileread(MFILE *f, void *buf, int n);
int UTL_mfilesize(void *f);
int UTL_mfiledelete(MFILE *f);
void UTL_mfileseek(MFILE *f, int pos);
MFILE *UTL_mfilecreate(int bsize);
QUEUE *UTL_peekqueue(QUEUE *q, QUEUE *e);
int UTL_mfilewrite(MFILE *f, void *buf, int n);

typedef struct {
    int type;
    char *mime;
    char *ext;
} CNTTBL;
extern const CNTTBL cnt_tbl[];
int strcasecmp(const char *a, const char *b);
char *trimspace(char *s);
char *toAbsoluteURL(char *base, char *rel);

extern char *FILESTRAGE_TABLE[];

int getFrameNumber(u8 *p, int len);

typedef struct {
    char *start;
    char *end;
} STRWORD;
int strcmp(const char *a, const char *b);

M2C_UNK createGifContext();                         /* extern */
M2C_UNK deleteGifContext();                         /* extern */
M2C_UNK initializeGifContext();                     /* extern */
M2C_UNK setGifBuffer();                             /* extern */


char *strcpy(char *d, const char *s);

typedef struct { char *start; char *end; } UTLWORD;
char *trimspace(char *s) {
    char *buf;
    char *p;

    buf = MEM_malloc(NULL, strlen(s) + 1);
    if (buf == NULL) {
        return NULL;
    }
    p = s;
    while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') {
        p++;
    }
    strcpy(buf, p);
    p = buf + strlen(buf) - 1;
    while (buf < p && (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')) {
        *p = 0;
        p--;
    }
    return buf;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001322F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001322F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001322FC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", toAbsoluteURL);

typedef struct {
    char *scheme;
    int schemeLen;
    char *host;
    int hostLen;
    char *port;
    int portLen;
    char *path;
    int pathLen;
    char *query;
    int queryLen;
    char *frag;
    int fragLen;
} URLPARTS;

extern char D_001322F4[];
void *MEM_calloc(void *pool, unsigned int n);
void URL_splitURL(URLPARTS *p, char *s);
long strtol(const char *s, char **end, int base);
char *strcat(char *d, const char *s);

URL *URL_new(char *s) {
    URL *u;
    char *t;
    URLPARTS p;
    char c;

    if (s == NULL || (u = MEM_malloc(NULL, sizeof(URL))) == NULL) {
        return NULL;
    }
    u->scheme = NULL;
    u->host = NULL;
    u->port = 0;
    u->path = NULL;
    u->query = NULL;
    u->frag = NULL;
    t = trimspace(s);
    if (t == NULL) {
        goto fail;
    }
    URL_splitURL(&p, t);
    if (p.scheme != NULL) {
        u->scheme = MEM_calloc(NULL, p.schemeLen + 2);
        if (u->scheme == NULL) {
            goto fail;
        }
        memcpy(u->scheme, p.scheme, p.schemeLen);
        strcat(u->scheme, D_001322F4);
    }
    if (p.host != NULL) {
        u->host = MEM_malloc(NULL, p.hostLen + 1);
        if (u->host == NULL) {
            goto fail;
        }
        memcpy(u->host, p.host, p.hostLen);
        u->host[p.hostLen] = 0;
    }
    if (p.port != NULL) {
        c = p.port[p.portLen];
        p.port[p.portLen] = 0;
        u->port = strtol(p.port, NULL, 10);
        p.port[p.portLen] = c;
    }
    if (p.path != NULL) {
        u->path = MEM_malloc(NULL, p.pathLen + 1);
        if (u->path == NULL) {
            goto fail;
        }
        memcpy(u->path, p.path, p.pathLen);
        u->path[p.pathLen] = 0;
    }
    if (p.query != NULL) {
        u->query = MEM_malloc(NULL, p.queryLen + 1);
        if (u->query == NULL) {
            goto fail;
        }
        memcpy(u->query, p.query, p.queryLen);
        u->query[p.queryLen] = 0;
    }
    if (p.frag != NULL) {
        u->frag = MEM_malloc(NULL, p.fragLen + 1);
        if (u->frag == NULL) {
            goto fail;
        }
        memcpy(u->frag, p.frag, p.fragLen);
        u->frag[p.fragLen] = 0;
    }
    MEM_free(NULL, t);
    return u;
fail:
    if (u->scheme != NULL) {
        MEM_free(NULL, u->scheme);
    }
    if (u->host != NULL) {
        MEM_free(NULL, u->host);
    }
    if (u->path != NULL) {
        MEM_free(NULL, u->path);
    }
    if (u->query != NULL) {
        MEM_free(NULL, u->query);
    }
    if (u->frag != NULL) {
        MEM_free(NULL, u->frag);
    }
    if (t != NULL) {
        MEM_free(NULL, t);
    }
    MEM_free(NULL, u);
    return NULL;
}

void URL_free(URL *u) {
    if (u->scheme != NULL) {
        MEM_free(NULL, u->scheme);
    }
    if (u->host != NULL) {
        MEM_free(NULL, u->host);
    }
    if (u->path != NULL) {
        MEM_free(NULL, u->path);
    }
    if (u->query != NULL) {
        MEM_free(NULL, u->query);
    }
    if (u->frag != NULL) {
        MEM_free(NULL, u->frag);
    }
    MEM_free(NULL, u);
}

void URL_setScheme(URL *u, char *s) {
    int len;
    char *p;
    int add = 0;

    if (s == NULL || (len = strlen(s)) <= 0) {
        if (u->scheme != NULL) {
            MEM_free(NULL, u->scheme);
            u->scheme = NULL;
        }
        return;
    }
    if (s[len - 1] != ':') {
        add = 1;
    }
    p = MEM_malloc(NULL, len + add + 1);
    if (p == NULL) {
        return;
    }
    memcpy(p, s, len);
    if (add == 1) {
        p[len] = ':';
        len++;
    }
    p[len] = 0;
    if (u->scheme != NULL) {
        MEM_free(NULL, u->scheme);
    }
    u->scheme = p;
}

void URL_setHost(URL *u, char *s) {
    int len;
    char *p;

    if (s == NULL || (len = strlen(s)) <= 0) {
        if (u->host != NULL) {
            MEM_free(NULL, u->host);
            u->host = NULL;
        }
        return;
    }
    p = MEM_malloc(NULL, len + 1);
    if (p == NULL) {
        return;
    }
    memcpy(p, s, len);
    p[len] = 0;
    if (u->host != NULL) {
        MEM_free(NULL, u->host);
    }
    u->host = p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void URL_setPort(void *arg0, int arg1) {
    if (M2C_FIELD(arg0, int *, 8) >= 0) {
        M2C_FIELD(arg0, int *, 8) = arg1;
    }
}

void URL_setPath(URL *u, char *s) {
    int len;
    char *p;

    if (s == NULL || (len = strlen(s)) <= 0) {
        if (u->path != NULL) {
            MEM_free(NULL, u->path);
            u->path = NULL;
        }
        return;
    }
    p = MEM_malloc(NULL, len + 1);
    if (p == NULL) {
        return;
    }
    memcpy(p, s, len);
    p[len] = 0;
    if (u->path != NULL) {
        MEM_free(NULL, u->path);
    }
    u->path = p;
}

void URL_setQuery(URL *u, char *s) {
    int len;
    char *p;
    int add = 0;

    if (s == NULL || (len = strlen(s)) <= 0) {
        if (u->query != NULL) {
            MEM_free(NULL, u->query);
            u->query = NULL;
        }
        return;
    }
    if (s[0] != '?') {
        add = 1;
    }
    p = MEM_malloc(NULL, len + add + 1);
    if (p == NULL) {
        return;
    }
    if (add == 1) {
        p[0] = '?';
        memcpy(p + 1, s, len);
        len++;
    } else {
        memcpy(p, s, len);
    }
    p[len] = 0;
    if (u->query != NULL) {
        MEM_free(NULL, u->query);
    }
    u->query = p;
}

void URL_setAnchor(URL *u, char *s) {
    int len;
    char *p;
    int add = 0;

    if (s == NULL || (len = strlen(s)) <= 0) {
        if (u->frag != NULL) {
            MEM_free(NULL, u->frag);
            u->frag = NULL;
        }
        return;
    }
    if (s[0] != '#') {
        add = 1;
    }
    p = MEM_malloc(NULL, len + add + 1);
    if (p == NULL) {
        return;
    }
    if (add == 1) {
        p[0] = '#';
        memcpy(p + 1, s, len);
        len++;
    } else {
        memcpy(p, s, len);
    }
    p[len] = 0;
    if (u->frag != NULL) {
        MEM_free(NULL, u->frag);
    }
    u->frag = p;
}

char *URL_toString(URL *u) {
    unsigned int len;
    int p;
    int n;
    char *buf;
    char *s;

    len = 0;
    if (u == NULL) {
        return NULL;
    }
    if (u->scheme != NULL) {
        len += strlen(u->scheme);
        if (u->host != NULL) {
            len += strlen(u->host) + 2;
            if (u->port != 80) {
                n = 0;
                for (p = u->port; p > 0; p /= 10) {
                    n++;
                }
                len += n + 1;
            }
        }
    }
    if (u->path != NULL) {
        len += strlen(u->path);
    }
    if (u->query != NULL) {
        len += strlen(u->query);
    }
    if (u->frag != NULL) {
        len += strlen(u->frag);
    }
    buf = MEM_malloc(NULL, len + 1);
    if (buf == NULL) {
        return NULL;
    }
    *buf = 0;
    s = buf;
    if (u->scheme != NULL) {
        s += sprintf(s, "%s", u->scheme);
        if (u->host != NULL) {
            s += sprintf(s, "//%s", u->host);
            if (u->port != 0) {
                s += sprintf(s, ":%d", u->port);
            }
        }
    }
    if (u->path != NULL) {
        s += sprintf(s, "%s", u->path);
    }
    if (u->query != NULL) {
        s += sprintf(s, "%s", u->query);
    }
    if (u->frag != NULL) {
        sprintf(s, "%s", u->frag);
    }
    return buf;
}

char *URL_toAbsoluteURL(char *base, char *rel) {
    char *b;
    char *r;
    char *res;

    b = trimspace(base);
    if (b == NULL) {
        return NULL;
    }
    r = trimspace(rel);
    if (r == NULL) {
        MEM_free(NULL, b);
        return NULL;
    }
    res = toAbsoluteURL(b, r);
    MEM_free(NULL, r);
    MEM_free(NULL, b);
    return res;
}

int URL_equals(URL *a, URL *b) {
    if (a == b) {
        return 1;
    }
    if (a->scheme != NULL && b->scheme != NULL) {
        if (strcmp(a->scheme, b->scheme) != 0) {
            return 0;
        }
    } else if (a->scheme != b->scheme) {
        return 0;
    }
    if (a->host != NULL && b->host != NULL) {
        if (strcmp(a->host, b->host) != 0) {
            return 0;
        }
    } else if (a->host != b->host) {
        return 0;
    }
    if (a->port != b->port) {
        return 0;
    }
    if (a->path != NULL && b->path != NULL) {
        if (strcmp(a->path, b->path) != 0) {
            return 0;
        }
    } else if (a->path != b->path) {
        return 0;
    }
    if (a->query != NULL && b->query != NULL) {
        if (strcmp(a->query, b->query) != 0) {
            return 0;
        }
    } else if (a->query != b->query) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_splitURL);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132328);

char *strchr(const char *s, int c);
int sprintf(char *buf, const char *fmt, ...);

char *URL_encode(char *s_, int len) {
    char safe[] = "%$-_.+!*'(),;:@&=/~?[]";
    char *buf;
    char *d;
    int i;
    char *s;

    buf = MEM_malloc(NULL, len * 3 + 1);
    if (buf == NULL) {
        return NULL;
    }
    d = buf;
    s = s_;
    for (i = 0; i < len; i++) {
        if (((_ctype_ + 1)[(int)*s] & 7) || strchr(safe, *s) != NULL) {
            *d++ = *s++;
        } else {
            d += sprintf(d, "%%%02X", (u8)*s++);
        }
    }
    *d = 0;
    return buf;
}

#define CT(c) ((_ctype_ + 1)[(int)(c)])
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_decode);

int URL_checkFileStrage(URL *u) {
    int i;

    if (u->scheme == NULL || u->host == NULL) {
        return -1;
    }
    if (strcasecmp(u->scheme, D_00132354) != 0) {
        return -1;
    }
    for (i = 0; FILESTRAGE_TABLE[i] != NULL; i++) {
        if (strncasecmp(u->host, FILESTRAGE_TABLE[i], strlen(FILESTRAGE_TABLE[i])) == 0) {
            return i;
        }
    }
    return -1;
}

char *URL_toLocalFileName(char *url) {
    if (strncasecmp(url, D_00132354, 5) == 0) {
        url += 5;
    }
    if (url[0] == '/' && url[1] == '/') {
        url += 2;
    }
    return pathMake(url);
}

int UTL_isSupportedMIMEType(char *mime) {
    int i;

    if (mime == NULL) {
        return 0;
    }
    for (i = 0; cnt_tbl[i].type != -1; i++) {
        if (cnt_tbl[i].mime != NULL && strcasecmp(cnt_tbl[i].mime, mime) == 0) {
            return 1;
        }
    }
    return 0;
}

int UTL_isSupportedFileType(char *name) {
    if (strrchr(name, '.') == NULL) {
        return 1;
    }
    return UTL_guessMIMETypeFromName(name) != -1;
}

int UTL_guessMIMETypeFromName(char *name) {
    char *buf;
    char *p;
    int i;
    int j;
    char **ext;

    buf = MEM_malloc(NULL, strlen(name) + 1);
    if (buf == NULL) {
        return -1;
    }
    strcpy(buf, name);
    p = strchr(buf, '#');
    if (p != NULL) {
        *p = 0;
    }
    p = strchr(buf, '?');
    if (p != NULL) {
        *p = 0;
    }
    p = strrchr(buf, '.');
    if (p == NULL) {
        MEM_free(NULL, buf);
        return 5;
    }
    p++;
    for (i = 0; cnt_tbl[i].type != -1; i++) {
        if (cnt_tbl[i].ext == NULL) {
            continue;
        }
        ext = (char **)cnt_tbl[i].ext;
        for (j = 0; ext[j] != NULL; j++) {
            if (strcasecmp(p, ext[j]) == 0) {
                MEM_free(NULL, buf);
                return cnt_tbl[i].type;
            }
        }
    }
    MEM_free(NULL, buf);
    return -1;
}

int UTL_guessMIMEType(char *mime) {
    int i;

    if (mime == NULL) {
        return -1;
    }
    for (i = 0; cnt_tbl[i].type != -1; i++) {
        if (cnt_tbl[i].mime != NULL && strcasecmp(cnt_tbl[i].mime, mime) == 0) {
            return cnt_tbl[i].type;
        }
    }
    return -1;
}

int UTL_isNumber(char *s, int len) {
    int i;

    if (s == NULL) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        if (!((_ctype_ + 1)[(int)*s] & 4)) {
            return 0;
        }
        s++;
    }
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void UTL_initqueue(QUEUE *q) {
    q->next = q;
    q->prev = q;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void UTL_enqueue(QUEUE *q, QUEUE *e) {
    QUEUE *last;

    last = q->prev;
    q->prev = e;
    last->next = e;
    e->next = q;
    e->prev = last;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
QUEUE *UTL_dequeue(QUEUE *q) {
    QUEUE *e;
    QUEUE *n;
    QUEUE *ret;

    e = q->next;
    ret = NULL;
    if (q != e) {
        n = e->next;
        q->next = n;
        n->prev = q;
        e->next = NULL;
        e->prev = NULL;
        ret = e;
    }
    return ret;
}

void UTL_relqueue(QUEUE *q, QUEUE *e) {
    QUEUE *next;
    QUEUE *prev;

    next = e->next;
    prev = e->prev;
    prev->next = next;
    next->prev = prev;
    e->next = NULL;
    e->prev = NULL;
}

void UTL_insqueue(QUEUE *q, QUEUE *pos, QUEUE *e) {
    QUEUE *prev;

    prev = pos->prev;
    e->next = pos;
    e->prev = prev;
    pos->prev = e;
    prev->next = e;
}

QUEUE *UTL_peekqueue(QUEUE *q, QUEUE *e) {
    QUEUE *n;

    if (e == NULL) {
        e = q;
    }
    n = e->next;
    if (q != n) {
        return n;
    }
    return NULL;
}

QUEUE *UTL_peekprevqueue(QUEUE *q, QUEUE *e) {
    QUEUE *n;

    if (e == NULL) {
        e = q;
    }
    n = e->prev;
    if (q != n) {
        return n;
    }
    return NULL;
}

int UTL_sizequeue(QUEUE *q) {
    QUEUE *e;
    int n;

    e = NULL;
    n = 0;
    while ((e = UTL_peekqueue(q, e)) != NULL) {
        n++;
    }
    return n;
}

MFILE *UTL_mfilecreate(int bsize) {
    MFILE *f;

    f = MEM_malloc(NULL, sizeof(MFILE));
    if (f == NULL) {
        return NULL;
    }
    f->unk0 = bsize;
    f->size = 0;
    f->off = 0;
    f->first = MEM_malloc(NULL, bsize + 0x10);
    if (f->first == NULL) {
        MEM_free(NULL, f);
        return NULL;
    }
    f->first->len = 0;
    f->first->flag = 1;
    f->cur = f->first;
    UTL_initqueue(&f->q);
    UTL_enqueue(&f->q, &f->first->q);
    return f;
}

int UTL_mfiledelete(MFILE *f) {
    void *b;

    if (f != NULL) {
        while ((b = UTL_dequeue(&f->q)) != NULL) {
            MEM_free(NULL, b);
        }
        MEM_free(NULL, f);
    }
    return 0;
}

int UTL_mfileread(MFILE *f, void *buf, int n) {
    int total = 0;
    int len;
    MBLOCK *b;

    if (f->cur->flag != 1) {
        return 0;
    }
    while (n > 0) {
        len = f->cur->len - f->off;
        if (len > 0) {
            if (len > n) {
                len = n;
            }
            memcpy(buf, (char *)(f->cur + 1) + f->off, len);
            f->off += len;
            n -= len;
            buf = (char *)buf + len;
            total += len;
        } else {
            b = (MBLOCK *)UTL_peekqueue(&f->q, &f->cur->q);
            if (b == NULL) {
                return total;
            }
            f->cur = b;
            f->off = 0;
        }
    }
    return total;
}

int UTL_mfilewrite(MFILE *f, void *buf, int n) {
    int total = 0;
    int len;
    MBLOCK *b;

    if (f->first->flag != 1) {
        return 0;
    }
    while (n > 0) {
        len = f->unk0 - f->first->len;
        if (len > 0) {
            if (len > n) {
                len = n;
            }
            memcpy((char *)(f->first + 1) + f->first->len, buf, len);
            f->first->len += len;
            f->size += len;
            n -= len;
            buf = (char *)buf + len;
            total += len;
        } else {
            b = MEM_malloc(NULL, f->unk0 + 0x10);
            if (b == NULL) {
                return -1;
            }
            b->len = 0;
            b->flag = 1;
            UTL_enqueue(&f->q, &b->q);
            b = (MBLOCK *)UTL_peekqueue(&f->q, &f->first->q);
            if (b == NULL) {
                return total;
            }
            f->first = b;
        }
    }
    return total;
}

int UTL_mfilegetc(void *f) {
    u8 c;

    if (UTL_mfileread(f, &c, 1) != 1) {
        return -1;
    }
    return c;
}

void UTL_mfileclean(MFILE *f) {
    MBLOCK *b;
    MBLOCK *n;

    for (b = (MBLOCK *)UTL_peekqueue(&f->q, NULL); b != NULL && f->cur != b; b = (MBLOCK *)UTL_peekqueue(&f->q, &b->q)) {
        if (b->flag == 1) {
            n = MEM_malloc(NULL, sizeof(MBLOCK));
            if (n == NULL) {
                return;
            }
            *n = *b;
            UTL_insqueue(&f->q, &b->q, &n->q);
            UTL_relqueue(&f->q, &b->q);
            MEM_free(NULL, b);
            b = n;
            b->flag = 0;
        }
    }
}

int UTL_mfileputc(void *f, int c) {
    u8 ch;

    ch = c;
    return UTL_mfilewrite(f, &ch, 1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int strlen(const char *s);

int UTL_mfileputs(void *f, char *s) {
    return UTL_mfilewrite(f, s, strlen(s));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int UTL_mfilesize(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

int UTL_mfilepos(MFILE *f) {
    MBLOCK *b;
    int pos;

    pos = f->off;
    for (b = (MBLOCK *)UTL_peekqueue(&f->q, NULL); b != NULL && b != f->cur; b = (MBLOCK *)UTL_peekqueue(&f->q, &b->q)) {
        pos += b->len;
    }
    return pos;
}

void UTL_mfileseek(MFILE *f, int pos) {
    MBLOCK *b;
    int len;

    if (pos < 0) {
        pos = 0;
    }
    f->cur = (MBLOCK *)UTL_peekqueue(&f->q, NULL);
    while (f->cur->len < pos) {
        len = f->cur->len;
        pos -= len;
        b = (MBLOCK *)UTL_peekqueue(&f->q, &f->cur->q);
        if (b == NULL) {
            pos = len;
            break;
        }
        f->cur = b;
    }
    f->off = pos;
}

MFILE *UTL_mfileduplicate(MFILE *f) {
    char buf[0x200];
    MFILE *d;
    int size;
    int n;

    if (f == NULL || (d = UTL_mfilecreate(f->unk0)) == NULL) {
        return NULL;
    }
    size = UTL_mfilesize(f);
    UTL_mfileseek(f, 0);
    while (size > 0) {
        n = UTL_mfileread(f, buf, 0x200);
        if (n <= 0) {
            break;
        }
        if (UTL_mfilewrite(d, buf, n) != n) {
            UTL_mfiledelete(d);
            return NULL;
        }
        size -= n;
    }
    return d;
}

UTLWORD UTL_strword(char *p, char *skip, char *term) {
    UTLWORD w;
    char q[4];
    int i;

    while (*p != '\0') {
        for (i = 0; skip[i]; i++)
            if (*p == skip[i]) break;
        if (skip[i] == 0) break;
        p++;
    }
    if (*p == '\0') {
        w.start = p;
        w.end = p;
        return w;
    }
    if (*p == '"' || *p == '\'') {
        q[0] = *p++;
        q[1] = '\r';
        q[2] = '\n';
        q[3] = 0;
        term = q;
    }
    w.start = p;
    while (*p != '\0') {
        for (i = 0; term[i]; i++)
            if (*p == term[i]) break;
        if (term[i] != 0) break;
        p++;
    }
    w.end = p;
    return w;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int directoryCheck(void) {
    return 1;
}

char *pathMake(char *path) {
    int len;
    char *p;

    if (path == NULL) {
        return NULL;
    }
    for (len = 0; ((u8 *)path)[len] != 0 && ((u8 *)path)[len] != '?' && ((u8 *)path)[len] != '#'; len++) {
    }
    if (len == 0) {
        return NULL;
    }
    if (len > 0x800) {
        return NULL;
    }
    p = MEM_malloc(NULL, len + 1);
    if (p == NULL) {
        return NULL;
    }
    memcpy(p, path, len);
    p[len] = 0;
    return p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_gifCreateContext(void) {
    createGifContext();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_gifDestroyContext(void) {
    deleteGifContext();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_gifFinalizeContext(void) {
    initializeGifContext();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_gifInputData(void) {
    setGifBuffer();
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int IMG_gifStartDecompress(void) {
    return 1;
}

int IMG_gifGetImageData(GIFCTX *ctx, IMGDATA *info) {
    int r;

    r = GIFParser(ctx, 1);
    info->width = ctx->width;
    info->height = ctx->height;
    info->unk8 = ctx->unk1C;
    info->unk4 = ctx->unk18;
    info->unkC = 0;
    info->unk10 = ctx->unk58;
    return r;
}

int IMG_gifReadHeader(GIFCTX *ctx, IMGDATA *info) {
    int r;
    int n;

    r = GIFParser(ctx, 0);
    if (ctx->unk54 == 0) {
        return -1;
    }
    info->width = ctx->width;
    info->height = ctx->height;
    if (ctx->bs->end - ctx->bs->start <= 0) {
        return -1;
    }
    n = getFrameNumber(ctx->bs->start, ctx->bs->end - ctx->bs->start - 1);
    if (n == -1) {
        return -1;
    }
    info->unk8 = n;
    info->unk4 = 0;
    info->unkC = 0;
    info->unk10 = (int)ctx->unk54;
    return r;
}

void ESP_free(void *p);
void *ESP_malloc(int n);
void *memset(void *d, int c, unsigned int n);
void createInterlaceOrder(GIFCTX *ctx, int n);
void deleteInterlaceOrder(GIFCTX *ctx);
int getGifScanLines(GIFCTX *ctx, int n);
int getGifScanLinesInterlace(GIFCTX *ctx, int n);

int IMG_gifScanLines(GIFCTX *ctx, IMGDATA *info, int n) {
    int r;
    GIFFRAME *f;
    int *rows;

    if (ctx->unk54->height < n + ctx->lines) {
        n = ctx->unk54->height - ctx->lines;
    }
    if (n == 0) {
        goto fail;
    }
    if (ctx->unk54->buf != NULL) {
        ESP_free(ctx->unk54->buf);
    }
    f = ctx->unk54;
    if ((f->buf = ESP_malloc(f->width * n * 3)) == NULL) {
        return -2;
    }
    memset(ctx->unk54->buf, 0, ctx->unk54->width * n * 3);
    if (ctx->interlace == 1) {
        createInterlaceOrder(ctx, n);
        rows = ctx->rows;
        ctx->offset = ctx->unk54->width * rows[0] * 3;
        ctx->x = 0;
        ctx->line = 0;
        ctx->step = 1;
        ctx->unk4C = 3;
        r = getGifScanLinesInterlace(ctx, n);
        deleteInterlaceOrder(ctx);
    } else {
        ctx->offset = 0;
        ctx->x = 0;
        ctx->line = 0;
        ctx->step = ctx->interlace ? 8 : 1;
        ctx->unk4C = ctx->interlace ? 0 : 3;
        r = getGifScanLines(ctx, n);
    }
    if (r < 0) {
        goto fail;
    }
    ctx->lines += n;
    info->width = ctx->width;
    info->height = ctx->height;
    info->unk8 = 1;
    info->unk4 = 0;
    info->unkC = ctx->lines;
    info->unk10 = (int)ctx->unk54;
    return n;
fail:
    return -1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_0013234C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132350);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132354);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_0013235C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132360);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132364);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132368);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132370);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132374);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132378);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_0013237C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132384);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132388);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_0013238C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132390);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132394);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_0013239C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001323F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132404);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132410);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_0013241C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132428);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", cnt_tbl);
