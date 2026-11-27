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

int sceCtrlReadBufferPositive(SceCtrlData *pData, int nBufs);
void sceGuStart(int type, void *list, int size);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
extern __typeof__(disp_list) disp_list_347C0;

static inline int IsValidMenuItem(int sel)
{
	return (unsigned int)sel < 100 && menuitems[sel].name != NULL && menuitems[sel].callback != NULL;
}

extern u_int32 D_00034780;
#define cont D_00034780

void Menu_Update(void)
{
	int i;

	if (lock_count == 0) {
		u_int32 prev = cont;
		u_int32 padd;
		SceCtrlData buf[1];
		int ret;

		ret = sceCtrlReadBufferPositive(buf, 1);
		if (ret != 0)
			cont = buf[0].Buttons;
		else
			cont = 0;
		padd = cont & (cont ^ prev);

		if (padd & 0x2000) {
			if (IsValidMenuItem(selection))
				(*menuitems[selection].callback)(selection);
		} else if (padd & 0x4000) {
			if (cancel_callback)
				(*cancel_callback)(selection);
		} else if (padd & 0x0010) {
			if (IsValidMenuItem(selection - 1))
				selection--;
		} else if (padd & 0x0040) {
			if (IsValidMenuItem(selection + 1))
				selection++;
		}
	}

	if (show) {
		sceGuStart(0, disp_list_347C0, sizeof(disp_list_347C0));

		for (i = 0; i < 100 && menuitems[i].name; i++) {
			int color = 0x00ffffff;
			if (i == selection)
				color = 0x000000ff;
			sceGuDebugPrint(8, i * 9 + 8, color, menuitems[i].name);
		}

		sceGuDebugPrint(0, 85, 0x00ffffff, "------------------------------------------------");

		for (i = 0; i < 20; i++)
			sceGuDebugPrint(8, i * 9 + 90, output[i].color, output[i].str);

		if (lock_count) {
			int color = 0x00ffffff;
			if (tick % 60 > 30)
				color = 0;
			sceGuDebugPrint(440, 260, color, "BUSY");
		}

		sceGuFinish();
		sceGuSync(0, 0);
	}

	tick++;
}
#undef cont

/* unreferenced empty string literal that followed Menu_Update's strings */
const char D_00014B7C[] = "";

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

void Menu_WriteLine(const char *line, int color)
{
	int i;

	for (i = 0; i < 19; i++)
		output[i] = output[i + 1];

	for (i = 0; line[i]; i++)
		output[19].str[i] = line[i];
	output[19].str[i] = 0;
	output[19].color = color;
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
