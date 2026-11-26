#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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
extern ScePspFVector3 pos;
extern ScePspFVector3 rot;
extern int mode;
extern int prim;
extern int current;
extern int knot[4];
extern int param;
extern int unum;
extern int vnum;
extern ScePspFVector3 control[256];
extern const int primflag[3];
extern const float spline[48];
extern const float dot[6];
extern u_int32 cont;
extern int analog;

static void resize_model(int pu, int pv, int nu, int nv);
static int get_knotflag(int s, int e);
static void draw_spline(void);
static void draw_dot(void);
static void num2str(int num, char *str);
static void draw_param(void);
static void draw_frame(void);
static void init_param(void);
static void init_all(void);
static int pad_read(void);


INCLUDE_ASM("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", resize_model);

static int get_knotflag(int s, int e)
{
	int ret;

	ret = 0;
	if (s) {
		ret = 1;
	}
	if (e) {
		ret += 2;
	}

	return ret;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", draw_spline);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", draw_dot);

static void num2str(int num, char *str)
{
	const int columns = 2;
	int i;
	int a;

	a = num;
	for (i = columns - 1; i >= 0; i--) {
		str[i] = a % 10 + '0';
		a /= 10;
	}
	str[columns] = 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", primflag);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", spline);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", dot);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", draw_param);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", draw_frame);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", D_000127E8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", D_00012804);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", D_00012820);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", D_00012824);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", init_param);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editspline/nonmatchings/main", pad_read);

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
    menuTerm(1, 9);
    return 0;
}
