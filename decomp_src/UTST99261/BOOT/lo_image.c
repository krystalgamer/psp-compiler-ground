/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
#include "UTST99261/BOOT/nflayout.h"

typedef struct LNODE {
    struct LNODE *next;
    struct LNODE *prev;
    struct LNODE *child;        /* 0x8 */
    int state;                  /* 0xC */
    int unk10;
    int unk14;
    int unk18;
    int doc;                    /* 0x1C */
    void *data;                 /* 0x20 */
    int unk24;
    int session;                /* 0x28 */
    int unk2C[5];
    struct LURL *url;           /* 0x40 */
} LNODE;

typedef struct LURL {
    u8 unk0[0x10];
    int len;                    /* 0x10 */
    char *str;                  /* 0x14 */
} LURL;

int memcmp(const void *a, const void *b, unsigned int n);

typedef struct {
    int count;
    LNODE *head;
    LNODE *tail;
} LLIST;

typedef struct IMGENT {
    struct IMGENT *next;
    int unk4;
    int unk8;
    char *name;                 /* 0xC */
    void *image;                /* 0x10 */
    int unk14;
    int type;                   /* 0x18 */
    LIST boxes;                 /* 0x1C */
} IMGENT;

typedef struct {
    int unk0;
    int unk4;
    IMGENT *head;               /* 0x8 */
    int unkC;
} IMGLIST;

typedef struct {
    int unk0;
    int session;                /* 0x4 */
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int len;                    /* 0x18 */
    void *data;                 /* 0x1C */
} LOMSG;

typedef struct {
    int len;
    char *str;
} LURLSTR;

extern LIST D_00584CF0;
int addUrlList(LIST *list, char *url);
void *MEM_malloc(void *pool, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
IMGENT *checkImageList(IMGLIST *list, char *name);
void imageDecodeFailure(IMGENT *e);
void setImageToBoxBuffer(BOX *b, void *image);
void rnd_removeAnimBoxnode(BOX *b);
int rnd_gdrawImageProperty(void *img, int *w, int *h);
void rnd_addAnimBoxnode(BOX *b, BOX *body);
void delLLISTByDocumentSession(LLIST *list, int doc);
typedef struct {
    u8 unk0[0x48];
    int sid;                    /* 0x48 */
} LHIST;
LHIST *HST_getChildHistoryNode(LHIST *h);
LHIST *HST_getSiblingHistoryNode(LHIST *h);
LHIST *HST_getParentHistoryNode(LHIST *h);
void *imageDecode(const u8 *data, int size, int a, int b, int c);
extern const u8 defImage[];
extern const u8 noImage[];
extern const u8 discImage[];
extern const u8 circleImage[];
extern const u8 squareImage[];
typedef struct {
    u8 unk0[0x14];
    int state;                  /* 0x14 */
    u8 unk18[0xC];
    IMGENT *ent;                /* 0x24 */
} LIMGGEOM;

extern LLIST REQUEST_LLIST;
void imageDelete(void *image);
void delLLIST(LLIST *list, LNODE *n);



#ifndef NULL
#define NULL ((void *)0)
#endif
int getRestImageTotalSquareSize(void) {
    return -1;
}

void incrementImageTotalSquareSize(void) {
}

void addBoxList();
void delBoxList();
unsigned int strlen(const char *s);
char *strcpy(char *d, const char *s);

void addImageList(IMGLIST *list, BOX *box, char *name) {
    IMGENT *e;
    char *s;
    IMGENT *tail;

    if (box->content == 10 && ((IMGENT **)box->geom)[9] != NULL) {
        delBoxList(&((IMGENT **)box->geom)[9]->boxes, box);
    }
    for (e = list->head; e != NULL; e = e->next) {
        if (strcmp(name, e->name) == 0) {
            break;
        }
    }
    if (e != NULL) {
        addBoxList(&e->boxes, box);
    } else {
        e = MEM_malloc(0, 0x28);
        e->next = NULL;
        e->unk4 = 0;
        e->unk8 = 0;
        e->name = NULL;
        e->image = NULL;
        e->unk14 = 0;
        e->type = 0;
        e->boxes.head = NULL;
        e->boxes.tail = NULL;
        e->boxes.count = 0;
        tail = (IMGENT *)list->unkC;
        if (tail != NULL) {
            tail->next = e;
            e->unk4 = (int)tail;
        } else {
            list->head = e;
        }
        list->unkC = (int)e;
        addBoxList(&e->boxes, box);
        s = MEM_malloc(0, strlen(name) + 1);
        strcpy(s, name);
        e->name = s;
        list->unk0++;
    }
    if (box->content == 10) {
        ((IMGENT **)box->geom)[9] = e;
    }
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", defImage);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", noImage);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", discImage);

int sprintf(char *buf, const char *fmt, ...);

char *makeHttpHeader(char *ref, char *user, char *pass) {
    unsigned int rl;
    unsigned int al;
    char *p;

    al = 0;
    rl = 0;
    p = NULL;
    if (ref != NULL) {
        rl = strlen(ref);
    }
    if (user != NULL) {
        al = strlen(user);
        if (pass != NULL) {
            al += strlen(pass);
        }
    }
    if (rl != 0 || al != 0) {
        if (al != 0) {
            if (rl != 0) {
                p = MEM_malloc(0, rl + al + 0x22);
                sprintf(p, "Referer: %s\nAuthorization: Basic %s:%s\n", ref, user, pass);
            } else {
                p = MEM_malloc(0, rl + al + 0x18);
                sprintf(p, "Authorization: Basic %s:%s\n", user, pass);
            }
        } else if (rl != 0) {
            p = MEM_malloc(0, rl + al + 0xB);
            sprintf(p, "Referer: %s\n", ref);
        }
    }
    return p;
}

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int urllen;                 /* 0x10 */
    char *url;                  /* 0x14 */
    int hdrlen;                 /* 0x18 */
    char *hdr;                  /* 0x1C */
    int unk20;
    int unk24;
} LREQ;
char *makeHttpHeader(char *ref, char *user, char *pass);
unsigned int strlen(const char *s);

