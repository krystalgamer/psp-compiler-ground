/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
#include "m2c_macros.h"
extern char lo_global[];
int Element_getAttribute(DOMString *s, void *elem, void *name);
char *DOMStringtoUTF8(DOMString *s);
int strcmp(const char *a, const char *b);
void adaptArea(void *a0, void *area, void *a2, s8 n);
int MEM_malloc(M2C_UNK, M2C_UNK);                   /* extern */
void MEM_free(M2C_UNK, void *);                  /* extern */


struct MAPAREA;
void *createAreaInfo(s8 type, struct MAPAREA *ar, void *node);
void addFocusList(void *ctx, int kind, void *node, short tabindex, void *info);
void *appendFocusList(void *ctx, int kind, void *node, void *last, void *info);
typedef struct { char *name; void (*func)(void *node, void *box); } TagAfter;
extern TagAfter jt_after[];
extern int D_001F5E20;
int DOMStringcasecmpCharFast(DOMString *s, char *name);
void *Node_getBox(void *node);
typedef struct { double x; double y; double angle; int pad[2]; } MAPPT;
typedef struct { MAPPT *pts; int n; int cap; int uC; double maxx; double maxy; double minx; double miny; int center; } MAPPOLY;
double atan2(double y, double x);
typedef struct MAPAREA { s16 type; s16 u2; void *x4; void *x8; struct MAPAREA *next; MAPPOLY poly; } MAPAREA;
void parseCoords(s16 type, char *coords, void *p);
int strcasecmp(const char *a, const char *b);
typedef struct { char *name; int (*func)(void *node, void *box, void *a2); } TagBranch;
extern TagBranch jt[];
extern int D_001F5E1C;
extern char D_00139428[], D_00139430[], D_0013950C[];
int Element_getTagName(DOMString *s, void *elem);
int DOMStringcasecmpChar(DOMString *s, char *str);
typedef struct { s8 kind; int x; int y; int w; int h; MAPAREA *area; } MAPINFO;
typedef struct { int x; int y; double r; } MAPCIRCLE;
extern const double D_00139300;
void *MEM_realloc(void *pool, void *p, unsigned int size);
int atoi(const char *s);
char *strchr(const char *s, int c);
extern const double D_001392D8;
typedef struct LmStyle {
    int bg;                           /* 0x0 */
    u8 pad4[0x2C];
    s16 m30, m32, m34, m36;           /* 0x30 */
    int b38, b3C, b40, b44;           /* 0x38 */
    u8 pad48[0xC];
    int color;                        /* 0x54 */
    int link, vlink, alink;           /* 0x58 */
    int fontColor;                    /* 0x64 */
    s16 fontSize;                     /* 0x68 */
    s16 fontStyle;                    /* 0x6A */
    u8 u6C, u6D, u6E, u6F, u70, u71, u72, u73, u74;
} LmStyle;
typedef struct LmBox { struct LmBox *parent; u8 pad4[0x20]; LmStyle *style; u8 pad28[0x12]; s16 html; } LmBox;
typedef struct { int color[4][7]; } LmUiGlobal;
extern LmUiGlobal *ui_global;
extern char *gPREF_UI;
LmBox *getBodyBox(LmBox *box);
int colorValue(char *s);
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", parseCoords);

#ifndef NULL
#define NULL ((void *)0)
#endif

void initAreaBuffer(void *arg0) {
    M2C_FIELD(arg0, int *, 0) = 0;
    M2C_FIELD(arg0, int *, 0xC) = 0;
    M2C_FIELD(arg0, int *, 0x10) = 0;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = 0;
    M2C_FIELD(arg0, int *, 0x1C) = 0;
    M2C_FIELD(arg0, int *, 0x20) = 0;
    M2C_FIELD(arg0, int *, 0x24) = 0;
    M2C_FIELD(arg0, int *, 0x28) = 0;
    M2C_FIELD(arg0, int *, 0x2C) = 0;
    M2C_FIELD(arg0, int *, 0x30) = 0;
    M2C_FIELD(arg0, int *, 0x34) = 0;
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, int *, 8) = 0xA;
    M2C_FIELD(arg0, int *, 0) = MEM_malloc(0, 0x140);
}

