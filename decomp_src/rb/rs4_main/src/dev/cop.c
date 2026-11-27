/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
extern signed char D_000F9BF0;
extern unsigned char Seed;


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", D_000F9BF0);

#ifndef NULL
#define NULL ((void *)0)
#endif

void copInit(void) {
    consPrintf(&D_000F9BF0, "copInit");
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void copTerm(void) {
    consPrintf(&D_000F9BF0, "copTerm");
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copSetSeed);

#ifndef NULL
#define NULL ((void *)0)
#endif

void copSetSeedHL(int arg0, int arg1) {
    M2C_FIELD(&Seed, int *, 0) = arg0;
    M2C_FIELD(&Seed, int *, 4) = arg1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copGetSeed);

#ifndef NULL
#define NULL ((void *)0)
#endif

void copGetSeedHL(int *arg0, int *arg1) {
    *arg0 = M2C_FIELD(&Seed, int *, 0);
    *arg1 = M2C_FIELD(&Seed, int *, 4);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRand);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRandS);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copInitAttr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copCosSin);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAtan);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAcos);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAsin);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copUnitMat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copLetMat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copLetMat3);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRevMat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRevMat3);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copSclMat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copSclMat3);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copSclMatH);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copSclMatH3);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copMulMat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copMulMat3);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copNomMat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copNomMatY);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRotMat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRotMatX);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRotMatY);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRotMatZ);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAngMatXYZ);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAngMatXZY);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAngMatYXZ);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAngMatYZX);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAngMatZXY);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAngMatZYX);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copInterMat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copInterMatAng);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copLetVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copVecF0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copVecF4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copVecI0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copVecI4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copMinVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copMaxVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAddVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copSubVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copMltVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copLenVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copNomVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copStrVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copSclVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copIntVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copDotVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copOutVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copDistVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRotVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copRotTraVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copPersVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copUnitQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copLetQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copMinQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copMaxQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copAddQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copSubQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copMltQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copNomQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copIntQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copSclQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copDotQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copMulQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copQuatMat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copMatQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copInterQuat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copInterQuatAng);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copTargetPos);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copLinePos);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copGrdVec);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/cop", copCrossChk);
