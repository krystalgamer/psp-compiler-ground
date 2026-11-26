#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0x14 */
    int unum;
    int vnum;
    int utype;
    int vtype;
    const float *vert;
};
typedef struct _anon1 POT_PARTS;

extern const float body_b[75];
extern const float body_f_l[105];
extern const float body_f_r[105];
extern const float cap1[108];
extern const float cap_frame1[108];
extern const float cap_grip_1[48];
extern const float cap_grip_2[48];
extern const float grip_1[96];
extern const float grip_2[96];
extern const float plince[108];
extern const float plince_bottom[108];
extern const float plince_frame[108];
extern POT_PARTS pot_all[12];

void DrawPot(void);


void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
extern const float body_b[75];
extern const float body_f_l[105];
extern const float body_f_r[105];
extern const float cap1[108];
extern const float cap_frame1[108];
extern const float cap_grip_1[48];
extern const float cap_grip_2[48];
extern const float grip_1[96];
extern const float grip_2[96];
extern const float plince[108];
extern const float plince_bottom[108];
extern const float plince_frame[108];
extern POT_PARTS pot_all[12];
void DrawPot(void);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void DrawPot(void)
{
    int i;

    for (i = 0; i < (int)(sizeof(pot_all) / sizeof(POT_PARTS)); i++) {
        sceGumDrawSpline(0x180, pot_all[i].unum, pot_all[i].vnum,
            pot_all[i].utype, pot_all[i].vtype, NULL, pot_all[i].vert);
    }
}












INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/pot", body_b);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/pot", body_f_l);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/pot", body_f_r);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/pot", cap1);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/pot", cap_frame1);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/pot", cap_grip_1);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/pot", cap_grip_2);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/pot", grip_1);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/pot", grip_2);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/pot", plince);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/pot", plince_bottom);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/pot", plince_frame);

