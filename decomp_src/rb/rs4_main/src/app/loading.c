/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
extern int pNowLocale;
extern int pRegionCntx;
M2C_UNK ctrlSetCancel(M2C_UNK);                     /* extern */
M2C_UNK ctrlSetEnter(M2C_UNK);                      /* extern */



void loadingInit(void) {
}

void loadingTerm(void) {
}

void loadingSetup(void) {
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", loadingDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", localeChangeDirect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", localeChange);

int sceUtilityGetSystemParamInt(int, int *);
int localeChange();
int localeSetKeyConfig(void);
int localeInit(void)
{
	int lang;
	if (sceUtilityGetSystemParamInt(8, &lang) == 0)
		localeChange(lang, 0);
	else
		localeChange(0, 0);
	localeSetKeyConfig();
	return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int localeGetCntx(void) {
    return pNowLocale;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int localeGetRegionCntx(void) {
    return pRegionCntx;
}

char *resArg();
int strncmp(const char *, const char *, unsigned int);
int localeIsUse(int res)
{
	if (*(char *)resArg(res, 2) == 0) {
		return 1;
	}
	return strncmp(resArg(res, 2), (char *)pNowLocale + 4, 4) == 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int localeSetKeyConfig(void) {
    M2C_UNK var_a0;

    if (M2C_FIELD(pNowLocale, int *, 0xC) & 1) {
        ctrlSetEnter(0x4000);
        var_a0 = 0x2000;
    } else {
        ctrlSetEnter(0x2000);
        var_a0 = 0x4000;
    }
    ctrlSetCancel(var_a0);
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", empty_start);

#ifndef NULL
#define NULL ((void *)0)
#endif
int empty_stop(void) {
    return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", D_000FDB38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", D_000FDB44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", D_000FDB50);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/loading", D_000FDB54);