int insertBuffer_90298(int x, int y, MAPPOLY *p) {
    if (p->n >= p->cap) {
        p->cap = p->cap * 2;
        p->pts = MEM_realloc(NULL, p->pts, p->cap * sizeof(MAPPT));
    }
    p->pts[p->n].x = x;
    p->pts[p->n].y = y;
    if (p->n == 0) {
        p->maxx = x;
        p->maxy = y;
        p->minx = x;
        p->miny = y;
    }
    if (x > p->maxx) {
        p->maxx = x;
    } else if (x < p->minx) {
        p->minx = x;
        p->center = p->n;
    }
    if (y > p->maxy) {
        p->maxy = y;
    } else if (y < p->miny) {
        p->miny = y;
    }
    p->n++;
    return 0;
}

void calcAngle(MAPPOLY *a) {
    int i;
    int c;
    double d;
    for (i = 0; i < a->n; i++) {
        c = a->center;
        if (i != c) {
            d = atan2(a->pts[i].y - a->pts[c].y, a->pts[i].x - a->pts[c].x);
            a->pts[i].angle = d;
        } else {
            a->pts[i].angle = 0;
        }
    }
}

int sortPoint(MAPPOLY *a) {
    int i;
    int j;
    MAPPT tmp;
    for (i = 0; i < a->n; i++) {
        for (j = i; j > 0 && a->pts[j - 1].angle >= a->pts[j].angle; j--) {
            if (a->pts[j - 1].angle != a->pts[j].angle) {
                tmp = a->pts[j];
                a->pts[j] = a->pts[j - 1];
                a->pts[j - 1] = tmp;
            } else if (a->pts[j - 1].x > a->pts[j].x) {
                tmp = a->pts[j];
                a->pts[j] = a->pts[j - 1];
                a->pts[j - 1] = tmp;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", checkInterior);

#ifndef NULL
#define NULL ((void *)0)
#endif

void initMapList(void *arg0) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x18);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0) = 0;
        M2C_FIELD(temp_v0, int *, 4) = 0;
        M2C_FIELD(temp_v0, int *, 8) = 0;
        M2C_FIELD(temp_v0, int *, 0xC) = 0;
        M2C_FIELD(temp_v0, int *, 0x10) = 0;
        M2C_FIELD(temp_v0, int *, 0x14) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x74) = temp_v0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x78) = temp_v0;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeMapList(void *arg0) {
    void *temp_s0;
    void *temp_s1;
    void *temp_s4;
    void *var_a1;
    void *var_s0;
    void *var_s2;

    var_s2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x74);
    if (var_s2 != NULL) {
        do {
            var_s0 = M2C_FIELD(var_s2, void **, 0xC);
            temp_s4 = M2C_FIELD(var_s2, void **, 0x14);
            if (var_s0 != NULL) {
                do {
                    temp_s1 = M2C_FIELD(var_s0, void **, 0xC);
                    if (M2C_FIELD(var_s0, short *, 0) == 4) {
                        MEM_free(0, M2C_FIELD(var_s0, void **, 0x10));
                    }
                    MEM_free(0, var_s0);
                    var_s0 = temp_s1;
                } while (temp_s1 != NULL);
            }
            var_a1 = M2C_FIELD(var_s2, void **, 4);
            if (var_a1 != NULL) {
                do {
                    temp_s0 = M2C_FIELD(var_a1, void **, 8);
                    MEM_free(0, var_a1);
                    var_a1 = temp_s0;
                } while (temp_s0 != NULL);
            }
            MEM_free(0, var_s2);
            var_s2 = temp_s4;
        } while (temp_s4 != NULL);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), int *, 0x74) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);
unsigned int strlen(const char *s);
char *strcpy(char *d, const char *s);

