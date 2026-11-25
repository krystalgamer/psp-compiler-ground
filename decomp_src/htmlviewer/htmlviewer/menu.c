#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int32;
typedef struct SceCtrlData SceCtrlData;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef void (*Menu_Callback)(int);
typedef void *__gnuc_va_list;
typedef __gnuc_va_list va_list;
struct _anon1;
struct _anon1 { /* size 0x8 */
    const char *name;
    Menu_Callback callback;
};
typedef struct _anon1 MenuItem;
struct SavedSelection;
struct SavedSelection { /* size 0x8 */
    const char *name;
    int selection;
};
struct LineBuf;
struct LineBuf { /* size 0x104 */
    char str[256];
    int color;
};

extern char disp_list[65536];
extern MenuItem menuitems[100];
extern Menu_Callback cancel_callback;
extern int selection;
extern int listtop;
extern struct SavedSelection savedselection[30];
extern int curmenu;
extern struct LineBuf linebuf[500];
extern int linebuf_dptr;
extern int linebuf_dptr_s;
extern int linebuf_wptr;
extern int lock_count;
extern int show;
extern int tick;

void Menu_Shutdown(void);
void Menu_MenuSelect(void);
static int IsValidMenuItem(int sel);
void Menu_MenuUp(void);
void Menu_MenuDown(void);
void Menu_Update(void);
void Menu_ClearItems(void);
void Menu_AppendItem(const char *name, Menu_Callback callback);
void Menu_ClearSavedSelection(void);
void Menu_SetCurMenu(const char *name);
void Menu_SaveSelection(const char *name, int selection);
int Menu_GetSelection(const char *name);
void Menu_WriteLine(const char *line, int color);
void Menu_PrintF(int color, const char *fmt, ...);
void Menu_ScrollLines(int direction, int count);

/* SDK functions (tools/sdk_protos.h) */
int sceCtrlSetSamplingCycle(int cycle);
int sceCtrlSetSamplingMode(int mode);


INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_Init);

void Menu_Shutdown(void) {
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_MenuSelect);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_MenuUp);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_MenuDown);

void Menu_SetSelection(int newselection) {
    MenuItem *temp_v1;

    temp_v1 = &menuitems[newselection];
    if (((unsigned int) newselection < 0x64U) && (temp_v1->name != NULL) && (temp_v1->callback != NULL)) {
        selection = newselection;
        if (newselection < listtop) {
            listtop = newselection;
            return;
        }
        if ((listtop + 4) < newselection) {
            listtop = newselection - 4;
        }
    }
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_Update);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_ClearItems);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_AppendItem);

void Menu_SetCancelCallback(void (*callback)(int)) {
    cancel_callback = callback;
}

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_ClearSavedSelection);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_SetCurMenu);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_SaveSelection);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_GetSelection);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_WriteLine);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_PrintF);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/menu", Menu_ScrollLines);

void Menu_ScrollUp(void) {
    Menu_ScrollLines(-1, 1);
}

void Menu_ScrollDown(void) {
    Menu_ScrollLines(1, 1);
}

void Menu_LockInput(void) {
    lock_count += 1;
}

void Menu_UnlockInput(void) {
    lock_count -= 1;
}

void Menu_Show(void) {
    show = 1;
}

void Menu_Hide(void) {
    show = 0;
}
