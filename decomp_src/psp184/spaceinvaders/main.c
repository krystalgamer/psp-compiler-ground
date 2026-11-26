/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/main", main);

#ifndef NULL
#define NULL ((void *)0)
#endif
int MoriyaHatoMove(int *arg0, int arg1, int arg2) {
    int temp_v0;
    int temp_v1;

    temp_v1 = *arg0;
    temp_v0 = (int) (arg1 - temp_v1) >> arg2;
    if (temp_v0 == 0) {
        if (temp_v1 != arg1) {
            *arg0 = temp_v1 + 1;
        } else {
            *arg0 = arg1;
        }
    } else {
        *arg0 = temp_v1 + temp_v0;
    }
    return *arg0 - arg1;
}
