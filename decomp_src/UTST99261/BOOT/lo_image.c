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
} LNODE;

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
    u8 unk8[0x14];
    void *data;                 /* 0x1C */
} LOMSG;

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", setImageToBoxBuffer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", setImageInBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", imageDecodeSuccess);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", imageDecodeFailure);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", initDefaultImage);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", setBrokenImageData);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", delLLIST);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", checkRecieveLLIST);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", checkNoReceiveLLIST);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", delLLISTByHistoryTree);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_image", proc_msg_IL5);
