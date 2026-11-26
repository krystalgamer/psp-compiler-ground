#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFMatrix4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef struct ScePspFMatrix4 ScePspFMatrix4;
typedef unsigned char u_char8;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspIMatrix4;
struct ScePspIVector4;
struct ScePspIVector4 { /* size 0x10 */
    int x;
    int y;
    int z;
    int w;
};
typedef struct ScePspIVector4 ScePspIVector4;
struct ScePspIMatrix4 { /* size 0x40 */
    ScePspIVector4 x;
    ScePspIVector4 y;
    ScePspIVector4 z;
    ScePspIVector4 w;
};
typedef struct ScePspIMatrix4 ScePspIMatrix4;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
typedef unsigned int u_int32;
struct _anon1;
struct _anon1 { /* size 0x18 */
    ScePspFVector3 pos;
    ScePspFVector3 rot;
};
typedef struct _anon1 POS;
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

extern const float pole[96];
extern const float sphere[96];
extern const float cylinder[392];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];
extern POS world;
extern POS effector[4];
extern int select;
extern int mode;
extern const char char_mode[2][8];
extern u_int32 cont;
extern int analog;

static void init_effector(void);
static void calc_bone(void);
static void draw_cylinder(void);
static void draw_effector(int c);
static void draw_frame(void);
static void init_all(void);
static int pad_read(void);


static void init_effector(void)
{
	int i;

	for (i = 0; i < 4; i++) {
		effector[i].pos.x = effector[i].pos.y = effector[i].pos.z = 0.0f;
		effector[i].rot.x = effector[i].rot.y = effector[i].rot.z = 0.0f;
	}
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", pole);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", sphere);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", cylinder);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", char_mode);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", D_00012750);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", D_00012770);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", calc_bone);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", draw_cylinder);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", draw_effector);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editbone/nonmatchings/main", pad_read);

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
    menuTerm(1, 7);
    return 0;
}
