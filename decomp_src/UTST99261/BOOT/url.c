#include "common.h"
#include "m2c_macros.h"
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_free);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_setScheme);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_setHost);

#ifndef NULL
#define NULL ((void *)0)
#endif
void URL_setPort(void *arg0, int arg1) {
    if (M2C_FIELD(arg0, int *, 8) >= 0) {
        M2C_FIELD(arg0, int *, 8) = arg1;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_setPath);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_setQuery);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_setAnchor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_toString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_toAbsoluteURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_equals);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_splitURL);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/url", D_00132328);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_encode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_decode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_checkFileStrage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", URL_toLocalFileName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_isSupportedMIMEType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_isSupportedFileType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_guessMIMETypeFromName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_guessMIMEType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_isNumber);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_initqueue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_enqueue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_dequeue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_relqueue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_insqueue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_peekqueue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_peekprevqueue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_sizequeue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfilecreate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfiledelete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfileread);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfilewrite);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfilegetc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfileclean);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfileputc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfileputs);

#ifndef NULL
#define NULL ((void *)0)
#endif
int UTL_mfilesize(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfilepos);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfileseek);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_mfileduplicate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", UTL_strword);

#ifndef NULL
#define NULL ((void *)0)
#endif
int directoryCheck(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", pathMake);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", IMG_gifGetImageData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/url", IMG_gifReadHeader);

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