void *addMapList(void *arg0, signed char *arg1) {
    signed char *temp_a0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *var_s1;

    temp_v0 = getMapList();
    var_s1 = temp_v0;
    if (temp_v0 == NULL) {
        temp_v0_2 = MEM_malloc(0, strlen(arg1) + 0x19);
        var_s1 = temp_v0_2;
        temp_a0 = temp_v0_2 + 0x18;
        M2C_FIELD(temp_v0_2, signed char **, 0) = temp_a0;
        strcpy(temp_a0, arg1);
        temp_v0_3 = MEM_malloc(0, 0x48);
        memset(temp_v0_3, 0, 0x48U);
        M2C_FIELD(var_s1, void **, 0x10) = temp_v0_3;
        M2C_FIELD(var_s1, void **, 0xC) = temp_v0_3;
        temp_v0_4 = MEM_malloc(0, 0xC);
        M2C_FIELD(temp_v0_4, int *, 0) = 0;
        M2C_FIELD(temp_v0_4, int *, 4) = 0;
        M2C_FIELD(temp_v0_4, int *, 8) = 0;
        M2C_FIELD(var_s1, void **, 8) = temp_v0_4;
        M2C_FIELD(var_s1, void **, 4) = temp_v0_4;
        M2C_FIELD(var_s1, int *, 0x14) = 0;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x78), void **, 0x14) = var_s1;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x78) = var_s1;
    }
    return var_s1;
}

void *addMapUserList(void *a0, void *a1, void *name, void *data) {
    void *map;
    void *u;
    if (name == NULL) {
        return NULL;
    }
    map = addMapList(a0, a1);
    u = (void *)MEM_malloc(0, 0xC);
    M2C_FIELD(u, void **, 0) = name;
    M2C_FIELD(u, void **, 4) = data;
    M2C_FIELD(u, void **, 8) = NULL;
    M2C_FIELD(M2C_FIELD(map, void **, 8), void **, 8) = u;
    M2C_FIELD(map, void **, 8) = u;
    return u;
}

void *getMapList(void *box, char *name) {
    void *m;
    for (m = M2C_FIELD(M2C_FIELD(M2C_FIELD(box, void **, 0x20), void **, 0x74), void **, 0x14); m != NULL; m = M2C_FIELD(m, void **, 0x14)) {
        if (strcmp(M2C_FIELD(m, char **, 0), name) == 0) {
            break;
        }
    }
    return m;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001392D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001392DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001392E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001392E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001392E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001392EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001392F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001392F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001392F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001392FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_00139300);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_00139304);

