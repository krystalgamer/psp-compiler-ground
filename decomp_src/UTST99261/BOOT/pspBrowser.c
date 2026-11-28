/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
#include "UTST99261/BOOT/pspBrowser.h"
#include "UTST99261/BOOT/nfgui.h"

typedef struct { /* size 0xD8 */
    int unk0;
    int flags;
    int unk8;
    int widget;                                 /* 0xC */
    void *unk10;
    void *unk14;
    PSPBROWSER_INI ini;                         /* 0x18 */
    u8 unk7C[8];
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    char *unk94;
    void *unk98;
    PSPBROWSER_FOCUS_CALLBACK focusCallback;    /* 0x9C */
    int unkA0;
    PSPBROWSER_UNLOAD_CALLBACK unloadCallback;  /* 0xA4 */
    int unkA8;
    struct PURL *anchorUrl;                     /* 0xAC */
    u8 anchorExt[8];                            /* 0xB0 */
    u8 imageReq[8];                             /* 0xB8 */
    u8 imageExt[8];                             /* 0xC0 */
    void *unkC8;
    int unkCC;
    void **unkD0;                               /* 0xD0 */
    int mutex;                                  /* 0xD4 */
} PSPBROWSER_INSTANCE;

extern PSPBROWSER_INSTANCE pspBrowserInstance;
extern int _i_windsystemOn;
int zWindSetSetFocusCallback(PSPBROWSER_FOCUS_CALLBACK callback);
int ucs2ToSjis(char *dst, u16 *src, int len);
int ucs2ToUtf8(char *dst, u16 *src, int len);
void zWindSetFontClip();
void zWindFontDraw();
void zWindFontDrawSJ();
unsigned int utf8nlen(void *, int);                          /* extern */
void ESP_free(signed char *);                             /* extern */
signed char *ESP_malloc(int);                                /* extern */
void UTL_enqueue(int, signed char *);                     /* extern */
void zWindDrawClipSet();                         /* extern */
extern int _i_pspBrowserFontState;

typedef struct EXTCB {
    struct EXTCB *next;
    struct EXTCB *prev;
    char *name;
    int (*callback)();
} EXTCB;

typedef struct PURL {
    char *scheme;
    char *host;
    int port;
    u8 *path;
    u8 *query;
} PURL;

typedef struct {
    void *next;
    void *prev;
    PURL *url;
    int data;
} IMGREQ;

extern char D_00130214[];
int OS_thread_mutex_lock(int);
int OS_thread_mutex_unlock(int);
int ESP_hasPreviousHistory(void);
int ESP_hasNextHistory(void);
int ESP_moveHistory(int);
int ESP_reloadPage(int);
void URL_free(void *);
void UTL_initqueue(void *);
void *UTL_dequeue(void *);

void *UTL_peekqueue(void *q, void *e);
void UTL_relqueue(void *q, void *e);
int strcmp(const char *, const char *);
extern u8 D_0025B0DC[];
extern u8 D_0025B0EC[];
EXTCB *pspBrowserGetExtensionCallback(void *q, char *name);

M2C_UNK sjisToUtf8();                               /* extern */
int sjisToUcs2();                                   /* extern */
M2C_UNK utf8ToSjis();                               /* extern */
int utf8ToUcs2();                                   /* extern */


INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", D_00130210);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", D_00130214);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserEventCallback);

#ifndef NULL
#define NULL ((void *)0)
#endif

int pspBrowserStrcpyTo(void *arg0, int arg1, void *arg2, int arg3) {
    signed char *var_v0;
    unsigned int temp_v0;

    if ((arg0 != NULL) & (arg1 > 0)) {
        if (arg3 < arg1) {
            memcpy(arg0, arg2, (unsigned int) arg3);
            var_v0 = arg0 + arg3;
        } else {
            temp_v0 = utf8nlen(arg2, arg1 - 1);
            memcpy(arg0, arg2, temp_v0);
            var_v0 = arg0 + temp_v0;
        }
        *var_v0 = 0;
    }
    return arg3;
}