int setRequestMessageBuffer(void **out, char *url, int a, int b, char *ref, char *user, char *pass) {
    LREQ r = {a, b};
    char *hdr;
    int size;
    char *buf;

    r.urllen = strlen(url);
    hdr = makeHttpHeader(ref, user, pass);
    r.hdrlen = hdr != NULL ? strlen(hdr) : 0;
    size = r.urllen + r.hdrlen + 0x28;
    buf = *out = MEM_malloc(0, size);
    r.url = buf + 0x28;
    r.hdr = r.hdrlen != 0 ? r.url + r.urllen : NULL;
    memcpy(buf, &r, sizeof(r));
    buf = (char *)*out + 0x28;
    memcpy(buf, url, r.urllen);
    buf += r.urllen;
    memcpy(buf, hdr, r.hdrlen);
    MEM_free(0, hdr);
    return size;
}

void setImageToBoxBuffer(BOX *b, void *image) {
    int w;
    int h;

    if (b == NULL) {
        return;
    }
    switch (b->content) {
    case 0:
        if (b->display != 0) {
            break;
        }
    case 1:
    case 4:
    case 6:
        ((void **)b->style)[1] = image;
        break;
    case 10:
        ((void **)b->geom)[0] = image;
        rnd_removeAnimBoxnode(b);
        if (rnd_gdrawImageProperty(image, &w, &h) == 1) {
            rnd_addAnimBoxnode(b, getBodyBox(b));
        }
        break;
    }
}

BOX *getParentBlockBox(BOX *b);
int getContainingBlockWidth(BOX *b);

int setImageInBox(BOX *b, void *img, int w, int h) {
    int *g;
    int *st;
    int ow;
    int oh;
    int nw;
    int nh;
    int f;
    int changed;
    BOX *p;

    changed = 0;
    setImageToBoxBuffer(b, img);
    if (b->content != 10) {
        return 0;
    }
    getContainingBlockWidth(getParentBlockBox(b));
    g = (int *)b->geom;
    ow = g[1];
    oh = g[2];
    nw = w;
    st = (int *)b->style;
    f = st[5];
    nh = h;
    if ((f & 3) == 1) {
        nw = st[6];
        if ((((u32)f & 0xC) >> 2) == 1) {
            nh = st[7];
        } else if (!(st[5] & 0xC)) {
            nh = h * st[6] / w;
        }
    } else if (((((u32 *)b->style)[5] & 0xC) >> 2) == 1) {
        nh = ((int *)b->style)[7];
        if (!(((int *)b->style)[5] & 3)) {
            nw = w * nh / h;
        }
    } else if (!(((int *)b->style)[5] & 3)) {
        if (!(((int *)b->style)[5] & 0xC)) {
            nw = w;
            nh = h;
        }
    }
    ((int *)b->geom)[3] = w;
    ((int *)b->geom)[4] = h;
    ((int *)b->geom)[1] = nw;
    ((int *)b->geom)[2] = nh;
    if (ow != nw || oh != nh) {
        for (p = b->parent; p != NULL; p = p->parent) {
            if (p->content == 4 || p->content == 6) {
                ((u16 *)p)[0x20] |= 1;
            }
        }
        changed = 1;
        ((u16 *)b)[0x20] |= 4;
    }
    return changed;
}

void imageProperty(void *img, int *w, int *h);
int setImageInBox(BOX *b, void *img, int w, int h);
void relayoutAtBody(BOX *body, int f);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", imageDecodeSuccess);

