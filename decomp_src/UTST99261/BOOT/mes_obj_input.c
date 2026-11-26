#include "common.h"
#include "m2c_macros.h"
M2C_UNK addCSSRule();                               /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", mes_input_inner);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", mes_input_blur);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", mes_input_click);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", mes_input_focus);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", mes_input_select);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", mes_input_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", mes_input_put);

#ifndef NULL
#define NULL ((void *)0)
#endif
void mes_input_free(void) {
    MEM_free(0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", readCFData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", writeCFData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", removeCFData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", newCSSCharsetRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", freeCSSCharsetRule);

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSCharsetRule(void) {
    addCSSRule();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSCharsetRule_getType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSCharsetRule_getCssText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSCharsetRule_setCssText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSCharsetRule_getParentStyleSheet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSCharsetRule_getParentRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSCharsetRule_getEncoding);

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSCharsetRule_setEncoding(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 2)) {
        M2C_FIELD(arg0, int *, 0x24) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSCharsetRule_setParentStyleSheet(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 2)) {
        M2C_FIELD(arg0, int *, 0x1C) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSCharsetRule_setParentRule(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 2)) {
        M2C_FIELD(arg0, int *, 0x20) = arg1;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", newCSSImportRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", freeCSSImportRule);

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSImportRule(void) {
    addCSSRule();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSImportRule_getType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSImportRule_getCssText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSImportRule_setCssText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSImportRule_getParentStyleSheet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSImportRule_getParentRule);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSImportRule_getHref);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSImportRule_getMedia);

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSImportRule_getStyleSheet(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSImportRule_getMediaType);

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSImportRule_setParentStyleSheet(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 3)) {
        M2C_FIELD(arg0, int *, 0x1C) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSImportRule_setParentRule(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 3)) {
        M2C_FIELD(arg0, int *, 0x20) = arg1;
    }
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrACCEPT);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrACCEPTCHARSET);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrACCEPTENCODING);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrACCEPTLANGUAGE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrAGE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrALLOW);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrAUTHORIZATION);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrCACHECONTROL);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrCONNECTION);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrCONTENTENCODING);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrCONTENTLANGUAGE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrCONTENTLENGTH);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrCONTENTLOCATION);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrCONTENTTYPE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrCOOKIE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrDATE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrETAG);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrEXPECT);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrEXPIRES);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrFROM);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrHOST);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrIFMATCH);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrIFMODIFIEDSINCE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrIFNONEMATCH);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrIFUNMODIFIEDSINCE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrLASTMODIFIED);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrLOCATION);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrPRAGMA);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrPROXYAUTHENTICATE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrPROXYAUTHORIZATION);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrPROXYCONNECTION);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrREFERER);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrRETRYAFTER);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrSERVER);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrSETCOOKIE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrTRANSFERENCODING);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrUSERAGENT);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrWWWAUTHENTICATE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrCHUNKED);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", htlib_cstrKEEPALIVE);
