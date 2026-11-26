/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sjisToUtf8();                               /* extern */
int sjisToUcs2();                                   /* extern */
M2C_UNK utf8ToSjis();                               /* extern */
int utf8ToUcs2();                                   /* extern */


INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", D_00130210);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", D_00130214);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserEventCallback);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserStrcpyTo);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserReportValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserGetExtensionCallback);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserDeleteExtensionCallback);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserNewExtensionCallback);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/pspBrowser", pspBrowserFontClip);

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
