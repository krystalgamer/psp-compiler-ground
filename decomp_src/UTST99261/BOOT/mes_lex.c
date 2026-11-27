/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int mes_util_digit(int c);
double mes_util_expt(double x, int n);
double floor(double x);
int mes_util_is_white_space(int c);
int mes_util_is_alpha_digit(int c);
int mes_util_string_eq2(void *s, const char *t);
int mes_util_hex(int c);
int mes_util_octal(int c);
typedef struct MesReserved {
    struct MesReserved *next;
    unsigned int hash;                /* 0x4 */
    unsigned short len;               /* 0x8 */
    unsigned short tok;               /* 0xA */
    const char *name;                 /* 0xC */
} MesReserved;
extern MesReserved *mes_lex_reserved_hash[31];
extern MesReserved mes_lex_reserved[];
typedef struct MesLine {
    char pad[8];
    unsigned char eof;
    unsigned char html;               /* 0x9 */
    char padA[2];
    unsigned short quote;             /* 0xC */
    char padE[0x20];
    unsigned short line;              /* 0x2E */
    unsigned short col;               /* 0x30 */
    int pos;                          /* 0x34 */
} MesLine;
typedef struct MesStrBuf {
    char pad[0x14];
    int len;                          /* 0x14 */
} MesStrBuf;
typedef struct MesLex {
    void *ctx;
    MesLine *line;                    /* 0x4 */
    unsigned short line_no;           /* 0x8 */
    unsigned short col;               /* 0xA */
    int pos;                          /* 0xC */
    unsigned char tok;                /* 0x10 */
    unsigned char prev;               /* 0x11 */
    short f12;
    MesStrBuf *str;                   /* 0x14 */
    double num;                       /* 0x18 */
} MesLex;
int mes_line_match(MesLine *l, const char *s);
void mes_util_string_put(MesStrBuf *s, int c);
int mes_lex_escape(MesLine *l);
int mes_line_peekn(MesLine *l, int n);
void mes_line_skipn(MesLine *l, int n);
unsigned short mes_line_peek(MesLine *l);
int mes_line_skip(MesLine *l);
int mes_stack_check(void *ctx);
int mes_lex_token_sub(MesLex *lx);
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
int mes_util_string_new();                          /* extern */
M2C_UNK mes_line_free(int);                         /* extern */
M2C_UNK mes_util_string_free(int);                  /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

void *mes_lex_new(int arg0, int arg1) {
    int temp_v0_2;
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x20);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0) = arg0;
        M2C_FIELD(temp_v0, int *, 4) = arg1;
        M2C_FIELD(temp_v0, signed char *, 0x11) = 0;
        M2C_FIELD(temp_v0, signed char *, 0x10) = 0;
        M2C_FIELD(temp_v0, short *, 0x12) = 0;
        temp_v0_2 = mes_util_string_new();
        M2C_FIELD(temp_v0, int *, 0x14) = temp_v0_2;
        if (temp_v0_2 == 0) {
            MEM_free(0, temp_v0);
            return NULL;
        }
    }
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_lex_free(void *arg0) {
    mes_util_string_free(M2C_FIELD(arg0, int *, 0x14));
    mes_line_free(M2C_FIELD(arg0, int *, 4));
    MEM_free(0, arg0);
}

int mes_lex_escape(MesLine *l)
{
    unsigned short c;
    int i;
    int d;

    c = mes_line_peek(l);
    switch (c) {
    case 'b':
        c = 8;
        break;
    case 't':
        c = 9;
        break;
    case 'n':
        c = 10;
        break;
    case 'v':
        c = 11;
        break;
    case 'f':
        c = 12;
        break;
    case 'r':
        c = 13;
        break;
    case 'u':
        mes_line_skip(l);
        c = 0;
        for (i = 0; i < 4; i++) {
            d = mes_util_hex(mes_line_peekn(l, i));
            if (d < 0)
                return 'u';
            c = (c << 4) | d;
        }
        mes_line_skipn(l, 4);
        return c;
    case 'x':
        mes_line_skip(l);
        c = 0;
        for (i = 0; i < 2; i++) {
            d = mes_util_hex(mes_line_peekn(l, i));
            if (d < 0)
                return 'x';
            c = (c << 4) | d;
        }
        mes_line_skipn(l, 2);
        return c;
    default:
        d = mes_util_octal(c);
        i = c < '4';
        i += 2;
        c = 0;
        if (d < 0) {
            c = l->quote;
            break;
        }
        while (i-- > 0 && (d = mes_util_octal(mes_line_peek(l))) >= 0) {
            c = c * 8 + d;
            mes_line_skip(l);
        }
        return c;
    }
    mes_line_skip(l);
    return c;
}

