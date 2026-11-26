/* parser context types used by parseStrings/parser, recovered from the asm */
#ifndef PARSE_STR_H
#define PARSE_STR_H

typedef unsigned short PChar;

typedef struct PBuf {
    PChar *cur;
    int x04;
    int x08;
    int count;                  /* 0x0C */
    PChar *base;                /* 0x10 */
} PBuf;

typedef struct PTagCounts {
    unsigned short n[95];
} PTagCounts;

typedef struct PCtx {
    int x00[6];
    PBuf *buf;                  /* 0x18 */
    int x1C[9];
    int pos;                    /* 0x40 */
    int x44[4];
    PTagCounts tags;            /* 0x54 */
} PCtx;

typedef struct PTag {
    int x00;
    int x04;
    short x08;
    short id;                   /* 0x0A */
} PTag;

typedef struct PDStr {
    int x00;
    int len;                    /* 0x04 */
    PChar *data;                /* 0x08 */
} PDStr;

typedef struct PMb {
    PChar *str;
    int len;
} PMb;

typedef struct PCtxList {
    void **items;
    int n;
    int cap;
} PCtxList;

typedef struct PStrBuf {
    PChar *data;
    int cap;
    int len;
} PStrBuf;

#endif
