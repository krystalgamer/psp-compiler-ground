/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
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
void *memcpy(void *d, const void *s, unsigned int n);

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
unsigned int strlen(const char *s);
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserSetFocusCallback);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserUnloadCallback);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserUcs2ToSjis);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserUcs2ToUtf8);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserFontSetImage);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", zWindExit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", zWindExec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", zWindMouseOk);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", zWindExecK);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", zWindUpdate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", zWindImageSet);
