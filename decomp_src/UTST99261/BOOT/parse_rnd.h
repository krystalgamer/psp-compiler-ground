#ifndef PARSE_RND_H
#define PARSE_RND_H

typedef struct RndAnimNode {
    struct RndAnimNode *next;
    void *box;
    void *arg;
    void *x0C;
} RndAnimNode;
typedef struct RndAnimImage {
    char x00[0x1C];
    int x1C;
} RndAnimImage;
typedef struct RndAnimGroup {
    struct RndAnimGroup *next;
    RndAnimImage *image;
    RndAnimNode *list;
} RndAnimGroup;
typedef struct RndBox {
    char x00[0x20];
    RndAnimImage **x20;
    char x24[0x14];
    short type;
} RndBox;
typedef struct RndGlobal {
    char x00[0xC];
    RndAnimNode *x0C;
    RndAnimGroup *x10;
    RndAnimNode *x14;
} RndGlobal;
typedef struct RndTime {
    int a;
    int b;
} RndTime;
extern RndGlobal rnd_global;

#endif
