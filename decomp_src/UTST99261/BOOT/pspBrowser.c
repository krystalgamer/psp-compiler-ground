/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
#include "UTST99261/BOOT/pspBrowser.h"
#include "UTST99261/BOOT/nfgui.h"

typedef struct { /* size 0xD8 */
    int unk0;
    u8 unk4[0x98];
    PSPBROWSER_FOCUS_CALLBACK focusCallback;    /* 0x9C */
    int unkA0;
    PSPBROWSER_UNLOAD_CALLBACK unloadCallback;  /* 0xA4 */
    u8 unkA8[0x30];
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
M2C_UNK ESP_free(signed char *);                             /* extern */
signed char *ESP_malloc(int);                                /* extern */
M2C_UNK UTL_enqueue(int, signed char *);                     /* extern */
M2C_UNK zWindDrawClipSet();                         /* extern */
extern int _i_pspBrowserFontState;

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserReportValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserGetExtensionCallback);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserDeleteExtensionCallback);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserBuildInAnchorExtensionCallback);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserExecuteAnchorExtensionCallback);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserExecuteImageExtensionCallback);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserInit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserExit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserExec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserSetState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserGetState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserAddAnchor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserAddImage);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserFontPut);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserFontPutSJ);

void null_callback(void) {
}

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", zWindExecK);

int zWindUpdate(void) {
    s_windsystem_data.flags &= ~2;
    return 0;
}

int zWindImageSet(void *dst) {
    memcpy(dst, s_windsystem_init.image, s_windsystem_init.width * s_windsystem_init.height * 2);
    s_windsystem_init.image = dst;
    return 0;
}
