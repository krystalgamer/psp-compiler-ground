#include "common.h"
#include "m2c_macros.h"
M2C_UNK I3dSearchName(int, unsigned short, int);               /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3r", I3dSearchName);

#ifndef NULL
#define NULL ((void *)0)
#endif
int strcmp(const char *a, const char *b);
int I3rRoot__CheckIdString(signed char *arg0) {
    int var_a0;

    var_a0 = 0;
    if ((strcmp(arg0, "I3D_BIN") != 0) || (__builtin_allegrex_ext(M2C_FIELD(arg0, int *, 0x14), 0x18, 7) != 0x52)) {
        var_a0 = 3;
    }
    return var_a0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3r", I3rRoot__PackSub);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3r", I3rRoot__Unpack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3r", I3rRoot__Pack);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rRoot__Get_nNode(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 0x18), int *, 0x34), 0, 0x18);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3r", I3rRoot__GetNodeName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_parser_i3r", I3rRoot__GetNodeIndexByName);

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned short I3rRoot__Get_nTex(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), unsigned short *, 0x2C);
}

int I3rRoot__GetTexName(char *r, int i)
{
	return (*(int **)(*(char **)(r + 0x10) + 0x18))[i];
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3rRoot__GetTexIndexByName(void *arg0, int arg1) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x10);
    I3dSearchName(M2C_FIELD(temp_v0, int *, 0x18), M2C_FIELD(temp_v0, unsigned short *, 0x2C), arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rRoot__CalcTotalStrip(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), int *, 0x24);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rRoot__GetLocalBasicTransformA(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), int *, 0x10) + (arg1 << 6);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rRoot__GetModelBasicTransformA(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), int *, 0x14) + (arg1 << 6);
}

