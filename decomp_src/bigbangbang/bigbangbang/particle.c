#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int32;
struct _anon1;
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef unsigned char u_char8;
struct _anon1 { /* size 0x30 */
    int flg;
    ScePspFVector3 pos;
    ScePspFVector3 spd;
    ScePspFVector3 rot;
    u_int32 c;
    u_char8 a;
};
typedef struct _anon1 PARTICLE;

extern PARTICLE particle[128];
extern int nextindex;
extern float flit[18];
extern u_int32 rand_data;

void InitParticle(void);
int CheckParticle(void);
void SetParticle(float x, float y, float z, float speed, int number, int c);
void DrawParticle(void);


void random_seed(unsigned int seed) {
    rand_data = seed;
}

int random(void) {
    unsigned int temp_v1;

    temp_v1 = (rand_data * 0x4E6D) + 0x3039;
    rand_data = temp_v1;
    return (int) (temp_v1 >> 4);
}

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/particle", InitParticle);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/particle", CheckParticle);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/particle", SetParticle);

INCLUDE_ASM("tmp/asm/bigbangbang/bigbangbang/nonmatchings/particle", DrawParticle);
