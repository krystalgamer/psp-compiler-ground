#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef short unsigned int u_short16;
typedef unsigned int u_int32;
struct _anon2;
struct _anon2 { /* size 0xa */
    u_short16 u;
    u_short16 v;
    short int p[3];
};
typedef struct _anon2 Gu2dVertex16T;
struct _anon1 { /* size 0x40 */
    u_short16 visible;
    short int x;
    short int y;
    short int w;
    short int h;
    short int cw;
    short int ch;
    short int bw;
    short int bh;
    short int scrollx;
    short int scrolly;
    short int __dummy;
    u_int32 color;
    u_short16 *map;
    u_int32 *chr;
    u_int32 *clut;
    u_int32 *work;
    Gu2dVertex16T model[2];
};
typedef struct _anon1 BGDATA;
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

extern unsigned int plt_bgmap0[8];
extern unsigned int chr_bgmap0[608];
extern short unsigned int map_bgmap0[1024];
extern unsigned int plt_bgmap1[8];
extern unsigned int chr_bgmap1[544];
extern short unsigned int map_bgmap1[1024];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[65536];
extern int frame;
extern int select;
extern BGDATA bgdata[4];
extern u_int32 bgwork[4][65536];
extern u_int32 cont;

static void init_map(void);
static void draw_cursor(void);
static void draw_frame(void);
static int pad_read(void);


INCLUDE_ASM("tmp/asm/UTST99332/graphics_map/nonmatchings/main", init_map);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_map/nonmatchings/main", draw_cursor);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_map/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_map/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_map/nonmatchings/main", pad_read);

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
    menuTerm(1, 0xD);
    return 0;
}
