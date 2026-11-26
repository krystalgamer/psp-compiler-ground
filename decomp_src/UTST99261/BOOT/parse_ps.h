/* parser task (ps_*) types, recovered from the asm */
#ifndef PARSE_PS_H
#define PARSE_PS_H

typedef struct ExMsgBox {
    int id;
    void *x04;
    void *x08;
    void *x0C;
    struct ExMsgBox *prev;            /* 0x10 */
    struct ExMsgBox *next;            /* 0x14 */
} ExMsgBox;

typedef struct ExMsgBoxList {
    int count;
    ExMsgBox *first;
    ExMsgBox *last;
} ExMsgBoxList;

typedef struct PsMsg {
    int type;
    int arg[7];
} PsMsg;

extern ExMsgBoxList exMsgBoxList;
ExMsgBox *ps_getExMsgBox();

#endif
