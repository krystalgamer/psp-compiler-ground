/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
extern int pNowLocale;
extern int pRegionCntx;
M2C_UNK ctrlSetCancel(M2C_UNK);                     /* extern */
M2C_UNK ctrlSetEnter(M2C_UNK);
int sceUtilityGetSystemParamInt(int, int *);
int localeChange();
int localeSetKeyConfig(void);

char *resArg();
int strncmp(const char *, const char *, unsigned int);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/locale", localeChangeDirect);

int localeChangeDirect();
typedef struct { unsigned char f0, f1, lang, btn; char name[8]; unsigned char flags; } LocInfo;
typedef struct { unsigned char num, cur, f2, f3; int pad[3]; LocInfo *loc[1]; } RegionInfo;
#define RGN ((RegionInfo *)pRegionCntx)
#define NOWLOC ((LocInfo *)pNowLocale)
int localeChange(int lang, int btn)
{
	unsigned int n = RGN->num;
	unsigned int i;
	for (i = 0; i < n; i++)
		if (lang == RGN->loc[i]->lang && btn == RGN->loc[i]->btn) goto found;
	for (i = 0; i < n; i++)
		if (lang == RGN->loc[i]->lang) goto found;
	for (i = 0; i < n; i++)
		if (btn == RGN->loc[i]->btn) goto found;
found:
	return localeChangeDirect(i);
}

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

int localeGetCntx(void) {
    return pNowLocale;
}

int localeGetRegionCntx(void) {
    return pRegionCntx;
}

int localeIsUse(int res)
{
	if (*(char *)resArg(res, 2) == 0) {
		return 1;
	}
	return strncmp(resArg(res, 2), (char *)pNowLocale + 4, 4) == 0;
}

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
