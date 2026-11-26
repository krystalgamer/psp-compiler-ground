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

typedef struct PsLocation {
    int id;
    int x04;
    int x08;
    int x0C;
    struct PsLocation *prev;          /* 0x10 */
    struct PsLocation *next;          /* 0x14 */
    void *buf;                        /* 0x18 */
} PsLocation;

typedef struct PsDomBuild {
    int x[14];
} PsDomBuild;

typedef struct PsMqMsg {
    int x[4];
    int evt;                          /* 0x10 */
    int x14[3];
    void *data;                       /* 0x20 */
} PsMqMsg;

/* inter-task message */
typedef struct PsIpc {
    int type;
    int x04;
    int x08;
    int cmd;
    int x10;
    int x14;
    int x18;
    int x1C;
} PsIpc;

extern PsLocation *PS_LOCATION_HEAD;
extern PsLocation *D_0025B5CC;
extern ExMsgBoxList exMsgBoxList;
ExMsgBox *ps_getExMsgBox();

#endif
