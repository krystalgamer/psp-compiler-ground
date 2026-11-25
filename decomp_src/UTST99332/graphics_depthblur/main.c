#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1 { /* size 0x18 */
    ScePspFVector3 _pos;
    ScePspFVector3 _rot;
};
typedef struct _anon1 Positioning;
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
typedef unsigned int SceSize;
typedef int SceUID;
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
typedef int bool;
struct _anon2;
struct _anon2 { /* size 0x14 */
    unsigned int format;
    bool toggle;
    bool copy;
    bool final32;
    const char *desc;
};

extern unsigned int checkcolor[1];
extern unsigned int check32x32[128];
extern unsigned int check16x16[64];
extern unsigned int check8x8[32];
extern unsigned int check4x4[16];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern int sce_newlib_heap_kb_size;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];
extern Positioning _camera_inverse_transform;
extern Positioning _dragon_transform;
extern int texflag;
extern bool frame32;
extern bool depthspread;
extern float focus;
extern int mode;
extern const struct _anon2 modes[5];
extern float wall[80];
extern u_int32 cont;

void ResetAllPositioning();
static void PositioningMultMatrix(Positioning *_Positioning);
static void draw_dragon_with_camera_transform();
void InitWall(void);
void DrawTorus(float inner, float outer);
void DrawRoom(void);
static void draw_frame(void);
static void init_gfx(void);
static int pad_read(void);
void StartMainThread();


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000151A0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000151AC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000151C8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000151D8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000151E4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", modes);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015258);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015290);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000152A0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000152AC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000152C0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000152D4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000152E4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015300);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015340);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015348);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015358);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015368);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015394);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000153A0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000153B0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000153BC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000153CC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000153E0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000153F4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015404);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", ResetAllPositioning);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", PositioningMultMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", draw_dragon_with_camera_transform);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", InitWall);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", DrawTorus);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", DrawRoom);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", init_gfx);

void init_all(void) {
    init_gfx();
    ResetAllPositioning();
    InitWall();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", pad_read);

int MainThread(unsigned int _ArgNum, void *_ArgData) {
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
    menuTerm(1, 5);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", StartMainThread);

int main(void) {
    StartMainThread();
    return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000154C8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000154CC);