typedef struct {
    unsigned int state : 16;
    unsigned int pad : 8;
    unsigned int b24 : 1;
    unsigned int b25 : 1;
    unsigned int b26 : 1;
    unsigned int b27 : 1;
    unsigned int b28 : 1;
    unsigned int b29 : 1;
    unsigned int b30 : 1;
    unsigned int b31 : 1;
} REPORTBITS;

typedef union {
    int v;
    REPORTBITS b;
} REPORT;


int pspBrowserReportValue(void) {
    unsigned int r;
    int st;

    r = 0;
    st = 0;
    if (pspBrowserInstance.flags & 2) {
        r |= 0x80000000;
    } else {
        r &= ~0x80000000;
    }
    if (pspBrowserInstance.flags & 4) {
        r |= 0x40000000;
    } else {
        r &= ~0x40000000;
    }
    if (pspBrowserInstance.flags & 0x10) {
        r |= 0x20000000;
    } else {
        r &= ~0x20000000;
    }
    if (pspBrowserInstance.flags & 1) {
        r &= ~0x8000000;
    } else {
        r |= 0x8000000;
    }
    if (pspBrowserInstance.flags & 0x20) {
        r |= 0x2000000;
    } else {
        r &= ~0x2000000;
    }
    if (pspBrowserInstance.flags & 0x40) {
        r |= 0x4000000;
    } else {
        r &= ~0x4000000;
    }
    if (pspBrowserInstance.flags & 0x80) {
        r |= 0x1000000;
    } else {
        r &= ~0x1000000;
    }
    if (pspBrowserInstance.flags & 0x04000000) {
        st = 0x19;
    } else if (pspBrowserInstance.flags & 8) {
        st = 0x18;
    } else if (pspBrowserInstance.flags & 0x400) {
        st = 0x11;
    } else if (pspBrowserInstance.flags & 0x800) {
        st = 0x12;
    } else if (pspBrowserInstance.flags & 0x1000) {
        st = 0x13;
    } else if (pspBrowserInstance.flags & 0x2000) {
        st = 0x14;
    } else if (pspBrowserInstance.flags & 0x4000) {
        st = 0x15;
    } else if (pspBrowserInstance.flags & 0x8000) {
        st = 0x16;
    } else if (pspBrowserInstance.flags & 0x100) {
        st = 0x10;
    } else if (pspBrowserInstance.flags & 0x10000) {
        st = 0x20;
    } else if (pspBrowserInstance.flags & 0x20000) {
        st = 0x21;
    } else if (pspBrowserInstance.flags & 0xC0000) {
        st = 0x22;
    } else if (pspBrowserInstance.flags & 0x100000) {
        st = 0x23;
    } else if (pspBrowserInstance.flags & 0x200000) {
        st = 0x24;
    } else if (pspBrowserInstance.flags & 0x01C00000) {
        st = 0x1E;
    } else if (pspBrowserInstance.flags & 0x02000000) {
        st = 0x1F;
    }
    if ((pspBrowserInstance.flags & 0x200)
        && (st == 0 || ((REPORT *)&pspBrowserInstance.unk8)->b.state != st)) {
        st = 0x17;
    }
    return st | (r & 0xFFFF0000);
}

EXTCB *pspBrowserGetExtensionCallback(void *q, char *name) {
    EXTCB *e;

    if (name == NULL || *name == 0) {
        return NULL;
    }
    e = NULL;
    while ((e = UTL_peekqueue(q, e)) != NULL) {
        if (strcmp(e->name, name) == 0) {
            break;
        }
    }
    return e;
}

