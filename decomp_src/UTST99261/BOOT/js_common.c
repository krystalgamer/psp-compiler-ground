/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct JsBuf {
    unsigned char *cur;
    unsigned char *end;
} JsBuf;
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
M2C_UNK mes_eval(int, int, int, int, int);          /* extern */
M2C_UNK mes_stack_init(M2C_UNK);                    /* extern */
M2C_UNK mes_window_set_global_property(int);        /* extern */


typedef struct JsFrame { char pad[0x18]; int x18; int x1C; } JsFrame;
typedef struct JsCtx { int x00; int x04; int list; int global; JsFrame *frame; int stop; int *sp; } JsCtx;
typedef struct JsCode { char pad[0x28]; int x28; } JsCode;
void *mes_line_new(int (*getc)(JsBuf *), JsBuf *buf, int n);
void *mes_lex_new(JsCtx *cx, void *line);
int mes_lex_peek(void *lex);
void mes_lex_free(void *lex);
void *mes_parse_program(JsCtx *cx, void *lex, int mode);
void mes_parse_node_free(void *node);
JsCode *mes_compile(JsCtx *cx, void *node);
JsCode *mes_compile_body(JsCtx *cx, void *node, int a, int b, int c);
void mes_list_free2(int list, int keep);
JsBuf *js_common_buffer_open(unsigned char *p, int len) {
    JsBuf *b;

    b = MEM_malloc(0, sizeof(JsBuf));
    if (b != NULL) {
        if (p == NULL || len == 0) {
            b->cur = NULL;
            b->end = NULL;
        } else {
            b->cur = p;
            b->end = p + len - 1;
        }
    }
    return b;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_common_buffer_close(int arg0) {
    MEM_free(0, arg0);
}

int js_common_buffer_getc(JsBuf *b) {
    if (b->cur != NULL && b->cur <= b->end) {
        return *b->cur++;
    }
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_common_eval(int arg0, int arg1, int arg2, int arg3, int arg4) {
    mes_stack_init(0x4000);
    mes_window_set_global_property(arg0);
    mes_eval(arg0, arg1, arg2, arg3, arg4);
}

int js_common_execute(JsCtx *cx, JsBuf *buf, int mode) {
    void *lex;
    int *sp;
    int result;
    int list;
    void *node;
    JsCode *code;

    mes_stack_init(0x4000);
    mes_window_set_global_property((int)cx);
    lex = mes_lex_new(cx, mes_line_new(js_common_buffer_getc, buf, 3));
    sp = cx->sp;
    result = 0;
    for (;;) {
        if (mes_lex_peek(lex) == 0x66) {
            break;
        }
        list = cx->list;
        node = mes_parse_program(cx, lex, mode);
        if (mode == 1) {
            code = mes_compile(cx, node);
        } else {
            code = mes_compile_body(cx, node, 0, 0, 0);
        }
        mes_parse_node_free(node);
        mes_list_free2(cx->list, list);
        cx->list = list;
        cx->sp = sp;
        if (mode == 1) {
            if (cx->stop == 0) {
                cx->sp = sp - 1;
                sp[-1] = (int)code;
                if (cx->frame != NULL) {
                    code->x28 = cx->frame->x18;
                    result = mes_eval((int)cx, (int)code, 0, cx->frame->x1C, 1);
                } else {
                    result = mes_eval((int)cx, (int)code, 0, cx->global, 1);
                }
                cx->sp++;
                if (cx->stop) {
                    cx->stop = 0;
                }
            }
        } else {
            result = (int)code;
            break;
        }
    }
    mes_lex_free(lex);
    return result;
}
