/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char _DOMa;
extern unsigned char _DOMhref;
void *Util_getNodeByTagName(void *node, void *tag);
int Element_hasAttribute(void *node, void *name);
void *Node_getParentNode(void *node);
void *getBodyBox(void *);
M2C_UNK *MEM_malloc(M2C_UNK, M2C_UNK);              /* extern */
extern M2C_UNK *head;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
int Node_getBox(int);                               /* extern */
M2C_UNK drawScroll(int, int, int);                  /* extern */
extern void *gESPRIT_LO_GLOBAL_NDA;

M2C_UNK clearSearchStrings();                       /* extern */
M2C_UNK searchStrings();                            /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
typedef struct RPOS { int x; int y; } RPOS;
void *rnd_findParentBoxnode(void *bn, int type);
void GUI_ScrollPane_getScrollPosition(void *pane, int *x, int *y);
void rnd_gdrawGetViewClientSize(void *pane, int *w, int *h);
int checkParentBox(M2C_UNK *arg0, int arg1) {
    M2C_UNK *var_a0;
    int var_v0;

    var_a0 = arg0;
    var_v0 = 1;
    if (var_a0 != arg1) {
        var_v0 = 0;
        if (var_a0 != NULL) {
loop_2:
            var_a0 = *var_a0;
            var_v0 = 1;
            if (var_a0 != arg1) {
                if (var_a0 == NULL) {
                    var_v0 = 0;
                } else {
                    goto loop_2;
                }
            }
        }
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_deleteAnimBoxnode);

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_addUpdateWidgetList(int arg0, int arg1) {
    M2C_UNK *temp_v0;
    M2C_UNK *temp_v0_2;
    M2C_UNK *var_s0;
    M2C_UNK *var_v0;

    var_s0 = NULL;
    if (head == NULL) {
        temp_v0 = MEM_malloc(0, 0xC);
        head = temp_v0;
        *temp_v0 = NULL;
        M2C_FIELD(head, int *, 4) = 0;
        M2C_FIELD(head, int *, 8) = 0;
        var_s0 = head;
    }
    var_v0 = M2C_FIELD(head, M2C_UNK **, 0);
    if (var_v0 != NULL) {
        do {
            var_s0 = var_v0;
            var_v0 = *var_v0;
        } while (var_v0 != NULL);
    }
    temp_v0_2 = MEM_malloc(0, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK **, 0) = NULL;
    M2C_FIELD(temp_v0_2, int *, 4) = arg0;
    M2C_FIELD(temp_v0_2, int *, 8) = arg1;
    *var_s0 = temp_v0_2;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_clearUpdateWidgetList(void) {
    void *temp_a1;
    void *temp_s1;
    void *var_s0;

    var_s0 = head;
    if (var_s0 != NULL) {
        do {
            temp_a1 = M2C_FIELD(var_s0, void **, 8);
            temp_s1 = M2C_FIELD(var_s0, void **, 0);
            if (temp_a1 != NULL) {
                MEM_free(0, temp_a1);
            }
            MEM_free(0, var_s0);
            var_s0 = temp_s1;
        } while (temp_s1 != NULL);
    }
    head = NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_updateUpdateWidgetList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_updateAnimBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_resetAnimBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_newMarquee);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_updateAnimMarqueeBoxnode);

int rnd_resetAnimMarqueeBoxnode(void *bn, RPOS *pos) {
    RPOS p;
    void *a;
    void *par;
    int sx, sy, w, h;

    p = *pos;
    a = M2C_FIELD(bn, void **, 0x2C);
    if (a == NULL)
        return 0;
    M2C_FIELD(a, int *, 0x1C) = p.x;
    M2C_FIELD(a, int *, 0x20) = p.y;
    M2C_FIELD(a, int *, 4) = M2C_FIELD(a, int *, 8);
    par = rnd_findParentBoxnode(bn, 1);
    if (par == NULL)
        return 0;
    GUI_ScrollPane_getScrollPosition(M2C_FIELD(par, void **, 0x2C), &sx, &sy);
    rnd_gdrawGetViewClientSize(M2C_FIELD(par, void **, 0x2C), &w, &h);
    return sx < M2C_FIELD(bn, int *, 0x10) + M2C_FIELD(bn, int *, 0x18)
        && M2C_FIELD(bn, int *, 0x10) < sx + w
        && sy < M2C_FIELD(bn, int *, 0x14) + M2C_FIELD(bn, int *, 0x1C)
        && M2C_FIELD(bn, int *, 0x14) < sy + h;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void actClearSearchString(void) {
    clearSearchStrings();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void actSearchString(void) {
    searchStrings();
}

void freeScrollStart(void *box, int x, int y) {
    void *body = getBodyBox(box);
    int *g = gESPRIT_LO_GLOBAL_NDA;
    g[1] = M2C_FIELD(body, int *, 0x28);
    g[2] = x;
    g[3] = y;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeScroll(int arg0, int arg1) {
    int temp_a0;
    int temp_s1;
    int temp_s2;
    void *temp_s0;

    temp_s0 = gESPRIT_LO_GLOBAL_NDA;
    temp_s2 = arg0 - M2C_FIELD(temp_s0, int *, 8);
    temp_s1 = arg1 - M2C_FIELD(temp_s0, int *, 0xC);
    temp_a0 = Node_getBox(M2C_FIELD(temp_s0, int *, 4));
    if ((temp_s2 | temp_s1) != 0) {
        drawScroll(temp_a0, -temp_s2, -temp_s1);
        M2C_FIELD(temp_s0, int *, 8) = arg0;
        M2C_FIELD(temp_s0, int *, 0xC) = arg1;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", searchDestinationAnchor);

void *getAncestorLink(void *node) {
    while (node != NULL) {
        node = Util_getNodeByTagName(node, &_DOMa);
        if (node == NULL) {
            return NULL;
        }
        if (Element_hasAttribute(node, &_DOMhref)) {
            return node;
        }
        node = Node_getParentNode(node);
    }
    return NULL;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", D_00139028);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", actLinkJumpInner);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", actLinkJump);
