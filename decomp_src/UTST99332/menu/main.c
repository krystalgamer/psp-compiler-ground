#include "common.h"

/* declarations recovered from DWARF */
struct SceKernelLoadExecParam;
typedef unsigned int SceSize;
struct SceKernelLoadExecParam { /* size 0x10 */
    SceSize size;
    SceSize args;
    const void *argp;
    const char *key;
};
typedef struct SceKernelLoadExecParam SceKernelLoadExecParam;
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
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1;
typedef short unsigned int u_short16;
struct _anon1 { /* size 0x10 */
    u_short16 u;
    u_short16 v;
    float p[3];
};
typedef struct _anon1 Gu2dV32T;
struct _anon2;
struct _anon2 { /* size 0x6 */
    short int p[3];
};
typedef struct _anon2 Gu2dV16;
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
struct _anon3;
struct _anon3 { /* size 0x24 */
    ScePspFVector3 pos;
    ScePspFVector3 rot;
    int cat;
    int num;
    int ret;
};
typedef struct _anon3 MENUDATA;
typedef struct _anon3 *PMENUDATA;
struct _anon4;
struct _anon4 { /* size 0xc */
    int flag;
    int mode;
    int next;
};
typedef struct _anon4 PROG;
struct _anon5;
typedef void voidfunc(void);
typedef void voidfuncuint2(u_int32, u_int32, float *);
struct _anon5 { /* size 0x10 */
    voidfunc *init;
    voidfunc *run;
    voidfunc *draw;
    voidfuncuint2 *key;
};
typedef struct _anon5 FUNCLIST;
struct _anon6;
struct _anon6 { /* size 0x8 */
    unsigned char *p;
    int size;
};
typedef struct _anon6 SE;
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

extern MENUDATA menudata;
extern PMENUDATA menu;
extern int exitflag;
extern u_int32 cont;
extern u_int32 vcount;
extern PROG program;
extern FUNCLIST func[2];
extern int catlist[6];
extern char filelist[62][31];
extern unsigned char cube_m[4944];
extern unsigned char decide1_m[15296];
extern unsigned char decide2_m[31024];
extern unsigned char slide_m[4048];
extern SE se[4];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char displist[327680];
extern ScePspFMatrix4 matrix_stack[48];
extern int __fade;
extern int __fadecount;
extern int __fadecolor;
extern int __fadestep;

int GetItem(int cat, int num);
void PrxExec(int cat, int num);
static void InitSE(void);
void PlaySE(int num);
static void InitFunc(void);
void DrawSprite(float x, float y, float w, float h, int u, int v);
void FadeDraw(void);
static void DrawFunc(void);
static void KeyFunc(void);
static int ProgramSwitch(void);
int main(int argc, char **argv);


INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/main", GetItem);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/main", PrxExec);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/main", InitSE);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/main", PlaySE);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/main", D_00016F80);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/main", InitFunc);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/main", DrawSprite);

void FadeSetup(int mode, int step, int c) {
    __fade = mode;
    __fadecolor = c;
    __fadestep = step;
    __fadecount = 0;
}

int FadeState(void) {
    return __fade;
}

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/main", FadeDraw);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/main", DrawFunc);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/main", KeyFunc);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/main", ProgramSwitch);

void ProgramChange(int mode) {
    if (program.next != mode) {
        program.next = mode;
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/main", main);
