/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nflayout.h"



typedef struct {
    int type;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
} HALTMSG;

typedef struct {
    int unk0;
    HALTMSG m;
} HALTBUF;

void GUI_Toolkit_mutexUnlock();
int OS_thread_mutex_unlock(int m);
int OS_mq_receive(int q, void *buf, int size, int flag);
void lo_sendHalt();
void proc_msg_PL2(HALTMSG *m);
void proc_msg_JL3(HALTMSG *m);
extern int jsapi_lock;

void lo_halt(void) {
    HALTBUF buf;
    HALTMSG m;
    int q;
    int *nda;

    GUI_Toolkit_mutexUnlock();
    nda = gESPRIT_LO_GLOBAL_NDA;
    if (nda[0x10] != 0) {
        OS_thread_mutex_unlock(nda[0x10]);
    }
    if (jsapi_lock != 0) {
        OS_thread_mutex_unlock(jsapi_lock);
    }
    lo_sendHalt();
    GUI_Toolkit_mutexUnlock();
    q = (*(int *)((char *)&lo_global + 0x80));
    do {
        if (OS_mq_receive(q, &buf, 0x24, 0) == 0xB) {
            break;
        }
        nda = gESPRIT_LO_GLOBAL_NDA;
        if (nda[0x10] != 0) {
            OS_thread_mutex_unlock(nda[0x10]);
        }
        m = buf.m;
    } while (m.type != 2 || m.unkC != 0x302);
    proc_msg_PL2(&m);
    do {
        if (OS_mq_receive(q, &buf, 0x24, 0) == 0xB) {
            break;
        }
        nda = gESPRIT_LO_GLOBAL_NDA;
        if (nda[0x10] != 0) {
            OS_thread_mutex_unlock(nda[0x10]);
        }
        m = buf.m;
    } while (m.type != 8 || m.unkC != 0x803);
    proc_msg_JL3(&m);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", esp_loThread);

void initBoxList(LIST *list) {
    LISTNODE *n;
    LISTNODE *next;

    for (n = list->head; n != NULL; n = next) {
        next = n->next;
        MEM_free(NULL, n);
    }
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

void addBoxList(LIST *list, void *data) {
    LISTNODE *n;
    LISTNODE *tail;

    n = MEM_malloc(NULL, sizeof(LISTNODE));
    n->next = NULL;
    n->prev = NULL;
    n->data = NULL;
    tail = list->tail;
    if (tail != NULL) {
        tail->next = n;
        n->prev = tail;
    } else {
        list->head = n;
    }
    list->tail = n;
    n->data = data;
    list->count++;
}

void delBoxList(LIST *list, void *data) {
    LISTNODE *n;
    LISTNODE *prev;
    LISTNODE *next;

    for (n = list->head; n != NULL; n = n->next) {
        if (n->data == data) {
            prev = n->prev;
            next = n->next;
            if (prev != NULL) {
                if (next != NULL) {
                    prev->next = next;
                    next->prev = prev;
                } else {
                    prev->next = NULL;
                    list->tail = prev;
                }
            } else if (next != NULL) {
                next->prev = NULL;
                list->head = next;
            } else {
                list->head = NULL;
                list->tail = NULL;
            }
            list->count--;
            MEM_free(NULL, n);
            return;
        }
    }
}

void delBoxLastList(LIST *list) {
    LISTNODE *n;
    LISTNODE *prev;

    n = list->tail;
    if (n != NULL) {
        prev = n->prev;
        if (prev == NULL) {
            list->head = NULL;
            list->tail = NULL;
        } else {
            list->tail = prev;
            prev->next = NULL;
        }
        MEM_free(NULL, n);
        list->count--;
    }
}

void divideBoxList(LIST *list, LIST *out, void *data) {
    LISTNODE *n;
    LISTNODE *prev;

    n = list->head;
    while (n != NULL && n->data != data) {
        n = n->next;
    }
    if (n != NULL) {
        prev = n->prev;
        if (prev != NULL) {
            prev->next = NULL;
            n->prev = NULL;
        } else {
            list->head = NULL;
        }
        list->tail = prev;
        out->head = n;
        while (n->next != NULL) {
            n = n->next;
        }
        out->tail = n;
    }
}

void initUrlList(LIST *list) {
    LISTNODE *n;
    LISTNODE *next;

    n = list->head;
    if (n != NULL) {
        next = n->next;
        goto check;
        for (;;) {
            MEM_free(NULL, n);
            if (next == NULL)
                break;
            n = next;
            next = n->next;
check:
            if (n->data != NULL)
                MEM_free(NULL, n->data);
        }
    }
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/layoutMain", searchUrlList);

int addUrlList(LIST *list, char *url) {
    LISTNODE *n;
    LISTNODE *p;
    LISTNODE *last;
    LISTNODE *h;

    if (searchUrlList(list, url) != 0) {
        return 0;
    }
    if (list->count >= 256) {
        last = list->tail;
        p = last->prev;
        list->tail = p;
        if (p != NULL) {
            p->next = NULL;
        }
        if (last->data != NULL) {
            MEM_free(NULL, last->data);
        }
        MEM_free(NULL, last);
        list->count--;
    }
    n = MEM_malloc(NULL, sizeof(LISTNODE));
    n->next = NULL;
    n->prev = NULL;
    n->data = NULL;
    h = list->head;
    if (h != NULL) {
        h->prev = n;
        n->next = h;
        list->head = n;
    } else {
        list->head = n;
        list->tail = n;
    }
    n->data = url;
    list->count++;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void copyBoxList(LIST *dst, LIST *src) {
    LISTNODE *n;

    initBoxList(dst);
    for (n = src->head; n != NULL; n = n->next) {
        addBoxList(dst, n->data);
    }
}

char *lo_fullUrl(BOX *box, char *url) {
    char *full;

    full = URL_toAbsoluteURL(*(char **)((u8 *)getBodyBox(box)->geom + 0x28), url);
    MEM_free(NULL, url);
    return full;
}

BOX *lo_getActiveFrameBodybox(void) {
    HISTNODE *h;
    BOX *box;
    int *nda;

    nda = gESPRIT_LO_GLOBAL_NDA;
    if (*nda == 0) {
        return NULL;
    }
    h = HST_searchSessionIDHistoryNode(*nda);
    if (h == NULL) {
        return NULL;
    }
    box = h->body;
    if (box == NULL) {
        return NULL;
    }
    if (checkBoxValidity(box) != 0) {
        return box;
    }
    return NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initSessionNumber(void) {
    lo_global.session = 0x08000001;
}

int getSessionNumber(void) {
    if (++lo_global.session > 0x10000000) {
        lo_global.session = 0x08000001;
    }
    return lo_global.session;
}

void setUiGlobal_window(void) {
    int i;
    int j;
    int k;

    k = 0;
    ui_ins = gBEINSI_UI;
    if (ui_ins != NULL) {
        ui_global = MEM_malloc(NULL, sizeof(UIGLOBAL));
        ui_global->unk90 = ui_ins->unk74;
        ui_global->unk94 = ui_ins->unk70;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 7; j++) {
                ui_global->color[i][j] = ui_ins->color[k];
                k++;
            }
        }
    }
}

int GUI_Graphics_getStringSize(int font, char *s, int len, int *w, int *h);

void setUiGlobal_browser(void) {
    PREFUI *pref;
    int w;
    int h;
    int mode;

    pref = gPREF_UI;
    if (pref == NULL) {
        return;
    }
    ui_global->font = pref->unk24;
    if (ui_global->font > 6) {
        ui_global->font = 6;
    }
    if (ui_global->font < 0) {
        ui_global->font = 0;
    }
    GUI_Graphics_getStringSize(ui_global->color[0][ui_global->font], "m", 1, &w, &h);
    ui_global->unk74 = w;
    ui_global->unk78 = pref->unk4C;
    mode = pref->unk10;
    switch (mode) {
    case 0:
        ui_global->unk7C = 25;
        break;
    case 1:
        ui_global->unk7C = 50;
        break;
    case 2:
        ui_global->unk7C = 75;
        break;
    default:
        ui_global->unk7C = 100;
        break;
    }
    ui_global->unk80 = mode;
    ui_global->unk84 = pref->unk48;
    ui_global->unk88 = pref->unk50;
    ui_global->unk8C = pref->unk54;
    ui_global->unk98 = pref->unk58;
}

void setLoGlobal(void) {
    PREFUI *pref;

    pref = gPREF_UI;
    lo_global.flags |= 1;
    lo_global.unk54 = 0;
    lo_global.unk68 = pref->unk24;
    lo_global.unk6C = pref->unk24;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int getRNDSEM(void) {
    return gESPRIT_LO_GLOBAL_NDA[15];
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int getJSSEM(void) {
    return gESPRIT_LO_GLOBAL_NDA[16];
}