void imageDecodeFailure(IMGENT *e) {
    LISTNODE *p;
    BOX *b;

    for (p = e->boxes.head; p != NULL; p = p->next) {
        b = p->data;
        if (b->content == 10 && (((LIMGGEOM *)b->geom)->state != 1 || ((LIMGGEOM *)b->geom)->ent == e)) {
            setImageToBoxBuffer(p->data, lo_global.img18);
            ((LIMGGEOM *)((BOX *)p->data)->geom)->state = 2;
        }
    }
    e->type = 2;
}

void initDefaultImage(void) {
    lo_global.img14 = imageDecode(defImage, 0xCB, 0, 0, 0);
    lo_global.img18 = imageDecode(noImage, 0x59, 0, 0, 0);
    lo_global.img24 = imageDecode(discImage, 0x42, 0, 0, 0);
    lo_global.img28 = imageDecode(circleImage, 0x47, 0, 0, 0);
    lo_global.img2C = imageDecode(squareImage, 0x45, 0, 0, 0);
}

void deleteDefaultImage(void) {
    imageDelete(lo_global.img14);
    imageDelete(lo_global.img18);
    imageDelete(lo_global.img24);
    imageDelete(lo_global.img28);
    imageDelete(lo_global.img2C);
}

void initImageList(IMGLIST *list) {
    IMGENT *e;
    IMGENT *next;

    for (e = list->head; e != NULL; e = next) {
        next = e->next;
        if (e->type == 1) {
            imageDelete(e->image);
        }
        if (e->name != NULL) {
            MEM_free(NULL, e->name);
        }
        initBoxList(&e->boxes);
        MEM_free(NULL, e);
    }
    list->head = NULL;
    list->unkC = 0;
    list->unk4 = 0;
    list->unk0 = 0;
}

LNODE *make_msg_LI1();
int getSessionNumber();
int setRequestMessageBuffer();

void reserveGetRequest(int a0, char *url, int doc, int a3, int a4, int a5, int a6, int a7) {
    LNODE *n;
    LOMSG *m;
    void *buf;
    int cnt;

    n = make_msg_LI1();
    n->doc = doc;
    n->unk18 = a0;
    m = (LOMSG *)&n->unk24;
    m->session = getSessionNumber();
    m->unk8 = 0;
    if (a3 == 1) {
        m->unk10 = 2;
    } else {
        m->unk10 = a4 ? 3 : 0;
    }
    cnt = countRequestedLLIST(&REQUEST_LLIST, doc) + 1;
    m->len = setRequestMessageBuffer(&buf, url, cnt, cnt, a5, a6, a7);
    m->data = buf;
    n->data = MEM_malloc(0, strlen(url) + 1);
    strcpy(n->data, url);
    putLLIST(&REQUEST_LLIST, n);
}

IMGENT *checkImageList(IMGLIST *list, char *name) {
    IMGENT *e;

    for (e = list->head; e != NULL; e = e->next) {
        if (strcmp(name, e->name) == 0) {
            break;
        }
    }
    return e;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", requestImageData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", setImageData);

int setBrokenImageData(LNODE *n, BOX *doc) {
    char *name;
    BOX *body;
    IMGENT *e;

    name = n->data;
    if (name == NULL) {
        return -1;
    }
    body = getBodyBox(doc);
    if (body == NULL) {
        return -1;
    }
    e = checkImageList((IMGLIST *)((u8 *)body->geom + 0x54), name);
    if (e == NULL) {
        return -1;
    }
    e->unk8 = 1;
    imageDecodeFailure(e);
    e->image = NULL;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", calcHttpHeaderSize);

#ifndef NULL
#define NULL ((void *)0)
#endif
void initLLIST(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0) = 0;
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 8) = 0;
    }
}

void putLLIST(LLIST *list, LNODE *n) {
    LNODE *tail;

    if (list == NULL || n == NULL) {
        return;
    }
    if (list->head == NULL) {
        list->head = n;
        list->tail = n;
        n->prev = NULL;
        n->next = NULL;
    } else {
        tail = list->tail;
        list->tail = n;
        n->prev = tail;
        n->next = NULL;
        tail->next = n;
    }
    list->count++;
}

void delLLIST(LLIST *list, LNODE *n) {
    LNODE *c;
    LNODE *next;
    LNODE *prev;
    LNODE *nx;

    if (list == NULL || list->head == NULL || n == NULL) {
        return;
    }
    if (n->child != NULL) {
        c = n->child;
        while (c != NULL) {
            nx = c;
            c = c->next;
            if (nx->data != NULL) {
                MEM_free(NULL, nx->data);
            }
            MEM_free(NULL, nx);
        }
        n->child = NULL;
    }
    prev = n->prev;
    next = n->next;
    if (prev == NULL) {
        if (next == NULL) {
            list->head = NULL;
            list->tail = NULL;
        } else {
            list->head = next;
            next->prev = NULL;
        }
    } else if (next == NULL) {
        prev->next = NULL;
        list->tail = prev;
    } else {
        prev->next = next;
        next->prev = prev;
    }
    list->count--;
}

