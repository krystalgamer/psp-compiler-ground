#include "common.h"

/* declarations recovered from DWARF */
typedef int SceUID;
typedef unsigned int SceSize;
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

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[65536];
extern char buffer[1048576];
extern int draw;
extern short int board[2][3];

static int file_read(void);
static int file_seek(void);
static int file_write(void);
static int pad_read(void);


INCLUDE_ASM("tmp/asm/UTST99332/graphics_fileio/nonmatchings/main", file_read);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_fileio/nonmatchings/main", file_seek);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_fileio/nonmatchings/main", D_0000EA90);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_fileio/nonmatchings/main", file_write);

void draw_frame(void) {
    sceGuStart(0, disp_list, 0x10000);
    sceGuClear(7);
    if (draw != 0) {
        sceGuEnable(9);
        sceGuTexMode(3, 0, 0, 0);
        sceGuTexImage(0, 0x200, 0x200, 0x200, buffer);
        sceGuColor(-1);
        sceGuSpriteMode(0x200, 0x200, 0x200, 0x200);
        sceGuDrawSprite(0, 0, 0, 0, 0, 0, 0);
    } else {
        sceGuDisable(9);
    }
    sceGuColor(0x90000000);
    sceGuDrawArray(6, 0x800100, 2, 0, board);
    sceGuDebugPrint(8, 8, 0xFFFFFF, "PAD_A : READ");
    sceGuDebugPrint(8, 0x10, 0xFFFFFF, "PAD_B : SEEK>READ");
    sceGuDebugPrint(8, 0x18, 0xFFFFFF, "PAD_C : WRITE");
    sceGuDebugPrint(8, 0x28, 0xFFFFFF, "START : DISP OFF");
    sceGuDebugPrint(8, 0x30, 0xFFFFFF, "SELECT: EXIT");
    sceGuFinish();
    sceGuSync(0, 0);
}

void init_all(void) {
    sceGuInit();
    sceGuStart(0, disp_list, 0x10000);
    sceGuDrawBuffer(3, 0, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, 0x88000, 0x200);
    sceGuDepthBuffer(0x110000, 0x200);
    sceGuOffset(0, 0);
    sceGuScissor(0, 0, 0x1E0, 0x110);
    sceGuEnable(2);
    sceGuBlendFunc(0, 2, 3, 0, 0);
    sceGuEnable(4);
    sceGuTexFunc(0, 1);
    sceGuTexFilter(7, 0);
    sceGuTexWrap(0, 0);
    sceGuClearColor(0);
    sceGuClearDepth(0);
    sceGuClearStencil(0);
    sceGuFinish();
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    draw = 0;
    sceGuDisplay(1);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_fileio/nonmatchings/main", pad_read);

int main(void) {
    menuInit();
    init_all();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0xA);
    return 0;
}
