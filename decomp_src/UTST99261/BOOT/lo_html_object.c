/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
extern char lo_global[];
BOX *createBox(void *ctx, int type);
BOX *getBodyBox(void *box);
void linkBox(BOX *box, BOX *parent, BOX *prev);
void initNoneContent(BOX *box, void *ctx);
void initBoxProperty(BOX *box);
void applyCSSExtStyleSheetToBox(void *node, BOX *box);
void applyCSSInlinePropertyToBox(void *node, BOX *box);
void delLinkBox(void *box);
void freeBox(void *box, int a1);



#ifndef NULL
#define NULL ((void *)0)
#endif
char *getDOMAttributeValue(void *node, void *name);
void MEM_free(int pool, void *p);
int html_IMG_inner(void *node, BOX *box);
extern unsigned char _DOMclassid;
extern unsigned char _DOMdata;
extern unsigned char _DOMtype;
typedef struct { int r[8]; int x20; int num; int x28; char *name; int x30; char *scrolling; int x38[3]; int cols; int x48[16]; int rows; } FRGEOM;
char *getTagName(void *node);
int strcmp(const char *a, const char *b);
void *Node_getParentNode(void *node);
int getFramenum(BOX *box);
void getFrameSizeFromFramesetBox(int *x, int *y, int *w, int *h, BOX *fs, int n);
void initBodyContent(BOX *box, void *node);
void attr_MARGINWIDTH(void *node, BOX *box);
void attr_MARGINHEIGHT(void *node, BOX *box);
void addFocusList(void *ctx, int kind, void *node, short tabindex, void *info);
void createFrameBorder(BOX *box, void *node, int *w, int *h, int *x, int *y);
void addBoxList(void *list, BOX *box);
void *lfm_createPageRegion(BOX *box, int w);
extern unsigned char _DOMscrolling;
extern unsigned char _DOMname;
typedef struct { char p[0x8C]; int w; int h; int x; int y; int x9C; int bcolor; int border; int num; int xAC; char *cols; char *rows; } FSGEOM;
void initFramesetContent(BOX *box, void *node);
void createFrameBorder_frameset(BOX *box, void *node, int *w, int *h, int *x, int *y);
void initFrameSize(BOX *box, char *cols, char *rows);
int colorValue(char *s);
int atoi(const char *s);
void *MEM_malloc(int pool, unsigned int size);
void *memcpy(void *d, const void *s, unsigned int n);
extern unsigned char _DOMbordercolor;
extern unsigned char _DOMborder;
extern unsigned char _DOMcols;
extern unsigned char _DOMrows;
int isImageMimeType(signed char *arg0) {
    return (unsigned int) (UTL_guessMIMEType(arg0) - 1) < 4U;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int isImageFileType(signed char *arg0) {
    return (unsigned int) (UTL_guessMIMETypeFromName(arg0) - 1) < 4U;
}

BOX *html_OBJECT(void *node, BOX *parent, BOX *prev) {
    BOX *box = NULL;
    char *classid;
    char *data;
    char *type;
    int img;

    classid = getDOMAttributeValue(node, &_DOMclassid);
    data = getDOMAttributeValue(node, &_DOMdata);
    if (data != NULL) {
        img = 0;
        type = getDOMAttributeValue(node, &_DOMtype);
        if (type != NULL) {
            if (isImageMimeType((signed char *)type) == 1) {
                img = 1;
            }
            MEM_free(0, type);
        } else {
            if (isImageFileType((signed char *)data) == 1) {
                img = 1;
            }
        }
        if (img == 1) {
            box = createBox(node, 1);
            if (box == NULL) {
                if (classid != NULL) {
                    MEM_free(0, classid);
                }
                if (data != NULL) {
                    MEM_free(0, data);
                }
                return NULL;
            }
            linkBox(box, parent, prev);
            box->display = 1;
            box->html = 0x42;
            html_IMG_inner(node, box);
            (*(int *)(lo_global + 0x70)) = 1;
        }
    }
    if (box == NULL) {
        box = createBox(node, 1);
        if (box == NULL) {
            return NULL;
        }
        linkBox(box, parent, prev);
        box->display = 1;
        box->html = 0x42;
        initNoneContent(box, node);
        initBoxProperty(box);
        applyCSSExtStyleSheetToBox(node, box);
        applyCSSInlinePropertyToBox(node, box);
    }
    if (classid != NULL) {
        MEM_free(0, classid);
    }
    if (data != NULL) {
        MEM_free(0, data);
    }
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void html_OBJECT_after(void) {
    (*(int *)(lo_global + 0x70)) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_PARAM(void) {
    return 0;
}

BOX *html_FRAME(void *node, BOX *parent, BOX *prev) {
    int x;
    int y;
    int w;
    int h;
    BOX *body;
    void *n;
    char *t;
    BOX *fs;
    int num;
    BOX *box;

    body = getBodyBox(parent);
    if (body == NULL) {
        return NULL;
    }
    for (n = node; n != NULL; n = Node_getParentNode(n)) {
        t = getTagName(n);
        if (t != NULL && strcmp(t, "FRAMESET") == 0) {
            break;
        }
    }
    if (n == NULL) {
        return NULL;
    }
    for (fs = parent; fs != NULL; fs = fs->parent) {
        if (fs->content == 2) {
            break;
        }
    }
    if (fs == NULL) {
        return NULL;
    }
    num = getFramenum(fs);
    if (((FRGEOM *)fs->geom)->cols != 0 && ((FRGEOM *)fs->geom)->rows != 0) {
        if (num >= ((FRGEOM *)fs->geom)->cols * ((FRGEOM *)fs->geom)->rows) return NULL;
    } else if (((FRGEOM *)fs->geom)->cols != 0) {
        if (num >= ((FRGEOM *)fs->geom)->cols) return NULL;
    } else if (((FRGEOM *)fs->geom)->rows != 0) {
        if (num >= ((FRGEOM *)fs->geom)->rows) return NULL;
    } else {
        return NULL;
    }
    getFrameSizeFromFramesetBox(&x, &y, &w, &h, fs, num);
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, fs, prev);
    box->display = 0;
    box->html = 0x24;
    initBodyContent(box, node);
    initBoxProperty(box);
    box->style->unk28 = 0;
    box->style->unk2A = 0;
    box->style->unk2C = 0;
    box->style->unk2E = 0;
    attr_MARGINWIDTH(node, box);
    attr_MARGINHEIGHT(node, box);
    ((FRGEOM *)box->geom)->num = num;
    ((FRGEOM *)box->geom)->scrolling = getDOMAttributeValue(node, &_DOMscrolling);
    addFocusList(box, 0, box, 0, 0);
    createFrameBorder(box, node, &w, &h, &x, &y);
    ((FRGEOM *)box->geom)->r[0] = w;
    ((FRGEOM *)box->geom)->r[1] = h;
    ((FRGEOM *)box->geom)->r[2] = x;
    ((FRGEOM *)box->geom)->r[3] = y;
    ((FRGEOM *)box->geom)->r[4] = x;
    ((FRGEOM *)box->geom)->r[5] = y;
    ((FRGEOM *)box->geom)->r[6] = 0;
    ((FRGEOM *)box->geom)->r[7] = 0;
    t = getDOMAttributeValue(node, &_DOMname);
    ((FRGEOM *)box->geom)->name = t;
    addBoxList((char *)body->geom + 0x48, box);
    box->region = lfm_createPageRegion(box, ((FRGEOM *)box->geom)->r[2]);
    return box;
}


BOX *html_FRAMESET(void *node, BOX *parent, BOX *prev) {
    int x;
    int y;
    int w;
    int h;
    BOX *body;
    BOX *box;
    int num = 0;
    char *s;
    char *cols;
    char *rows;

    body = getBodyBox(parent);
    if (body == NULL) {
        return NULL;
    }
    ((FRGEOM *)body->geom)->cols = 1;
    if (parent->content == 2) {
        num = getFramenum(parent);
        getFrameSizeFromFramesetBox(&x, &y, &w, &h, parent, num);
    } else {
        w = 0;
        h = 0;
        x = M2C_FIELD(body->geom, int *, 8);
        y = M2C_FIELD(body->geom, int *, 0xC);
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 0;
    box->html = 0x25;
    initFramesetContent(box, node);
    initBoxProperty(box);
    ((FSGEOM *)box->geom)->w = w;
    ((FSGEOM *)box->geom)->h = h;
    ((FSGEOM *)box->geom)->x = x;
    ((FSGEOM *)box->geom)->y = y;
    ((FSGEOM *)box->geom)->border = 4;
    if (parent->content == 2) {
        ((FSGEOM *)box->geom)->num = num;
        createFrameBorder_frameset(box, node, &w, &h, &x, &y);
        ((FSGEOM *)box->geom)->w = w;
        ((FSGEOM *)box->geom)->h = h;
        ((FSGEOM *)box->geom)->x = x;
        ((FSGEOM *)box->geom)->y = y;
    }
    s = getDOMAttributeValue(node, &_DOMbordercolor);
    if (s != NULL) {
        ((FSGEOM *)box->geom)->bcolor = colorValue(s);
        MEM_free(0, s);
    }
    s = getDOMAttributeValue(node, &_DOMborder);
    if (s != NULL) {
        ((FSGEOM *)box->geom)->border = atoi(s);
        MEM_free(0, s);
    }
    if (((FSGEOM *)box->geom)->border < 0) {
        ((FSGEOM *)box->geom)->border = 4;
    }
    cols = getDOMAttributeValue(node, &_DOMcols);
    rows = getDOMAttributeValue(node, &_DOMrows);
    if (cols == NULL && rows == NULL) {
        rows = MEM_malloc(0, 2);
        memcpy(rows, "*", 2);
    }
    initFrameSize(box, cols, rows);
    ((FSGEOM *)box->geom)->cols = cols;
    ((FSGEOM *)box->geom)->rows = rows;
    return box;
}

BOX *html_NOFRAMES(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 0;
    box->html = 0x40;
    initNoneContent(box, node);
    initBoxProperty(box);
    M2C_FIELD(getBodyBox(parent)->geom, int *, 0x88) = 1;
    return box;
}

void html_NOFRAMES_after(void *a0, void *box) {
    if (box != NULL) {
        M2C_FIELD(getBodyBox(box)->geom, int *, 0x88) = 0;
        delLinkBox(box);
        freeBox(box, 0);
    }
}

BOX *html_IFRAME(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x30;
    initNoneContent(box, node);
    initBoxProperty(box);
    return box;
}
