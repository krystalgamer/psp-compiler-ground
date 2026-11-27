/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
extern unsigned char D_00103564;
extern unsigned char D_0010357C;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_00103564);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_0010357C);

int refloadSetRef2CardFunc(int arg0) {
    if (arg0 >= 5) {
        consPrintf(&D_0010357C, &D_00103564, 0x1B, "refloadSetRef2CardFunc", "Inst < Inst_Num");
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", refloadGetLocal);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_001035D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_001035EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_0010362C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", refloadKeepLocal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", refloadReleaseRefer);

void refloadReleaseAll(int a, int b, int c)
{
	refloadReleaseAll2(a, 1, b, c);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_0010369C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", refloadReleaseAll2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", refloadReadTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_00103740);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_00103744);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_00103774);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_001037A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_001037C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_001037DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_001037FC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", refloadReleaseTask);
