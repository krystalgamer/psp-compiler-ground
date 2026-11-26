/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "m2c_macros.h"
extern float D_00353AC0;


INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_camera", camera_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_camera", camera_control);

#ifndef NULL
#define NULL ((void *)0)
#endif

void camera_fovy_set(float fparg0) {
    D_00353AC0 = (fparg0 * 3.14f) / 180.0f;
}
