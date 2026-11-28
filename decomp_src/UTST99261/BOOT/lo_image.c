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

int addUrlList(LIST *list, char *url);
void *MEM_malloc(void *pool, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
IMGENT *checkImageList(IMGLIST *list, char *name);
void imageDecodeFailure(IMGENT *e);
void setImageToBoxBuffer(BOX *b, void *image);
void rnd_removeAnimBoxnode(BOX *b);
int rnd_gdrawImageProperty(void *img, int *w, int *h);
int rnd_addAnimBoxnode(BOX *b, BOX *body);
void delLLISTByDocumentSession(LLIST *list, int doc);
typedef struct {
    u8 unk0[0x48];
    int sid;                    /* 0x48 */
} LHIST;
LHIST *HST_getChildHistoryNode(LHIST *h);
LHIST *HST_getSiblingHistoryNode(LHIST *h);
LHIST *HST_getParentHistoryNode(LHIST *h);
void *imageDecode();
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
int OS_timer_stop();
int OS_timer_start();
void proc_msg_PL1();
void proc_msg_PL2();
void proc_msg_PL3();
void proc_msg_PL4();
void proc_msg_PL5();
void proc_msg_PL6();
void proc_msg_PL7();
void proc_msg_PL8();
void proc_msg_PL11();
void proc_msg_PL13();
void proc_msg_PL15();
void proc_msg_PL16();
void proc_msg_PL17();
void proc_msg_PL18();
void proc_msg_PL19();
void proc_msg_IL1();
void proc_msg_IL2();
void proc_msg_IL3();
void proc_msg_IL4();
void proc_msg_IL5();
void proc_msg_JL1();
void proc_msg_JL2();
void proc_msg_JL3();
void proc_msg_JL4();
void proc_msg_JL5();
void proc_msg_JL6();
void proc_msg_JL7();
void proc_msg_JL8();
void proc_msg_JL9();
void proc_msg_JL10();
void proc_msg_JL11();
void proc_msg_JL12();
void proc_msg_JL13();
void proc_msg_JL14();
void proc_msg_JL15();
void proc_msg_TM();
int countRequestedLLIST(LLIST *list, int doc);
void putLLIST(LLIST *list, LNODE *n);
int getRestImageTotalSquareSize(IMGLIST *list) {
    return -1;
}

void incrementImageTotalSquareSize(IMGLIST *list) {
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

int setBrokenImageData(LNODE *n, BOX *doc);

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

int calcHttpHeaderSize(char *s, int len) {
    int i;
    for (i = 0; i < len;) {
        if (s[i++] == '\r' && s[i++] == '\n' && s[i++] == '\r') {
            if (s[i] == '\n') {
                return i + 1;
            }
            i++;
        }
    }
    for (i = 0; i < len;) {
        if (s[i++] == '\n') {
            if (s[i] == '\n') {
                return i + 1;
            }
            i++;
        }
    }
    return 0;
}

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

void msgBranch(LOMSG *msg) {
    if (lo_global.flags & 0x10) {
        if (msg->unk0 != 8) {
            return;
        }
        if (msg->unkC != 0x803 && msg->unkC != 0x809) {
            return;
        }
    }
    switch (msg->unk0) {
    case 2:
        switch (msg->unkC) {
        case 0x301:
            proc_msg_PL1(msg);
            break;
        case 0x302:
            proc_msg_PL2(msg);
            break;
        case 0x303:
            OS_timer_stop(lo_global.timer);
            proc_msg_PL3(msg);
            OS_timer_start(lo_global.timer);
            break;
        case 0x304:
            proc_msg_PL4(msg);
            break;
        case 0x305:
            OS_timer_stop(lo_global.timer);
            proc_msg_PL5(msg);
            OS_timer_start(lo_global.timer);
            break;
        case 0x306:
            proc_msg_PL6(msg);
            break;
        case 0x307:
            proc_msg_PL7(msg);
            break;
        case 0x308:
            proc_msg_PL8(msg);
            break;
        case 0x30B:
            proc_msg_PL11(msg);
            break;
        case 0x30D:
            proc_msg_PL13(msg);
            break;
        case 0x30F:
            proc_msg_PL15(msg);
            break;
        case 0x310:
            proc_msg_PL16(msg);
            break;
        case 0x311:
            proc_msg_PL17(msg);
            break;
        case 0x312:
            proc_msg_PL18(msg);
            break;
        case 0x313:
            proc_msg_PL19(msg);
            break;
        }
        break;
    case 5:
        switch (msg->unkC) {
        case 0x501:
            proc_msg_IL1(msg);
            break;
        case 0x502:
            proc_msg_IL2(msg);
            break;
        case 0x503:
            proc_msg_IL3(msg);
            break;
        case 0x504:
            proc_msg_IL4(msg);
            break;
        case 0x506:
            proc_msg_IL5(msg);
            break;
        }
        break;
    case 8:
        switch (msg->unkC) {
        case 0x801:
            proc_msg_JL1(msg);
            break;
        case 0x802:
            proc_msg_JL2(msg);
            break;
        case 0x803:
            proc_msg_JL3(msg);
            break;
        case 0x804:
            proc_msg_JL4(msg);
            break;
        case 0x805:
            proc_msg_JL5(msg);
            break;
        case 0x806:
            proc_msg_JL6(msg);
            break;
        case 0x807:
            proc_msg_JL7(msg);
            break;
        case 0x808:
            if (!(lo_global.flags & 0x20)) {
                proc_msg_JL8(msg);
            }
            break;
        case 0x809:
            proc_msg_JL9(msg);
            break;
        case 0x80A:
            proc_msg_JL10(msg);
            break;
        case 0x80B:
            proc_msg_JL11(msg);
            break;
        case 0x80C:
            proc_msg_JL12(msg);
            break;
        case 0x80D:
            proc_msg_JL13(msg);
            break;
        case 0x80E:
            proc_msg_JL14(msg);
            break;
        case 0x80F:
            proc_msg_JL15(msg);
            break;
        }
        break;
    case 9:
        proc_msg_TM(msg);
        break;
    }
}

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

typedef struct {
    u8 unk0[0x30];
} LJSEVENT;
void initJSEvent(LJSEVENT *ev, int type, int node, int a, int b);
void sendJSEvent(int obj, LJSEVENT *ev);
int Node_getJSObj(int node);
int isLoadedAllChild(HISTNODE *h);
int GUI_ScrollPane_setScrollPosition(int w, int x, int y);
LNODE *make_msg_LP4(int sid, int w, int h);
LNODE *make_msg_LP21(int sid, BOX *body);
int drawPaint(BOX *b);
int drawObject(BOX *b);

void proc_msg_IL4(LOMSG *msg) {
    LNODE *n;
    HISTNODE *h;
    BOX *box;
    BOX *body;
    IMGENT *e;
    LISTNODE *l;
    LJSEVENT ev;
    HISTNODE *p;
    BOX *pb;

    n = searchLLISTBySESSION(&REQUEST_LLIST, msg->session);
    if (n == NULL) {
        goto end;
    }
    h = HST_searchSessionIDHistoryNode(n->doc);
    if (h == NULL || h->body == NULL || !checkBoxValidity(h->body)) {
        goto del;
    }
    n->unk14 = 1;
    box = (BOX *)n->unk18;
    if (box == NULL) {
        goto del;
    }
    body = getBodyBox(box);
    if (body == NULL) {
        goto end;
    }
    if (box->content == 10 && setBrokenImageData(n, box) == 0
        && (e = checkImageList((IMGLIST *)((u8 *)body->geom + 0x54), n->data)) != NULL) {
        for (l = e->boxes.head; l != NULL; l = l->next) {
            if (((BOX *)l->data)->content == 10 && ((int *)((BOX *)l->data)->geom)[5] == 2) {
                initJSEvent(&ev, 7, ((int *)l->data)[0xA], 0, 0);
                sendJSEvent(Node_getJSObj(((int *)l->data)[0xA]), &ev);
            }
        }
    }
    if (((int *)body->geom)[0x10] == 2 && checkNoReceiveLLIST(&REQUEST_LLIST, ((int *)body->geom)[0xE]) == 0) {
        for (p = h; p != NULL; p = (HISTNODE *)HST_getParentHistoryNode((LHIST *)p)) {
            if (!isLoadedAllChild(p)) {
                break;
            }
            pb = p->body;
            initJSEvent(&ev, 0xC, ((int *)pb)[0xA], 0, 0);
            sendJSEvent(Node_getJSObj(((int *)pb)[0xA]), &ev);
        }
        if (((int *)body->geom)[6] != 0 || ((int *)body->geom)[7] != 0) {
            GUI_ScrollPane_setScrollPosition(((int *)body)[0xB], ((int *)body->geom)[6], ((int *)body->geom)[7]);
        }
        lo_global.flags &= ~8;
        putLLIST(&REQUEST_LLIST, make_msg_LP4(n->doc, ((int *)body->geom)[2], ((int *)body->geom)[3]));
        putLLIST(&REQUEST_LLIST, make_msg_LP21(n->doc, body));
        ((int *)body->geom)[0x10] = 3;
        drawPaint(body);
    }
    drawObject(box);
del:
    delLLIST(&REQUEST_LLIST, n);
    if (n->data != NULL) {
        MEM_free(NULL, n->data);
    }
    MEM_free(NULL, n);
end:
    MEM_free(NULL, msg->data);
}

void proc_msg_IL5(LOMSG *m) {
    LURLSTR *d;
    char *s;

    if (m->unk10 == -1) {
        d = m->data;
        s = MEM_malloc(NULL, d->len + 1);
        memcpy(s, d->str, d->len);
        s[d->len] = 0;
        if (addUrlList(&(*(LIST *)((char *)&lo_global + 0x58)), s) != 1) {
            MEM_free(NULL, s);
        }
    }
    if (m->len > 0) {
        MEM_free(NULL, m->data);
    }
}
