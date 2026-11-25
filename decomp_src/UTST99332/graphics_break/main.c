#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1;
struct _anon1 { /* size 0x80 */
    int buffer[32];
};
typedef struct _anon1 SceGumContext;
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
struct _anon2;
struct _anon2 { /* size 0x18 */
    ScePspFVector3 rot;
    ScePspFVector3 trans;
};
typedef struct _anon2 POS;
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
struct SceGeContext;
struct SceGeContext { /* size 0x800 */
    unsigned int buffer[512];
};
typedef struct SceGeContext SceGeContext;
typedef SceGeContext SceGuContext;

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern volatile int vcnt;
extern int num;
extern int step;
extern int cdb;
extern POS pos;
extern int frame;
extern int prev_vcnt;
extern int cur_vcnt;
extern float fps;
extern void *edram_addr;
extern int list_size;
extern u_int32 packet[2][1024];
extern char disp_list[1048576];
extern ScePspFMatrix4 matrix_stack[16];
extern SceGuContext context;
extern float triangle[9];

static void mk_pkt(void);
static void cbvsync(int idx, void *cookie);
static void frame_update(void);
static void draw_debug(void);
static void draw_frame(void);
static void init_all(void);
int main(void);

/* SDK functions (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_break/nonmatchings/main", D_00011DF8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_break/nonmatchings/main", D_00011E04);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_break/nonmatchings/main", D_00011E10);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_break/nonmatchings/main", D_00011E18);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_break/nonmatchings/main", mk_pkt);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_break/nonmatchings/main", cbvsync);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_break/nonmatchings/main", frame_update);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_break/nonmatchings/main", draw_debug);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_break/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_break/nonmatchings/main", init_all);

int pad_read(void) {
    SceCtrlData buf;
    sceCtrlReadBufferPositive(&buf, 1);
    if (buf.Buttons & 1) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_break/nonmatchings/main", main);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_break/nonmatchings/main", D_00011E60);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_break/nonmatchings/main", D_00011E64);
