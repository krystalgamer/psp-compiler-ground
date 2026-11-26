/* cflags: -O1 */
#include "common.h"
#include "nflayout.h"
#include "m2c_macros.h"
typedef struct LINEENT { struct LINEENT *next; int x4; BOX *box; } LINEENT;
typedef struct LINE { LINEENT *first; LINEENT *last; } LINE;
void moveBoxPositionChild(BOX *box, int dx, int dy);


#ifndef NULL
#define NULL ((void *)0)
#endif
int getPrevLineHeight(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 4), int *, 0x34);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", D_00139244);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", lineProcByBR);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", getPositionParameter);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", delSpaceText);

#ifndef NULL
#define NULL ((void *)0)
#endif
void adjustInlineBoxDimension(void *arg0) {
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int var_a2;
    int var_a3;
    int var_a4;
    int var_a5;
    void *temp_a6;
    void *var_a0;
    void *var_a1;

    var_a0 = arg0;
    temp_a6 = var_a0;
    if (var_a0 != NULL) {
        do {
            if ((M2C_FIELD(var_a0, short *, 0x3C) == 1) && (M2C_FIELD(var_a0, short *, 0x38) == 0)) {
                var_a5 = -1;
                var_a2 = -1;
                var_a4 = -1;
                var_a1 = M2C_FIELD(temp_a6, void **, 4);
                var_a3 = -1;
                if (var_a1 != NULL) {
                    do {
                        if (var_a2 == -1) {
                            var_a2 = M2C_FIELD(var_a1, int *, 0x10);
                            var_a5 = var_a2 + M2C_FIELD(var_a1, int *, 0x18);
                            var_a3 = M2C_FIELD(var_a1, int *, 0x14);
                            var_a4 = var_a3 + M2C_FIELD(var_a1, int *, 0x1C);
                        }
                        temp_v0 = M2C_FIELD(var_a1, int *, 0x10);
                        var_a2 = __builtin_allegrex_min(var_a2, temp_v0);
                        var_a5 = __builtin_allegrex_max(var_a5, temp_v0 + M2C_FIELD(var_a1, int *, 0x18));
                        temp_v0_2 = M2C_FIELD(var_a1, int *, 0x14);
                        var_a3 = __builtin_allegrex_min(var_a3, temp_v0_2);
                        temp_v0_3 = temp_v0_2 + M2C_FIELD(var_a1, int *, 0x1C);
                        var_a1 = M2C_FIELD(var_a1, void **, 0xC);
                        var_a4 = __builtin_allegrex_max(var_a4, temp_v0_3);
                    } while (var_a1 != NULL);
                }
                if (var_a3 != -1) {
                    M2C_FIELD(temp_a6, int *, 0x10) = var_a2;
                    M2C_FIELD(temp_a6, int *, 0x14) = var_a3;
                    M2C_FIELD(temp_a6, int *, 0x18) = (int) (var_a5 - var_a2);
                    M2C_FIELD(temp_a6, int *, 0x1C) = (int) (var_a4 - var_a3);
                }
            }
            var_a0 = M2C_FIELD(var_a0, void **, 0);
        } while (var_a0 != NULL);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void adjustInlineBoxDimensionLoop(int *arg0, int arg1) {
    int var_s0;

    var_s0 = *arg0;
    if ((var_s0 != 0) & (var_s0 != arg1)) {
        do {
            if ((M2C_FIELD(var_s0, short *, 0x3C) == 1) && (M2C_FIELD(var_s0, short *, 0x38) == 0)) {
                adjustInlineBoxDimension((void *) var_s0);
            }
            var_s0 = M2C_FIELD(var_s0, int *, 0);
        } while ((var_s0 != 0) & (var_s0 != arg1));
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", wordWrapProc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", calcBlockButtonBoxPosition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", calcTableBoxPosition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", calcTrBoxPosition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", calcTdBoxPosition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", calcInlineBoxPosition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", calcBlockBoxPosition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", calcFloatBoxPosition);

BOX *getCurrentLineBox(BOX *box) {
    s16 c;
    while (box != NULL) {
        c = box->content;
        if (c == 17 || c == 1) {
            return box;
        }
        box = box->parent;
    }
    return NULL;
}

void *getCurrentLineCB(BOX *box) {
    while (box != NULL) {
        if (box->content == 17) {
            return (char *)box->geom + 4;
        }
        if (box->content == 1) {
            return (char *)box->geom + 0x90;
        }
        box = box->parent;
    }
    return NULL;
}

void initLinePosition(BOX *box) {
    while (box != NULL) {
        if (box->content == 17) {
            M2C_FIELD(box->geom, int *, 0x10) = 0;
            return;
        }
        if (box->content == 1) {
            M2C_FIELD(box->geom, int *, 0x8C) = 0;
            return;
        }
        box = box->parent;
    }
}

void setLinePosition(BOX *box, int pos) {
    while (box != NULL) {
        if (box->content == 17) {
            M2C_FIELD(box->geom, int *, 0x10) = pos;
            return;
        }
        if (box->content == 1) {
            M2C_FIELD(box->geom, int *, 0x8C) = pos;
            return;
        }
        box = box->parent;
    }
}

int getLinePosition(BOX *box) {
    while (box != NULL) {
        if (box->content == 17) {
            return M2C_FIELD(box->geom, int *, 0x10);
        }
        if (box->content == 1) {
            return M2C_FIELD(box->geom, int *, 0x8C);
        }
        box = box->parent;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", getLineWidth);

int getLineHeight(LINE *line) {
    LINEENT *e;
    int h;
    if (line->first == NULL) {
        h = 0;
    } else {
        h = 0;
        for (e = line->first; e != NULL && e->box != NULL; e = e->next) {
            h = h > e->box->height ? h : e->box->height;
        }
    }
    return h;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", lineFeedProc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", turnupContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", moveBoxPositionChild);

void moveBoxPosition(BOX *box, int dx, int dy) {
    box->x += dx;
    box->y += dy;
    moveBoxPositionChild(box, dx, dy);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void getBaseBlockPosition(void *arg0, int *arg1, int *arg2) {
    int temp_a1;
    int temp_a3;
    int temp_v1;
    int temp_v1_2;

    *arg1 = 0;
    *arg2 = 0;
    *arg1 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), int *, 0x10);
    *arg2 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), int *, 0x14);
    temp_a3 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24), short *, 0x26) + *arg1;
    *arg1 = temp_a3;
    temp_v1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24), short *, 0x2E) + temp_a3;
    *arg1 = temp_v1;
    *arg1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24), short *, 0x36) + temp_v1;
    temp_a1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24), short *, 0x20) + *arg2;
    *arg2 = temp_a1;
    temp_v1_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24), short *, 0x28) + temp_a1;
    *arg2 = temp_v1_2;
    *arg2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24), short *, 0x30) + temp_v1_2;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", adjustLineVposition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", adjustLineHposition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", calcBoxPosition);
