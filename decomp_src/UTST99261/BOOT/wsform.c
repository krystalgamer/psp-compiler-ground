/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/wszlib.h"
#include "m2c_macros.h"
M2C_UNK rnd_gdrawGetTextlineExtents();              /* extern */
M2C_UNK rnd_gdrawGetTextboxExtents();               /* extern */
M2C_UNK rnd_gdrawGetCheckboxExtents();              /* extern */
M2C_UNK rnd_gdrawGetRadiobuttonExtents();           /* extern */
M2C_UNK rnd_gdrawGetButtonExtents();                /* extern */
M2C_UNK rnd_gdrawGetPulldownExtents();              /* extern */
M2C_UNK rnd_gdrawGetListExtents();                  /* extern */
M2C_UNK GUI_Graphics_getStringSize();               /* extern */
M2C_UNK rnd_gdrawGetStringsVisibleLength();         /* extern */
M2C_UNK colorValue();                               /* extern */

int setTextStrings(FORMELEM *e, char *s) {
    if (e->widget == NULL) {
        return -100;
    }
    if (e->info->kind == 1) {
        GUI_TextArea_setText(e->widget, s);
    } else {
        GUI_TextField_setText(e->widget, s);
    }
    return 0;
}

char *getTextStrings(FORMELEM *e) {
    if (e->widget == NULL) {
        return (char *)-100;
    }
    if (e->info->kind == 1) {
        return rnd_gdrawGetTextboxString(e->widget);
    }
    return rnd_gdrawGetTextlineString(e->widget);
}

int replaceTextStrings(FORMELEM *e, char *s, int start, int end) {
    int t;

    if (e->widget == NULL) {
        return -100;
    }
    if (end < start) {
        t = start;
        start = end;
        end = t;
    }
    if (e->info->kind == 1) {
        return rnd_gdrawReplaceTextboxString(e->widget, s, start, end);
    }
    return GUI_TextField_insert(e->widget, s, start, end);
}

int getTextSelectionRange(FORMELEM *e, int *start, int *end) {
    if (e->widget == NULL) {
        return -100;
    }
    if (e->info->kind == 1) {
        return GUI_TextArea_getSelection(e->widget, start, end);
    }
    return GUI_TextField_getSelection(e->widget, start, end);
}

char *getTextSelectionString(FORMELEM *e) {
    if (e->widget == NULL) {
        return (char *)-100;
    }
    if (e->info->kind == 1) {
        return rnd_gdrawGetTextboxSelectionString(e->widget);
    }
    return rnd_gdrawGetTextlineSelectionString(e->widget);
}

int selectText(FORMELEM *e) {
    if (e->widget == NULL) {
        return -100;
    }
    if (e->info->kind == 1) {
        rnd_gdrawSelectTextbox(e->widget, 1);
    } else {
        GUI_TextField_selectAll(e->widget);
    }
    return 0;
}

void getTextlineExtents(void) {
    rnd_gdrawGetTextlineExtents();
}

void getTextboxExtents(void) {
    rnd_gdrawGetTextboxExtents();
}

void getCheckboxExtents(void) {
    rnd_gdrawGetCheckboxExtents();
}

int setCheckboxState(FORMELEM *e, int state) {
    if (e->widget == NULL) {
        return -100;
    }
    GUI_Checkbox_setState(e->widget, state);
    return 0;
}

int getCheckboxState(FORMELEM *e) {
    if (e->widget == NULL) {
        return -100;
    }
    return GUI_Checkbox_getState(e->widget);
}

void getRadiobuttonExtents(void) {
    rnd_gdrawGetRadiobuttonExtents();
}

int setRadiobuttonState(FORMELEM *e, int state) {
    if (e->widget == NULL) {
        return -100;
    }
    GUI_RadioButton_setState(e->widget, state);
    return 0;
}

int getRadiobuttonState(FORMELEM *e) {
    if (e->widget == NULL) {
        return -100;
    }
    return GUI_RadioButton_getState(e->widget);
}

void getButtonExtents(void) {
    rnd_gdrawGetButtonExtents();
}

void getPulldownExtents(void) {
    rnd_gdrawGetPulldownExtents();
}

int setPulldownState(FORMELEM *e, int index) {
    if (e->widget == NULL) {
        return -100;
    }
    GUI_Choice_select(e->widget, index);
    return 0;
}

int getPulldownState(FORMELEM *e) {
    if (e->widget == NULL) {
        return -100;
    }
    return GUI_Choice_getSelectedItem(e->widget);
}

void getListExtents(void) {
    rnd_gdrawGetListExtents();
}

int setListSelect(FORMELEM *e, int index, int state) {
    if (e->widget == NULL) {
        return -100;
    }
    rnd_gdrawSetListState(e->widget, index, state, 0);
    return 0;
}

int getListSelect(FORMELEM *e, int index) {
    if (e->widget == NULL) {
        return -100;
    }
    return GUI_List_isIndexSelected(e->widget, index);
}

void getStringsExtents(void) {
    GUI_Graphics_getStringSize();
}

void getStringsVisibleLength(void) {
    rnd_gdrawGetStringsVisibleLength();
}
