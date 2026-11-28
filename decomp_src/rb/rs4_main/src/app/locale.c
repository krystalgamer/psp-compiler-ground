/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#include "../minmax.h"
extern int pNowLocale;
extern int pRegionCntx;
M2C_UNK ctrlSetCancel(M2C_UNK);                     /* extern */
M2C_UNK ctrlSetEnter(M2C_UNK);
int sceUtilityGetSystemParamInt(int, int *);
int localeChange();
int localeSetKeyConfig(void);

char *resArg();
int strncmp(const char *, const char *, unsigned int);

typedef struct { unsigned char f0, f1, lang, btn; char name[8]; unsigned char flags; } LocInfo;
typedef struct { unsigned char num, cur, f2, f3; int pad[3]; LocInfo *loc[1]; } RegionInfo;
#define RGN ((RegionInfo *)pRegionCntx)
#define NOWLOC ((LocInfo *)pNowLocale)
int localeChangeDirect();
int localeGetRegionCntx(void);
void sceImposeSetLanguageMode(int, int);
void consPrintf(const char *, ...);
int localeChangeDirect(int idx)
{
	unsigned int i = amax(idx, 0);
	int lang, btn;
	int v;
	LocInfo *loc;

	if (i >= ((RegionInfo *)localeGetRegionCntx())->num)
		i = 0;
	loc = RGN->loc[i];
	pNowLocale = (int)loc;
	consPrintf("%s : %s\n", "localeChangeDirect", loc->name);
	lang = -1;
	btn = -1;
	if (sceUtilityGetSystemParamInt(8, &v) == 0)
		lang = v;
	else
		consPrintf("cassert : %s %d : %s : %s\n", "src/app/locale.c", 765, "localeChangeDirect", "FALSE");
	if (sceUtilityGetSystemParamInt(9, &v) == 0)
		btn = v;
	else
		consPrintf("cassert : %s %d : %s : %s\n", "src/app/locale.c", 767, "localeChangeDirect", "FALSE");
	if (RGN->f2)
		lang = NOWLOC->lang;
	if (RGN->f3)
		btn = NOWLOC->flags & 1;
	consPrintf("%s : sceImposeSetLanguageMode(%d,%d)\n", "localeChangeDirect", lang, btn);
	sceImposeSetLanguageMode(lang, btn);
	RGN->cur = i;
	return (unsigned char)i;
}

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
