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
struct _scemoduleinfo;
struct _scemoduleinfo { /* size 0x34 */
    short unsigned int modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    const void *ent_top;
    const void *ent_end;
    const void *stub_top;
    const void *stub_end;
};
struct _anon1;
struct _anon1 { /* size 0xc */
    unsigned int col;
    short int x;
    short int y;
    short unsigned int z;
};
typedef struct _anon1 CRECT;

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern CRECT rect[32][2];
extern int snum;
extern char disp_list[4096];
extern char call_list[32][256];

static void mk_list(void);
static void draw_frame(void);
static int pad_read(void);


INCLUDE_ASM("tmp/asm/UTST99332/graphics_callmode/nonmatchings/main", mk_list);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_callmode/nonmatchings/main", draw_frame);

void init_all(void) {
    sceGuInit();
    sceGuStart(0, disp_list, 0x1000);
    sceGuCallMode(1);
    sceGuDrawBuffer(1, 0, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, 0x44000, 0x200);
    sceGuOffset(0, 0);
    sceGuScissor(0, 0, 0x1E0, 0x110);
    sceGuEnable(2);
    sceGuDisable(1);
    sceGuDisable(9);
    sceGuClearColor(0);
    sceGuClearDepth(0);
    sceGuClearStencil(0);
    sceGuFinish();
    sceGuSync(0, 0);
    sceGuDisplay(1);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_callmode/nonmatchings/main", pad_read);

int main(void) {
    menuInit();
    init_all();
    mk_list();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 3);
    return 0;
}
