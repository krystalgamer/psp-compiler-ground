#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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

extern ScePspFVector3 light_vec;
extern const unsigned int marble_clut[8];
extern const unsigned int ref_clut[8];
extern const unsigned int marble_tex[2048];
extern const unsigned int ref_tex[512];
extern const float alphabet[26][300];
extern float morph[16][600];
extern char cur_word[17];
extern int cur_len;
extern int cur_stat;
extern int new_len;
extern int frame;
extern int wait;
extern float stepx;
extern float startx;
extern float ground[48];
extern ScePspFMatrix4 shadow_mat;

static void init_morph(int n, int src, int dst);
static void draw_alphabet(void);
static void update_data(void);
void DrawData(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuMorphWeight(int index, float weight);


INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/draw", marble_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/draw", ref_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/draw", marble_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/draw", ref_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/draw", alphabet);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/draw", init_morph);

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
void update_morph(int frame) {
    float temp_f20;

    temp_f20 = (float) frame / 15.0f;
    sceGuMorphWeight(0, 1.0f - temp_f20);
    sceGuMorphWeight(1, temp_f20);
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/draw", draw_alphabet);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/draw", update_data);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/draw", DrawData);
