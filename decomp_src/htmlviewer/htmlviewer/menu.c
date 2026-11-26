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

extern char disp_list[65536] __asm__("disp_list_17D880");
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

#define SCE_CTRL_UP 0x0010
#define SCE_CTRL_DOWN 0x0040
#define SCE_CTRL_CIRCLE 0x2000
#define SCE_CTRL_CROSS 0x4000
#define SCEGU_IMMEDIATE 0
#define SCEGU_SYNC_FINISH 0
#define SCEGU_SYNC_WAIT 0
#define va_start(v, l) __builtin_stdarg_start((v), l)
#define va_end(v) __builtin_va_end(v)

static inline int IsValidMenuItem(int sel)
{
    return (sel >= 0 && sel < 100 && menuitems[sel].name && menuitems[sel].callback);
}

extern u_int32 D_0017D74C;
extern u_int32 D_0017D750;
extern u_int32 D_000F4B8C;
extern char D_0017D754[256];
#define cont D_0017D74C
#define frame D_0017D750
#define inframe D_000F4B8C

void DrawSetting(void);
int strcmp(const char *, const char *);
int snprintf(char *, unsigned int, const char *, ...);
int vsprintf(char *, const char *, va_list);
int sceCtrlReadBufferPositive(SceCtrlData *, int);
int sceGuStart(int, void *, int);
int sceGuFinish(void);
int sceGuSync(int, int);
void sceGuDebugPrint(int, int, unsigned int, const char *);
void sceGuDebugFlush(void);

/* SDK functions (tools/sdk_protos.h) */
int sceCtrlSetSamplingCycle(int cycle);
int sceCtrlSetSamplingMode(int mode);



void Menu_Init(void)
{
    Menu_ClearItems();
    Menu_ClearSavedSelection();
    show = 1;
    selection = 0;
    listtop = 0;
    curmenu = 0;
    lock_count = 0;
    tick = 0;
    sceCtrlSetSamplingMode(1);
    sceCtrlSetSamplingCycle(0);
}

void Menu_Shutdown(void)
{
}

void Menu_MenuSelect(void)
{
    if (IsValidMenuItem(selection)) {
        Menu_SaveSelection(savedselection[curmenu].name, selection);
        (*menuitems[selection].callback)(selection);
    }
}

void Menu_MenuUp(void)
{
    if (IsValidMenuItem(selection - 1)) {
        selection--;
        if (selection < listtop) listtop = selection;
        Menu_SaveSelection(savedselection[curmenu].name, selection);
    }
}

void Menu_MenuDown(void)
{
    if (IsValidMenuItem(selection + 1)) {
        selection++;
        if (selection > listtop + 4) listtop = selection - 4;
        Menu_SaveSelection(savedselection[curmenu].name, selection);
    }
}

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

#define LINE "------------------------------------------------------------"

void Menu_Update(void)
{
    int i;
    int j;

    if (lock_count == 0) {
        u_int32 prev = cont;
        u_int32 padd;
        SceCtrlData buf[1];
        int ret = sceCtrlReadBufferPositive(buf, 1);
        if (ret != 0) {
            cont = buf[0].Buttons;
        } else {
            cont = 0;
        }
        if (prev == cont && cont == SCE_CTRL_UP) {
            if (frame++ > 40) {
                if (inframe++ > 5) {
                    prev = 0;
                    inframe = 0;
                }
            }
        } else if (prev == cont && cont == SCE_CTRL_DOWN) {
            if (frame++ > 40) {
                if (inframe++ > 5) {
                    prev = 0;
                    inframe = 0;
                }
            }
        } else {
            frame = 0;
            inframe = 0;
        }
        if (buf[0].Ly - 128 < -80) Menu_ScrollUp();
        if (buf[0].Ly - 128 > 80) Menu_ScrollDown();
        padd = cont & (cont ^ prev);

        if (padd & SCE_CTRL_CIRCLE) {
            if (IsValidMenuItem(selection)) {
                (*menuitems[selection].callback)(selection);
            }
        } else if (padd & SCE_CTRL_CROSS) {
            if (cancel_callback) {
                (*cancel_callback)(selection);
            }
        } else if (padd & SCE_CTRL_UP) {
            if (IsValidMenuItem(selection - 1)) {
                Menu_MenuUp();
            }
        } else if (padd & SCE_CTRL_DOWN) {
            if (IsValidMenuItem(selection + 1)) {
                Menu_MenuDown();
            }
        }
    }

    if (show) {
        j = linebuf_dptr_s;
        sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
        sceGuDebugPrint(0, 0, 0x00ffffff, LINE);
        sceGuDebugPrint(0, 9, 0x00ffffff, "Utility Check Tool (V2.00)");
        sceGuDebugPrint(0, 18, 0x00ffffff, LINE);
        sceGuDebugFlush();
        for (i = listtop; i - listtop < 5 && menuitems[i].name; i++) {
            char buf[128];
            unsigned int color = 0x00ffffff;
            if (i == selection) color = 0x000000ff;
            snprintf(buf, sizeof(buf), "(%.2d)%s", i + 1, menuitems[i].name);
            sceGuDebugPrint(8, (i - listtop) * 9 + 26, color, buf);
            sceGuDebugFlush();
        }
        if (listtop > 0) sceGuDebugPrint(0, 26, 0x0000ffff, "^");
        if (IsValidMenuItem(listtop + 5)) sceGuDebugPrint(0, 62, 0x0000ffff, "v");
        sceGuDebugFlush();
        sceGuDebugPrint(0, 71, 0x00ffffff, LINE);
        for (i = 0; i < 19; i++, j++) {
            sceGuDebugPrint(8, i * 9 + 80, linebuf[j].color, linebuf[j].str);
            sceGuDebugFlush();
        }
        sceGuDebugPrint(0, 251, 0x00ffffff, LINE);
        if (lock_count) {
            int color = 0x00ffffff;
            if (tick % 60 > 30) color = 0x00000000;
            sceGuDebugPrint(440, 269, color, "BUSY");
        }
        sceGuDebugFlush();
        DrawSetting();
        sceGuFinish();
        sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
    }

    tick++;
}

