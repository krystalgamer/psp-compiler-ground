/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
int resGetPtrLocal();                               /* extern */
int resGetSizeLocal(int, int);                      /* extern */
M2C_UNK seek_top();                                 /* extern */
extern int cus_buf;
extern int cus_size;
M2C_UNK find_section(int);                          /* extern */
extern int cus_inst;
M2C_UNK get_key_count(int);                         /* extern */
extern unsigned char GameData;
M2C_UNK gameOvlProcInst(int, int, int, int, int);   /* extern */
int resGetCurrentInst();                            /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
int iskanji1(int arg0) {
    int temp_v0;

    temp_v0 = arg0 & 0xFF;
    return ((unsigned int) ((temp_v0 + 0x7F) & 0xFF) < 0x1FU) | ((unsigned int) ((temp_v0 + 0x20) & 0xFF) < 0x1DU);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int iskanji2(int arg0) {
    int temp_a0;

    temp_a0 = arg0 & 0xFF;
    return ((unsigned int) ((temp_a0 - 0x40) & 0xFF) < 0xBDU) & (temp_a0 != 0x7F);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", seek_top);

#ifndef NULL
#define NULL ((void *)0)
#endif

void load_cus(int arg0, int arg1) {
    cus_buf = resGetPtrLocal();
    cus_size = resGetSizeLocal(arg0, arg1);
    seek_top();
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC368);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_line);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", is_section);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", is_key);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", extract_key);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_cus_value);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC398);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_cus_value_fast);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_key_count);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_key_by_index);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_key_by_index_fast);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_key_index);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_key_index_fast);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", to_int);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", to_float);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", trim);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", find_section);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_index_value);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_index_num);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetString);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetInt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetFloat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetStringIndex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetIntIndex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetFloatIndex);

#ifndef NULL
#define NULL ((void *)0)
#endif

void cusSetSection(int arg0, int arg1) {
    load_cus(cus_inst, arg0);
    find_section(arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void cusSetInst(int arg0) {
    cus_inst = arg0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC3D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC3DC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetIndexNum);

#ifndef NULL
#define NULL ((void *)0)
#endif

void cusGetKeyNum(int arg0, int arg1) {
    load_cus(cus_inst, arg0);
    get_key_count(arg1);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetKeyName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetKeyIndex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", _fontAlloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", _fontFree);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC3F8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC41C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC438);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC450);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC460);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC470);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC480);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC494);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC498);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontSetPgfResource);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC4EC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontSetPgfResourceExtra);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontGetPos);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC524);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontSetPos);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontOfsPos);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC544);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontIsMarkFont);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontGetCharWidth);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontGetCharHeight);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontGetStrWidth);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontGetStrHeight);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontImgInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontImgInitEx);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontImgTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontImgPut);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontImgStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontImgDat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontStrInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontStrTerm);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC62C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontStrPut);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontStrStr);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC668);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC66C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC670);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC674);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC678);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontStrDraw);

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *gameGetCntx(void) {
    return &GameData;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", gameLock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", gameUnlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", gameChkChange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", gameSwitchPlayer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", gameMain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", gameProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", gameOvlProcInst);

#ifndef NULL
#define NULL ((void *)0)
#endif

void gameOvlProcCurrent(int arg0, int arg1, int arg2, int arg3) {
    gameOvlProcInst(resGetCurrentInst(), arg0, arg1, arg2, arg3);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", gameOvlProcAll);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC690);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC6AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC6BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC6C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC6D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC6FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC71C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC73C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC75C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC77C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC79C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC7B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC7DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC7FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC81C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC83C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC85C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC87C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC898);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC8B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC8D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC8E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC904);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC91C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC938);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC958);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC98C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC9B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC9E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FCA18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FCA48);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FCA74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FCAA0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FCAC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FCAD4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FCB24);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", gameTaskInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FCB74);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", gameTaskTerm);
