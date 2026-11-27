/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef unsigned short UCSChar;
typedef struct MesLine {
    int (*getc)(void *arg);
    void *arg;
    unsigned char eof;
    unsigned char bol;
    unsigned char fA;
    unsigned char len;
    UCSChar buf[16];
    unsigned short f2C;
    unsigned short line;
    unsigned short col;
    int pos;
} MesLine;
void *MEM_malloc(int heap, unsigned int size);
int mes_line_peekn();
int mes_line_skipn();
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */


MesLine *mes_line_new(int (*getc)(void *), void *arg, int flag)
{
    MesLine *l = MEM_malloc(0, sizeof(MesLine));

    if (l != NULL) {
        l->getc = getc;
        l->arg = arg;
        l->eof = 0;
        l->bol = 1;
        l->fA = flag;
        l->len = 0;
        l->f2C = 0;
        l->line = 1;
        l->col = 1;
        l->pos = 0;
    }
    return l;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_line_free(int arg0) {
    MEM_free(0, arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_line_getc(void *arg0) {
    int temp_v0;
    int var_v1;

    var_v1 = 0;
    if (M2C_FIELD(arg0, unsigned char *, 8) == 0) {
        temp_v0 = M2C_FIELD(arg0, int (**)(int), 0)(M2C_FIELD(arg0, int *, 4));
        var_v1 = temp_v0;
        if (temp_v0 >= 0) {
            M2C_FIELD(arg0, int *, 0x34) = (int) (M2C_FIELD(arg0, int *, 0x34) + 1);
        } else {
            M2C_FIELD(arg0, unsigned char *, 8) = 1U;
            var_v1 = 0;
        }
    }
    return var_v1;
}

UCSChar mes_line_fill(MesLine *l)
{
    int c = mes_line_getc(l);
    int c2;

    if (l->fA == 1) {
        if ((c & 0xE0) == 0xC0) {
            c = (c & 0x1F) << 6;
            c |= mes_line_getc(l) & 0x3F;
        } else if ((c & 0xF0) == 0xE0) {
            c = (c & 0xF) << 12;
            c |= (mes_line_getc(l) & 0x3F) << 6;
            c |= mes_line_getc(l) & 0x3F;
        } else if ((c & 0xF8) == 0xF0) {
            c = ((c & 7) << 6) | 0xD800;
            c |= (mes_line_getc(l) & 0x3F) << 2;
            c2 = mes_line_getc(l);
            c |= (unsigned int)(c2 & 0x30) >> 4;
            c -= 0x40;
            c2 = ((c2 & 0xF) << 6) | 0xCD00;
            c2 |= mes_line_getc(l) & 0x3F;
            l->buf[l->len++] = c;
            l->buf[l->len++] = c2;
            return c;
        }
    } else if (l->fA == 2) {
        c = (c << 8) | mes_line_getc(l);
    } else if (l->fA == 3) {
        c |= mes_line_getc(l) << 8;
    } else if (l->fA == 4) {
        if (c & 0x80)
            c = (c << 8) | mes_line_getc(l);
    }
    l->buf[l->len++] = c;
    return c;
}

int mes_line_peekn(MesLine *l, int n)
{
    int i, j;
    int c, d;

    while (!l->eof && n >= (i = l->len)) {
        c = mes_line_fill(l);
        if (mes_util_is_line_terminator(c)) {
            while (!l->eof) {
                if (i + 1 >= l->len)
                    mes_line_fill(l);
                if (l->eof)
                    break;
                d = l->buf[i + 1];
                if (d == c)
                    break;
                if (!mes_util_is_line_terminator(d))
                    break;
                for (j = i + 2; j < l->len; j++)
                    l->buf[j - 1] = l->buf[j];
                l->len--;
            }
            l->buf[i] = '\n';
            for (j = i + 1; j < l->len; j++) {
                if (mes_util_is_line_terminator(l->buf[j]))
                    l->buf[j] = '\n';
            }
        }
    }
    if (n < l->len)
        return l->buf[n];
    return 0;
}

int mes_line_skipn(MesLine *l, int n)
{
    int i, j;

    mes_line_peekn(l, n - 1);
    for (i = 0; i < n && i < l->len; i++) {
        if (l->buf[i] == '\n') {
            l->line++;
            l->bol = 1;
            l->col = 1;
        } else {
            l->col++;
            l->bol = 0;
        }
    }
    i = n;
    for (j = 0; i < l->len; i++, j++)
        l->buf[j] = l->buf[i];
    if (n < l->len)
        l->len -= n;
    else
        l->len = 0;
}

int mes_line_peek(void *l)
{
    return mes_line_peekn(l, 0);
}

int mes_line_skip(void *l)
{
    return mes_line_skipn(l, 1);
}

int mes_line_match(MesLine *l, const char *s)
{
    int i = 0;
    UCSChar c;

    while ((c = *s++) != 0) {
        if (mes_line_peekn(l, i) != c)
            return 0;
        i++;
    }
    mes_line_skipn(l, i);
    return 1;
}
