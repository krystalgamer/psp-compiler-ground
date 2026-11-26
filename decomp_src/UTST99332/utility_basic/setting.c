#include "common.h"

/* declarations recovered from DWARF */


extern int g_lang;
extern int g_assing;

void OnPush_ChangeSetting(int selection);
static void OnCancel_ChangeSetting(int selection);
static void OnPush_Japanese(int selection);
static void OnPush_English(int selection);
static void OnPush_French(int selection);
static void OnPush_Spanish(int selection);
static void OnPush_German(int selection);
static void OnPush_Italian(int selection);
static void OnPush_Dutch(int selection);
static void OnPush_Portuguese(int selection);
static void OnPush_Russian(int selection);
static void OnPush_ChangeLang(int selection);
int GetMessageLang();
void OnPush_Circle(int selection);
void OnPush_Cross(int selection);
static void OnPush_ChangeAssign(int selection);
int GetAssign();


void OnPush_ChangeSetting(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("change lang >", OnPush_ChangeLang);
    Menu_AppendItem("change assing >", OnPush_ChangeAssign);
    Menu_SetCancelCallback(OnCancel_ChangeSetting);
}

static void OnCancel_ChangeSetting(int selection)
{
    Menu_WriteLine("OnCancel_SaveData", 0x00ffffff);
    CreateMenu_Root();
}

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", OnPush_Japanese);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", OnPush_English);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", OnPush_French);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", OnPush_Spanish);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", OnPush_German);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", OnPush_Italian);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", OnPush_Dutch);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", OnPush_Portuguese);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", OnPush_Russian);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", OnPush_ChangeLang);

int GetMessageLang(void) {
    return g_lang;
}

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", OnPush_Circle);

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", OnPush_Cross);

static void OnPush_ChangeAssign(int selection)
{
    Menu_ClearItems();
    Menu_AppendItem("circle is enter", OnPush_Circle);
    Menu_AppendItem("cross  is enter", OnPush_Cross);
    Menu_SetCancelCallback(OnPush_ChangeSetting);
}

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/setting", GetAssign);
