#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int size_t;
struct SceGmoModel;
typedef struct SceGmoModel SceGmoModel;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
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
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern int sce_newlib_heap_kb_size;
extern int DogSize;
extern int DogData;
extern char g_packet_buf[1048576];
extern ScePspFMatrix4 g_matrix_buf[16];
extern _Bool g_running;
extern ScePspFVector3 g_translate;
extern ScePspFVector3 g_rotate;
extern ScePspFVector3 g_scale;
extern SceGmoModel *g_model;
extern SceGmoModel *g_copies[3];

int main(int argc, char **argv);
static void begin_scene(void);
static void end_scene(void);
static void move_objects(void);
static void draw_objects(void);
static _Bool load_objects(int argc, char **argv);
static void unload_objects(void);
static _Bool load_file(const char *filename, int **buf, int *size);


void *malloc16(unsigned int size) {
    return memalign(0x10, size);
}

void free16(void *addr) {
    free();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", main);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D5E0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D5EC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D5F8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D604);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D610);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D61C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D628);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D62C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D630);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D63C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D648);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D654);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D65C);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", begin_scene);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", end_scene);

void swap_buffers(void) {
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", move_objects);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", draw_objects);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", load_objects);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", unload_objects);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", load_file);