void mes_lex_single_line_comment(MesLine *l)
{
    while (!l->eof && mes_line_peek(l) != '\n')
        mes_line_skip(l);
}

int mes_lex_multi_line_comment(MesLine *l)
{
    int r = 0;

    while (!l->eof) {
        if (mes_line_peek(l) == '\n')
            r = 0x65;
        if (mes_line_match(l, "*/"))
            return r;
        mes_line_skip(l);
    }
    return r;
}

int mes_lex_id(MesLex *lx)
{
    MesLine *l = lx->line;
    unsigned int h;
    int esc;
    unsigned int c;
    int len;
    MesReserved *r;

    lx->str->len = 0;
    h = 0;
    esc = 0;
    while (!l->eof && (c = mes_line_peek(l)) != '\n' && !mes_util_is_white_space(c)
           && (mes_util_is_alpha_digit(c) || c == '_' || c == '\\' || c == '$' || c >= 0x80)) {
        mes_line_skip(l);
        if (c == '\\') {
            esc = 1;
            c = mes_lex_escape(l);
        }
        mes_util_string_put(lx->str, c);
        h = (h * 37) ^ c;
    }
    len = lx->str->len;
    if (len == 0)
        return 0;
    if (!esc) {
        for (r = mes_lex_reserved_hash[h % 31]; r != NULL; r = r->next)
            if (r->hash == h && r->len == len && mes_util_string_eq2(lx->str, r->name))
                return r->tok;
    }
    return 0x67;
}

int mes_lex_number(MesLex *lx, int frac)
{
    MesLine *l = lx->line;
    int d;
    unsigned int exp;
    unsigned int nfrac;
    int neg;

    lx->num = 0;
    if (!frac) {
        if (mes_line_peek(l) == '0') {
            mes_line_skip(l);
            if (mes_line_peek(l) == 'x' || l->quote == 'X') {
                while (mes_line_skip(l), (d = mes_util_hex(mes_line_peek(l))) >= 0)
                    lx->num = 16.0 * lx->num + d;
                return 0x68;
            }
            d = mes_util_octal(mes_line_peek(l));
            if (d >= 0) {
                for (;;) {
                    lx->num = 8.0 * lx->num + d;
                    mes_line_skip(l);
                    d = mes_util_octal(mes_line_peek(l));
                    if (d < 0)
                        return 0x68;
                }
            }
        }
        while ((d = mes_util_digit(mes_line_peek(l))) >= 0) {
            lx->num = 10.0 * lx->num + d;
            mes_line_skip(l);
        }
    }
    if (mes_line_peek(l) == '.') {
        mes_line_skip(l);
        frac = 1;
    }
    exp = 0;
    nfrac = 0;
    neg = 0;
    if (frac) {
        while ((d = mes_util_digit(mes_line_peek(l))) >= 0) {
            nfrac++;
            lx->num = 10.0 * lx->num + d;
            mes_line_skip(l);
        }
        lx->num = floor(lx->num + 0.5);
    }
    if (mes_line_peek(l) == 'e' || l->quote == 'E') {
        mes_line_skip(l);
        if (mes_line_peek(l) == '+')
            mes_line_skip(l);
        else if (l->quote == '-') {
            neg = 1;
            mes_line_skip(l);
        }
        while ((d = mes_util_digit(mes_line_peek(l))) >= 0) {
            exp = exp * 10 + d;
            mes_line_skip(l);
        }
    }
    if (nfrac != 0) {
        if (exp != 0) {
            if (neg)
                exp += nfrac;
            else if (exp >= nfrac)
                exp -= nfrac;
            else {
                exp = nfrac - exp;
                neg = 1;
            }
        } else {
            exp = nfrac;
            neg = 1;
        }
    }
    if (exp != 0) {
        if (neg)
            lx->num = lx->num / mes_util_expt(10.0, exp);
        else if (exp > 500)
            lx->num = mes_util_expt(10.0, exp) * lx->num;
        else
            while (exp-- > 0)
                lx->num = 10.0 * lx->num;
    }
    return 0x68;
}

