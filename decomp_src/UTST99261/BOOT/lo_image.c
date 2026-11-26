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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", addImageList);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", defImage);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", noImage);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", discImage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", makeHttpHeader);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", setRequestMessageBuffer);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", setImageInBox);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", reserveGetRequest);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", countRequestedLLIST);

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
