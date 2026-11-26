/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK drawEachFrame(int);                         /* extern */
M2C_UNK drawObject(int);                            /* extern */
int rnd_relayoutWidgets(int, int);                  /* extern */
extern void *ui_global;
M2C_UNK GUI_Component_update(int, int, int, int, int); /* extern */
M2C_UNK GUI_Component_remove(int);                  /* extern */
M2C_UNK rnd_deleteAnimBoxnode();                    /* extern */
M2C_UNK GUI_ScrollPane_getScrollPosition(int);      /* extern */
M2C_UNK GUI_ScrollPane_getContentSize(int);         /* extern */
M2C_UNK GUI_Component_getParent();                  /* extern */
extern int sellist;

M2C_UNK rnd_gdrawImageDecode();                     /* extern */
M2C_UNK rnd_gdrawImageDecodeByGifFile();            /* extern */
M2C_UNK rnd_gdrawImageProperty();                   /* extern */
M2C_UNK rnd_gdrawImageDelete();                     /* extern */
M2C_UNK rnd_updateAnimBoxnode();                    /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", drawEachFrame);

#ifndef NULL
#define NULL ((void *)0)
#endif

int drawPaint(int arg0) {
    int temp_v0;

    if (arg0 != 0) {
        GUI_Toolkit_mutexLock();
        temp_v0 = rnd_relayoutWidgets(M2C_FIELD(ui_global, int *, 0x90), arg0);
        if (temp_v0 < 0) {
            GUI_Toolkit_mutexUnlock();
            return temp_v0;
        }
        GUI_Toolkit_mutexUnlock();
        drawEachFrame(arg0);
        drawObject(arg0);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", drawObject);

#ifndef NULL
#define NULL ((void *)0)
#endif

int drawObjectWithArea(int *arg0, int arg1, int arg2, int arg3, int arg4) {
    int *temp_v0;
    int var_v0;
    void *temp_v1;

    temp_v0 = rnd_findParentBoxnode(arg0, 1);
    var_v0 = -0x64;
    if (temp_v0 != NULL) {
        temp_v1 = M2C_FIELD(arg0, void **, 0x24);
        GUI_Component_update(M2C_FIELD(temp_v0, int *, 0x2C), M2C_FIELD(temp_v1, short *, 0x26) + M2C_FIELD(arg0, int *, 0x10) + M2C_FIELD(temp_v1, short *, 0x36) + M2C_FIELD(temp_v1, short *, 0x2E) + arg1, M2C_FIELD(temp_v1, short *, 0x20) + M2C_FIELD(arg0, int *, 0x14) + M2C_FIELD(temp_v1, short *, 0x30) + M2C_FIELD(temp_v1, short *, 0x28) + arg2, arg3, arg4);
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", drawScroll);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", drawRemoveChild);

#ifndef NULL
#define NULL ((void *)0)
#endif

void drawDelete(int *arg0) {
    int *temp_v0;
    int temp_a0;

    rnd_deleteAnimBoxnode();
    temp_v0 = rnd_findParentBoxnode(arg0, 1);
    if (temp_v0 != NULL) {
        temp_a0 = M2C_FIELD(temp_v0, int *, 0x2C);
        if (temp_a0 != 0) {
            GUI_Component_remove(temp_a0);
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int getViewPort(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0x38) != 1)) {
        return -0x64;
    }
    GUI_ScrollPane_getScrollPosition(M2C_FIELD(arg0, int *, 0x2C));
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", getViewClientSize);

#ifndef NULL
#define NULL ((void *)0)
#endif

int getViewVirtualSize(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0x38) != 1)) {
        return -0x64;
    }
    GUI_ScrollPane_getContentSize(M2C_FIELD(arg0, int *, 0x2C));
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", setFocus);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", setFocusImageMap);

#ifndef NULL
#define NULL ((void *)0)
#endif

void imageDecode(void) {
    rnd_gdrawImageDecode();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void imageDecodeByGifFile(void) {
    rnd_gdrawImageDecodeByGifFile();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void imageProperty(void) {
    rnd_gdrawImageProperty();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void imageDelete(void) {
    rnd_gdrawImageDelete();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void drawAnimation(void) {
    rnd_updateAnimBoxnode();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", startBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", moveBorder);

#ifndef NULL
#define NULL ((void *)0)
#endif

int deleteBorder(int arg0) {
    int var_v0;

    var_v0 = -0x64;
    if (arg0 != 0) {
        GUI_Component_getParent();
        GUI_Component_remove(arg0);
        var_v0 = 0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void addSelectList(int *arg0) {
    int temp_v0;
    int var_s1;
    void *temp_v0_2;

    if (sellist == 0) {
        temp_v0 = MEM_malloc(0, 0xC);
        sellist = temp_v0;
        M2C_FIELD(temp_v0, int *, 0) = 0;
        M2C_FIELD(temp_v0, int *, 4) = 0;
        M2C_FIELD(temp_v0, int *, 8) = 0;
    }
    var_s1 = sellist;
    if (M2C_FIELD(var_s1, int *, 8) != 0) {
        do {
            var_s1 = M2C_FIELD(var_s1, int *, 8);
        } while (M2C_FIELD(var_s1, int *, 8) != 0);
    }
    temp_v0_2 = MEM_malloc(0, 0xC);
    M2C_FIELD(temp_v0_2, int **, 4) = arg0;
    M2C_FIELD(temp_v0_2, int *, 0) = (int) M2C_FIELD(M2C_FIELD(getBodyBox(arg0), void **, 0x20), int *, 0x38);
    M2C_FIELD(temp_v0_2, int *, 8) = 0;
    M2C_FIELD(var_s1, void **, 8) = temp_v0_2;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", destroySelectList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", delSelectListBySID);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", getSelectListFromGadget);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", rnd_drawAllBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", rnd_drawBoxnode);

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *rnd_findParentBoxnode(M2C_UNK *arg0, int arg1) {
    M2C_UNK *var_a0;

    var_a0 = arg0;
    if ((var_a0 != NULL) && (M2C_FIELD(var_a0, short *, 0x38) != arg1)) {
loop_2:
        var_a0 = *var_a0;
        if (var_a0 != NULL) {
            if (M2C_FIELD(var_a0, short *, 0x38) != arg1) {
                goto loop_2;
            }
        }
    }
    return var_a0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", rnd_prevRadioBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", rnd_drawBasicBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", rnd_drawBoxnodeBackground);