int pspBrowserDeleteExtensionCallback(void *q, char *name) {
    EXTCB *e;

    if (name == NULL) {
        while ((e = UTL_peekqueue(q, NULL)) != NULL) {
            pspBrowserDeleteExtensionCallback(q, e->name);
        }
        return 0;
    }
    e = pspBrowserGetExtensionCallback(q, name);
    if (e == NULL) {
        return -1;
    }
    UTL_relqueue(q, e);
    ESP_free((signed char *)e->name);
    ESP_free((signed char *)e);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
char *strcpy(char *d, const char *s);

signed char *pspBrowserNewExtensionCallback(int arg0, signed char *arg1, int arg2) {
    signed char *temp_v0;
    signed char *temp_v0_2;
    signed char *var_v0;
    unsigned int temp_s1;

    temp_s1 = strlen(arg1);
    temp_v0 = ESP_malloc(0x10);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0) = 0;
        M2C_FIELD(temp_v0, int *, 4) = 0;
        M2C_FIELD(temp_v0, signed char **, 8) = NULL;
        M2C_FIELD(temp_v0, int *, 0xC) = arg2;
        temp_v0_2 = ESP_malloc(temp_s1 + 1);
        M2C_FIELD(temp_v0, signed char **, 8) = temp_v0_2;
        if (temp_v0_2 == NULL) {
            ESP_free(temp_v0);
            return NULL;
        }
        strcpy(M2C_FIELD(temp_v0, signed char **, 8), arg1);
        UTL_enqueue(arg0, temp_v0);
        var_v0 = temp_v0;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}

int pspBrowserBuildInAnchorExtensionCallback(char *name) {
    if (name != NULL) {
        if (strcmp(name, "backward") == 0) {
            if (ESP_hasPreviousHistory() == 0) {
                return -1;
            }
            if (ESP_moveHistory(-1) != 0) {
                return -1;
            }
            return 0;
        }
        if (strcmp(name, "forward") == 0) {
            if (ESP_hasNextHistory() == 0) {
                return -1;
            }
            if (ESP_moveHistory(1) != 0) {
                return -1;
            }
            return 0;
        }
        if (strcmp(name, "reload") == 0) {
            if (ESP_reloadPage(0) != 0) {
                return -1;
            }
            return 0;
        }
    }
    return -1;
}

void pspBrowserExecuteAnchorExtensionCallback(void) {
    PURL *url;
    EXTCB *e;

    OS_thread_mutex_lock(pspBrowserInstance.mutex);
    url = pspBrowserInstance.anchorUrl;
    if (url != NULL) {
        pspBrowserInstance.anchorUrl = NULL;
    }
    OS_thread_mutex_unlock(pspBrowserInstance.mutex);
    if (url == NULL) {
        return;
    }
    if (url->scheme != NULL && strcmp(D_00130214, url->scheme) == 0
        && (e = pspBrowserGetExtensionCallback(pspBrowserInstance.anchorExt, url->host)) != NULL) {
        e->callback((url->path != NULL && *url->path != 0) ? url->path + 1 : NULL,
                    (url->query != NULL && *url->query != 0) ? url->query + 1 : NULL);
    }
    URL_free(url);
}