MAPAREA *addAreaList(void *list, void *a1, char *shape, char *coords, void *t0) {
    MAPAREA *ar;
    if (shape == NULL && coords == NULL) {
        return NULL;
    }
    ar = (MAPAREA *)MEM_malloc(0, 0x48);
    ar->x4 = a1;
    ar->x8 = t0;
    if (coords == NULL) {
        ar->type = 1;
    } else if (shape == NULL || strcasecmp(shape, "rect") == 0) {
        ar->type = 2;
        parseCoords(2, coords, &ar->poly);
    } else if (strcasecmp(shape, "circle") == 0) {
        ar->type = 3;
        parseCoords(3, coords, &ar->poly);
    } else if (strcasecmp(shape, "poly") == 0 || strcasecmp(shape, "polygon") == 0) {
        ar->type = 4;
        initAreaBuffer(&ar->poly);
        parseCoords(ar->type, coords, &ar->poly);
        calcAngle(&ar->poly);
        sortPoint(&ar->poly);
    } else {
        ar->type = 1;
    }
    ar->next = NULL;
    M2C_FIELD(M2C_FIELD(list, MAPAREA **, 0x10), MAPAREA **, 0xC) = ar;
    M2C_FIELD(list, MAPAREA **, 0x10) = ar;
    return ar;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
signed char getAreaIndex(void *arg0, int arg1) {
    int var_a0;
    signed char var_a2;
    signed char var_v0;

    var_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), int *, 0xC);
    var_a2 = 1;
    if ((var_a0 != 0) & (var_a0 != arg1)) {
        do {
            var_a0 = M2C_FIELD(var_a0, int *, 0xC);
            var_a2 += 1;
        } while ((var_a0 != 0) & (var_a0 != arg1));
    }
    var_v0 = var_a2;
    if (var_a0 == 0) {
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", getAreaList);

void adaptArea(void *ctx, void *map, void *link, s8 type) {
    void *info = createAreaInfo(type, map, M2C_FIELD(link, void **, 0));
    void *r;

    if (info != NULL) {
        if (M2C_FIELD(map, int *, 8) > 0) {
            addFocusList(ctx, 1, M2C_FIELD(link, void **, 0), M2C_FIELD(map, int *, 8), info);
        } else {
            r = appendFocusList(ctx, 1, M2C_FIELD(link, void **, 0), M2C_FIELD(link, void **, 4), info);
            if (r != NULL)
                M2C_FIELD(link, void **, 4) = r;
        }
    }
}

void adaptAreaList(void *a0, void *map, void *a2) {
    void *a;
    int i = 1;
    for (a = M2C_FIELD(M2C_FIELD(map, void **, 0xC), void **, 0xC); a != NULL; a = M2C_FIELD(a, void **, 0xC)) {
        adaptArea(a0, a, a2, i);
        i++;
    }
}

void *createAreaInfo(s8 type, MAPAREA *ar, void *node) {
    MAPINFO *inf;
    int x, y, w, h;
    int r;
    double d;
    inf = (MAPINFO *)MEM_malloc(0, 0x18);
    if (inf == NULL) {
        return NULL;
    }
    if (ar->type == 2) {
        int *rc = (int *)&ar->poly;
        x = rc[0];
        y = rc[1];
        w = rc[2] - x;
        h = rc[3] - y;
    } else if (ar->type == 3) {
        MAPCIRCLE *c = (MAPCIRCLE *)&ar->poly;
        if (c->r <= D_00139300) {
            if (M2C_FIELD(node, int *, 0x18) < M2C_FIELD(node, int *, 0x1C)) {
                d = M2C_FIELD(node, int *, 0x18);
            } else {
                d = M2C_FIELD(node, int *, 0x1C);
            }
            r = c->r * d;
        } else {
            r = c->r;
        }
        x = c->x - r;
        y = c->y - r;
        w = h = r * 2;
    } else if (ar->type == 4) {
        MAPPOLY *p = &ar->poly;
        x = p->minx;
        y = p->miny;
        w = p->maxx - p->minx;
        h = p->maxy - p->miny;
    } else {
        x = M2C_FIELD(node, int *, 0x10);
        y = M2C_FIELD(node, int *, 0x14);
        w = M2C_FIELD(node, int *, 0x18);
        h = M2C_FIELD(node, int *, 0x1C);
    }
    inf->kind = type;
    inf->x = x;
    inf->y = y;
    inf->w = w;
    inf->h = h;
    inf->area = ar;
    return inf;
}

void initBoxProperty(LmBox *box)
{
    LmBox *parent;
    LmBox *body;
    int size;
    char *bg;

    memset(box->style, 0, 0x78);
    box->style->m30 = 2;
    box->style->m32 = 2;
    box->style->m34 = 2;
    box->style->m36 = 2;
    parent = box->parent;
    if (parent != NULL && box->html != 0x25 && box->html != 0x24) {
        box->style->bg = parent->style->bg;
        box->style->link = parent->style->link;
        box->style->vlink = parent->style->vlink;
        box->style->alink = parent->style->alink;
        box->style->u6F = parent->style->u6F;
        box->style->u73 = parent->style->u73;
        box->style->u6E = parent->style->u6E;
        size = parent->style->fontSize;
        if (box->html != 0x68) {
            box->style->color = parent->style->color;
            box->style->u6C = parent->style->u6C;
            box->style->fontStyle = parent->style->fontStyle;
            box->style->fontColor = ui_global->color[box->style->fontStyle][size];
            box->style->u74 = parent->style->u74;
        } else {
            body = getBodyBox(box);
            box->style->color = body->style->color;
            box->style->u6C = 0;
            box->style->fontStyle = 0;
            box->style->fontColor = ui_global->color[0][2];
            box->style->u74 = 0;
        }
        if ((u8)(parent->style->u70 - 1) < 2)
            box->style->u70 = parent->style->u70;
    } else {
        box->style->bg = colorValue(M2C_FIELD(gPREF_UI, char **, 0x38) != NULL ? M2C_FIELD(gPREF_UI, char **, 0x38) : "white");
        box->style->color = colorValue("black");
        box->style->link = colorValue("blue");
        box->style->vlink = colorValue("purple");
        box->style->alink = colorValue("blue");
        box->style->u6F = 0;
        box->style->u6C = 0;
        size = 2;
        box->style->fontColor = ui_global->color[0][2];
    }
    box->style->b38 = box->style->color;
    box->style->b3C = box->style->color;
    box->style->b40 = box->style->color;
    box->style->b44 = box->style->color;
    if (size >= 7)
        size = 6;
    size = size < 0 ? 0 : size;
    box->style->fontSize = size;
}

int htmlTagBranch(void *node, void *box, void *a2) {
    DOMString s;
    int idx = D_001F5E1C;
    int lo;
    int hi;
    int mid;
    int c;
    Element_getTagName(&s, node);
    if (s.len != 0) {
        lo = 0;
        hi = D_001F5E1C - 1;
        do {
            mid = lo + (hi - lo) / 2;
            c = DOMStringcasecmpChar(&s, jt[mid].name);
            if (c == 0) {
                idx = mid;
                break;
            }
            if (c > 0) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        } while (lo <= hi);
    }
    if (M2C_FIELD(box, s16 *, 0x3A) == 0x25 && strcmp(jt[idx].name, D_00139428) != 0 && strcmp(jt[idx].name, D_00139430) != 0) {
        return 0;
    }
    if ((*(int *)(lo_global + 0x70)) != 0 && strcmp(jt[idx].name, D_0013950C) != 0) {
        return 0;
    }
    return jt[idx].func(node, box, a2);
}

void htmlTagBranchAfter(void *node) {
    DOMString s;
    int i;
    int idx = -1;

    Element_getTagName(&s, node);
    if (s.len != 0) {
        for (i = 0; i < D_001F5E20; i++) {
            if (DOMStringcasecmpCharFast(&s, jt_after[i].name) == 0) {
                idx = i;
                break;
            }
        }
    }
    if (idx >= 0)
        jt_after[idx].func(node, Node_getBox(node));
}

DOMString *newDOMString(unsigned char *s, int len) {
    DOMString *d = (DOMString *)MEM_malloc(0, 0xC);
    unsigned short *p;
    unsigned char *q;
    int i;

    if (d == NULL)
        return NULL;
    M2C_FIELD(d, int *, 0) = len;
    M2C_FIELD(d, int *, 4) = len;
    M2C_FIELD(d, int *, 8) = MEM_malloc(0, len * 2);
    if (M2C_FIELD(d, int *, 8) == 0) {
        MEM_free(0, d);
        return NULL;
    }
    q = s;
    p = M2C_FIELD(d, unsigned short **, 8);
    for (i = 0; i < len; i++)
        *p++ = *q++;
    return d;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeDOMString(void *arg0) {
    MEM_free(0, M2C_FIELD(arg0, void **, 8));
    MEM_free(0, arg0);
}

char *getDOMAttributeValue(void *elem, void *name) {
    DOMString s;
    char *r;
    Element_getAttribute(&s, elem, name);
    r = NULL;
    if (s.len != 0) {
        r = DOMStringtoUTF8(&s);
    }
    return r;
}

int getDOMAttributeValue_PositiveNum(void *elem, void *name) {
    DOMString s;
    char *str;
    int n;
    Element_getAttribute(&s, elem, name);
    if (s.len == 0) {
        return -1;
    }
    str = DOMStringtoUTF8(&s);
    if (str == NULL) {
        return -1;
    }
    n = atoi(str);
    if (n < 0) {
        n = 0;
    }
    MEM_free(0, str);
    return n;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_00139348);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_0013934C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_00139354);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_0013935C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_00139364);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_0013936C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_00139374);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_00139378);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_00139380);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_0013938C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_00139390);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_00139394);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_0013939C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001393A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001393B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001393B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_map", D_001393BC);
