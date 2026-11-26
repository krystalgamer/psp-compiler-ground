/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern int _zWindDrawTexClipOffX;
extern int _zWindDrawTexClipOffY;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_createGraphics);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getGraphics);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_freeGraphics);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_createPixmap);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_freePixmap);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_setColor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_setFont);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_drawString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getStringSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getStringBound);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_drawRect);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_fillRect);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_setClip);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getImageProperty);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getImage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getPixmapSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_drawPixmap);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_drawTiledPixmap);

#ifndef NULL
#define NULL ((void *)0)
#endif
int puts(const char *s);
void GUI_Graphics_flush(signed char *arg0) {
    if ((arg0 == NULL) || (*arg0 != 2)) {
        puts("[X1]GUI_Graphics_flush");
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_createAnimationGIF);

void GUI_Graphics_startAnimationGIF(void) {
}

void GUI_Graphics_getAnimationGIFSize(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_freeAnimationGIF);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getMaskPattern);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getBrokenLinePattern);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", _GUI_Graphics_Push);

#ifndef NULL
#define NULL ((void *)0)
#endif

void _GUI_Graphics_Pop(void) {
    _zWindDrawTexClipOffX = 0;
    _zWindDrawTexClipOffY = 0;
}

void GUI_Graphics_getAnimationGIFGlobalProperty(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getAnimationGIFNextFrame);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Graphics_getAnimationGIFFrameProperty);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createFrame);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createPanel);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createButton);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createCheckbox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createRadioboxGroup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createRadiobox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createLabel);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createChoice);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createTextField);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createTextArea);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createContentView);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_ContentView_setArgument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_createFrameBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Button_setImage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Button_setLabel);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_RadioButton_setState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_RadioButton_getState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_RadioButton_getGroup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Checkbox_setState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Checkbox_getState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", _GUI_List_no);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_add);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_remove);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_removeAll);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_getItem);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_select);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_deselect);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_List_isIndexSelected);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_insert);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_remove);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_removeAll);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_getItem);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_select);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Graphic", GUI_Choice_getSelectedItem);
