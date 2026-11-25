#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
typedef unsigned int u_int32;
struct _anon1;
struct _anon1 { /* size 0x24 */
    ScePspFVector3 pos;
    ScePspFVector3 rot;
    int cat;
    int num;
    int ret;
};
typedef struct _anon1 *PMENUDATA;
struct _anon2;
struct _anon2 { /* size 0x20 */
    int cnt_rot;
    int flag_rot;
    float scale;
    float sbuf[3];
    int scnt;
    float t;
};
typedef struct _anon2 CATDATA;

extern PMENUDATA menu;
extern CATDATA cat;

void InitCategory(void);
void DrawCategory(void);
static void InitSpline(void);
static void CtrlSpline(void);
void RunCategory(void);
void KeyCategory(u_int32 padd, u_int32 cont, float *axis);


INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/category", InitCategory);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/category", DrawCategory);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/category", InitSpline);

float Spline(float t, float pos0, float pos1, float pos2) {
    float temp_f13;
    float temp_f15;
    float temp_f1;

    temp_f13 = (pos1 + pos0) * 0.5f;
    temp_f15 = (pos2 + pos1) * 0.5f;
    temp_f1 = ((temp_f13 + temp_f15 + pos1) / 3.0f) * 4.0f;
    return ((((2.0f * temp_f15) + (2.0f * temp_f13)) - temp_f1) * t * t) + (((temp_f1 - temp_f15) - (temp_f13 * 3.0f)) * t) + temp_f13;
}

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/category", CtrlSpline);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/category", RunCategory);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/category", KeyCategory);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/category", D_00017078);
