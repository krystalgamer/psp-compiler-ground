#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int32;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
typedef void (*Menu_Callback)(int);
struct _anon1;
struct _anon1 { /* size 0x8 */
    const char *name;
    Menu_Callback callback;
};
typedef struct _anon1 MenuItem;
struct _anon2;
struct _anon2 { /* size 0x104 */
    char str[256];
    int color;
};
typedef struct _anon2 OutputLine;

extern char disp_list[65536];
extern MenuItem menuitems[100];
extern Menu_Callback cancel_callback;
extern int selection;
extern OutputLine output[20];
extern int lock_count;
extern int show;
extern int tick;

void Menu_Shutdown();
void Menu_Update();
static int IsValidMenuItem(int sel);
void Menu_ClearItems();
void Menu_AppendItem(const char *name, Menu_Callback callback);
void Menu_WriteLine(const char *line, int color);


void Menu_Init(void) {
    Menu_ClearItems();
    show = 1;
    lock_count = 0;
    tick = 0;
}

void Menu_Shutdown(void) {
}

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/menu/Menu_Init", Menu_Update);

void Menu_ClearItems(void)
{
	int i;

	for (i = 0; i < 100; i++) {
		menuitems[i].name = NULL;
		menuitems[i].callback = NULL;
	}

	cancel_callback = NULL;

	selection = 0;
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

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/menu/Menu_Init", Menu_WriteLine);

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
