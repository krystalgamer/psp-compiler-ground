/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern unsigned char D_000FC3F8;
extern unsigned char D_000FC41C;
extern unsigned char D_000FC4EC;
extern int pFontDat;
extern int pMarkFontDat;
extern int pMarkTextDat;
extern unsigned char D_000FC524;
M2C_UNK _memFree(int *, M2C_UNK *, M2C_UNK);        /* extern */
extern unsigned char D_000FC544;
extern unsigned char D_000FC62C;
M2C_UNK semaLock(int);                              /* extern */
extern int GameSema;
M2C_UNK semaUnlock(int);                            /* extern */

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

double atof(const char *);
float to_float(const char *s)
{
	return atof(s);
}

void trim(char *s)
{
	char *d = s;
	do {
		if (*s != ' ' && *s != '\t')
			*d++ = *s;
	} while (*s++);
}

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

void *_memAlloc();
int _fontAlloc(int a, int size)
{
	int r = -1;
	if (size)
		r = (int)_memAlloc(size, &D_000FC3F8, 0x41);
	return r;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif

int fontSetPgfResource(int arg0) {
    if (arg0 == 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xDA, "fontSetPgfResource", &D_000FC4EC);
    }
    pFontDat = arg0;
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC4EC);

#ifndef NULL
#define NULL ((void *)0)
#endif

int fontSetPgfResourceExtra(int arg0, int arg1) {
    if (arg0 == 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xE4, "fontSetPgfResourceExtra", &D_000FC4EC);
    }
    if (arg1 == 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xE5, "fontSetPgfResourceExtra", "pTextDat");
    }
    pMarkFontDat = arg0;
    pMarkTextDat = arg1;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int fontGetPos(void *arg0, void *arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0xF4, "fontGetPos", &D_000FC524);
    }
    M2C_FIELD(arg1, int *, 0) = (int) M2C_FIELD(arg0, int *, 0x10);
    M2C_FIELD(arg1, int *, 4) = (int) M2C_FIELD(arg0, int *, 0x14);
    M2C_FIELD(arg1, int *, 8) = (int) M2C_FIELD(arg0, int *, 0x18);
    M2C_FIELD(arg1, int *, 0xC) = (int) M2C_FIELD(arg0, int *, 0x1C);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC524);

#ifndef NULL
#define NULL ((void *)0)
#endif

int fontSetPos(void *arg0, void *arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x102, "fontSetPos", &D_000FC524);
    }
    M2C_FIELD(arg0, int *, 0x10) = (int) M2C_FIELD(arg1, int *, 0);
    M2C_FIELD(arg0, int *, 0x14) = (int) M2C_FIELD(arg1, int *, 4);
    M2C_FIELD(arg0, int *, 0x18) = (int) M2C_FIELD(arg1, int *, 8);
    M2C_FIELD(arg0, int *, 0x1C) = (int) M2C_FIELD(arg1, int *, 0xC);
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontOfsPos);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC544);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontIsMarkFont);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontGetCharWidth);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontGetCharHeight);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontGetStrWidth);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontGetStrHeight);

void fontImgInit(int a)
{
	fontImgInitEx(a, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontImgInitEx);

#ifndef NULL
#define NULL ((void *)0)
#endif

int fontImgTerm(int *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x1E2, "fontImgTerm", &D_000FC524);
    }
    if (*arg0 != 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x1E3, "fontImgTerm", &D_000FC544);
    }
    _memFree(arg0, &D_000FC3F8, 0x1E5);
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontImgPut);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontImgStr);

#ifndef NULL
#define NULL ((void *)0)
#endif

int fontImgDat(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x224, "fontImgDat", &D_000FC524);
    }
    if (M2C_FIELD(arg0, int *, 0) != 0) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x225, "fontImgDat", &D_000FC544);
    }
    return M2C_FIELD(arg0, int *, 0x50);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", fontStrInit);

#ifndef NULL
#define NULL ((void *)0)
#endif

int fontStrTerm(M2C_UNK *arg0) {
    M2C_UNK *temp_s0;
    M2C_UNK *temp_s0_2;
    M2C_UNK *var_a0;
    M2C_UNK *var_a0_2;

    if (arg0 == NULL) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x24D, "fontStrTerm", &D_000FC524);
    }
    if (M2C_FIELD(arg0, M2C_UNK **, 0) != (M2C_UNK *)1) {
        consPrintf(&D_000FC41C, &D_000FC3F8, 0x24E, "fontStrTerm", &D_000FC62C);
    }
    var_a0 = M2C_FIELD(arg0, M2C_UNK **, 0x6C);
    if (var_a0 != NULL) {
        do {
            temp_s0 = *var_a0;
            _memFree(var_a0, &D_000FC3F8, 0x254);
            var_a0 = temp_s0;
        } while (temp_s0 != NULL);
    }
    var_a0_2 = M2C_FIELD(arg0, M2C_UNK **, 0x74);
    if (var_a0_2 != NULL) {
        do {
            temp_s0_2 = *var_a0_2;
            _memFree(var_a0_2, &D_000FC3F8, 0x25D);
            var_a0_2 = temp_s0_2;
        } while (temp_s0_2 != NULL);
    }
    _memFree(arg0, &D_000FC3F8, 0x262);
    return 1;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif

void gameLock(void) {
    if (GameSema > 0) {
        semaLock(GameSema);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void gameUnlock(void) {
    if (GameSema > 0) {
        semaUnlock(GameSema);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", gameChkChange);

typedef struct { char pad[0x9C]; int mode; int pad2; int player; } GameDataSw;
int SaruNet_ResidentData__Is_Server();
void gameSwitchPlayer(int a)
{
	GameDataSw *g = (GameDataSw *)&GameData;
	if (g->mode != 2)
		g->player = a;
	else
		g->player = !SaruNet_ResidentData__Is_Server();
}

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
