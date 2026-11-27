/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void *newCSSNode(int a, int size);
void CSS_StyleSheetRuleSingle(void *ss, char *text);
void popCSSNode(void *n);
void addCSSNode(void *p, void *n);
void pushCSSNode(void *p, void *n);
void freeCSSStyleSheet(void *ss);
int Node_getSid(void *node);
typedef struct InpMsg {
    int w[8];                         /* inp */
} InpMsg;
void SetIpcMember(InpMsg *msg, int a, int sid, int b, int cmd, int c, int d, void *node);
int JSSendMail(InpMsg *msg, const char *name);
void *mes_class_private_get(void *obj);
void *Node_getOwnerDocument(void *node);
typedef struct MesContext MesContext;
int mes_input_inner(MesContext *ctx, int cmd, int kind);
typedef struct CSSRule {
    short type;
    char pad[0x22];
    void *f24;
} CSSRule;
void freeCSSNode(void *node);
M2C_UNK FIO_remove();                               /* extern */
int CSS_getPoolBuf(unsigned short *);                          /* extern */

M2C_UNK addCSSRule();                               /* extern */


int mes_input_inner(MesContext *ctx, int cmd, int kind)
{
    InpMsg msg;
    void **priv = mes_class_private_get(M2C_FIELD(M2C_FIELD(ctx, void **, 0x10), void **, 0x1C));

    SetIpcMember(&msg, 8, Node_getSid(Node_getOwnerDocument(*priv)), 0, cmd, kind, 0, *priv);
    JSSendMail(&msg, "/tmp/mq_lo");
    return 0;
}

int mes_input_blur(MesContext *ctx)
{
    return mes_input_inner(ctx, 0x808, 1);
}

int mes_input_click(MesContext *ctx)
{
    return mes_input_inner(ctx, 0x80B, 2);
}

int mes_input_focus(MesContext *ctx)
{
    return mes_input_inner(ctx, 0x808, 0);
}

int mes_input_select(MesContext *ctx)
{
    return mes_input_inner(ctx, 0x80A, 0);
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif

int removeCFData(signed char *arg0) {
    int var_v1;

    var_v1 = -0x78;
    if (*arg0 != 0) {
        FIO_remove();
        var_v1 = 0;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void newCSSCharsetRule(void *arg0, void *arg1) {
    newCSSRule(2, 0x28, arg0, arg1);
}

void freeCSSCharsetRule(CSSRule *r)
{
    if (r != NULL && r->type == 2) {
        if (r->f24 != NULL)
            MEM_free(0, r->f24);
        freeCSSNode(r);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSCharsetRule(void) {
    addCSSRule();
}

int CSSCharsetRule_getType(CSSRule *r)
{
    if (r != NULL && r->type == 2)
        return 2;
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int CSSCharsetRule_getCssText(void *arg0) {
    int temp_s0;
    int var_v0;
    unsigned short *temp_v0;

    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 2)) {
        return 0;
    }
    temp_v0 = CSS_newPoolBuf();
    var_v0 = 0;
    if (temp_v0 != NULL) {
        CSS_putSPoolBuf(temp_v0, "@charset \"");
        CSS_putsPoolBuf(temp_v0, M2C_FIELD(arg0, unsigned short **, 0x24));
        CSS_putSPoolBuf(temp_v0, "\";");
        CSS_putSPoolBuf(temp_v0, "\n");
        temp_s0 = CSS_getPoolBuf(temp_v0);
        CSS_freePoolBuf(temp_v0);
        var_v0 = temp_s0;
    }
    return var_v0;
}

int CSSCharsetRule_setCssText(void *r, char *text)
{
    int ret = -1;
    void *ss;
    CSSRule *n;
    CSSRule *old;

    if (r != NULL && M2C_FIELD(r, void **, 0x1C) != NULL && M2C_FIELD(M2C_FIELD(r, void **, 0x1C), short *, 0x36) == 0
        && (ss = newCSSNode(0, 0x3C)) != NULL) {
    CSS_StyleSheetRuleSingle(ss, text);
    n = M2C_FIELD(ss, CSSRule **, 0xC);
    if (n != NULL && n->type == 2 && n->f24 != NULL) {
        old = M2C_FIELD(M2C_FIELD(r, void **, 0x1C), CSSRule **, 0xC);
        ret = 0;
        if (old != NULL && old->type == 2)
            freeCSSCharsetRule(old);
        popCSSNode(n);
        pushCSSNode(M2C_FIELD(r, void **, 0x1C), n);
    }
    freeCSSStyleSheet(ss);
    }
    return ret;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSCharsetRule_getParentStyleSheet(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 2)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x1C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSCharsetRule_getParentRule(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 2)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSCharsetRule_getEncoding(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 2)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x24);
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif
void newCSSImportRule(void *arg0, void *arg1) {
    newCSSRule(3, 0x2C, arg0, arg1);
}

void freeCSSImportRule(CSSRule *r)
{
    if (r != NULL && r->type == 3) {
        if (r->f24 != NULL)
            MEM_free(0, r->f24);
        freeCSSNode(r);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSImportRule(void) {
    addCSSRule();
}

int CSSImportRule_getType(CSSRule *r)
{
    if (r != NULL && r->type == 3)
        return 3;
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_input", CSSImportRule_getCssText);

int CSSImportRule_setCssText(void *r, char *text)
{
    int ret = -1;
    void *ss;
    CSSRule *n;

    if (r != NULL && M2C_FIELD(r, void **, 0x1C) != NULL && M2C_FIELD(M2C_FIELD(r, void **, 0x1C), short *, 0x36) == 0
        && (ss = newCSSNode(0, 0x3C)) != NULL) {
    CSS_StyleSheetRuleSingle(ss, text);
    n = M2C_FIELD(ss, CSSRule **, 0xC);
    if (n != NULL && n->type == 3 && n->f24 != NULL) {
        popCSSNode(n);
        addCSSNode(M2C_FIELD(r, void **, 0x1C), n);
        ret = 0;
    }
    freeCSSStyleSheet(ss);
    }
    return ret;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSImportRule_getParentStyleSheet(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 3)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x1C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSImportRule_getParentRule(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 3)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSImportRule_getHref(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 3)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x24);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned short *CSSImportRule_getMedia(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 3)) {
        return NULL;
    }
    return CSS_getMediaTypeString(M2C_FIELD(arg0, short *, 0x28));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSImportRule_getStyleSheet(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
short CSSImportRule_getMediaType(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 3)) {
        return -1;
    }
    return M2C_FIELD(arg0, short *, 0x28);
}

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