void pspBrowserExecuteImageExtensionCallback(void) {
    u8 q[8];
    IMGREQ *r;
    EXTCB *e;

    UTL_initqueue(q);
    OS_thread_mutex_lock(pspBrowserInstance.mutex);
    while ((r = UTL_dequeue(pspBrowserInstance.imageReq)) != NULL) {
        UTL_enqueue((int)q, (signed char *)r);
    }
    OS_thread_mutex_unlock(pspBrowserInstance.mutex);
    while ((r = UTL_dequeue(q)) != NULL) {
        if (r->url->scheme != NULL && strcmp(D_00130214, r->url->scheme) == 0
            && (e = pspBrowserGetExtensionCallback(pspBrowserInstance.imageExt, r->url->host)) != NULL) {
            e->callback((r->url->path != NULL && *r->url->path != 0) ? r->url->path + 1 : NULL,
                        (r->url->query != NULL && *r->url->query != 0) ? r->url->query + 1 : NULL,
                        &r->data);
        }
        URL_free(r->url);
        ESP_free((signed char *)r);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserInit);

int ESP_destroyCore();
int GUI_Component_remove();
int zWindExit();
void OS_thread_mutex_destroy();

int pspBrowserExit(void) {
    void **p;
    IMGREQ *r;
    int r2;

    if (pspBrowserInstance.unk0 == 0) {
        return -1;
    }
    if (pspBrowserInstance.unk10 != NULL) {
        ESP_free(pspBrowserInstance.unk10);
        pspBrowserInstance.unk10 = NULL;
    }
    if (pspBrowserInstance.unk94 != NULL) {
        ESP_free(pspBrowserInstance.unk94);
        pspBrowserInstance.unk94 = NULL;
    }
    for (p = (void **)pspBrowserInstance.unkA8; p != NULL; p = (void **)pspBrowserInstance.unkA8) {
        pspBrowserInstance.unkA8 = (int)*p;
        ESP_free((signed char *)p);
    }
    if (pspBrowserInstance.unk14 != NULL) {
        ESP_free(pspBrowserInstance.unk14);
        pspBrowserInstance.unk14 = NULL;
    }
    if (pspBrowserInstance.anchorUrl != NULL) {
        URL_free(pspBrowserInstance.anchorUrl);
        pspBrowserInstance.anchorUrl = NULL;
    }
    pspBrowserDeleteExtensionCallback(pspBrowserInstance.anchorExt, NULL);
    while ((r = UTL_dequeue(pspBrowserInstance.imageReq)) != NULL) {
        URL_free(r->url);
        ESP_free((signed char *)r);
    }
    pspBrowserDeleteExtensionCallback(pspBrowserInstance.imageExt, NULL);
    if (pspBrowserInstance.unkC8 != NULL) {
        ESP_free(pspBrowserInstance.unkC8);
        pspBrowserInstance.unkC8 = NULL;
    }
    if (pspBrowserInstance.unkD0 != NULL) {
        ESP_free(pspBrowserInstance.unkD0[0]);
        ESP_free(pspBrowserInstance.unkD0[1]);
        ESP_free((signed char *)pspBrowserInstance.unkD0);
        pspBrowserInstance.unkD0 = NULL;
    }
    if (pspBrowserInstance.unk98 != NULL) {
        ESP_free(pspBrowserInstance.unk98);
        pspBrowserInstance.unk98 = NULL;
    }
    pspBrowserInstance.focusCallback = NULL;
    pspBrowserInstance.unkA0 = 0;
    pspBrowserInstance.unloadCallback = NULL;
    OS_thread_mutex_destroy(pspBrowserInstance.mutex);
    pspBrowserInstance.mutex = 0;
    ESP_destroyCore();
    if (pspBrowserInstance.widget != 0) {
        GUI_Component_remove(pspBrowserInstance.widget);
    }
    r2 = zWindExit();
    pspBrowserInstance.unk0 = 0;
    if (r2 != 0) {
        return -1;
    }
    return 0;
}

typedef struct {
    char *a;
    char *b;
} FOCUSREQ;

int pspBrowserInit(PSPBROWSER_INI *ini);
int pspBrowserSetState(int state, void *arg);
int zWindExec(PSPBROWSER_INPUT *in);
int sceNetApDialogDummyGetState(int *state);
int pspBrowserReportValue(void);
void pspBrowserExecuteAnchorExtensionCallback(void);
void pspBrowserExecuteImageExtensionCallback(void);

int pspBrowserExec(PSPBROWSER_INPUT *in) {
    PSPBROWSER_INPUT buf;
    PSPBROWSER_INPUT *p;
    void *url;
    int r;
    FOCUSREQ *f;
    int st;

    p = NULL;
    if (pspBrowserInstance.unk0 == 0) {
        return 0x08000000;
    }
    if (pspBrowserInstance.unk0 == 4) {
        url = pspBrowserInstance.unk14;
        if (url == NULL) {
            url = pspBrowserInstance.ini.homeURL;
        }
        pspBrowserInstance.ini.mode |= 1;
        pspBrowserExit();
        pspBrowserInit(&pspBrowserInstance.ini);
        pspBrowserSetState(0x18, url);
    }
    if (in != NULL && *(u16 *)&pspBrowserInstance.unk8 == 0) {
        buf = *in;
        p = &buf;
    }
    r = zWindExec(p);
    if (r == 1) {
        pspBrowserInstance.flags |= 0x200;
    } else if (r != 0) {
        pspBrowserInstance.flags |= 0x04000000;
    }
    pspBrowserExecuteAnchorExtensionCallback();
    pspBrowserExecuteImageExtensionCallback();
    OS_thread_mutex_lock(pspBrowserInstance.mutex);
    f = pspBrowserInstance.unk98;
    if (f != NULL) {
        pspBrowserInstance.unk98 = NULL;
    }
    OS_thread_mutex_unlock(pspBrowserInstance.mutex);
    if (f != NULL) {
        if (pspBrowserInstance.focusCallback != NULL) {
            pspBrowserInstance.focusCallback(f->a, f->b);
        }
        ESP_free((signed char *)f);
    }
    if (pspBrowserInstance.unkA0 != 0) {
        pspBrowserInstance.unkA0 = 0;
        if (pspBrowserInstance.unloadCallback != NULL) {
            pspBrowserInstance.unloadCallback();
        }
    }
    if (sceNetApDialogDummyGetState(&st) == 0 && st == 2) {
        pspBrowserInstance.flags |= 2;
    } else {
        pspBrowserInstance.flags &= ~2;
    }
    pspBrowserInstance.unk8 = pspBrowserReportValue();
    return pspBrowserInstance.unk8;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserSetState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserGetState);

int pspBrowserAddAnchor(char *name, PSPBROWSER_ANCHOR_CALLBACK callback) {
    if (pspBrowserInstance.unk0 == 0) {
        return -5;
    }
    if (name == NULL || *name == 0 || callback == 0) {
        return -1;
    }
    if (pspBrowserGetExtensionCallback(D_0025B0DC, name) != NULL) {
        return -1;
    }
    if (pspBrowserNewExtensionCallback((int)D_0025B0DC, (signed char *)name, (int)callback) != NULL) {
        return 0;
    }
    pspBrowserInstance.flags |= 0x4000000;
    return -1;
}

int pspBrowserAddImage(char *name, int callback) {
    if (pspBrowserInstance.unk0 == 0) {
        return -5;
    }
    if (name == NULL || *name == 0 || callback == 0) {
        return -1;
    }
    if (pspBrowserGetExtensionCallback(D_0025B0EC, name) != NULL) {
        return -1;
    }
    if (pspBrowserNewExtensionCallback((int)D_0025B0EC, (signed char *)name, (int)callback) != NULL) {
        return 0;
    }
    pspBrowserInstance.flags |= 0x4000000;
    return -1;
}

int pspBrowserSetFocusCallback(PSPBROWSER_FOCUS_CALLBACK callback) {
    if (pspBrowserInstance.unk0 == 0) {
        return -5;
    }
    if (pspBrowserInstance.focusCallback != NULL) {
        return -1;
    }
    if (zWindSetSetFocusCallback(callback) != 0) {
        return -1;
    }
    pspBrowserInstance.focusCallback = callback;
    return 0;
}

int pspBrowserUnloadCallback(PSPBROWSER_UNLOAD_CALLBACK callback) {
    if (pspBrowserInstance.unk0 == 0) {
        return -5;
    }
    if (pspBrowserInstance.unloadCallback != NULL) {
        return -1;
    }
    pspBrowserInstance.unloadCallback = callback;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void pspBrowserSjisToUtf8(void) {
    sjisToUtf8();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int pspBrowserSjisToUcs2(void) {
    return sjisToUcs2() * 2;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void pspBrowserUtf8ToSjis(void) {
    utf8ToSjis();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int pspBrowserUtf8ToUcs2(void) {
    return utf8ToUcs2() * 2;
}

int pspBrowserUcs2ToSjis(char *dst, u16 *src, int size) {
    return ucs2ToSjis(dst, src, size / 2);
}

int pspBrowserUcs2ToUtf8(char *dst, u16 *src, int size) {
    return ucs2ToUtf8(dst, src, size / 2);
}

void pspBrowserFontSetImage(void *image, int width, int height) {
    zWindSetFontClip(image);
    _i_pspBrowserFontState = 0;
    if (width != 0) {
        if (height != 0) {
            _i_pspBrowserFontState = 1;
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void pspBrowserFontClip(void) {
    if (_i_pspBrowserFontState != 0) {
        zWindDrawClipSet();
    }
}

void pspBrowserFontPut(int x, int y, char *str, int len, int color) {
    if (_i_pspBrowserFontState) {
        zWindFontDraw(0, x, y, str, (s16)color, len);
    }
}

void pspBrowserFontPutSJ(int x, int y, char *str, int len, int color) {
    if (_i_pspBrowserFontState) {
        zWindFontDrawSJ(0, x, y, str, (s16)color, len);
    }
}

void null_callback(void) {
}

typedef struct {
    char *image;                /* 0x0 */
    int width;                  /* 0x4 */
    int height;                 /* 0x8 */
    int unkC;
    int unk10;
    int unk14;
    int fontSize;               /* 0x18 */
    int font[4];                /* 0x1C */
} ZWINDINIT;

void zWindPartsSet(int size);
void zWindFontSet(int type, short w, short h, short bpp, int f0, int f1, int f2, int f3);
int GuigraphicsInit(void);
int GuipixmapInit(void);
int GuifontInit(void);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", zWindInit);

int zWindExit(void) {
    if (_i_windsystemOn == 0) {
        puts("[X1]zWindExit");
        return -1;
    }
    _i_windsystemOn = 0;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", zWindExec);

int zWindMouseOk(GUIWIDGET *w, int x, int y) {
    int l;
    int t;
    int r;
    int b;

    if (w == NULL) {
        return 0;
    }
    if (w->type != 1) {
        return -1;
    }
    l = w->unk36;
    t = w->unk38;
    r = l + w->w;
    b = t + w->h;
    if (x < l) {
        return -1;
    }
    if (r < x) {
        return -1;
    }
    if (y < t) {
        return -1;
    }
    if (b < y) {
        return -1;
    }
    return 0;
}

GUIWIDGET *zWindExecK(GUIWIDGET *w, int x, int y) {
    GUIWIDGET *r;
    int x0;
    int y0;
    int x1;
    int y1;

    if (w == NULL) {
        return NULL;
    }
    if (w->type != 1) {
        return NULL;
    }
    x0 = w->unk36;
    y0 = w->unk38;
    x1 = x0 + w->w;
    y1 = y0 + w->h;
    switch (w->flags & 0xF) {
    case 3:
    case 4:
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
        if (!(w->flags & 0x40000000) && (x >= x0 & x < x1) && (y >= y0 & y < y1)) {
            r = zWindExecK(w->child, x, y);
            if (r == NULL) {
                return w;
            }
            return r;
        }
        break;
    default:
        r = zWindExecK(w->child, x, y);
        if (r != NULL) {
            return r;
        }
        break;
    }
    return zWindExecK(w->next, x, y);
}

int zWindUpdate(void) {
    s_windsystem_data.flags &= ~2;
    return 0;
}

int zWindImageSet(void *dst) {
    memcpy(dst, s_windsystem_init.image, s_windsystem_init.width * s_windsystem_init.height * 2);
    s_windsystem_init.image = dst;
    return 0;
}