void putChildLLIST(LNODE *parent, LNODE *n) {
    LNODE *c;

    if (parent == NULL || n == NULL) {
        return;
    }
    c = parent->child;
    if (c != NULL) {
        while (c->next != NULL) {
            c = c->next;
        }
        c->next = n;
        n->prev = c;
    } else {
        parent->child = n;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", getNextLLIST);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", searchLLISTByURL);

LNODE *searchLLISTBySESSION(LLIST *list, int session) {
    LNODE *n;
    int i;

    if (list == NULL) {
        return NULL;
    }
    n = list->head;
    if (n == NULL) {
        return NULL;
    }
    for (i = 0; i < list->count; i++) {
        if (n->session == session) {
            return n;
        }
        n = n->next;
        if (n == NULL) {
            break;
        }
    }
    return NULL;
}

int checkRecieveLLIST(LLIST *list) {
    LNODE *n;
    int i;

    if (list == NULL) {
        return 0;
    }
    n = list->head;
    if (n == NULL) {
        return 0;
    }
    for (i = 0; i < list->count; i++) {
        if (n->state == 5) {
            n = n->next;
            continue;
        }
        if (n->unk14 == 0) {
            return 1;
        }
        n = n->next;
        if (n == NULL) {
            break;
        }
    }
    return 0;
}

int checkNoReceiveLLIST(LLIST *list, int doc) {
    LNODE *n;
    int i;

    if (list == NULL) {
        return 0;
    }
    for (n = list->head, i = 0; i < list->count && n != NULL; n = n->next, i++) {
        if (n->unk18 != 0 && n->unk14 == 0 && n->doc == doc) {
            return 1;
        }
    }
    return 0;
}

void delLLISTByDocumentSession(LLIST *list, int doc) {
    LNODE *n;
    LNODE *next;

    if (list == NULL) {
        return;
    }
    for (n = list->head; n != NULL; n = next) {
        next = n->next;
        if (doc == 0 || n->doc == doc) {
            delLLIST(list, n);
            if (n->data != NULL) {
                MEM_free(NULL, n->data);
            }
            MEM_free(NULL, n);
        }
    }
}

void delLLISTByHistoryTree(LLIST *list, LHIST *root) {
    LHIST *h;
    LHIST *n;

    h = HST_getChildHistoryNode(root);
    while (h != NULL) {
        if (h->sid != 0) {
            delLLISTByDocumentSession(list, h->sid);
        }
        n = HST_getChildHistoryNode(h);
        if (n == NULL) {
            n = HST_getSiblingHistoryNode(h);
            if (n == NULL) {
                h = HST_getParentHistoryNode(h);
                if (h == root) {
                    return;
                }
                do {
                    n = HST_getSiblingHistoryNode(h);
                    if (n != NULL) {
                        break;
                    }
                    h = HST_getParentHistoryNode(h);
                } while (h != root);
                if (h == root) {
                    return;
                }
            }
        }
        h = n;
    }
}

int countRequestedLLIST(LLIST *list, int doc) {
    LNODE *n;
    int i;
    int count;

    if (list == NULL) {
        return 0;
    }
    n = list->head;
    if (n == NULL) {
        return 0;
    }
    for (i = 0, count = 0; i < list->count; i++) {
        if (n->doc == doc) {
            count++;
        }
        n = n->next;
        if (n == NULL) {
            break;
        }
    }
    return count;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", msgBranch);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", proc_msg_IL1);

void proc_msg_IL2(void) {
}

void proc_msg_IL3(LOMSG *msg) {
    LNODE *n;

    n = searchLLISTBySESSION(&REQUEST_LLIST, msg->session);
    if (n != NULL) {
        delLLIST(&REQUEST_LLIST, n);
        if (n->data != NULL) {
            MEM_free(NULL, n->data);
        }
        MEM_free(NULL, n);
        MEM_free(NULL, msg->data);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", proc_msg_IL4);

void proc_msg_IL5(LOMSG *m) {
    LURLSTR *d;
    char *s;

    if (m->unk10 == -1) {
        d = m->data;
        s = MEM_malloc(NULL, d->len + 1);
        memcpy(s, d->str, d->len);
        s[d->len] = 0;
        if (addUrlList(&D_00584CF0, s) != 1) {
            MEM_free(NULL, s);
        }
    }
    if (m->len > 0) {
        MEM_free(NULL, m->data);
    }
}
