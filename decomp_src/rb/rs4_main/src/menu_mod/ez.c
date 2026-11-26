/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
int cusGetKeyName(M2C_UNK, M2C_UNK, int, int, M2C_UNK); /* extern */
extern int D_0011A46C;

extern unsigned char l_tMenuCntx;
M2C_UNK cusGetKeyIndex(M2C_UNK, M2C_UNK, int);      /* extern */
extern unsigned char l_szEdition;
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *);           /* extern */
int gameChgGameMode(int);                           /* extern */
M2C_UNK *gameChgModule(M2C_UNK, int);               /* extern */
int menuGetGameMode(M2C_UNK);                       /* extern */
int menuGetModule(M2C_UNK);                         /* extern */
extern unsigned char D_00102EDC;
extern unsigned char D_00103018;
M2C_UNK cardlistRefresh();                          /* extern */
M2C_UNK databaseRefresh();                          /* extern */
M2C_UNK *localeChange(int, int);                    /* extern */
void *localeGetRegionCntx();                        /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
int AnmIsSuicide(void *arg0) {
    return (M2C_FIELD(arg0, int *, 0x40) & 3) == 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102A88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102AA4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezAnmTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102AC4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezGimTask);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezMenuTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102AE0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102AF4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezScxTask);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezSprintfAllocUCS4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezTtrWrite);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102E5C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezTtrWrite2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezInfoWinInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezInfoWinTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezWriteCardResultEfc);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102E94);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuGetModule);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuGetGameMode);

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *menuGetCntx(void) {
    return &l_tMenuCntx;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102EDC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuFlowInit);

#ifndef NULL
#define NULL ((void *)0)
#endif

void menuGetFlowID(int arg0) {
    cusSetInst(1);
    cusSetSection(6, (int) &l_szEdition);
    cusGetKeyIndex(6, 0, arg0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuGetNextFlowID);

#ifndef NULL
#define NULL ((void *)0)
#endif

int menuGetFlowName(int arg0, int arg1) {
    int var_v1;

    cusSetInst(1);
    cusSetSection(6, (int) &l_szEdition);
    var_v1 = 0;
    if (cusGetKeyName(6, 0, arg0, arg1, 0x20) == 0) {
        consPrintf("%s : IDOverFlow\n", "menuGetFlowName");
        var_v1 = -2;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void menuGetFlowIDNum(void) {
    cusSetInst(1);
    cusGetKeyNum(6, (int) &l_szEdition);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuNextFlow);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuSetNewFlowForce);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuGuessLastSelect);

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *menuChgModule(void) {
    M2C_UNK *var_s0;
    M2C_UNK *var_v1;
    int temp_v0;
    int temp_v0_2;
    int var_v0;

    consPrintf(&D_00102EDC, "menuChgModule");
    temp_v0 = menuGetModule(-1);
    var_v1 = NULL;
    if (temp_v0 >= 0) {
        var_s0 = gameChgModule(2, temp_v0);
        temp_v0_2 = menuGetGameMode(-1);
        if (temp_v0_2 >= 0) {
            var_v0 = 0;
            if (var_s0 != NULL) {
                var_v0 = gameChgGameMode(temp_v0_2) != 0;
            }
            var_s0 = (M2C_UNK *) var_v0;
        }
        consPrintf(&D_00103018, var_s0);
        var_v1 = var_s0;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuChgResetModule);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00103018);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuGosubCardBattle);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuIsCardBattle);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuReturnCardBattle);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuChkCardBattle);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuGosubSaruColle);

#ifndef NULL
#define NULL ((void *)0)
#endif

int menuIsSaruColle(void) {
    return ~D_0011A46C == 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", menuReturnSaruColle);

#ifndef NULL
#define NULL ((void *)0)
#endif

int menuChkSaruColle(void) {
    return ~D_0011A46C != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *menuChangeLocale(int arg0, int arg1) {
    M2C_UNK *temp_v0;
    unsigned char temp_s0;

    consPrintf(&D_00102EDC, "menuChangeLocale");
    temp_s0 = M2C_FIELD(localeGetRegionCntx(), unsigned char *, 1);
    temp_v0 = localeChange(arg0, arg1);
    if (temp_v0 != temp_s0) {
        cardlistRefresh();
        databaseRefresh();
    }
    consPrintf(&D_00103018, temp_v0);
    return temp_v0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_0010308C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00103090);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00103094);
