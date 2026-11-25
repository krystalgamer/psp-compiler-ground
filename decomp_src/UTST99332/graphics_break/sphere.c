#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;

extern ScePspFVector3 sphere[28];



void DrawSphere(void) {
    sceGumDrawBezier(0x180, 4, 7, 0, sphere);
}