int mes_lex_string(MesLex *lx)
{
    MesLine *l = lx->line;
    int q = l->quote;
    int c;

    mes_line_skip(l);
    lx->str->len = 0;
    while (!l->eof && (c = mes_line_peek(l)) != '\n' && c != q) {
        mes_line_skip(l);
        if (c == '\\')
            c = mes_lex_escape(l);
        mes_util_string_put(lx->str, c);
    }
    if (!l->eof && c == q)
        mes_line_skip(l);
    return 0x69;
}

int mes_lex_regex(MesLex *lx, int eq)
{
    MesLine *l = lx->line;
    int esc;
    int c;

    lx->str->len = 0;
    if (eq)
        mes_util_string_put(lx->str, '=');
    esc = 0;
    while (!l->eof && (c = mes_line_peek(l)) != '\n' && (esc || c != '/')) {
        mes_util_string_put(lx->str, c);
        mes_line_skip(l);
        esc = !esc && c == '\\';
    }
    if (!l->eof && c == '/')
        mes_line_skip(l);
    return 0x6A;
}

int mes_lex_regex_flags(MesLex *lx)
{
    MesLine *l = lx->line;
    int c;

    lx->str->len = 0;
    while (!l->eof && (c = mes_line_peek(l)) != '\n' && (c == 'g' || c == 'i' || c == 'm')) {
        mes_util_string_put(lx->str, c);
        mes_line_skip(l);
    }
    return 1;
}

