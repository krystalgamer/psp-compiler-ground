/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);

extern int DecTbl[];

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/calc", calcNumBcd);

int calcBcdNum(int *arg0) {
    int sum = 0;
    int n = *arg0;
    unsigned char *p = (unsigned char *)(arg0 + 1);
    if (!(n > 0)) {
        consPrintf("cassert : %s %d : %s : %s\n", "src/lib/calc.c", 0x49, "calcBcdNum", "Place > 0");
    }
    for (; n != 0; n--) {
        sum += *p++ * DecTbl[n];
    }
    return sum;
}
