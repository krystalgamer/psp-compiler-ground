/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void *FIO_fopen(const char *path, const char *mode);
int FIO_fseek(void *fp, int off, int whence);
int FIO_ftell(void *fp);
int FIO_fread(void *buf, int size, int n, void *fp);
int FIO_fwrite(void *buf, int size, int n, void *fp);
int FIO_fclose(void *fp);
void *memset(void *p, int c, unsigned int n);
void *CSS_newPoolBuf(void);
void CSS_putSPoolBuf(void *pb, const char *s);
void CSS_putsPoolBuf(void *pb, void *s);
void *CSS_getMediaTypeString(int t);
void CSS_freePoolBuf(void *pb);
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

int CSSImportRule_getCssText(void *arg0) {
    int temp_s0;
    int var_v0;
    unsigned short *temp_v0;
    void *m;

    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 3)) {
        return 0;
    }
    temp_v0 = CSS_newPoolBuf();
    var_v0 = 0;
    if (temp_v0 != NULL) {
        CSS_putSPoolBuf(temp_v0, "@import url(");
        CSS_putsPoolBuf(temp_v0, M2C_FIELD(arg0, unsigned short **, 0x24));
        CSS_putSPoolBuf(temp_v0, ")");
        m = CSS_getMediaTypeString(M2C_FIELD(arg0, short *, 0x28));
        if (m != NULL) {
            CSS_putsPoolBuf(temp_v0, m);
            MEM_free(0, m);
        }
        CSS_putSPoolBuf(temp_v0, ";");
        CSS_putSPoolBuf(temp_v0, "\n");
        temp_s0 = CSS_getPoolBuf(temp_v0);
        CSS_freePoolBuf(temp_v0);
        var_v0 = temp_s0;
    }
    return var_v0;
}

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

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrACCEPT);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrACCEPTCHARSET);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrACCEPTENCODING);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrACCEPTLANGUAGE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrAGE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrALLOW);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrAUTHORIZATION);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrCACHECONTROL);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrCONNECTION);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrCONTENTENCODING);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrCONTENTLANGUAGE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrCONTENTLENGTH);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrCONTENTLOCATION);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrCONTENTTYPE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrCOOKIE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrDATE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrETAG);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrEXPECT);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrEXPIRES);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrFROM);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrHOST);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrIFMATCH);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrIFMODIFIEDSINCE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrIFNONEMATCH);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrIFUNMODIFIEDSINCE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrLASTMODIFIED);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrLOCATION);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrPRAGMA);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrPROXYAUTHENTICATE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrPROXYAUTHORIZATION);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrPROXYCONNECTION);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrREFERER);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrRETRYAFTER);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrSERVER);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrSETCOOKIE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrTRANSFERENCODING);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrUSERAGENT);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrWWWAUTHENTICATE);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrCHUNKED);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/CSSImportRule", htlib_cstrKEEPALIVE);