int mes_lex_token_sub(MesLex *lx)
{
    MesLine *l = lx->line;
    int html = l->html;
    unsigned int c;
    int t;

    while (!l->eof && mes_util_is_white_space(mes_line_peek(l)))
        mes_line_skip(l);
    lx->line_no = l->line;
    lx->col = l->col;
    lx->pos = l->pos;
    if (l->eof)
        return 0x66;
    c = mes_line_peek(l);
    if (c == '\n') {
        mes_line_skip(l);
        return 0x65;
    }
    if (mes_util_digit(c) >= 0)
        return mes_lex_number(lx, 0);
    if (html && mes_line_match(l, "-->")) {
        mes_lex_single_line_comment(l);
        return 0x65;
    }
    switch (c) {
    case '$':
    case '\\':
    case '_':
        return mes_lex_id(lx);
    case '"':
    case '\'':
        return mes_lex_string(lx);
    case '!':
        mes_line_skip(l);
        if (mes_line_match(l, "=="))
            return 0x42;
        if (mes_line_match(l, "="))
            return 0x40;
        return 0x4F;
    case '%':
        mes_line_skip(l);
        if (mes_line_match(l, "="))
            return 0x59;
        return 0x46;
    case '&':
        mes_line_skip(l);
        if (mes_line_match(l, "&"))
            return 0x51;
        if (mes_line_match(l, "="))
            return 0x5D;
        return 0x4C;
    case '(':
        t = 0x34;
        break;
    case ')':
        t = 0x35;
        break;
    case '*':
        mes_line_skip(l);
        if (mes_line_match(l, "="))
            return 0x58;
        return 0x45;
    case '+':
        mes_line_skip(l);
        if (mes_line_match(l, "+"))
            return 0x47;
        if (mes_line_match(l, "="))
            return 0x56;
        return 0x43;
    case ',':
        t = 0x3A;
        break;
    case '-':
        mes_line_skip(l);
        if (mes_line_match(l, "-"))
            return 0x48;
        if (mes_line_match(l, "="))
            return 0x57;
        return 0x44;
    case '.':
        mes_line_skip(l);
        if (mes_util_digit(mes_line_peek(l)) < 0)
            return 0x38;
        return mes_lex_number(lx, 1);
    case '/':
        mes_line_skip(l);
        if (mes_line_match(l, "*"))
            return mes_lex_multi_line_comment(l);
        if (mes_line_match(l, "/")) {
            mes_lex_single_line_comment(l);
            return 0x65;
        }
        if (mes_line_match(l, "="))
            return 0x60;
        return 0x61;
    case ':':
        t = 0x54;
        break;
    case ';':
        t = 0x39;
        break;
    case '<':
        mes_line_skip(l);
        if (mes_line_match(l, "="))
            return 0x3D;
        if (mes_line_match(l, "<="))
            return 0x5A;
        if (mes_line_match(l, "<"))
            return 0x49;
        if (!mes_line_match(l, "!--"))
            return 0x3B;
        mes_lex_single_line_comment(l);
        return 0x65;
    case '=':
        mes_line_skip(l);
        if (mes_line_match(l, "=="))
            return 0x41;
        if (mes_line_match(l, "="))
            return 0x3F;
        return 0x55;
    case '>':
        mes_line_skip(l);
        if (mes_line_match(l, "="))
            return 0x3E;
        if (mes_line_match(l, ">>="))
            return 0x5C;
        if (mes_line_match(l, ">>"))
            return 0x4B;
        if (mes_line_match(l, ">="))
            return 0x5B;
        if (mes_line_match(l, ">"))
            return 0x4A;
        return 0x3C;
    case '?':
        t = 0x53;
        break;
    case '[':
        t = 0x36;
        break;
    case ']':
        t = 0x37;
        break;
    case '^':
        mes_line_skip(l);
        if (mes_line_match(l, "="))
            return 0x5F;
        return 0x4E;
    case '{':
        t = 0x32;
        break;
    case '|':
        mes_line_skip(l);
        if (mes_line_match(l, "="))
            return 0x5E;
        if (mes_line_match(l, "|"))
            return 0x52;
        return 0x4D;
    case '}':
        t = 0x33;
        break;
    case '~':
        t = 0x50;
        break;
    default:
        if (c < 0x20) {
            t = 0;
            break;
        }
        t = mes_lex_id(lx);
        if (t != 0)
            return t;
        t = 0x1E;
        break;
    }
    mes_line_skip(l);
    return t;
}

int mes_lex_peek(MesLex *lx)
{
    int t;

    mes_stack_check(lx->ctx);
    t = lx->tok;
    while (t == 0 || t == 0x65) {
        t = mes_lex_token_sub(lx);
        if (t != 0) {
            lx->prev = lx->tok;
            lx->tok = t;
        }
    }
    return t;
}

int mes_lex_peek_lf(MesLex *lx)
{
    int t;

    mes_stack_check(lx->ctx);
    for (t = lx->tok; t == 0;) {
        if ((t = mes_lex_token_sub(lx)) != 0) {
            lx->prev = lx->tok;
            lx->tok = t;
        }
    }
    return t;
}

void mes_lex_initialize(void)
{
    int i;
    MesReserved *r;
    const char *p;
    unsigned int h;
    int len;
    char c;

    for (i = 0; i < 31; i++)
        mes_lex_reserved_hash[i] = NULL;
    for (r = mes_lex_reserved; (p = r->name) != NULL; r++) {
        h = 0;
        len = 0;
        while (*p != 0) {
            h = (h * 37) ^ (unsigned short)*p++;
            len++;
        }
        r->hash = h;
        r->len = len;
        h %= 31;
        r->next = mes_lex_reserved_hash[h];
        mes_lex_reserved_hash[h] = r;
    }
}

