/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
BOX *createInlineBox(void *ctx, BOX *parent, BOX *prev);
BOX *createBlockBox(void *ctx, BOX *parent, BOX *prev);
BOX *createBox(void *ctx, int type);
void linkBox(BOX *box, BOX *parent, BOX *prev);
void initNoneContent(BOX *box, void *ctx);
void font_attr(void *node, BOX *box);
M2C_UNK applyCSSExtStyleSheetToBox(int, void *);    /* extern */
M2C_UNK applyCSSInlinePropertyToBox(int, void *);   /* extern */
M2C_UNK initBoxProperty(void *);                    /* extern */



typedef struct UICOLORS { int color[4][7]; } UICOLORS;
extern void *ui_global;
#define TEXTCOLOR(b) ((b)->style->unk64 = ((UICOLORS *)ui_global)->color[(b)->style->unk6A][(b)->style->fontSize])
char *getDOMAttributeValue(void *node, void *name);
int colorValue(char *s);
void MEM_free(void *pool, void *p);
int atoi(const char *s);
long strtol(const char *s, char **end, int base);
extern unsigned char _DOMcolor;
extern unsigned char _DOMsize;
typedef struct { int behavior; int direction; int loop; } MGEOM;
void initMarqueeContent(BOX *box, void *node);
BOX *getParentBlockBox(BOX *box);
int getContainingBlockWidth(BOX *box);
void attr_BGCOLOR(void *node, BOX *box);
void attr_HSPACE(void *node, BOX *box);
void attr_VSPACE(void *node, BOX *box);
int strcasecmp(const char *a, const char *b);
unsigned int strlen(const char *s);
extern unsigned char _DOMbehavior;
extern unsigned char _DOMdirection;
extern unsigned char _DOMloop;
extern unsigned char _DOMwidth;
extern unsigned char _DOMheight;
void font_attr(void *node, BOX *box) {
    char *s;
    char *end;
    int n;

    s = getDOMAttributeValue(node, &_DOMcolor);
    if (s != NULL) {
        box->style->unk54 = colorValue(s);
        MEM_free(0, s);
    }
    s = getDOMAttributeValue(node, &_DOMsize);
    if (s != NULL) {
        if (*s == '+') {
            n = atoi(s + 1);
            if (n > 0) {
                box->style->fontSize += n;
            }
        } else if (*s == '-') {
            n = atoi(s + 1);
            if (n > 0) {
                box->style->fontSize -= n;
            }
        } else {
            n = strtol(s, &end, 10);
            if (end != s) {
                n = n < 1 ? 1 : n;
                if (n > 7) {
                    n = 7;
                }
                box->style->fontSize = n - 1;
            }
        }
        if (box->style->fontSize > 6) {
            box->style->fontSize = 6;
        }
        if (box->style->fontSize < 0) {
            box->style->fontSize = 0;
        }
        TEXTCOLOR(box);
        MEM_free(0, s);
    }
}

BOX *html_BASEFONT(void *node, BOX *parent, BOX *prev) {
    BOX *box;

    if (getBoxByHTML(parent, 0x2C) != NULL) {
        box = getBodyBox(parent);
        if (box == NULL)
            return NULL;
    } else {
        box = createBox(node, 1);
        if (box == NULL)
            return NULL;
        linkBox(box, parent, prev);
        box->display = 0;
        box->html = 9;
        initNoneContent(box, node);
        initBoxProperty(box);
    }
    font_attr(node, box);
    return box->content == 1 ? NULL : box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_CENTER(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x13;
    initBoxProperty(box);
    box->style->unk6F = 2;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_FONT(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x22;
    font_attr(node, box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_ISINDEX(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_S(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x50;
    box->style->unk6C[0] |= 4;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_STRIKE(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x50;
    box->style->unk6C[0] |= 4;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_U(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x5F;
    box->style->unk6C[0] |= 2;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_BLINK(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    initNoneContent(box, node);
    box->display = 1;
    box->html = 0xD;
    initBoxProperty(box);
    box->style->unk6C[0] |= 8;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_MARQUEE(void *node, BOX *parent, BOX *prev) {
    BOX *box;
    char *s;
    int n;
    int r;

    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    initMarqueeContent(box, node);
    box->display = 0;
    box->html = 0x3C;
    initBoxProperty(box);
    box->width = getContainingBlockWidth(getParentBlockBox(box));
    attr_BGCOLOR(node, box);
    s = getDOMAttributeValue(node, &_DOMbehavior);
    if (s != NULL) {
        if (strcasecmp(s, "SCROLL") == 0) {
            ((MGEOM *)box->geom)->behavior = 1;
        } else if (strcasecmp(s, "SLIDE") == 0) {
            ((MGEOM *)box->geom)->behavior = 2;
        } else {
            r = strcasecmp(s, "ALTERNATE");
            ((MGEOM *)box->geom)->behavior = r == 0 ? 3 : 1;
        }
        MEM_free(0, s);
    } else {
        ((MGEOM *)box->geom)->behavior = 1;
    }
    s = getDOMAttributeValue(node, &_DOMdirection);
    if (s != NULL) {
        r = strcasecmp(s, "RIGHT");
        ((MGEOM *)box->geom)->direction = r == 0 ? 2 : 1;
        MEM_free(0, s);
    } else {
        ((MGEOM *)box->geom)->direction = 1;
    }
    s = getDOMAttributeValue(node, &_DOMloop);
    if (s != NULL) {
        ((MGEOM *)box->geom)->loop = atoi(s);
        MEM_free(0, s);
    }
    s = getDOMAttributeValue(node, &_DOMwidth);
    if (s != NULL) {
        n = strlen(s);
        if (s[n - 1] == '%') {
            s[n - 1] = 0;
            n = atoi(s);
            if (n > 0) {
                box->style->flags &= ~3;
                box->style->flags |= 2;
                box->style->width = n;
            }
        } else {
            n = atoi(s);
            if (n > 0) {
                box->style->flags &= ~3;
                box->style->flags |= 1;
                box->style->width = n;
            }
        }
        MEM_free(0, s);
    }
    s = getDOMAttributeValue(node, &_DOMheight);
    if (s != NULL) {
        n = strlen(s);
        if (s[n - 1] == '%') {
            s[n - 1] = 0;
            n = atoi(s);
            if (n > 0) {
                box->style->flags &= ~0xC;
                box->style->flags |= 8;
                box->style->height = n;
            }
        } else {
            n = atoi(s);
            if (n > 0) {
                box->style->flags &= ~0xC;
                box->style->flags |= 4;
                box->style->height = n;
            }
        }
        MEM_free(0, s);
    }
    attr_HSPACE(node, box);
    attr_VSPACE(node, box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    if ((box->style->flags & 3) == 1) {
        box->width = box->style->width;
    }
    if (((box->style->flags & 0xC) >> 2) == 1) {
        box->height = box->style->height;
    }
    return box;
}

BOX *html_NOBR(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x3F;
    initNoneContent(box, node);
    initBoxProperty(box);
    box->style->unk74 = 2;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}
