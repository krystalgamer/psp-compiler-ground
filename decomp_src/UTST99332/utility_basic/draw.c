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
struct _anon1 { /* size 0x18 */
    ScePspFVector3 rot;
    ScePspFVector3 trans;
};
typedef struct _anon1 POS;
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

extern const unsigned int env_clut[128];
extern const unsigned int env_tex[256];
extern const unsigned int toon_clut[8];
extern const unsigned int toon_tex[128];
extern POS pos;
extern float angle;
extern int changed;
extern int autoflag;
extern int mode;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];

void draw_frame(void);
void init_all(void);
static void init_pos(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void *sceGuSwapBuffers(void);
int sceDisplayWaitVblankStart(void);


INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", env_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", env_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", toon_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", toon_tex);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", init_pos);

void term_all(void) {
    sceGuTerm();
}

void vsync_frame(void) {
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}
