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
struct _anon1 { /* size 0x3c */
    int mode;
    ScePspFVector3 pos;
    ScePspFVector3 sbuf[3];
    int scnt;
    float t;
};
typedef struct _anon1 BALLOONDAT;

extern BALLOONDAT balloon;
extern ScePspFVector3 sphere[28];
extern ScePspFVector3 pole[28];

void init_balloon(void);
void draw_balloon(void);
static void ctrl_spline(int mode);
int proc_balloon(void);


/* SDK prototypes (tools/sdk_protos.h) */
int rand(void);
void sceGuColor(unsigned int color);
void sceGuDisable(int state);
void sceGuSpecular(float power);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/balloon", init_balloon);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/balloon", draw_balloon);

float spline(float t, float pos0, float pos1, float pos2) {
    float temp_f13;
    float temp_f15;
    float temp_f1;

    temp_f13 = (pos1 + pos0) * 0.5f;
    temp_f15 = (pos2 + pos1) * 0.5f;
    temp_f1 = ((temp_f13 + temp_f15 + pos1) / 3.0f) * 4.0f;
    return ((((2.0f * temp_f15) + (2.0f * temp_f13)) - temp_f1) * t * t) + (((temp_f1 - temp_f15) - (temp_f13 * 3.0f)) * t) + temp_f13;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/balloon", ctrl_spline);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/balloon", proc_balloon);

void set_balloon(int mode) {
    balloon.mode = mode;
}

int get_balloon(void) {
    return balloon.mode;
}