void Menu_ClearItems(void)
{
    int i;

    for (i = 0; i < 100; i++) {
        menuitems[i].name = 0;
        menuitems[i].callback = 0;
    }
    cancel_callback = 0;
    selection = 0;
    listtop = 0;
}

void Menu_AppendItem(const char *name, Menu_Callback callback)
{
    int i;

    for (i = 0; i < 100; i++) {
        if (menuitems[i].name == 0) {
            menuitems[i].name = name;
            menuitems[i].callback = callback;
            return;
        }
    }
}

void Menu_SetCancelCallback(void (*callback)(int)) {
    cancel_callback = callback;
}

void Menu_ClearSavedSelection(void)
{
    int i;

    for (i = 0; i < 30; i++) {
        savedselection[i].name = 0;
        savedselection[i].selection = 0;
    }
}

void Menu_SetCurMenu(const char *name)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (savedselection[i].name && strcmp(savedselection[i].name, name) == 0) {
            curmenu = i;
            break;
        }
    }
    if (i == 30) {
        for (i = 0; i < 30; i++) {
            if (savedselection[i].name == 0) {
                savedselection[i].name = name;
                savedselection[i].selection = selection;
                curmenu = i;
                break;
            }
        }
    }
}

void Menu_SaveSelection(const char *name, int selection)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (savedselection[i].name && strcmp(savedselection[i].name, name) == 0) {
            savedselection[i].selection = selection;
            break;
        }
    }
    if (i == 30) {
        for (i = 0; i < 30; i++) {
            if (savedselection[i].name == 0) {
                savedselection[i].name = name;
                savedselection[i].selection = selection;
                break;
            }
        }
    }
}

int Menu_GetSelection(const char *name)
{
    int i;
    int ret = 0;

    for (i = 0; i < 30; i++) {
        if (savedselection[i].name && strcmp(savedselection[i].name, name) == 0) {
            ret = savedselection[i].selection;
            break;
        }
    }
    return ret;
}

void Menu_WriteLine(const char *line, int color)
{
    int i;

    if (linebuf_wptr == 500) {
        for (i = 0; i < 499; i++) {
            linebuf[i] = linebuf[i + 1];
        }
        linebuf_wptr = 499;
    }
    for (i = 0; line[i]; i++) {
        linebuf[linebuf_wptr].str[i] = line[i];
    }
    linebuf[linebuf_wptr].str[i] = 0;
    linebuf[linebuf_wptr].color = color;
    if (linebuf_wptr - linebuf_dptr == 19) linebuf_dptr++;
    linebuf_wptr++;
    linebuf_dptr_s = linebuf_dptr;
}

void Menu_PrintF(int color, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    vsprintf(D_0017D754, fmt, args);
    va_end(args);
    Menu_WriteLine(D_0017D754, color);
}

void Menu_ScrollLines(int direction, int count)
{
    linebuf_dptr_s += direction * count;
    if (direction == 1) {
        if (linebuf_wptr - linebuf_dptr_s < 19) linebuf_dptr_s = linebuf_wptr - 19;
    }
    if (linebuf_dptr_s < 0) linebuf_dptr_s = 0;
}

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
