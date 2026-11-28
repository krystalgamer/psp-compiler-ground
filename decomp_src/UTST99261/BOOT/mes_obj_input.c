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
int CSS_putSPoolBuf(void *pb, const char *s);
int CSS_putsPoolBuf(void *pb, void *s);
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

void addCSSRule();                               /* extern */


void *MEM_malloc(void *, unsigned int size);
void *newCSSRule(int type, int size, void *a2, void *a3);
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

void *readCFData(char *path, int *size)
{
    void *fp;
    int n;
    void *buf;

    *size = 0;
    if (path[0] == 0)
        return NULL;
    fp = FIO_fopen(path, "rb");
    if (fp == NULL)
        return NULL;
    FIO_fseek(fp, 0, 2);
    n = FIO_ftell(fp);
    FIO_fseek(fp, 0, 0);
    buf = MEM_malloc(0, n + 1);
    if (buf == NULL) {
        FIO_fclose(fp);
        return NULL;
    }
    memset(buf, 0, n + 1);
    FIO_fread(buf, n, 1, fp);
    FIO_fclose(fp);
    *size = n;
    return buf;
}

int writeCFData(char *path, void *buf, int size, int off)
{
    void *fp;

    if (path[0] == 0)
        return -0x78;
    if (size == 0)
        return -0x78;
    if (off == 0)
        fp = FIO_fopen(path, "wb");
    else
        fp = FIO_fopen(path, "ab");
    if (fp == NULL)
        return -0x6E;
    FIO_fseek(fp, off, 0);
    if (FIO_fwrite(buf, size, 1, fp) != 1) {
        FIO_fclose(fp);
        FIO_remove(path);
        return -0x8C;
    }
    FIO_fclose(fp);
    return 0;
}

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
