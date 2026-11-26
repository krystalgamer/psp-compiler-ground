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
    GIFBS *bs;
    u16 width;          /* 0x4 */
    u16 height;
    u8 unk8[0x10];
    int unk18;
    int unk1C;
    u8 unk20[0x34];
    int unk54;
    int unk58;
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


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", trimspace);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001322F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001322F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_001322FC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", toAbsoluteURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_new);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_toString);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_encode);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_guessMIMETypeFromName);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_strword);

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
    info->unk10 = ctx->unk54;
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", IMG_gifScanLines);

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
